#include <iostream>
#include <vector>

template<typename T>
class myvector
{
    T* vector_pointer;
    int vector_size, vector_capacity;

public:
    myvector() // Default Constructor
        : vector_pointer(NULL)
        , vector_size(0)
        , vector_capacity(0) {}  
        
    myvector(vector<T> newVector) // Parametered  Constructor
        {
	       vector_pointer = newVector;
        } 

    myvector(const myvector& other) // Copy Constructor
        : vector_pointer(NULL)
        , vector_size(0)
        , vector_capacity(0)  
    {
        vector_pointer=new T[other.capacity()];
        std::copy(&other[0],&other[0]+other.size(),vector_pointer);
        vector_size=other.vector_size;
        vector_capacity=other.vector_capacity;
    }
    
        ~myvector()  // Destructor
    {
        delete[] vector_pointer;
    }
    
        void push_back(const T &val)
    {
        if(vector_capacity<=vector_size)
            vector_capacity = 2*vector_capacity;//reserve
        vector_pointer[vector_size++]=val;
    }
    
        void pop_back()  // Remove the last element of the vector..
    {
        if(vector_size)
        {
            vector_pointer[vector_size-1].~T();
            --vector_size;
        }
    }
    
    int size() const
    {
        return vector_size;
    }

    int capacity() const
    {
        return vector_capacity;
    }
    
        myvector& operator =(myvector other)
    {
        swap(*this,other);
        return *this;
    }
    
        bool empty() const
    {
        return vector_size==0;
    }
    
        void clear()
    {
        for(size_t i=0; i<vector_size; i++)
        {
            vector_pointer[i].~T();
        }
        vector_size=0;
    }
};
int main() {

    return 0;
}
