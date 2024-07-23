// Question is related to move from 0th step to nth step to reach nth step, only 1 step or 2 steps are allowed to reach nth step.
// for n = 3 , we have 3 ways to reach 3rd step,
// 1) 0->1->2->3 , taking 1 step each to reach 3rd, 0 to 1 , is 1 step and so on
// 2) 0->2->3, ie 0 to 2 , 2 steps then 1 step to 3rd
// 3) 0->1->3 
// question is very similiar to Fibonacci , Nth Fibonacci Number
class Solution {
public:
    int fib(int n){
        if(n == 0) return 1; // 0th step is there, then there is only one way.
        if(n == 1) return 1; 
      // fib(n-1) means taking 1 step, and fib(n-2) means 2 steps taken
        return fib(n-1) + fib(n-2);
    }
    int climbStairs(int n) {
        return fib(n);
    }
};
// DP approach, Memoization
class Solution {
public:
    int fib(int n,vector<int>& dp){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (fib(n-1,dp) + fib(n-2,dp));
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};
//  Tabulation
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1); 
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i<= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// Optimization space
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1 , prev = 1;
        for(int i = 2; i<=n ; i++){
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
