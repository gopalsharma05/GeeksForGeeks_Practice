/*

    problem-> factorial(basic).cpp

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


//the below solution is using vector for storing the factorial     ....   you can also use boost library of c++ for solving it normally without vector
                                                                             // see problem (factorial_with boost(easy).cpp ) in same list for that

#include<bits/stdc++.h>
 using namespace std;
 #define lli long long int
 #define pb push_back

 void facto(int n)
 {


     vector<int> v;

     v.push_back(1);
     int carry=0;

     for(int i=2;i<=n;i++)
    {
        int carry=0;
        for(int j=0;j<v.size();j++)
        {

            int r= (v[j]*i) + carry;
            v[j]=r%10;
            carry=r/10;

        }

        while(carry!=0)
        {
            v.pb(carry%10);
            carry/=10;
        }
    }

    for(int i=v.size()-1;i>=0;i--)
    cout<<v[i];

    cout<<endl;




 }


 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
        int n;
     cin>>n;
     facto(n);
     }
 }
