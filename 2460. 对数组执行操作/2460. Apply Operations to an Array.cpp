class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        const int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                continue;
            int j = i + 1;
            while (j < n && !nums[j])
                j++;
            if (j < n)
                swap(nums[i], nums[j]);
        }

        return nums;
    }
};