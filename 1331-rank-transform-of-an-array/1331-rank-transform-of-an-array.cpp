class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return {};
        }
        unordered_map<int , int>mp;
        vector<int>temp = arr;
        sort(arr.begin(), arr.end());
        mp[arr[0]] = 1;
        int rank  = 2;
        for(int i = 1; i < n; i++){
            if(arr[i] != arr[i-1]){
                mp[arr[i]] = rank;
                rank++;
            }
        }
        for(int i = 0; i < n; i++){
            temp[i] = mp[temp[i]];
        }
        return temp;
    }
};