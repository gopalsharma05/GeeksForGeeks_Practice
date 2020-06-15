/*

    problem-> swap_even_odd_bits(easy).cpp

    Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on right side(even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains single line.

Output:
For each testcase in new line, print the converted number.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
23
2

Output:
43
1

Explanation:
Testcase 1: BInary representation of the given number; 00010111 after swapping 00101011

        */

// one line solution is ((1010101010101010&n)>>1) | ((0101010101010101 & n)<<1)

// just brute forces using keep track of bits
#include <bits/stdc++.h>
using namespace std;

int main() {
	 int t;
	 cin>>t;
	 while(t--)
	 {
	     int n;
	     cin>>n;
	     int ans=0,s=0;
            while(n!=0)
            {
                int g=(1&n);
                int r=(1&n>>1);
                ans+=r*pow(2,s);
                s++;
                ans+=g*pow(2,s);
                s++;

                n=n>>2;

            }

            cout<<ans<<"\n";

	 }
}
