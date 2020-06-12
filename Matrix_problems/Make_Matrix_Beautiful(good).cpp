/*
    problem-> Make_Matrix_Beautiful(good).cpp
    Given a Square matrix mat[] of size NxN. Your task is to find minimum number of operation(s) that are required to make the matrix Beautiful.
A Beautiful matrix is a matrix in which sum of elements in each row and column is equal. In one operation you can only increment any value of cell of matrix by 1.

Input:
First line of the input contains an integer T denoting the number of test cases. Then T test case follows. First line of each test case contains an integer N denoting the size of the matrix. Next line contains NxN space separated integers denoting the elements of the matrix.

Output:
For each test case print a single integer in a new line denoting the minimum number of operations required that needed to be performed.

Constraints:
1 <= T <= 150
1 <= N <= 100
1 <= mat[i][j] <= 150

Example:
Input:
2
2
1 2 3 4
3
1 2 3 4 2 3 3 2 1

Output:
4
6

Explanation:
TestCase 1:
4 3
3 4
1. Increment value of cell(0, 0) by 3
2. Increment value of cell(0, 1) by 1
Hence total 4 operation are required.

    */




 #include <iostream>
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
	    int maxr=0,maxc=0;
	    for(int i=0;i<n;i++)
	    {
	        int sum=0;
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            sum+=a[i][j];
	        }

	        maxr=max(maxr,sum);

	    }

	   for(int i=0;i<n;i++)
	    {
	        int sum=0;
	        for(int j=0;j<n;j++)
	        {

	            sum+=a[j][i];
	        }

	        maxc=max(maxc,sum);
	    }


	    int maxm=max(maxr,maxc);
	   // cout<<maxm<<"\n";
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        int sum=0;
	        for(int j=0;j<n;j++)
	        {

	            sum+=a[j][i];
	        }

	       ans+=maxm-sum;
	    }

	    cout<<ans<<"\n";


	}

	return 0;
}
