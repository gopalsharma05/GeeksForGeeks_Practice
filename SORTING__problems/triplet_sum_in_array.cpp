/*

This is same as triplet with zero sum ......above in this code list

Given an array A[] of N numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains n and x. Next line contains array elements.

Output:
Print 1 if there exist three elements in A whose sum is exactly x, else 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1

Explanation:
Testcase 1: There is one triplet with sum 13 in the array. Triplet elements are 1, 4, 8, whose sum is 13.

*/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int


bool twopinter(lli a[],lli n,lli i,lli k)
{
    lli l=i+1,r=n-1;
    while(l<r)              // use 2 pointer approach with sorted array
    {
        if(a[i]+a[r]+a[l]==k)           // if sum is less than k then increament l
        return true;
        else if(a[i]+a[r]+a[l]<k)       // if sum is more than k then decreament r
        l++;
        else
        r--;
    }

    return false;
}

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
    {


        lli n,k;
        cin>>n>>k;
        lli a[n];
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];

        }

        sort(a,a+n);
        bool flag=false;

        for(lli i=0;i<n;i++)
        {
            if(twopinter(a,n,i,k))
            {
                flag=true;
                break;
            }
        }

        if(flag)
        cout<<"1\n";
        else
        cout<<"0\n";
    }
    	return 0;
}
