#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;

}

class minheap {

    int heap[1000];
    int size = 0;

    int parent(int i) {
        return (i - 1)/2 ;
    }

    int left_child(int i) {
        return 2*i + 1;
    }

    int right_child(int i) {
        return 2*i + 2;
    }

    //if any non leaf node is not present at its correct position
    //if heapify(i) - > it means node i is not at its correct position and apart from this node every other node is at its correct position
    void heapify(int i) {
        
        if(left_child(i) < size && heap[left_child(i)] >= heap[i]) {
            swap(heap[i], heap[left_child(i)]);
        }

        if(right_child(i) < size && heap[right_child(i)] >= heap[i]) {
            swap(heap[i], heap[right_child(i)]);
        }

    }


    public:

    int top() {
        return heap[0];
    }

    void insert(int val) {
        
        heap[size] = val;
        size++;
        int i = size - 1;

        while(i != 0 && heap[parent(i)] < heap[i]) {
            
            swap(heap[parent(i)], heap[i]);
            i = parent(i);

        }

    }

    void pop() {
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

    void printheap() {

        for(int i = 0; i < size; i++) {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }


    bool empty() {
        if(size == 0) return true;
        else return false;
    }

    
};


int main() {

    minheap pq;
    pq.insert(2);
    pq.insert(1);
    pq.insert(5);
    pq.insert(100);
    pq.insert(1);
    pq.insert(2);

    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
