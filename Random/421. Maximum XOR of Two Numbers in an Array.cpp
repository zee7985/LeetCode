421. Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 231 - 1

class trie{
    public:
    trie *nxt[2];
        
    trie()
        {
            nxt[0]=nxt[1]=NULL;
        }
};

   
    
class Solution {
public:
   
    trie* head=new trie();
     void insert(int val)
    {
        trie*curr=head;
        for(int i=31;i>=0;i--)
        {
            int bit=(val>>i)&1;
            if(curr->nxt[bit]==NULL)
            {
                curr->nxt[bit]=new trie();
                    
            }
            curr=curr->nxt[bit];
        }
    }

    
    int findMaximumXOR(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            insert(nums[i]);
        }
        
        int maxXor=0;
        
        
        long int maxans=INT_MIN;
    
        for(int i=0;i<nums.size();i++)
        {
            trie *curr=head;
            int val=nums[i];
            long int curXor=0;
            for(int j=31;j>=0;j--)
            {
                int bit=(val>>j)&1;
                if(bit==0)
                {
                    if(curr->nxt[1])
                    {
                        curXor+=pow(2,j);
                        curr=curr->nxt[1];
                    
                    }
                    else
                    {
                        curr=curr->nxt[0];
                    }
                }
                else
                {
                    if(curr->nxt[0])
                    {
                        curXor+=pow(2,j);
                        curr=curr->nxt[0];
                    
                    }
                    else
                    {
                        curr=curr->nxt[1];
                    }
                }
                
                maxans=max(maxans,curXor);
            }
        }
    return maxans;
    }
};
