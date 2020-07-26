/*

        problem-> step_by_knight(good).cpp

        Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the
        target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting
the size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target.

Output:
Print the minimum steps the Knight will take to reach the target position.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight
(knightPos), the target position of Knight (targetPos) and the size of the chess board (N) as inputs and returns the minimum number of steps required by
the knight to reach from its current position to the given target position.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= knight_pos(X, Y), targer_pos(X, Y) <= N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9



            */


int minStepToReachTarget(int start[], int end[], int n) {


    queue<pair<int,int> > q;
    q.push({start[0],start[1]});
    int r=end[0],c=end[1],cnt=0;

    int xwala[]={1,1,-1,-1,2,2,-2,-2};
    int ywala[]={2,-2,2,-2,1,-1,1,-1};

   int visited[n+1][n+1]={0};
    int size=q.size();

    while(!q.empty())
    {
        pair<int,int> p=q.front();
        int i=p.first;
        int j=p.second;
        q.pop();


        if(i==r  && j==c)
        {
            return cnt;

        }

        for(int k=0;k<8;k++)
        {
            int x=i+xwala[k];
            int y=j+ywala[k];

            if(x<=n && y<=n && x>=0 && y>=0 && visited[x][y]==0)
            {
                visited[x][y]=1;
                q.push({x,y});


            }
        }

        size--;
        if(size==0)
        {
            cnt++;
            size=q.size();
        }







    }



}
