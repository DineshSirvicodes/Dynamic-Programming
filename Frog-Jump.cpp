// recrusive sol 
#include <bits/stdc++.h> 
int func(int ind , vector<int>& heights){
    if(ind == 0) return 0;

    int left = func(ind-1,heights) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = func(ind-2,heights) + abs(heights[ind]-heights[ind-2]);
    }
    return min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    return func(n-1,heights);
}

// Memoization  TC - O(N)  , SC  - O(N) + O(N) - recursive stack space
#include <bits/stdc++.h> 
int func(int ind , vector<int>& heights,vector<int>&dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int left = func(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = func(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return func(n-1,heights,dp);
}

//Tabulation TC - O(N) , SC - O(N)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i = 1; i<n ; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

// Space optimization TC - O(N) , SC - O(1)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev = 0;
    int prev2 = 0;
    for(int i = 1; i<n ; i++){
        int left = prev + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr = min(left,right);
        prev2 = prev;
        prev = curr;
    }
    return prev; // at n-1 will be prev
}
