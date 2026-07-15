class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int>prevSmall(n);
        vector<int>nextSmall(n);
        stack<int>st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && height[i] <= height[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nextSmall[i] = n; 
            }
            else{
                nextSmall[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[i] <= height[st.top()]){
                st.pop();
            }
            if(st.empty()){
                prevSmall[i] = -1;
            }
            else{
                prevSmall[i] = st.top();
            }
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int hei = height[i];

            int width = nextSmall[i] - prevSmall[i] - 1;
            maxArea = max(maxArea, hei * width);
        }
        return maxArea ;
    }
};