    /*

    //DYNAMO123

    problem->Rat_Maze_With_Multiple_Jumps(good).cpp

        A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move in only two directions: first forward if possible or down. If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].
In this variation, Rat is allowed to jump multiple steps at a time instead of 1.

Input:
The first line of input contains an integer T denoting the number of test cases. For each test case, the first line contains an integer n denoting the size of the square matrix followed by  N*N space-separated values of the matrix m where 0's represents blocked paths and any number represents valid paths.

Output:
For each test case, the output is a matrix containing 1 for the path taken and 0 for not chosen path. If no path exists print -1.

Constraints:
1 <= T <= 50
2 <= n <= 10
0 <= m[i][j] <= 5

Example:
Input
2
4
2 1 0 0
3 0 0 1
0 1 0 1
0 0 0 1
4
2 1 0 0
2 0 0 1
0 1 0 1
0 0 0 1

Output:
1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1
-1

Explanation:
Testcase 1:  Rat started with m[0][0] and can jump up to 2 steps right/down. First check m[0][1] as it is 1, next check m[0][2], this won't lead to the solution. Then check m[1][0], as this is 3(non-zero), so we can make 3 jumps to reach m[1][3]. From m[1][3] we can move downwards taking 1 jump each time to reach destination at m[3][3].

Testcase 2: As no path exists, so -1.

            */



 approach -->  Make other matrix of n*n to store the path ,Using backtracking , if we able to reach the destination from (i,j) cell(by moving right and down)
            // .....we will mark it  true ,else we will choose other right and down cell using the value stored in mat[i][j].



#include <bits/stdc++.h>
using namespace std;

int MAX=50;
int b[20][20]={0};
bool backtrack(int a[][100],int i,int j,int n)
{
    if(i==n-1  && j==n-1)
    {
         b[i][j]=1;
        return true;
    }

    if( i>=n  ||  j>=n  ||  a[i][j]==0 )
    return false;



    for(int k=1;k<=a[i][j];k++)
    {
        if(backtrack(a,i,j+k,n))
        {
            b[i][j]=1;
            return true;
        }



       else if(backtrack(a,i+k,j,n))
       {
            b[i][j]=1;
            return true;
       }



    }
    return false;


}

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[100][100];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	        }
	    }

	    memset(b,0,sizeof(b));

	    b[0][0]=1;

	    if(backtrack(a,0,0,n))
	    {
	        //b[n-1][n-1]=1;
    	    for(int i=0;i<n;i++)
    	    {
    	        for(int j=0;j<n;j++)
    	        {
    	            cout<<b[i][j]<<" ";
    	        }
    	        cout<<endl;
    	    }
	    }
	    else
	    cout<<"-1\n";

	}


	return 0;
}
