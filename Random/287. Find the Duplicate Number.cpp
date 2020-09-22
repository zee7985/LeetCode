287. Find the Duplicate Number
Medium

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

class Solution {
public:
    
    //1.bRUTE fORCE the array -O(nlogn)
    
    //2.Hashmap  o(n) with o(n) space
//     int findDuplicate(vector<int>& nums) {
//         map<int,int> mp;
//         int ans=-1;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(mp.find(nums[i])!=mp.end())
//             {
//                 ans= nums[i];
//             }
//             mp[nums[i]]++;
//         }
//         return ans;
//     }
    
    //===================================================
    
    //3. O(n) with O(1) space
//      Use two pointers the fast and the slow. The fast one goes forward two steps each time, while the slow one goes only step each time. They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must be the entry point of the circle when visiting the array from nums[0]. Next we just need to find the entry point. We use a point(we can use the fast one before) to visit form begining with one step each time, do the same job to slow. When fast==slow, they meet at the entry point of the circle.
         
// *Second step, take tortoise or hare to the start point of the list (i.e. let one of the animal be 0) and keep the other one staying at the meeting point. Now, advance both of the animals one node each unit of time, the meeting point is the starting point of the cycle. This is what the second while loop does. The second while loop finds their meeting point.

// *Proof of second step:

// Distance traveled by tortoise while meeting = x + y

// Distance traveled by hare while meeting = (x + y + z) + y = x + 2y + z

// Since hare travels with double the speed of tortoise,

// so 2(x+y)= x+2y+z => x+2y+z = 2x+2y => x=z

// Hence by moving tortoise to start of linked list, and making both animals to move one node at a time, they both have same distance to cover .
    
    int findDuplicate(vector<int>&nums)
    {
        int fast=nums[0];
        int slow=nums[0];
        
        do
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
        }while(fast!=slow);
        
        fast=nums[0];
        while(fast!=slow)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
    
};
