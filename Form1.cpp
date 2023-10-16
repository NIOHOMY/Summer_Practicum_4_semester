//----Forms----//
#include "pch.h"
#include "Form1.h"
#include "AddStudentForm.h"
#include"DeleteStudentForm.h"
#include "ViewAllStudentsForm.h"
//----TasksCollections----//
#include "DynamicLIST.h"
#include"TopLIST.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
//----TasksModels----//
//#include"NewTasksStudentModel.h"
//#include"TopStudentsModel.h"

std::string marshalString(String^ str) {
    IntPtr ptr = Marshal::StringToHGlobalAnsi(str);
    std::string result(static_cast<const char*>(ptr.ToPointer()));
    Marshal::FreeHGlobal(ptr);
    return result;
}

//-----------------------------------------------------------------------------------------------------//
/*
*/
void task1(MainLIST^% list, DynamicLIST% list1)
{
    auto check = [](StudentModel% S)
    {
        std::string grades; S.getGrades(grades);
        bool result = true;
        int length = grades.length() - 1;
        while (result && length >= 0)
        {
            if (isdigit(grades[length]) && grades[length] != '4') {
                result = false;
            }
            --length;
        }
        return result;
    };

    //LIST list1;

    MainptrNODE p_main_list = list->get_head();
    DynamicptrNODE p_last_checked = list1.get_head();

    bool first_good = false;
    while (p_main_list->next)
    {
        String^ surname = p_main_list->next->info.getSurname();
        double average_score = p_main_list->next->info.getAverageScore();

        NewTasksStudentModel S(surname, average_score);

        if (check(p_main_list->next->info))
        {
            list1.add_to_head(S);
            if (!first_good)
            {
                p_last_checked = p_last_checked->next;
                first_good = true;
            }
        }
        else
        {
            list1.add_after(p_last_checked, S);
        }
        p_main_list = p_main_list->next;
    }
    p_main_list = nullptr;
    p_last_checked = nullptr;
    delete p_main_list;
    delete p_last_checked;
}

/*
*/
void task2(MainLIST^% list, DynamicLIST% list2)
{
    auto check = [](NewTasksStudentModel% student1, NewTasksStudentModel% student2)
    {
        std::string surname1; student1.getSurname(surname1);
        std::string surname2; student2.getSurname(surname2);
        return surname1 < surname2;
    };

    //LIST list2;

    MainptrNODE p_main_list = list->get_head();
    DynamicptrNODE p_list2 = list2.get_head();
    if (p_main_list->next)
    {
        String^ surname = p_main_list->next->info.getSurname();
        double average_score = p_main_list->next->info.getAverageScore();
        NewTasksStudentModel S(surname, average_score);
        list2.add_to_head(S);
        p_main_list = p_main_list->next;
    }
    while (p_main_list->next)
    {
        String^ surname = p_main_list->next->info.getSurname();
        double average_score = p_main_list->next->info.getAverageScore();
        NewTasksStudentModel S(surname, average_score);

        p_list2 = list2.get_head();
        bool pasted = false;
        while (!pasted && p_list2->next)
        {
            if (check(p_list2->next->info, S))
            {
                list2.add_after(p_list2, S);
                pasted = true;
            }
            p_list2 = p_list2->next;
        }
        if (!pasted)
        {
            list2.add_to_tail(S);
        }
        p_main_list = p_main_list->next;
    }

    p_main_list = nullptr;
    delete p_main_list;
}

/*
*/
void task3(MainLIST^% list, BSTree% tree)
{
    //BSTree tree;

    MainptrNODE p_main_list = list->get_head();
    while (p_main_list->next)
    {
        String^ surname = p_main_list->next->info.getSurname();
        double average_score = p_main_list->next->info.getAverageScore();
        NewTasksStudentModel S(surname, average_score);

        tree.insert(S);

        p_main_list = p_main_list->next;
    }
    p_main_list = nullptr;
    delete p_main_list;
}

/*
*/
void task4(MainLIST^% list, AVLTree% tree)
{
    //AVLTree tree;

    MainptrNODE p_main_list = list->get_head();
    while (p_main_list->next)
    {
        String^ surname = p_main_list->next->info.getSurname();
        double average_score = p_main_list->next->info.getAverageScore();
        NewTasksStudentModel S(surname, average_score);

        tree.Insert(S);

        p_main_list = p_main_list->next;
    }
    p_main_list = nullptr;
    delete p_main_list;
}

/*
*/
void task5(MainLIST^% list, TopLIST% list3)
{
    double max_average_score = 2;
    MainptrNODE p_main_list = list->get_head();
    while (p_main_list->next)
    {
        if (max_average_score < p_main_list->next->info.getAverageScore())
        {
            max_average_score = p_main_list->next->info.getAverageScore();
        }
        p_main_list = p_main_list->next;
    }

    //LIST<TopStudentsModel> list3;
    p_main_list = list->get_head();
    while (p_main_list->next)
    {
        if (max_average_score == p_main_list->next->info.getAverageScore())
        {
            String^ surname, ^ grades;
            surname = p_main_list->next->info.getSurname();
            grades = p_main_list->next->info.getGrades();

            TopStudentsModel S(surname, grades);
            list3.add_to_tail(S);
        }
        p_main_list = p_main_list->next;
    }
    p_main_list = nullptr;
    delete p_main_list;
}

//-----------------------------------------------------------------//
void readData(std::string% data_file_name, MainLIST^% main_list, int% number_students)
{
    main_list->del_all_elem();
    std::ifstream file(data_file_name);
    std::string size;
    std::getline(file, size);

    number_students = std::stoi(size);

    std::getline(file, size);

    while (!file.eof())
    {
        StudentModel student(file);
        main_list->add_to_tail(student);
    }
    file.close();
}
void saveData(std::string% out_data_file_name, MainLIST^% main_list)
{
    MainptrNODE ptr = main_list->get_head();

    std::ofstream out_file(out_data_file_name);

    out_file << main_list->get_size() << std::endl;
    out_file << "--------------------";
    while (ptr->next)
    {
        ptr->next->info.writeStudentToOpenedFile(out_file);
        ptr = ptr->next;
    }
    out_file.close();
}
//-----------------------------------------------------------------------------------------------------//

//--------------------------------------------BSTreeViewHelpres-----------------------------------------------//

TreeNode^ CreateTreeNodeForBStree(BSTNODE^ node)
{
    String^ label = node->data.getSurname() + " (Average Score: " + node->data.getAverageScore().ToString("F2") + ")";
    return gcnew TreeNode(label);
}

void FillChildNodesForBStree(BSTNODE^ parentNode, TreeNode^ parentTreeNode, int height)
{
    if (parentNode == nullptr || height == 30)
        return;

    // Заполнение левого поддерева
    if (parentNode->p_left != nullptr)
    {
        TreeNode^ leftTreeNode = CreateTreeNodeForBStree(parentNode->p_left);
        parentTreeNode->Nodes->Add(leftTreeNode);
        FillChildNodesForBStree(parentNode->p_left, leftTreeNode, height + 1);
    }

    // Заполнение правого поддерева
    if (parentNode->p_right != nullptr)
    {
        TreeNode^ rightTreeNode = CreateTreeNodeForBStree(parentNode->p_right);
        parentTreeNode->Nodes->Add(rightTreeNode);
        FillChildNodesForBStree(parentNode->p_right, rightTreeNode, height + 1);
    }
}

void DisplayBSTree(MainLIST^% list, System::Windows::Forms::TreeView^ treeView)
{
    BSTree BStree;
    task3(list, BStree);

    treeView->Dock = System::Windows::Forms::DockStyle::Fill;

    // Заполнение TreeView
    if (BStree.getRoot() != nullptr)
    {
        TreeNode^ rootTreeNode = CreateTreeNodeForBStree(BStree.getRoot());
        treeView->Nodes->Add(rootTreeNode);
        FillChildNodesForBStree(BStree.getRoot(), rootTreeNode, 0);
    }
}

System::Void CppCLRWinformsProjekt::Form1::BStreeView(System::Object^ sender, System::EventArgs^ e)
{
    System::Windows::Forms::TreeView^ treeView1 = gcnew System::Windows::Forms::TreeView();
    BS->Controls->Clear();
    DisplayBSTree(% _main_list, /*this->*/treeView1);
    // Добавление элемента управления TreeView в TabPage
    BS->Controls->Add(treeView1);
    return System::Void();
}
//------------------------------------------------------------------------------------------------//
//--------------------------------------------AVLTreeViewHelpres-----------------------------------------------//

TreeNode^ CreateTreeNodeForAVLtree(AVLTreeNode^ node)
{
    String^ label = node->key.getSurname() + " (Average Score: " + node->key.getAverageScore().ToString("F2") + ")";
    return gcnew TreeNode(label);
}

void FillChildNodesForAVLtree(AVLTreeNode^ parentNode, TreeNode^ parentTreeNode, int height)
{
    if (parentNode == nullptr || height == 20)
        return;

    // Заполнение левого поддерева
    if (parentNode->leftChild != nullptr)
    {
        TreeNode^ leftTreeNode = CreateTreeNodeForAVLtree(parentNode->leftChild);
        parentTreeNode->Nodes->Add(leftTreeNode);
        FillChildNodesForAVLtree(parentNode->leftChild, leftTreeNode, height + 1);
    }

    // Заполнение правого поддерева
    if (parentNode->rightChild != nullptr)
    {
        TreeNode^ rightTreeNode = CreateTreeNodeForAVLtree(parentNode->rightChild);
        parentTreeNode->Nodes->Add(rightTreeNode);
        FillChildNodesForAVLtree(parentNode->rightChild, rightTreeNode, height + 1);
    }
}

void DisplayAVLTree(MainLIST^% list, System::Windows::Forms::TreeView^ treeView)
{
    AVLTree AVLtree;
    task4(list, AVLtree);
    treeView->Dock = System::Windows::Forms::DockStyle::Fill;

    // Заполнение TreeView
    if (AVLtree.getRoot() != nullptr)
    {
        TreeNode^ rootTreeNode = CreateTreeNodeForAVLtree(AVLtree.getRoot());
        treeView->Nodes->Add(rootTreeNode);
        FillChildNodesForAVLtree(AVLtree.getRoot(), rootTreeNode, 0);
    }
}
System::Void CppCLRWinformsProjekt::Form1::AVLtreeView(System::Object^ sender, System::EventArgs^ e)
{
    System::Windows::Forms::TreeView^ treeView2 = gcnew System::Windows::Forms::TreeView();
    AVL->Controls->Clear();
    DisplayAVLTree(% _main_list, /*this->*/treeView2);
    // Добавление элемента управления TreeView в TabPage
    AVL->Controls->Add(treeView2);
    return System::Void();
}
//------------------------------------------------------------------------------------------------//

System::Void CppCLRWinformsProjekt::Form1::tabPage1_Click(System::Object^ sender, System::EventArgs^ e)
{
    //------------------------------------------------------------------------//
    // Создание/Обновление DataGridView для страницы TabPage (l1)
    //------------------------------------------------------------------------//

    l1->Controls->Clear();
    DataGridView^ dataGridView1 = gcnew DataGridView();
    dataGridView1->Dock = DockStyle::Fill;
    this->l1->Controls->Add(dataGridView1);

    dataGridView1->Columns->Add("ColSurname1", "Surname");
    dataGridView1->Columns->Add("ColAverageScore1", "Average Score");

    DynamicLIST list1;
    task1(% _main_list, list1);

    DynamicptrNODE p1 = list1.get_head();
    while (p1->next)
    {
        array<String^>^ row = gcnew array<String^>(2);
        row[0] = p1->next->info.getSurname();
        row[1] = p1->next->info.getAverageScore().ToString();

        dataGridView1->Rows->Add(row);

        p1 = p1->next;
    }
    p1 = nullptr;

    //------------------------------------------------------------------------//
    // Создание/Обновление DataGridView для страницы TabPage (l2)
    //------------------------------------------------------------------------//

    l2->Controls->Clear();
    DataGridView^ dataGridView2 = gcnew DataGridView();
    dataGridView2->Dock = DockStyle::Fill;
    this->l2->Controls->Add(dataGridView2);

    dataGridView2->Columns->Add("ColSurname2", "Surname");
    dataGridView2->Columns->Add("ColAverageScore2", "Average Score");

    DynamicLIST list2;
    task2(% _main_list, list2);

    DynamicptrNODE p2 = list2.get_head();
    while (p2->next)
    {
        array<String^>^ row = gcnew array<String^>(2);
        row[0] = p2->next->info.getSurname();
        row[1] = p2->next->info.getAverageScore().ToString();

        dataGridView2->Rows->Add(row);

        p2 = p2->next;
    }

    //------------------------------------------------------------------------//
    // Создание/Обновление DataGridView для страницы TabPage (BST)
    //------------------------------------------------------------------------//

    BStreeView(sender, e);

    //------------------------------------------------------------------------//
    // Создание/Обновление DataGridView для страницы TabPage (AVL)
    //------------------------------------------------------------------------//

    AVLtreeView(sender, e);

    //------------------------------------------------------------------------//
    // Создание/Обновление DataGridView для страницы TabPage (Top)
    //------------------------------------------------------------------------//

    Top->Controls->Clear();
    DataGridView^ dataGridView3 = gcnew DataGridView();
    dataGridView3->Dock = DockStyle::Fill;
    this->Top->Controls->Add(dataGridView3);

    dataGridView3->Columns->Add("ColSurname3", "Surname");
    dataGridView3->Columns->Add("ColGrades", "Grades");

    TopLIST list3;
    task5(% _main_list, list3);

    TopptrNODE p3 = list3.get_head();
    while (p3->next)
    {
        array<String^>^ row = gcnew array<String^>(2);
        row[0] = p3->next->info.getSurname();
        row[1] = p3->next->info.getGrades();

        dataGridView3->Rows->Add(row);

        p3 = p3->next;
    }
    p3 = nullptr;
    //------------------------------------------------------------------------//

    return System::Void();
}

void CppCLRWinformsProjekt::Form1::RefreshOnClosed(System::Object^ sender, System::EventArgs^ e)
{
    // Ваш код, который должен выполниться при закрытии окна AddStudentForm
    CppCLRWinformsProjekt::Form1::tabPage1_Click(sender, e);
}
void CppCLRWinformsProjekt::Form1::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    CppCLR_WinformsProjekt1::AddStudentForm^ RegStud = gcnew CppCLR_WinformsProjekt1::AddStudentForm(% _main_list, gcnew System::Action<System::Object^, System::EventArgs^>(this, &CppCLRWinformsProjekt::Form1::RefreshOnClosed));  // Создание экземпляра объекта Form2

    RegStud->Show();
}

void CppCLRWinformsProjekt::Form1::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    CppCLR_WinformsProjekt2::DeleteStudentForm^ DelStud = gcnew CppCLR_WinformsProjekt2::DeleteStudentForm(% _main_list, gcnew System::Action<System::Object^, System::EventArgs^>(this, &CppCLRWinformsProjekt::Form1::RefreshOnClosed));  // Создание экземпляра объекта Form2
    DelStud->Show();
    CppCLRWinformsProjekt::Form1::tabPage1_Click(sender, e);
}

System::Void CppCLRWinformsProjekt::Form1::button_OpenFile_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Title = "Выберите файл";
    openFileDialog->Filter = "Текстовые файлы (*.txt)|*.txt";

    // Открываем диалоговое окно выбора файла
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Получаем путь к выбранному файлу
        String^ filepath = openFileDialog->FileName;

        // Преобразуем строку пути в std::string
        std::string filepathStd = marshalString(filepath);

        //GlobalContainer GC;
        readData(filepathStd, % _main_list, number_of_students);
        Console::WriteLine(gcnew String(filepathStd.c_str()));
        CppCLRWinformsProjekt::Form1::tabPage1_Click(sender, e);
    }
    return System::Void();
}

System::Void CppCLRWinformsProjekt::Form1::View_Click(System::Object^ sender, System::EventArgs^ e)
{
    CppCLR_WinformsProjekt1::ViewAllStudentsForm^ ViewStud;

    ViewStud = gcnew CppCLR_WinformsProjekt1::ViewAllStudentsForm(% _main_list);

    ViewStud->Show();
}

System::Void CppCLRWinformsProjekt::Form1::button_SaveFile_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Создание диалогового окна сохранения файла
    SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();

    // Настройка фильтра файлов
    saveFileDialog1->Filter = "Текстовые файлы (*.txt)|*.txt";
    saveFileDialog1->FilterIndex = 1;
    saveFileDialog1->RestoreDirectory = true;

    if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        // Получение имени выбранного файла
        String^ fileName = saveFileDialog1->FileName;

        // Преобразование типа String^ в std::string
        std::string filePath = marshalString(fileName);

        saveData(filePath, % _main_list);
    }
    // Открытие файла для записи
    return System::Void();
}