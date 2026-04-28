// #include <bits/stdc++.h>
// using namespace std;
// int maxi1(unordered_map<int,int>&mp){
//     int maxi=0;
//     for(auto &i:mp){
//         if(i.second>maxi){
//             maxi=i.second;
//         }
//     }
//     return maxi;
// }
// int k1(unordered_map<int,int>&mp){
//     int maxi=0;
//     int k=0;
//     for(auto &i:mp){
//         if(i.second>maxi){
//             maxi=i.second;
//             k=i.first;
//         }
//     }
//     return k;
// }
// vector<int> solve(vector<int>&nums){
//     unordered_map<int,int>mp;
//     for(auto &num:nums){
//         mp[num]++;
//     }
//     vector<int>ans;
//     int alice=0;
//     int bob=0;
//     int i=1;
//     while(!mp.empty()){
//         int maxi=maxi1(mp);
//         int k=k1(mp);
//         if(i%2==1){
//             alice+=maxi;
//         }else{
//             bob+=maxi;
//         }
//         i++;
//         if(mp.find(k-1)!=mp.end()){
//             mp[k-1]+=maxi;
//         }
//         else{
//             mp[k-1]=maxi;
//         }
//         if(mp.find(0)!=mp.end()){
//             mp.erase(0);
//         }xx
//     }
//     ans.push_back(alice);
//     ans.push_back(bob);
//     return ans;
// }
// vector<int> input(int n){
//     vector<int>ab;
//     int a;
//     for( int i=0;i<n;i++){
//         cin>>a;
//         ab.push_back(a);
//     }
//     return solve(ab);
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         int n;
//         cin>>n;
//         vector<int>p=input(n);
//         cout<<p[0]<<" "<<p[1]<<"\n";
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int>canAllPackagesBeDelivered(vector<int>truckCap,vector<int>weights){
    int n1=truckCap.size();
    int n2=weights.size(); 
    sort(weights.begin(),weights.end());
    if(truckCap[n1-1]<weights[n2-1]){
        return {0};
    }
    int j=n2-1;
    multiset<int>ms;
    for(int i=0;i<n1;i++){
        ms.insert(truckCap[i]);
    }
    int k;
    while(j>=0){
        int maxi=*ms.rbegin();
        if(maxi>=weights[j]){
            j--;
            k=maxi/2;
            ms.erase(ms.find(maxi));
            ms.insert(k);
        }

    }
    if(j<0){
        return {1};
    }
    else{
        return {0};
    }
}

#include <bits/stdc++.h>
using namespace std;

void s() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    vector<int> v;
    for (auto p : m) {
        if (p.first != a[0]) {
            v.push_back(p.second);
        }
    }
    sort(v.begin(), v.end());
    int r = 0;
    for (int x : v) {
        if (k >= x) {
            k -= x;
            r++;
        } else {
            break;
        }
    }
    cout << m.size() - r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        s();
    }
    return 0;
}



    long countBoughtItems(long m,vector<int>cost){
        int count=0;
        int i=0;
        int n=cost.size();
        int k=1;
        while(m>=0){
            if(m>=k*cost[i]){
                count++;
                m-=k*cost[i];
                i++;
            }
            else{
                break;
            }
            if(i>n-1){
                i=0;
                k++;
            }
        }
        return count;
    }



    // #include <bits/stdc++.h>
// using namespace std;

// void s() {
    
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--) {
//         s();
//     }
//     return 0;
// }



using ll=long long;
    bool canComplete(vector<int>& time, int totalTrips,ll k){
        unordered_map<int,int>mp;
        for(auto &num:time){
            mp[num]++;
        }
        vector<int>v;
        for(auto &i:mp){
            v.push_back(i.first);
        }
        sort(v.begin(),v.end());
        ll trips=0;
        for(int i=0;i<v.size();i++){
            trips+=(k/v[i])*mp[v[i]];
        }
        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size()==1){
             return totalTrips*time[0];
        }
        ll l=1;
        ll r=1e9;
        ll ans=0;
        while(l<r){
            ll mid=l+((r-l)/2);
            if(canComplete(time, totalTrips, mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }



// (x+6,y);
// (x+3,y);
// (x+2,y+1);

// (x+4,y-1);



// (0,0) -> (x,y);


// (0,0) ->  (14,1)           true

// (2,1)

// (12,0)
// if(p%6==0 || p%3==0){
// return true;  simply
// }


 