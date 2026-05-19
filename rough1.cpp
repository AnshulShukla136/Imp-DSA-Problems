//arr =[1,3,6,4,2,0]
//no duplicate values
//array size <= 1e5
// 0 <= arr[i] <= 1e5
//[1,2,3,4,6]
//[7,5,3,2,1]
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums){
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while(l <= r){
        int mid = l + (r - l)/2;

        if( mid + 1 < n && nums[mid] > nums[mid+1] && mid - 1 >= 0 && nums[mid] > nums[mid-1]){
            return nums[mid];
        }
        else if(mid + 1 == n && nums[mid] > nums[mid-1]){
            return nums[mid];
        }
        else if(mid - 1 < 0 && nums[mid] > nums[mid+1]){
            return nums[mid];
        }
        else if(mid + 1 < n && nums[mid] < nums[mid+1] && mid - 1 >= 0 && nums[mid] > nums[mid-1]){
            l = mid + 1;
        }
        else if(mid + 1 < n && nums[mid] > nums[mid+1] && mid - 1 >= 0 && nums[mid] < nums[mid-1]){
            r = mid - 1;
        }

    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int ans = solve(arr);
    cout << ans << endl;
}
