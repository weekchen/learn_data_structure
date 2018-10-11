//
// Created by AJishu on 18-10-8.
//
#include "iostream"
#include "vector"

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int queue_size;
    int head;
    int tail;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k = 1) {
        queue_size = k + 1;
        head = 0;
        tail = 0;
        for(int i=0; i < queue_size; i++)
            data.push_back(0);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()){
            data[tail] = value;
            tail = (tail+1)%queue_size;
            return true;
        }
        else
            return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()){
            head = (head+1)%queue_size;
            return true;
        }
        else
            return false;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(!isEmpty())
            return data[head];
        else
            return -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(!isEmpty()){
            if(tail == 0)
                return data[queue_size - 1];
            else
                return data[tail - 1];
        }
        else
            return -1;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail+1)%queue_size == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
