//Memoization Sol TC - O(N*K) SC - O(N*K) + O(N);

int MOD = 1e9+7;
int f(int ind, int sum,vector<int>&arr,vector<vector<int>> &dp){
	
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
	if(dp[ind][sum] != -1) return dp[ind][sum];
	int notpick = f(ind-1,sum,arr,dp);
	int pick = 0;
    if (arr[ind] <= sum) {
        pick = f(ind - 1, sum - arr[ind], arr, dp);
    }
    return dp[ind][sum] = (pick + notpick)%MOD;
}

int findWays(vector<int>& num, int k)
{
	int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,num,dp);
}


// Tabulation TC - O(N*K) SC - O(N*K);
int findWays(vector<int>& num, int k)
{
	int n = num.size();

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first row based on the first element of the array
    if (num[0] <= k) {
        dp[0][num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
              taken = dp[ind - 1][target - num[ind]];
            }

            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
}

// Space Optimization TC - O(N*K) SC - O(K)
int MOD = 1e9+7;
int findWays(vector<int>& num, int k)
{
	int n = num.size();

    vector<int> prev(k+1,0), curr(k+1,0);
    prev[0] = curr[0] = 1;
    if (num[0] <= k) {
        prev[num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
              taken = prev[target - num[ind]];
            }

            // Update the DP table
            curr[target] = (notTaken + taken)%MOD;
        }
		prev = curr;
    }

    // The final result is in the last cell of the DP table
    return prev[k];
}
