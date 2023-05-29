class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int sum = 0, cnt = 0;
        for (auto &num : nums)
        {
            if ((num % 3 == 0) && (num & 1) == 0)
            {
                sum += num;
                cnt++;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};