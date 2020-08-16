/*

        problem-> Total_Decoding_Messages(good).cpp

        A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are
leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.

Input:
First line contains the test cases T.  1<=T<=1000
Each test case have two lines
First is length of string N.  1<=N<=40
Second line is string S of digits from '0' to '9' of N length.

Example:
Input:
2
3
123
4
2563
Output:
3
2




            */


#include <bits/stdc++.h>
using namespace std;

int count(string s,int n)
{

    if(s[0]=='0')
    return 0;

      if(n==0 || n==1)
    return 1;

    int cnt=0;
    if(s[n-1]>'0')
    cnt=count(s,n-1);

    if(s[n-2]=='1' ||(s[n-2]=='2' && s[n-1]<='6'))
    cnt+=count(s,n-2);

    return cnt;



}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    // cout<<count(s,n)<<"\n";   using recursion

	    // using bottom up

	    int dp[n+1];
	    dp[0]=dp[1]=1;

	    for(int i=2;i<=n;i++)
	    {
	        dp[i]=0;
	        if(s[i-1]>'0')
	        dp[i]=dp[i-1];

	        if(s[i-2]=='1' ||(s[i-2]=='2' && s[i-1]<='6'))
	        dp[i]+=dp[i-2];
	    }

	    if(s[0]=='0')
	    cout<<"0\n";
	    else
	    cout<<dp[n]<<"\n";

	}
	return 0;
}
