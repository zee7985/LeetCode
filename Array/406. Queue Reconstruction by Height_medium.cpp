406. Queue Reconstruction by Height
Medium

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


// Hint:here The queue is a line or sequence of people  and not the queue used in computer
// GIven [h,k] -k represent how many people( whose height is greater thancurr person) are in front of him.
// We insert people one by one into an empty array. The number k is the position we need to insert. For everyone, we should first insert the higher h person. For the person who has same h we should first insert the person has small k value. For each inserted person, it takes O(n) time to move the person behind him back one position, so it will take the O(n^2) time for all people.
// E.g.
// input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// sort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
// step1: [[7,0]]
// step2: [[7,0], [7,1]]
// step3: [[7,0], [6,1], [7,1]]
// step4: [[5,0], [7,0], [6,1], [7,1]]
// step5: [[5,0], [7,0], [5,2], [6,1], [7,1]]
// step6: [[5,0], [7,0], [5,2],  [6,1],[4,4], [7,1]]


class Solution {
public:
    static bool myCmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        } 
        else return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), myCmp);
        vector<vector<int>> ans;
        
        for(int i = 0; i < people.size(); i++){
            ans.insert(ans.begin()+people[i][1], people[i]);
        }
        return ans;
    }
    

};