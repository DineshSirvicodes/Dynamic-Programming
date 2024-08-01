// Same as maximum sum of non-ajacent elements
// problem is a continuation of house robber , LC - 198
// now the houses are in circle, so now first and last element cannot be taken together, instead we take 2 new arrays and push separate values ,in which
// one array contains the elements apart from first , and second array contains the elements from the nums array apart the last element, and call the function to return the max sum in both
// the arrays and take the maximum of their sums.
// TC - O(N) SC - O(1)
class Solution {
public:
    int func(vector<int>& nums){
        int n = nums.size();
        int prev = nums[0];  // i - 1
        int prev2 = 0;          // i-2
        for(int i = 1 ; i<n; i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int nottake = 0 + prev;
            int curr = max(take,nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1,temp2;
        for(int i = 0 ; i<n ; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(func(temp1),func(temp2));
    }
};
