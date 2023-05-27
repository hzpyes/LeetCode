class Solution
{
public:
    int get(vector<int> &count, int k)
    {
        int res = 0;
        for (int i = 0; i <= 255; i++)
        {
            res += count[i];
            if (res >= k)
                return i;
        }
        return -1;
    }

    vector<double> sampleStats(vector<int> &count)
    {
        vector<double> res(5);
        // 样本中的最小元素。
        for (int i = 0; i <= 255; i++)
            if (count[i] != 0)
            {
                res[0] = i;
                break;
            }
        // 样品中的最大元素
        for (int i = 255; i >= 0; i--)
            if (count[i] != 0)
            {
                res[1] = i;
                break;
            }
        // 样本的平均值
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i <= 255; i++)
        {
            if (count[i])
            {
                sum += (double)count[i] * i;
                cnt += count[i];
            }
        }
        res[2] = sum / cnt;
        // 样本中位数 (由于样本数量非常大，数据量超过了10^9，不能用简单的排序去做)
        // 做法：统计当前一共出现了多少个数，如果当前出现次数第一次>=k，那么当前的数就是第k个数
        if (cnt & 1)
            res[3] = get(count, cnt / 2 + 1);
        else
            res[3] = (get(count, cnt / 2) + get(count, cnt / 2 + 1)) / 2.0;
        // 样本中出现次数最多的数字
        int t = 0;
        for (int i = 1; i <= 255; i++)
            if (count[i] > count[t])
                t = i;
        res[4] = t;
        return res;
    }
};