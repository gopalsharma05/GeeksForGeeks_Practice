/*

    problem-> Max_sum_subarray_by_removing_at_most_one_element(good).cpp



    You are given array A of size n. You need to find the maximum-sum sub-array with the condition that you are allowed to skip at most one element.

Input Format:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case
contains a single integer n denoting the size of the array. The second line contains n space-separated integers A1, A2, ..., An denoting the elements of
the array.

Output Format:
For each test case, in a new line, print the maximum sum.

Your Task:
This is a function problem. The driver code takes input. Your task is to complete the function maxSumSubarray that take array and size as parameters and
returns the maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= n <= 100
-103 <= Ai<= 103

Example:
Input:
2
5
1 2 3 -4 5
8
-2 -3 4 -1 -2 1 5 -3

Output:
11
9

Explanation:
Testcase1:
Input  : A[] = {1, 2, 3, -4, 5}
Output : 11
We can get maximum sum subarray by skipping -4.
Testcase2:
Input: A[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 9
We can get maximum sum subarray by skipping -2 as [4, -1, 1, 5] sums to 9, which is the maximum achievable sum.


            */



         // APPROACH -> RUN KEDANE ALGORITHMS FROM BOTH END ,   AND STORE VALUES IN 2 VECTORS



int maxSumSubarray(int a[], int n)
{

     if(n==0)
     return 0;

     vector<int> leftkedane,rightkedane(n);
     int r=a[0],m=a[0];

     leftkedane.push_back(a[0]);

     for(int i=1;i<n;i++)
     {
         r=max(r+a[i],a[i]);
         m=max(r,m);
         leftkedane.push_back(r);
     }

     int res=m;

     r=a[n-1],m=a[n-1];
     rightkedane[n-1]=r;
     for(int i=n-2;i>=0;i--)
     {
         r=max(r+a[i],a[i]);
         m=max(r,m);
         rightkedane[i]=r;

     }

     int maxm=res;
     for(int i=0;i<n-1;i++)
     {
         maxm=max(maxm,rightkedane[i+1]+leftkedane[i-1]);
     }


     return maxm;

}
