//1) Memoization TC - O(N*N) , SC - O(N*N) + O(N)
 
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

//2) Tabulation TC - O(N*N) SC - O(N*N)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        // base case, filling oth row of the dp array
        for(int j = 0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i<n ; i++){
            for(int j = 0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];

                int leftDiagonal = matrix[i][j];
                if(j-1>=0){
                    leftDiagonal += dp[i-1][j-1];
                }
                else{
                    leftDiagonal += 1e9;
                }

                int rightDiagonal = matrix[i][j];
                if(j+1<n){
                    rightDiagonal += dp[i-1][j+1];
                }else{
                    rightDiagonal += 1e9;
                }
                
                dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j<n; j++){
            mini = min(mini,dp[n-1][j]); // finding minimum from the last row of the dp array
        }
        return mini;
    }
//3) Space Optimization TC - O(N*N) SC - O(N)

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
    
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        for(int j = 0; j<n; j++){
            prev[j] = matrix[0][j];
        }
        for(int i = 1; i<n ; i++){
            for(int j = 0; j<n; j++){
                int up = matrix[i][j] + prev[j];

                int leftDiagonal = matrix[i][j];
                if(j-1>=0){
                    leftDiagonal += prev[j-1];
                }
                else{
                    leftDiagonal += 1e9;
                }

                int rightDiagonal = matrix[i][j];
                if(j+1<n){
                    rightDiagonal += prev[j+1];
                }else{
                    rightDiagonal += 1e9;
                }
                
                curr[j] = min(up,min(leftDiagonal,rightDiagonal));
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int j = 0; j<n; j++){
            mini = min(mini,prev[j]); // finding minimum from the last row of the dp array
        }
        return mini;
    }
