 /*

LIVE   BATCHES

Three way partitioning
Given an array A[] and a range [a, b]. The task is to partition the array around the range such that array is divided in three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified arranged array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array (A[]).Then the next line contains two space separated integers which denote the range(a,b).

Output:
For each test case the output will be 1 if the array is properly arranged else it would be 0.

User Task:
The task is to complete the function threeWayPartition() which should segregate the elements as required. The function returns an array.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 106

Example:
Input:
2
5
1 2 3 3 4
1 2
3
1 2 3
1 3
Output:
1
1

Explanation:
Testcase 1: First, array has elements less than or equal to 1. Then , elements between 1 and 2.
 And, finally elements greater than 2. So, output is 1.
Testcase 2: First, array has elements less than or equal to 1. Then, elements between 1 and 3.
 And, finally elements greater than 3. So, output is 1.
 */

 vector<int> threeWayPartition(vector<int> v, int a, int b)
{
     int l=0,mid=0,h=v.size()-1;     // initializing the three variable
     while(mid<=h)
     {
         if(v[mid]<a)               // checking that element with mid index ,if  it is less than a then swapping
                                    // it with 'l' index and increament l and mid
         {
             swap(v[mid],v[l]);
             mid++;
             l++;
         }
         else if(v[mid]>b)         // checking that element ,if  it is greater than a then swaping it with 'h' index
                                    // decreament only h, as other element can be less than a ...so no change in mid
         {
             swap(v[h],v[mid]);
             h--;
         }
         else           // if element is in range [a,b] ,,just increament only mid
         {
             mid++;
         }
     }

    //  cout<<l<<" "<<mid<<" "<<h<<"\n";
    //  for(int i=0;i<v.size();i++)
    //  cout<<v[i]<<" ";
    //  cout<<endl;

     return v;
}
