#pragma once
#include <iostream>

template<typename T>
class u_vector 
{
public:
    u_vector();
    u_vector(const u_vector<T>& rhs);
    u_vector& operator=(const u_vector<T>& rhs) = delete;
    u_vector(u_vector<T> &&rhs) noexcept;
    u_vector& operator=(u_vector<T>&& rhs) noexcept;
    virtual ~u_vector(); 

    void push_back(T value);
    int size() const;
    void erase(int pos);
    void insert(const int pos, const T& value);

    struct iterator;
    iterator begin() const;
    iterator end() const;

    T& operator[](int i) const;
    template<typename T>
    friend std::ostream& operator<<(std::ostream& out, const u_vector<T>& rhs);   

private:
    
    void double_capacity(); //extra 1
    void new_container(const int old_size);
    void fill_new_arr(const int new_pos, const int new_size, const T& value, T* ptr_old);
    void permutation(const int new_pos, const int new_size);
    
        
    int m_arr_size;
    T *m_arr;
    int m_capacity;
};

template<typename T>
struct u_vector<T>::iterator
{
public:
    iterator(T* p);

    T& operator*();
    iterator& operator++();
    bool operator!=(iterator& rhs);

    T& get();

private:
    T* m_iterator_ptr;
};

#include "u_vector.ipp"


