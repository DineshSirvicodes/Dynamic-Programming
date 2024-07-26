
// Memoization - TC - O(N*k) Sc - O(n) + O(n)
int func(int ind,vector<int>&arr,vector<int>&dp,int k){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int minSteps = INT_MAX;
    for(int j = 1; j<=k ; j++){
        if(ind-j>=0){
            int jump = func(ind-j,arr,dp,k) + abs(arr[ind]-arr[ind-j]);
            minSteps = min(minSteps,jump);
        }
    }
    return dp[ind] = minSteps;
}

int solve(int n,vector<int>&arr, int k){
    vector<int>dp(n,-1);
    return func(n-1,arr,dp,k);
}

// Tabulation TC - O(N*k) Sc - O(N)
int solve(int n,vector<int>&arr, int k){
    
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i = 1; i<n ; i++){
        int minSteps = INT_MAX;
        for(int j = 1 ;j<=k ;j++){
            if(i-j >= 0){
                int jump = dp[i-j] + abs(arr[i]-arr[i-j]);
                minSteps = min(minSteps,jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}
