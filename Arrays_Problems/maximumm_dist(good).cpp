/*
    problem-> maximumm_dist(good).cpp
    Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then T test case follows. First line of each test case contains an integer N denoting the size of the array. Next line contains N space separated integeres denoting the elements of the array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

Constraints:
1 ≤ T ≤ 1000
1 ≤ N ≤ 103
0 ≤ A[i] ≤ 1018

Example:
Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6

Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1).


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
	    cin>>a[i];

	    lli minm[n],maxm[n];

	    minm[0]=a[0];
	    for(lli i=1;i<n;i++)
	    {

	        minm[i]=min(minm[i-1],a[i]);
	    }


	    maxm[n-1]=a[n-1];
	    for(lli i=n-2;i>=0;i--)
	    {

	        maxm[i]=max(a[i],maxm[i+1]);

	    }



	    lli ans=-1,i=0,j=0;
	    while(i<n && j<n)
	    {
	        if(minm[i]<=maxm[j])
	        {
	            ans=max(ans,j-i);
	            j++;
	        }
	        else
	        {
	            i++;
	        }
	    }

	    cout<<ans<<"\n";


	}
	return 0;
}
