// Memoization TC - O(n*m) SC - O((m-1) + (n-1)) + O(N*M)

class Solution {
public:
    int findPathSum(int i ,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i== 0 && j == 0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = INT_MAX, left = INT_MAX;
        if(i>0) up = grid[i][j] + findPathSum(i-1,j,grid,dp);
        if(j>0) left = grid[i][j] + findPathSum(i,j-1,grid,dp);
        return dp[i][j] = min(up,left);
       
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return findPathSum(m-1,n-1,grid,dp);
    }
};

// Tabulation TC - O(N*M) SC - O(N*M)

class Solution {
public:
    int findPathSum(int i ,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i== 0 && j == 0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        int up = INT_MAX, left = INT_MAX;
        if(i>0) up = grid[i][j] + findPathSum(i-1,j,grid,dp);
        if(j>0) left = grid[i][j] + findPathSum(i,j-1,grid,dp);
        return dp[i][j] = min(up,left);
       
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return findPathSum(m-1,n-1,grid,dp);
        // dp[0][0] = grid[0][0];
        for(int i = 0 ;i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optimization
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return findPathSum(m-1,n-1,grid,dp);
        // dp[0][0] = grid[0][0];
        vector<int> prev(n,0);
        for(int i = 0 ;i<m ; i++){
            vector<int> temp(n,0);
            for(int j = 0 ; j<n ; j++){
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = grid[i][j] + prev[j];
                    if(j>0) left = grid[i][j] + temp[j-1];
                    temp[j] = min(up,left);
                }
            }
            prev = temp;
        }
        return prev[n-1];
}
