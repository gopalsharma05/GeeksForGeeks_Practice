/*

    problem->  max_circular_subArray_Sum(good).cpp

    Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contigious subarray sum.

Input:
First line of input contains a single integer T which denotes the number of test cases. First line of each test case contains a single integer N
which denotes the total number of elements. Second line of each test case contains N space separated integers denoting the elements of the array.

Output:
For each test case print the maximum sum obtained by adding the consecutive elements.

Constraints:
1 <= T <= 101
1 <= N <= 106
-106 <= Arr[i] <= 106

Example:
Input:
3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1

Output:
22
23
52

Explanation:
Testcase 1: Starting from last element of the array, i.e, 12, and moving in circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives
maximum sum as 22.


            */








#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli kedane(lli a[],lli n)
{
    lli r=a[0],t=a[0];

    for(lli i=1;i<n;i++)
    {
        r=max(a[i],r+a[i]);
        t=max(t,r);
    }

    return t;


}

int main() {
	//code
	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    lli a[n],sum=0;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum+=a[i];
	    }

	    lli k1=kedane(a,n);


	    for(lli i=0;i<n;i++)
	    a[i]=-a[i];

	    lli  k2=kedane(a,n);


	    lli ans=max(k1,sum+k2);
	    if(ans==0)
	    cout<<"-1\n";
	    else
	    cout<<ans<<"\n";


	}
	return 0;
}
