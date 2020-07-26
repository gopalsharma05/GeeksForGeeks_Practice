/*

    problem->  Floyd_Warshall(good).cpp


    The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as Adjancency Matrix, and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix. The next V lines contain V space separated values of the matrix (graph). All input will be integer type.

Output:
For each test case output will be V*V space separated integers where the i-jth integer denote the shortest distance of ith vertex from jth vertex. For INT_MAX integers output INF.

Constraints:
1 <= T <= 20
1 <= V <= 100
1 <= graph[][] <= 500

Example:
Input
2
2
0 25
INF 0
3
0 1 43
1 0 6
INF INF 0

Output
0 25
INF 0
0 1 7
1 0 6
INF INF 0




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
	    int a[n][n],distance[n][n];
	    for(int  i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            distance[i][j]=a[i][j];
	        }
	    }


	     for(int  i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	           for(int k=0;k<n;k++)
	           {

	               distance[j][k]=min(distance[j][k],distance[j][i]+distance[i][k]);
	           }

	        }
	    }

	     for(int  i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(distance[i][j]==10000000)
	            {
	                cout<<"INF ";

	            }
	            else
	            cout<<distance[i][j]<<" ";
	        }

	        cout<<endl;
	    }







	}
	return 0;
}
