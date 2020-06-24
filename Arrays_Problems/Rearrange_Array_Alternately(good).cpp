/*


        problem -> Rearrange_Array_Alternately(good).cpp


        Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...

Note: O(1) extra space is allowed. Also, try to modify the input array as required.

Input:
First line of input conatins number of test cases T. First line of test case contain an integer denoting the array size N and second line of test case contain N space separated integers denoting the array elements.

Output:
Output the modified array with alternated elements.

Constraints:
1 <=T<= 100
1 <=N<= 107
1 <=arr[i]<= 107

Example:
Input:
2
6
1 2 3 4 5 6
11
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60

Explanation:
Testcase 1: Max element = 6, min = 1, second max = 5, second min = 2, and so on... Modified array is : 6 1 5 2 4 3.




            */



 APPROACH  -> /*


            Here, We will store both new value and old value at same position.
            Here, We will use the formula Dividend = Divisor * Quotient + Remainder
where Divisor = max_element
           Quotient = New number at index i after rearrangement
           Remainder = Old Number at index i before rearrangement
           Dividend = The number stored at index i

The even indices store Max elements and the odd indices store Min elements. Traverse the array, and look for elements accordingly, multiply it with Divisor (max_element) and add the value present at arr[i]

Divisor is a value which is higher than values stored in array (in this case n - size of array, as array elements are between 0 to n-1)
Obviously, don't forget to remove the multiplier n from the values while accessing and outputting the new values.

                    */

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(lli i=0;i<n;i++)
        cin>>a[i];

        lli l=0,r=n-1,divisor=a[n-1]+1,i=0;   // divisor is (maxm of array +1).

        while(l<=r)
        {
            if(i%2==0)
            {
                a[i]+=(a[r]%divisor)*divisor;
                r--;

            }
            else
            {
                a[i]+=(a[l]%divisor)*divisor;
                l++;
            }
            i++;
        }

        for(lli i=0;i<n;i++)
        a[i]=a[i]/divisor;

        for(lli i=0;i<n;i++)
        cout<<a[i]<<" ";

        cout<<endl;


    }
}

