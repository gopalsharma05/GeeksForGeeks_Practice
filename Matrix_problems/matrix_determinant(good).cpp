/*

    problem-matrix_determinant(good).cpp

    Given a square matrix mat of size N x N. The task is to find the determinant of this matrix.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix. The next line contains the elements of the matrix in row-wise form.

Output:
Print the determinant of the matrix.

Constraints:
1 <= T <= 100
1 <= N <= 100
-100 <= mat[i][j] <= 100

Example:
Input:
2
4
1 0 2 -1 3 0 0 5 2 1 4 -3 1 0 5 0
3
1 2 3 4 5 6 7 10 9

Output:
30
12

        */

        #include <bits/stdc++.h>
using namespace std;
int MAX=105;
void findcofact(int a[][105],int n,int cofact[][105],int r,int c)
{
    int p=0,q=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=r && j!=c)
            {
                cofact[p][q++]=a[i][j];
                if(q==n-1)
                {
                    q=0;
                    p++;
                }
            }
        }

    }

}
int det(int a[][105],int n)
{
    if(n==1)
    return a[0][0];

    int cofact[105][105];
    int d=0,r=1;
    for(int i=0;i<n;i++)
    {
        findcofact(a,n,cofact,0,i);
        d+=r*a[0][i]*det(cofact,n-1);
        r=-r;
    }

    return d;
}

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[105][105];
	    for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    cin>>a[i][j];


	    cout<<det(a,n)<<"\n";


	}
	return 0;
}


