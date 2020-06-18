/*

    problem -->  Number_of_paths_in_matrix_with_k_coins(good).cpp

    Given a N x N matrix where every cell has some number of coins. Count number of ways to reach bottom right cell of matrix from top left cell with exactly K coins. We can move to (i+1, j) or (i, j+1) from a cell (i, j).

Input:
First line contains number of test cases T. For each test case, first line contains the integer value 'X' denoting coins, second line contains an integer 'N' denoting the order of square matrix. Last line contains N x N elements in a single line in row-major order.

Output:
Output the number of paths possible.

Constraints:
1 <=T<= 500
1 <= K <= 50
1 <= N <= 50
1 <= Ai <= 200

Example:
Input:
2
16
3
1 2 3 4 6 5 9 8 7
12
3
1 2 3 4 6 5 3 2 1

Output:
0
2

Explanation:
Testcase 2: There are 2 possible paths with exactly K coins, which are (1 + 4 + 3 + 2 + 1) and (1 + 2 + 3 + 5 + 1).


            */


#include<bits/stdc++.h>
#define lli long long int
using namespace std;
#define pb push_back
lli dp[50][50][50];            // using 3D DP as 3 variable are changing in our function i.e  i,j,sum

// dynamo 123
lli ans=0;

lli checkpath(lli a[][210],lli i,lli j,lli n,lli k,lli sum)
{


   if(j>=n  || i>=n|| sum>k)
   return 0;

    sum+=a[i][j];

   if(j==n-1  && i==n-1)
   {
       return (sum==k);


   }

   if(dp[i][j][sum]!=-1)
    return dp[i][j][sum];


      dp[i][j][sum]= (checkpath(a,i,j+1,n,k,sum)+checkpath(a,i+1,j,n,k,sum));
      return dp[i][j][sum];

}

int main()
{

    lli t;
    cin>>t;

    while(t--)
    {
        lli n,k;
        cin>>k>>n;

        lli a[210][210];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>a[i][j];
        }

        lli sum=0;
        memset(dp,-1,sizeof(dp));
        cout<<checkpath(a,0,0,n,k,sum)<<"\n";


    }



    return 0;
}
