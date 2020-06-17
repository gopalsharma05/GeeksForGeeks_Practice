/*

   problem-> Pairs_of_prime_number(easy).cpp

   Print all pairs (sets) of prime numbers (p,q) such that p*q <= n, where n is given number.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.
The first line of each test case is N.

Output:
For each testcase, in a new line, print the all pairs of prime numbers in increasing order.

Constraints:
1 ≤ T ≤ 50
4 ≤ N ≤ 400

Example:
Input:
2
4
8
Output:
2 2
2 2 2 3 3 2

Explanation:
Testcase 1: Pair (2, 2) which has both prime numbers as well as satisfying the condition 2*2 <= 4.

        */




 #include<bits/stdc++.h>
#define lli long long int
using namespace std;
#define pb push_back

// dynamo 123




int main()
{

    lli t;cin>>t;

    int s[412]={0};

    for(int i=2;i*i<=412;i++)    // sieve of erathoneses  for finding the prime up to n
    {
        for(int p=i*i;p<=412;p+=i)
        {
            if(s[p]==0)
            s[p]=1;
        }
    }

    while(t--)
    {
        lli n;
        cin>>n;





        vector<lli> v;

        for(lli i=2;i<=n;i++)
        if(s[i]==0)
        v.pb(i);

        for(lli i=0;i<v.size();i++)
        {
        	for(int j=0;j<v.size();j++)
        	{
        		if(v[i]*v[j]<=n)
        		cout<<v[i]<<" "<<v[j]<<" ";
        	}
        }

        cout<<endl;


    }

    return 0;
}
