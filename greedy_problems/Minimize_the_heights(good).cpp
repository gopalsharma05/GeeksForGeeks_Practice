/*

problem-Minimize_the_heights(good).cpp

Given an array A[ ] denoting heights of N towers and a positive integer K, modify the heights of each tower either by increasing or decreasing them by K only once and then find out the minimum difference of the heights of shortest and longest towers.

Example

Input  : A[] = {1, 15, 10}, k = 6
Output : 5
Explanation : We change 1 to 7, 15 to
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains a positive integer K. The second line of each test case contains a positive integer N, denoting number of towers. The third line of the test cases contains N integers denoting the heights of N towers.

Output
For each test case in new line print out the minimum difference of heights possible.

Constraints
1 <= T <= 100
0 <   K <= 30
0 <   N <= 30
0 <= A[i] <= 500


Examples
Input
3
2
4
1 5 8 10
3
5
3 9 12 16 20
4
6
100 150 200 250 300 400

Output
5
11
292

Explanation:
Test Case 1: arr[] = {1, 5, 8, 10}. k = 2
The array can be modified as: {3, 3, 6, 8}. The difference between the largest and the smallest is 8-3 = 5. We can't have a difference less than this.
Test Case 2: arr[] = {3 9 12 16 20}. k = 3
The array can be modified as: {6 12 9 13 17}. The difference between the largest and the smallest is 17-6 = 11.

*/


//  APPROACH -> First sort the array ,initially store ans as a[n-1]-a[0], as we want minimum after changing the element so add k to a[0] and subtract k
// form a[n-1], i can either increase or decrease a[i] by k...but we should keep in mind that if i add the k in a[i] it can go beyond the a[n-1], if
//i decrease k from a[i] it can go below a[0]...now we should check which one is giving the minm difference out of both case ...suppose latter one
// giving the less difference , it means we should decrease k from a[i], else we should add k to a[i];


#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main() {
	//code

	int t;
	cin>>t;

	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    int a[n];
	    for(lli i=0;i<n;i++)
	    cin>>a[i];


	    sort(a,a+n);

	    int ans=a[n-1]-a[0];

	    a[0]+=k;
	    a[n-1]-=k;
	    for(int i=1;i<n-1;i++)
	    {
	        int ad=a[i]+k;
	        int sb=a[i]-k;
	        if(ad>a[n-1]  || sb<a[0])
	        {
	            if(ad-a[0]<=a[n-1]-sb)
	            {
	                a[i]+=k;
	            }
	            else
	            a[i]-=k;
	        }


	    }

	    cout<<min(ans,abs(*max_element(a,a+n)-*min_element(a,a+n)))<<"\n";


	}

	return 0;
}
