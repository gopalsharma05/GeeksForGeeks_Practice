/*

    Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines:-
The number of votes cast N
The name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output:
For each testcase, print the name of the candidate with the maximum votes, and also print the votes casted for the candidate. The name and votes are separated by a space.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark

Output:
john 4
andy 1

Explanation:
Testcase1: john has 4 votes casted for him, but so does johny. john is lexicographically smaller, so we print john and the votes he received.
Testcase2: All the candidates get 1 votes each. We print andy as it is lexicographically smaller.

    */




#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	//code

	lli t;
	cin>>t;
	while(t--)
	{
	    lli n;
	    cin>>n;
	    string a[n];
	    map<string ,lli> m;
	    for(lli i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m[a[i]]++;
	    }
	    lli maxm=INT_MIN;
	    string ans;
	    for(auto x=m.begin();x!=m.end();x++)
	    {
	        if(maxm<x->second)
	        {
	            ans=x->first;
	            maxm=x->second;
	        }
	    }

	    cout<<ans<<" "<<maxm<<"\n";


	}

	return 0;
}
