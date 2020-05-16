/*

SEPERATE CHAINING

Separate chaining technique in hashing allows to us to use a linked list at each hash slot to handle the problem of collisions. That is, every slot of the hash table is a linked list, so whenever a collision occurs, the element can be appened as a node to the linked list at the slot.

In this question, we'll learn how to fill up the hash table using Separate chaining technique. You are given hash table size which you'll use to insert elements into their correct position in the hash table. You are also given an array arr. The size of the array is denoted by sizeOfArray. You need to fill up the hash table using Separate chaining and print the resultant hash table.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 3 lines of input. The first line contains size of the hashtable. The second line contains size of the array. The third line contains elements of the array.

Output Format:
For each testcase, in a new line, print the hash table.

Constraints:
1 <= T <= 100
2 <= hashSize <= 103
1 <= sizeOfArray <= 103
0 <= arri <= 107

Examples:
Input:
2
10
6
92 4 14 24 44 91
5
3
33 65 46
Output:
1->91
2->92
4->4->14->24->44
0->65
1->46
3->33

Explanation:
Testcase1: 92%10=2 so 92 goes to slot 2. 4%10=4 so 4 goes to slot
4. 14%10=4. But 4 is already occupied so we make a linked list at this position and add 14 after 4 in slot 4 and so on.

    */

// code start here

#include <bits/stdc++.h>
using namespace std;
#define lli long long int


void printans(vector<lli> v[],lli s)
{
    for(lli i=0;i<s;i++)
    {
       if(v[i].size()!=0)
       {
           lli j;
           cout<<i<<"->";
           for( j=0;j<v[i].size()-1;j++)
           {
               cout<<v[i][j]<<"->";
           }
           cout<<v[i][j]<<"\n";

       }

    }
}

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

	    vector<lli> v[s];     // creating this 2d vector to make the chain
	    for(lli i=0;i<n;i++)
	    {
	        v[a[i]%s].push_back(a[i]);   // putting the element in table(2-d vector)...have chain
	    }


	    printans(v,s);   //   this function printing the answer in the required manner


	}

	return 0;
}
