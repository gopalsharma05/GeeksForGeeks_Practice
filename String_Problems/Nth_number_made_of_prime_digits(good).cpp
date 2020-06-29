/*


    problem-> Nth_number_made_of_prime_digits(good).cpp

Given a number 'N'. The task is to find the Nth number whose each digit is a prime number i.e 2, 3, 5, 7. In other words, you have to find the nth number of this sequence: 2, 3, 5, 7, 22, 23,.. and so on.

Input:
The first line contains a single integer T i.e. the number of test cases. The first and only line of each test case consists of an integer N.

Output:
In one line print the nth number of the given sequence made of prime digits.

Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 100

Examples:
Input:
2
10
21
Output:
33
222

Explanation:
Testcase 1: 10th number in the sequence of numbers whose each digit is prime is 33.
Testcase 2: 21st number in the sequence of numbers whose each digit is prime is 222.




APPROACH-->  JUST DO LITTLE BIT PAPER WORK...YOU WILL SEE A PATTERN THAT 1,5,9 NUMBER HAVE 2 AS LAST DIGIT, 2,6,10 HAVE 3 AS LAST DIGIT,,SO ON....SO
            // THAT THING IN MY SOLUTION


            */








#include <bits/stdc++.h>
using namespace std;

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s="";
	    char p[4];
	    p[1]='2';
	    p[2]='3';
	    p[3]='5';
	    p[0]='7';
	    while(n)
	    {

	            s+=p[n%4];
	            if(n%4==0)
	            n--;

	            n/=4;

	    }
	    reverse(s.begin(),s.end());
	    cout<<s<<"\n";



	}
	return 0;
}
