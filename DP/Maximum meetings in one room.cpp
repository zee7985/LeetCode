There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples:

Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9}
Output : 1 2 4 5
First meeting [1, 2]
Second meeting [3, 4]
Fourth meeting [5, 7]
Fivth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924},
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 }
Output : 6 7 1

#include <bits/stdc++.h> 
using namespace std; 


class meeting { 
	int start; 
	int end; 
	int pos; 
}; 

 
bool comparator(struct meeting m1, meeting m2) 
{ 
	return (m1.end < m2.end); 
} 


void maxMeeting(int s[], int f[], int n) 
{ 
	struct meeting meet[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		// Starting time of meeting i. 
		meet[i].start = s[i]; 
		
		// Finishing time of meeting i 
		meet[i].end = f[i]; 
		
		// Original position/index of meeting 
		meet[i].pos = i + 1; 
	} 

	// Sorting of meeting according to their finish time. 
	sort(meet, meet + n, comparator); 

	// Vector for storing selected meeting. 
	vector<int> m; 

	// Initially select first meeting. 
	m.push_back(meet[0].pos); 

	int time_limit = meet[0].end; 
  
	for (int i = 1; i < n; i++) { 
		if (meet[i].start >= time_limit) 
		{ 
			m.push_back(meet[i].pos);  
			time_limit = meet[i].end; 
		} 
	} 

	// Print final selected meetings. 
	for (int i = 0; i < m.size(); i++) { 
		cout << m[i] << " "; 
	} 
} 

 
int main() 
{ 
	int s[] = { 1, 3, 0, 5, 8, 5 }; 
	int f[] = { 2, 4, 6, 7, 9, 9 }; 
	int n = sizeof(s) / sizeof(s[0]);
	maxMeeting(s, f, n); 

	return 0; 
} 
