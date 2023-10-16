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
