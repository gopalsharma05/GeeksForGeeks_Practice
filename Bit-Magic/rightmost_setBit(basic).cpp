/*

    // problem->rightmost_setBit(basic).cpp

    Given an integer an N. The task is to print the position of first set bit found from right side in the binary representation of the number.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. The only line of the each test case contains an integer N.

Output:
For each test case print in a single line an integer denoting the position of the first set bit found form right side of the binary representation of the number. If there is no set bit print "0".

Constraints:
1 <= T <= 200
0 <= N <= 106

Example:
Input:
2
18
12

Output:
2
3

Explanation:
Testcase 1: Binary representation of the 18 is 010010, the first set bit from the right side is at position 2.

        */


 // in one line ........   log2(n&-n)+1     will be the answer

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=0;i<32;i++)
        {
            int g=1<<i;
            if(g&n)
            break;


        }

        if(n!=0)
       cout<<i+1<<"\n";
       else cout<<"0\n";

    }
}
