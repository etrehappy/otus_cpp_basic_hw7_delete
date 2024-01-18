#pragma once
#include <iostream>

template<typename T>
class u_vector 
{
public:
    u_vector();
    u_vector(const u_vector<T>& rhs) = delete;
    u_vector& operator=(const u_vector<T>& rhs) = delete;
    u_vector(u_vector<T> &&rhs) noexcept;
    u_vector& operator=(u_vector<T>&& rhs) noexcept;
    ~u_vector(); 

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
    //friend bool operator!=(iterator& lhs, iterator& rhs); //!!! Почему в таком варианте возникает ошибка линковки? 

    T& get();

private:
    T* m_iterator_ptr;
};

#include "u_vector.ipp"


/*Текст ошибки для строки 49
Error	LNK2019	
unresolved external symbol  "bool __cdecl operator!=(struct u_vector<int>::iterator &,struct u_vector<int>::iterator &)" (??9@YA_NAEAUiterator@?$u_vector@H@@0@Z) 
referenced in function      "void __cdecl check_iterator<class u_vector<int> >(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class u_vector<int> const &)" 
(??$check_iterator@V?$u_vector@H@@@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$u_vector@H@@@Z)	
containers	C:\Users\etreh\Documents\Programming\Otus\C++_Developer_2023_06\Basic\lesson_14\otus_cpp_basic_hw6\cmake_build\main.obj	1
*/