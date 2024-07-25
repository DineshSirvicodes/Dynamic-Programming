// Recursive Sol - Exponential Solution
int func(int n){
  if(n<=1) return n;
  return func(n-1) + func(n-2);
}

//  Dynamic Approach

// 1) Memoization - Top Down Approach, If a problem was solved, it is stored in a ds like array, and next time if the problem is encountered again , we can easily take the values from the already stored before;
int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}
// TC - O(N) , SC - O(N) for recursive stack ,and O(N) for extra array dp
// returning to mod 10^7, for large answers, GeeksforGeeks Sol
const int mod = 1e9+7;
class Solution {
  public:
    
    int fib(int n, vector<int>&dp){
        if(n<0) return 0;
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (fib(n-1,dp) + fib(n-2,dp)) % mod;
        
    }
  
    int nthFibonacci(int n){
       vector<int> dp(n+1,-1);
       int res = fib(n,dp);
       return res;
    }
};

int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  cout<<f(n,dp);
  return 0;
}
//2) Tabulation- Start from the base case and move up to the final N,bottom-up
// TC - O(N) , SC - O(N) - > O(N) is the extra array, no recursion stack needed
int nthFibonacci(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//3) Optimizing Space Complexity - O(N) -> O(1)
// predefining variables. for each iteration, the prev- (i-1) And prev2 - (i-2) are already repeating at next iteration, so we can store these values and use again.
// Refer takeuforward. https://takeuforward.org/data-structure/dynamic-programming-introduction/
int nthFibonacci(int n){
    int prev2 = 0, prev = 1;
    for(int i = 2; i<=n ; i++){
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
