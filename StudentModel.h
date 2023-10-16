#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <regex>
using namespace System::Text::RegularExpressions;

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

ref class StudentModel
{
    String^ _name;
    String^ _surname;
    String^ _grades;
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
    void checkStringLength(std::string% str)
    {
        if (str.length() > 20) {
            str = str.substr(0, 20);
        }
    }
    String^ ParseString(String^ input)
    {
        // Создаем регулярное выражение для поиска цифр от 2 до 5
        String^ pattern = "[2-5]";
        Regex^ regex = gcnew Regex(pattern);

        // Используем StringBuilder для эффективной конкатенации строк
        StringBuilder^ result = gcnew StringBuilder();

        // Находим все совпадения с регулярным выражением во входной строке
        MatchCollection^ matches = regex->Matches(input);

        // Объединяем найденные цифры через пробел
        for (int i = 0; i < matches->Count; i++)
        {
            result->Append(matches[i]->Value);
            if (i < matches->Count - 1)
            {
                result->Append(" ");
            }
        }

        // Возвращаем полученный результат
        return result->ToString();
    }
public:
    //-----------------------//
    StudentModel()
    {
        _name = "-";
        _surname = "-";
        _grades = "0";
        _average_score = 0.0;
    }
    StudentModel(String^& name, String^& surname, String^& grades, double& average_score)
    {
        _name = name;
        _surname = surname;

        _grades = grades;
        _average_score = average_score;
    }
    StudentModel(String^& name, String^& surname, String^& grades)
    {
        _name = name;
        _surname = surname;

        setGrades(grades);
    }
    StudentModel(std::ifstream& file)
    {
        if (file.is_open())
        {
            // Чтение имени
            std::string name;
            std::getline(file, name);
            checkStringLength(name);
            _name = ConvertToManagedString(name);

            // Чтение фамилии
            std::string surname;
            std::getline(file, surname);
            checkStringLength(surname);
            _surname = ConvertToManagedString(surname);

            // Чтение оценок
            std::string grades;
            std::getline(file, grades);

            String^ sgrades = ConvertToManagedString(grades);
            sgrades = ParseString(sgrades);
            // установка оценок и ср. балла
            setGrades(sgrades);

            //разделитель (20 x '-') "--------------------" ;
            std::getline(file, name);
        }
        else
        {
            _name = "-";
            _surname = "-";
            _grades = "0";
            _average_score = 0.0;
        }
    }

    StudentModel(const StudentModel% other)
    {
        _name = other._name;
        _surname = other._surname;

        _grades = other._grades;
        _average_score = other._average_score;
    }
    //-----------------------//

    // SET / GET //
    void setNewStudent(const StudentModel% other)
    {
        _name = other._name;
        _surname = other._surname;

        _grades = other._grades;
        _average_score = other._average_score;
    }
    void setName(String^& name)
    {
        _name = name;
    }
    void setSurname(String^& surname)
    {
        _surname = surname;
    }
    void setGrades(String^& grades)
    {
        _grades = grades;
        std::string tmp = marshalString(grades);
        double new_average_score = 0;
        double counter = 0;
        for (auto i : tmp)
        {
            switch (i)
            {
            case '2':
            {
                new_average_score += 2;
                ++counter;
                break;
            }
            case '3':
            {
                new_average_score += 3;
                ++counter;
                break;
            }
            case '4':
            {
                new_average_score += 4;
                ++counter;
                break;
            }
            case '5':
            {
                new_average_score += 5;
                ++counter;
                break;
            }
            default:
                break;
            }
        }
        _average_score = (new_average_score / counter);
    }
    String^ getName()
    {
        return _name;
    }
    void getName(std::string& name)
    {
        name = marshalString(_name);
    }
    String^ getSurname()
    {
        return _surname;
    }
    void getSurname(std::string& surname)
    {
        surname = marshalString(_surname);
    }
    String^ getGrades()
    {
        return _grades;
    }
    void getGrades(std::string& grades)
    {
        grades = marshalString(_grades);
    }
    double getAverageScore()
    {
        return _average_score;
    }
    //-----------------------//
    void writeStudentToOpenedFile(std::ofstream& output_file)
    {
        // Открываем файл для записи

        if (output_file.is_open())
        {
            // Записываем имя и фамилию
            std::string tmp = marshalString(_name);
            output_file << std::endl << tmp << std::endl;
            tmp = marshalString(_surname);
            output_file << tmp << std::endl;

            // Записываем оценки
            tmp = marshalString(_grades);
            output_file << tmp << std::endl;

            // Записываем разделитель
            output_file << "--------------------";

            //std::cout << "Студент успешно записан в файл." << std::endl;
        }
        else
        {
            std::cerr << "Ошибка открытия файла " << std::endl;
        }
    }
    void operator = (const StudentModel% other)
    {
        _name = other._name;
        _surname = other._surname;

        _grades = other._grades;
        _average_score = other._average_score;
    }
    bool operator < (const StudentModel% c)
    {
        return _average_score < c._average_score;
    }
    bool operator > (const StudentModel% c)
    {
        return _average_score > c._average_score;
    }
    bool operator <= (const StudentModel% c)
    {
        return _average_score <= c._average_score;
    }
    bool operator >= (const StudentModel% c)
    {
        return _average_score >= c._average_score;
    }
    bool operator == (const StudentModel% c)
    {
        return _average_score == c._average_score;
    }
};
