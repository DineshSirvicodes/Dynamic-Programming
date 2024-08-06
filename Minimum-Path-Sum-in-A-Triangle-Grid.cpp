// Memoization TC - O(N*N) Sc - O(N*N)
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

//    2
//.   3. 4
//.   6. 5  7
//.   4  1. 8. 3
