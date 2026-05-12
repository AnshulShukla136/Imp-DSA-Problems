class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            vector<int>temp;
            while(n > 0){
                int rem = n % 10;
                temp.push_back(rem);

                n = n / 10;
            }
            int len = temp.size();
            for(int j = len-1; j >= 0; j--){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};