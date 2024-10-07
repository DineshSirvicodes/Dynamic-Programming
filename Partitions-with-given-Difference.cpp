// Question changed to work as Count subsets with given sum
// Total Sum = S , s1 + s2 = S . Two subsets that give the total sum S.
// Now in this question - 
// https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628?interviewProblemRedirection=true&search=partitions&leftPanelTabValue=PROBLEM
// Subset difference is d, and we know s1 + s2 = totalSum
// s1 - s2 = d, and s1 + s2 = S . So S-s2 - s2 = d, then s2 = S(totalSum) - D / 2; so we already can get s1 ,and now from this we can easily find s2.
// Memoization Sol - TC - O(N*K) SC - O(N*K) + O(N)

// Tabulation Sol TC - O(N*K) SC - O(N*K)
#include <bits/stdc++.h>
int mod = 1e9+7;
int findWays(vector<int>& num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){       
            int notTaken = dp[ind-1][target];
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here
    int totalSum = accumulate(arr.begin(),arr.end(),0);
    
    if(totalSum - d < 0 || (totalSum - d)%2 == 1) return false;
    // this should not be negative and should not be odd
    return findWays(arr,(totalSum-d)/2);
    
}



// Space Optimization Sol

