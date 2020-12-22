//1. DP (use full target)
Input:
9
4 3 2 5 6 7 2 5 5

Output: "7772"

1449. Form Largest Integer With Digits That Add up to Target
Hard

Given an array of integers cost and an integer target. Return the maximum integer you can paint under the following rules:

The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
The total cost used must be equal to target.
Integer does not have digits 0.
Since the answer may be too large, return it as string.

If there is no way to paint any integer given the condition, return "0".

 

Example 1:

Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
Output: "7772"
Explanation:  The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "977", but "7772" is the largest number.
Digit    cost
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
Example 2:

Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
Output: "85"
Explanation: The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.
Example 3:

Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
Output: "0"
Explanation: It's not possible to paint any integer with total cost equal to target.
Example 4:

Input: cost = [6,10,15,40,40,40,40,40,40], target = 47
Output: "32211"
 

Constraints:

cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000

class Solution {
public:
    string maxStr(string a,string b)
    {
        if(a.length()>b.length())
        {
            return a;
        }
        else if(a.length()<b.length())
        {
            return b;
        }
         else{
            if(a>b)
                return a;
            else
                return b;
        }
        return "";
    }
  
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>> dp(10,vector<string>(target+1,"0"));  //0 means no path possible
        
        for(int i=0; i<10; i++)   //"" means path possible with 0 target
            dp[i][0]="";
        
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=target;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(cost[i-1]<=j && dp[i][j-cost[i-1]]!="0")
                {
                    string str=to_string(i)+ dp[i][j-cost[i-1]];
                    dp[i][j]=maxStr(dp[i][j],str);
                }
            }
                                        
                                                  
        }
        return dp[9][target];
    }
};


//Greedy (use upto target)
Input:
9
4 3 2 5 6 7 2 5 5

Output: "7777"

B. Color the Fence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Igor has fallen in love with Tanya. Now Igor wants to show his feelings and write a number on the fence opposite to Tanya's house.
Igor thinks that the larger the number is, the more chance to win Tanya's heart he has.

Unfortunately, Igor could only get v liters of paint. He did the math and concluded that digit d requires ad liters of paint. 
Besides, Igor heard that Tanya doesn't like zeroes. That's why Igor won't use them in his number.

Help Igor find the maximum number he can write on the fence.

Input
The first line contains a positive integer v (0 ≤ v ≤ 106). The second line contains nine positive integers a1, a2, ..., a9 (1 ≤ ai ≤ 105).

Output
Print the maximum number Igor can write on the fence. If he has too little paint for any digit (so, he cannot write anything), print -1.

Examples
inputCopy
5
5 4 3 2 1 2 3 4 5
output
55555
input
2
9 11 1 12 5 8 9 10 6
outputCopy
33
inputCopy
0
1 1 1 1 1 1 1 1 1
outputCopy
-1

#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int paint;
    cin>>paint;
    vector<int> arr(9);
    int digit=0,minValue=INT_MAX;
    for(int i=0;i<9;i++)
    {
        cin>>arr[i];
        if(minValue>=arr[i])
        {
            minValue=arr[i];
            digit=i+1;
        }
        
    }

    if(minValue>paint)
    {
        cout<<"-1\n";
    }
    else
    {
        int noOfDigit=paint/minValue;
        string ans;
        for(int i=0;i<noOfDigit;i++)
        {
            ans+=to_string(digit);
        }
        int left=paint - minValue*noOfDigit;

        for(int i=0;i<ans.length();i++)
        {
            for(int j=8;j>=0;j--)
            {
                if(arr[j]<=left + minValue)
                {
                    char newDigit=char((j+1)+'0');
                    ans[i]=newDigit;
                    left=left+ minValue -arr[j];
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
}


                                                   

