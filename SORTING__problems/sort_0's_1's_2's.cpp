// SAME as three way partitioning

/*
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output:
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
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
	    vector<lli> a(n);

	   for(lli i=0;i<n;i++)
	   cin>>a[i];

	   lli l=0,mid=0,h=n-1;

	   while(mid<=h)      // running o(n) loop
	   {
	       if(a[mid]==0)                 // if we encounter 0 swap it with l index so that it come before 1 and increment mid and l
	       {
	           swap(a[l],a[mid]);
	           l++;
	           mid++;

	       }
	       else if(a[mid]==2)			 // if we encounter 2 swap it with h index so that it come after 1 and decrement h
	       {
	           swap(a[h],a[mid]);
	           h--;
	       }
	       else
	       mid++;					// if we encounter 1 just increase mid
	   }

	   for(lli i=0;i<n;i++)
	   cout<<a[i]<<" ";

	   cout<<"\n";


	}
	return 0;
}
