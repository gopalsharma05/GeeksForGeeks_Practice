/*

    problem-> first_positive_missing_number(good).cpp

    You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case
consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.




                */


#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;
int main()
    {
        lli t;
        cin>>t;
        while(t--)
        {
            lli n;
            cin>>n;
            lli a[n+3];
               for(lli i=1;i<=n;i++)
               {
                   cin>>a[i];
                   if(a[i]<0 || a[i]>n)
                   {
                       a[i]=n+1;
                   }

               }

               for(int i=1;i<=n;i++)
               {
                   if(a[abs(a[i])]>0)
                   a[abs(a[i])]=-a[abs(a[i])];

               }

               int ans=n+1;
               for(int i=1;i<=n;i++)
               {
                   if(a[i]>0)
                   {
                       ans=i;
                       break;
                   }
               }


               cout<<ans<<"\n";


        }

        return 0;
    }
