class Solution
{
public:
    int storeWater(vector<int> &bucket, vector<int> &vat)
    {
        int n = bucket.size();
        int maxVat = 0;
        for (auto &v : vat)
            maxVat = max(v, maxVat);
        if (maxVat == 0)
            return 0; // 特判

        int res = INT_MAX;
        for (int k = 1; k <= maxVat; k++)
        { // 枚举假设最终需要蓄水次数为k次
            if (k >= res)
                break;
            int t = 0; // 记录需要升级的总次数
            for (int i = 0; i < bucket.size(); i++)
            { // 枚举每个水桶
                // 第i个水桶在蓄水操作前的容量为vat[i] / k(向上取整),那么做差就能知道升级的次数
                t += max(0, (vat[i] + k - 1) / k - bucket[i]);
            }
            res = min(t + k, res);
        }
        return res;
    }
};