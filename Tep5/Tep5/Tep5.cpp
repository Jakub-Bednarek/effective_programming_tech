// Tep5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CMySmartPointer.h"
#include "CTab.h"
#include "CTable.h"

void smart_pointers_test();
void ctab_test();
void ctable_test();

int main()
{
    smart_pointers_test();
    ctab_test();
    ctable_test(); 
}

void smart_pointers_test()
{
    std::cout << "SMART POINTERS TEST\n\n";

    CMySmartPointer<int> first_pointer(new int(25));

    std::cout << "Value of first_pointer: " << *first_pointer << '\n';

    CMySmartPointer<int> copy_constructed_pointer(first_pointer);

    std::cout << "Value of copy_constructed_pointer: " << *copy_constructed_pointer << '\n';

    {
        CMySmartPointer<int> inner_scope_copy_pointer(first_pointer);
        std::cout << "Value of inner_scope_copy_pointer: " << *inner_scope_copy_pointer << '\n';
    }

    std::cout << "Value of first_pointer after deletion of inner_scope_copy_pointer: " << *first_pointer << '\n';

    {
        CMySmartPointer<int> inner_scope_assign_pointer(new int(50));
        std::cout << "Value of inner_scope_assign_pointer before copy assignment operation: " << *inner_scope_assign_pointer << '\n';

        inner_scope_assign_pointer = copy_constructed_pointer;
        std::cout << "Value of inner_scope_assign_pointer after copy assignment operation: " << *inner_scope_assign_pointer << '\n';
    }

    std::cout << "Value of copy_constructed_pointer after deletion of innser_scope_assign_pointer: " << *copy_constructed_pointer << '\n';

    //Self assignment operation
    first_pointer = first_pointer;
    std::cout << "Value of first_pointer after self assignment operation: " << *first_pointer << '\n';

    /*int x = 15;
    {
        CMySmartPointer<int> static_try(&x);
        std::cout << *static_try << '\n';
    }*/

    //Jeœli spróbujemy zaalokowaæ nasz smart pointer wrzucaj¹c do niego dane zaalokowane statycznie napotkamy problem w momencie w którym zosta³by wywo³any destruktor smart pointer, poniewa¿ bêdziemy próbowali usun¹æ dane zaalokowane na stacku u¿ywaj¹c operatora delete
}

void ctab_test()
{
    std::cout << "\n\nCTAB TEST\n\n";

    CTab first_tab;
    first_tab.v_fill_random();
    first_tab.v_print_tab("Content of first_tab:");

    CTab copy_constructed_tab(first_tab);
    copy_constructed_tab.v_print_tab("Content of copy_constructed_tab:");
    copy_constructed_tab.b_set_size(5);
    copy_constructed_tab.v_print_tab("Content of copy_constructed_tab after size change:");
    first_tab.v_print_tab("Content of first_tab after being used in copy constructor:");

    CTab copy_assigned_tab;
    copy_assigned_tab = copy_constructed_tab;
    copy_assigned_tab.v_print_tab("Content of copy_assigned_tab after using copy assignment operator:");

    //Self assignment test
    copy_assigned_tab = copy_assigned_tab;
    copy_assigned_tab.v_print_tab("Content of copy_assigned_tab after trying to self assign:");

    CTab move_constructed_tab(std::move(first_tab));
    move_constructed_tab.v_print_tab("Content of move_constructed_tab:");
    first_tab.v_print_tab("Content of first_tab after being used in move constructor:");

    CTab move_assigned_tab;
    move_assigned_tab = std::move(copy_constructed_tab);
    move_assigned_tab.v_print_tab("Content of move_assigned_tab:");
    copy_constructed_tab.v_print_tab("Contet of copy_constructed_tab after using move assignment operator:");
}

void ctable_test()
{
    std::cout << "\n\nCTABLE TEST\n\n";

    CTable first_table;
    first_table.v_fill_random();
    first_table.v_print("Content of first_table:");

    CTable copy(first_table);
    copy.v_print("Content of copy: ");

    CTable moved(std::move(first_table));
    moved.v_print("Content of moved:");
    first_table.v_print("Content of first after being moved:");

    moved.b_set_new_size(7);
    moved.v_fill_random();
    moved.v_print("Content of moved after resizing:");

    std::cout << "Length: " << moved.i_get_table_length() << '\n';
    moved.v_set_value_at(5, 155555);
    moved.v_print("Content of moved after changing value:");

    CTable assignMoved("Assign_test", 12);
    assignMoved.v_fill_random();
    assignMoved.v_print("Content of assignMoved:");
    assignMoved = std::move(copy);
    assignMoved.v_print("Content of assignMoved after using move assignment operator:");
    copy.v_print("Content of copy after being used by move assignment operator:");

    CTable concat;
    concat = std::move(moved);
    concat.v_print("Content of concated moved and assignMoved CTables:");
}