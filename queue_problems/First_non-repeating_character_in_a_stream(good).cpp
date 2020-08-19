/*
    problem-> First_non-repeating_character_in_a_stream(good).cpp

    Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a
    character is inserted to the stream. If no non repeating element is found print -1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the
size of the stream. Then in the next line are x characters which are inserted to the stream.

Output:
For each test case in a new line print the first non repeating elements separated by spaces present in the stream at every instinct when a character is
 added to the stream, if no such element is present print -1.

Constraints:
1 <= T <= 200
1 <= N <= 500

Example:
Input:
2
4
a a b c
3
a a c

Output:
a -1 b b
a -1 c

Explanation:
Test Case 1: a a b c
The step wise first non-repeating elements are made bold:
a (print a)
a a (no non-repeating element, print -1)
a a b (print b)
a a b c (print b)
Result: a -1 b b

Test Case 2: a a c
a (print a)
a a (no non-repeating element, print -1)
a a c (print c)
Result: a -1 c


            */



#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char s[n];

        queue<char> q;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)
        {

            cin>>s[i];

            m[s[i]]++;
            if(m[s[i]]==1)
            q.push(s[i]);

            if(m[q.front()]==1)
            cout<<q.front()<<" ";
            else
            {

                while(!q.empty()&&m[q.front()]>1)
                q.pop();

                if(q.empty())
                cout<<"-1 ";
                else
                cout<<q.front()<<" ";

            }

        }

        cout<<endl;

    }
	return 0;
}
