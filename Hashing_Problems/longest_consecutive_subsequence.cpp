/*

problem=-->  longest_consecutive_subsequence

Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:
The first line of input contains T, number of test cases. First line of line each test case contains a single integer N.
Next line contains N integer array.

Output:
Print the output of each test case in a seprate line.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= a[i] <= 105

Example:
Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
4

Explanation:
Testcase 1:  The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Testcase2: 1, 2, 3, 4 is the longest consecutive subsequence.



    */

// i solve this sorting.....another method is to use set

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

	    sort(a,a+n);
	    lli cnt=0,maxm=1;
	    for(lli i=0;i<n-1;i++)
	    {
	        if(a[i+1]-a[i]!=1)
	        {
	            if(a[i+1]-a[i]==0)
	            continue;

	            maxm=max(cnt+1,maxm);
	            cnt=0;
	        }
	        else
	        cnt++;
	    }
	    maxm=max(cnt+1,maxm);

	    cout<<maxm<<"\n";

	}
	return 0;
}
