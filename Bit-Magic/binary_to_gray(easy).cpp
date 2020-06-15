/*

    problem-> binary_to_gray(easy).cpp

    You are given a decimal number n. You need to find the gray code of the number n and convert it into decimal.
To see how it's done, refer here.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is an integer n denoting the number

Output:
For each test case, the output is gray code equivalent of n.

Constraints:
1 <= T <= 100
0 <= n <= 108

Example:
Input
2
7
10
Output
4
15

Explanation:
Testcase1: 7 is represented as 111 in binary form. The gray code of 111 is 100, in the binary form whose decimal equivalent is 4.

Testcase2: 10 is represented as 1010 in binary form. The gray code of 1010 is 1111, in the binary form whose decimal equivalent is 15

        */


// how to convert binary to gray code can be found here---->  https://www.tutorialspoint.com/conversion-of-binary-to-gray-code


 #include <bits/stdc++.h>
using namespace std;

int main() {
	 int t;
	 cin>>t;
	 while(t--)
	 {
	     int n;
	     cin>>n;
	      string s="";
	     if(n==0)
	     cout<<0<<"\n";
	     else
	     {
	      for(int i=0;i<int(log2(n)+1);i++)
	      {
	          int g=1<<i;
	          if(g&n)
	          s+='1';
	          else
	          s+='0';
	      }

	      int g=0,sum=0;

	      for(int i=0;i<s.length()-1;i++)
	      {
	          sum+=((s[i]-48)^(s[i+1]-48))*pow(2,g);
	          g++;
	      }

	      if(s[s.length()-1])
	      sum+=pow(2,g);


	      cout<<sum<<"\n";
	     }

	 }
}
