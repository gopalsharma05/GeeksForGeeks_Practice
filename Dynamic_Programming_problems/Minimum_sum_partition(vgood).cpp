/*

    problem->  Minimum_sum_partition(vgood).cpp

    Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=200
1<=N<=50
1<=A[i]<=200


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output :
1
23

Explaination :
Testcase 1:
Subset1 = {1, 5, 6} ; sum of Subset1 = 12
Subset2 = {11} ;       sum of Subset2 = 11

Testcase 2:
Subset1 = {7, 46} ;   sum = 53
Subset2 = {36, 40} ; sum = 76



            */


   // suggestion->  first try to do "equal sum partition" problem



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
	    int a[n],sum=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum+=a[i];

	    }

	    int dp[n+1][sum+1];

	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0)
	            dp[i][j]=0;

	            if(j==0)
	            dp[i][j]=1;
	        }
	    }

	    for(int i =1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(a[i-1]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
	            }
	        }
	    }

	    int ans=INT_MAX;
	    for(int i=0;i<=sum/2;i++)
	    {
	        if(dp[n][i])
	        ans=min(ans,(sum-2*i));
	    }

	    cout<<ans<<"\n";



	}
	return 0;
}
