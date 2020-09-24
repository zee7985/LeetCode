134. Gas Station
Medium

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

class Solution {
public:
    
    //try all the possibility  O(n^2)
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int n=gas.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         int total=0;
    //         int j=i;
    //         int count=0;
    //         while(count<n)
    //         {
    //             total+=gas[j%n]-cost[j%n];
    //             if(total<0)
    //             {
    //                 break;
    //             }
    //             count++;
    //             j++;
    //         }
    //         if(count==n && total>=0)   // if we are able to cover all the stop and fuel +ve return i'th stop
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    
    
    //2.Greedy-o(n)
    //If you carefully observe at the end if we check total gas - cost is >= 0 which means we
    //have a solution and       as per problem note we must be have 1 solution.
    // Now the point how to find from which station we have to start?

    // If we Start from 0th stop and check fuel tank at every stop whenver it goes -ve which implies that we            can't start from all the previous station and including i`th station -> we will update our start station           from i + 1 and reset tank to 0.

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {   
        int total = 0, tank = 0, index = 0;
        for (int i = 0; i < cost.size(); i++) {
            int consume = gas[i] - cost[i];			
            tank += consume;
            if (tank < 0) {
                index = i + 1;
                tank = 0;
            }
            total += consume;			
        }		
        return total < 0 ? -1 : index; // check if total -ve which means we can't complete the trip.
    }    
    
};
