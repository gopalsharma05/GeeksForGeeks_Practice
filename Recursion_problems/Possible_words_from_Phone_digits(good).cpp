/*

    problem-> Possible_words_from_Phone_digits(good).cpp

        as given in our mobiles number :
        2 have letters   "abc"
        3 have letters   "def"
        4 have letters   "ghi"
        5 have letters   "jkl"
        6 have letters   "mno"
        7 have letters   "pqrs"
        8 have letters   "tuv"
        9 have letters   "wxyz"


Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line of each test case is N, N is the number of digits. The second line of each test case contains D[i], N number of digits.

Output:
Print all possible words from phone digits with single space in lower case.

Constraints:
1 <= T <= 10
1 <= N <= 10
2 <=  D[i] <= 9

Example:
Input:
1
3
2 3 4

Output:
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi


        */








#include<bits/stdc++.h>
#define lli long long int
using namespace std;
#define pb push_back

// dynamo 123


 void allnames(vector<string> v,lli  i,string s)
 {
     if(i==v.size())
     {
         cout<<s<<" ";
        return ;
     }

     for(lli j=0;j<v[i].length();j++)
     {
         s.pb(v[i][j]);
         allnames(v,i+1,s);
         s.pop_back();
     }



 }

int main()
{

    lli t;
    cin>>t;
    unordered_map<lli ,string> m;
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    while(t--)
    {
        lli n;
        cin>>n;
        vector<string> v;


        for(lli i=0;i<n;i++)
        {
            lli x;
            cin>>x;
            v.pb(m[x]);
        }

        allnames(v,0,"");
        cout<<endl;

    }

    return 0;
}
