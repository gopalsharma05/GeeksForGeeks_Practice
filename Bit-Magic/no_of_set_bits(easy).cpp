/*

    problem-> no_of_set_bits(easy).cpp

    You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is N.

Output:
For each testcase, in a new line, print the total count of all bits.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103

Example:
Input:
2
4
17
Output:
5
35

Explanation:
Testcase1:
An easy way to look at it is to consider the number, n = 4:
0 0 0 = 0
0 0 1 = 1
0 1 0 = 1
0 1 1 = 2
1 0 0 = 1
Therefore , the total number of bits is 5.


*/


// one solution is use inbuilt function  ...  __builtin_popcount()
/*

for(int i=1;i<=n;i++)
ans+=__builtin_popcount(i);

cout<<ans<<"\n";

*/

// other solution is taking in consideration that .....   n&(n-1)  will make rightmost set bit to 0...using this we can solve this

#include <bits/stdc++.h>
using namespace std;

int main() {

 int t;
 cin>>t;
 while(t--)
 {
     int n ;
    cin>>n;
    int cnt=0;
    // for(int i=1;i<=n;i++)
    //  cnt+=__builtin_popcount(i);  // using inbuilt function
     int ans=0;
     for(int i=1;i<=n;i++)
     {
         int g=i;
         cnt=0;
         while(g!=0)           // barkingham algorithm
         {
             g=g&(g-1);      // it make rightmost set bit of g to 0.....at last g will be 0... i.e no set bit
             cnt++;
         }
         ans+=cnt;
     }

     cout<<ans<<"\n";
 }


}


