// Same as Subset sum equal to target , with little Modification, for Array Sum as odd, it is not possible to find 2 subsets that give equal sum
// only for Equal sum array , we can use the TotalSum/2 to be the target to be found in the array
// Memoization TC -  O(N*K) + O(N), where O(N) extra is to calculate sum. SC - O(N*K) + O(N) - recursive stack space
class Solution {
public:
    bool f(int ind,int k, vector<int>&nums, vector<vector<int>>&dp){
        if(k == 0) return true;
        if(ind == 0) return (nums[0] == k);
        if(dp[ind][k] != -1) return dp[ind][k];
        bool NotTake = f(ind-1,k,nums,dp);
        bool Take = false;
        if(k >= nums[ind]){
            Take = f(ind-1,k-nums[ind],nums,dp);
        }
        return dp[ind][k] = Take | NotTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int TotalSum = accumulate(nums.begin(),nums.end(),0);
        if(TotalSum % 2 != 0) return false;
        else{
            int k = TotalSum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return f(n-1,k,nums,dp);
        }    
    }
};
// Tabulation - O(N*K) + O(N) , SC - O(N*K) 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int TotalSum = accumulate(nums.begin(),nums.end(),0);
        if(TotalSum % 2 != 0) return false;
        int k = TotalSum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i = 0 ; i<n ; i++){
            dp[i][0] = true;
        }
        if(nums[0]<=k) dp[0][nums[0]]=true;
        for(int ind = 1; ind < n ; ind++){
            for(int target = 1; target<=k; target++){
                bool NotTake = dp[ind-1][target];
                bool Take = false;
                if(target >= nums[ind]){
                    Take = dp[ind-1][target-nums[ind]];
                }
                dp[ind][target] = Take|NotTake;
            }
            
        }
        return dp[n-1][k];
      
    }
};
