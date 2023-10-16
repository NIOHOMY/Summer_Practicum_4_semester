#pragma once
#include <functional>
#include <fstream>
#include<iostream>
#include<functional>
#include"TopStudentsModel.h"

using TopTInfo = TopStudentsModel;
ref class TopNODE
{
public:
    TopTInfo info;
    TopNODE^ next;
    TopNODE() {}
    TopNODE(TopTInfo% info, TopNODE^ ptr) : next(ptr)
    {
        (this->info).setNewStudent(info);
    }
    ~TopNODE()
    {
        next = nullptr;
    }
};

using TopptrNODE = TopNODE^;

ref class TopLIST
{
private:
    TopptrNODE head, tail;
    size_t size;
    void adding_by_pointer(TopptrNODE% ptr, TopTInfo% elem)
    {
        TopptrNODE p = gcnew TopNODE(elem, ptr);
        ptr = p;
    }
    void deleting_by_pointer(TopptrNODE% ptr)
    {
        TopptrNODE p = ptr;
        ptr = p->next;
        delete p;
    }
public:
    //конструктор
    TopLIST()
    {
        head = gcnew TopNODE;
        tail = head;
        size = 0;
    }
    //деструктор
    ~TopLIST()
    {
        while (!empty())
            del_from_head();
        delete head;
    }

    TopptrNODE get_head()//никогда не меняется
    {
        return head;
    }

    TopTInfo get_first()
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
    void add_to_head(TopTInfo elem)
    {
        adding_by_pointer(head->next, elem);
        if (head == tail)
            tail = tail->next;
        ++size;
    }
    void add_to_tail(TopTInfo elem)
    {
        adding_by_pointer(tail->next, elem);
        tail = tail->next;
        ++size;
    }//pushback метод
    void add_after(TopptrNODE ptr, TopTInfo elem)
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
    void del_after(TopptrNODE ptr)
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

    TopptrNODE get_tail()
    {
        return tail;
    }
    void set_tail(TopptrNODE p)
    {
        tail = p;
    }
};