/*

    problem->   merge_2_sorted_linked_list(easy).cpp


    Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the
     merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains N and M, and next two line contains N and M sorted
elements in two lines for each.

Output:
For each testcase, print the merged list in sorted form.

User Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged
linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N, M <= 104
1 <= Node's data <= 105

Example:
Input:
2
4 3
5 10 15 40
2 3 20
2 2
1 1
2 4
Output:
2 3 5 10 15 20 40
1 1 2 4

Explanation:
Testcase 1: After merging the two linked lists, we have merged list as 2, 3, 5, 10, 15, 20, 40.
Testcase 2: After merging the given two linked list , we have 1, 1, 2, 4 as output.


            */


Node* sortedMerge(Node* head1, Node* head2)
{

   Node *a=head1,*b=head2,*final=NULL,*ans;

   while(a!=NULL && b!=NULL)
   {
       if(a->data<b->data)
       {
           if(final==NULL)
           {
               final=a;
               ans=final;
               a=a->next;

           }
           else
           {
               final->next=a;
               a=a->next;
               final=final->next;
           }
       }
       else{

           if(final==NULL)
           {
               final=b;
               ans=final;
               b=b->next;

           }
           else
           {
               final->next=b;
               b=b->next;
               final=final->next;
           }

       }
   }

   while(a!=NULL)
   {
            if(final==NULL)
           {
               final=a;
               a=a->next;

           }
           else
           {
               final->next=a;
               a=a->next;
               final=final->next;
           }
   }

   while(b!=NULL)
   {
       if(final==NULL)
           {
               final=b;
               b=b->next;

           }
           else
           {
               final->next=b;
               b=b->next;
               final=final->next;
           }
   }

   return ans;


}
