/*
    problem->  Check_if_array_is_sorted_and_rotated_clockwise(good).cpp

    Given an array arr[] of N distinct integers, check if this array is Sorted and Rotated clockwise.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Input:
The first line of input contains number of testcases T. Each testcase contains 2 lines, the first line contains N, the number of elements in array, and second line contains N space separated elements of array.

Output:
Print "Yes" if the given array is sorted and rotated, else Print "No", without Inverted commas.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
2
4
3 4 1 2
3
1 3 2
Output:
Yes
Yes

Explanation:
Testcase 1: The array is sorted (1, 2, 3, 4) and rotated twice (3, 4, 1, 2).
Testcase 2: The array is sorted (3, 2, 1) and rotated once (1, 3, 2).


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

        lli min_ind=0,max_ind=0;
        for(int i=0;i<n;i++)
        {
            if(a[min_ind]>a[i])
            min_ind=i;

            if(a[max_ind]<a[i])
            max_ind=i;
        }


        if(abs(min_ind-max_ind)!=1)
        {
            cout<<"No\n";
        }
        else if(min_ind>max_ind)
        {
            bool flag=true;
            lli d=min_ind;
             for(lli i=0;i<n-1;i++)
             {
                 if(a[(i+d)%n]>a[(i+d+1)%n])
                 {
                     flag=false;
                     break;
                 }
             }

            if(flag==false )
            cout<<"No\n";
            else
            cout<<"Yes\n";


        }
        else
        {
             bool flag=true;
            lli d=max_ind;
             for(lli i=0;i<n-1;i++)
             {
                 if(a[(i+d)%n]<a[(i+d+1)%n])
                 {
                     flag=false;
                     break;
                 }
             }



            if(flag==false)
            cout<<"No\n";
            else
            cout<<"Yes\n";
        }
    }
	return 0;
}
