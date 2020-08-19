/*

    problem-> generate_binary_number(good).cpp


    Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Input:
The first line of input contains an integer T denoting the number of test cases. There will be a single line for each testcase which contains N.

Output:
Print all binary numbers with decimal values from 1 to N in a single line.

Constraints:
1 ≤ T ≤ 106
1 ≤ N ≤ 106

Example:
Input:
2
2
5

Output:
1 10
1 10 11 100 101

Explanation:
Testcase 1: Binary numbers from 1 to 2 are 1 and 10


            */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n;
	cin>>n;
	while(n--)
	{
	    int n1;
	    cin>>n1;
	    queue<string> q;
	    q.push("1");
	    for(int i=0;i<n1;i++)
	    {
	        string s=q.front();
	        cout<<s<<" ";
	        q.pop();
	        q.push(s+'0');
	        q.push(s+'1');
	    }

	    cout<<endl;
	}
	return 0;
}
