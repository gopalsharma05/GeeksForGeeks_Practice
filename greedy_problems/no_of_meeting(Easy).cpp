/*

    problem -->  no_of_meeting(Easy).cpp

    There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings.

        */



// it is like the activity selection problem ,,,the only difference is we have to print the meeting number ..so i use map for that


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

	    map< pair<lli,lli> ,lli> m;
	    for(lli i=0;i<n;i++)
	    {
	        v.push_back({start_time[i],finish_time[i]});
	        m[{start_time[i],finish_time[i]}]=i+1;
	    }



	    sort(v.begin(),v.end(),cmp);
	    lli cnt=1,r=v[0].second;
	    cout<<m[{v[0].first,v[0].second}]<<" ";
	    for(lli i=1;i<n;i++)
	    {
	       if(v[i].first>=r)
	       {

	           r=v[i].second;
	           cout<<m[{v[i].first,v[i].second}]<<" ";
	       }
	    }

	   cout<<endl;


	}
	return 0;
}
