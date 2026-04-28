#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int a ,b;
    cin >> a >> b;                    
    
    int count = 0;
    if(b == 1){
        count++;
        b++;
    }
    int p  = 0;
    while(a>0){
        if(a < b){
            count++;
            break;
        }
     
        a=a/b;
        if(a==0)break;
        count++;
        b++;
        count++;    
    }
    cout<<count<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}