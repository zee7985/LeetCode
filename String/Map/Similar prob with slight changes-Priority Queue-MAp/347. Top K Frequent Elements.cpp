Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Count the frequency of each number  
        map<int ,int > mp;
        for(int i=0;i<nums.size();i++){
            {
                mp[nums[i]]++;
            }
        }
        
        //put the elements of map into priority queue-so as to sort interms of count by putting second of map(count) as first of pq
        priority_queue<pair<int,int> ,vector<pair<int,int>> > pq;   // By default gives decreasing order
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        
               
        vector<int> ans;
        while(!pq.empty()  && k-->0){
            pair<int,int> temp=pq.top();
            pq.pop();
            ans.push_back(temp.second); 
            
        }
        return ans;
    }
        
};