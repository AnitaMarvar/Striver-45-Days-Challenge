//non-circular

class myQueue {

  public:
   int *arr;
   int frontIndex;
   int rearIndex;
   int n;
   
    myQueue(int n) {
        this->n = n;
        arr = new int[n];
        frontIndex=0;
        rearIndex=-1;
    }

    bool isEmpty() {
        if(frontIndex > rearIndex)return true;
        return false;
    }

    bool isFull() {
        if(rearIndex == n-1)return true;
        return false;
    }

    void enqueue(int x) {
       if(!isFull())
       {
           rearIndex++;
           arr[rearIndex] = x;
       }
    }

    void dequeue() {
       if(!isEmpty())
       {
           frontIndex++;
       }
    }

    int getFront() {
        if(!isEmpty())
        {
            return arr[frontIndex];
        }
        return -1;
    }

    int getRear() {
        if(!isEmpty())
        {
            return arr[rearIndex];
        }
        return -1;
    }
};
