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