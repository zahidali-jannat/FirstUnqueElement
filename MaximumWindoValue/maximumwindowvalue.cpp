#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution{
    public:
    vector<int> maxSlideWindow(vector<int> &nums , int k){
        // vector that i am going to intiliaze here is storing the ans 
        vector<int> ans;

        // the doubly ended queue that i am going to use is for storing max value for the specific window 
        deque<int> d;

        // run the loop over the vector nums 
        for(int i=0; i<nums.size(); i++)
        {

            // The code below this statement check whether the value that i am checking 
            // is under the window or outside the window 
            if(!d.empty() && i-d.front()>=k)
            {
                d.pop_back();
            }

            while(!d.empty() && d.front()< nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);

            if(i>=k-1)
            {
             ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
};


int main()
{
  Solution sol;
  int size=5;
  vector<int> a(size);
  for(int i=0; i<a.size(); i++)
  {
    cin >> a[i];
  }

  vector<int> ans =sol.maxSlideWindow(a , 3);
  for(int i=0; i<ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

    return 0;
}