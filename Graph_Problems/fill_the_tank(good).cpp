/*

    problem->  fill_the_tank(good).cpp





    In a city water tanks are connected by pipeline(As a tree). Since people working at the city corporation are lazy they usually select one
     of the tank and pour complete amount of water into it, when the tank is filled, the excess water evenly flows to the connected tanks. The head of
     city corporation has instructed to pour minimum amount of water into the selected tank so that all other tank is filled. As the labours of the
     corporation are not intelligent enough to figure out the minimum amount of water required to fill all the tanks they have asked your help. Also
     Maximum amount of water available with city corporation is 1018

NOTE: If the tank if full, the water flows to all of its connected tanks except the tank from which the water had come to it. i.e, to all tanks except the
source for that particular tank. If it has no
option to flow the water is considered to be wasted

Input:
First line contains single integer 't' denoting the number of test cases
First line of each testcase contains two integers 'n'and 's'
    n - number of tanks
    s - selected tank for pouring water
Next line contains n space separated integers, where ith integer denotes capacity of ith tank
Next n-1  line contains two integers 'u' and 'v' denoting there is a pipe connecting tank u and tank v

Output:
For each test case print the minimum amount of water required to fill all the tanks. If it is not possible to fill all the tanks print -1

Constraints:
1 <= t <= 10
1 <= n <= 100000
1 <= s,u,v <= n
1 <= capacity of each tank <= 1000000007

Example:
Input:
1
4 1
1 1 1 1
1 2
1 3
2 4

OUTPUT:
5

EXPLANATION:
Initially 5 unit of water is poured into tank 1. 2 unit of it flows to tank 2 and 2 unit of it flows into tank 3. From 2 unit of water in tank 2 1 unit flows into tank 4 and 1 unit from tank 3 is wasted.

        */





#include <bits/stdc++.h>
using namespace std;
#define limited 1e18
#define lli long long int



lli dfs(lli i,lli cap[],vector<lli> a[],vector<lli> &vis)
{
    vis[i]=1;



    if(a[i].size()==0)
    return cap[i];



    lli maxm=-1,c=0;

    for(auto x:a[i])
    {
        if(!vis[x])
        {
            c++;
           lli g=dfs(x,cap,a,vis);
           if(g==0)
           return 0;
           if(maxm<g)
           maxm=g;
        }

    }

    maxm=cap[i]+maxm*c;

    if(maxm>limited)
    {

        return 0;
    }
    else
    return maxm;

}



int main() {
	//code

	int  t;
	cin>>t;
	while(t--)
	{
	    lli n,start;
	    cin>>n>>start;
	    lli a[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        cin>>a[i];
	    }
	    vector<lli> v[n+1];

	    for(int i=0;i<n-1;i++)
	    {
	        lli  a,b;
	        cin>>a>>b;
	        v[a].push_back(b);
	        v[b].push_back(a);
	    }


	    vector<lli> vis(n+1,0);

	    lli ans=dfs(start,a,v,vis);
	    if(ans==0)
	    cout<<"-1\n";
	    else
	    cout<<ans<<"\n";


	}

	return 0;
}
