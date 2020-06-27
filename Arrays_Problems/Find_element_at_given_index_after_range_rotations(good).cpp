/*

    problem -> Find_element_at_given_index_after_range_rotations(good).cpp

Given an array arr[] of N elements. Perform K right circular rotations on given ranges [L..R]. After performing these rotations, we need to find element at a given index X.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains three integers N, X  and K. Second line contains N space separated array elements and next line contains K ranges [L, R] (space seperated) on which we have to rotate the array in right circular manner.

Output:
For each test case, print the array[X] (0-based indexing)element after K rotations in new line.

Constraints:
1 <= T <= 500
2 <= N <= 105
1 <= arr[] <= 105
1 <= K <= 105
X < N
0 <= L <= R

Example:
Input:
2
5 1 2
1 2 3 4 5
0 2 0 3
3 2 1
1 2 3
0 1

Output:
3
3

Explanation:
Testcase 1: Rotating the elements in range 0-2 and 0-3, we have array as 4 3 1 2 5. Element at first position is 3



        */




        /*
                    APPROACH-->  Store all the rotations.
                    Traverse the stored rotations from last to first
                    If the index lies between the Rotation range of L R, then decreament it.
                    Else if, its value is equal to L then make it equal to R.
                    This index value is the answer.

                    */



#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n,x,k;
	    cin>>n>>x>>k;
	    vector<lli> v(n);
	    for(lli i=0;i<n;i++)
	    cin>>v[i];

	    lli ranges[k][2];
	    for(lli i=0;i<k;i++)
	    {
	        lli a,b;
	        cin>>a>>b;
	        ranges[i][0]=a;
	        ranges[i][1]=b;

	    }

	    for(lli i=k-1;i>=0;i--)    // starting from last end
	    {
	        lli  r=ranges[i][1];
	        lli l=ranges[i][0];
	        if(x<=r &&  x>=l)
	        {
	            if(x==l)
	            x=r;
	            else
	            x--;
	        }
	    }


	    cout<<v[x]<<" ";
	    cout<<endl;



	}
	return 0;


}
