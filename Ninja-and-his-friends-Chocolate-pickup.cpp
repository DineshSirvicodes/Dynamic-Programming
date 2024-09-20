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
