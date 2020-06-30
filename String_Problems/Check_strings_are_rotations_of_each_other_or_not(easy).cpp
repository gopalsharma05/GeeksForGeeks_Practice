/*


    problem-> Check_strings_are_rotations_of_each_other_or_not(easy).cpp


Given strings s1 and s2, you need to find if s2 is a rotated version of the string s1. The strings are lowercase.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines for
s1 and s2.

Output:
For each testcase, in a new line, you need to print 1 if s2 is a rotated version of s1; else print 0.

Constraints:
1 <= T <= 103
1 <= |s1|, |s2| <= 107

Example:
Input:
4
geeksforgeeks
forgeeksgeeks
mightandmagic
andmagicmigth
mushroomkingdom
itsamemario
geekofgeeks
geeksgeekof

Output:
1
0
0
1

Explanation:
Testcase 1: s1 is geeksforgeeks, s2 is forgeeksgeeks. Clearly, s2 is a rotated version of s1 as s2 can be obtained by left-rotating s1 by 5 units

*/

// DYNAMO 123

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool isrotate(string a,string b)
{
    return (a.length()==b.length() && (a+a).find(b)!=string::npos);

}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	  string a,b;
	  cin>>a>>b;
	  cout<<isrotate(a,b)<<"\n";




	}
	return 0;
}
