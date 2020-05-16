/*

    problem-> subarrays_with_given_sum

    Given an unsorted array arr[] of N integers and a sum. The task is to count the number of subarrays which add to a given number.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated integers forming the array. The last line contains an integer denoting the value of the sum.

Output:
Print the count of the subarray which adds to the given sum.

Constraints:
1 <= T <= 200
1 <= N <= 105
-105 <= arr[i] <= 105
-105 <= sum <= 105

Example:
Input:
2
5
10 2 -2 -20 10
-10
6
1 4 20 3 10 5
33

Output:
3
1

Explanation:
Testcase 1: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].

        */


#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code

	lli  t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    lli a[n];

	    unordered_map<lli,lli> m;

	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];


	    }
	    lli x;
	    cin>>x;

	    lli sum=0,cnt=0;
	    for(lli i=0;i<n;i++)
	    {
	        sum+=a[i];

	        if(sum==x)
	        cnt++;

	        if(m[sum-x]!=0)
	        {
	            cnt+=m[sum-x];
	        }
	        m[sum]++;
	    }
	    cout<<cnt<<"\n";


	}
	return 0;
}
