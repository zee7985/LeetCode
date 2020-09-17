1041. Robot Bounded In Circle
Medium
\
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir[2]={0,1}; //facing north
        int x=0,y=0;      //starting pt;
        
        
        for(auto s:instructions)
        {
            int a=dir[0];
            int b=dir[1];
            if(s=='G')
            {
                x+=dir[0];
                y+=dir[1];
            }
            else if(s=='L')
            {
                dir[0]=-b;
                dir[1]=a;
            }
            else
            {
                dir[0]=b;
                dir[1]=-a;
            }
        }
        
        if((x==0 && y==0)|| !(dir[0]==0 && dir[1]==1))
        {
            return true;
        }
        return false;
    }
};
