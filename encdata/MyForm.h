// encdata.h

#pragma once

namespace encdata {

	public ref class encdata : public System::Windows::Forms::Form
	{
	public:
		encdata(void);

	protected:
		~encdata();

	private:
		System::String^ selectedFilePath;
		System::Windows::Forms::Button^ buttonSelectFile;
		System::Windows::Forms::Button^ buttonSelectFolder;
		System::Windows::Forms::Button^ buttonEncrypt;
		System::Windows::Forms::Button^ buttonDecrypt;
		System::Windows::Forms::TextBox^ textBoxPassword;
		System::Windows::Forms::ProgressBar^ progressBarOperation;
		System::Windows::Forms::Label^ labelSelectedPath;
	private: System::Windows::Forms::Label^ passwordlabel;
	private: System::Windows::Forms::Label^ label1;
		   System::ComponentModel::Container^ components;

		void buttonSelectFile_Click(System::Object^ sender, System::EventArgs^ e);
		void buttonSelectFolder_Click(System::Object^ sender, System::EventArgs^ e);
		void buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e);
		void buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e);
		void textBoxPassword_Enter(System::Object^ sender, System::EventArgs^ e);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->buttonSelectFile = (gcnew System::Windows::Forms::Button());
			this->buttonSelectFolder = (gcnew System::Windows::Forms::Button());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->progressBarOperation = (gcnew System::Windows::Forms::ProgressBar());
			this->labelSelectedPath = (gcnew System::Windows::Forms::Label());
			this->passwordlabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonSelectFile
			// 
			this->buttonSelectFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonSelectFile->Location = System::Drawing::Point(17, 48);
			this->buttonSelectFile->Name = L"buttonSelectFile";
			this->buttonSelectFile->Size = System::Drawing::Size(122, 35);
			this->buttonSelectFile->TabIndex = 0;
			this->buttonSelectFile->Text = L"Select File";
			this->buttonSelectFile->UseVisualStyleBackColor = true;
			this->buttonSelectFile->Click += gcnew System::EventHandler(this, &encdata::buttonSelectFile_Click);
			// 
			// buttonSelectFolder
			// 
			this->buttonSelectFolder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonSelectFolder->Location = System::Drawing::Point(147, 48);
			this->buttonSelectFolder->Name = L"buttonSelectFolder";
			this->buttonSelectFolder->Size = System::Drawing::Size(139, 35);
			this->buttonSelectFolder->TabIndex = 1;
			this->buttonSelectFolder->Text = L"Select Folder";
			this->buttonSelectFolder->UseVisualStyleBackColor = true;
			this->buttonSelectFolder->Click += gcnew System::EventHandler(this, &encdata::buttonSelectFolder_Click);
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonEncrypt->Location = System::Drawing::Point(401, 48);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(98, 35);
			this->buttonEncrypt->TabIndex = 2;
			this->buttonEncrypt->Text = L"Encrypt";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &encdata::buttonEncrypt_Click);
			// 
			// buttonDecrypt
			// 
			this->buttonDecrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonDecrypt->Location = System::Drawing::Point(293, 48);
			this->buttonDecrypt->Name = L"buttonDecrypt";
			this->buttonDecrypt->Size = System::Drawing::Size(101, 35);
			this->buttonDecrypt->TabIndex = 3;
			this->buttonDecrypt->Text = L"Decrypt";
			this->buttonDecrypt->UseVisualStyleBackColor = true;
			this->buttonDecrypt->Click += gcnew System::EventHandler(this, &encdata::buttonDecrypt_Click);
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->textBoxPassword->Location = System::Drawing::Point(31, 89);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(452, 26);
			this->textBoxPassword->TabIndex = 4;
			this->textBoxPassword->UseSystemPasswordChar = true;
			this->textBoxPassword->Enter += gcnew System::EventHandler(this, &encdata::textBoxPassword_Enter);
			// 
			// progressBarOperation
			// 
			this->progressBarOperation->Location = System::Drawing::Point(28, 143);
			this->progressBarOperation->Name = L"progressBarOperation";
			this->progressBarOperation->Size = System::Drawing::Size(455, 23);
			this->progressBarOperation->TabIndex = 5;
			// 
			// labelSelectedPath
			// 
			this->labelSelectedPath->AutoSize = true;
			this->labelSelectedPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->labelSelectedPath->Location = System::Drawing::Point(27, 19);
			this->labelSelectedPath->Name = L"labelSelectedPath";
			this->labelSelectedPath->Size = System::Drawing::Size(192, 20);
			this->labelSelectedPath->TabIndex = 6;
			this->labelSelectedPath->Text = L"No file or folder selected";
			// 
			// passwordlabel
			// 
			this->passwordlabel->AutoSize = true;
			this->passwordlabel->Location = System::Drawing::Point(35, 95);
			this->passwordlabel->Name = L"passwordlabel";
			this->passwordlabel->Size = System::Drawing::Size(112, 16);
			this->passwordlabel->TabIndex = 7;
			this->passwordlabel->Text = L"Enter a Password";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 288);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"1.0";
			// 
			// encdata
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(513, 313);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->passwordlabel);
			this->Controls->Add(this->labelSelectedPath);
			this->Controls->Add(this->progressBarOperation);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->buttonDecrypt);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->buttonSelectFolder);
			this->Controls->Add(this->buttonSelectFile);
			this->Name = L"encdata";
			this->Text = L"encdata";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
