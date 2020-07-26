/*
    problem-> Minimum_Cost_Path(vgood).cpp

    Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.

Note: It is assumed that negative cost cycles do not exist in the input matrix.

Input:
The first line of input will contain the number of test cases T. Then T test cases follow. Each test case contains 2 lines. The first line of each test case contains an integer N denoting the size of the grid. The next line of each test contains a single line containing N*N space separated integers depicting the cost of the respective cells from (0, 0) to (N - 1, N - 1).

Output:
For each testcase, in a new line, print the minimum cost to reach bottom right cell from top left cell.

Your Task:
Complete shortest() function which takes a N*N grid and N as input parameters and returns a single integer depicting the minimum cost to reach the destination.
Expected Time Complexity: O(N * N * log N).
Expected Auxiliary Space: O(N * N).

Constraints:
1 <= T <= 50
1 <= N <= 1000
1 <= cost of cells <= 106

Example:
Input:
2
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14

Output:
327
63

Explanation:
Testcase 1:
Grid is:
 31,   100,   65,   12,   18,
 10,    13,    47,  157,   6,
100,  113,  174,   11,   33,
 88,   124,   41,    20,  140,
 99,    32,   111,   41,   20
A cost grid is given in above diagram, minimum
cost to reach bottom right from top left
is 327 (31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20)
Testcase 2:
Grid is:
42 93
07 14
A cost grid is given in above diagram, minimum
cost to reach bottom right from top left
is 63(42+7+14)



                */


      //   APPROACH ->SIMPLE DIJKSTRA ALGORITHM APPLICAITON ON MATIRX


#define prop pair<int,pair<int,int> >
int shortest(vector<vector<int> > &a, int n) {

    vector<vector<int> > distance(n,vector<int>(n,INT_MAX));

    distance[0][0]=a[0][0];

    priority_queue< prop,vector<prop>,greater<prop> >pq;

    pq.push({a[0][0],{0,0}});

    while(!pq.empty())
    {
        prop p=pq.top();
        int dist=p.first;
        pair<int,int> pr=p.second;

        int i=pr.first;
        int j=pr.second;

        pq.pop();

        if(j+1<n  && distance[i][j+1]>dist+a[i][j+1])
        {
             distance[i][j+1]=dist+a[i][j+1];
             pq.push({distance[i][j+1],{i,j+1}});
        }
        if(j-1>=0 && distance[i][j-1]>dist+a[i][j-1])
        {
             distance[i][j-1]=dist+a[i][j-1];
             pq.push({distance[i][j-1],{i,j-1}});
        }
       if(i+1<n  && distance[i+1][j]>dist+a[i+1][j])
        {
             distance[i+1][j]=dist+a[i+1][j];
             pq.push({distance[i+1][j],{i+1,j}});
        }
        if(i-1>=0  && distance[i-1][j]>dist+a[i-1][j])
        {
             distance[i-1][j]=dist+a[i-1][j];
             pq.push({distance[i-1][j],{i-1,j}});
        }




    }

    return distance[n-1][n-1];




}
