class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int i = 0;

        while (i < n - 1) {
            int j = i;

            // Climb up
            while (j < n - 1 && arr[j] < arr[j + 1]) {
                j++;
            }

            // If no increasing part, move ahead
            if (j == i) {
                i++;
                continue;
            }

            // Climb down
            int peak = j;
            while (j < n - 1 && arr[j] > arr[j + 1]) {
                j++;
            }

            // Valid mountain
            if (peak != j) {
                ans = max(ans, j - i + 1);
            }

            i = max(i + 1, j);
        }

        return ans;
    }
};