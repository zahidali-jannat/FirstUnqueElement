#include <iostream> 
#include <vector>
#include <string>


using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
          // now how  
          vector<int> ans(26 ,0);
          int result=-1;
          for(int i=0; i<s.length(); i++){
           
            ans[s[i]-'a']++;
          }
    
           for(int i=0; i<s.length(); i++){
            int element=s[i]-'a';
            if(ans[element]==1){
                return i;
            }
           }
          return -1;
        }
    };