/*

    problem-> Print adjacency list(easy).cpp

    Given number of edges 'E' and vertices 'V' of a bidirectional graph. Your task is to build a graph through adjacency list and print the adjacency list
     for each vertex.

Input:
The first line of input is T denoting the number of testcases.Then first line of each of the T contains two positive integer V and E where 'V' is the
number of vertex and 'E' is number of edges in graph. Next, 'E' line contains two positive numbers showing that there is an edge between these two vertex.

Output:
For each vertex, print their connected nodes in order you are pushing them inside the list . See the  given  example.

Constraints:
1 <= T <= 200
1 <= V <= 103
1 <= E = V*(V-1)

Example:
Input:
2
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
3 3
0 1
1 2
2 0

Output:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3
0-> 1-> 2
1-> 0-> 2
2-> 1-> 0

Explanation:
Testcase 1: Given graph has 5 nodes and 7 edges. After creating adjacency list of given graph, we have list as:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3


        */






#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int v,e;
	    cin>>v>>e;

	    vector<int> adj[v];
	    for(int i=0;i<e;i++)
	    {
	        int a,b;
	        cin>>a>>b;
	        adj[a].pb(b);
	        adj[b].pb(a);
	    }


	    for(int i=0;i<v;i++)
	    {


	           cout<<i;
	           int n=adj[i].size();
	           for(int j=0;j<n;j++)
	           {
	               cout<<"-> "<<adj[i][j];
	           }

	           cout<<endl;






	    }




	}

	return 0;


}
