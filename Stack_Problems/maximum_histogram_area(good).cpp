/*

    problem-> maximum_histogram_area(good).cpp



    Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
    For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an
integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The
elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 104

Example:
Input:
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9



                    */


                    #include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    int a[n];

	    for(int i=0;i<n;i++)
	    cin>>a[i];


	    stack<int> st;
	    int nsr[n];
	    for(int i=n-1;i>=0;i--)
	    {
	        while(!st.empty()&&a[i]<=a[st.top()])
	        {
	            st.pop();
	        }

	        if(st.empty())
	        nsr[i]=-1;
	        else
	        nsr[i]=st.top();

	        st.push(i);
	    }

	   // for(int i=0;i<n;i++)
	   // cout<<nsr[i]<<" ";
	   // cout<<endl;

	     for(int i=0;i<n;i++) // so that we can find the the range
	   if(nsr[i]==-1)
	   nsr[i]=n;

	   while(!st.empty())
	   {
	       st.pop();
	   }

	   int nsl[n];
	   for(int i=0;i<n;i++)
	   {
	       while(!st.empty() && a[i]<=a[st.top()])
	       st.pop();

	       if(st.empty())
	       nsl[i]=-1;
	       else
	       nsl[i]=st.top();

	       st.push(i);
	   }

	   // for(int i=0;i<n;i++)
	   // cout<<nsl[i]<<" ";
	   // cout<<endl;
	   int ans=0;
	 for(int i=0;i<n;i++)
	 {
	     ans=max(ans,a[i]*(nsr[i]-nsl[i]-1));
	 }

	 cout<<ans<<"\n";



	}

	return 0;
}
