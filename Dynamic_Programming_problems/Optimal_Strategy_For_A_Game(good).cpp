/*

    problem-> Optimal_Strategy_For_A_Game(good).cpp

    You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2,
    ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains
N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)

            */




#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int dp[120][120];



int playoptimal(int a[],int start,int end)
{
    if(start>end)
    return 0;

    if(dp[start][end]!=-1)
    return dp[start][end];

    return dp[start][end]=max((a[end]+min(playoptimal(a,start,end-2),playoptimal(a,start+1,end-1))),(a[start]
            + min(playoptimal(a,start+2,end),playoptimal(a,start+1,end-1))));



}


int main() {
	//code
	int  t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;

	    memset(dp,-1,sizeof(dp));

	    int a[n];

	    for(lli i=0;i<n;i++)
	    cin>>a[i];

	    cout<<playoptimal(a,0,n-1)<<"\n";



	}

	return 0;
}
