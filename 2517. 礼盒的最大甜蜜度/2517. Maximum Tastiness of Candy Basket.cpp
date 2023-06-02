class Solution
{
public:
    int maximumTastiness(vector<int> &price, int k)
    {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        int res = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(price, k, mid))
            {
                res = mid;   // 可能是潜在答案，记录一下;
                l = mid + 1; // 去更大的地方试着找
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }

    bool check(vector<int> &price, int k, int target)
    {
        int pre = price[0];
        int cnt = 1;
        for (int i = 1; i < price.size(); i++)
        {
            if (price[i] - pre >= target)
            {
                cnt++;
                pre = price[i];
            }
        }
        return cnt >= k;
    }
};
