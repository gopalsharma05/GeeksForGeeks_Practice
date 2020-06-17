/*

    problem -> moduler_multiplicative_inverse(basic).cpp


    Given two integers ‘a’ and ‘m’. The task is to find modular multiplicative inverse of ‘a’ under modulo ‘m’.
Note: Print the smallest modular multiplicative inverse.

Input:
First line consists of T test cases. Only line of every test case consists of 2 integers 'a' and 'm'.

Output:
For each testcase, in a new line, print the modular multiplicative inverse if exists else print -1.

Constraints:
1 <= T <= 100
1 <= m <= 100
1 <= a <= m

Example:
Input:
2
3 11
10 17

Output:
4
12

Explanation:
Testcase1:
Input:  a = 3, m = 11
Output: 4
Since (4*3) mod 11 = 1, 4 is modulo inverse of 3
One might think, 15 also as a valid output as "(15*3) mod 11"
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not valid.

        */


  #include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)

    {

        int a,m;
        cin>>a>>m;
        int g=0;
        int i;
        for( i=0;i<m;i++)
        {
            if((a*i)%m==1)
            {
                g=10;
                break;
            }
        }

        if(g==10)
        cout<<i<<"\n";
        else
        cout<<"-1\n";



    }


}
