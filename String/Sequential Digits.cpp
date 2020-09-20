Sequential Digits

Solution
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9

Hint:Generate all numbers with sequential digits and check if they are in the given range.
Fix the starting digit then do a recursion that tries to append all valid digits.

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
    
        vector<int> v;
    
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                string sub=s.substr(i,j-i+1);
                //cout<<sub<<"\n";
            
                int ans=stoi(sub);
            
                if(ans>=low and ans<=high)
                {
                    v.push_back(ans);
                }
            }
        }
    
        sort(v.begin(),v.end());
    
        return v;
    }
        
};
