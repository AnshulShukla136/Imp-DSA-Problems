
// simulation make separate vector and push into it then make it rotate then push again
class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {

        int n = grid.size();
        int m = grid[0].size();

        int layers = min(n, m) / 2;

        for (int layer = 0; layer < layers; layer++)
        {

            vector<int> temp;

            int top = layer;
            int left = layer;
            int bottom = n - layer - 1;
            int right = m - layer - 1;

            // temp filling

            for (int j = left; j <= right; j++)
                temp.push_back(grid[top][j]);

            for (int i = top + 1; i < bottom; i++)
                temp.push_back(grid[i][right]);

            for (int j = right; j >= left; j--)
                temp.push_back(grid[bottom][j]);

            for (int i = bottom - 1; i > top; i--)
                temp.push_back(grid[i][left]);

            int len = temp.size();

            int rot = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++)
            {
                rotated[i] = temp[(i + rot) % len];
            }

            int idx = 0;

            // put back

            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            for (int i = top + 1; i < bottom; i++)
                grid[i][right] = rotated[idx++];

            for (int j = right; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};