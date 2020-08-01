/*

    problem-> sort_linkedList_of_(0,1,2)(easy).cpp

    Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all
    zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of the linked list and next
 line contains N elements as the data in the linked list.


Output:
For each test case, segregate the 0s, 1s, and 2s and display the linked list.

Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of
 the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
8
1 2 2 1 2 0 2 2
4
2 2 0 1
Output:
0 1 1 2 2 2 2 2
0 1 2 2

Explanation:
Testcase 1: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Testcase 2: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

        */


Node* segregate(Node *head) {

   Node *s=head;
   int zero=0,one=0,two=0;
   while(s!=NULL)
   {
       if(s->data==0)
       {
           zero++;

       }
       else if(s->data==1)
       {
           one++;
       }
       else
       {
           two++;
       }

       s=s->next;
   }

   s=head;

   while(zero--)
   {
    head->data=0;
    head=head->next;

   }
   while(one--)
   {
    head->data=1;
    head=head->next;

   }

   while(two--)
   {
    head->data=2;
    head=head->next;

   }


   return s;

}
