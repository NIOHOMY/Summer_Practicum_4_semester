#include "pch.h"
#include "AddStudentForm.h"
#include <string>
#include <regex>
using namespace System::Text::RegularExpressions;
String^ ParseString(String^ input)
{
    // ������� ���������� ��������� ��� ������ ���� �� 2 �� 5
    String^ pattern = "[2-5]";
    Regex^ regex = gcnew Regex(pattern);

    // ���������� StringBuilder ��� ����������� ������������ �����
    StringBuilder^ result = gcnew StringBuilder();

    // ������� ��� ���������� � ���������� ���������� �� ������� ������
    MatchCollection^ matches = regex->Matches(input);

    // ���������� ��������� ����� ����� ������
    for (int i = 0; i < matches->Count; i++)
    {
        result->Append(matches[i]->Value);
        if (i < matches->Count - 1)
        {
            result->Append(" ");
        }
    }

    // ���������� ���������� ���������
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
    // ��������� ���������� ������
    some_list->add_to_tail(S);

    // �������� ��������� �� �������� ���������� ��� ����������� ��������
    MessageBox::Show(L"Student added successfully!");

    Refresh(sender, e);

    return System::Void();
}