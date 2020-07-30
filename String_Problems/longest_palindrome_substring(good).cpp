/*

    problem-> longest_palindrome_substring(good).cpp

    Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string:
     A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs
      first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".



            */



#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;

	    int n=s.length();
	    int start=0,len=1;
	    for(int i=1;i<n;i++)
	    {

	        // for even length string

	        int l=i-1,h=i;
	        while(l>=0&&h<n &&s[l]==s[h])
	        {
	            if(len<h-l+1)
	            {
	                len=h-l+1;
	                start=l;
	            }


	            h++;
	            l--;

	        }


	        // for odd length string

	        l=i-1,h=i+1;
	        while(l>=0&&h<n &&s[l]==s[h])
	        {
	            if(len<h-l+1)
	            {
	                len=h-l+1;
	                start=l;
	            }


	            h++;
	            l--;

	        }


	    }

	    cout<<s.substr(start,len)<<"\n";

	}

	return 0;
}
