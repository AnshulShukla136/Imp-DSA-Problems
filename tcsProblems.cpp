#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    int n;
    getline(cin, s);
    cin>>n;
    unordered_map<string, int>mp;
    string str = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            mp[str]++;
            str= "";
        }else{
            str.push_back(s[i]);
        }
    }
    int maxi = 0;
    for(auto &i : mp){
        maxi = max(maxi, i.second);
    }
    for(auto &i : mp){
        if(i.second == maxi){
            cout << i.first << ": " << i.second << endl; 
        }
    }
}
