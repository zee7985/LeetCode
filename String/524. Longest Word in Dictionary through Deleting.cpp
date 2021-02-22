524. Longest Word in Dictionary through Deleting
Medium

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.

class Solution {
public:
    //O(mn)
    //Iterate all the word in dictionary and find whether that word can be formed from string s and update resStr
    string findLongestWord(string s, vector<string>& d) {
        int max_=INT_MIN;
        string res="";
        for(string t : d)
        {
            int i=0,j=0;
            while(i<t.length() && j<s.length())
            {
                //cout<<t[i]<<" "<<s[j]<<"\n";
                if(t[i]==s[j])
                {
                    i++;
                }
                
                j++;
            }
            // cout<<i<<" "<<t.length()<<"\n";
            if(i==t.length())
            {
                if (t.length() > res.length()  || (res.length() == t.length() && t < res))
                {
                    res = t;
                }
                    
            }
        }
        return res;
    }
};
