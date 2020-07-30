/*

    problem-> Check_if_Linked_List_is_Palindrome(good).cpp

    Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list N and next line contains N integers as data of linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

User Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= T <= 103
1 <= N <= 50

Example:
Input:
2
3
1 2 1
4
1 2 3 4
Output:
1
0

Explanation:
Testcase 1: The given linked list is 1 2 1 , which is a pallindrome and Hence, the output is 1.
Testcase 2: The given linked list is 1 2 3 4 , which is not a pallindrome and Hence, the output is 0.

        */


bool isPalindrome(Node *head)
{
    Node *s=head,*f=head;

    while(f!=NULL  && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }

    if(f==NULL)  // it means number of nodes are even
    {
        // cout<<"even\n";
        Node *current=head,*p=NULL,*n;

        while(current!=s)
        {
            n=current->next;
            current->next=p;
            p=current;
            current=n;
        }

        while(p!=NULL)
        {
            if(p->data!=s->data)
            return false;

            // cout<<p->data<<" "<<s->data<<"\n";

            p=p->next;
            s=s->next;
        }

    }
    else                            // if number of nodes are odd
    {
        // cout<<"odd\n";
        Node *current=head,*p=NULL,*n;

        while(current!=s)
        {
            n=current->next;
            current->next=p;
            p=current;
            current=n;
        }
        s=s->next;
        while(p!=NULL)
        {

            if(p->data!=s->data)
            return false;

            p=p->next;
            s=s->next;
        }
    }


    return true;


}
