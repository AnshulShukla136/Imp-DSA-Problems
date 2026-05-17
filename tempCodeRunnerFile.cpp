#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,x1,x2,k;
    cin>>n>>x1>>x2>>k;

    int dis = abs(x1-x2);

    dis = min(dis, n-dis);

    cout<<dis+k<<endl;
    
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}