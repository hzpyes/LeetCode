class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        const int n = reward1.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += reward2[i];
            reward1[i] -= reward2[i];
        }
        sort(reward1.rbegin(), reward1.rend());
        res += accumulate(reward1.begin(), reward1.begin() + k, 0);
        return res;
    }
};