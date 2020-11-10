787. Cheapest Flights Within K Stops
Medium

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.


// We set ans = INT_MAX;
// We push in all the nodes connected to 0, i.e. 2 and 1.
// We visit 2 and update our answer, ans = min(ans, node.second), our answer is now equal to 500 and pop out 2.
// We visit 1. Now 2 is a child of 1, things are different from rest of the BFS here, just because we have visited 2 once does not mean we will ignore it like we use to do in standard BFS call. Instead, we'll prune using the condition if(child.second + node.second > ans) continue;. The following calculation happens:
// a. Child = 2, Node = 1
// b. Child.second = 100 (cost of 1 to 2)
// c. Node.second = 100 (total cost from start i.e. 0 to 1)
// d. 100 + 100 = 200 < ans(=500), hence we update the value of the child node 2 and push it again into the queue.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
          unordered_map<int, vector<pair<int, int>>> graph;
        for(auto e: flights) graph[e[0]].push_back({e[1], e[2]});
        vector<int> prices(n, -1);
        queue<pair<int, int>> q; q.push({src, 0});
        ++K;
        while(!q.empty() && K-->0) {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto cur = q.front(); q.pop();
                for(auto e: graph[cur.first]) {
                    int price = cur.second + e.second; 
                    if(prices[e.first] == -1 || price < prices[e.first]) {
                        prices[e.first] = price;
                        q.push({e.first, price});
                    }
                }
            }
        }
        return prices[dst];
    }
        
};
// class Node{
//  public:
    
//     int nodesIntBtw;
//     int dist;
//     int node;

//     Node(int a,int b,int c)
//     {
//         nodesIntBtw = a;
//         dist = b;
//         node = c;
//     }
    
// };

// struct compare{
//     bool operator()(const Node &a,const Node &b)
//     {
//         return a.dist >= b.dist;
//     }
// };

// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
//         vector<list<pair<int,int>>> graph(n);
//         for(auto vec : flights)
//         {
//             graph[vec[0]].push_back({vec[1],vec[2]});
            
//         }
    
//         priority_queue<Node,vector<Node>,compare> pq;
//         pq.push(Node(0,0,src));
        
//         while(!pq.empty())
//         {
//             auto cur = pq.top();
//             pq.pop();
//             int cur_node = cur.node;

//             if(cur_node == dst) return cur.dist;

//             for(auto ch : graph[cur_node])
//             {
//                 int child_node = ch.first;
//                 int wt = ch.second;

//                 if(cur.nodesIntBtw <= K)
//                 {
//                     pq.push(Node(cur.nodesIntBtw + 1,cur.dist + wt,child_node));
//                 }
//             }
//         }
        
//         return -1;
//     }
// };
