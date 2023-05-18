class Solution
{
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());

        vector<int> res;
        int a = 0, b = 0, c = 0; // 第二个进位，第一个进位，当前位
        for (int i = 0; i < arr1.size() || i < arr2.size() || a || b; i++)
        {
            if (a == 1 && b == 2)
                a = b = 0; // 抵消掉，避免无限循环
            c = b, b = a, a = 0;
            if (i < arr1.size())
                c += arr1[i];
            if (i < arr2.size())
                c += arr2[i];
            res.push_back(c & 1); // c&1 判断奇数还是偶数
            c >>= 1;
            a += c, b += c;
        }
        // 去除前导0
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();

        reverse(res.begin(), res.end());
        return res;
    }
};