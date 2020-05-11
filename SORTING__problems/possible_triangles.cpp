
/*
Given an unsorted array of positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.

Input:
The first line of the input contains T denoting the number of testcases. First line of test case is the length of array N and second line of test case are its elements.

Output:
Number of possible triangles are displayed to the user.

Constraints:
1 <= T <= 200
3 <= N <= 107
1 <= arr[i] <= 103

Example:
Input:
2
3
3 5 4
5
6 4 9 7 8

Output:
1
10
*/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main() {



	lli t;
	cin>>t;  // test cases
	while(t--)
	{
	    lli n;
	    cin>>n;    // size of array
	    lli a[n];

	    for(lli i=0;i<n;i++)
	    cin>>a[i];                  // taking array element as input

	    sort(a,a+n);                // sorting the array , so that can be done in O(n^2)

	    lli cnt=0;
	    for(lli i=0;i<n-2;i++)
	    {
	        lli k=i+2;                  // we are taking 1st 2 elements, starting with 3rd element
                                        // with index k,finding the maxm k till we get (a[k]>a[i]+a[j])
                                        // so then we have our range and increament our global count by k-j-1
	        for(lli j=i+1;j<n;j++)
	        {
	            while(k<n && a[k]<a[i]+a[j])
	            k++;

	            if(k>j)
	            cnt+=k-j-1;

	        }
	    }

	    cout<<cnt<<"\n";


	}
	return 0;
}
