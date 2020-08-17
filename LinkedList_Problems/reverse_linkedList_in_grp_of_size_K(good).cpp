/*

    problem->reverse_linkedList_in_grp_of_size_K(good).cpp

    Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list
elements.

Output:
For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

User Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Example:
Input:
2
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4

Explanation:
Testcase 1: Since, k = 4. So, we have to reverse every group of four elements. Modified linked list is as 4, 2, 2, 1, 8, 7, 6, 5.





                */





struct node *reverse (struct node *head, int k)
{
     node *current=head,*prev=NULL,*n=NULL,*f=head,*s,*ans;     // current,prev,n for reversing purpose.......f and s for doing connection internally and
                                                                    // and ans storing the head of required list
     int cnt1=0;
     while(current!=NULL)
     {
         int cnt=0;
         prev=NULL;
         while(cnt<k)
         {
             n=current->next;
             current->next=prev;
             prev=current;
             current=n;

             cnt++;

             if(current==NULL)
             break;
         }
         cnt1++;
         if(cnt1==1)
         {
             s=current;
             ans=prev;
         }
         if(cnt1>=2)
         {
             f->next=prev;
             f=s;
             s=current;
         }

     }

     return ans;
}
