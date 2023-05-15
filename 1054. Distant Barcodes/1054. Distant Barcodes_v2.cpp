class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> hash;
        for (auto &c : barcodes)
            hash[c]++; // <num, freq>

        vector<pair<int, int>> temp; // <freq, num>
        for (auto &x : barcodes)
            temp.push_back({hash[x], x});
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        int i = 0, n = barcodes.size();
        vector<int> res(n);
        for (auto &t : temp)
        {
            res[i] = t.second;
            i += 2;
            if (i >= n)
                i = 1;
        }
        return res;
    }
};