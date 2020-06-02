/*

    problem- no_of_platform(good).cpp

    Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first line will contain an integer N, the number of trains. Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour (between 00 to 23 ) and last two characters represent minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= A[i] < D[i] <= 2359

Example:
Input:
2
6
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains

    */


#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return (p1.second<p2.second);
}

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arrival[n],departure[n];
	    for(int i=0;i<n;i++)
	    cin>>arrival[i];

	     for(int i=0;i<n;i++)
	     cin>>departure[i];

	        sort(arrival,arrival+n);
	        sort(departure,departure+n);

	        int ans=1,r=1,i=1,j=0;

	        while(i<n  && j<n)
	        {

	            if(arrival[i]<=departure[j])
	            {
	                i++;
	                r++;
	                ans=max(ans,r);
	            }
	            else
	            {
	                j++;
	                r--;

	            }
	        }

	        cout<<ans<<"\n";

	}
	return 0;
}
