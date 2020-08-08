/*

    problem->Longest_Repeating_Subsequence(good).cpp

    Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an
integer N denoting the length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2


            */


#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string a;
	    cin>>a;

	    string b=a;
	    int dp[n+1][n+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j]=0;
	            }
	            else if(a[i-1]==b[j-1] && i!=j)
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else
	            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	        }
	    }

            cout<<dp[n][n]<<"\n";

	}
	return 0;
}
