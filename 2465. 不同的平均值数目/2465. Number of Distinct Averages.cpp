class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<int> hash;
        int n = nums.size();
        for (int i = 0, j = n - 1; i <= j; i++, j--)
        {
            hash.insert(nums[i] + nums[j]);
        }
        return hash.size();
    }
};