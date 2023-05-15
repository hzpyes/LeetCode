class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> hash;
        for (auto &c : barcodes)
            hash[c]++; // <num, freq>

        priority_queue<pair<int, int>> pq; // {freq, num};

        for (auto &h : hash)
            pq.push({h.second, h.first});

        vector<int> res;
        while (!pq.empty())
        {
            if (pq.size() == 1 && pq.top().first > 1)
                return {};

            int len = pq.size();
            vector<pair<int, int>> temp; //
            for (int i = 0; i < min(2, len); i++)
            { // 取前2大频率的两种数
                res.push_back(pq.top().second);
                if (pq.top().first > 1) // 需要加一个判断，如果这个数的频率只有一次了，下次就不需要再加入堆了
                    temp.push_back({pq.top().first, pq.top().second});
                pq.pop();
            }
            for (auto t : temp)
            {
                t.first--;
                pq.push(t);
            }
        }
        return res;
    }
};