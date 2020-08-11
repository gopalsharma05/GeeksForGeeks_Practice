/*

    problem-> minimum_element_in_rotated_sorted_array(good).cpp


    A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Expected Time Complexity: O(Log n)

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines.
The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements.

Output:
Corresponding to each test case, in a new line, print the minimum element in the array.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 1000

Example:

Input
2
5
4 5 1 2 3
6
10 20 30 40 50 5 7

Output
1
5



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

	    int l=0,r=n-1,ans;
	    while(l<=r)
	    {
	        int mid=l+(r-l)/2;
	        if(l==r)
	       {
	           ans=a[0];
	           break;
	       }
	        else if( mid<r && a[mid]>a[mid+1])
	        {
	            ans=a[mid+1];
	            break;
	        }
	        else if(mid>l && a[mid]<a[mid-1])
	        {
	            ans=a[mid];
	            break;
	        }
	        else if(a[mid]>a[0])
	        l=mid+1;
	        else r=mid-1;

	    }

	    cout<<ans<<"\n";


	}
	return 0;
}
