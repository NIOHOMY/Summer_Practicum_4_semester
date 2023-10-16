#pragma once
#include <Windows.h>
#include <string>
//#include<functional>
//#include<tuple>
//#include <vector>
#include "StudentModel.h"
#include "MainLIST.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Windows::Forms;
namespace CppCLR_WinformsProjekt1 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ViewAllStudentsForm : public System::Windows::Forms::Form
    {
    private: MainLIST^ some_list;
    public:
        ViewAllStudentsForm(void)
        {
            //InitializeComponent();
            Text = "All Student`s view";
            Width = 500;
            Height = 300;

            // Создание и настройка DataGridView
            dataGridView1 = gcnew DataGridView();
            dataGridView1->Dock = DockStyle::Fill;
            dataGridView1->ReadOnly = true;
            Controls->Add(dataGridView1);

            // Создание и заполнение таблицы данными
            DataTable^ dataTable = gcnew DataTable();
            dataTable->Columns->Add("Name", String::typeid);
            dataTable->Columns->Add("Surname", String::typeid);
            dataTable->Columns->Add("Grades", String::typeid);
            dataTable->Columns->Add("Average Scores", Double::typeid);

            //// Пример данных студентов
            //std::vector< std::tuple <std::string, std::string, std::string, double> > students = {
            //	std::make_tuple("Bob","Fesg","4 4 5 5 5", 4.5),
            //	std::make_tuple("Bobsdg","Fesgsdg","4 5 5 5 5", 4.75),
            //	std::make_tuple("Afsaf","AFesg","4 4 5 5 4", 4.54)
            //};

            //// Заполнение таблицы данными из вектора студентов
            //for each (auto student in students)
            //{
            //	DataRow^ row = dataTable->NewRow();
            //	row["Name"] = gcnew String(std::get<0>(student).c_str());
            //	row["Surname"] = gcnew String(std::get<1>(student).c_str());
            //	row["Grades"] = gcnew String(std::get<2>(student).c_str());
            //	row["Average Scores"] = std::get<3>(student);
            //	dataTable->Rows->Add(row);
            //}

            // Присвоение таблицы в качестве источника данных DataGridView
            dataGridView1->DataSource = dataTable;
        }

        ViewAllStudentsForm(MainLIST^ main_list)
        {
            some_list = main_list;
            //InitializeComponent();
            Text = "All Student`s view";
            Width = 450;
            Height = 500;

            // Создание и настройка DataGridView
            dataGridView1 = gcnew DataGridView();
            dataGridView1->Dock = DockStyle::Fill;
            dataGridView1->ReadOnly = true;
            Controls->Add(dataGridView1);

            // Создание и заполнение таблицы данными
            DataTable^ dataTable = gcnew DataTable();
            dataTable->Columns->Add("Name", String::typeid);
            dataTable->Columns->Add("Surname", String::typeid);
            dataTable->Columns->Add("Grades", String::typeid);
            dataTable->Columns->Add("Average Scores", Double::typeid);

            MainptrNODE p = some_list->get_head();
            while (p->next)
            {
                DataRow^ row = dataTable->NewRow();
                row["Name"] = gcnew String(p->next->info.getName());
                row["Surname"] = gcnew String(p->next->info.getSurname());
                row["Grades"] = gcnew String(p->next->info.getGrades());
                row["Average Scores"] = p->next->info.getAverageScore();
                dataTable->Rows->Add(row);
                p = p->next;
            }

            // Присвоение таблицы в качестве источника данных DataGridView
            dataGridView1->DataSource = dataTable;
        }

    protected:

        ~ViewAllStudentsForm()
        {
            some_list = nullptr;
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ AllViewName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ AllViewSurname;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ AllViewGrades;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ AllViewAv;
    protected:

    protected:

    private:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
        }
#pragma endregion
    };
}
