/*

    Problem  -> Maximum_Product_of_Increasing_Subsequence_of_Size_3(good).cpp

    Given a sequence of non-negative integers, find the subsequence of length 3 having maximum product, with the elements of the subsequence being in increasing order.

Input: The first line of input contains number of testcases T. Each testcase contains 2 lines, the first line contains N, the number of elements in array, and second line contains space separated elements of array.

Output: Print the subsequence of size 3 having maximum product, numbers of subsequence being in increasing order. If no such sequence exists, print "Not Present".

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 105

Example:
Input:
2
8
6 7 8 1 2 3 9 10
4
3 4 2 1
Ouput:
8 9 10
Not present

Explanation:
Testcase 1: 3 increasing elements of the given arrays are 8, 9 and 10 which forms the subsequence of size 3 with maximum product.



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
	    lli a[n];
	    for(lli i=0;i<n;i++)
	    cin>>a[i];

	    lli largest_smaller[n];
	    set<lli> s;
	    for(lli  i=0;i<n;i++)
	    {
	        s.insert(a[i]);

	        auto it=s.find(a[i]);
	        if(*s.begin()==a[i])
	        {

	            largest_smaller[i]=-1;

	        }
	       else
	       {

	           it--;
	           largest_smaller[i]=*it;
	       }



	    }



	    lli maxm=a[n-1];
	    lli ans[3]={0};
	    lli mul_max=INT_MIN;
	    for(lli i=n-2;i>0;i--)
	    {
	        if(a[i]>=maxm)
	        {
	            maxm=a[i];

	        }
	        else if(largest_smaller[i]!=-1)
	        {
	            if(mul_max<largest_smaller[i]*a[i]*maxm)
	            {
	            mul_max=largest_smaller[i]*a[i]*maxm;
	            ans[0]=largest_smaller[i];
	            ans[1]=a[i];
	            ans[2]=maxm;
	            }
	        }
	    }

	    if(ans[0]==0)
        cout<<"Not present\n";
        else
        {
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
        }








	}
	return 0;
}
