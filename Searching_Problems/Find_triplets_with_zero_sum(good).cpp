/*

    problem-> Find_triplets_with_zero_sum(good).cpp



    Given an array of integers. Check whether it contains a triplet that sums up to zero.

Example 1:

Input: N = 5, arr[] = {0, -1, 2, -3, 1}
Output: true
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: false
Explanation: No triplet with zero sum exists.

Your Task:
You don't need to read input or print anything. Your task is to complete the boolean function findTriplets() which takes the array arr[] and the size of
 the array (n) as inputs and returns True if the given array has a triplet with zero sum and False otherwise.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constrains:
1 <= N <= 104
-106 <= Ai <= 106



                */



      //APPROACH-> TWO_POINTER_APPROACH




bool istrue(int j,int a[],int n)
{
    int l=j+1,r=n-1;
    while(l<r)
    {

        if(a[j]+a[l]+a[r]==0)
        return true;
        else if(a[j]+a[l]+a[r]<0)
        l++;
        else
        r--;

    }

    return false;
}
bool findTriplets(int a[], int n)
{
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(istrue(i,a,n))
        return true;
    }


    return false;
}
