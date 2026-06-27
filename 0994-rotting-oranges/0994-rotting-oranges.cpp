class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = -1;
        queue<pair<int, int>> q;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int,int>p = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dx[i];
                    int c=p.second+dy[i];
                    if(r>=0 && r<n && c>=0 && c<m &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            minutes++;
        }
        if(fresh>0) return -1;
        if(minutes==-1) return 0;
        return minutes;
    }
};