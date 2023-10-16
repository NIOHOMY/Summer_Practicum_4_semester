#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<fstream>

#include <string>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

ref class TopStudentsModel
{
private:
    String^ _surname;
    String^ _grades;

    String^ ConvertToManagedString(const std::string& str)
    {
        IntPtr ptr = Marshal::StringToHGlobalUni(gcnew String(str.c_str()));
        String^ managedString = Marshal::PtrToStringUni(ptr);
        Marshal::FreeHGlobal(ptr);
        return managedString;
    }
    std::string marshalString(String^ str) {
        IntPtr ptr = Marshal::StringToHGlobalAnsi(str);
        std::string result(static_cast<const char*>(ptr.ToPointer()));
        Marshal::FreeHGlobal(ptr);
        return result;
    }

public:
    //------------------------------------------------------------//
    TopStudentsModel()
    {
        _surname = "-";

        _grades = "-";
    }
    TopStudentsModel(String^ surname, String^ grades)
    {
        _surname = surname;

        _grades = grades;
    }
    TopStudentsModel(const TopStudentsModel% S)
    {
        _surname = S._surname;

        _grades = S._grades;
    }

    //------------------------------------------------------------//
    void setNewStudent(const TopStudentsModel% S)
    {
        _surname = S._surname;

        _grades = S._grades;
    }
    void setSurname(String^ surname)
    {
        _surname = surname;
    }
    void setAverageScore(String^ grades)
    {
        _grades = grades;
    }
    String^ getSurname()
    {
        return _surname;
    }
    void getSurname(std::string% surname)
    {
        surname = marshalString(_surname);
    }
    String^ getGrades()
    {
        return _grades;
    }
    void getGrades(std::string% grades)
    {
        grades = marshalString(_grades);
    }
    //------------------------------------------------------------//
    bool operator == (const TopStudentsModel c)
    {
        return ((_grades == c._grades) && (_surname == c._surname));
    }
    void operator =(const TopStudentsModel c)
    {
        _surname = c._surname;

        _grades = c._grades;
    }
    //------------------------------------------------------------//
};
