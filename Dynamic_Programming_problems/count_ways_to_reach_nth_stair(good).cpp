/*

    problem->   count_ways_to_reach_nth_stair(good).cpp

    There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time.
     Count the number of ways, the person can reach the top (order does matter).

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, an integer N will be given.

Output:
For each testcase, in a new line, print number of possible ways to reach Nth stair. Answer your output % 10^9+7.

Constraints:
1<=T<=105
1<=N<=105

Example:
Input:
3
4
10
24
Output:
5
89
75025

        */



// APPROACH-->  TRY SOME EXAMPLE,,,YOU WILL FIND FIBONACCI PATTERN.....so you have to just print nth fibonacci number


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {

	int t;
	cin>>t;
	 int dp[1000006];
	    dp[0]=1;
	    dp[1]=2;
	    for(int i=2;i<1000006;i++)
	    {
	        dp[i]=dp[i-1]+dp[i-2];
	        dp[i]=dp[i]%mod;
	    }
	while(t--)
	{
	    int n;
	    cin>>n;



	    cout<<dp[n-1]<<"\n";

	}
	return 0;
}
