class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        long long xr = 0;

        for (auto &row : grid) {
            for (int num : row) {
                xr ^= num;
            }
        }

        for (int i = 1; i <= N; i++) {
            xr ^= i;
        }

        int bitNo = 0;
        while (((xr & (1 << bitNo)) == 0)) {
            bitNo++;
        }

        int zero = 0, one = 0;

        for (auto &row : grid) {
            for (int num : row) {
                if ((num & (1 << bitNo)) != 0)
                    one ^= num;
                else
                    zero ^= num;
            }
        }

        for (int i = 1; i <= N; i++) {
            if ((i & (1 << bitNo)) != 0)
                one ^= i;
            else
                zero ^= i;
        }

        int cnt = 0;
        for (auto &row : grid) {
            for (int num : row) {
                if (num == zero)
                    cnt++;
            }
        }

        if (cnt == 2)
            return {zero, one}; // zero = repeated, one = missing
        return {one, zero}; // one = repeated, zero = missing
    }
};