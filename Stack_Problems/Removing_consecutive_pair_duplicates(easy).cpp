/*

        problem-> Removing_consecutive_pair_duplicates(easy).cpp

        You are given a string str. You need to remove the pair of duplicates.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing string str.

Output:
For each testcase, in a new line, print the modified string. If the final string is empty print "$"

Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaabbaaccd
aabb
Output:
ad
$

Explanation:
Testcase1: Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad


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
	    stack<char> st;
	    int n=s.length();

	    for(int i=0;i<n;i++)
	    {
	        if(st.empty())
	        {
	            st.push(s[i]);
	        }
	        else
	        {
	            if(st.top()==s[i])
	            {
	                st.pop();
	            }
	            else
	            {
	                st.push(s[i]);
	            }
	        }
	    }
	    string ans="";
	    while(!st.empty())
	    {
	        ans+=st.top();
	        st.pop();
	    }

	    reverse(ans.begin(),ans.end());
	    if(ans.size()!=0)
	    cout<<ans<<"\n";
	    else
	    cout<<"$\n";


	}
	return 0;
}
