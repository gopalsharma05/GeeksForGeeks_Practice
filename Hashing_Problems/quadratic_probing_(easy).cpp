/*
    //Quadratic Probing in Hashing

Quadratic probing is a collision handling technique in hashing. Quadratic probing says that whenever a collision occurs, search for i2 position.

In this question, we'll learn how to fill up the hash table using Quadratic probing technique. You are given hash table size which you'll use to insert elements into their correct position in the hash table. You are also given an array arr[] of size N. You need to fill up the hash table using Quadratic probing and print the resultant hash table.

Note:

All the positions that are unoccupied are denoted by -1 in the hash table.
An empty slot can only be found if load factor < 0.5 and hash table size is a prime number.
The given testcases satisfy the above condition so you can assume that an empty slot is always reachable.
Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 3 lines of input. The first line contains size of the hashtable. The second line contains size of the array. The third line contains elements of the array.

Output Format:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You only need to complete the function QuadraticProbing that takes hash, hashSize, arr, and sizeOfArray as parameters and inserts elements of arr in hash

Constraints:
1 <= T <= 100
2 <= hashSize (prime) <= 97
1 <= sizeOfArray < hashSize*0.5

Examples:
Input:
1
11
4
21 10 32 43
Output:
10 -1 -1 32 -1 -1 -1 -1 43 -1 21

Explanation:
Testcase1: 21%11=10 so 21 goes into hashTable[10] position. 10%11=10. hashTable[10] is already filled so we
try for (10+12)%11=0 position. hashTable[0] is empty so we put 10 there. 32%11=10. hashTable[10] is filled.
We try (32+12)%11=0. But hashTable[0] is also already filled. We try (32+22)%11=3. hashTable[3] is empty so we put 32 in
hashTable[3] position.
43 uses (43+33)%11=8. We put it in hashTable[8]


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
	        else               // checking for nextempty slot by increasing slot index by j square
	        {
	            lli j=1;

	            while(v[(a[i]%s+j*j)%s]!=-1)
	            {
	                j++;


	                if((a[i]%s+j*j)%s==a[i]%s)
	                {
	                    flag=true;
	                    break;
	                }
	            }



	            if(flag)
	            break;

	            v[(a[i]%s+j*j)%s]=a[i];


	        }
	    }


	    for(lli i=0;i<s;i++)
	    cout<<v[i]<<" ";

	    cout<<endl;




	}

	return 0;


}
