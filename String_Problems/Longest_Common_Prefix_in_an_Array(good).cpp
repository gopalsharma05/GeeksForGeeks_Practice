/*

        problem-> Longest_Common_Prefix_in_an_Array(good).cpp

        Given a array of N strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer N. Next line has
 space separated N strings.

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1 <= T <= 103
1 <= N <= 103
1 <= |S| <= 103

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

Explanation:
Testcase 1: Longest common prefix in all the given string is gee.



            */




#include<bits/stdc++.h>
using namespace std;

bool check(string a[],int n,string s,int start,int end)
{
    for(int i=0;i<n;i++)
    {
        for(int j=start;j<=end;j++)
        {
            if(a[i][j]!=s[j])
            return false;
        }
    }
    return true;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string a[n];
	    int minlen=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        int g=a[i].length();
	        minlen=min(minlen,g);
	    }


	    int l=0,r=minlen;
	    string ans="";

	    while(l<=r)
	    {
	        int mid=l+(r-l)/2;

	        if(check(a,n,a[0],l,mid))
	        {
	            ans+=a[0].substr(l,mid-l+1);
	            l=mid+1;
	        }
	        else
	        {
	            r=mid-1;
	        }
	    }
	    if(ans.length()>0)
	    cout<<ans<<"\n";
	    else
	    cout<<"-1\n";



	}
	return 0;
}
