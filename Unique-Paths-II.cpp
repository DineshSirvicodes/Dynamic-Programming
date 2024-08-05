// Recursive Sol
class Solution {
public:
    int findPath(int i, int j,vector<vector<int>>& arr){
       
        if(i>=0 && j>=0 && arr[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        int up = findPath(i-1,j,arr);
        int left = findPath(i,j-1,arr);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();
        return findPath(i-1,j-1,obstacleGrid);
    }
};

// Memoization TC - O(n*m) SC = O((m-1) + (n-1)) + O(N*M), where m-1 + n-1 is the path length, O((m-1) + (n-1)) is the recursive stack space
class Solution {
public:
    int findPath(int i, int j,vector<vector<int>>& arr,vector<vector<int>>&dp){

        if(i>=0 && j>=0 && arr[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = findPath(i-1,j,arr,dp);
        int left = findPath(i,j-1,arr,dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return findPath(i-1,j-1,obstacleGrid,dp);
    }
};

// Tabulation TC - O(N*M) SC - O(N*M)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        int dp[m][n];
        for(int i = 0 ;i<m; i++){
            for(int j = 0 ;j<n; j++){
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    
                }
                else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    
                }
                else{
                    int up = 0, left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};
// Space Optimization TC = O(n*m) Sc - o(N), only to store one row
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int>prev(n,0);
        for(int i = 0 ;i<m; i++){
            vector<int>temp(n,0);
            for(int j = 0 ;j<n; j++){
                if(obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                }
                else if(i == 0 && j == 0) {
                    temp[j] = 1;
                }
                else{
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = temp[j-1];
                    temp[j] = up+left;
                }    
            }
            prev = temp;
        }
        return prev[n-1];
    }
};
