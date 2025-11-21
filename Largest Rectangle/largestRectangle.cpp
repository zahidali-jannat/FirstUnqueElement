class Solution {
    private:
        vector<int> nextSmallerElement(vector<int> arr, int n) {
            vector<int> ans;
            stack<int> s;
            s.push(-1);
    
            for (int i = n - 1; i >= 0; i--) {
                int current = arr[i];
                while (s.top()!=-1 &&  arr[s.top()] >= current) {
                    s.pop();
                }
                ans.push_back(s.top());
                s.push(i);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
       vector<int> nextPreviousElement(vector<int> arr, int n) {
            vector<int> ans;
            stack<int> s;
            s.push(-1);
    
            for (int i = 0; i<n; i++) {
                int current = arr[i];
                while (s.top()!=-1 &&  arr[s.top()] >= current) {
                    s.pop();
                }
                ans.push_back(s.top());
                s.push(i);
            }
            
            return ans;
        }
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> next(n);
            next = nextSmallerElement(heights, n);
    
            vector<int> previous(n);
            previous = nextPreviousElement(heights, n);
            int area = INT_MIN;
            for (int i = 0; i < n; i++) {
                int length = heights[i];
                // yeh sochne wali hai chiz hai
                if (next[i] == -1) {
                    next[i] = n;
                }
                int width = next[i] - previous[i] - 1;
                int newArea = length * width;
                area = max(area, newArea);
                // if width -ve aai toh
            }
    
            return area;
        }
    };
    
    // vector<int> areas;
    // for(int i=0; i<heights.size(); i++)
    // {
    //     int left=i-1;
    //     int count=1;
    //     while(left>=0 && heights[i]<=heights[left])
    //     {
    
    //         count++;
    
    //      left--;
    //     }
    
    //     int right=i+1;
    //     while(right<heights.size() && heights[i]<=heights[right])
    //     {
    
    //         count++;
    
    //      right++;
    //     }
    //      int area = heights[i] * count;
    //  areas.push_back(area);
    // }
    
    // // now we have vector
    // int maxVal = *max_element(areas.begin(), areas.end());
    // return maxVal;