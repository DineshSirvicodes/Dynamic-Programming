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
