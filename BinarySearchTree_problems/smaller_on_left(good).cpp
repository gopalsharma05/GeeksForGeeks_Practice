/*

    problem=smaller_on_left(good).cpp

    Given an array arr[] of N elements. The task is to count maximum number of distinct smaller elements on right side of any array element. For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4.  Note that 20 has maximum 4 smaller elements on right side. Other elements have less count, for example 10 has 3 smaller elements on right side.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and next line contains array elements.

Output:
For each testcase, print the maximum count of smaller elements on right side.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 106

Example:
Input:
4
10
10 6 9 7 20 19 21 18 17 16
5
5 4 3 2 1
5
1 2 3 4 5
5
1 2 3 2 1

Output:
4
4
0
2

Explanation:

Testcase 1: Number of smaller elements on right side of every element (from left to right) in the array
are 3 0 1 0 4 3 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.
Testcase 2: Number of smaller elements on right side of every element (from left to right) in the array are
4 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.

        */




#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;

	    lli a[n];
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];

	    }
	    lli maxm=INT_MIN;
	    set<lli> s;
	    for(lli i=n-1;i>=0;i--)
	    {
	        s.insert(a[i]);
	        auto lb=s.lower_bound(a[i]);
	        lli dist=distance(s.begin(),lb);
	        //cout<<dist<<" ";
	        maxm=max(maxm,dist);
	    }

	    cout<<maxm<<"\n";


	}

	return 0;
}
