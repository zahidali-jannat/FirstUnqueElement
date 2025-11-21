//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  bool IfPossible(int x, int y, vector<vector<int>>& matrix, vector<vector<bool>>& visited, int fdx, int fdy) {
    int n = matrix.size();
    int m = matrix[0].size();
    return (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == 1 && !visited[x][y]);
}
     void solve(vector<vector<int>>& matrix , vector<vector<bool>>&visited ,vector<int> &count ,int x , int y , int fdx, int fdy , int ans)
     {
        
        
        // base case 
        if(x==fdx&& y==fdy)
        {
            count.push_back(ans);
            ans=0;
            return ;
        }
        
      
        visited[x][y]=true;
        
        int newx=x-1;
        int newy=y;
        
        if(IfPossible(newx , newy , matrix , visited , fdx , fdy))
        {
            solve(matrix , visited , count , newx , newy, fdx , fdy , ans+1);
        }
        
        newx=x+1;
        newy=y;
          if(IfPossible(newx , newy , matrix , visited , fdx , fdy))
        {
             solve(matrix , visited , count , newx , newy, fdx , fdy , ans+1); 
        }
        
        
        newx=x;
        newy=y+1;
          if(IfPossible(newx , newy , matrix , visited , fdx , fdy))
        {
              solve(matrix , visited , count , newx , newy, fdx , fdy , ans+1);
        }
        
        newx=x;
        newy=y-1;
        
        if(IfPossible(newx , newy , matrix , visited , fdx , fdy))
        {
               solve(matrix , visited , count , newx , newy, fdx , fdy , ans+1);
        }
        
        
        visited[x][y]=false;
        
     }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) 
    {
     
     int n = matrix.size();
     int m = matrix[0].size();
     if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0) {
            return -1;
        }

        // If start and destination are the same
        if (xs == xd && ys == yd) {
            return 0;
        }
     vector<vector<bool>> visited(n, vector<bool>(m, false));
     
     int ans;
     
     int x=xs;
     int y=ys;
     int fdx=xd;
     int fdy=yd;
     vector<int> count;
    
     
     solve(matrix , visited , count,  x , y , fdx , fdy , ans);
     int max=-1;
     
     for(int i=0; i<count.size(); i++)
     {
         if(max<count[i]){
             max=count[i];
         }
     }
     ans=max;
     return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends