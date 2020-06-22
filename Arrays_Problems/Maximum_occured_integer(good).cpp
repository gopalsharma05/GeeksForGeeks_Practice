/*

        problem-> Maximum_occured_integer(good).cpp


        Given two arrays L[] and R[] consisting of N ranges of the form L and R, L[i] consists of starting point of range and R[i] consists of corresponding end point of the range. The task is to find the maximum occurred integer in all the ranges. If more than one such integer exits, print the smallest one.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the ranges. The next two lines contain the n space separated elements of L and R respectively.

Output:
Print the smallest maximum occured integer in all the ranges.

Constraints:
1 <= T <= 105
1 <= n <= 105
0 <= L[i], R[i] <= 105

Example:
Input:
2
4
1 4 3 1
15 8 5 4
5
1 5 9 13 21
15 8 12 20 30

Output:
4
5

Explanation:
Testcase 1: 4 is the most occuring element after considering all the ranges. So, output is 4.




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
	    lli n;
	    cin>>n;
	    lli L[n],R[n],a[100001]={0};


	    for(lli i=0;i<n;i++)
	    {
	        cin>>L[i];
	        a[L[i]]++;

	    }

	   for(lli i=0;i<n;i++)
	   {
	        cin>>R[i];
	        a[R[i]+1]-=1;
	   }

	  lli maxm=a[0],ans=0;
	  for(lli i=1;i<100001;i++)
	  {

	      a[i]+=a[i-1];
	      if(maxm<a[i])
	      {
	          maxm=a[i];
	          ans=i;

	      }

	  }

	  cout<<ans<<"\n";



	}
	return 0;
}
