/*

    dynamo 123

    problem->  Reverse_words_in_given_string(easy).cpp

Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr


            */


using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{

	    string s;
	    cin>>s;   // here'.'is used to connect the word else use getline(cin,s)

	    reverse(s.begin(),s.end());

	    int n=s.length();
	    int  r=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='.')
	        {
	            reverse(s.begin()+r,s.begin()+i);
	            r=i+1;
	        }
	    }

	    reverse(s.begin()+r,s.end());

	    cout<<s<<"\n";




	}

	    return 0;
}
