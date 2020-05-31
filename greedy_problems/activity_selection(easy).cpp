/*
    problem=activity_selection(easy).cpp

Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. First line is N number of activities then second line contains N numbers which are starting time of activies.Third line contains N finishing time of activities.

Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4

Explanation:
Test Case 1: The following activities can be performed (in the same order):
(1, 2)
(3, 4)
(5, 7)
(8, 9)

*/

// sort the activity according to the finish time and count only those activity which is non overlapping with previous one.

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool cmp(pair<lli,lli> p1,pair<lli,lli> p2)
{
    return (p1.second<p2.second);
}

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    lli start_time[n],finish_time[n];
	    for(lli i=0;i<n;i++)
	    cin>>start_time[i];

	    for(lli i=0;i<n;i++)
	    cin>>finish_time[i];

	    vector<pair<lli,lli> > v;
	    for(lli i=0;i<n;i++)
	    {
	        v.push_back({start_time[i],finish_time[i]});
	    }

	    sort(v.begin(),v.end(),cmp);
	    lli cnt=1,r=v[0].second;
	    for(lli i=1;i<n;i++)
	    {
	       if(v[i].first>=r)
	       {
	           cnt++;
	           r=v[i].second;
	       }
	    }

	    cout<<cnt<<"\n";


	}
	return 0;
}
