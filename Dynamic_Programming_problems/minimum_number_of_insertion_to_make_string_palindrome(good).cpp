/*

    problem-> minimum_number_of_insertion_to_make_string_palindrome(good).cpp


    Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3




            */



#include <bits/stdc++.h>
using namespace std;


int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    string a;
	    cin>>a;
	    int n=a.length();
	    string b=a;
	    reverse(a.begin(),a.end());
	    int dp[n+1][n+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=0;
	            else if(a[i-1]==b[j-1])
	            dp[i][j]=1+dp[i-1][j-1];
	            else
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }

	    }

	    	cout<<n-dp[n][n]<<"\n";
	}



	return 0;
}
