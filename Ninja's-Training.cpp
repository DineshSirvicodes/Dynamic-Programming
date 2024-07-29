// Codestudio problem -> 
//Memoization TC - O(N*4*3) , where N*4 states with 3 times check for for loop, SC = O(N) + O(N*4)

#include<bits/stdc++.h>
int func(int day,int last, vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task<3 ; task++){
            if(task!=last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for(int task = 0; task<3 ; task++){
        if (task != last) {
            int point = points[day][task] + func(day - 1, task,points,dp);
            maxi = max(maxi,point);
        }
        
    }
    return dp[day][last] = maxi;
}   

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return func(n-1,3,points,dp);
}

// Tabulation TC - O(N*4*3) SC - O(N*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // define dp 2d array of size N*4; where N is the no. of days and 4 represents the tasks cols 0 , 1, 2 ,3
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1] , points[0][2]);
    dp[0][1] = max(points[0][0] , points[0][2]);
    dp[0][2] = max(points[0][0] , points[0][1]);
    dp[0][3] = max(points[0][0] , max(points[0][1],points[0][2]));
    
    // start from day 1 to n-1
    for(int day = 1 ; day<n ; day++){
        for(int last = 0 ; last<4 ; last++){
            dp[day][last] = 0;
            // iterate thru the task for the given day

            for(int task = 0 ;task<=2 ;task++){
                if(task!=last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
    
}

// Space Optimization  TC - O(N*4)*3  SC - O(4) -> O(1) constant time
int ninjaTraining(int n, vector<vector<int>> &points)
{
    
    vector<int> prev(4,0);
    prev[0] = max(points[0][1] , points[0][2]);
    prev[1] = max(points[0][0] , points[0][2]);
    prev[2] = max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][0] , max(points[0][1],points[0][2]));
    
    // start from day 1 to n-1
    for(int day = 1 ; day<n ; day++){
        vector<int> temp(4,0);
        for(int last = 0 ; last<4 ; last++){
            temp[last] = 0;
            // iterate thru the task for the given day

            for(int task = 0 ;task<=2 ;task++){
                if(task!=last){
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last],point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
    
}
