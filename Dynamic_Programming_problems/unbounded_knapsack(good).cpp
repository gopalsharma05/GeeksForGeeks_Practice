/*

    problem->unbounded_knapsack(good).cpp

    Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick
    any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the number of test cases. Then T test cases follow . Each test case contains two integers N and W
denoting the number of items and the total allowed weight. In the next two lines are space separated values of the array denoting values of the items
(val[]) and their weights (wt[]) respectively.

Output:
For each test case, in a new line, print the  maximum value which we can achieve if we can pick any weights any number of times for a bag of size W.

Constraints:
1 <= T <= 100
1 <= N, W <= 103
1 <= wt[], val[] <= 100

Example:
Input:
2
2 3
1 1
2 1
4 8
1 4 5 7
1 3 4 5
Output:
3
11




            */

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int find(int val[],int wt[],int n,int W )
{
    if(n==0 || W==0)
    return 0;

    if(dp[n][W]!=-1)
    return dp[n][W];

    if(wt[n-1]>W)
    return dp[n][W]= find(val,wt,n-1,W);

    return dp[n][W]= max(val[n-1]+find(val,wt,n,W-wt[n-1]),find(val,wt,n-1,W));
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    memset(dp,-1,sizeof(dp));
	    int n,W;
	    cin>>n>>W;

	    int val[n],wt[n];
	    for(int i=0;i<n;i++)
	    cin>>val[i];

	    for(int i=0;i<n;i++)
	    cin>>wt[i];

	    cout<<find(val,wt,n,W)<<"\n";

	}
	return 0;
}
