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
