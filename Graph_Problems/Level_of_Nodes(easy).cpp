/*
    problem-> Level_of_Nodes(easy).cpp

    Given an undirected graph of N edges and a node X is given. The task is to find the level of X. if X does not exist
    in the graph then print -1.



Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes and
edges N and E. Next E lines contais U and V, which represents that there is an edge between U and V. The final line
contains X whose level we have to find.

Output:
For each testcase, print the level of the given node X.

Constraints:
1 <= T <= 100
1 <= E, N <= 104
1 <= X <= 104

Example:
Input:
2
8 8
0 1
0 2
1 3
1 4
1 5
2 6
6 7
2 5
7
4 4
0 1
1 2
0 3
1 3
2

Output:
3
2

Explanation:
Testcases 1: In the given graph(above), 7 is at 3rd level starting from source node 0 which is at 0th level.




        */




#include<bits/stdc++.h>
using namespace std;



int ans;
void dfs(int i,vector<int> v[],map<int,int> m,int X)
{
    if(i==X )
    {
        ans=min(ans,m[i]);
    }
    for(auto x:v[i])
    {
        if(m[x]==-1)
        {
            m[x]=m[i]+1;
            dfs(x,v,m,X);
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;

        vector<int> v[n];
        for(int i=0;i<e;i++)
        {
            int a ,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);


        }

        int x;
        cin>>x;


        map<int,int> m;
        for(int i=0;i<n;i++)
        m[i]=-1;

        m[0]=0;

        ans=INT_MAX;
        dfs(0,v,m,x);

        if(ans==INT_MAX)
        cout<<"-1\n";
        else
        cout<<ans<<"\n";


    }
}
