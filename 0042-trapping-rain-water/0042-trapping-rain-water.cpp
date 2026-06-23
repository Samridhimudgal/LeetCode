class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int leftMax = height[0];
        int rightMax = height[n-1];
        left[0] = right[0];
        right[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            left[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }

        for(int i=n-1; i>=0; i--){
            right[i] =rightMax;
            rightMax = max(rightMax, height[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(left[i] > height[i] && right[i] > height[i]){
                ans += min(left[i], right[i]) - height[i];
            }
        }
        return ans;
    }
};