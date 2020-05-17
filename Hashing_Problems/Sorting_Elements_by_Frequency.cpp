/*
problem->Sorting_Elements_by_Frequency

    Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase, in a new line, print each sorted array in a seperate line. For each array its numbers should be seperated by space.

Constraints:
1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ Ai ≤ 60

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

Explanation:
Testcase1: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are same then smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.

Testcase2: The highest frequency here is 3. The element 9 has the highest frequency. So 9 9 9 comes first. Now both 2 and 5 have same frequency. So we print smaller element first.
The output is 9 9 9 2 5.

        */


#include <bits/stdc++.h>
using namespace std;
#define lli long long int

bool cmp(pair<lli,lli> p1,pair<lli,lli> p2)    //comparator
{
    if(p1.first==p2.first)
    return p1.second<p2.second;
    else
    return p1.first>p2.first;
}

int main()
{
    lli  t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> m;
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;    // calculating the frequency of the elements
        }


        vector<pair<lli,lli> > vp;   // vector to store the frequency and elements...so that we can
                                        // sort this

        for(auto i=m.begin();i!=m.end();i++)
        {
            vp.push_back({i->second,i->first});
        }

        sort(vp.begin(),vp.end(),cmp);   // cmp(comparator) function to sort in decreasing order and handeling
                                        // this("If frequencies of two elements are same, then smaller
                                        //  number comes first") condition.

        for(lli i=0;i<vp.size();i++)
        {
            // cout<<vp[i].first<<" "<<vp[i].second<<" ";
            while(vp[i].first!=0)
            {
                cout<<vp[i].second<<" ";
                vp[i].first--;
            }
        }


        cout<<endl;
    }
}
