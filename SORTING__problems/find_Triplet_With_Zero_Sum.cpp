 /*
 Find triplets with zero sum
Given an array A[] of N elements. The task is to complete the function which returns true if triplets exists in array A whose sum is zero else returns false.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N, denoting the number of elements in array. The second line of each test case contains N space separated values of the array.

Output:
For each test case, output will be 1 if triplet exists else 0.

Your Task:
Your task is to complete the function findTriplets() which check if the triplet with sum 0 exists or not. This is of boolean type which returns either true of false.

Constrains:
1 <= T <= 100
1 <= N <= 106
-106 <= A <= 106

Example:
Input:
2
5
0 -1 2 -3 1
3
1 2 3
Output:
1
0

Explanation:
Testcase 1: 0, -1 and 1 forms a triplet with sum equal to 0.
Testcase 2: No triplet exists which sum to 0.
 */

 bool twopointer(int a[],int n,int i)
{
    int l=i+1,r=n-1;
        while(l<r)
        {
            if(a[l]+a[r]+a[i]==0)   // as array is sorted so we can use the 2 pointer approach here to find the sum of
                                    // 2 numbers equal to required sum
            return true;
            else if(a[l]+a[r]+a[i]<0)
            l++;
            else
            r--;
        }

        return false;
}


bool findTriplets(int a[], int n)
{
    sort(a,a+n);  // sorting the array
    int cnt=0;
    for(int i=0;i<n;i++)         // this loop is selecting 1st element out of three
    {
        if(twopointer(a,n,i))     // calling function with 1st selected element
        return true;
    }

    return false;
}
