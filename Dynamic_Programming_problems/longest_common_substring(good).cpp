/*

    problem-> longest_common_substring(good).cpp


    Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M
denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.


            */


     // FIRST DO THE LCS OF 2 STRING , PROBLEM



#include <bits/stdc++.h>
using namespace std;


int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;

	    int dp[n+1][m+1];

	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0 ||  j==0)
	            {
	                dp[i][j]=0;

	            }

	        }
	    }


	    int ans=0;
	    for(int i=1;i<=n;i++)
	    {
        	    for(int j=1;j<=m;j++)
        	    {
        	        if(a[i-1]==b[j-1])
        	        {

        	            dp[i][j]=1+dp[i-1][j-1];
        	        }
        	        else
        	        {
        	           dp[i][j]=0;
        	        }

        	        ans=max(dp[i][j],ans);
        	    }


	    }

	    cout<<ans<<"\n";
	}
	return 0;
}
