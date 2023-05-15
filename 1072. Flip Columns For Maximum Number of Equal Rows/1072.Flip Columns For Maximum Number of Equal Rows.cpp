class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> hash;

        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            string a, b;
            for (auto &c : matrix[i])
            {
                a += to_string(c);
                b += to_string(c ^ 1);
            }
            res = max(res, max(++hash[a], ++hash[b]));
        }
        return res;
    }
};