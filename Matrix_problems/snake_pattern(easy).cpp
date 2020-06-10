/*

   problem-snake_pattern(easy).cpp

   Given a matrix mat[][] of size N x N. The task is to print the elements of the matrix in the snake pattern.


Input:
First line consists of an integer T denoting the number of test cases. First line of each test case consists of N, denoting number of elements(N x N) in Matrix. Second line of every test case consists of N x N spaced integers denoting elements of Matrix elements.

Output:
For each testcase, in a new line, print the matrix in snake pattern.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= mat[i][j] <= 100

Example:
Input:
2
3
45 48 54 21 89 87 70 78 15
2
25 27 23 21

Output:
45 48 54 87 89 21 70 78 15
25 27 21 23

Explanation:
Testcase 1: Matrix is as below:
45 48 54
21 89 87
70 78 15

Printing it in snake pattern will lead to the output as 45 48 54 87 89 21 70 78 15.

    */




#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int n,m;
	   cin>>n;
	   int a[n][n];
	   m=n;

	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           cin>>a[i][j];
	       }
	   }

	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           if(i%2==0)
	           {
	               cout<<a[i][j]<<" ";
	           }
	           else
	           {
	               cout<<a[i][m-j-1]<<" ";
	           }
	       }
	   }

	   cout<<endl;
	}
	return 0;
}
