973. K Closest Points to Origin

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


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


