42. Trapping Rain Water
Hard


Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

class Solution {
public:
    
    //1.Brute Force-O(n^2)
    //Find maximum left bar and max right bar so current bar and ans+=(take min of both by subtracting current height)
//     int trap(vector<int>& height) {
//         int sum=0;
//         int n=height.size();
//         for(int i=0;i<n;i++)
//         {
//             int left=0,right=0;
//             for(int j=i;j>=0;j--)
//             {
//                 left=max(left,height[j]);
//             }
            
//             for(int j=i;j<n;j++)
//             {
//                 right=max(right,height[j]);
//             }
//             sum+=min(right,left)-height[i];
//         }
//         return sum;
//     }
    
    
    //2.o(n) with o(n) space Dp store max of left and right in an array
//     int trap(vector<int>& height) 
//     {
     
//         int n = height.size();
        
//         vector<int>mh1(n,0);
//         vector<int>mh2(n,0);
        
//         int maxx1 = 0;
//         int maxx2 = 0;
        
//         for(int i = 0 ; i < n ; i++)
//         {
//             mh1[i] = maxx1;
//             maxx1 = maxx1 < height[i] ? height[i] : maxx1;
//         }
//         for(int i = n-1 ; i >= 0 ; i--)
//         {
//             mh2[i] = maxx2;
//             maxx2 = maxx2 < height[i] ? height[i] : maxx2;
//         }
        
//         int sum = 0;
        
//         for(int i = 0 ; i < n ; i++)
//         {
//             int minn = min( mh1[i], mh2[i] );
//             minn -= height[i];
//             if( minn > 0) sum += minn;
//         }
//         return sum;
//     }
    
    //3.2 pointer o(n) with o(1)we're comparing leftMax and rightMax to decide which pointer to move
    
    int trap(vector<int>& height)
    {
        int l=0;
        int r=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int ans=0;
        
        while(l<r)
        {
            if(height[l]<height[r])     //here r will be fixed and l will be incrementd and computed till h[l] become greater than h[r]
            {
                if(height[l]>=leftmax)
                {
                    leftmax=height[l]; //update
                }
                else
                {
                    ans+=(leftmax-height[l]);  //else compute ans
                
                }
                l++;
            }
            else                    //here l will be fixed and r will be decremented 
            {
                if(height[r]>=rightmax)
                {
                    rightmax=height[r];
                }
                else
                {
                    ans+=(rightmax-height[r]);
                
                }
                r--;
            }
        }
        return ans;
    }
};
