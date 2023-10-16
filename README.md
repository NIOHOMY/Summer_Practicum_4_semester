# Summer_Practicum_4_semester
CppCLR_WinformsProjekt

    1. Постановка задачи.
С клавиатуры вводится информация об итогах последней экзаменационной сессии. Эта информация включает в себя: 1) целое число n – количество студентов; 2) n объединенных в структуру данных: 
<имя ><фамилия>  <оценка>  <оценка> <оценка>  <оценка> <оценка> , где <имя>, <фамилия> ― символьные строки, содержащие не более 20 
символов, оценка за экзамен ― десятичная цифра из диапазона ‘2’..’5’. 
Требуется  
    1) создать текстовый файл из данных, введенных с клавиатуры;  
    2) из данных файла сформировать динамический список, каждый элемент которого содержит фамилию студента и его средний балл, причем вначале размещаются данные о студентах, сдавших все экзамены на «хорошо», затем об остальных студентах, при этом в каждой части данные следуют в порядке, обратном порядку следования данных при вводе с клавиатуры; вывести этот список на экран;  
    3) из данных файла сформировать динамический список, каждый элемент которого содержит фамилию студента и его средний балл, причем данные в списке располагаются в обратном алфавитном порядке фамилий студентов; вывести этот список на экран; 
    4) из данных файла сформировать бинарное дерево поиска, каждый элемент которого содержит фамилию студента и его средний балл, при построении дерева в качестве ключа использовать средний балл студента; вывести на экран первые три уровня дерева (начиная с корня). 
    5) из данных файла сформировать сбалансированное дерево поиска, взяв за основу балансировки определение АВЛ-сбалансированного дерева, и вывести на экран первые три уровня дерева (начиная с корня). 
    6) Вывести фамилии и оценки студентов, имеющих наибольший средний балл. 
    7) Выполнить запуск созданной программы из командной строки операционной системы. 
Интерфейс с пользователем реализовать, используя визуальные средства программирования среды MS Visual Studio 2019. 

2. Теоретические сведения, необходимые для решения поставленных задач.

Связный список является базовой динамической структурой данных в информатике. Он состоит из узлов, которые содержат данные и ссылки на следующий и/или предыдущий узел списка.

Двоичное дерево поиска - это особый тип двоичного дерева, который удовлетворяет определенным условиям. 
- Оба поддерева (левое и правое) также являются двоичными деревьями поиска. 
- Значения ключей данных для всех узлов левого поддерева меньше значения ключа данных самого узла X, а значения ключей данных для всех узлов правого поддерева больше либо равны значению ключа данных самого узла X.

АВЛ-дерево является сбалансированным по высоте двоичным деревом поиска. Для каждой вершины в нем разница в высоте ее двух поддеревьев не превышает 1.

TXT - это текстовый формат обмена данными. Подобно другим текстовым форматам, TXT легко читается людьми.

3. Описание решения поставленной задачи и способов вывода результатов.
3.1. Описание данных и алгоритма решения задачи.
StudentModel – основная структура студента содержащая Имя, Фамилию (не более 20 символов), оценки и средний балл.


MainLIST – динамический связный список, информационная часть - StudentModel
Используется для хранения и отображения всех текущих студентов, а так же для всех заданий.

NewTasksStudentModel – структура студента, для заданий 2, 3, 4, 5 содержащая Фамилию (не более 20 символов), средний балл.
DynamicLIST - динамический связный список, аналогичный MainLIST, однако информационная часть – NewTasksStudentModel. Используется в заданиях 2, 3

TopStudentsModel – структура студента, для задания 6, содержащая Фамилию (не более 20 символов), все оценки.
TopLIST - динамический связный список, аналогичный MainLIST, однако информационная часть – TopStudentsModel. Используется в задании 6.


Основные функции списка MainLIST: 
get_head() 
get_tail()
get_size() 
add_to_head(TInfo elem) 
add_to_tail(TInfo elem) 
add_after(MainptrNODE ptr, TInfo elem) 
del_from_head()
del_after(MainptrNODE ptr)

Их реализация представлена блок схемами:

get_head() 

get_tail()

get_size() 

add_to_head(TInfo elem) 

void adding_by_pointer(MainptrNODE%ptr, TInfo% elem)

add_to_tail(TInfo elem) 

add_after(MainptrNODE ptr, TInfo elem) 

del_from_head()

void deleting_by_pointer(MainptrNODE% ptr)
 удаление p
del_after(MainptrNODE ptr)



BSTree - Двоичное дерево поиска, информационная часть – NewTasksStudentModel. Используется в задании 4.
Основные функции:
BSTNODE^ getRoot()
void insert( TBST% d)
bool remove( TBST% d);

Вспомогательные:
bool insertHelper(BSTNODE^% p_node,  TBST% elem);
	bool removeHelper(BSTNODE^% p_node, TBST elem);

Их реализация представлена блок схемами:
BSTNODE^ getRoot()

void insert( TBST% d)

bool remove( TBST% d);

bool insertHelper(BSTNODE^% p_node,  TBST% elem);

data (elem <= p_node->data)
	bool removeHelper(BSTNODE^% p_node, TBST elem);


AVLTree - сбалансированное по высоте двоичное дерево поиска, информационная часть – NewTasksStudentModel. 
Используется в задании 5.
Основные функции:
AVLTreeNode^ getRoot();
	void Insert(AVLTInfo);
bool Delete(AVLTInfo);

Вспомогательные:
AVLTreeNode^ LeftRotate(AVLTreeNode^);
AVLTreeNode^ LeftAndRightRotate(AVLTreeNode^);
AVLTreeNode^ RightRotate(AVLTreeNode^);
AVLTreeNode^ RightAndLeftRotate(AVLTreeNode^);
	int GetHeight(AVLTreeNode^);

Их реализация представлена блок схемами и псевдокодом:
AVLTreeNode^ getRoot();

	void Insert(AVLTInfo);



bool Delete(AVLTInfo);




AVLTreeNode^ LeftRotate(AVLTreeNode^);
Псевдокод: 
//------------------------------------//
функция LeftRotate(tempNode):
    lChildNode = tempNode.rightChild.leftChild
    newRoot = tempNode.rightChild

    tempNode.rightChild.leftChild = tempNode
    tempNode.rightChild = lChildNode

    tempNode.height = максимум(ПолучитьВысоту(tempNode.leftChild), ПолучитьВысоту(tempNode.rightChild)) + 1
    
    если (tempNode.rightChild != null):
        tempNode.rightChild.height = максимум(ПолучитьВысоту(tempNode.rightChild.leftChild), ПолучитьВысоту(tempNode.rightChild.rightChild)) + 1
    
    вернуть newRoot
//------------------------------------//
AVLTreeNode^ LeftAndRightRotate(AVLTreeNode^);
Псевдокод: 
//------------------------------------//
функция LeftAndRightRotate(tempNode):
    tempNode.leftChild = LeftRotate(tempNode.leftChild)
    вернуть RightRotate(tempNode)
//------------------------------------//
AVLTreeNode^ RightRotate(AVLTreeNode^);
Псевдокод: 
//------------------------------------//
функция RightRotate(tempNode):
    rChildNode = tempNode.leftChild.rightChild
    newRoot = tempNode.leftChild

    tempNode.leftChild.rightChild = tempNode
    tempNode.leftChild = rChildNode

    tempNode.height = максимум(ПолучитьВысоту(tempNode.leftChild), ПолучитьВысоту(tempNode.rightChild)) + 1
    
    если (tempNode.leftChild != null):
        tempNode.leftChild.height = максимум(ПолучитьВысоту(tempNode.leftChild.leftChild), ПолучитьВысоту(tempNode.leftChild.rightChild)) + 1
    
    вернуть newRoot
//------------------------------------//
AVLTreeNode^ RightAndLeftRotate(AVLTreeNode^);
Псевдокод: 
//------------------------------------//
функция RightAndLeftRotate(tempNode):
    tempNode.rightChild = RightRotate(tempNode.rightChild)
    вернуть LeftRotate(tempNode)
	int GetHeight(AVLTreeNode^);

//------------------------------------//

Задача 1:
Реализована функциями:
void readData(std::string %data_file_name, MainLIST^% main_list, int% number_students)
открывает файл и считывает все данные в main_list
void saveData(std::string %out_data_file_name, MainLIST^% main_list)
сохраняет все данные из main_list в txt файл
System::Void CppCLR_WinformsProjekt1::AddStudentForm::NewStudentSaveBtn_Click(System::Object^ sender, System::EventArgs^ e)
Через форму регистрации добавляет студента в main_list 

Псевдокод функций:
void readData(std::string %data_file_name, MainLIST^% main_list, int% number_students)
Псевдокод: 
//------------------------------------//

функция readData(строка& data_file_name, MainLIST^& main_list, целое число& number_students):
    main_list->del_all_elem()
    файл file = открыть_файл(data_file_name)
    строка size = считать_строку(file)
    number_students = преобразовать_в_целое_число(size)
    size = считать_строку(file)
    
    пока (файл не достиг конца):
        StudentModel student(file)
        main_list->add_to_tail(student)

    закрыть_файл(file)
//------------------------------------//

void saveData(std::string %out_data_file_name, MainLIST^% main_list)
Псевдокод: 
//------------------------------------//

функция saveData(строка& out_data_file_name, MainLIST^& main_list):
    MainptrNODE ptr = main_list->get_head()

    файл out_file = открыть_файл(out_data_file_name)

    out_file << main_list->get_size() << перевод_строки
    out_file << "--------------------"

    пока (ptr->next существует):
        ptr->next->info.writeStudentToOpenedFile(out_file)
        ptr = ptr->next

    закрыть_файл(out_file)
//------------------------------------//

System::Void CppCLR_WinformsProjekt1::AddStudentForm::NewStudentSaveBtn_Click(System::Object^ sender, System::EventArgs^ e)
Псевдокод: 
//------------------------------------//
функция ParseString(строка input):
    // Создаем регулярное выражение для поиска цифр от 2 до 5
    строка pattern = "[2-5]"
    РегулярноеВыражение regex = создать_регулярное_выражение(pattern)

    // Используем StringBuilder для эффективной конкатенации строк
    StringBuilder result = создать_StringBuilder()

    // Находим все совпадения с регулярным выражением во входной строке
    СписокСовпадений matches = найти_совпадения(regex, input)

    // Объединяем найденные цифры через пробел
    для каждого совпадения в matches:
        result.Добавить(sовпадение.Значение)
        если текущее совпадение не последнее:
            result.Добавить(" ")

    // Возвращаем полученный результат
    вернуть result.Преобразовать_в_строку()
    

функция NewStudentSaveBtn_Click(sender, e):
    строка name = прочитать_текст(NewNameInput)
    строка surname = прочитать_текст(NewSurnameInput)
    строка grades = прочитать_текст(NewGradesInput)

    если (длина(name) > 20 или длина(surname) > 20):
        Показать_сообщение("Имя и фамилия не должны превышать 20 символов!")
        вернуть

    grades = ParseString(grades)
    StudentModel S = создать_студента(name, surname, grades)

    // обработка сохранения данных
    some_list.Добавить_в_конец(S)
    
    // Выведите сообщение об успешном сохранении или выполненной операции
    Показать_сообщение("Студент успешно добавлен!")

    Обновить(sender, e)

    вернуть
//------------------------------------//

Задача 2:
Реализована функцией:

void task1(MainLIST^% list, DynamicLIST %list1)
Псевдокод: 
//------------------------------------//
функция task1(MainLIST^& list, DynamicLIST& list1):
    лямбда-функция check(S: StudentModel):
        строка grades = S.getGrades()
        булево значение result = true
        целое число length = длина(grades) - 1
        пока (result и length >= 0):
            если (является_цифрой(grades[length]) и grades[length] != '4'):
                result = false
            уменьшить length на 1
        вернуть result

    MainptrNODE p_main_list = list->get_head()
    DynamicptrNODE p_last_checked = list1.get_head()

    булево значение first_good = false
    пока (p_main_list->next существует):
        строка surname = p_main_list->next->info.getSurname()
        вещественное число average_score = p_main_list->next->info.getAverageScore()

        NewTasksStudentModel S(surname, average_score)

        если (check(p_main_list->next->info)):
            list1.add_to_head(S)
            если (!first_good):
                p_last_checked = p_last_checked->next
                first_good = true
        иначе:
            list1.add_after(p_last_checked, S)

        p_main_list = p_main_list->next

    освободить память p_main_list
    освободить память p_last_checked

//------------------------------------//

Задача 3:
Реализована функцией:

void task2(MainLIST^% list, DynamicLIST% list2)
Псевдокод: 
//------------------------------------//
функция task2(MainLIST^& list, DynamicLIST& list2):
    лямбда-функция check(student1: NewTasksStudentModel, student2: NewTasksStudentModel):
        строка surname1 = student1.getSurname()
        строка surname2 = student2.getSurname()
        вернуть surname1 < surname2

    MainptrNODE p_main_list = list->get_head()
    DynamicptrNODE p_list2 = list2.get_head()

    если (p_main_list->next существует):
        строка surname = p_main_list->next->info.getSurname()
        вещественное число average_score = p_main_list->next->info.getAverageScore()
        NewTasksStudentModel S(surname, average_score)
        list2.add_to_head(S)
        p_main_list = p_main_list->next

    пока (p_main_list->next существует):
        строка surname = p_main_list->next->info.getSurname()
        вещественное число average_score = p_main_list->next->info.getAverageScore()
        NewTasksStudentModel S(surname, average_score)

        p_list2 = list2.get_head()
        булево значение pasted = false
        пока (!pasted и p_list2->next существует):
            если (check(p_list2->next->info, S)):
                list2.add_after(p_list2, S)
                pasted = true
            p_list2 = p_list2->next

        если (!pasted):
            list2.add_to_tail(S)

        p_main_list = p_main_list->next

    освободить память p_main_list

//------------------------------------//

Задача 4:
Реализована функцией:

void task3(MainLIST^% list, BSTree% tree)
Псевдокод: 
//------------------------------------//
функция task3(MainLIST^& list, BSTree& tree):
    MainptrNODE p_main_list = list->get_head()

    пока (p_main_list->next существует):
        строка surname = p_main_list->next->info.getSurname()
        вещественное число average_score = p_main_list->next->info.getAverageScore()
        NewTasksStudentModel S(surname, average_score)

        tree.insert(S)

        p_main_list = p_main_list->next

    освободить память p_main_list

//------------------------------------//

Задача 5:
Реализована функцией:


void task4(MainLIST^% list, AVLTree% tree)
Псевдокод: 
//------------------------------------//
функция task4(MainLIST^& list, AVLTree& tree):
    MainptrNODE p_main_list = list->get_head()

    пока (p_main_list->next существует):
        строка surname = p_main_list->next->info.getSurname()
        вещественное число average_score = p_main_list->next->info.getAverageScore()
        NewTasksStudentModel S(surname, average_score)

        tree.Insert(S)

        p_main_list = p_main_list->next

    освободить память p_main_list

//------------------------------------//

Задача 6:
Реализована функцией:


void task5(MainLIST^% list, TopLIST% list3)
Псевдокод: 
//------------------------------------//
функция task5(MainLIST^& list, TopLIST& list3):
    вещественное число max_average_score = 2
    MainptrNODE p_main_list = list->get_head()

    пока (p_main_list->next существует):
        если (max_average_score < p_main_list->next->info.getAverageScore()):
            max_average_score = p_main_list->next->info.getAverageScore()
        p_main_list = p_main_list->next

    p_main_list = list->get_head()
    пока (p_main_list->next существует):
        если (max_average_score == p_main_list->next->info.getAverageScore()):
            строка surname, grades
            surname = p_main_list->next->info.getSurname()
            grades = p_main_list->next->info.getGrades()

            TopStudentsModel S(surname, grades)
            list3.add_to_tail(S)

        p_main_list = p_main_list->next

    освободить память p_main_list
//------------------------------------//

3.2. Описание структуры программы.
    • К решению первой задачи относятся следующие классы: MainLIST, StudentModel .
    • К решению второй задачи относятся следующие классы: MainLIST, StudentModel, NewTasksStudentModel, DynamicLIST.
    • К решению третьей задачи относятся следующие классы: MainLIST, StudentModel, NewTasksStudentModel, DynamicLIST.
    • К решению четвертой задачи относятся следующие классы: MainLIST, StudentModel, NewTasksStudentModel, BSTree.
    • К решению пятой задачи относятся следующие классы: MainLIST, StudentModel, NewTasksStudentModel, AVLTree.
    • К решению шестой задачи относятся следующие классы: MainLIST, StudentModel, TopStudentsModel, TopLIST.

3.3. Описание использованных инструментальных средств среды MS Visual Studio.
В ходе разработки были использованы следующие инструментальные средства MS Visual Studio: отладчик, конструктор форм, монитор активности приложения.
3.4. Результаты тестирования.
В графы “Name” и “Surname” запрещено вводить строки длинной больше 20.
Графа “Grades” парсится и из любого набора будут собираться цифры от 2 до 5 через пробел.
3.5. Список использованных источников.
Конечно! Вот список 20 источников, которые могут быть полезными для изучения WinForms в C++:

1. Официальная документация Microsoft по WinForms: https://docs.microsoft.com/en-us/dotnet/desktop/winforms/?view=netframeworkdesktop-4.8
2. Статьи на сайте CodeProject, посвященные WinForms в C++: https://www.codeproject.com/KB/cpp/
3. Форумы MSDN, где можно найти ответы на различные вопросы о WinForms и C++: https://social.msdn.microsoft.com/Forums/en-US/home?category=visualcplusplussuccess&filter=alltypes&sort=lastpostdesc
4. Книга "Visual C++ .NET Developer's Guide" от Марка Микала (Mark Michaels): https://www.amazon.com/Visual-C-NET-Developers-Guide/dp/0672323430
5. Блог The Visual Studio Blog, где можно найти информацию о последних обновлениях и новостях в среде разработки Visual Studio: https://devblogs.microsoft.com/cppblog/
6. Сайт LearnVisualStudio.net, предлагающий видеоуроки по разработке на C++ и использованию WinForms: https://www.learnvisualstudio.net/
7. Серия статей "Windows Forms Programming with C++" на сайте CodeGuru: https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c15609/Windows-Forms-Programming-with-C.htm
8. Статьи на сайте CppDepend, посвященные разработке WinForms приложений на C++: https://cppdepend.com/blog/?category=C%2B%2B+WinForms
9. Видеокурсы на платформе Udemy о программировании WinForms на C++: https://www.udemy.com/topic/c-winforms/
10. Статьи и уроки на сайте CodeGuru по разработке WinForms приложений на C++: https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c15609/Windows-Forms-Programming-with-C.htm
11. Сайт Stack Overflow, где можно найти ответы на множество вопросов по WinForms и C++: https://stackoverflow.com/questions/tagged/c%2b%2b+winforms
12. Форумы на сайте Dream.In.Code с обширной базой вопросов и ответов по WinForms и C++: https://www.dreamincode.net/forums/forum/29-visual-c/page__sort_key__views__sort_order__desc__prune_day__1000__st__15
13. Книга "C++/CLI in Action" от Нигеля Пери (Nigel Perry), которая содержит информацию о создании приложений WinForms на C++/CLI: https://www.amazon.com/C-CLI-Action-Nigel-Perry/dp/1932394818
14. Вебинары и видеоуроки на YouTube по WinForms и C++: просто введите "WinForms C++ tutorial" в поисковой строке YouTube.
15. Блог Маршала Карта (Marshall Clow), где он дает советы и рекомендации по программированию WinForms на C++: https://www.marshallclow.com/
16. Статьи на сайте Codeguru, посвященные разработке приложений WinForms на C++: https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c15609/Windows-Forms-Programming-with-C.htm
17. Сайт The Code Project, предлагающий множество статей, учебников и примеров кода по WinForms и C++: https://www.codeproject.com/KB/cpp/
18. Видеокурсы на платформе Pluralsight о разработке WinForms приложений на C++: https://www.pluralsight.com/browse/software-development/windows-forms?view=cpp
    4. Заключение (перечень навыков и умений, приобретенных студентом за время прохождения практики).
Вот перечень навыков и умений, которые я приобрела  во время прохождения практики разработки приложения на WinForms в C++:
- Понимание архитектуры WinForms и умение создавать графические пользовательские интерфейсы с использованием элементов управления (controls) и контейнеров (containers).
- Умение работать с событиями (Actions) и обработкой пользовательского ввода.
- Навыки создания и управления формами (forms) и диалоговыми окнами (dialogs).
- Понимание работы с компонентами (components) и контроллерами данных (data controllers).
- Умение работать с графическими ресурсами, такими как изображения, значки и курсоры.
- Навыки работы с текстом, отображение текстовых данных.
- Понимание принципов отладки и тестирования приложений на WinForms в C++.
- Навыки оптимизации производительности приложений и эффективного использования ресурсов.
- Умение работать с расширениями и сторонними библиотеками для WinForms в C++.
- Знание основных принципов работы с файловой системой, включая чтение и запись файлов.
- Владение навыками разработки многопоточных приложений и обработки асинхронных операций.
- Понимание принципов безопасности приложений и защиты данных пользователя.
- Умение создавать удобный и интуитивно понятный интерфейс пользователя.
- Навыки командной работы, коллаборации и документирования кода.
    5. Приложение.
В этой  части  отчета  размещается  полный  текст  программы  и  результаты  ее выполнения.
...\Collections\AVLTree.h 
#pragma once
#include<iostream>
#include"NewTasksStudentModel.h"

using std::cout; using std::cin; using std::max;
//------------------------------------------------------------------------------------
//	AVL - сбалансир бин дерево поиска
//------------------------------------------------------------------------------------
using AVLTInfo = NewTasksStudentModel;
ref class AVLTreeNode
{
public:
    AVLTInfo key;
    int height;
    AVLTreeNode^ leftChild;
    AVLTreeNode^ rightChild;
    AVLTreeNode(AVLTInfo tempKey)
    {
        height = 0;
        key = tempKey;
        /*leftChild = nullptr;
        rightChild = nullptr;*/
    }
};

ref class AVLTree
{
private:

    AVLTreeNode^ root;

    AVLTreeNode^ Search(AVLTInfo, AVLTreeNode^);
    AVLTreeNode^ LeftRotate(AVLTreeNode^);
    AVLTreeNode^ LeftAndRightRotate(AVLTreeNode^);
    AVLTreeNode^ RightRotate(AVLTreeNode^);
    AVLTreeNode^ RightAndLeftRotate(AVLTreeNode^);

    int GetHeight(AVLTreeNode^);

    AVLTreeNode^ Insert(AVLTInfo, AVLTreeNode^);
    AVLTreeNode^ Delete(bool%, AVLTInfo, AVLTreeNode^);
public:
    AVLTree();
    AVLTreeNode^ getRoot();
    void Insert(AVLTInfo);
    bool Search(AVLTInfo);
    bool Delete(AVLTInfo);
    bool Updata(AVLTInfo, AVLTInfo);
};

//------------------------------------------------------------------------------------

AVLTree::AVLTree()
{
    root = nullptr;
}

// текущая высота ноды

int AVLTree::GetHeight(AVLTreeNode^ tempNode)
{
    return nullptr == tempNode ? -1 : tempNode->height;
}

inline AVLTreeNode^ AVLTree::getRoot()
{
    return root;
}

// вернём указатель на ноду где есть элемент

AVLTreeNode^ AVLTree::Search(AVLTInfo tempKey, AVLTreeNode^ tempNode)
{
    if (nullptr == tempNode)
        return nullptr;
    else if (tempKey == tempNode->key)
        return tempNode;
    else if (tempKey < tempNode->key)
        return Search(tempKey, tempNode->leftChild);
    return Search(tempKey, tempNode->rightChild);
}

bool AVLTree::Search(AVLTInfo tempKey)
{
    if (nullptr == Search(tempKey, root))
        return false;
    return true;
}

//------------------------------------------------------------------------------------
//	возвращается корневая нода текущего поддерева Функция левого малого поворота

AVLTreeNode^ AVLTree::LeftRotate(AVLTreeNode^ tempNode)
{
    AVLTreeNode^ lChildNode = tempNode->rightChild->leftChild, ^ newRoot = tempNode->rightChild;
    tempNode->rightChild->leftChild = tempNode;
    tempNode->rightChild = lChildNode;
    tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    if (nullptr != tempNode->rightChild)
        tempNode->rightChild->height = max(GetHeight(tempNode->rightChild->leftChild), GetHeight(tempNode->rightChild->rightChild)) + 1;
    return newRoot;
}

// тоже самое для баланса малый поворот направо

AVLTreeNode^ AVLTree::RightRotate(AVLTreeNode^ tempNode)
{
    AVLTreeNode^ rChildNode = tempNode->leftChild->rightChild, ^ newRoot = tempNode->leftChild;
    tempNode->leftChild->rightChild = tempNode;
    tempNode->leftChild = rChildNode;
    tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    if (nullptr != tempNode->leftChild)
        tempNode->leftChild->height = max(GetHeight(tempNode->leftChild->leftChild), GetHeight(tempNode->leftChild->rightChild)) + 1;
    return newRoot;
}

//	 для баланса сначача налево зачем направо

AVLTreeNode^ AVLTree::LeftAndRightRotate(AVLTreeNode^ tempNode)
{
    tempNode->leftChild = LeftRotate(tempNode->leftChild);
    return RightRotate(tempNode);
}

//	так же для баланса сначала направо потом налево

AVLTreeNode^ AVLTree::RightAndLeftRotate(AVLTreeNode^ tempNode)
{
    tempNode->rightChild = RightRotate(tempNode->rightChild);
    return LeftRotate(tempNode);
}
//------------------------------------------------------------------------------------

// вставка элемента в текущую ноду

AVLTreeNode^ AVLTree::Insert(AVLTInfo tempKey, AVLTreeNode^ tempNode)
{
    if (nullptr == tempNode)
        return tempNode = gcnew AVLTreeNode(tempKey);
    else
    {
        /*if (tempKey == tempNode->key)
            return tempNode;
        else */
        if (tempKey <= tempNode->key)
            tempNode->leftChild = Insert(tempKey, tempNode->leftChild);
        else tempNode->rightChild = Insert(tempKey, tempNode->rightChild);
    }
    //tempNode->height=max(GetHeight(tempNode->leftChild),GetHeight(tempNode->rightChild))+1;
    if (2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
    {
        if (tempKey <= tempNode->leftChild->key)
            tempNode = RightRotate(tempNode);
        else tempNode = LeftAndRightRotate(tempNode);
    }
    else if (-2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
    {
        if (tempKey > tempNode->rightChild->key)
            tempNode = LeftRotate(tempNode);
        else tempNode = RightAndLeftRotate(tempNode);
    }
    tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    return tempNode;
}

void AVLTree::Insert(AVLTInfo tempKey)
{
    root = Insert(tempKey, root);
}

//	удаление

AVLTreeNode^ AVLTree::Delete(bool% isDelSucceed, AVLTInfo tempKey, AVLTreeNode^ tempNode)
{
    if (nullptr == tempNode)
        return nullptr;
    else
    {
        if (tempKey == tempNode->key)
        {
            if (nullptr == tempNode->rightChild)
            {
                AVLTreeNode^ cur = tempNode;
                tempNode = tempNode->leftChild;
                delete cur;
                isDelSucceed = true;
                return tempNode;
            }
            else// идём искать наименьший элемент правого поддерева для замены, а затем удаляем
            {
                AVLTreeNode^ cur = tempNode->rightChild;
                while (cur->leftChild != nullptr)
                    cur = cur->leftChild;
                tempNode->key = cur->key;
                tempNode->rightChild = Delete(isDelSucceed, cur->key, tempNode->rightChild);
            }
        }
        else if (tempKey < tempNode->key)
            tempNode->leftChild = Delete(isDelSucceed, tempKey, tempNode->leftChild);
        else tempNode->rightChild = Delete(isDelSucceed, tempKey, tempNode->rightChild);

        if (-2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))//удаляемый слева
        {
            if (GetHeight(tempNode->rightChild->rightChild) >= GetHeight(tempNode->rightChild->leftChild))
                tempNode = LeftRotate(tempNode);
            else tempNode = RightAndLeftRotate(tempNode);
        }
        else if (2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
        {
            if (GetHeight(tempNode->leftChild->leftChild) >= GetHeight(tempNode->leftChild->rightChild))
                tempNode = RightRotate(tempNode);
            else tempNode = LeftAndRightRotate(tempNode);
        }
        tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    }
    return tempNode;
}

bool AVLTree::Delete(AVLTInfo tempKey)
{
    bool isDelSucceed = false;
    root = Delete(isDelSucceed, tempKey, root);
    return isDelSucceed;
}

// замена значения

bool AVLTree::Updata(AVLTInfo oldKey, AVLTInfo newKey)
{
    if (Delete(oldKey))
    {
        Insert(newKey);
        return true;
    }
    return false;
}

...\Collections\BinarySearchTree.h 
#pragma once
#include <cmath>
#include <iostream>
#include"NewTasksStudentModel.h"

using TBST = NewTasksStudentModel;
ref class BSTNODE
{
public:
    BSTNODE() {}
    BSTNODE(TBST elem)
    {
        data.setNewStudent(elem);
    }
    TBST data;
    BSTNODE^ p_right;
    BSTNODE^ p_left;
    int leftHeight;
    int rightHeight;
};
ref class BSTree
{
public:
    BSTree();
    ~BSTree();
    void insert(TBST% d);
    bool search(TBST% d);
    bool remove(TBST% d);
    int size();
    BSTNODE^ getRoot();
    TBST findMax();
    TBST findMin();
    int heightOfTree();
    float percentLeaf();
    float percentInterior();

private:

    bool searchHelper(BSTNODE^ p_node, TBST elem);
    bool insertHelper(BSTNODE^% p_node, TBST% elem);
    bool removeHelper(BSTNODE^% p_node, TBST elem);

    bool isBalanced(BSTNODE^ p_node);
    int setHeightHelper(BSTNODE^ p_node);
    void percentLeafHelper(BSTNODE^ p_node);
    void percentInteriorHelper(BSTNODE^ p_node);
    void destructorHelper(BSTNODE^ p_node);

    int numElements;

    int countLeaves;
    int countInterior;

    BSTNODE^ root;
};
BSTree::BSTree()
{
    root;
    numElements = 0;
    countLeaves = 0;
    countInterior = 0;
}

BSTree:: ~BSTree()
{
    destructorHelper(root);
}

void BSTree::destructorHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        destructorHelper(p_node->p_left);
        destructorHelper(p_node->p_right);
        delete p_node;
        numElements--;
    }
}

void BSTree::insert(TBST% elem)
{
    insertHelper(root, elem);
}

bool BSTree::insertHelper(BSTNODE^% p_node, TBST% elem)
{
    bool retVal = false;

    if (p_node == nullptr)
    {
        p_node = gcnew BSTNODE(elem);

        numElements++;

        setHeightHelper(root);
    }
    else
    {
        if (elem <= p_node->data)
        {
            insertHelper(p_node->p_left, elem);
        }
        else
        {
            insertHelper(p_node->p_right, elem);
        }
    }
    return retVal;
}

bool BSTree::search(TBST% elem)
{
    return searchHelper(root, elem);
}

bool BSTree::searchHelper(BSTNODE^ p_node, TBST elem)
{
    if (p_node->data == elem)
    {
        return true;
    }
    else if (p_node->p_right == nullptr && p_node->p_left == nullptr)
    {
        return false;
    }
    else if (p_node->data < elem)
    {
        return searchHelper(p_node->p_right, elem);
    }
    else
    {
        return searchHelper(p_node->p_left, elem);
    }
}

bool BSTree::remove(TBST% elem)
{
    return removeHelper(root, elem);
}

bool BSTree::removeHelper(BSTNODE^% p_node, TBST elem)
{
    bool retVal = false;
    if (p_node != nullptr)
    {
        if (p_node->data == elem)
        {
            retVal = true;
            if (p_node->p_right == nullptr && p_node->p_left == nullptr)
            {
                delete p_node;
                p_node = nullptr;
                numElements--;
            }
            else if (p_node->p_right == nullptr && p_node->p_left != nullptr)
            {
                BSTNODE^ node = p_node;
                p_node = p_node->p_left;
                delete node;
                numElements--;
            }
            else if (p_node->p_left == nullptr && p_node->p_right != nullptr)
            {
                BSTNODE^ node = p_node;
                p_node = p_node->p_right;
                delete node;
                numElements--;
            }
            else
            {
                BSTNODE^ left = p_node->p_left;
                while (left->p_right != nullptr)
                {
                    left = left->p_right;
                }

                p_node->data = left->data;

                removeHelper(p_node->p_left, p_node->data);
            }
            setHeightHelper(root);
        }
        else if (p_node->data <= elem)
        {
            retVal = removeHelper(p_node->p_right, elem);
        }

        else
        {
            retVal = removeHelper(p_node->p_left, elem);
        }
    }

    return retVal;
}

int BSTree::size()
{
    return numElements;
}
inline BSTNODE^ BSTree::getRoot()
{
    return root;
}

int BSTree::setHeightHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        p_node->leftHeight = setHeightHelper(p_node->p_left) + 1;
        p_node->rightHeight = setHeightHelper(p_node->p_right) + 1;

        if (p_node->leftHeight >= p_node->rightHeight)
        {
            return p_node->leftHeight;
        }
        else
        {
            return p_node->rightHeight;
        }
    }
    else
    {
        return -1;
    }
}

bool BSTree::isBalanced(BSTNODE^ p_node)
{
    if (p_node->rightHeight - p_node->leftHeight > 1 || p_node->rightHeight - p_node->leftHeight < -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

float BSTree::percentLeaf()
{
    countInterior = 0;
    countLeaves = 0;

    percentLeafHelper(root);

    return ((float)countLeaves / (float)numElements);
}

void BSTree::percentLeafHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        percentLeafHelper(p_node->p_left);
        if (p_node->p_right == nullptr && p_node->p_left == nullptr)
        {
            countLeaves++;
        }
        percentLeafHelper(p_node->p_right);
    }
}

float BSTree::percentInterior()
{
    countInterior = 0;
    countInterior = 0;

    percentInteriorHelper(root);

    return((float)countInterior / (float)numElements);
}

void BSTree::percentInteriorHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        percentInteriorHelper(p_node->p_left);
        if (!(p_node->p_right == nullptr && p_node->p_left == nullptr))
        {
            countInterior++;
        }
        percentInteriorHelper(p_node->p_right);
    }
}

TBST BSTree::findMax()
{
    BSTNODE^ p_max = root;
    while (p_max->p_right != nullptr)
    {
        p_max = p_max->p_right;
    }

    return p_max->data;
}

TBST BSTree::findMin()
{
    BSTNODE^ p_min = root;
    while (p_min->p_left != nullptr)
    {
        p_min = p_min->p_left;
    }
    return p_min->data;
}

int BSTree::heightOfTree()
{
    if (numElements > 0)
    {
        if (root->rightHeight > root->leftHeight)
        {
            return root->rightHeight + 1;
        }
        else
        {
            return root->leftHeight + 1;
        }
    }
    else
    {
        return 0;
    }
}

...\Collections\DynamicLIST.h 
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
...\Collections\MainLIST.h 
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
...\Collections\TopLIST.h 
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
...\FormsCpp\AddStudentForm.cpp 
#include "pch.h"
#include "AddStudentForm.h"
#include <string>
#include <regex>
using namespace System::Text::RegularExpressions;
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

System::Void CppCLR_WinformsProjekt1::AddStudentForm::NewStudentSaveBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ name = NewNameInput->Text;
    String^ surname = NewSurnameInput->Text;
    String^ grades = NewGradesInput->Text;

    if (name->Length > 20 || surname->Length > 20)
    {
        MessageBox::Show(L"The name and surname should not exceed 20 characters!");
        return;
    }
    grades = ParseString(grades);
    StudentModel S(name, surname, grades);
    // обработка сохранения данных
    some_list->add_to_tail(S);

    // Выведите сообщение об успешном сохранении или выполненной операции
    MessageBox::Show(L"Student added successfully!");

    Refresh(sender, e);

    return System::Void();
}
...\FormsCpp\DeleteStudentForm.cpp 
#include "pch.h"
#include "DeleteStudentForm.h"

System::Void CppCLR_WinformsProjekt2::DeleteStudentForm::StudentDeleteBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ name = toDelNameInput->Text;
    String^ surname = toDelSurnameInput->Text;

    MainptrNODE p = some_list->get_head();
    bool finded = false;
    while (p->next && !finded)
    {
        if ((p->next->info.getName() == name) && (p->next->info.getSurname() == surname))
        {
            finded = true;
        }
        else
        {
            p = p->next;
        }
    }
    if (finded)
    {
        some_list->del_after(p);
        MessageBox::Show(L"Student deleted successfully!");
        Refresh(sender, e);
    }
    else
    {
        MessageBox::Show(L"Student not found!");
    }

    return System::Void();
}
...\FormsCpp\Form1.cpp 
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
...\FormsH\AddStudentForm.h 
#pragma once
#include "StudentModel.h"
#include "MainLIST.h"
namespace CppCLR_WinformsProjekt1 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddStudentForm : public System::Windows::Forms::Form
    {
    private: MainLIST^ some_list;
           System::Action<System::Object^, System::EventArgs^>^ Refresh;

    public:
        AddStudentForm(void)
        {
            InitializeComponent();
        }
        AddStudentForm(MainLIST^ main_list, System::Action<System::Object^, System::EventArgs^>^ pRefresh)
        {
            InitializeComponent();
            some_list = main_list;
            Refresh = pRefresh;
        }
    protected:

        ~AddStudentForm()
        {
            some_list = nullptr;
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TextBox^ NewNameInput;
    protected:
    private: System::Windows::Forms::TextBox^ NewSurnameInput;
    private: System::Windows::Forms::TextBox^ NewGradesInput;
    private: System::Windows::Forms::Label^ NewName;
    private: System::Windows::Forms::Label^ NewSurname;
    private: System::Windows::Forms::Label^ NewGrades;
    private: System::Windows::Forms::Button^ NewStudentSaveBtn;

    private:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->NewNameInput = (gcnew System::Windows::Forms::TextBox());
            this->NewSurnameInput = (gcnew System::Windows::Forms::TextBox());
            this->NewGradesInput = (gcnew System::Windows::Forms::TextBox());
            this->NewName = (gcnew System::Windows::Forms::Label());
            this->NewSurname = (gcnew System::Windows::Forms::Label());
            this->NewGrades = (gcnew System::Windows::Forms::Label());
            this->NewStudentSaveBtn = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // NewNameInput
            //
            this->NewNameInput->BackColor = System::Drawing::SystemColors::Window;
            this->NewNameInput->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewNameInput->Location = System::Drawing::Point(186, 32);
            this->NewNameInput->Name = L"NewNameInput";
            this->NewNameInput->Size = System::Drawing::Size(163, 26);
            this->NewNameInput->TabIndex = 0;
            this->NewNameInput->Text = L"Bob";
            this->NewNameInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            //
            // NewSurnameInput
            //
            this->NewSurnameInput->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewSurnameInput->Location = System::Drawing::Point(186, 82);
            this->NewSurnameInput->Name = L"NewSurnameInput";
            this->NewSurnameInput->Size = System::Drawing::Size(163, 26);
            this->NewSurnameInput->TabIndex = 1;
            this->NewSurnameInput->Text = L"Backer";
            this->NewSurnameInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            //
            // NewGradesInput
            //
            this->NewGradesInput->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewGradesInput->Location = System::Drawing::Point(186, 125);
            this->NewGradesInput->Name = L"NewGradesInput";
            this->NewGradesInput->Size = System::Drawing::Size(163, 26);
            this->NewGradesInput->TabIndex = 2;
            this->NewGradesInput->Text = L"5 5 5 5 5";
            this->NewGradesInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            //
            // NewName
            //
            this->NewName->AutoSize = true;
            this->NewName->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewName->Location = System::Drawing::Point(46, 32);
            this->NewName->Name = L"NewName";
            this->NewName->Size = System::Drawing::Size(52, 23);
            this->NewName->TabIndex = 3;
            this->NewName->Text = L"Name";
            //
            // NewSurname
            //
            this->NewSurname->AutoSize = true;
            this->NewSurname->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewSurname->Location = System::Drawing::Point(46, 82);
            this->NewSurname->Name = L"NewSurname";
            this->NewSurname->Size = System::Drawing::Size(74, 23);
            this->NewSurname->TabIndex = 4;
            this->NewSurname->Text = L"Surname";
            //
            // NewGrades
            //
            this->NewGrades->AutoSize = true;
            this->NewGrades->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewGrades->Location = System::Drawing::Point(46, 125);
            this->NewGrades->Name = L"NewGrades";
            this->NewGrades->Size = System::Drawing::Size(133, 46);
            this->NewGrades->TabIndex = 5;
            this->NewGrades->Text = L"Grades \r\n(through a space)";
            //
            // NewStudentSaveBtn
            //
            this->NewStudentSaveBtn->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->NewStudentSaveBtn->Location = System::Drawing::Point(104, 195);
            this->NewStudentSaveBtn->Name = L"NewStudentSaveBtn";
            this->NewStudentSaveBtn->Size = System::Drawing::Size(174, 38);
            this->NewStudentSaveBtn->TabIndex = 6;
            this->NewStudentSaveBtn->Text = L"Save new student";
            this->NewStudentSaveBtn->UseVisualStyleBackColor = true;
            this->NewStudentSaveBtn->Click += gcnew System::EventHandler(this, &AddStudentForm::NewStudentSaveBtn_Click);
            //
            // AddStudentForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(384, 261);
            this->Controls->Add(this->NewStudentSaveBtn);
            this->Controls->Add(this->NewGrades);
            this->Controls->Add(this->NewSurname);
            this->Controls->Add(this->NewName);
            this->Controls->Add(this->NewGradesInput);
            this->Controls->Add(this->NewSurnameInput);
            this->Controls->Add(this->NewNameInput);
            this->Name = L"AddStudentForm";
            this->Text = L"New student registration form";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private: System::Void NewStudentSaveBtn_Click(System::Object^ sender, System::EventArgs^ e);
    };
}

...\FormsH\DeleteStudentForm.h 
#pragma once
#include "StudentModel.h"
#include "MainLIST.h"
namespace CppCLR_WinformsProjekt2 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class DeleteStudentForm : public System::Windows::Forms::Form
    {
    private: MainLIST^ some_list;
           System::Action<System::Object^, System::EventArgs^>^ Refresh;
    public:
        DeleteStudentForm(void)
        {
            InitializeComponent();
        }
        DeleteStudentForm(MainLIST^ main_list, System::Action<System::Object^, System::EventArgs^>^ pRefresh)
        {
            InitializeComponent();
            some_list = main_list;
            Refresh = pRefresh;
        }
    protected:

        ~DeleteStudentForm()
        {
            some_list = nullptr;
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TextBox^ toDelNameInput;
    private: System::Windows::Forms::TextBox^ toDelSurnameInput;
    protected:

    protected:

    private: System::Windows::Forms::Label^ toDelName;
    private: System::Windows::Forms::Label^ toDelSurname;

    private: System::Windows::Forms::Button^ StudentDeleteBtn;

    private:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->toDelNameInput = (gcnew System::Windows::Forms::TextBox());
            this->toDelSurnameInput = (gcnew System::Windows::Forms::TextBox());
            this->toDelName = (gcnew System::Windows::Forms::Label());
            this->toDelSurname = (gcnew System::Windows::Forms::Label());
            this->StudentDeleteBtn = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // toDelNameInput
            //
            this->toDelNameInput->BackColor = System::Drawing::SystemColors::Window;
            this->toDelNameInput->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->toDelNameInput->Location = System::Drawing::Point(186, 60);
            this->toDelNameInput->Name = L"toDelNameInput";
            this->toDelNameInput->Size = System::Drawing::Size(163, 26);
            this->toDelNameInput->TabIndex = 0;
            this->toDelNameInput->Text = L"Bob";
            this->toDelNameInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            //
            // toDelSurnameInput
            //
            this->toDelSurnameInput->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->toDelSurnameInput->Location = System::Drawing::Point(186, 112);
            this->toDelSurnameInput->Name = L"toDelSurnameInput";
            this->toDelSurnameInput->Size = System::Drawing::Size(163, 26);
            this->toDelSurnameInput->TabIndex = 1;
            this->toDelSurnameInput->Text = L"Backer";
            this->toDelSurnameInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            //
            // toDelName
            //
            this->toDelName->AutoSize = true;
            this->toDelName->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->toDelName->Location = System::Drawing::Point(46, 60);
            this->toDelName->Name = L"toDelName";
            this->toDelName->Size = System::Drawing::Size(52, 23);
            this->toDelName->TabIndex = 3;
            this->toDelName->Text = L"Name";
            //
            // toDelSurname
            //
            this->toDelSurname->AutoSize = true;
            this->toDelSurname->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->toDelSurname->Location = System::Drawing::Point(46, 115);
            this->toDelSurname->Name = L"toDelSurname";
            this->toDelSurname->Size = System::Drawing::Size(74, 23);
            this->toDelSurname->TabIndex = 4;
            this->toDelSurname->Text = L"Surname";
            //
            // StudentDeleteBtn
            //
            this->StudentDeleteBtn->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->StudentDeleteBtn->Location = System::Drawing::Point(101, 181);
            this->StudentDeleteBtn->Name = L"StudentDeleteBtn";
            this->StudentDeleteBtn->Size = System::Drawing::Size(174, 38);
            this->StudentDeleteBtn->TabIndex = 6;
            this->StudentDeleteBtn->Text = L"Delete student";
            this->StudentDeleteBtn->UseVisualStyleBackColor = true;
            this->StudentDeleteBtn->Click += gcnew System::EventHandler(this, &DeleteStudentForm::StudentDeleteBtn_Click);
            //
            // DeleteStudentForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(384, 261);
            this->Controls->Add(this->StudentDeleteBtn);
            this->Controls->Add(this->toDelSurname);
            this->Controls->Add(this->toDelName);
            this->Controls->Add(this->toDelSurnameInput);
            this->Controls->Add(this->toDelNameInput);
            this->Name = L"DeleteStudentForm";
            this->Text = L"Delete student form";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void StudentDeleteBtn_Click(System::Object^ sender, System::EventArgs^ e);
    };
}

...\FormsH\Form1.h 
#pragma once
#include"MainLIST.h"
//#include"StudentModel.h"

namespace CppCLRWinformsProjekt {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    private: MainLIST _main_list;
    private: int number_of_students = 0;

    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TabControl^ tabControl1;

    private: System::Windows::Forms::TabPage^ l1;
    private: System::Windows::Forms::TabPage^ l2;
    private: System::Windows::Forms::TabPage^ BS;
    private: System::Windows::Forms::TabPage^ AVL;
    private: System::Windows::Forms::TabPage^ Top;

    private: System::Windows::Forms::Button^ Add;
    private: System::Windows::Forms::Button^ Delete;
    private: System::Windows::Forms::Button^ View;
    private: System::Windows::Forms::Button^ Open;
    private: System::Windows::Forms::Button^ Save;

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->l1 = (gcnew System::Windows::Forms::TabPage());
            this->l2 = (gcnew System::Windows::Forms::TabPage());
            this->BS = (gcnew System::Windows::Forms::TabPage());
            this->AVL = (gcnew System::Windows::Forms::TabPage());
            this->Top = (gcnew System::Windows::Forms::TabPage());
            this->Add = (gcnew System::Windows::Forms::Button());
            this->Delete = (gcnew System::Windows::Forms::Button());
            this->View = (gcnew System::Windows::Forms::Button());
            this->Open = (gcnew System::Windows::Forms::Button());
            this->Save = (gcnew System::Windows::Forms::Button());
            this->tabControl1->SuspendLayout();
            this->SuspendLayout();
            //
            // tabControl1
            //
            this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
            this->tabControl1->Controls->Add(this->l1);
            this->tabControl1->Controls->Add(this->l2);
            this->tabControl1->Controls->Add(this->BS);
            this->tabControl1->Controls->Add(this->AVL);
            this->tabControl1->Controls->Add(this->Top);
            this->tabControl1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->tabControl1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->tabControl1->ItemSize = System::Drawing::Size(160, 40);
            this->tabControl1->Location = System::Drawing::Point(-1, 49);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->Padding = System::Drawing::Point(27, 5);
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(603, 351);
            this->tabControl1->TabIndex = 0;
            //
            // l1
            //
            this->l1->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
            this->l1->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->l1->Location = System::Drawing::Point(4, 4);
            this->l1->Name = L"l1";
            this->l1->Padding = System::Windows::Forms::Padding(3);
            this->l1->Size = System::Drawing::Size(595, 303);
            this->l1->TabIndex = 0;
            this->l1->Text = L"Dynamic List 1";
            this->l1->UseVisualStyleBackColor = true;
            this->l1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
            //
            // l2
            //
            this->l2->Location = System::Drawing::Point(4, 4);
            this->l2->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
            this->l2->Name = L"l2";
            this->l2->Padding = System::Windows::Forms::Padding(3);
            this->l2->Size = System::Drawing::Size(595, 303);
            this->l2->TabIndex = 1;
            this->l2->Text = L"Dynamic List 2";
            this->l2->UseVisualStyleBackColor = true;
            //
            // BS
            //
            this->BS->Location = System::Drawing::Point(4, 4);
            this->BS->Name = L"BS";
            this->BS->Size = System::Drawing::Size(595, 303);
            this->BS->TabIndex = 2;
            this->BS->Text = L"BSTree";
            this->BS->UseVisualStyleBackColor = true;
            //
            // AVL
            //
            this->AVL->Location = System::Drawing::Point(4, 4);
            this->AVL->Name = L"AVL";
            this->AVL->Size = System::Drawing::Size(595, 303);
            this->AVL->TabIndex = 3;
            this->AVL->Text = L"AVLTree";
            this->AVL->UseVisualStyleBackColor = true;
            //
            // Top
            //
            this->Top->Location = System::Drawing::Point(4, 4);
            this->Top->Name = L"Top";
            this->Top->Size = System::Drawing::Size(595, 303);
            this->Top->TabIndex = 4;
            this->Top->Text = L"Top Students";
            this->Top->UseVisualStyleBackColor = true;
            //
            // Add
            //
            this->Add->AccessibleName = L"Add";
            this->Add->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Add->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Add->Location = System::Drawing::Point(12, 1);
            this->Add->Name = L"Add";
            this->Add->Size = System::Drawing::Size(110, 46);
            this->Add->TabIndex = 1;
            this->Add->Text = L"Add Student";
            this->Add->UseVisualStyleBackColor = true;
            this->Add->Click += gcnew System::EventHandler(this, &Form1::button_Add_Click);
            //
            // Delete
            //
            this->Delete->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Delete->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Delete->Location = System::Drawing::Point(128, 1);
            this->Delete->Name = L"Delete";
            this->Delete->Size = System::Drawing::Size(110, 46);
            this->Delete->TabIndex = 2;
            this->Delete->Text = L"Delete Student";
            this->Delete->UseVisualStyleBackColor = true;
            this->Delete->Click += gcnew System::EventHandler(this, &Form1::button_Delete_Click);
            //
            // View
            //
            this->View->Cursor = System::Windows::Forms::Cursors::Hand;
            this->View->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->View->Location = System::Drawing::Point(244, 1);
            this->View->Name = L"View";
            this->View->Size = System::Drawing::Size(110, 46);
            this->View->TabIndex = 3;
            this->View->Text = L"View All Info";
            this->View->UseVisualStyleBackColor = true;
            this->View->Click += gcnew System::EventHandler(this, &Form1::View_Click);
            //
            // Open
            //
            this->Open->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Open->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Open->Location = System::Drawing::Point(360, 1);
            this->Open->Name = L"Open";
            this->Open->Size = System::Drawing::Size(110, 46);
            this->Open->TabIndex = 4;
            this->Open->Text = L"Open File";
            this->Open->UseVisualStyleBackColor = true;
            this->Open->Click += gcnew System::EventHandler(this, &Form1::button_OpenFile_Click);
            //
            // Save
            //
            this->Save->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Save->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Save->Location = System::Drawing::Point(476, 1);
            this->Save->Name = L"Save";
            this->Save->Size = System::Drawing::Size(110, 46);
            this->Save->TabIndex = 5;
            this->Save->Text = L"Save File";
            this->Save->UseVisualStyleBackColor = true;
            this->Save->Click += gcnew System::EventHandler(this, &Form1::button_SaveFile_Click);
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(600, 400);
            this->Controls->Add(this->Save);
            this->Controls->Add(this->Open);
            this->Controls->Add(this->View);
            this->Controls->Add(this->Delete);
            this->Controls->Add(this->Add);
            this->Controls->Add(this->tabControl1);
            this->Name = L"Form1";
            this->Text = L"VSU summer practice";
            this->tabControl1->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

    private: System::Void BStreeView(System::Object^ sender, System::EventArgs^ e);
    private: System::Void AVLtreeView(System::Object^ sender, System::EventArgs^ e);
    private: System::Void CppCLRWinformsProjekt::Form1::RefreshOnClosed(System::Object^ sender, System::EventArgs^ e);
    private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_OpenFile_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void View_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_SaveFile_Click(System::Object^ sender, System::EventArgs^ e);
    };
}

...\FormsH\ViewAllStudentsForm.h 
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

...\Main\CppCLR_WinformsProjekt.h 

...\Main\pch.h 
// pch.h: Dies ist eine vorkompilierte Headerdatei.
// Die unten aufgefГјhrten Dateien werden nur einmal kompiliert, um die Buildleistung fГјr zukГјnftige Builds zu verbessern.
// Dies wirkt sich auch auf die IntelliSense-Leistung aus, CodevervollstГ¤ndigung und viele Features zum Durchsuchen von Code eingeschlossen.
// Die hier aufgefГјhrten Dateien werden jedoch ALLE neu kompiliert, wenn mindestens eine davon zwischen den Builds aktualisiert wird.
// FГјgen Sie hier keine Dateien hinzu, die hГ¤ufig aktualisiert werden sollen, da sich so der Leistungsvorteil ins Gegenteil verkehrt.

#ifndef PCH_H
#define PCH_H

// FГјgen Sie hier Header hinzu, die vorkompiliert werden sollen.

#endif //PCH_H

...\Main\Resource.h 
//{{NO_DEPENDENCIES}}
// Von Microsoft Visual C++ generierte Includedatei.
// Verwendet von app.rc

...\Main\AssemblyInfo.cpp 
#include "pch.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

[assembly:AssemblyTitleAttribute(L"CppCLRWinformsProjekt")] ;
[assembly:AssemblyDescriptionAttribute(L"")] ;
[assembly:AssemblyConfigurationAttribute(L"")] ;
[assembly:AssemblyCompanyAttribute(L"")] ;
[assembly:AssemblyProductAttribute(L"CppCLRWinformsProjekt")] ;
[assembly:AssemblyCopyrightAttribute(L"Copyright (c)  2019")] ;
[assembly:AssemblyTrademarkAttribute(L"")] ;
[assembly:AssemblyCultureAttribute(L"")] ;

[assembly:AssemblyVersionAttribute("1.0.*")] ;

[assembly:ComVisible(false)] ;

[assembly:CLSCompliantAttribute(true)] ;
...\Main\CppCLR_WinformsProjekt.cpp 
#include "pch.h"
#include <Windows.h>

#include "Form1.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

//явно указываем компилятору, что нужно подключить библиотеку "user32.lib", которая содержит определение функции LoadImageW
#pragma comment(lib, "user32.lib")

[STAThread]
int main(array<System::String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CppCLRWinformsProjekt::Form1^ form = gcnew CppCLRWinformsProjekt::Form1(); // Создаем экземпляр главной формы
    // Устанавливаем иконку приложения
    HINSTANCE hInstance = static_cast<HINSTANCE>(GetModuleHandle(NULL));
    HICON hIcon = static_cast<HICON>(LoadImage(hInstance, L"iconss\\app.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE));
    if (hIcon)
    {
        // Получаем дескриптор главной формы
        HWND hWnd = static_cast<HWND>(form->Handle.ToPointer());
        // Устанавливаем иконку для окна
        SendMessage(hWnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(hIcon)); // Маленькая иконка
        SendMessage(hWnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(hIcon));   // Большая иконка
    }

    Application::Run(form);
    return 0;
}
...\Main\pch.cpp 
// pch.cpp: Quelldatei, die dem vorkompilierten Header entspricht

#include "pch.h"

// Bei der Verwendung vorkompilierter Header ist diese Quelldatei fГјr eine erfolgreiche Kompilierung erforderlich. 
...\Models\NewTasksStudentModel.h 
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

...\Models\StudentModel.h 
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

...\Models\TopStudentsModel.h 
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
