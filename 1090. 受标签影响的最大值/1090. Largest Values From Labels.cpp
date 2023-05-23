class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        int n = values.size();

        vector<pair<int, int>> match;
        for (int i = 0; i < n; i++)
            match.push_back({values[i], labels[i]});

        sort(match.begin(), match.end(), greater<pair<int, int>>());

        int res = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            int value = match[i].first, label = match[i].second;
            if (numWanted > 0 && hash[label] < useLimit)
            {
                res += value;
                hash[label]++;
                numWanted--;
            }
        }
        return res;
    }
};