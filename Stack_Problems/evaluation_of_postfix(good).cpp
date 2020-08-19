/*

    problem-> evaluation_of_postfix(good).cpp


    Given a postfix expression, the task is to evaluate the expression and print the final value. Operators will only include the basic arithmetic
    operators like *,/,+ and - .

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Constraints:
1 <= T <= 100
1 <= length of expression <= 100

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3

Explanation:
Test Case 1: 231*+9-
- : ( ) - ( )
9 : ( ) - (9)
+ : ( ( ) + ( ) ) - (9)
'*':  ( ( ) + ( ( ) * ( ) ) ) - (9)
1 : ( ( ) + ( ( ) * (1) ) ) - (9)
3 : ( ( ) + ( (3) * (1) ) ) - (9)
2 : ( (2) + ( (3) * (1) ) ) - (9)
Result = (2 + 3) - 9 = 5 - 9 = -4

Test Case 2: 123+*8-
- : ( ) - ( )
8 : ( ) - (8)
* : ( ( ) * ( ) ) - (8)
+ : ( ( ) * ( ( ) + ( ) ) ) - (8)
3 : ( ( ) * ( ( ) + (3) ) ) - (8)
2 : ( ( ) * ( (2) + (3) ) ) - (8)
1 : ( (1) * ( (2) + (3) ) ) - (8)
Result = (1 * 5) - 8 = 5 - 8 = -3

    */





#include <bits/stdc++.h>
using namespace std;
int calculate(int b,char x,int a)
{
    if(x=='+')
    return b+a;
    else if(x=='-')
    return b-a;
    else if(x=='*')
    return b*a;
    else
    return b/a;
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

	    stack<int> st;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='-' ||s[i]=='/' ||s[i]=='*' ||s[i]=='+' )
	        {
	            int a=st.top();
	            st.pop();
	            int b=st.top();
	            st.pop();

	            st.push(calculate(b,s[i],a));
	        }
	        else
	        {
	            st.push(s[i]-48);
	        }
	    }

	    cout<<st.top()<<"\n";


	}
	return 0;
}


