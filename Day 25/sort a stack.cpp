class Solution {
  public:
    void sortStack(stack<int> &st) {
        stack<int>temp;
        
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            
            while(!temp.empty() && temp.top() < curr)   // if > done this it sorts descending manner
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(curr);
        }
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        
        
    }
};
