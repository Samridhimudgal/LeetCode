class Solution {
public:
    vector<int> t;

    bool solve(int n){

        if(n==0){
            return false;
        }

        if(t[n] != -1){
            return t[n] == 1 ? true : false;
        }

        for(int k=1; k*k <= n; k++){
            if(solve(n-(k*k)) == 0){
                return t[n] = true;   //call for bob, h loses and alice wins
            }
        }
        return t[n] = false;
    }

    bool winnerSquareGame(int n) {
        t.assign(n+1, -1);
        return solve(n);  //call for alice, if true alice wins if false she looses
    }
};