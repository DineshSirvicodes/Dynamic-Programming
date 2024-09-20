// Recursive Sol - TC - 3^n + 3^n
//                 SC - O(N) = recursive stack space
#include <bits/stdc++.h> 

int f(int i , int j1, int j2, int r, int c , vector<vector<int>> &grid){
    if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;

    if(i == r-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+ grid[i][j2];
        }
    }

    //explore all the paths Alice and Bob take simultaneously
    int maxi = -1e8;
    for(int dj1 = -1 ; dj1<=1 ; dj1++){ // Alice's 3 direction check
        for(int dj2 = -1 ; dj2<=1 ; dj2++){ // Bob's 3 direction check
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }
            else{
                value = grid[i][j1]+grid[i][j2];
            }
            value += f(i+1,j1+dj1, j2+dj2, r,c,grid);
            maxi = max(maxi,value);
        }   
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    return f(0,0,c-1,r,c,grid);
}

// Memoization  TC - O(N*M*M) * 9 , where there are 3 different directions both ALice and Bob take simultaneouly
// Sc  - O(N*M*M)  + O(N), O(N) recursive stack space  
#include <bits/stdc++.h> 

int f(int i , int j1, int j2, int r, int c , vector<vector<int>> &grid,
    vector<vector<vector<int>>> &dp){
    if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;

    if(i == r-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+ grid[i][j2];
        }
    }
    
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //explore all the paths Alice and Bob take simultaneously
    int maxi = -1e8;
    for(int dj1 = -1 ; dj1<=1 ; dj1++){ // Alice's 3 direction check
        for(int dj2 = -1 ; dj2<=1 ; dj2++){ // Bob's 3 direction check
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }
            else{
                value = grid[i][j1]+grid[i][j2];
            }
            value += f(i+1,j1+dj1, j2+dj2, r,c,grid,dp);
            maxi = max(maxi,value);
        }   
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // int dp[r][c][c];
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,r,c,grid,dp);
}

// Tabulation TC - O(N*M*M) * 9 , where there are 3 different directions both ALice and Bob take simultaneouly
// Sc  - O(N*M*M)  
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // int dp[r][c][c];
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    // base case
    for(int j1 = 0 ; j1<m ; j1++){
        for(int j2 = 0 ; j2<m ; j2++){
            if(j1 == j2){
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    // outer nested loops started from 2nd last row to first row
    for(int i = n-2 ; i>=0 ;i--){
        for(int j1 = 0 ; j1<m ;j1++){
            for(int j2 = 0 ; j2<m ; j2++){
                int maxi = -1e8;

                // inner nested loops to find  9 possible paths(diagonal moves)
                for(int dj1 = -1 ; dj1<=1 ; dj1++){
                    for(int dj2 = -1 ;dj2<=1 ; dj2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j1];
                        }
                        else{
                            value = grid[i][j1]+grid[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2 <m){
                            value += dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            value += -1e8;
                        }
                        maxi = max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    // maximum chocolates is stored at the top left corner of the dp array
    return dp[0][0][m-1];
}

// Space Optimization Time Complexity: O(N*M*M)*9 ,Reason: The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times.
// SC - O(M*M) Reason: We are using an external array of size ‘M*M’.

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // int dp[r][c][c];
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    // base case
    vector<vector<int>> front(m,vector<int>(m,0));
    vector<vector<int>> curr(m,vector<int>(m,0));

    for(int j1 = 0 ; j1<m ; j1++){
        for(int j2 = 0 ; j2<m ; j2++){
            if(j1 == j2){
                front[j1][j2] = grid[n-1][j1];
            }
            else{
                front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    // outer nested loops started from 2nd last row to first row
    for(int i = n-2 ; i>=0 ;i--){
        for(int j1 = 0 ; j1<m ;j1++){
            for(int j2 = 0 ; j2<m ; j2++){
                int maxi = -1e8;

                // inner nested loops to find  9 possible paths(diagonal moves)
                for(int dj1 = -1 ; dj1<=1 ; dj1++){
                    for(int dj2 = -1 ;dj2<=1 ; dj2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j1];
                        }
                        else{
                            value = grid[i][j1]+grid[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2 <m){
                            value += front[j1+dj1][j2+dj2];
                        }
                        else{
                            value += -1e8;
                        }
                        maxi = max(maxi,value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    // maximum chocolates is stored at the top left corner of the dp array
    return front[0][m-1];
}
