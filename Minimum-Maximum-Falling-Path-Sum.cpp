// Memoization TC - O(N*N) , SC - O(N*N) + O(N)
 
class Solution {
public:
    int minPathSum(int i ,int j ,vector<vector<int>>& matrix,int N,vector<vector<int>>&dp){
        if(j<0 || j>=N) return 1e9;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        // 3 conditions. 
        int up = matrix[i][j] + minPathSum(i-1,j,matrix,N,dp);
        int top_left = matrix[i][j] + minPathSum(i-1,j-1,matrix,N,dp);
        int top_right = matrix[i][j] + minPathSum(i-1,j+1,matrix,N,dp);

        return dp[i][j] = min(up,min(top_left,top_right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int mini = INT_MAX;
        for(int j = 0; j<n; j++){
            int ans = minPathSum(n-1,j,matrix,n,dp);
            mini = min(mini,ans);
        }
        return mini;

    }
};
