/*



 problem-matrix_multiplication(easy).cpp

You are given two matrices A and B. A is of dimension n1 x m1; and B is of dimension n2 x m2. You have to multiply A with B and print the resultant matrix. If multiplication is not possible then print -1.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains four lines of input. The first line contains dimensions of the first array n1 and m1. The second line contains n1 * m1 elements separated by spaces. The third line contains dimensions of the second array n2 and m2. The fourth line contains n2 * m2 elements separated by spaces.

Output Format:
For each testcase, in a new line, print the resultant matrix if possible; else print -1.

Constraints:
1 <= T <= 100
1 <= n1, m1, n2, m2 <= 30
0 <= arri <= 100

Examples:
Input:
2
3 2
4 8 0 2 1 6
2 2
5 2 9 4
1 2
5 6
2 1
7 8

Output:
92 40 18 8 59 26
83

        */


#include <bits/stdc++.h>
using namespace std;

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int r1,c1,r2,c2;
	    cin>>r1>>c1;
	    int a[r1][c1];
	    for(int i=0;i<r1;i++)
	    {
	        for(int j=0;j<c1;j++)
	        cin>>a[i][j];
	    }

	    cin>>r2>>c2;
	    int b[r2][c2];

	    for(int i=0;i<r2;i++)
	    {
	        for(int j=0;j<c2;j++)
	        cin>>b[i][j];
	    }


	    if(c1==r2)
	    {
	           int ans[r1][c2];
	            int sum=0;

    	    for(int i=0;i<r1;i++)
    	    {
    	        for(int j=0;j<c2;j++)
    	        {
    	            sum=0;
    	            for(int k=0;k<c1;k++)
    	            {
    	                sum+=a[i][k]*b[k][j];
    	            }

    	             ans[i][j]=sum;
    	        }


    	    }



    	    for(int i=0;i<r1;i++)
    	    {
    	        for(int j=0;j<c2;j++)
    	        cout<<ans[i][j]<<" ";

    	    }

    	    cout<<endl;
	    }
	    else
	    {
	        cout<<"-1\n";
	    }

	}
	return 0;
}
