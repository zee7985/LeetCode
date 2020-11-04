310. Minimum Height Trees
Medium


A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
Example 3:

Input: n = 1, edges = []
Output: [0]
Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.


class Solution {
public:
    //The basic idea is "keep deleting leaves layer-by-layer, until reach the root."

    // Specifically, first find all the leaves, then remove them. After removing, some nodes will become new leaves.
    // So we can continue remove them. Eventually, there is only 1 or 2 nodes left. If there is only one node left, 
    //it is the root. If there are 2 nodes, either of them   could be a possible root.
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            return {0};
        }
        
        vector<int> leaves;           //to store all the leaf node 
        vector<int> degree(n,0);      // to check whether a node is leaf(degree==1) or not 
        
        
        map<int,set<int>> graph;
        
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
            
            degree[edges[i][0]]++;          
            degree[edges[i][1]]++;
            
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                leaves.push_back(i);
            }
        }
        
        
        while(n>2)       //Remove the leave nodes until 1/2 nodes(this will be the ans) is left -
        {
            vector<int> newLeaves;
            int siz=leaves.size();
            n-=siz; 
            
            for(int i=0;i<siz;i++)
            {
                int curr=leaves[i];
                for(int neigh:graph[curr])
                {
                    graph[neigh].erase(curr);
                    degree[neigh]--;
                    
                    if(degree[neigh]==1)
                    {
                        newLeaves.push_back(neigh);
                    }
                }
            }
            leaves=newLeaves;
        }
        
        return leaves;
    }
    
};

//, if the number of nodes is V, and the number of edges is E. The space complexity is O(V+2E),
for storing the whole tree. The time complexity is O(E), because we gradually remove all the neighboring information.
for a tree, if V=n, then E=n-1. Thus both time complexity and space complexity become O(n).
