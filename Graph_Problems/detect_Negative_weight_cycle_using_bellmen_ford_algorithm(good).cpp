/*

    problem-> detect_Negative_weight_cycle_using_bellmen_ford_algorithm(good).cpp


    Given a graph, the task is to check if it contains a negative weight cycle or not.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 2 lines the first line contains two space separated integers v and e denoting the no of vertices and no of edges respectively. Then in the next line are 3*e space separated values x,y,z denoting an edge from x to y with a weight of z.

Output:
For each test case in a new line print 0 if there is no negative weight cycle else print 1.

Constraints:
1 <= T <= 50
1 <= v <= 100
1 <= e <= 50

Example:
Input:
2
5 8
0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
3 3
0 1 -5 1 2 -6 2 0 -9
Output:
0
1



                */




NOTE->  IF EDGE HAS -VE WIEGHTS,  YOU CAN NOT FIND THE SHORTEST DISTANCE BETWEEN THE SOURCE TO EVERY NODE USING DJIKSTRA. SO YOU CAN USE BELLMAN FORD ALGO
                    // FOR FINDING THE SHORTEST PATH. IT will not work if graph contains Negative_weight_cycle.








#include <bits/stdc++.h>
using namespace std;

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{

	    int n,e;
	    cin>>n>>e;
	    int ar[n][n];
	    int distance[n];

	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                ar[i][j]=INT_MAX;
	            }

	            distance[i]=INT_MAX;

	        }

	    int a,b,c;
	    for(int i=0;i<e;i++)
	    {

	        cin>>a>>b>>c;
	        ar[a][b]=c;



	    }

	    int src=0;
	    distance[src]=0;       //  if you want to find the shortest path from given source vertex src, replace src with given src in question.


	    for(int k=0;k<n-1;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(ar[i][j]!=INT_MAX)
	                {
	                    if(distance[i]!=INT_MAX &&distance[j]>ar[i][j]+distance[i])
	                    {
	                        distance[j]=ar[i][j]+distance[i];
	                    }
	                }
	            }
	        }
	    }
	    bool cycle=false;

	    for(int i=0;i<n;i++ )
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(ar[i][j]!=INT_MAX)
	                {
	                    if(distance[i]!=INT_MAX && distance[j]>ar[i][j]+distance[i])
	                    {
	                        cycle=true;
	                    }
	                }
	            }
	        }

	  cout<<cycle<<"\n";



	}

	return 0;
}
