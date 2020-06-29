/*
    problem- >  lexicography_rank_of_string(good).cpp

    You are given a string S of lowercase characters, find the rank of the string amongst its permutations when sorted lexicographically. Return 0 if the characters are repeated in the string.
Note: Return the rank%1000000007 as the answer as rank might overflow.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consists of a string S in 'lowercase' only in a separate line.

Output:
For each testcase, in a new line, print the rank of the string amongst its lexicographically-sorted-permutations.

Your Task:
This is a function problem. You only need to complete the function findRank that takes string S as a parameter and returns the rank.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 50
1 ≤ |S| ≤ 15

Example:
Input:
2
abc
acb
Output:
1
2

Explanation:
Testcase 1: In 'abc' when we sort all the permutations in lexicographic order 'abc' will be at the first position.
Testcase2: In 'acb' .The lexicographically-sorted permutations with letters 'a', 'c', and 'b' will be at second position.





        */

    /* APPROACH  ->
                        Let the given string be “STRING”. In the input string, ‘S’ is the first character. There are total 6 characters and 4 of
                        them are smaller than ‘S’. So there can be 4 * 5! smaller strings where first character is smaller than ‘S’, like following

R X X X X X
I X X X X X
N X X X X X
G X X X X X

Now let us Fix S’ and find the smaller strings staring with ‘S’.

Repeat the same process for T, rank is 4*5! + 4*4! +…

Now fix T and repeat the same process for R, rank is 4*5! + 4*4! + 3*3! +…

Now fix R and repeat the same process for I, rank is 4*5! + 4*4! + 3*3! + 1*2! +…

Now fix I and repeat the same process for N, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +…

Now fix N and repeat the same process for G, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0!

Rank = 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0! = 597

Note that the above computations find count of smaller strings. Therefore rank of given string is count of smaller strings plus 1.
The final rank = 1 + 597 = 598



                 */




#define mod 1000000007
void fact(int n,vector<int> &v)
{
    int ans=1;
    v.push_back(1);
    for(int i=1;i<=n;i++)
    {
        ans=((ans)%mod*(i)%mod)%mod;
        v.push_back(ans);
    }

}

int findRank(string s)
{
    //Your code here
    int n=s.length();
    vector<int> facvec;
    fact(n,facvec);

    unordered_map<char ,int> m;
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
        if(m[s[i]]>1)
        return 0;
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
         char ch=s[i];
         int cnt=0;
         for(int j=i+1;j<n;j++)
         if(s[j]<ch)
         cnt++;

         ans+=((cnt)*facvec[n-i-1])%mod;

    }
    return ans;





}
