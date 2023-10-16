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

ref class NewTasksStudentModel
{
private:
    String^ _surname;
    double _average_score;

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
    NewTasksStudentModel()
    {
        _surname = "-";
        _average_score = 0.0;
    }
    NewTasksStudentModel(String^ surname, double& average_score)
    {
        _surname = surname;

        _average_score = average_score;
    }
    NewTasksStudentModel(const NewTasksStudentModel% S)
    {
        _surname = S._surname;

        _average_score = S._average_score;
    }

    //------------------------------------------------------------//
    void setNewStudent(const NewTasksStudentModel% S)
    {
        _surname = S._surname;

        _average_score = S._average_score;
    }
    void setSurname(String^ surname)
    {
        _surname = surname;
    }
    void setAverageScore(double& average_score)
    {
        _average_score = average_score;
    }
    String^ getSurname()
    {
        return _surname;
    }
    void getSurname(std::string& surname)
    {
        surname = marshalString(_surname);
    }
    double getAverageScore()
    {
        return _average_score;
    }
    //------------------------------------------------------------//
    bool operator < (const NewTasksStudentModel c)
    {
        return _average_score < c._average_score;
    }
    bool operator > (const NewTasksStudentModel c)
    {
        return _average_score > c._average_score;
    }
    bool operator <= (const NewTasksStudentModel c)
    {
        return _average_score <= c._average_score;
    }
    bool operator >= (const NewTasksStudentModel c)
    {
        return _average_score >= c._average_score;
    }
    bool operator == (const NewTasksStudentModel c)
    {
        return _average_score == c._average_score;
    }
    void operator =(const NewTasksStudentModel c)
    {
        _surname = c._surname;

        _average_score = c._average_score;
    }
    //------------------------------------------------------------//
};
