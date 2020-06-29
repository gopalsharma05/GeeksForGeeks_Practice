/*

DYNAMO 123

problem-> Sum_of_numbers_in_string(easy).cpp

Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string containing alphanumeric characters.

Output:
Print the sum of all numbers present in the string.

Constraints:
1<=T<=105
1<=length of the string<=105

Example:
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123

Explanation:
Testcase 1: 1 and 23 are numbers in the string which is added to get the sum as 24.
Testcase 4: 123 is a single number, so sum is 123.

*/

#include <iostream>
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
	    int i=n-1,ans=0;
	    while(i>=0)
	    {
	        if(isdigit(s[i]))
	        {
	            int g=1;

	            int sum=0;
	            sum+=g*(s[i]-48);
	            g*=10;
	            i--;
	            while(isdigit(s[i]))  // you can use stoi function of string to convert the string to numerical numbers
	            {
	                sum+=g*(s[i]-48);
	                i--;
	                g*=10;
	            }
	            ans+=sum;

	        }

	        else
	        i--;
	    }

	    cout<<ans<<"\n";
	}
	return 0;
}
