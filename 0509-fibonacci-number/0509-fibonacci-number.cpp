class Solution {
public:
//BRUTE FORCE
//TC: O(2^n)
    // int solve(int n){
    //     if(n==0 || n==1){
    //         return n;
    //     }
    //     return solve(n-1) + solve(n-2);
    // }

    // int fib(int n) {
    //     return solve(n);
    // }


//BETTER 
    // vector<int> dp;
    // int solve(int n){
    //     if(n==0 || n==1){
    //         return n;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     return dp[n] = solve(n-1) + solve(n-2);
    // }

    // int fib(int n) {
    //     dp.resize(n+1, -1);
    //     return solve(n);
    // }


//OPTIMAL
    int fib(int n) {
        if(n <= 1) return n;
        int a=0, b=1;
        for(int i=2; i<=n; i++){
            int temp =b;
            b = a+b;
            a = temp;
        }
        return b;
    }
};

