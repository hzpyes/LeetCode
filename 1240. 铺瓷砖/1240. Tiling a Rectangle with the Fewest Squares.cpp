class Solution
{
public:
    int res;
    int n, m;
    vector<vector<bool>> st;

    bool check(int x, int y, int len)
    {
        for (int i = x; i < x + len; i++)
        {
            for (int j = y; j < y + len; j++)
            {
                if (st[i][j])
                    return false;
            }
        }
        return true;
    }

    void fill(int x, int y, int len, bool t)
    {
        for (int i = x; i < x + len; i++)
        {
            for (int j = y; j < y + len; j++)
            {
                st[i][j] = t;
            }
        }
    }

    void dfs(int x, int y, int cnt)
    {
        if (cnt >= res)
            return;
        if (y == m)
            x++, y = 0;
        if (x == n)
            res = cnt;
        else
        {
            if (st[x][y]) // 这个格子被搜过了, 递归搜索下一个
                dfs(x, y + 1, cnt);
            else
            {
                for (int len = min(n - x, m - y); len; len--)
                {
                    if (check(x, y, len))
                    { // 判断以x，y为左上角，变成为len的矩形是不是空的
                        fill(x, y, len, true);
                        dfs(x, y + 1, cnt + 1);
                        fill(x, y, len, false);
                    }
                }
            }
        }
    }

    int tilingRectangle(int n, int m)
    {
        this->n = n, this->m = m;
        res = n * m;
        st = vector<vector<bool>>(n, vector<bool>(m));
        dfs(0, 0, 0);

        return res;
    }
};