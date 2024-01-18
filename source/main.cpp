#include "main.h"

template<typename C>
void print(int number, std::string name, const C& container)
{
    std::cout << "\n " << number << ". ���������� ���������� " << name << ": " << container;
}

template<typename C>
void print_move(int number, std::string name, const C& container_moved)
{
    std::cout << "\n " << number << ". ���������� ���������� " << name << ": " << container_moved;
    std::cout << "\n-----------------------------------------------\n";
}

int middle_pos(int size)
{
    return (size / 2) + 1;
}

void check_u_vector(u_vector<int>& vec)
{  
    const int size_vec = 10;
    for (int i = 0; i < size_vec; i++)
    {
        vec.push_back(i);
    }

    std::cout << "\n 2. � ��������� vec ��������� " << size_vec << " ���������.";
    print(3, "vec", vec);
    std::cout << "\n 4. ������ ����������: " << vec.size();

    vec.erase(3);
    vec.erase(4);
    vec.erase(5);

    std::cout << "\n 5. �� ���������� ������� 3, 5 � 7 ��������.";
    print(6, "vec", vec);

    vec.insert(1, 10);

    std::cout << "\n 7. �������� ������� 10 � ������ ����������.";
    print(8, "vec", vec);
    
    vec.insert(middle_pos(vec.size()), 20);

    std::cout << "\n 9. �������� ������� 20 � �������� ����������.";
    print(10, "vec", vec);

    vec.push_back(30);
    std::cout << "\n 11. �������� ������� 30 � ����� ����������.";
    print(12, "vec", vec);
}

void check_u_list(u_list& list)
{   
    const int size_list = 13;
    for (int i = 0; i < size_list; i++)
    {
        list.push_back(i);
    }
    std::cout << "\n 2. � ��������� list ��������� " << size_list << " ���������.";    
    print(3, "list", list);
    std::cout << "\n 4. ������ ����������: " << list.size();

    list.erase(3);
    list.erase(4);
    list.erase(5);
    std::cout << "\n 5. �� ���������� ������� 3, 5 � 7 ��������.";
    print(6, "list", list);

    list.insert(1, 10);
    std::cout << "\n 7. �������� ������� 10 � ������ ����������.";
    print(8, "list", list);

    list.insert(middle_pos(list.size()), 20);
    std::cout << "\n 9. �������� ������� 20 � �������� ����������.";
    print(10, "list", list);

    list.push_back(30);
    std::cout << "\n 11. �������� ������� 30 � ����� ����������.";
    print(12, "list", list);
}

void check_u_forward_list(u_forward_list& f_list)
{
    const int size_f_list = 18;
    for (int i = 0; i < size_f_list; i++)
    {
        f_list.push_back(i);
    }
    std::cout << "\n 2. � ��������� f_list ��������� " << size_f_list << " ���������.";
    print(3, "f_list", f_list);
    std::cout << "\n 4. ������ ����������: " << f_list.size();

    f_list.erase(3);
    f_list.erase(4);
    f_list.erase(5);
    std::cout << "\n 5. �� ���������� ������� 3, 5 � 7 ��������.";
    print(6, "f_list", f_list);

    f_list.insert(1, 10);
    std::cout << "\n 7. �������� ������� 10 � ������ ����������.";
    print(8, "f_list", f_list);

    f_list.insert(middle_pos(f_list.size()), 20);
    std::cout << "\n 9. �������� ������� 20 � �������� ����������.";
    print(10, "f_list", f_list);

    f_list.push_back(30);   
    std::cout << "\n 11. �������� ������� 30 � ����� ����������.";
    print(12, "f_list", f_list);
}

void check_move(u_vector<int>& vec, u_list& list, u_forward_list& f_list)
{   
    std::cout << "\n�������������� ������� 3. ������������ � ���������� ��������� �����������\n";

    u_vector<int> vec_2(std::move(vec));   
    print_move(2, "vec_2", vec_2);

    u_vector<int> vec_3;
    vec_3 = static_cast<u_vector<int>&&>(vec_2); //Used static_cast just for a practice
    print_move(3, "vec_3", vec_3);
    
    u_list list_2(std::move(list));
    print_move(2, "list_2", list_2);
    
    u_list list_3;
    list_3 = std::move(list_2);
    print_move(3, "list_3", list_3);

    u_forward_list f_list_2(std::move(f_list));
    print_move(2, "f_list_2", f_list_2);

    u_forward_list f_list_3;
    f_list_3 = std::move(f_list_2);
    print_move(3, "f_list_3", f_list_3);
}

template<typename C>
void check_iterator(std::string name, const C& container)
{    
    std::cout << "\n - ���������� ���������� " << name << ": ";

    auto iter = container.begin();    
    std::cout << iter.get();
    ++iter;

    for (; iter != container.end(); ++iter)
    {
        std::cout << ", " << *iter;
    }    
}

int main() 
{ 
    setlocale(LC_ALL, "Russian");   
    
    u_vector<int> vec;   //need here for extra_task_3
    check_u_vector(vec); //base_task + extra_task_1
    std::cout << "\n===============================================\n";
    
    u_list list;        //need here for extra_task_3
    check_u_list(list); //base_task
    std::cout << "\n===============================================\n";

    u_forward_list f_list;       //need here for extra_task_3
    check_u_forward_list(f_list); //extra_task_2
    std::cout << "\n===============================================\n";

    std::cout << "\n�������������� ������� 4. ����������� �������������� ��������� � ��������\n"; //extra_task_4
    check_iterator("vec", vec); 
    check_iterator("list", list);
    check_iterator("f_list", f_list);
    std::cout << "\n===============================================\n";

    check_move(vec, list, f_list); //extra_task_3
   
    return 0;
}