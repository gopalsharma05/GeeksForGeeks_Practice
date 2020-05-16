/*

Subarray with 0 sum

    Given an array a[] of N positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains N space separated integers forming the array.

Output:
Print "Yes" ( without quotes) if there exist a subarray of size at least one with sum equal to 0 or else print "No" ( without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 104
-105 <= a[i] <= 105

Example:
Input:
2
5
4 2 -3 1 6
5
4 2 0 1 6

Output:
Yes
Yes

Explanation:
Testcase 1: 2, -3, 1 is the subarray with sum 0.

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
	    unordered_map<lli,lli> m;
	    m[a[0]]=1;
	    bool flag=false;
	    for(lli i=1;i<n;i++)
	    {
	        a[i]+=a[i-1];
	        m[a[i]]++;
	        if(m[a[i]]>1  ||  a[i]==0)
	        {
	            flag=true;
	            break;
	        }

	    }

	    if(flag)
	    cout<<"Yes\n";
	    else
	    cout<<"No\n";


	}

	return 0;
}
