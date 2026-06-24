class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++) {
            int ans = 0;  // reset for each row

            for(int j = 0; j < m; j++) {
                ans += mat[i][j];
            }

            pq.push({ans, i});
        }

        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};