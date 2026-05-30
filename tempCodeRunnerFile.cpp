#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, s;
    cin >> n >> x >> s;

    string st;
    cin >> st;

    long long eia = 0;  
    int empty = x;
    int ans = 0;

    for (char c : st) {
        if (c == 'I') {
            if (empty > 0) {
                empty--;
                eia += (s - 1);
                ans++;
            }
        }
        else if (c == 'E') {
            if (eia > 0) {
                eia--;
                ans++;
            }
        }
        else { 
            if (eia > 0) {
                eia--;
                ans++;
            }
            else if (empty > 0) {
                empty--;
                eia += (s - 1);
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}