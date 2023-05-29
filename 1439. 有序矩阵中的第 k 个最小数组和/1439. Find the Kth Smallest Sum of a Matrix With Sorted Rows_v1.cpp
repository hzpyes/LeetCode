class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        const int n = mat.size();
        const int m = mat[0].size();

        vector<int> heap;
        heap.push_back(0);

        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < heap.size(); k++)
                {
                    tmp.push_back(mat[i][j] + heap[k]);
                }
            }
            heap.swap(tmp);
            sort(heap.begin(), heap.end());
            heap.resize(min(k, (int)heap.size()));
            // while (heap.size() > k) heap.pop_back(); // 这样写好理解，但耗时了
        }
        return heap.back();
    }
};