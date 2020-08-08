/*

    problem-> Minimum_number_of_deletions_and_insertions_to_convert_strinaA_stringB(good).cpp


            Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in
            str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and
            inserted to some another point.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains
integers N and M denoting the length of the strings str1 and str2. Both the strings consist of only small letter alphabets.

The second line of each test case contains the strings str1 and str2.


Output:

Print the total no of insertions and deletions to be done to convert str1 to str2. Output the answer in a new line.


Constraints:

1<= T <=100

1<= N, M <=1000


Example:

Input:

1

4 3

heap pea

Output:

3


            */




#include <bits/stdc++.h>
using namespace std;

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;


	    int dp[n+1][m+1];

	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0  || j==0)
	            dp[i][j]=0;
	            else if(a[i-1]==b[j-1])
	            dp[i][j]=1+dp[i-1][j-1];
	            else
	            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	        }

	    }

	    int r=dp[n][m];
	   // cout<<r<<"\n";

	    int deletion=n-r;
	    int insertion=m-r;
	    cout<<insertion+deletion<<"\n";


	}

	return 0;
}
