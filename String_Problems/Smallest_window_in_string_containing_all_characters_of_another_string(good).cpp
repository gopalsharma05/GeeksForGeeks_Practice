/*

    problem-> Smallest_window_in_string_containing_all_characters_of_another_string(good).cpp


Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T contains lowercase english alphabets.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each test contains 2 lines having a string S and next line contains text T.

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be done then print -1.

Constraints:
1 <= T <= 100
1 <= |N|, |X| <= 1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo

Explanation:
Testcase 1: "toprac" is the smallest substring in the given string S which contains every characters of T.


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


	    string a,b;
	    cin>>a>>b;
	    int n=a.length();
	    int m=b.length();
	    unordered_map<char,int> hasha,hashb;
	    int minm=INT_MAX,maxm=INT_MIN,ans=-1,start=0,len=0;
        int cnt=0;

        for(int i=0;i<m;i++)
        hashb[b[i]]++;

        for(int i=0;i<n;i++)
        {

            hasha[a[i]]++;
            if(hashb[a[i]]!=0 && hasha[a[i]]<=hashb[a[i]])
            {
                cnt++;

            }

            if(cnt==m)
            {
                while(hasha[a[start]]>hashb[a[start]])
                {

                    hasha[a[start]]--;

                    start++;
                }

                len=i-start+1;
                if(minm>len)
                {
                    minm=len;
                    ans=start;
                }

            }
        }


        if(ans==-1)
        cout<<"-1\n";
        else
        {
            // cout<<start<<" "<<minm<<"\n";
            cout<<a.substr(ans,minm)<<"\n";
        }





	}
	return 0;
}
