/*

    problem-> sparse_or_not(easy).cpp

    Given a number N, check whether it is sparse or not. A number is said to be a sparse number if in the binary representation of the number no two or more consecutive bits are set.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is number 'N'.

Output:
Print '1' if the number is sparse and '0' if the number is not sparse.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
3

Output:
1
0

Explanation:
Testcase 1: Binary Representation of 2 is 10, which is not having consecutive set bits. So, it is sparse number.
Testcase 2: Binary Representation of 3 is 11, which is having consecutive set bits in it. So, it is not a sparse number

        */


#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--)
    {
         int n;
         cin>>n;
         int cnt=0;
         bool flag=false;
         while(n!=0)
         {

             if(1&(n))
             {
                 cnt++;
                 if(cnt>=2)
                 {
                     flag=true;
                     break;
                 }
             }
             else
             cnt=0;

             n=n>>1;


         }

         if(flag)
         cout<<"0\n";
         else
         cout<<"1\n";
    }
}
