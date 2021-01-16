126. Word Ladder II
Hard

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

class Solution {
public:
// The basic idea is:

// 1). Use BFS to find the shortest distance between start and end, tracing the distance of crossing nodes from start node to end node, and store node's next level neighbors to HashMap;
    //Here We need to make little bit different graph than usual we need to push only forward neighbour into curr and also if if the distance of  the next level node equals the distance of the current node + 1.

// 2). Use DFS to output paths 
    vector<vector<string>> ans;
    void dfs(string beginWord, string endWord, vector<string> path,map<string,set<string>> &graph) 
    {
        path.push_back(beginWord);
        if(beginWord==endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        
        for(auto a: graph[beginWord])
        {
            dfs(a,endWord,path,graph);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>s;
        for(auto w :wordList )
        {
            s.insert(w);
        }
        
        if(s.find(endWord)==s.end())    //EndWOrd not in WordList ,return 0;
        {
            return {};
        }
        
        
        //vector<vector<string>> graph;
       map<string,set<string>> graph;
       map<string,int> visited;
        
        
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=0;
        // int level=0;
        
        while(!q.empty())
        {
            // level++;
            int size=q.size();
            while(size--)
            {
                string curr=q.front(); q.pop();
            
                for(int i=0;i<curr.length();i++)// Replace one by one each char of curr word and check if it is set and push in te queue.
                {
                    string temp=curr;
                    for(char j='a';j<='z';j++)
                    {
                        temp[i]=j;
                        if(temp==curr)                     // If both word same (like hit and hit) after repalcing ,do nothing 
                        {
                            continue;
                        }
        
                        if(s.find(temp)!=s.end())
                        {
                            // q.push(temp);
                            // s.erase(temp);
                             if(visited.find(temp)==visited.end())   // If temp not visited
                            {
                                q.push(temp);
                                visited[temp]=visited[curr]+1;
                                graph[curr].insert(temp);
                            }
                            else if(visited[temp]==visited[curr]+1)
                            {
                                 graph[curr].insert(temp);
                            }
                        }
                    }
                }
            }
        }
        vector<string> path;
        dfs(beginWord,endWord,path,graph);
        return ans;
    }
  
   vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        set<string>s;
        for(auto w :wordList )
        {
            s.insert(w);
        }
        
        if(s.find(endWord)==s.end())
        {
            return {};
        }
        
        vector<vector<string>>ans;
        queue<vector<string>> q;
        q.push({beginWord});
        bool flag=false;
        
        while(!q.empty())
        {
            int size=q.size();
            unordered_set<string> visited;
            while(size--)
            {
                vector<string> currVec=q.front(); q.pop();
                
                string curr=currVec.back();

            
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;
                    
                    for(char j='a';j<='z';j++)
                    {
                        temp[i]=j;
                        if(temp==curr)
                        {
                            continue;
                        }
                        
                        if(temp==endWord)
                        {
                            currVec.push_back(temp);
                            flag=true;
                            ans.push_back(currVec);
                        }
                        
                        if(s.find(temp)!=s.end())
                        {
                            currVec.push_back(temp);
                            q.push(currVec);
                            currVec.pop_back();
                            visited.insert(temp);
                        }
                    }
                 }
            }
            if(flag==true) break;
             for(auto a: visited)   //red ted tad ,red ted tex , red rex tex  //Erased here because tex will be deleted and can't be used in rex
            {
                s.erase(a);
            }
        }
        return ans;
    }
    
};
