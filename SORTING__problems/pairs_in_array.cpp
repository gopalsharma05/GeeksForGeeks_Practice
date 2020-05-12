/*
Given two arrays X and Y of positive integers, find number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test consists of three lines. The first line of each test case consists of two space separated M and N denoting size of arrays X and Y respectively. The second line of each test case contains M space separated integers denoting the elements of array X. The third line of each test case contains N space separated integers denoting elements of array Y.
Output:
Corresponding to each test case, print in a new line, the number of pairs such that xy > yx.

Constraints:
1 ≤ T ≤ 100
1 ≤ M, N ≤ 105
1 ≤ X[i], Y[i] ≤ 103

Example:
Input
1
3 2
2 1 6
1 5

Output
3

Explanation:
Testcase 1: The pairs which follow xy > yx are as such: 21 > 12,  25 > 52 and 61 > 16
*/



//SOLUTION
/*
The trick to this question is if y > x, then then x^y > y^x with some exceptions.

Simply sort the array Y[], and for every element x in X[], find the index idx of smallest number just greater than x in Y[].
All the elements after, this index idx satisfy the above relation. So add (n - idx) to the ans.

But as we mentioned there are some exceptions


Following are the exceptions :

if x = 0, then count for this is 0.
 if x = 1, then count is total no of 0s in Y[] only.
if x = 2, for y = 3, y = 4, the above property does not hold, and the count should be decreased
if x = 3, for x = 2, the count need to be inreased


if y==1 then consider all element all the element of the array X which are greater than 1

This is the complete solution.
The overall time complexity is O(nlong + mlogn)


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
	    lli n,m;
	    cin>>n>>m;
	    vector<lli> a(n),b(m);
	    lli m1[6]={0},m2[6]={0};

	     lli cnt=0,ind1=0;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
    	       if(a[i]<6)
    	       m1[a[i]]++;

	        if(a[i]>1)
	        ind1++;

	    }

	    for(lli i=0;i<m;i++)
	    {
	        cin>>b[i];
	         if(b[i]<6)
	            m2[b[i]]++;


	    }


	    sort(b.begin(),b.end());





	    for(lli i=0;i<n;i++)
	    {   if(a[i]!=1)
	        {
	        auto ub=upper_bound(b.begin(),b.end(),a[i]);

	        cnt+= m-(ub-b.begin());
	        }

	    }





	    cnt+=m1[1]*m2[0];

	    cnt+=m1[3]*m2[2];

	    cnt-=(m1[2]*m2[3]+m1[2]*m2[4]);
	   ;

	    cnt+= m2[1]*ind1;



	    cout<<cnt<<"\n";
	}

	return 0;
}
