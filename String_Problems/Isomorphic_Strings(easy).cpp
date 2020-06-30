/*

    problem-> Isomorphic_Strings(easy).cpp


Given two string 'str1' and 'str2', check if two given strings are isomorphic to each other. Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2. And all occurrences of every character in ‘str1′ map to same character in ‘str2′.

Input:
The first line contains an integer T, depicting total number of test cases. Each test case contains two strings each in new line.

Output:
Print "1" if strings are isomorphic and "0" if not.

Constraints:
1 <= T <= 100
1 <= Length of Strings <= 103

Example:
Input:
2
aab
xxy
aab
xyz

Output:
1
0

Explanation:
Testcase 1: There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.


            */

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool  isomorphic(string a,string b)
{
    if(a.length()!=b.length())
    return false;

    int n=a.length();
    unordered_map<char,lli> m1,m2;


    for(int i=0;i<n;i++)
    {
        if(m1[a[i]]!=m2[b[i]])
        return false;

        m1[a[i]]=i+1;
        m2[b[i]]=i+1;
    }
    return true;



}

int main() {


	//DYNAMO 123


	lli t;
	cin>>t;
	while(t--)
	{
	  string a,b;
	  cin>>a>>b;

	  cout<<isomorphic(a,b)<<"\n";



	}
	return 0;
}
