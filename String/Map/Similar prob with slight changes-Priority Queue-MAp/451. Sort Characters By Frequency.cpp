// Sort Characters By Frequency

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"


class Solution {
public:
    string frequencySort(string s) {
        
        //Count the frequency of char  -(char,int)pair
        map<char ,int > mp;
        for(int i=0;i<s.length();i++){
            {
                mp[s[i]]++;
            }
        }
        
        //put the elements of map into priority queue- (int,char)pair
        priority_queue<pair<int,char> ,vector<pair<int,char>> > pq;   // By default gives decreasing order
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        
        // Make resultant string        
        string ans="";
        while(!pq.empty()){
            pair<int,char> temp=pq.top();
            pq.pop();
            ans+=string(temp.first,temp.second); // string(n,c)-character c will be added n times to string
            
        }
        return ans;
    }
};