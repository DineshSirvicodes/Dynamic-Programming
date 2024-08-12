// reCursive sol - TC - nearly O(2^n) 
// Leetcode - problem 198 house robber

// Memoization Tc - O(N) SC - O(N) + O(N)-recursive stack space
class Solution {
public:
    int func(int ind,vector<int>&nums, vector<int>&dp){
        if(ind == 0) return nums[ind];
        if(ind<0) return 0;

        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + func(ind-2,nums,dp);
        int notpick = 0 + func(ind-1,nums,dp);
        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(n-1,nums,dp);
    }
};

// Tabulation  TC - O(N) Sc - O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        // int negative = 0 , if( i<0) return 0;
        for(int i = 1; i<n; i++){
            int pick = nums[i];        // i<1 edge case taken care
            if(i>1) pick+=dp[i-2]; 
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
};

// Space optimization SC - O(1) ,TC -O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0]; // prev -> i-1, prev2-> i-2
        int prev2 = 0; // handles i<1 cases too
        for(int i = 1; i<n ; i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int nottake = 0 + prev;
            int curr = max(take,nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
