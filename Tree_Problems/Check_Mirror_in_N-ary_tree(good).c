/*

    problem-> Check_Mirror_in_N-ary_tree(good)

    Given two n-ary tree's the task is to check if they are mirror of each other or not.

Example

     1                    1
   /    \                 /   \
 2      3             3     2

Output: 1

    1                      1
   /  \                    /  \
 2    3                2    3

Output: 0

Note: you may assume that root of both the given tree as 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two space
separated values n and e denoting the no of nodes and edges respectively. Then in the next line two lines are 2*e space separated values u,v denoting an
edge from u to v for the both trees .

Output:
For each test case in a new line print 1 if both the trees are mirrors of each other else print 0.

Constraints:
1<=T<=20
1<=n<=15
1<=e<=20

Example:
Input:
2
3 2
1 2 1 3
1 3 1 2
3 2
1 2 1 3
1 2 1 3
Output:
1
0


            */



#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--)
	{
	    int n,e;
	    cin>>n>>e;
	    vector<int> a[n+1],b[n+1];

	    for(int i=0;i<e;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        a[x].push_back(y);
	    }


	    for(int i=0;i<e;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        b[x].push_back(y);
	    }

	    bool flag=true;

	    for(int i=1;i<=n;i++)
	    {
	            stack<int> st;
	            queue<int> q;
	        for(auto x:a[i])
	        {
	            st.push(x);
	        }
	        for(auto x:b[i])
	        {
	            q.push(x);
	        }




	    while(!st.empty() && !q.empty())
	    {
	        if(st.top()!=q.front())
	        {
	            flag=false;
	            break;
	        }

	        st.pop();
	        q.pop();

	    }

	    if(!st.empty() || !q.empty())
	   {
         flag=false;

	   }
	     if(flag==false)
	     break;




	    }



	    if(flag)
	    cout<<"1\n";
	    else
	    cout<<"0\n";

	}
	return 0;
}
