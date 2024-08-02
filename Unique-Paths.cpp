// Recursive Sol - TC - O(2^(m*n)), exponential sol . for each box we are checking up and left direction
// Sc - O((m-1) + (n-1)) , where m-1 + n-1 is the path length of each unique path.
class Solution {
public:
    int paths(int i, int j){
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        // row decrease ,col constant
        int up = paths(i-1,j);
        // col decrease, row constant
        int left = paths(i,j-1);
        return up + left;
    }
    int uniquePaths(int m, int n) {
        int i = m-1; // row
        int j = n-1; // col
        return paths(i,j);
    }
};

// DP approach
// 1) Memoization- TC - O(N*M) , SC - O((m-1)+(n-1)) + O(n*m) where O(n*m) is the recursive stack space
class Solution {
public:
    int paths(int i, int j,vector<vector<int>> dp){
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // row decrease ,col constant
        int up = paths(i-1,j,dp);
        // col decrease, row constant
        int left = paths(i,j-1,dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int i = m-1; // row
        int j = n-1; // col
        return paths(i,j,dp);
    }
};
// 2) Tabulation TC - O(n*m) Sc - O(n*m)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        // dp[0][0] = 1;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 && j == 0) dp[i][j] = 1; // base case 
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// 3) Space optimization TC - O(n*m) Sc  = O(N) for external space
// taking two arrays, first prev-> n sized array for keeping track of the prev values, temp will be current values in n sized array.
// moving ahead prev = temp->values , then temp calculates new values,
// lastly prev[n-1] => the final value
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        // dp[0][0] = 1;
        for(int i = 0 ; i<m ; i++){
            vector<int>curr(n,0);
            for(int j = 0 ; j<n ; j++){
                if(i == 0 && j == 0) curr[j] = 1; // base case 
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }   
            prev = curr; 
        }
        return prev[n-1];
    }
};
