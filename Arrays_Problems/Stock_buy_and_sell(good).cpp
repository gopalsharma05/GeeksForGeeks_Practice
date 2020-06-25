/*

    problem ->  Stock_buy_and_sell(good).cpp

    The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input:
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days.

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line


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
        lli a[n];
        for(lli i=0;i<n;i++)
        cin>>a[i];

        lli profit=0,i=0;
        bool flag=false;
        while(i<n-1)
        {

            if(a[i]<=a[i+1])
            {
                flag=true;
                cout<<"("<<i<<" ";
                i++;
                while(a[i]<=a[i+1] && i+1<n)
                {

                    i++;
                }

                cout<<i<<") ";


            }
            i++;


        }

        if(flag==false)
        cout<<"No Profit";

        cout<<"\n";


    }

	return 0;


}
