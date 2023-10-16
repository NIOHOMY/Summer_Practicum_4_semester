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
