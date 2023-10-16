#include "pch.h"
#include <Windows.h>

#include "Form1.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

//���� ��������� �����������, ��� ����� ���������� ���������� "user32.lib", ������� �������� ����������� ������� LoadImageW
#pragma comment(lib, "user32.lib")

[STAThread]
int main(array<System::String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CppCLRWinformsProjekt::Form1^ form = gcnew CppCLRWinformsProjekt::Form1(); // ������� ��������� ������� �����
    // ������������� ������ ����������
    HINSTANCE hInstance = static_cast<HINSTANCE>(GetModuleHandle(NULL));
    HICON hIcon = static_cast<HICON>(LoadImage(hInstance, L"iconss\\app.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE));
    if (hIcon)
    {
        // �������� ���������� ������� �����
        HWND hWnd = static_cast<HWND>(form->Handle.ToPointer());
        // ������������� ������ ��� ����
        SendMessage(hWnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(hIcon)); // ��������� ������
        SendMessage(hWnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(hIcon));   // ������� ������
    }

    Application::Run(form);
    return 0;
}