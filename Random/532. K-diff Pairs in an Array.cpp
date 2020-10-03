532. K-diff Pairs in an Array
Medium
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
a <= b
b - a == k
 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Example 4:

Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2
Example 5:

Input: nums = [-1,-2,-3], k = 1
Output: 2
 

Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107

//1 o(n) with o(2n) space
// Just iterate over the array and check for the element (num[i]+k) and (num[i]-k) in the hash. If they are present, add it in the answer set.
// The size of the set would be the answer. Those are the unique number of pairs with 'k' difference.
// We need not sort the vector, and it happens in just one pass, so O(n) solution :)
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    set<pair<int, int>> s; 
    unordered_map <int, bool> m;
    int n = nums.size();
    
    for(int i=0;i<n;++i){
      if (m.find(nums[i]+k)!=m.end()){
        s.insert(make_pair(nums[i], nums[i]+k));
      }
      if (m.find(nums[i]-k)!=m.end()){
        s.insert(make_pair(nums[i]-k, nums[i]));
      }
      m[nums[i]] = true;
    }
    
    return s.size();
  }
    
    //2.o(nlogn)

//   int findPairs(vector<int>& nums, int k) {
   
//     sort(nums.begin(),nums.end());
    
//      int i = 0, j = 1, ans = 0;
//     while (i < nums.size() && j < nums.size()) {
//             while (i - 1 >= 0 && nums[i] == nums[i - 1] && i < j - 1) { //[1,1,3,4,5]
//                 i++;
//             }
//             while (j + 1 <nums.size() && nums[j] == nums[j + 1]) {
//                 j++;
//             }
//             if (nums[j] - nums[i] == k) {
//                 ans++;
//                 i++;
//                 j++;
//             } else if (nums[j] - nums[i] < k) {
//                 j++;
//             } else {
//                 i++;
//             }
//             if (i == j) {
//                 j++;
//             }
//         }
//         return ans;
//     }
 
};

