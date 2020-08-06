/*

    problem-> Longest_Common_Subsequence(good).cpp



    Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2


            */




#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int dp[120][120];

int LCS(string a,string b,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;

    }

    if(dp[n][m]!=-1)
    return dp[n][m];


    if(a[n-1]==b[m-1])
    return dp[n][m]= 1+LCS(a,b,n-1,m-1);
    else
      return dp[n][m]= max(LCS(a,b,n,m-1),LCS(a,b,n-1,m));


}


int main() {
	//code

	lli t;cin>>t;
	while(t--)
    {
        lli  a,b;
        cin>>a>>b;
        string s1,s2;
        cin>>s1>>s2;

        memset(dp,-1,sizeof(dp));

        cout<<LCS(s1,s2,a,b)<<"\n";


    }

	return 0;
}
