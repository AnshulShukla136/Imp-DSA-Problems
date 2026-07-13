class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        for(char &ch: s){
            if(ch == '#' && !s1.empty()){
                s1.pop_back();
            }
            else if(ch != '#'){
                s1.push_back(ch);
            }
        }
        string s2 = "";
        for(char &ch: t){
            if(ch == '#' && !s2.empty()){
                s2.pop_back();
            }
            else if(ch != '#'){
                s2.push_back(ch);
            }
        }
        return s1 == s2;
    }
};