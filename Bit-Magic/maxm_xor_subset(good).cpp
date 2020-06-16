/*

    problem- maxm_xor_subset(good).cpp

    Given a set A[ ] of positive integers. The task is to find the maximum XOR value of the elements from all the possible subsets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N, where N is the size of the set A[ ]. The second line of each test case contains N space separated integers, denoting elements of the set A[ ].

Output
Print out the maximum XOR subset value.

Constraints
1 <= T <= 100
1 <= N <= 30
0 <= A[i] < 1000

Examples:
Input:
3
3
2 4 5
3
33 73 64
9
5 633 64 43 131 51 87 999 23

Output:
7
104
1023

Explanation:
Testcase 1: The maximum XOR value form possible subsets of the given array elements is : 7(2^5), where ^ is the symbol of XOR.

        */


 approach  ->>   please reffer this link             https://stackoverflow.com/questions/27470592/maximum-xor-among-all-subsets-of-an-array

 #include <bits/stdc++.h>
using namespace std;

int main() {
	 int t;
	 cin>>t;
	 while(t--)
	 {
	     int n;
	     cin>>n;
	     int a[n];

	     for(int i=0;i<n;i++)
	     {

	         cin>>a[i];

	     }

	     int ind=0;
	     for(int i=31;i>=0;i--)
	     {


	         int max_ind=ind,maxm=INT_MIN;  // using maxm to find the index of maxm element
	         for(int j=ind;j<n;j++)
	         {
	             if(((1<<i)&a[j])!=0  && maxm<a[j] )
	                {
	                    maxm=a[j];
	                    max_ind=j;
	                }
	         }


	         if(maxm==INT_MIN)
	         continue;

	         swap(a[max_ind],a[ind]);

	         max_ind=ind;

	         for(int j=0;j<n;j++)
	         {
	             if(j!=max_ind && ((1<<i)&a[j])!=0)
	             {
	                 a[j]=a[j]^a[max_ind];
	             }
	         }

	         ind++;


	     }



	     int ans=0;
	     for(int i=0;i<n;i++)
	     ans^=a[i];

	     cout<<ans<<"\n";



	 }
}
