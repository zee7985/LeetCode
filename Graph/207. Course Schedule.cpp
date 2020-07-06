207. Course Schedule
Medium


There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.




Hint : //Cycle detection in directed graph

class Solution {
public:
    
    
        vector<vector<int>> graph;
    
    bool topoHelper(int u, vector<bool> &visited,vector<bool> &recStack)
    {
        if(!visited[u]){
            visited[u] = true;
            recStack[u]=true;

            for (int e : graph[u])
            {
                if (!visited[e] && topoHelper(e, visited,recStack)){
                
                return true;
                }
                else if(recStack[e]){
                    return true;
                }
            }   
            
        }
        recStack[u]=false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         for(int i = 0;i<numCourses;i++) 
        {
            vector<int> v;
            graph.push_back(v);
        }
        
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
            
        vector<bool> visited(graph.size(), false);
        vector<bool> recStack(graph.size(), false);
        stack<int> s;
        for (int i = 0; i < graph.size(); i++)
        {
            if(topoHelper(i, visited,recStack)) return false;
                
        }

        
        return true;
    }
};



