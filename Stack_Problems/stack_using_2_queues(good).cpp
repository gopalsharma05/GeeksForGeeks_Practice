/*


        problem-> stack_using_2_queues(good).cpp

        Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: In the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue
    will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.
Example 2:

Input:
Q = 4
Queries = 1 2 2 2 1 4
Output: 2 -1
Explanation: In the second testcase
1 2 the queue will be {2}
2   poped element will be 2 and
    then the queue will be empty
2   the queue is empty and hence -1
1 4 the queue will be {4}.
Your Task:
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the queue and pop which returns a integer
poped out from other queue(-1 if the queue is empty). The printing is done automatically by the driver code.

Expected Time Complexity : O(1) for both push() and O(N) for pop().
Expected Auxilliary Space : O(N).

Constraints:
1 <= Q <= 100
1 <= x <= 100

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a
 function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full
  code.

            */


         // APPROACH-> S2 STACK FOR POPPING OUT AND OTHER STACK (S1) IS FOR STORING THE ELEMENT , IF S2 GOT EMPTY, PUSH ALL ELEMENT FOR S1 TO S2 THEN POP


 void StackQueue :: push(int x)
 {
       s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        if(s1.empty()&& s2.empty())
       {
           return -1;
       }
       else
       {

           if(s2.empty())
           {
               while(!s1.empty())
               {
                   s2.push(s1.top());
                   s1.pop();
               }

           }

            int ans=s2.top();
               s2.pop();
               return ans;
       }
}
