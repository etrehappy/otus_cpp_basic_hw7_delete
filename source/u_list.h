#pragma once
#include <iostream>

class u_list
{
public:
    u_list();
    u_list(const u_list&) = delete;
    u_list& operator=(const u_list&) = delete;
    u_list(u_list&& rhs) noexcept;
    u_list& operator=(u_list&& rhs) noexcept;
    ~u_list();

    void push_back(int value);
    int size() const;
    void erase(int pos);
    void insert(const int pos, const int value);
    
    struct iterator;
    iterator begin() const;
    iterator end() const;

    friend std::ostream& operator<<(std::ostream& out, const u_list& rhs);    

private:

    struct Node;

    int m_arr_size;
    Node* m_start_node;    
    Node* m_end_node;
};


struct u_list::iterator
{
public:
    iterator(Node* p);

    int& operator*();
    iterator& operator++();
    friend bool operator!=(iterator& lhs, iterator& rhs); 

    int& get();

private:
    Node* m_iterator_ptr;
};

struct u_list::Node
{
    Node* next;
    Node* prev;
    int m_data;

    Node();    
    ~Node() = default;
};
