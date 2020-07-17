/*

    problem->  Find_whether_path_exist(good).cpp

    Given a square matrix filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left. (Check Your Task for more details).

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space-separated values of the matrix (M).

Output:
Complete isExist function and return 1 if the path exists from source to destination else return 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function is_possible() which takes a square matrix (M) and its size (N) as inputs and returns true if there's path possible from the source to destination. Else, it returns false.
You have to start from the Source, traverse through the blank cells and reach the Destination. You can move Up, Down, Right and Left. The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above-given input is:
0 3 2
3 0 0
1 0 0
From the matrix, we can see that there does not exist any path to reach destination 2 from source 1.


        */



bool istrue(int i,int j,vector<vector<int> > &m,int n,vector<vector<bool > > &vis)
{
    if(i<0 || i>=n || j<0 || j>=n || vis[i][j]==true || m[i][j]==0)
    return false;

     if(m[i][j]==2)
    return true;



    vis[i][j]=true;

    if(istrue(i,j+1,m,n,vis))
    return true;
    if(istrue(i,j-1,m,n,vis))
    return true;
    if(istrue(i+1,j,m,n,vis))
    return true;
    if(istrue(i-1,j,m,n,vis))
    return true;

    return false;
}


bool is_possible(vector <vector <int>> &m, int n) {


    vector<vector<bool > > vis(n,vector<bool>(n,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]==1)
            {
                if(istrue(i,j,m,n,vis))
                return true;
                else
                return false;
            }
        }
    }


}
