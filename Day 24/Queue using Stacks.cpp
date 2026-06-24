class myQueue {

  public:
  stack<int>st1;
  stack<int>st2;
    myQueue() {
       
    }

    void enqueue(int x) {
        st1.push(x);
    }

    void dequeue() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(!st2.empty())
        st2.pop();
    }

    int front() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(!st2.empty())
        return st2.top();
        return -1;
    }

    int size() {
       return st1.size() + st2.size();
    }
};
