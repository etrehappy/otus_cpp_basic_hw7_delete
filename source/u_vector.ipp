#include "u_vector.h"

//u_vector's constructor and destructor

template<typename T>
u_vector<T>::u_vector()
    : m_arr_size(NULL), m_arr(new T[m_arr_size]), m_capacity(NULL)
{
    std::cout << "\n 1. Cоздан объект шаблонного класса u_vector для хранения элементов размером " << sizeof(T) << " байта в последовательном контейнере.";
}

template<typename T>
u_vector<T>::u_vector(u_vector<T>&& rhs) noexcept
{
    m_arr = rhs.m_arr;
    m_arr_size = rhs.m_arr_size;
    m_capacity = rhs.m_capacity;
    
    rhs.m_arr = nullptr;
    rhs.m_arr_size = NULL;
    rhs.m_capacity = NULL;

    std::cout << "\n 1. Вызван конструктор перемещения u_vector(u_vector<T>&& rhs)";
}

template<typename T>
u_vector<T>& u_vector<T>::operator=(u_vector<T>&& rhs) noexcept
{
    if (&rhs == this) 
        return *this;

    m_arr = rhs.m_arr;
    m_arr_size = rhs.m_arr_size;
    m_capacity = rhs.m_capacity;

    rhs.m_arr = nullptr;
    rhs.m_arr_size = NULL;
    rhs.m_capacity = NULL;

    std::cout << "\n 2. Вызван оператор присваивания перемещением operator=(u_vector<T>&& rhs)";
    
    return *this;
}

template<typename T>
u_vector<T>::~u_vector()
{
    delete[] m_arr;
    //std::cout << "\nОбъект удалён деструктором ~u_vector()";  
}



//u_vector's public and friend functions

template<typename T>
void u_vector<T>::push_back(T value)
{  
    const int old_size = m_arr_size;
    ++m_arr_size;

    if (m_capacity <= old_size)
    {
        double_capacity();
        new_container(old_size);
        m_arr[old_size] = value;
    }
    else if (m_capacity > old_size)
    {
        m_arr[old_size] = value;
    } 
}

template<typename T>
int u_vector<T>::size() const
{
    return m_arr_size;
}

//@param pos > 0
template<typename T>
void u_vector<T>::erase(int pos)
{   
    //check pos
    if (pos <= 0 || pos > m_arr_size)
    {
        std::cout << "\nError: erase pos <= 0 OR > max";
        exit(-1);
    }

    //move position
    for (int pre_pos = pos - 1; pre_pos < m_arr_size; pre_pos++)
    {
        m_arr[pre_pos] = m_arr[pre_pos + 1];
    }    
    --m_arr_size;
}

//@param pos > 0
template<typename T> 
void u_vector<T>::insert(const int pos, const T& value)
{
    if (pos < 1 || pos > m_arr_size)
    {
        std::cout << "\nError. Pos <= 0 OR pos > max container's size = " << m_arr_size;
        exit(1);
    }

    const int new_pos = pos - 1;
    const int old_size = m_arr_size;
    const int new_size = ++m_arr_size;
    
    T* arr_old = m_arr;

    if (m_capacity <= old_size)
    {
        double_capacity();        
        m_arr = new T[new_size];
        fill_new_arr(new_pos, new_size, value, arr_old);

        delete[] arr_old;
    }
    else if (m_capacity > old_size)
    {
        permutation(new_pos, new_size);
        m_arr[new_pos] = value;
    }
}

template<typename T>
typename u_vector<T>::iterator u_vector<T>::begin() const
{
    return iterator(m_arr);
}

template<typename T>
typename u_vector<T>::iterator u_vector<T>::end() const
{
    return iterator(m_arr + m_arr_size);
}

template<typename T>
T& u_vector<T>::operator[](int i) const
{
    return m_arr[i];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const u_vector<T>& rhs)
{
    if (rhs.m_arr == nullptr)
    {
        out << rhs.m_arr;
        return out;
    }

    const int last = rhs.size() - 1;

    for (int i = 0; i < last; ++i) {
        out << rhs[i] << ", ";
    }
    out << rhs[last];
    return out;
}



//u_vector's private functions

template<typename T>
void u_vector<T>::double_capacity()
{
    m_capacity = 2 * m_arr_size;
}

template<typename T>
void u_vector<T>::new_container(const int old_size) {

    T* arr_old = m_arr;
    m_arr = new T[m_capacity]{ NULL };

    std::copy(arr_old, arr_old + old_size, m_arr); //Used std::copy, because VS doesn't like my alternative code below (Warning C6386)
    
    //for (int i = 0; i < old_size; i++) {
    //    m_arr[i] = ptr_old[i];   //There isn't problem with here, because old_size = (m_arr_size - 1) 
    //}
    delete[] arr_old;
}

template<typename T>
void u_vector<T>::fill_new_arr(const int new_pos, const int new_size, const T& value, T* arr_old)
{ 
    for (int i = 0; i < new_size; i++)
    {
        if (i == new_pos)
            m_arr[i] = value; //insert new value in new_pos
        else if (i > new_pos)
            m_arr[i] = arr_old[i - 1]; //insert from (new value + 1) to end
        else
            m_arr[i] = arr_old[i];  //insert from 0 to new value 
    }
}

template<typename T>
void u_vector<T>::permutation(const int new_pos, const int new_size) 
{
    //move values from end until new value
    for (int j = new_size-1; j != new_pos; j--)
    {            
        m_arr[j] = m_arr [j-1];
    }
}


//===========================================================================================================
//iterator's constructor and public functions

template<typename T>
u_vector<T>::iterator::iterator(T* p)
    : m_iterator_ptr(p)
{}

template<typename T>
T& u_vector<T>::iterator::operator*()
{
    return *m_iterator_ptr;
}

template<typename T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator++()
{
    ++m_iterator_ptr;
    return *this;
}

template<typename T>
bool u_vector<T>::iterator::operator!=(typename u_vector<T>::iterator& rhs)
{
    return  m_iterator_ptr != rhs.m_iterator_ptr;
}

//template<typename T> //вариант с ошибкой
//bool operator!=(typename u_vector<T>::iterator& lhs, typename u_vector<T>::iterator& rhs)
//{
//    return lhs.m_iterator_ptr != rhs.m_iterator_ptr;
//}

template<typename T>
T& u_vector<T>::iterator::get()
{
    return *m_iterator_ptr;
}