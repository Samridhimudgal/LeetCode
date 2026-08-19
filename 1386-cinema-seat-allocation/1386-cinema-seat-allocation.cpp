class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            rows[seat[0]] |= (1 << (seat[1] - 1));
        }

        int ans = (n - rows.size()) * 2;

        int left  = 0b0000011110;
        int mid   = 0b0001111000;
        int right = 0b0111100000;

        for (auto &[row, mask] : rows) {
            bool L = (mask & left) == 0;
            bool M = (mask & mid) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                ans += 2;
            else if (L || M || R)
                ans += 1;
        }

        return ans;
    }
};