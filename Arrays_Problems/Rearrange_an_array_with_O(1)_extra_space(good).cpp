/*


    problem -> Rearrange_an_array_with_O(1)_extra_space(good).cpp


    Given an array arr[] of size N where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].
    This should be done with O(1) extra space.

Input:
First line contains an integer denoting the test cases 'T'. First line of each test case contains an integer value depicting size of array 'N' and next
line contains N space separated integers denoting the elements of the array.

Output:
Print all elements of the array after rearranging, each separated by a space, in separate line for each test case.

Constraints:
1 <= T <= 100
1 <= N<= 107
0 <= Arr[i] < N

Example:
Input:
3
2
1 0
5
4 0 2 1 3
4
3 2 0 1

Output:
0 1
3 4 2 0 1
1 0 3 2

Explanation:
Testcase 1: arr[0] = 1 and arr[arr[0]] = 0. Also, arr[1] = 0 and arr[arr[1]] = 1. So, rearranging elements, we get array as, 0 1



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


	    lli divisor=n;
	    for(lli i=0;i<n;i++)
	    {
	        a[i]+=(a[a[i]]%divisor)*divisor;
	    }
	    for(lli i=0;i<n;i++)
	    {
	        a[i]=a[i]/divisor;
	    }

	    for(lli i=0;i<n;i++)
	    cout<<a[i]<<" ";

	    cout<<"\n";

	}

	return 0;
}
