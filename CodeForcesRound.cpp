// codeforces Round 1096
// A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int x, y;
    cin >> x >> y;

    if (x % 2 != 0 && y % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        return;
    }
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
// B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int leftB =0 , rightB = 0;
    for(int i = 0;i <n; i++){
        if(s[i] == '('){
            leftB++;
        }
        if(s[i] == ')'){
            rightB++;
        }
    }
    if(leftB != rightB){
        cout<<"NO"<<endl;
        return ;
    }
    else{
        cout<<"YES"<<endl;
        return;
    }
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

// C
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

// codeforces Practice
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    vector<int> a = m;
    sort(m.begin(), m.end());
    if (m == a)
    {
        cout << 0 << endl;
        return;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = i;
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (abs(i - mp[]))
    }
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

#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
void sieve(int limit)
{
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(200000);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << primes[i] * primes[i + 1] << " ";
        }
        cout << "\n";
    }
}
// int count=1;
//     if(n==1){
//         cout<<1;
//         return ;
//     }
//     if(s[0]==s[n-1]){
//         int i=0;
//         while(i<n-1){
//            if(s[i]!=s[i+1]){
//             count++;
//            }
//            i++;
//         }
//     }
//     else{
//         int maxi=1;
//         int i=0;
//         while(i<n-1){
//             if(s[i]==s[i+1]){
//                 maxi=2;
//             }
//            if(s[i]!=s[i+1]){
//             count++;
//            }
//            i++;
//         }
//         if(maxi==2){
//             count++;
//         }
//     }

// #include <bits/stdc++.h>
// using namespace std;

// string solve(vector<long long>& nums) {
//     int n=nums.size();
//     vector<long long>temp=nums;
//     unordered_map<int,int>mp;
//     for(int i=0;i<n;i++){
//         if(i%2==0){
//             mp[temp[i]]=0;
//         }
//         else{
//             mp[temp[i]]=1;
//         }
//     }
//     bool ans=true;
//     sort(temp.begin(),temp.end());
//     for(int i=0;i<n-1;i++){
//         if(mp[temp[i]]==mp[temp[i+1]]){
//             ans=false;
//             break;
//         }
//     }
//     if(ans)return "YES";
//     bool ans2=true;
//     unordered_map<int,int>mp1;
//     for(int i=0;i<n;i++){
//         if(i%2==0){
//             mp1[nums[i]]=1;
//         }
//         else{
//             mp1[nums[i]]=0;
//         }
//     }
//     sort(nums.begin(),nums.end());
//     for(int i=0;i<n-1;i++){
//         if(mp1[nums[i]]==mp1[nums[i]]){
//             ans2=false;
//             break;
//         }
//     }
//     if(ans2)return "YES";
//     else{
//         return "NO";
//     }

// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<long long> arr(n);
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//        cout<<solve(arr)<<endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int T;
//     cin >> T;

//     while(T--){
//         int n;
//         cin >> n;

//         vector<long long> A(n), ans(n);

//         for(int i=0;i<n;i++) cin >> A[i];

//         long long turns = 0;

//         for(int i=0;i<n;i++){

//             ans[i] = min(turns, A[i]);

//             if(turns < A[i]){
//                 // friend gets a turn
//                 turns++;
//             }
//         }

//         for(long long x : ans) cout << x << " ";
//         cout << "\n";
//     }
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long a, b, c;
//         cin >> a >> b >> c;

//         if (c % 2 == 1)
//         {

//             if (b > a)
//                 cout << "Second" << endl;
//             else
//                 cout << "First" << endl;
//         }
//         else
//         {

//             if (a > b)
//                 cout << "First" << endl;
//             else
//                 cout << "Second" << endl;
//         }
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void merge(int arr[], int left, int mid, int right) {
//     int i = left;
//     int j = mid + 1;
//     int k = 0;
//     int temp[right - left + 1];

//     while (i <= mid && j <= right) {
//         if (arr[i] < arr[j]) {
//             temp[k++] = arr[i++];
//         } else {
//             temp[k++] = arr[j++];
//         }
//     }

//     while (i <= mid) {
//         temp[k++] = arr[i++];
//     }

//     while (j <= right) {
//         temp[k++] = arr[j++];
//     }

//     for (int p = 0; p < k; p++) {
//         arr[left + p] = temp[p];
//     }
// }

// void mergeSort(int arr[], int left, int right) {
//     if (left < right) {
//         int mid = (left + right) / 2;

//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     int arr[] = {38, 27, 43, 3, 9, 82, 10};
//     int n = 7;

//     mergeSort(arr, 0, n - 1);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin >> n;

//     vector<pair<long long,int>> a(n);
//     for(int i=0;i<n;i++){
//         cin >> a[i].first;
//         a[i].second = i+1;
//     }

//     if(n < 3){
//         cout << -1 << "\n";
//         return;
//     }

//     sort(a.begin(), a.end());

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(a[i].first + a[j].first != a[n-1].first){
//                 cout << a[i].second << " "
//                      << a[j].second << " "
//                      << a[n-1].second << "\n";
//                 return;
//             }
//         }
//     }

//     cout << -1 << "\n";
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while(t--) solve();
// }

// sort(nums1.begin(), nums1.end());

//     int target = nums1[0] % 2;

//     for (int i = 0; i < nums1.size(); i++) {
//         if (nums1[i] % 2 != target) {
//             bool canFix = false;

//             // try all smaller elements
//             for (int j = 0; j < i; j++) {
//                 if (nums1[j] < nums1[i]) {
//                     int diff = nums1[i] - nums1[j];
//                     if (diff >= 1 && diff % 2 == target) {
//                         canFix = true;
//                         break;
//                     }
//                 }
//             }

//             if (!canFix) return false;
//         }
//     }

//     return true;