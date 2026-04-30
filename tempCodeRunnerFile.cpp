#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++){
        cin >> m[i];
    }
    vector<int>two, three, six, other;
    for (int i = 0; i < n; i++){
        if(m[i] % 6 == 0){
            six.push_back(m[i]);
        }
        else if(m[i] % 3 == 0){
            three.push_back(m[i]);
        }
        else if(m[i] % 2 == 0){
            two.push_back(m[i]);
        }
        else{
            other.push_back(m[i]);
        }
    }
    for(int x : two)cout << x << " ";
    for(int x : other)cout << x << " ";
    for(int x : three)cout << x << " ";
    for(int x : six)cout << x << " ";
    cout<<endl;
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