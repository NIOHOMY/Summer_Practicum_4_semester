#pragma once
#include <functional>
#include <fstream>
#include<iostream>
#include<functional>
#include"NewTasksStudentModel.h"

using DynamicTInfo = NewTasksStudentModel;
ref class DynamicNODE
{
public:
    DynamicTInfo info;
    DynamicNODE^ next;
    DynamicNODE() {}
    DynamicNODE(DynamicTInfo% info, DynamicNODE^ ptr) : next(ptr)
    {
        (this->info).setNewStudent(info);
    }
    ~DynamicNODE()
    {
        next = nullptr;
    }
};

using DynamicptrNODE = DynamicNODE^;

ref class DynamicLIST
{
private:
    DynamicptrNODE head, tail;
    size_t size;
    void adding_by_pointer(DynamicptrNODE% ptr, DynamicTInfo% elem)
    {
        DynamicptrNODE p = gcnew DynamicNODE(elem, ptr);
        ptr = p;
    }
    void deleting_by_pointer(DynamicptrNODE% ptr)
    {
        DynamicptrNODE p = ptr;
        ptr = p->next;
        delete p;
    }
public:
    //конструктор
    DynamicLIST()
    {
        head = gcnew DynamicNODE;
        tail = head;
        size = 0;
    }
    //деструктор
    ~DynamicLIST()
    {
        while (!empty())
            del_from_head();
        delete head;
    }

    DynamicptrNODE get_head()//никогда не меняется
    {
        return head;
    }

    DynamicTInfo get_first()
    {
        return  head->next->info;
    }
    size_t get_size()
    {
        return size;
    }
    bool empty()
    {
        return !head->next;
    }
    void add_to_head(DynamicTInfo elem)
    {
        adding_by_pointer(head->next, elem);
        if (head == tail)
            tail = tail->next;
        ++size;
    }
    void add_to_tail(DynamicTInfo elem)
    {
        adding_by_pointer(tail->next, elem);
        tail = tail->next;
        ++size;
    }//pushback метод
    void add_after(DynamicptrNODE ptr, DynamicTInfo elem)
    {
        if (ptr)
        {
            adding_by_pointer(ptr->next, elem);
            if (ptr == tail)
                tail = tail->next;
            ++size;
        }
    }

    void del_from_head()
    {
        if (head->next)//!empty();
        {
            deleting_by_pointer(head->next);
            if (!head->next)//empty()
            {
                tail = head;
            }
            --size;
        }
    }
    void del_after(DynamicptrNODE ptr)
    {
        if (ptr && ptr->next)
        {
            if (ptr->next == tail)
                tail = ptr;
            deleting_by_pointer(ptr->next);
            if (empty())
                tail = head;
            --size;
        }
    }
    void del_all_elem()
    {
        while (!empty())
        {
            del_from_head();
        }
    }

    DynamicptrNODE get_tail()
    {
        return tail;
    }
    void set_tail(DynamicptrNODE p)
    {
        tail = p;
    }
};