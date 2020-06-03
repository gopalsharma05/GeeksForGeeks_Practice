    /*

    //DYNAMO123

    problem->Largest_number_in_K_swaps(good).cpp

        Given a number K and string S of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of S atmost K times.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains a positive integer K. The second line of each test case contains a string of digits denoting a positive integer.

Output:
Print out the largest number possible.

Constraints:
1 <= T <= 100
0 <   S <= 30
0 <   K  <= 10

Examples :
Input:
3
4
1234567
3
3435335
2
1034

Output:
7654321
5543333
4301

Explanation:
Testcase 1: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.


            */



 approach -->   using backtrackcing swap every element with every greater element and compare string after each swap and pick the largest string
 //             if no. of swap becomes k simply backtrack as further swap we can not do.

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void backtrack(string s,int n,int k,string &ans)
{
    if(k==0)
    return ;
    int cnt=0;
    for(int i=0;i<n;i++)
    {


        for(int j=i+1;j<n;j++)
        {

            if(s[i]-48 < s[j]-48)
            {
                cnt++;
                string str=s;
                swap(s[i],s[j]);

                    if (s.compare(ans) > 0)
                        ans = s;

                backtrack(s,n,k-1,ans);
                 swap(s[i],s[j]);


            }





        }
    }


}

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int k;
	    cin>>k;
	    string s;
	    cin>>s;
	    int n=s.length();
	    string ans=s;

	    backtrack(s,n,k,ans);
	    cout<<ans<<"\n";


	}
	return 0;
}
