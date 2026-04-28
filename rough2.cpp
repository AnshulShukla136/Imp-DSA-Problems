// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// bool isSorted(vector<int>&nums){
//     for(int i=0;i<nums.size()-1;i++){
//         if(nums[i]>nums[i+1]){
//             return false;
//         }
//     }
//     return true;
// }
// int solve(vector<int>&nums){
//     vector<int>temp;
//     if(isSorted(nums))return 0;
//     int ans=INT_MAX;
//     for(int i=0;i<nums.size();i++){
//         temp.push_back(nums[i]);
//         sort(temp.begin(),temp.end());
//         for(int j=i+1;j<nums.size();j++){
//             temp.push_back(nums[j]);
//         }
//         if(isSorted(temp)){
//             ans=min(ans,nums[i]);
//         }
//          for(int j=i+1;j<nums.size();j++){
//              temp.pop_back();
//          }
//     }
//     return ans;
// }
// int solve1(int n){
//     vector<int>nums;
//     int a;
//     for( int i=0;i<n;i++){
//         cin>>a;
//         nums.push_back(a);
//     }
//     return solve(nums);
// }
// int main() {
// 	// your code goes here
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         int n;
//         cin>>n;
//         cout<<solve1(n)<<endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int dp[101][101];
// int solve1(vector<int>&nums,int n,int i,int watch){
//     if(i>=n)return 0;
//     int sell1=0,sell2=0;
//     if(dp[i][watch]!=-1)return dp[i][watch];
//     int sell0=solve1(nums,n,i+1,watch+1);
//     if(watch>=1){
//          sell1=nums[i]+solve1(nums,n,i+1,watch);

//     }
//     if(watch>=2){
//         sell2=nums[i]*2+solve1(nums,n,i+1,watch-1);
//     }
//     return dp[i][watch]=max(sell0,max(sell1,sell2));
// }

// #include <bits/stdc++.h>
// using namespace std;

// int solve(string s,int n){
//     for(int i=0;i<n;i++){
//         int ch=s[i];
//         if(ch>=65 && ch<=90){
//             s[i]=ch+32;
//         }
//     }
//     unordered_map<int,int>mp;
//     for(auto &ch:s){
//         mp[ch]++;
//     }
//     int count=0;
//     char character=0;
//     int maxi=0;
//     for(int j=0;j<2;j++){
//         for(auto &i:mp){
//             if(i.second>maxi){
//                 maxi=i.second;
//                 character=i.first;
//             }            
//         }
//         count+=maxi;
//         mp.erase(character);
//         maxi=0;
//     }
//     return count;
// }
// int main() {
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         int n;
//         string s;
//         cin>>n>>s;
//         cout<<solve(s,n)<<endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
void solve(vector<long long>&nums){
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n);
    ans[n-1]=-1;
    st.push(nums[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && nums[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;   
        }else{
            ans[i]=st.top();
        }
        st.push(nums[i]);
        
    }
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   

    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

       solve(arr);
        
    }

    return 0;
}