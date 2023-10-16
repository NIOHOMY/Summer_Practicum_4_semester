#pragma once
#include <functional>
#include <fstream>
#include<iostream>
#include<functional>
#include"StudentModel.h"

using TInfo = StudentModel;
ref class MainNODE
{
public:
    TInfo info;
    MainNODE^ next;
    MainNODE() {}
    MainNODE(TInfo% info, MainNODE^ ptr) : next(ptr)
    {
        (this->info).setNewStudent(info);
    }
    ~MainNODE()
    {
        next = nullptr;
    }
};

using MainptrNODE = MainNODE^;

ref class MainLIST
{
private:
    MainptrNODE head, tail;
    size_t size;
    void adding_by_pointer(MainptrNODE% ptr, TInfo% elem)
    {
        MainptrNODE p = gcnew MainNODE(elem, ptr);
        ptr = p;
    }
    void deleting_by_pointer(MainptrNODE% ptr)
    {
        MainptrNODE p = ptr;
        ptr = p->next;
        delete p;
    }
public:
    //конструктор
    MainLIST()
    {
        head = gcnew MainNODE;
        tail = head;
        size = 0;
    }
    //деструктор
    ~MainLIST()
    {
        while (!empty())
            del_from_head();
        delete head;
    }

    MainptrNODE get_head()//никогда не меняется
    {
        return head;
    }

    TInfo get_first()
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
    void add_to_head(TInfo elem)
    {
        adding_by_pointer(head->next, elem);
        if (head == tail)
            tail = tail->next;
        ++size;
    }
    void add_to_tail(TInfo elem)
    {
        adding_by_pointer(tail->next, elem);
        tail = tail->next;
        ++size;
    }//pushback метод
    void add_after(MainptrNODE ptr, TInfo elem)
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
    void del_after(MainptrNODE ptr)
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

    MainptrNODE get_tail()
    {
        return tail;
    }
    void set_tail(MainptrNODE p)
    {
        tail = p;
    }
};