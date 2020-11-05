274. H-Index
Medium


Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.

class Solution {
public:
    //1.O(nlogn)
//     int hIndex(vector<int>& citations) {
//         sort(citations.begin(),citations.end());
        
//         int n=citations.size();
        
//         for(int i=0;i<n;i++)
//         {
//             if(citations[i]>=(n-i))
//             {
//                 return (n-i);
//             }
//         }
//         return 0;
//     }
    
    // From the definition of h-index, we could find that the max of h-index of a researcher is the amount of           papers the researcher published. Therefore we can define a bucket with the size of "amounr of paper + 1".         Then we traverse the citation array, if citation is larger than amount of paper, we throw this paper to           bucket[amout of paper], else, we throw it to the bucket[citation]. Finally, we count the number of papers         in each bucket from larger h-index to lower h-index.
    
    
    //Bucket sort -O(n)
    int hIndex(vector<int>& citations) {
        int l = citations.size();
        vector<int> bucket(l+1,0);     // because h-index cant be greater than the amountof papers
        for (int i : citations) {
            if (i > l) bucket[l]++;    // put all the paper greater than amount size in last index 
            else bucket[i]++;
        }
        int sum = 0;
        for (int i = l; i >= 0; i--) {
            sum += bucket[i];
            if (sum >= i) return i;
        }
        return 0;
    }
};
