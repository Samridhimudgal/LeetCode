class Solution {
public:

    void bfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;

        vector<int> delRows = {-1, 0, 1, 0}; 
        vector<int> delCols = {0, 1, 0, -1}; 

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();


            for (int i = 0; i <= 3; i++){
                int nRow = delRows[i] + row;
                int nCol = delCols[i] + col;
                if(nRow < n && nRow >=0 && nCol < m && nCol >= 0){
                    if(grid[nRow][nCol] == '1' && !vis[nRow][nCol]){

                        vis[nRow][nCol] = true;
                        q.push({nRow, nCol});
                    }
                }

            }
        }
    }

    // t.c: O(n*m) +  O((n*m) * 4)...
    // s.c: O(n*m) + O(n*m)... 
    int numIslands(vector<vector<char>>& grid) {
        int cnt =0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return cnt;
    }
    
};
