/*

    problem->  Distance_of_nearest_cell_having_1(good).cpp


    // do it after doing dijkstra algorithm



    Given a binary matrix of size N x M. The task is to find the distance of nearest 1 in the matrix for each cell. The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

Input:
The first line of input is an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of 2 lines . The first line of each test case contains two integers M and N denoting the number of rows and columns of matrix . Then in the next line are N*M space separated values of the matrix (mat) .

Output:
For each test case in a new line print the required distance matrix in a single line separated by space.

Constraints:
1 <= T <= 20
1 <= N, M <= 500

Example:
Input:
2
2 2
1 0 0 1
1 2
1 1

Output:
0 1 1 0
0 0

Explanation:
Testcase 1:
1 0
0 1
0 at {0, 1} and 0 at {1, 0} are at 1 distance from 1s at {0, 0} and {1, 1} respectively.


            */



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m],distance[n][m];
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==1)
                {
                    distance[i][j]=0;
                    q.push({i,j});
                }
                else
                {
                    distance[i][j]=INT_MAX;
                }
            }


        }

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            if(i<n && j+1<m && distance[i][j+1]>distance[i][j])
            {
                distance[i][j+1]=1+distance[i][j];
                q.push({i,j+1});
            }

            if(i<n && j-1>=0 && distance[i][j-1]>distance[i][j])
            {
                distance[i][j-1]=1+distance[i][j];
                q.push({i,j-1});
            }
            if(i+1<n && j<m && distance[i+1][j]>distance[i][j])
            {
                distance[i+1][j]=1+distance[i][j];
                q.push({i+1,j});
            }
            if(i-1>=0 && j<m && distance[i-1][j]>distance[i][j])
            {
                distance[i-1][j]=1+distance[i][j];
                q.push({i-1,j});
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<distance[i][j]<< " ";
            }
        }

        cout<<endl;

    }

}
