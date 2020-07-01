338. Counting Bits
Medium


Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2  ( i.e for 0,1,2)
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>v;
        for(int i=0;i<=num;i++){
            int count=0;
            int temp=i;
            while(temp){
                count++;
                temp=(temp&(temp-1));
            }
            v.push_back(count);
        }
        return v;
    }
};