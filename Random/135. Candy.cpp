135. Candy
Hard


There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
1 <= ratings[i] <= 2 * 104
  
 //so we assummed that , we are startng assign a candy to children with left dependecies.. i.e.
// if any i-th child's rank greater than their i-1 child's rank assigne candy for i with 1+candy which have i-1 child..
// So for any child i [1,n) it's true that if i-th child's rank greater then he has greater candies than i-1child...
// So same idea apply for right dependecies...
// And ans will max of left and right dependencies

// eg-               2 12 6 7 7 8 1
// Left              1 2  1 2 1 2 1
// Right             1 2  1 1 1 2 1
// Max(left,right)   1 2  1 2 1 2 1  =10

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>ans(ratings.size(),1);
        
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                ans[i]=ans[i-1]+1;
            }
        }
        
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        
        int sum=0;
        for(int s:ans)
            sum+=s;
        
        return sum;
    }
};
