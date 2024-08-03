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

// Tabulation
