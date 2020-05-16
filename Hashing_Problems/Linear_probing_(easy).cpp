/*
    Linear Probing in Hashing

    Linear probing is a collision handling technique in hashing. Linear probing says that whenever a collision occurs, search for the immediate next position.

In this question, we'll learn how to fill up the hash table using linear probing technique. You are given hash table size which you'll use to insert elements into their correct position in the hash table. You are also given an array arr of size n. You need to fill up the hash table using linear probing and print the resultant hash table.
Note: All the positions that are unoccupied are denoted by -1 in the hash table.
If there is no more space to insert, then just drop that element.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 3 lines of input. The first line contains size of the hashtable. The second line contains size of the array. The third line contains elements of the array.

Output Format:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You only need to complete this function linearProbing that takes parameters hash, hashSize, arr, sizeOfArray and inserts elements of arr in hash that is of size sizeOfArray.

Constraints:
1 <= T <= 100
1 <= hashSize <= 100
1 <= sizeOfArray <= 100

Examples:
Input:
1
10
4
4 14  24 44
10
4
9 99 999 9999
Output:
-1 -1 -1 -1 4 14 24 44 -1 -1
99 999 9999 -1 -1 -1 -1 -1 -1 9

Explanation:
Testcase1: 4%10=4. So put 4 in hashtable[4]. Now, 14%10=4, but hashtable[4] is already filled so put 14 in the next slot and
so on.
Testcase2: 9%10=9. So put 9 in hashtable[9]. Now, 99%10=9, but hashtable[9] is already filled so put 99 in the (99+1)%10 =0 slot
so 99 goes into hashtable[0] and so on.

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
	    lli s,n;
	    cin>>s>>n;
	    lli a[n];
	    for(lli i=0;i<n;i++)
	    cin>>a[i];

	    vector<lli> v(s,-1);    // vector filled initally with -1's
	    bool flag=false;

	    for(lli i=0;i<n;i++)
	    {
	        if(v[a[i]%s]==-1)    // checking slot is empty or not
	        v[a[i]%s]=a[i];
	        else               // checking for nextempty slot
	        {
	            lli j=(a[i]%s+1)%s;
	            while(v[j%s]!=-1)
	            {
	                j++;
	                if(j%s==a[i]%s)
	                {
	                    flag=true;
	                    break;
	                }
	            }



	            if(flag)
	            break;

	            v[j%s]=a[i];


	        }
	    }


	    for(lli i=0;i<s;i++)
	    cout<<v[i]<<" ";

	    cout<<endl;




	}

	return 0;


}
