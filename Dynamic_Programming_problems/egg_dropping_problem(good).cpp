/*

        problem-> egg_dropping_problem(good).cpp



        Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have
        to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are
        few rules given below.

        An egg that survives a fall can be used again.
        A broken egg must be discarded.
        The effect of a fall is the same for all eggs.
        If the egg doesn't break at a certain floor, it will not break at any floor below.
        If the eggs breaks at a certain floor, it will break at any floor above.
        For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of
eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3




            */


#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int dp[100][100];

int eggdrop(int n,int k)
{
    if(k==0 ||  k==1 || n==1)
    return k;

    if(dp[n][k]!=-1)
    return dp[n][k];

    int minm=INT_MAX;
    for(int i=1;i<=k;i++)
    {
            int t=1+max(eggdrop(n-1,i-1),eggdrop(n,k-i));
            minm=min(minm,t);
    }


    return dp[n][k]= minm;

}





int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;

	    lli k;
	    cin>>k;

	    memset(dp,-1,sizeof(dp));

	   cout<<eggdrop(n,k)<<"\n";  // using recursion with memoization



	   // BELOW IS TOP DOWN APPROACH

	   // lli dp[n+1][k+1];

	   // for(int i=1;i<=k;i++)
	   // {
	   //     dp[1][i]=i;
	   // }

	   // for(int i=1;i<=n;i++)
	   // {
	   //     dp[i][0]=0;
	   //     dp[i][1]=1;
	   // }

	   // for(int i=2;i<=n;i++)
	   // {

	   //     for(int j=2;j<=k;j++)
	   //     {
	   //         dp[i][j]=INT_MAX;
	   //         for(int l=1;l<=j;l++)
	   //         {
	   //             lli temp=1+max(dp[i-1][l-1],dp[i][j-l]);
	   //             dp[i][j]=min(dp[i][j],temp);
	   //         }
	   //     }
	   // }



	   // cout<<dp[n][k]<<"\n";
	}
	return 0;
}
