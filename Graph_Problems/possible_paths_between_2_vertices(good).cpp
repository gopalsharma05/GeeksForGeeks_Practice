/*

    problem-> possible_paths_between_2_vertices(good).cpp



    Count the total number of ways or paths that exist between two vertices in a directed graph. These paths doesn’t contain a cycle.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers N and M . In the next line are M space separated values u,v denoting an edge from u to v. Next line contains the starting node s and the ending node e. (The vertices start from 1)

Output: For each testcase print the total number of paths that exists between the starting and the ending node.

Constraints:
1<=T<=100
1<=N,M<=100
1<=u,v, s,e<=N

Example:
Input:
1
5 7
1 2 1 3 1 5 2 4 2 5 3 5 4 3
1 5
Output:
4

Explanation:
Testcase 1 :  There are 4 paths from 1 to 5.
                       1 -> 5
                       1 -> 2 -> 5
                       1 -> 3 -> 5
                       1 -> 2 -> 4 -> 3 -> 5


        */


      //    DYNAMO123

#include <bits/stdc++.h>
using namespace std;

void addedges(int a,int b,vector<int> vec[])
{
    vec[a].push_back(b);
}

int cnt=0;

void dfs(int start,int end,vector<int> v[],int n,bool vis[])
{
    if(vis[start])
    return ;

    if(start==end)
    cnt++;

    vis[start]=true;



    for(auto x:v[start])
    {
        if(vis[x]==false)
        {
            dfs(x,end,v,n,vis);
        }
    }

    vis[start]=false;

}

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<int> vec[n+1];

	    for(int i=0;i<m;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        addedges(u,v,vec);



	    }

	    int s,e;
	    cin>>s>>e;


	    bool visi[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        visi[i]=false;
	    }


	    dfs(s,e,vec,n,visi);

	    cout<<cnt<<"\n";

	    cnt=0;


	}

	return 0;
}
