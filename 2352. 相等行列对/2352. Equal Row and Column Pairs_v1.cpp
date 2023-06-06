class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        const int n = grid.size();

        unordered_map<vector<int>, int> hash;

        // 将每一列存入哈希表
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                tmp.push_back(grid[j][i]);
            }
            hash[tmp]++;
        }

        int cnt = 0;
        // 查询每一行是否出现过
        for (auto &g : grid)
        {
            if (hash.find(g) != hash.end())
            { // 出现过
                cnt += hash[g];
            }
        }
        return cnt;
    }
};