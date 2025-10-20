#ifndef HEAP_HPP
#define HEAP_HPP

template<typename T>
class Heap {
    private:
        T* data;
        int length;
        const int capacity;
    
        


    public:
        

        Heap(int capacity) : capacity(capacity), length(0) {data = new T[capacity];}

        virtual ~Heap() {delete[] data;}

        Heap(const Heap& other) : capacity(other.capacity), length(other.length), data(new T[other.capacity]) {
            for (int i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }

        virtual void insert(const T& value){
            if(length == 0) length++;
            data[length] = value;
            
        }
        
        int size()const{return size;}
        
        
        
};

#endif