/*
    problem- >Smallest_Positive_missing_number(good).cpp


    You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

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


// Approach > as we want smallese positive , so dont care about negative and 0, so put all positive at starting using swapping in O(n), and have count of
// them ,  then use the indeces of positive element (from i=1 to positive_count) for cheking which positive value are there in my array

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

               }

               lli r=n,i=1;

              while(r>i)
              {
                   if(a[i]<=0)
                   {
                       swap(a[i],a[r]);
                       r--;
                   }
                   else
                   i++;

              }


             while(a[r]<=0)     // if by mistake some -ve or 0 values are there in my code between 1 to r  ,, then removing those values.
             r--;

              for(int i=1;i<=r;i++)            // marking the values as -ve which are >0 && <=r(i.e total positive values in array)
              {
                 if(abs(a[i])<=r && a[abs(a[i])]>0)
                 {
                     a[abs(a[i])]=-a[abs(a[i])];

                 }
              }
              bool flag=false;

              for(int i=1;i<=r;i++)
              {
                  if(a[i]>0)
                  {
                      cout<<i<<"\n";
                      flag=true;
                      break;
                  }
              }

              if(flag==false)    // if we have all value present from 1 to r then answer will be r+1
              cout<<r+1<<"\n";





        }

        return 0;
    }
