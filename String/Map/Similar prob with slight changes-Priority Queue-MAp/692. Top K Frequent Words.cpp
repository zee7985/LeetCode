692. Top K Frequent Words

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.



class Solution {
public:
    struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const { //comparator to sort string alphabetically if count same
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;        
            return lhs.second > rhs.second;   // count same then sort alphabetically
        }
    };

 
    vector<string> topKFrequent(vector<string>& words, int k) {
        
         //Count the frequency of string  -(string,int)pair
        unordered_map<string ,int > mp;
        for(int i=0;i<words.size();i++){
            {
                mp[words[i]]++;
            }
        }
        
        //put the elements of map into priority queue- (int,string)pair
        priority_queue<pair<int,string> ,vector<pair<int,string>> ,Comp> pq;   // By default gives decreasing order
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        
        // Make resultant string vector
        vector<string> ans;
        
        while(!pq.empty() && k--){
            pair<int,string> temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
            
        }
        return ans;
    }
    
};