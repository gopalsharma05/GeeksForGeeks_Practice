/*

    problem-> mergesort_LinkedList(good).cpp

    Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes in the linked list and next line
contains N elements of the linked list.

Output:
For each test, in a new line, print the sorted linked list.

Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 105

Note: Try to solve the problem in constant space.

Example:

Input:
2
5
3 5 2 4 1
3
9 15 0
Output:
1 2 3 4 5
0 9 15

Explanation:
Testcase 1: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.
Testcase 2: After sorting the given linked list , resultant will be 0->9->15.

*/




Node* partition(Node *head)
{
    if(head==NULL)
    return NULL;

    Node *first=head,*second=head->next;
    while(second!=NULL  && second->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
    }

    return first;

}

Node* merge(Node *a,Node* b)
{
    Node *ans=NULL,*t;
    while(a!=NULL  && b!=NULL)
    {
        if(a->data<b->data)
        {
            if(ans==NULL)
            {
                ans=a;
                a=a->next;
                t=ans;
            }
            else
            {
                ans->next=a;
                a=a->next;
                ans=ans->next;
            }
        }
        else
        {
            if(ans==NULL)
            {
                ans=b;
                b=b->next;
                t=ans;
            }
            else
            {
                ans->next=b;
                b=b->next;
                ans=ans->next;
            }
        }
    }


    while(a!=NULL)
    {
                ans->next=a;
                a=a->next;
                ans=ans->next;
    }

    while(b!=NULL)
    {
                 ans->next=b;
                b=b->next;
                ans=ans->next;
    }

    return t;

}

Node* mergesort(Node*head)
{
    if(head->next==NULL)
    return head;

      Node *r=partition(head);
      Node *k=r->next;
      r->next=NULL;

      Node *a=mergesort(head);
      Node* b=mergesort(k);
      return merge(a,b);
}


Node* mergeSort(Node* head) {


       return  mergesort(head);




}



        */
