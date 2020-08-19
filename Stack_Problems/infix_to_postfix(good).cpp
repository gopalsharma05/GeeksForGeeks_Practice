/*

    problem-> infix_to_postfix(good).cpp

    Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Input:
The first line of input contains an integer T denoting the number of test cases. The next T lines contains an infix expression.The expression contains
all characters and ^,*,/,+,-.

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Constraints:
1 <= T <= 100
1 <= length of str <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/





            */



#include <bits/stdc++.h>
using namespace std;

bool isoperator(char ch)
{
    if(ch=='^' ||ch=='*' ||ch=='/' ||ch=='-' ||ch=='+' )
    return true;

    return false;
}

int precedence(char a)
{
    if(a=='^')
    return 3;
    if(a=='+' || a=='-')
    return 1;
    if(a=='*' || a=='/')
    return 2;

    return -1;
}

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



	    for(int i=0;i<n;i++)
	    {


	        if(isoperator(s[i]))
	        {

	               while(!st.empty()&&precedence(st.top())>=precedence(s[i])
	               && st.top()!='(')
	               {
	                   cout<<st.top();
	                   st.pop();
	               }

	               st.push(s[i]);

	        }
	        else if((s[i]<=122 && s[i]>=97) ||(s[i]<=90 && s[i]>=65))
	        {
	            cout<<s[i];
	        }
	        else if(s[i]=='(')
	        st.push(s[i]);
	        else if(s[i]==')')
	        {
	            while(!st.empty()&&st.top()!='(')
	            {
	                cout<<st.top();
	                st.pop();
	            }
	            if(!st.empty())
	            st.pop();
	        }

	    }

	    while(!st.empty())
	    {
	        cout<<st.top();
	        st.pop();
	    }

	    cout<<endl;


	}
	return 0;
}
