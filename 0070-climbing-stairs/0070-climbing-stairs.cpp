class Solution {
public:
//BRUTE
//O(2^n), O(n)
    // int solve(int n){
    //     if(n==0 || n==1){
    //         return 1;
    //     }
    //     return solve(n-1) + solve(n-2);
    // }
    // int climbStairs(int n) {
    //     return solve(n);
    // }


//Optimal
//O(n), O(n)
    vector<int> dp;
    int solve(int n){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solve(n-1) + solve(n-2);
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(n);
    }

};