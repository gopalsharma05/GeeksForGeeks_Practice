/*

    problem-> kedane's'_algorithm(good).cpp

    Kadane's algorithm comes into picture when we want to find the maximum possible sum in an array when summing the contiguous elements of the array.

You are given an array. Find the maximum possible sum of contiguous elements of the array ending at each position in the array. Also, return the overall
 maximum that we can achieve.

Input Format:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains two lines of input. The first line
contains sizeOfArray. The second line contains the elements of the array.

Output Format:
For each testcase, in a new line, print the maximum sum at each index and print the maximum sum in the next line.

Your Task:
This is a function problem. You don't need to take any input. Just complete the function maximumSum() that takes the integer array and its size as inputs
 and prints the maximum contiguous subarray sum ending at each position in the array. Also, return the overall maximum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= sizeOfArray <= 103
-103 <= Ai <= 103

Example:
Input:
2
6
5 -2 -3 32 -5 65
5
-9 -8 8 3 -4

Output:
5 3 0 32 27 92
92
-9 -8 8 11 17
11

Example:
Testcase 1: Maximum sum at each index is 5, 3, 0, 32, 27, 92. And, maximum sum for contiguous array is 92.


            */


long long maximumSum(int a[], int n)
{
   int r=0,maxm=0,s=0,start,end;
   for(int i=0;i<n;i++)
   {
       r=max(r+a[i],a[i]);
       cout<<r<<" ";
       if(maxm<r)
       {
           maxm=r;
           start=s;
           end=i;

       }

       if(r<0)
       {
           r=0;
           s=i+1;
       }
   }
   cout<<endl;

//   cout<<start<< " "<<end<<"\n";  // for printing the range of maxm subarray

   return maxm;
}
