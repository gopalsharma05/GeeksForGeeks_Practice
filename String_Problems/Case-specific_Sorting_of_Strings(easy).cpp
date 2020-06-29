/*
    problem -> Case-specific_Sorting_of_Strings(easy).cpp

    Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase characters separately such that if the ith place in the original string had an uppercase character then it should not have a lowercase character after being sorted and vice versa.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the length of string. The second line contains a string S of length N, consisting of uppercase and lowercase characters.

Output:
For each testcase, print the sorted string.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 103

Example:
Input:
2
12
defRTSersUXI
6
eDefSR

Output:
deeIRSfrsTUX
eDefRS

Explanation:
Testcase 1: Sorted form of given string with the same case of character as that in original string.


        */


#include <bits/stdc++.h>
using namespace std;


bool cmp(char a,char b)
{
    if(a<=122 && a>=97 && b<=122 && b>=97)
    {
        return a<b;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    string s1="",s2="",s3="";
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]<=122 && s[i]>=97)
	        s1+=s[i];
	        else
	        s2+=s[i];
	    }

	    sort(s1.begin(),s1.end());
	    sort(s2.begin(),s2.end());
	   // cout<<s1<<" "<<s2<<"\n";
	    int j=0,k=0;
	     for(int i=0;i<n;i++)
	    {
	        if(s[i]<=122 && s[i]>=97)
	        s3+=s1[j++];
	        else
	        s3+=s2[k++];
	    }

	    cout<<s3<<"\n";



	}
	return 0;
}
