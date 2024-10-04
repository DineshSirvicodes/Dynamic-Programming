// Brute Sol - Recursive Sol - TC - O(2^n) SC - O(N)- auxiliary stack space
class Solution{   
public:
    bool f(int ind,int target,vector<int>&arr){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        
        bool NotTake = f(ind-1,target,arr);
        bool Take = false;
        if(target >= arr[ind]){
            Take = f(ind-1,target-arr[ind],arr);
        }
        return Take|NotTake;
    }
    
    bool isSubsetSum(vector<int>arr, int target){
        // code here 
        int n = arr.size();
        return f(n-1,target,arr);
    }
};

// Memoization - TC- O(N*target ) SC - O(N*target) + O(N), - stack space
class Solution{   
public:
    bool f(int ind,int target,vector<int>&arr,vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool NotTake = f(ind-1,target,arr,dp);
        bool Take = false;
        if(target >= arr[ind]){
            Take = f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target] = Take|NotTake;
    }
    
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};

// Tabulation - TC - O(N* target) Sc - O(N*target)
class Solution{   
public:  
    bool isSubsetSum(vector<int>arr, int k){
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(k+1,0)); // initially all false;
        for(int i = 0; i<n; i++){
            dp[i][0] = true; // if target == 0 at any given ind, we return true;
        }
        if(arr[0]<=k) dp[0][arr[0]] = true; // if at ind == 0 , if we get the target , we return true;
        //or directly dp[0][arr[0]] = true;
        for(int ind = 1 ; ind<n; ind++){
            for(int target = 1; target<=k; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(target >= arr[ind]){
                    take = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n-1][k];
    }
};
// Space Optimization - TC - O(N*K) , Sc O(K+1) or simply O(K)
class Solution{   
public:
    // bool f(int ind,int target,vector<int>&arr,vector<vector<int>> &dp){
    //     if(target == 0) return true;
    //     if(ind == 0) return (arr[0] == target);
    //     if(dp[ind][target] != -1) return dp[ind][target];
    //     bool NotTake = f(ind-1,target,arr,dp);
    //     bool Take = false;
    //     if(target >= arr[ind]){
    //         Take = f(ind-1,target-arr[ind],arr,dp);
    //     }
    //     return dp[ind][target] = Take|NotTake;
    // }
    
    bool isSubsetSum(vector<int>arr, int k){
        int n = arr.size();
        // initially all false;
        // if target == 0 at any given ind, we return true;
        // if at ind == 0 , if we get the target , we return true;
        vector<bool> prev(k+1,0), curr(k+1,0);
        prev[0] = curr[0] = true; 
        prev[arr[0]] = true;
        for(int ind = 1 ; ind<n; ind++){
            for(int target = 1; target<=k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[ind]){
                    take = prev[target-arr[ind]];
                }
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
};
