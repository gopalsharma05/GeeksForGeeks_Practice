/*

problem=First Repeating Element

Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.

Input :
The first line contains an integer T denoting the total number of test cases. In each test cases, First line is number of elements in array N and second its values.

Output:
In each separate line print the index of first repeating element, if there is not any repeating element then print “-1” (without quotes). Use 1 Based Indexing.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 106

Example:
Input:
3
7
1 5 3 4 3 5 6
4
1 2 3 4
5
1 2 2 1 3
Output:
2
-1
1

Explanation:
Testcase 1: 5 is appearing twice and its first appearence is at index 2 which is less than 3 whose first occuring index is 3.
Testcase 2: None of the elements are occuring twice . So, the answer is -1.
Testcase 3: 1 is appearing twice and its first appearence is at index 1 which is less than 2 whose first occuring is at index 2.

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
	    unordered_map<lli,lli> m;
	    lli minm=INT_MAX;
	    lli a[n];
	    for(lli i=1;i<=n;i++)
	    {
	        cin>>a[i];

	        if(m[a[i]]==0)
	        {
	           m[a[i]]=i;
	        }
	        else {

	            minm=min(minm,m[a[i]]);
	        }
	    }

	    if(minm!=INT_MAX)
	    cout<<minm<<"\n";
	    else
	    cout<<"-1\n";
	}

	return 0;
}
