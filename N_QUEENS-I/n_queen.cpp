#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
void check(vector<vector<bool>> &isAttacked , vector<vector<bool>> &temp , int row , int col , int n , bool values){
 temp=isAttacked;

 
 // mark colums same as 
 for(int i=0; i<n; i++)
 {
    isAttacked[i][col]=true;
 }

 // now marks the diagonal understand it properly 
 for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i - j == row - col || i + j == row + col) {
                    isAttacked[i][j] = values;
                }
            }
        }


}
// how to solve this problem lets solve 
void solve(int n , vector<vector<string>> &ans , vector<vector<bool>> &isAttacked, int row , vector<string> &q){
 if(row==n){
    ans.push_back(q);
    return ;
 }

 for(int i=0; i<n; i++)
 {
    if(!isAttacked[row][i])
    {
      string s(n , '.');  // it wil create a string of size n with values'.' in it 
      s[i]='Q'; // where we put the queen mark it as queen 
      q[row]=s;

      vector<vector<bool>> temp;
      check(isAttacked ,temp ,row ,i , n , true);

      solve(n , ans , isAttacked ,row+1 , q);

      isAttacked=temp;
    }
 }

 
}
vector<vector<string>> solveNQueens(int n){
// Sbse pehle question samjh aagaya ab solve karo dhere dhere 
vector<vector<string>> ans;
vector<vector<bool>> isAttacked(n , vector<bool>(n , false));
vector<string> s(n , string(n , '.'));
solve(n , ans , isAttacked , 0 , s);
return ans;
}
};
int main()
{

    return 0;
}