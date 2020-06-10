/*

    problem-Sum_of_upper_and_lower_triangles(basic).cpp

    Given a square matrix mat[][] of size N*N, print the sum of upper and lower triangular elements. Upper Triangle consists of elements on the diagonal and above it. Lower triangle consists of elements on the diagonal and below it.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case consists of an integer N denoting the size of the matrix. The next line contains N*N spaced separated integers.

Output:
For each testcase, in a new line, print the required output.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= mat[i][j] <= 100

Example:
Input:
2
3
6 5 4 1 2 5 7 9 7
2
5 7 8 9
Output:
29 32
21 22

Explanation:
Testcase1: The given matrix is
6 5 4
1 2 5
7 9 7

The elements of upper triangle are
6 5 4
   2 5
      7

Sum of these elements is 6+5+4+2+5+7=29
The elements of lower triangle are
6
1 2
7 9 7

Sum of these elements is 6+1+2+7+9+7= 32

    */



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
	    int a[n][n];
	    int l=0,u=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            if(i>=j)
	            l+=a[i][j];

	            if(i<=j)
	            u+=a[i][j];

	        }
	    }


	    cout<<u<<" "<<l<<"\n";
	}
	return 0;
}
