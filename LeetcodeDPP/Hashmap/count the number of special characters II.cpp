// TC = O(n)
// SC = O(1)
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.size();
        vector<int> mp(26, -1);
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z')
            {
                mp[ch - 'a'] = i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            if (ch >= 'A' && ch <= 'Z')
            {
                if (mp[ch - 'A'] != -1)
                {
                    if (mp[ch - 'A'] > i)
                    {
                        mp[ch - 'A'] = -1;
                    }
                    else
                    {
                        cnt++;
                        mp[ch - 'A'] = -1;
                    }
                }
            }
        }
        return cnt;
    }
};