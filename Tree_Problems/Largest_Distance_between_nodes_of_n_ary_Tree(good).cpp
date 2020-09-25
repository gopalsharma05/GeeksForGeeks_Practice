/*
    problem-> Largest_Distance_between_nodes_of_n_ary_Tree(good).cpp


    Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



Problem Constraints
1 <= N <= 40000



Input Format
First and only argument is an integer array A of size N.



Output Format
Return a single integer denoting the largest distance between two nodes in a tree.



Example Input
Input 1:

 A = [-1, 0, 0, 0, 3]


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 node 0 is the root and the whole tree looks like this:
          0
       /  |  \
      1   2   3
               \
                4

 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.




                    */



 // fastest solution

  int Solution::solve(vector<int> &A) {
    vector<int> hgt(A.size(),0);
    int ans=0,maxx=0;
    for(int i=A.size()-1;i>0;i--){
        ans=max(ans,hgt[A[i]]+hgt[i]+1);
        hgt[A[i]]=max(hgt[i]+1,hgt[A[i]]);
    }
    return ans;
}


// SOLUTION USING  DFS


int ans=0;

int dfs(vector<vector< int> > v,vector<int> &vis,int i)
{



    vis[i]=true;
    vector<int> vec;
    for(auto x:v[i])
    {
        if(!vis[x])
        {
            vec.push_back(dfs(v,vis,x));
        }
    }

    sort(vec.begin(),vec.end(),greater<int>());
    if(vec.size()>=2)
    {
        ans=max(vec[0]+vec[1]+1,ans);
        return vec[0]+1;
    }
    else if(vec.size()==1)
    {
        ans=max(vec[0]+1,ans);
        return vec[0]+1;
    }
     else
    return 1;



}
int Solution::solve(vector<int> &a) {


    int n=a.size(),root;
    vector<vector<int> > v(n+1),vec(n+1);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            v[a[i]].push_back(i);
            v[i].push_back(a[i]);
        }
        else
        root=i;
    }

    vector<int> vis(n,0);

    ans=0;
    dfs(v,vis,root);

    return max(0,ans-1);




}




// OTHER SOLUTION IS->  run 2 DFS , in first find the deepest node, from there go to other deepest node and count the node for answer using one more time
//  DFS


int ans=0,r;

void dfs(vector<vector< int> > v,vector<int> &vis,int i,int cnt)
{
    if(vis[i])
    return ;
    vis[i]=1;
    cnt++;
    for(auto x:v[i])
    {
        if(vis[x]==0)
        {
            if(cnt>ans)
            {
                ans=cnt;
                r=x;
            }

           dfs(v,vis,x,cnt);
        }
    }



}
int Solution::solve(vector<int> &a) {


    int n=a.size(),root;
    vector<vector<int> > v(n+1);
    vector<int>  vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            v[a[i]].push_back(i);
            v[i].push_back(a[i]);

        }
        else
        root=i;
    }

    ans=INT_MIN;
    dfs(v,vis,root,0);
    for(int i=0;i<n;i++)
    vis[i]=0;


    ans=INT_MIN;

    dfs(v,vis,r,0);

    return (ans==INT_MIN)?0:ans;



}

