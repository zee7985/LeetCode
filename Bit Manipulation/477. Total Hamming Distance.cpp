477. Total Hamming Distance
Medium

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.



class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        //TLE 
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 int res=nums[i]^nums[j];
                
//                 while(res>0){
//                     count++;
//                     res=res&(res-1);
//                 }
//             }
//         }
//         return count;
    //}
    
    
// The idea behind this algorithm is that instead of comparing eah pair of numbers, we calculate the total hamming distance one bit at a time. The hamming distance is 1 only if the bits are different. Thus, we can calculate the total hamming distance by finding out the number of 1s and 0s in that bit position, and multiply them together. The intuition is that say if there are 4 numbers, and for a specific bit there are 3 zeros and 1 one, then the hamming distance includes first zero + one, second zero + one, thid zero + one. So the total hamming distance from that bit is 3 * 1 = 3.

// Thus, we can iterate through all the bits, and then calculate the number of zeros and ones in the bit, and multiply them together to get the total hamming distance for all bits.

// The run-time is O(32n) = O(n), and the space complexity is O(1).

        int dist = 0, size = nums.size();
        for(int i = 0; i < 32; ++i) {
            int count = 0, mask = 1 << i;
            for(int n: nums)  
                if(n & mask){     // If mask not zero, we have a 1 bit
                    ++count;
                }                
            dist += count * (size-count); // All other bits are zero, so size-count = 0 bits
        }
        return dist;
    }

};