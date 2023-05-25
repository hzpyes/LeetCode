class Solution
{
public:
    string oddString(vector<string> &words)
    {
        unordered_map<string, int> hash1;
        unordered_map<string, int> hash2;
        for (int i = 0; i < words.size(); i++)
        {
            string temp;
            for (int j = 0; j < words[0].size() - 1; j++)
            {
                temp += to_string(words[i][j + 1] - words[i][j]);
                temp += "."; // 为了避免出现[1,11]和[11,1]这种会误认为一样，加一个特殊符号
            }
            hash1[temp]++;   // 将 差值整数数组 转成字符串方便存哈希表记录是否重复
            hash2[temp] = i; // 方便将答案还原
        }
        string res;
        for (auto it = hash1.begin(); it != hash1.end(); it++)
        {
            if (it->second == 1)
            {
                int index = hash2[it->first];
                res = words[index];
            }
        }
        return res;
    }
};