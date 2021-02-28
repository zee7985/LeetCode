84. Largest Rectangle in Histogram
Hard


Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
 
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;

        st.push(-1);
        int i=0;
        int maxArea=0;
        
        while(i< height.size()){
            while(st.top()!=-1 && height[st.top()] >= height[i]){
                int j=st.top();
                st.pop();
                int ht=height[j];
                int area=ht*(i-st.top()-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
            i++;
        }
        while(st.top()!=-1){
            int j=st.top();
            st.pop();
            int ht=height[j];
            int area=ht*(i-st.top()-1);
            maxArea=max(maxArea,area);
        }

        return maxArea;
        
    }
};

