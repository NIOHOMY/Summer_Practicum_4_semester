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