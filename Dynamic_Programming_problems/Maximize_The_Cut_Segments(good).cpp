/*

    problem-> Maximize_The_Cut_Segments(good).cpp



    Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time
    is integer either x ,     y or z. and after performing all cutting operation the total number of cutted segments must be maximum.



Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase
contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000


Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1. In secon test case, we can make
two segments of lengths 3 and 2


                */


#include <bits/stdc++.h>
using namespace std;

int dp[4][4005];
int find(int coins[],int n,int val)
{
    if(n==0)
    return INT_MIN;

    if(val==0)
    return 0;

    if(dp[n][val]!=-1)
    return dp[n][val];

    if(coins[n-1]>val)
    return dp[n][val]=find(coins,n-1,val);

    return dp[n][val]=max(1+find(coins,n,val-coins[n-1]),find(coins,n-1,val));

}

int main() {
	//code

    int t;
    cin>>t;
    while(t--)
    {
        int val;
        cin>>val;
        memset(dp,-1,sizeof(dp));
       int a[3],n=3;
       for(int i=0;i<3;i++)
       {
           cin>>a[i];
       }

      int g= find(a,n,val);
       if(g==INT_MIN)
       cout<<"0\n";
       else
       cout<<g<<"\n";





    }
	return 0;
}
