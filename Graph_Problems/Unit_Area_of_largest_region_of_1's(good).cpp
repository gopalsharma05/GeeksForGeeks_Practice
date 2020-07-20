/*

        problem-> Unit_Area_of_largest_region_of_1's(good).cpp


    // SOLVED USING BOTH DFS AND BFS

        Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers n and m. Then in the next line are the n x m inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1



        */








  // DYNAMO
  // DYNAMO

 #include<bits/stdc++.h>
 #define lli long long int
 using namespace std;


int usingBFS(vector<vector<int> > a,int n,int m,vector<vector<int> > visited)
{



        queue< pair < int,int > > q;
        int ans=INT_MIN;

        for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(a[i][j]==1 && visited[i][j]==0)
	            {
	                visited[i][j]=1;
	                q.push({i,j});

	                int cnt=0;
	                while(!q.empty())
	                {
	                    pair<int,int> p=q.front();
	                    int i=p.first;
	                    int j=p.second;
	                     cnt++;

	                    q.pop();
	                    int xwala[]={0,0,1,1,1,-1,-1,-1};
	                    int ywala[]={1,-1,0,1,-1,0,-1,1};


	                    for(int k=0;k<8;k++)
	                    {
	                        int x=i+xwala[k];
	                        int y=j+ywala[k];

	                        if(x>=0 && y>=0  && x<n  && y<m && a[x][y]==1 && visited[x][y]==0)
	                        {

	                            visited[x][y]=1;
	                            q.push({x,y});
	                        }
	                    }


	                }

	                ans=max(ans,cnt);

	            }

	        }
	    }


	    	    return ans;

}



    void dfs(int i,int j,vector<vector<int> > a,vector<vector<int> > &visited,int &cnt,int n,int m)
    {
        if(i<0 || i>=n  || j<0  || j>=m || visited[i][j]==1 ||a[i][j]==0)
        return ;

        visited[i][j]=1;

        cnt++;

        dfs(i,j+1,a,visited,cnt,n,m);
        dfs(i,j-1,a,visited,cnt,n,m);
        dfs(i+1,j+1,a,visited,cnt,n,m);
        dfs(i-1,j-1,a,visited,cnt,n,m);
        dfs(i+1,j-1,a,visited,cnt,n,m);
        dfs(i+1,j,a,visited,cnt,n,m);
        dfs(i-1,j,a,visited,cnt,n,m);
        dfs(i-1,j+1,a,visited,cnt,n,m);



    }



int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > a(n,vector<int>(m)),visited(n,vector<int>(m));

	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>a[i][j];
	            visited[i][j]=0;

	        }
	    }

	   // int ans=INT_MIN;

	   // for(int i=0;i<n;i++)
	   // {
	   //     for(int j=0;j<m;j++)
	   //     {
	   //         int cnt=0;
	   //         if(visited[i][j]==0 && a[i][j]==1)
	   //         {
	   //             dfs(i,j,a,visited,cnt,n,m);
	   //             ans=max(ans,cnt);
	   //         }
	   //     }
	   // }
	   // cout<<ans<<"\n";


	   cout<<usingBFS(a,n,m,visited)<<"\n";




	}

	return 0;
}
