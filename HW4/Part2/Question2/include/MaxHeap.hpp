//MaxHeap.hpp
#include <MaxHeap.h>
#include <cstdlib>
#include <cmath>

template <class T>
void MaxHeap<T>::BottomUpConstruction(const T *input_array, const int &size){
    if(capacity <= size){
        capacity = size*2;
        delete [] heap;
        heap = new T [capacity+1]; //heap[0] unused
        heap_size = size;
    }

    for(int i=0;i<size;++i){
        heap[i+1] = input_array[i];
    }

    int parent = heap_size/2;
    while(parent > 0){
        BobbleDown(parent);
        parent--;
    }
}

template <class T>
void MaxHeap<T>::Push(const T &item){
    if((heap_size+1) == capacity){//full condition
        ArrayDoubling();
    }

    heap_size++;
    heap[heap_size] = item;

    BobbleUp(heap_size);
}

template <class T>
void MaxHeap<T>::Pop(){
    if(MaxHeap<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: MaxHeap "+name+" is empty, cannot delete."));
    }

    heap[1] = heap[heap_size];
    heap[heap_size].~T();
    heap_size--;

    BobbleDown(1);
}


template <class T>
void MaxHeap<T>::Swap(T &item1, T &item2){
    T tmp = item1;
    item1 = item2;
    item2 = tmp;
}

template <class T>
void MaxHeap<T>::BobbleDown(const int &pos){
    int current_pos = pos;

    while(1){
        T max_val;
        int max_pos;
        int left_pos = current_pos*2;
        int right_pos = current_pos*2+1;

        if(right_pos <= heap_size){
            if(heap[left_pos] < heap[right_pos]){
                max_val = heap[right_pos];
                max_pos = right_pos;
            }else{
                max_val = heap[left_pos];
                max_pos = left_pos;
            }
        }else if(left_pos <= heap_size){
            max_val = heap[left_pos];
            max_pos = left_pos;
        }else{
            break;
        }

        if(heap[current_pos] < max_val){
            Swap(heap[current_pos], heap[max_pos]);
            current_pos = max_pos;
        }else{
            break;
        }
    }
}

template <class T>
void MaxHeap<T>::BobbleUp(const int &pos){
    int current_pos = pos;

    while(current_pos > 1){
        int parent = current_pos/2;
        if(heap[parent] < heap[current_pos]){
            Swap(heap[parent], heap[current_pos]);
        }
        current_pos = parent;
    }
}

template <class T>
void MaxHeap<T>::ArrayDoubling(){
    T* new_heap = new T [2*capacity];
    std::copy(heap, heap+capacity+1, new_heap);

    delete [] heap;
    heap      = new_heap;
    new_heap  = nullptr;
    capacity *= 2;
}

template <class T>
void MaxHeap<T>::operator=(const MaxHeap &other){
    if(capacity > 0){
        delete [] heap;
    }

    capacity = other.capacity;
    heap_size= other.heap_size;

    T *temp = new T [capacity];
    for(int i=1;i<=heap_size;++i){
        temp[i] = other.heap[i];
    }

    heap = temp;
    temp = nullptr;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const MaxHeap<T> &out_max_heap){
    if(out_max_heap.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The MaxHeap is empty."));
        return os;
    }

    os<<"> Array Illustration: "<<std::endl;
    os<<out_max_heap.name<<" = [";
    for(int i=0;i<=out_max_heap.heap_size;++i){
        if(i==out_max_heap.heap_size){
            os<<out_max_heap.heap[i]<<"]"<<std::endl;
        }else if(i==0){
            os<<"NULL"<<", ";
        }else{
            os<<out_max_heap.heap[i]<<", ";
        }
    }

    return os;
}
