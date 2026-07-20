class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string result = "";
        vector<bool>taken(26, false);
        vector<int>lastIdx(26);

        for(int i = 0; i < n; i++){
            char ch = s[i];

            lastIdx[ch - 'a'] = i;
        }

        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            if(taken[ch - 'a']){
                continue;
            }
            while(result.size() > 0 && result.back() > ch && lastIdx[result.back() - 'a'] > i){
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[ch - 'a'] = true;
        }
        return result;
    }
};