// optimal O(n) solution
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> ans;

        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            mp[A[i]]++;
            mp[B[i]]++;
            if (mp[A[i]] == 2 && mp[B[i]] == 2 && A[i] != B[i])
            {
                cnt += 2;
            }
            else if (mp[A[i]] == 2 && mp[B[i]] == 2 && A[i] == B[i])
            {
                cnt += 1;
            }
            else if (mp[B[i]] == 2 || mp[A[i]] == 2)
            {
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};