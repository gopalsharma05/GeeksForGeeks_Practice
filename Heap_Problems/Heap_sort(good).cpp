/*

    problem->  Heap_sort(good).cpp

     Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Input:
First line of the input denotes number of test cases T. First line of the test case is the size of array and second line consists of array elements.

Output:
Sorted array in ascending order.

Your Task : Complete the functions heapify() and buildheap().

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10

Explanation:
Testcase 1: After sorting elements using heap sort, elements will be in order as 1,3,4,7,9.
Testcase 2: After sorting elements using heap sort, elements will be in order as 1, 2,3,4,5,6,7,8,9,10.


            */

void heapify(int a[], int n, int i)  {


      int left=2*i+1;
      int right=2*i+2;

      int l=i;
      if(left<n && a[left]>a[l])
      {
          l=left;
      }

      if(right<n && a[right]>a[l])
      l=right;

      if(l!=i)
      {
          swap(a[l],a[i]);
          heapify(a,n,l);
      }


}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  {

        int i=(n-2)/2;
        for(int k=i;k>=0;k--)
        {
            heapify(arr,n,k);
        }




}
