/*

    problem-> 3Divisors(good).cpp

    Given a value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.

Input:
The first line contains integer T, denoting number of test cases. Then T test cases follow. The only line of each test case contains an integer N.

Output :
For each testcase, in a new line, print the answer of each test case.

Constraints :
1 <= T <= 103
1 <= N <= 1012

Example:
Input :
3
6
10
30
Output :
1
2
3

Explanation:
Testcase 1: There is only one number 4 which has exactly three divisors 1, 2 and 4.

        */

// approach --->   the number whose square root is prime will be count to our answer

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define mod 1000000007


bool isprime(lli n)
{
    if(n<2)
    return false;

    if(n==2 ||  n==3)
    return true;

    if(n%2==0 || n%3==0)
    return false;

    for(lli i=5;i<=sqrt(n);i+=6)
    if(n%i==0  ||  n%(i+2)==0)
    return false;

    return true;
}

 int main()
 {
     lli t;
     cin>>t;

      int s[1000001]={0};

    for(int i=2;i*i<=1000000;i++)    // sieve of erathoneses  for finding the prime up to 1000000
    {
        for(int p=i*i;p<=1000000;p+=i)
        {
            if(s[p]==0)
            s[p]=1;
        }
    }

     while(t--)
     {

        lli n;
        cin>>n;
        lli cnt=0;



        for(int i=2;i<=int(sqrt(n));i++)
        {
            if(s[i]==0 && i*i<=n)
            {
                cnt++;

            }
        }

        cout<<cnt<<"\n";


     }
 }
