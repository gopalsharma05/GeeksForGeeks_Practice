/*
    problem-> Black_and_White_knights(good).cpp

    How many ways are there to place a black and a white knight on an N * M chessboard such that they do not attack each other? The knights have to be placed on different squares. A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped). The knights attack each other if one can reach the other in one move.

Input:
The first line contains the number of test cases T. Each of the next T lines contains two integers N and M which is size of matrix.

Output:
For each testcase, print the required answer, i.e, number of possible ways to place knights.

Constraints:
1 <= T <= 100
1 <= N, M <= 105

Example:
Input:
3
2 2
2 3
4 5

Output:
12
26
312

Explanation:
Testcase 1: We can place a black and a white knight  in 12 possible ways such that none of them attracts each other.

        */



approach --> simple using brute froce if constraints are low


//if contraints are high then this can be done in O(1) also
/*
    credit --  gfg user 'folkstyler'


      res = n*m;                // total ways to choose first knight
        res *= (n*m-1);         // now total ways to choose both knights

        answer will be=res-(4*(2*n*m-3*n-3*m+4))

            refer this image for better understanding

        //https://uploads.disquscdn.com/images/6a83e040cdd775f4372395c87a046ad5f55c6ad2f0cd5dbfe8d9b7d2b47e3888.png

        After considering above image, you can determine that there are:

        (n-4)*(m-4) first knight positions which forbid 8 second knight positions a piece
        2*(n-4)+2*(m-4) first knight positions which forbid 6 second knight positions a piece
        2*(n-4)+2*(m-4)+4 first knight positions which forbid 4 second knight positions a piece
        8 first knight positions which forbid 3 second knight positions a piece
        4 first knight positions which forbid 2 second knight positions a piece


        NOTE-->please handel some basic cases for m<4 && n<4   if needed

    */



// as constraints are low then see below code which is brute force


#include <bits/stdc++.h>
using namespace std;

bool issafe(int i,int j,int n,int m)
{
    if(i>=n  ||  j>=m || i<0  || j<0 )
    return false;

    return true;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;

	    int total=n*m,ans=0;

	    for(int i=0;i<n;i++)
	    {

	        for(int j=0;j<m;j++)
	        {
	            int cnt=0;
	            if(cnt==0)
	            {
    	            if(issafe(i+2,j+1,n,m))
    	            cnt++;
    	            if(issafe(i+2,j-1,n,m))
    	            cnt++;
    	            if(issafe(i-2,j+1,n,m))
    	            cnt++;
    	            if(issafe(i-2,j-1,n,m))
    	            cnt++;
    	            if(issafe(i+1,j+2,n,m))
    	            cnt++;
    	            if(issafe(i+1,j-2,n,m))
    	            cnt++;
    	            if(issafe(i-1,j+2,n,m))
    	            cnt++;
    	            if(issafe(i-1,j-2,n,m))
    	            cnt++;
	            }

	           ans+=total-cnt-1;


	        }





	    }

	    cout<<ans<<"\n";

	}

	return 0;
}
