class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n){
        if(n<0) return 0;
        if (dp[n] != -1) {return dp[n];}

        return dp[n] = max(solve(nums,n-2) + nums[n], solve(nums, n-1));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return solve(nums, n-1);
    }
};