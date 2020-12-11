Add One To Number
Asked in:  
Google
Microsoft
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

vector<int> Solution::plusOne(vector<int> &A) {
    int idx=0;
    
    int carry=1;
    for(int i=A.size()-1;i>=0;i--)
    {
        int num=A[i]+ carry;
        A[i]=num%10;
        carry=num/10;
    }
    
    if(carry!=0)
    {
        A.insert(A.begin(), carry);
    }
    
    // Check trailing zeros in array
    for(idx=0;idx<A.size();idx++)
    {
        if(A[idx]!=0)
        {
            break;
        }
    }
    //Remove trailing zeros
    for(int i=0;i<idx;i++)
    {
        A.erase(A.begin());
    }
    return A;
}
