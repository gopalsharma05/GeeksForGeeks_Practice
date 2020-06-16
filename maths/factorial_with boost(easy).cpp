/*

boost library help us to store large interger... but if constraints are very large then always preffer array

    problem-factorial_with boost(easy).cpp

       Given a positive integer N. The task is to calculate the factorial of N.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T testcases follow. In each test cases, it contains an integer 'N'.

Output:
For each testcase in a new line, print the factorial of N.

Constraints:
1 <= T <= 19
0 <= N <= 18

Example:
Input:
2
1
4

Output:
1
24

        */



 #include<bits/stdc++.h>
 #include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
 using namespace std;
 #define lli long long int
 #define pb push_back

 int128_t fact(int n)
 {

     int128_t ans=1;
    for(int i=2;i<=n;i++)
    ans=ans*i;

    return ans;


 }


 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
        int n;
     cin>>n;
     cout<<fact(n)<<"\n";
     }
 }
