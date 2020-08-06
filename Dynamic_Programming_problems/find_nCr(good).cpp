/*

    problem-> find_nCr(good).cpp

    Find nCr for given n and r.

Input:
First line contains number of test cases T. T testcases follow. Each testcase contains 1 line of input containing 2 integers n and r separated by a space.

Output:
For each testcase, in a new line, find the nCr. Modulus your output to 109+7.

Constraints:
1 <= T <= 50
1 <= n <= 103
1 <= r <= 800

Example:
Input:
2
3 2
4 2
Output:
3
6

        */



//APPROACH->WE KNOW THAT-> nCr+nC(r-1) =(n+1)Cr ==>(n-1)Cr +(n-1)C(r-1) = nCr...we can write in dp after initialization -> dp[i][j]=dp[i-1][j]+dp[i-1][j-1]




#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007;

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n,r;
	    cin>>n>>r;
	    int dp[n+1][r+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=r;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=1;

	        }

	    }

	    for(int i=2;i<=r;i++)
	    dp[1][i]=0;

	    dp[1][1]=1;

	    for(int  i=2;i<=n;i++)
	    {
	        for(int j=1;j<=r;j++)
	       {
	            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
	            dp[i][j]=dp[i][j]%mod;
	       }

	    }


	    cout<<dp[n][r]<<"\n";



	}

	return 0;
}
