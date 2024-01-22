#include "u_list.h"

//u_list's constructor and destructor
u_list::u_list()
    : m_arr_size(0), m_start_node(nullptr), m_end_node(nullptr)
{  
   // std::cout << "\n 1. Cоздан объект класса u_list для хранения элементов типа int в контейнере типа «Двунаправленный список».";
}

u_list::u_list(u_list&& rhs) noexcept
{
    m_start_node = rhs.m_start_node;
    m_end_node = rhs.m_end_node;
    m_arr_size = rhs.m_arr_size;

    rhs.m_start_node = rhs.m_end_node = nullptr;
    rhs.m_arr_size = 0;

    std::cout << "\n 1. Вызван конструктор перемещения u_list(u_list&& rhs)";
}

u_list& u_list::operator=(u_list&& rhs) noexcept
{
    if (&rhs == this)
        return *this;

    m_start_node = rhs.m_start_node;
    m_end_node = rhs.m_end_node;
    m_arr_size = rhs.m_arr_size;

    rhs.m_start_node = rhs.m_end_node = nullptr;
    rhs.m_arr_size = 0;

    std::cout << "\n 2. Вызван оператор присваивания перемещением operator=(u_list&& rhs)";
    return *this;
}

u_list::~u_list()
{    
    Node* it = m_start_node;
    Node* it_del = nullptr;

    if (it == nullptr)
    {
        //std::cout << "\nВызван деструктор ~u_list(). Первый элемент контейнера пустой из-за перемещения list в list_2 или list_2 в list_3.";
        return;
    }

    while (it != nullptr)
    {
        it_del = it;
        it = it->next;

        delete it_del;
        it_del = nullptr;        
    }    
    /*std::cout << "\nОбъект list удалён деструктором ~u_list()";*/
}


//Node's constructor and destructor
u_list::Node::Node()
    : m_data(0), next(nullptr), prev(nullptr)
{
    //std::cout << "\n Вызван конструктор Node";
}


//public and friend functions

void u_list::push_back(int value)
{
    ++m_arr_size;

    Node* new_end_node = new Node;

    if (m_arr_size == 1)
    {
        m_start_node = m_end_node = new_end_node;
        m_start_node->m_data = value;
    }
    else
    {        
        new_end_node->m_data = value;
        new_end_node->prev = m_end_node;       
        m_end_node->next = new_end_node;       
        m_end_node = new_end_node;       
    }
}

int u_list::size() const
{
    return m_arr_size;
}

//@param pos > 0
void u_list::erase(int pos)
{
    //check pos
    if (pos <= 0 || pos > m_arr_size)
    {
        //std::cout << "\nError: erase pos <= 0 OR > max";
        return;
    }

    Node* node = m_start_node;

    if (node == nullptr)
    {
        std::cout << "Первый элемент контейнера пустой.";
        return;
    }

    //Search container[pos]   
    for (int count_pos = 1; count_pos != pos; ++count_pos)
    {
        node = node->next;
    }

    //Change memory address of the container[pos-1]->next and the container[pos+1]->prev.
    if (node->prev != nullptr) //not first
        node->prev->next = node->next;
    else    
        m_start_node = node->next;    
    
    if (node->next != nullptr) //not lust
        node->next->prev = node->prev;

    //Delete the old Node
    delete node;
    node = nullptr; 
    --m_arr_size;
}

//@param pos > 0
void u_list::insert(const int pos, const int value)
{
    if (pos < 1 || pos > m_arr_size)
    {
       // std::cout << "\nError. Pos <= 0 OR pos > max container's size = " << m_arr_size;
        return;
    }

    Node* old_node = m_start_node;
    Node* new_node = new Node;
    new_node->m_data = value;
   
    /*if (m_arr_size == 0)
    {
        m_start_node = m_end_node = new_node;
    }
    else */if (pos == 1) //Insert in the first pos
    {
        old_node->prev = m_start_node = new_node;
        new_node->next = old_node;
    }
    else if (pos > 1)
    {
        //Search container[pos]
        old_node = m_start_node->next;
        for (int count_pos = 2; count_pos != pos; ++count_pos) //start from second node
        {
            old_node = old_node->next;
        }

        //Set new address for container[pos-1].next
        old_node->prev->next = new_node; 

        new_node->prev = old_node->prev;
        new_node->next = old_node;

        //Set new address for container[pos+1].prev
        old_node->prev = new_node; 
    }    

    ++m_arr_size;
}

typename u_list::iterator u_list::begin() const
{
    return iterator(m_start_node);
}

typename u_list::iterator u_list::end() const
{
    return iterator(m_end_node->next);
}

std::ostream& operator<<(std::ostream& out, const u_list& rhs)
{    
    const u_list::Node* it = rhs.m_start_node;
    for (; it->next != nullptr; ) {
        out << it->m_data << ", ";
        it = it->next;
    }

    if (it->next == nullptr)
    {
        out << it->m_data;
    }
   
    return out;
}



//===========================================================================================================
//iterator's

u_list::iterator::iterator(Node* p)
    : m_iterator_ptr(p)
{}

int& u_list::iterator::operator*()
{
    return m_iterator_ptr->m_data;
}

typename u_list::iterator& u_list::iterator::operator++()
{
    m_iterator_ptr = m_iterator_ptr->next;
    return *this;
}

bool operator!=(typename u_list::iterator& lhs, typename u_list::iterator& rhs)
{
    return lhs.m_iterator_ptr != rhs.m_iterator_ptr;
}

int& u_list::iterator::get()
{
    return m_iterator_ptr->m_data;
}