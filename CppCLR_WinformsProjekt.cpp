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