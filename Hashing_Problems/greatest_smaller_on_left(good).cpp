/*

problem-->smaller_on_left


Given an array arr[] of N positive integers. The task is to find the greatest smaller on left of every element in the array.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N and next line contains array elements.

Output:
For each testcase, print the array which contains greatest smaller element on left of every corresponding element in the array. For the element whose smaller on left doesn't exists, consider -1 as greatest smaller.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 108

Example:
Input:
1
5
2 3 4 5 1

Output:
-1 2 3 4 -1

Explanation:
Testcase 1: Smallest element on left of 3 is 2, 4 is 3 and 5 is 1. Since 2 is the first element and no element on left
is present, so it's greatest smaller element will be -1 and that for 1, no greatest smaller element is present on left, so it's
greatest smaller element is -1.

*/


// code

#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--)
	{

	    lli n;
	    cin>>n;
	    lli a[n];
	    set<lli> s;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
	        s.insert(a[i]);

	        auto it=s.lower_bound(a[i]);
	        if(it==s.begin())
            cout<<"-1 ";
            else
            cout<<*(--it)<<" ";




	    }


	    cout<<"\n";
	}

	return 0;
}
