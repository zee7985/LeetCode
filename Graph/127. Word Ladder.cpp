127. Word Ladder

Solution
Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.


//DFS can't be used for this problem because that can have exponential number unique paths in a graph.
//We can use either DFS or BFS to find shortest path in Tree but we need to use BFS for finding shortest 
//path in graph due to polynomial time of BFS.
//Since only one letter can be changed at a time, if we start from "hit", we can only change to those words
//which have exactly one letter different from it (in this case, "hot"). Putting in graph-theoretic terms,
//"hot" is a neighbor of "hit". The idea is simpy to start from the beginWord, then visit its neighbors,
//then the non-visited neighbors of its neighbors until we arrive at the endWord. 




//Time Complexity :O(26*N*N*W)
//where one N is for endWord Length
//Another N for string comparison 
//And W -For no of words

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(auto w :wordList )
        {
            s.insert(w);
        }
        
        if(s.find(endWord)==s.end())    //EndWOrd not in WordList ,return 0;
        {
            return 0;
        }
        
        
        queue<string> q;
        q.push(beginWord);
        int level=0;
        
        while(!q.empty())
        {
            level++;
            int size=q.size();
            while(size--)
            {
                string curr=q.front(); q.pop();
            
                for(int i=0;i<curr.length();i++)            // Replace one by one each character of the current word and check if it is set and push in te queue.
                {
                    string temp=curr;
                    for(char j='a';j<='z';j++)
                    {
                        temp[i]=j;
                        if(temp==curr)                     // If both word same (like hit and hit) after repalcing ,do nothing 
                        {
                            continue;
                        }
                        
                        if(temp==endWord)               // If the word fromed by replacing character is equal to endWord,this is our ans
                        {
                            return level+1;
                        }
                        
                        if(s.find(temp)!=s.end())      // Else If the word formed is present in the set ,push it in the que and erase from set
                        {                              // As each word can be used only once
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
