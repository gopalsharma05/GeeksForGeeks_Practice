/*
    problem-> parenthesis_checker(good).cpp


    Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced


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
	    stack<char> st;
	    bool flag=true;
	    for(int i=0;i<n;i++)
	    {
	        if(st.empty())
	        {
	            if(s[i]=='{' ||s[i]=='[' ||s[i]=='(')
	            st.push(s[i]);
	            else{
	                flag=false;
	                break;
	            }
	        }
	        else {

	            if((s[i]=='}' &&st.top()=='{') ||(s[i]==')' &&st.top()=='(') ||(s[i]==']' &&st.top()=='['))
	            {
	                st.pop();
	            }
	            else
	            {
	                 if(s[i]=='{' ||s[i]=='[' ||s[i]=='(')
	                 st.push(s[i]);
	                 else{
	                flag=false;
	                break;
	            }

	            }

	        }

	    }

	    if(st.empty() && flag)
	    cout<<"balanced\n";
	    else
	    cout<<"not balanced\n";



	}
	return 0;
}
