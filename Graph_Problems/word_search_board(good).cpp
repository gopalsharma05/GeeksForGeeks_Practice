/*

    problem-> word_search_board(good).cpp


    Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.




                */




bool dfs(vector<string> a,string s,int i,int j,int k)
{
    if(i<0 || j>=a[0].size()||i>=a.size()||j<0 ||a[i][j]!=s[k])
    return false;

    if(a[i][j]==s[k]&&k==s.length()-1)
    return true;

    if(dfs(a,s,i+1,j,k+1))
    return true;
    if(dfs(a,s,i-1,j,k+1))
    return true;
    if(dfs(a,s,i,j+1,k+1))
    return true;
    if(dfs(a,s,i,j-1,k+1))
    return true;

    return false;

}

int Solution::exist(vector<string> &a, string s) {


    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]==s[0])
            {

                if(dfs(a,s,i,j,0))
                return true;
            }
        }
    }

    return false;



}
