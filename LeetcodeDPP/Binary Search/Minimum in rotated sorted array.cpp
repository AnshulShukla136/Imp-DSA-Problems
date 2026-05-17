class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int l = 0;
        int r = n-1;
        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(mid-1 >= 0 && nums[mid] < nums[mid-1] && mid+1 < n && nums[mid] < nums[mid+1] || mid-1 < 0 && nums[mid] < nums[mid+1] || mid+1 >= n && nums[mid] < nums[mid-1]){
                ans = nums[mid];
                return nums[mid];
            }

            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            if(nums[mid] < nums[r]){
                r = mid;
            }
        }
        return ans;
    }
};