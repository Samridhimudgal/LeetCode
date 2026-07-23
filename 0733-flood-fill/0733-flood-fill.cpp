class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,
             int oldColor, int newColor) {

        int n = image.size();
        int m = image[0].size();

        // Out of bounds
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        // Different color
        if (image[row][col] != oldColor)
            return;

        // Color the current cell
        image[row][col] = newColor;

        // Traverse in 4 directions
        dfs(image, row + 1, col, oldColor, newColor);
        dfs(image, row - 1, col, oldColor, newColor);
        dfs(image, row, col + 1, oldColor, newColor);
        dfs(image, row, col - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};