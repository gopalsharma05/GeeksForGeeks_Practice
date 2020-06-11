/*

    problem->spiral_view_matrix(easy).cpp

        Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Constraints:
1 <= T <= 100
2 <= M,N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7


    */


 #include <bits/stdc++.h>
using namespace std;

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;

	    int arr[n][m];
	    int cnt=0;

	    for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
	    cin>>arr[i][j];

	    int a=0,b=m-1,c=n-1,d=n-1,e=0;
	    while(cnt!=n*m)
	    {
    	    for(int i=e;i<=b;i++)
    	    {
    	        cout<<arr[a][i]<<" ";
    	        cnt++;
    	    }
    	    a++;

    	    if(cnt==n*m)
    	    break;

    	    for(int i=a;i<=c;i++)
    	    {
    	        cout<<arr[i][b]<<" ";
    	        cnt++;
    	    }
    	    b--;

    	     if(cnt==n*m)
    	    break;


    	    for(int i=b;i>=e;i--)
    	    {
    	        cout<<arr[c][i]<<" ";
    	        cnt++;
    	    }
    	    c--;

    	     if(cnt==n*m)
    	    break;

    	    for(int i=c;i>=a;i--)
    	    {
    	        cout<<arr[i][e]<<" ";
    	        cnt++;
    	    }
    	    e++;
	    }


	    cout<<endl;

	}

	return 0;
}
