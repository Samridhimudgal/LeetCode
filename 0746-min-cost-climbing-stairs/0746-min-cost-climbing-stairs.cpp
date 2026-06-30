class Solution {
public:
    // int solve(int n, vector<int>& cost) {
    //     if (n < 0) return 0;
    //     if (n == 0 || n==1) return cost[n];

    //     return cost[n] + min(solve(n - 1, cost), solve(n - 2, cost));
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     return min(solve(n - 1, cost), solve(n - 2, cost));
    // }


    vector<int> dp;
    int solve(int n, vector<int>& cost) {
        if (n < 0) return 0;
        if (n == 0 || n==1) return cost[n];
        if (dp[n] != -1) return dp[n];

        return dp[n] = cost[n] + min(solve(n - 1, cost), solve(n - 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1, -1);
        return min(solve(n - 1, cost), solve(n - 2, cost));
    }
};