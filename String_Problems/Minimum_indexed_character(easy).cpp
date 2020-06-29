/*

    problem-> Minimum_indexed_character(easy).cpp


Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Output the character in patt that is present at the minimum index in str. Print "$" (without quotes) if no character of patt is present in str.

Constraints:
1 <= T <= 105
1 <= |str|, |patt| <= 105

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
$

Explanation:
Testcase 1: e is the character which is present in given patt "geeksforgeeks" and is first found in str "set"


        */


#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string a,b;
	    cin>>a>>b;

	    int n=a.length();
	    int m1=b.length();
	    unordered_map<char,int> m;
	    for(int i=0;i<n;i++)
	    {
	        if(m[a[i]]==0)
	        m[a[i]]=i+1;
	    }

	    int ans=INT_MAX;
	    for(int i=0;i<m1;i++)
	    {

	    if(m[b[i]]!=0)
	    ans=min(m[b[i]],ans);

	    }

	    if(ans==INT_MAX)
	    cout<<"$\n";
	    else
	    cout<<a[ans-1]<<"\n";


	}
	return 0;
}
