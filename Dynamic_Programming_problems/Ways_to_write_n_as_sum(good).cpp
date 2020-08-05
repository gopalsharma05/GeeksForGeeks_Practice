/*

    problem-> Ways_to_write_n_as_sum(good).cpp


    Given a positive integer N, the task is to find the number of different ways in which N can be written as a sum of two or more positive integers.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains the
integer N.

Output:
For each testcase, in a new line, output the number of ways N can be written as the sum of two or more positive integers for each test case in a new line.
Since the answer can be quite large print the answer modulo 109+7.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
5
3
Output:
6
2

Explanation:
Testcase1:
5:
1+1+1+1+1
1+1+1+2
1+1+3
1+4
2+1+2
2+3
So, a total of 6 ways.



            */

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007



int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;

	    lli dp[n+1][n+1];



	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0)
	            dp[i][j]=0;

	            if(j==0)
	            dp[i][j]=1;
	        }
	    }

	    for(int i=1;i<=n;i++)
	    {
    	    for(int j=1;j<=n;j++)
    	    {
    	        if(i<=j)
    	        {
    	            dp[i][j]=dp[i][j-i]+dp[i-1][j];
    	            dp[i][j]=dp[i][j]%mod;
    	        }
    	        else
    	        {
    	            dp[i][j]=dp[i-1][j];
    	            dp[i][j]=dp[i][j]%mod;
    	        }
    	    }
	    }

	     cout<<dp[n][n]-1<<"\n";




	}



	return 0;
}
