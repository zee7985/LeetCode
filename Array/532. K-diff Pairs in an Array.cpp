532. K-diff Pairs in an Array
Easy

619

1331

Add to List

Share
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).


class Solution {
public:
    int findPairs(vector<int>& nums, int k) { 
    //     if(k < 0) return 0;
    //     set< pair<int,int> > s;
    //     unordered_set<int> hash;
    //     for(int x: nums) {
    //         if(hash.find(x+k) != hash.end()) s.insert({x,x+k});
    //         if(hash.find(x-k) != hash.end()) s.insert({x-k, x});
    //         hash.insert(x);
    //     }
    //     return s.size();
    // }
    

    sort(nums.begin(),nums.end());
    
     int i = 0, j = 1, ans = 0;
    while (i < nums.size() && j < nums.size()) {
            while (i - 1 >= 0 && nums[i] == nums[i - 1] && i < j - 1) { //[1,1,3,4,5]
                i++;
            }
            while (j + 1 <nums.size() && nums[j] == nums[j + 1]) {
                j++;
            }
            if (nums[j] - nums[i] == k) {
                ans++;
                i++;
                j++;
            } else if (nums[j] - nums[i] < k) {
                j++;
            } else {
                i++;
            }
            if (i == j) {
                j++;
            }
        }
        return ans;
    }
 
};
