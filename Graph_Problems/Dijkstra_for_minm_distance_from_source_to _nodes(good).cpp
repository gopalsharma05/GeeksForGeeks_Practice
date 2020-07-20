/*
    problem-> Dijkstra_for_minm_distance_from_source_to _nodes(good).cpp


    Note:
        You must assume that graph[i][j] = 0 means that the path from i to j does not exist.


    Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix and in the next line are V*V space-separated values, which denote the weight of an edge of the matrix (gr[i][j] represents the weight of an edge from ith node to jth node). The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test, case output will be V space-separated integers where the ith integer denotes the shortest distance of the ith vertex from source vertex.

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra() which takes the adjacency matrix of the Graph g, the source vertex src and the number of vertices V as inputs and returns a list containing the minimum distance of all the vertices from the source vertex.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 20
1 <= V <= 100
0 <= graph[i][j] <= 1000
0 <= s < V

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.

Note:
You must assume that graph[i][j] = 0 means that the path from i to j does not exist.



            */

vector <int> dijkstra(vector<vector<int>> a, int src, int v)
{

    vector<int> distance(v);
    for(int i=0;i<v;i++)
    distance[i]=INT_MAX;

    distance[src]=0;

    priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    pq.push({0,src});    // distance as first element as we want to extract minm
                                // distance

    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();

        int dist=p.first;
        int ver=p.second;
        for(int i=0;i<v;i++)
        {
            if(distance[i]>dist+a[ver][i] && a[ver][i]!=0)
            {
                distance[i]=dist+a[ver][i];
                pq.push({distance[i],i});
            }
        }

    }

   return distance;



}
