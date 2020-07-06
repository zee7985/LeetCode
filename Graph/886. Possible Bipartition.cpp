886. Possible Bipartition
Medium


Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false


class Solution {
public:
    class partite_pair
    {
    public:
        int vtx = -1;
        int colour = -1;

        partite_pair(int vtx, int colour)
        {
            this->vtx = vtx;
            this->colour = colour;
        }

        partite_pair()
        {
        }
        };
    
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> vis(N,-1);
	    vector<vector<int>> graph(N,vector<int>());
	    
	    for(auto v:dislikes)
	    {
		    graph[v[0]-1].push_back(v[1]-1);   
		    graph[v[1]-1].push_back(v[0]-1); 
	    }
        
        //Simple check if the graph is bipartite or not 
        for(int i=0;i<N;i++){     //This is to check that every vertex is covered-For disjoint graph
            if(vis[i]!=-1){
                continue;
            }
	
           //Rest same
            list<partite_pair> que;
            partite_pair root(i, 0);
            que.push_back(root);


            while (que.size() > 0)
            {
            //remove vertex
                partite_pair rpair = que.front();
                que.pop_front();

                if (vis[rpair.vtx] != -1)
                {
                    if (vis[rpair.vtx] != rpair.colour)
                    {
                        return false;
                    }
                }

                vis[rpair.vtx] = rpair.colour;

                for (int e : graph[rpair.vtx])
                {

                    if (vis[e] == -1)
                    {
                        int new_colour = (rpair.colour + 1) % 2;
                        partite_pair npair(e, new_colour);
                        que.push_back(npair);
                    }
                }
            }
        }
        return true;
    }
};
