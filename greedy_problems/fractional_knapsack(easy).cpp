/*

    problem->fractional_knapsack(easy).cpp


    Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Input:
First line consists of an integer T denoting the number of test cases. First line consists of two integers N and W, denoting number of items and weight respectively. Second line of every test case consists of 2*N spaced integers denoting Values and weight respectively. (Value1 Weight1 Value2 Weight2.... ValueN WeightN)

Output:
Print the maximum value possible to put items in a knapsack, upto 2 decimal place.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= W <= 100

Example:
Input:
2
3 50
60 10 100 20 120 30
2 50
60 10 100 20

Output:
240.00
160.00

Explanation:
Test Case 1: We can have a total value of 240 in the following manner:
W = 50 (total weight the Knapsack can carry)
Val = 0
Include the first item. Hence we have: W = 50-10 = 40, Val = 60
Include the second item. W = 40-20 = 20, Val = 160
Include 2/3rd of the third item. W = 20-20 = 0, Val = 160 + (2/3)*120 = 160 + 80 = 240.

Test Case 2: We can have a total value of 160 in the following manner:
W = 50 (total weight the Knapsack can carry)
Val = 0
Include both the items. W = 50-10-20 = 20. Val = 0+60+100 = 160.

        */




#include <bits/stdc++.h>
using namespace std;
#define lli double

struct knapsack{
    lli val,wt;
};

bool cmp(knapsack a,knapsack b)
{
    lli d1=a.val/a.wt;
    lli d2=b.val/b.wt;
    return d1>d2;

}

int main() {
	//code
	lli t;
	cin>>t;
	while(t--)
	{
	    int n,cap;
	    cin>>n>>cap;
	    struct knapsack arr[n];
	    for(int i=0;i<n;i++)
	    {
	        lli a,b;
	        cin>>a>>b;

	        arr[i].val=a;
	        arr[i].wt=b;

	    }


	    sort(arr,arr+n,cmp);
	    lli ans=0;

	   // for(int i=0;i<n;i++)
	   // cout<<arr[i].val<<" "<<arr[i].wt<<"\n";

	    for(int i=0;i<n;i++)
	    {


	        if(cap>=arr[i].wt)
	        {
	            ans+=arr[i].val;
	            cap-=arr[i].wt;
	        }
	        else if(cap!=0)
	        {
	            ans+=cap*(double(arr[i].val/arr[i].wt));
	            cap=0;

	            break;


	        }




	    }


	    cout << fixed << setprecision(2) <<ans<<"\n";


	}

	return 0;
}
