// Memoization TC - O(N*N) Sc - O(N*N), for recursive stack space , O(N*N) for dp array
class Solution {
public:
    int findPathSum(int i, int j, vector<vector<int>>&arr, vector<vector<int>>&dp,int N){
        if(i == N-1) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = INT_MAX,diagonal = INT_MAX;
        down = arr[i][j] + findPathSum(i+1,j,arr,dp,N);
        diagonal = arr[i][j] + findPathSum(i+1,j+1,arr,dp,N);
        return dp[i][j] = min(down,diagonal);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return findPathSum(0,0,triangle,dp,n);
    }
};


// Tabulation TC - O(N*N) Sc - O(N*N) 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
     
        for(int j = 0; j<n ; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2 ;i>=0 ;i--){
            for(int j = i ; j>=0; j--){
                int down = INT_MAX,diagonal = INT_MAX;
                down = triangle[i][j] + dp[i+1][j];
                diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }

// Space Optimization TC - O(N*N) SC - O(N) for storing the row 
   int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0);
        
        for(int j = 0; j<n ; j++){
            front[j] = triangle[n-1][j]; // storing the last row, n-1th row
        }
        for(int i = n-2 ;i>=0 ;i--){
            vector<int> curr(n,0); // n-2th row till 0th row
            for(int j = i ; j>=0; j--){
                int down = INT_MAX,diagonal = INT_MAX;
                down = triangle[i][j] + front[j];
                diagonal = triangle[i][j] + front[j+1];
                curr[j] = min(down,diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};

//    2
//.   3. 4
//.   6. 5  7
//.   4  1. 8. 3
