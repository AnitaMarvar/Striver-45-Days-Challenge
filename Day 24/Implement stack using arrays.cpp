class myStack {
  public:
    int *arr;
    int n ;
    int topIndex;
    
    myStack(int n) {
        this->n = n;
        arr = new int[n];
        this->topIndex=-1;
    }

    bool isEmpty() {
        if(topIndex == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull() {
        if(topIndex == n-1)
        {
            return true;
        }
        return false;
    }

    void push(int x) {
        if(!isFull())
        {
            topIndex++;
            arr[topIndex] = x;
        }
    }

    void pop() {
       if(!isEmpty())
       {
           topIndex--;
       }
    }

    int peek() {
        if(topIndex != -1)
        {
            return arr[topIndex];
        }
        return -1;
    }
};
