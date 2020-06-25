/*

    problem-> Trapping_Rain_Water(good).cpp


    Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much
    water can be trapped in between blocks after raining.
Structure is like below:
| |
|_|
We can trap 2 units of water in the middle gap.



Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.



        */



approach -> just make two array which store the maxm value till every index from both side right and left.

#include <bits/stdc++.h>
using namespace std;
#define lli long long int



int main() {
	//code

	int t;
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

	    lli right_max[n],left_max[n];

	    left_max[0]=a[0];
	    for(lli i=1;i<n;i++)
	    {
	        left_max[i]=max(left_max[i-1],a[i]);
	    }



	    right_max[n-1]=a[n-1];
	    for(lli i=n-2;i>=0;i--)
	    right_max[i]=max(right_max[i+1],a[i]);





	    lli ans=0;
	    for(lli i=1;i<=n-2;i++)
	    {
	        lli r=min(left_max[i],right_max[i]);
	        if(r-a[i]>0)
	        ans+=r-a[i];

	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
