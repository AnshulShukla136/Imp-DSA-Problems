// TC = O(n);
// SC = O(n);

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_map<int, int> mp;
        for (char ch : word)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                int c = ch;
                mp[c]++;
            }
        }
        int cnt = 0;
        for (char ch : word)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                if (mp.find(32 + ch) != mp.end())
                {
                    cnt++;
                    mp.erase(ch + 32);
                }
            }
        }
        return cnt;
    }
};