/*
    Given an array arr[] of N integers which is closer sorted (defined below) and an element x. The task is to find index of the element x if it is present. If not present, then print -1.

Closer Sorted: First array is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e, may be to the arr[i+1] or arr[i-1].

Expected Time Complexity: O(Log N)

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array. Next line contains the array elements. Last line contains the element to be searched.

Output:
Output the index at which the element is present (0-based), if present, else print "-1".

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5
3 2 10 4 40
2
4
2 1 4 3
5

Output:
1
-1

Explanation:
Testcase 1: 2 is present at index 1 (0-based indexing) in the given array.
    */

#include<bits/stdc++.h>
 using namespace std;
 #define lli long long int

 int useBS(int a[],int n,int x)
 {
        int l=0,r=n-1;
        while(l<=r)
        {

            int mid=l+(r-l)/2;
            if(a[mid]==x)
            return mid;

            else if(a[mid+1]==x && mid+1<n)      // checking that eleemtnt is present ar mid+1
            {
                return mid+1;
            }

            else if(a[mid-1]==x && mid-1>=0)  //// checking that eleemtnt is present ar mid-1
            {
                return mid-1;
            }

            else if(a[mid]>x)          // if element is greater than the x, r=mid-2,,-2 because
                                        // we already checked at its adjacent sides
            {
                r=mid-2;
            }
            else
            l=mid+2;


        }

        return -1;
 }

 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         int a[n];
         for(lli i=0;i<n;i++)
         cin>>a[i];

        int x;
        cin>>x;


        int ans=useBS(a,n,x);    // callling binary search function
        cout<<ans<<"\n";



     }
 }
