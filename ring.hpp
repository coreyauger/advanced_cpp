
#ifndef _RING_HPP_
#define _RING_HPP_

#include <vector>

template< typename T >
class Ring{
    private:
        int len;
        int next;
        std::vector<T> buffer;

    public:    
        Ring(int size) : len(size), next(0), buffer(size){
        }
        ~Ring(){            
        }

        class iterator;
        const int size() const { return len; }
        void add( T item ){
            int i = next++ % len;
            buffer[i] = item;
        }

        iterator begin(){
            return iterator(0, *this);
        }
        iterator end(){
            return iterator(len, *this);
        }

        T& operator [](int idx) {
            int i = idx % len;
            return buffer[i];
        }
};

template< typename T >
class Ring<T>::iterator{
    private:
        int pos;
        Ring& ring;
    public:
        iterator(int pos, Ring& ring) : pos(pos), ring(ring){            
        }

        bool operator!=(const iterator& other) const{
            return pos != other.pos;
        }

        iterator& operator++(int){
            pos++;
            return *this;
        } 
        iterator& operator++(){
            pos++;
            return *this;
        } 

        T& operator*(){
            return ring[pos % ring.size()];
        }       
};

#endif