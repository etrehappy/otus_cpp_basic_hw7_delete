#include "u_forward_list.h"

//u_forward_list's constructor and destructor

u_forward_list::u_forward_list()
    : m_arr_size(NULL), m_start_node(nullptr), m_lust_node(nullptr)
{
    std::cout << "\n 1. Cоздан объект класса u_forward_list для хранения элементов типа int в контейнере типа «Однонаправленный список».";
}

u_forward_list::u_forward_list(u_forward_list&& rhs) noexcept
{
    m_start_node = rhs.m_start_node;
    m_lust_node = rhs.m_lust_node;
    m_arr_size = rhs.m_arr_size;

    rhs.m_start_node = rhs.m_lust_node = nullptr;
    rhs.m_arr_size = NULL;

    std::cout << "\n 1. Вызван конструктор перемещения u_forward_list(u_forward_list&& rhs)";
}

u_forward_list& u_forward_list::operator=(u_forward_list&& rhs) noexcept
{
    if (&rhs == this)
        return *this;

    m_start_node = rhs.m_start_node;
    m_lust_node = rhs.m_lust_node;
    m_arr_size = rhs.m_arr_size;

    rhs.m_start_node = rhs.m_lust_node = nullptr;
    rhs.m_arr_size = NULL;

    std::cout << "\n 2. Вызван оператор присваивания перемещением operator=(u_forward_list&& rhs)";
    return *this;
}

u_forward_list::~u_forward_list()
{
    Node* it = m_start_node;
    Node* it_del = nullptr;

    if (it == nullptr)
    {
        //std::cout << "\nВызван деструктор ~u_forward_list(). Первый элемент контейнера пустой из-за перемещения f_list в f_list_2 или f_list_2 в f_list_3.";
        return;
    }

    while (it != nullptr)
    {
        it_del = it;
        it = it->next;

        delete it_del;
        it_del = nullptr;
    }
    //std::cout << "\nОбъект f_list удалён деструктором ~u_list()";
}


//Node's constructor and destructor

u_forward_list::Node::Node()
    : m_data(NULL), next(nullptr)
{
    //std::cout << "\n Вызван конструктор Node";
}


//public and friend functions

void u_forward_list::push_back(int value)
{
    ++m_arr_size;

    Node* new_node = new Node;
    new_node->m_data = value;

    if (m_arr_size == 1)   
        m_start_node = new_node;
    else      
        m_lust_node->next = new_node;

    m_lust_node = new_node;
}

int u_forward_list::size() const
{
    return m_arr_size;
}

//@param pos > 0
void u_forward_list::erase(int pos)
{   
    //check pos
    if (pos <= 0 || pos > m_arr_size)
    {
        std::cout << "\nError: erase pos <= 0 OR > max";
        exit(-1);
    }
    Node* node = m_start_node;
    Node* node_prev = nullptr;

    if (node == nullptr)
    {
        std::cout << "Первый элемент контейнера пустой.";
        return;
    }  

    //Search container[pos]       
    for (int count_pos = 1; count_pos != pos; ++count_pos)
    {
        node_prev = node;
        node = node->next;        
    }

    //Change memory address
    if (pos == 1)
    {
        node_prev = m_start_node;
        m_start_node = node_prev->next;
        goto size_count;
    }
    else if (node == nullptr) //check lust position
        node_prev->next = nullptr;
    else
        node_prev->next = node->next;  

    //Delete the old Node
    delete node;
    node = nullptr;

    size_count:
    --m_arr_size;
}

//@param pos > 0
void u_forward_list::insert(const int pos, const int value)
{
    if (pos < 1 || pos > m_arr_size)
    {
        std::cout << "\nError. Pos <= 0 OR pos > max container's size = " << m_arr_size;
        exit(1);
    }

    Node* node = m_start_node;
    Node* new_node = new Node;
    new_node->m_data = value;    

    if (pos == 1) //Insert in the first pos
    {
        m_start_node = new_node;
        new_node->next = node;
        goto size_count;
    }

    //Search container[pos]   
    Node* node_prev = nullptr;
    node = m_start_node->next;
    for (int count_pos = 2; count_pos != pos; ++count_pos) //start from the second node
    {
        node_prev = node;
        node = node->next;
    }
    
    //Insert 
    if (node == nullptr)            //in the lust position
        node_prev->next = new_node;
    else                            //in a pos between first and lust
    { 
        node_prev->next = new_node; //Set new address for container[pos-1].next, and error C6011 checked (node_prev != nullptr here)
        new_node->next = node;
    }    

    size_count:
    ++m_arr_size;
}

typename u_forward_list::iterator u_forward_list::begin() const
{
    return iterator(m_start_node);
}

typename u_forward_list::iterator u_forward_list::end() const
{    
    return iterator(m_lust_node->next);
}

std::ostream& operator<<(std::ostream& out, const u_forward_list& rhs)
{
    const u_forward_list::Node* it = rhs.m_start_node;
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
//iterator's constructor and public functions

u_forward_list::iterator::iterator(Node* p)
    : m_iterator_ptr(p)
{}

int& u_forward_list::iterator::operator*()
{
    return m_iterator_ptr->m_data;
}

typename u_forward_list::iterator& u_forward_list::iterator::operator++()
{
    m_iterator_ptr = m_iterator_ptr->next;
    return *this;
}

bool operator!=(typename u_forward_list::iterator& lhs, typename u_forward_list::iterator& rhs)
{
    return lhs.m_iterator_ptr != rhs.m_iterator_ptr;
}

int& u_forward_list::iterator::get()
{
    return m_iterator_ptr->m_data;
}