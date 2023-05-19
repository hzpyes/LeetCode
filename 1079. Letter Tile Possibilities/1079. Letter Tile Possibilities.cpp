class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        sort(tiles.begin(), tiles.end());
        unordered_set<string> hash;
        do
        {
            for (int len = 1; len <= tiles.size(); len++)
            {
                for (int i = 0; i + len - 1 < tiles.size(); i++)
                {
                    hash.insert(tiles.substr(i, len));
                }
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        return hash.size();
    }
};