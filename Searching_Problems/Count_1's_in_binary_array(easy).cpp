/*
    problem->Count_1's_in_binary_array(easy).cpp

    required_timeComplexity--> O(logn);

    Given a binary sorted non-increasing array arr of size N. You need to print the count of 1's in the binary array.

Input:
The input line contains T, denotes the number of testcases. Each input contains two lines. The first line contains N(size of binary array). The second
line contains N elements of binary array separated by space.

Output:
For each testcase in new line, print the count 1's in binary array.

Constraint:
1 <= T <= 100
1 <= N <= 5*106
0 <= arr[i] <= 1

Example:
Input:
2
8
1 1 1 1 1 0 0 0
7
1 1 1 1 1 1 1

Output:
5
7

Explanation:
Testcase 1: Number of 1's in given binary array : 1 1 1 1 1 0 0 0 is 5.


            */



#include <bits/stdc++.h>
using namespace std;
int a[5000000];
int count1(int n)
{

    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(a[mid]==1 && (a[mid+1]==0 || mid==n-1))
        return mid+1;
        else if(a[mid]==0)
        r=mid-1;
        else
        l=mid+1;
    }

    return 0;



}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i = 0; i < n; i++)
         cin>>a[i];
        cout <<count1(n)<<endl;
    }
    return 0;
}
