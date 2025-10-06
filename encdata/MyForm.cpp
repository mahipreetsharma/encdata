#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Text;
using namespace System::IO::Compression;

[System::STAThreadAttribute]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    encdata::encdata form;
    Application::Run(%form);
}

void encdata::encdata::buttonSelectFile_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        selectedFilePath = openFileDialog->FileName;
        labelSelectedPath->Text = selectedFilePath;
    }
}

void encdata::encdata::buttonSelectFolder_Click(System::Object^ sender, System::EventArgs^ e) {
    FolderBrowserDialog^ folderDialog = gcnew FolderBrowserDialog();
    if (folderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        selectedFilePath = folderDialog->SelectedPath;
        labelSelectedPath->Text = selectedFilePath;
    }
}

void encdata::encdata::buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBarOperation->Value = 0;

    if (selectedFilePath == nullptr || textBoxPassword->Text->Length == 0) {
        MessageBox::Show("Please select a file or folder and enter a password.");
        return;
    }

    try {
        String^ tempDir = Path::GetTempPath();
        String^ tempZip = Path::Combine(tempDir, "encdata_temp_" + Guid::NewGuid().ToString() + ".zip");

        // Always zip, whether it's a file or a folder
        if (File::Exists(selectedFilePath)) {
            // For a single file — make a temp folder and copy the file there
            String^ tempFolder = Path::Combine(tempDir, "encdata_temp_folder_" + Guid::NewGuid().ToString());
            Directory::CreateDirectory(tempFolder);
            String^ fileName = Path::GetFileName(selectedFilePath);
            String^ tempFilePath = Path::Combine(tempFolder, fileName);
            File::Copy(selectedFilePath, tempFilePath, true);

            // Zip that folder
            ZipFile::CreateFromDirectory(tempFolder, tempZip);

            // Clean up temp folder
            Directory::Delete(tempFolder, true);
        }
        else if (Directory::Exists(selectedFilePath)) {
            // For a folder — just zip directly
            ZipFile::CreateFromDirectory(selectedFilePath, tempZip);
        }
        else {
            MessageBox::Show("Selected path is not valid.");
            return;
        }

        // Read the zip file into memory
        array<Byte>^ fileBytes = File::ReadAllBytes(tempZip);
        array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(textBoxPassword->Text);

        progressBarOperation->Minimum = 0;
        progressBarOperation->Maximum = fileBytes->Length;

        // XOR encrypt
        for (int i = 0; i < fileBytes->Length; ++i) {
            fileBytes[i] ^= passwordBytes[i % passwordBytes->Length];
            if (i % 4096 == 0 || i == fileBytes->Length - 1) {
                progressBarOperation->Value = i;
                Application::DoEvents();
            }
        }

        progressBarOperation->Value = fileBytes->Length;

        // Save encrypted file with .amava extension
        String^ folderName = Path::GetFileName(selectedFilePath);
        String^ parentDir = Path::GetDirectoryName(selectedFilePath);
        String^ outPath = Path::Combine(parentDir, folderName + ".amava");

        File::WriteAllBytes(outPath, fileBytes);

        // Clean up temp zip
        File::Delete(tempZip);

        MessageBox::Show("Encrypted successfully: " + outPath);
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }

    progressBarOperation->Value = 0;
}

void encdata::encdata::buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e) {
    progressBarOperation->Value = 0;
    if (selectedFilePath == nullptr || textBoxPassword->Text->Length == 0) {
        MessageBox::Show("Please select a file and enter a password.");
        return;
    }
    if (!File::Exists(selectedFilePath)) {
        MessageBox::Show("Selected path is not a file. Please select a file to decrypt.");
        return;
    }
    try {
        array<Byte>^ fileBytes = File::ReadAllBytes(selectedFilePath);
        array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(textBoxPassword->Text);
        progressBarOperation->Minimum = 0;
        progressBarOperation->Maximum = fileBytes->Length;
        for (int i = 0; i < fileBytes->Length; ++i) {
            fileBytes[i] ^= passwordBytes[i % passwordBytes->Length];
            if (i % 4096 == 0 || i == fileBytes->Length - 1) {
                progressBarOperation->Value = i;
                Application::DoEvents();
            }
        }
        progressBarOperation->Value = fileBytes->Length;
        String^ tempZip = Path::GetTempFileName() + ".zip";
        File::WriteAllBytes(tempZip, fileBytes);

        // Use .amava extension for output folder name
        String^ fileName = Path::GetFileNameWithoutExtension(selectedFilePath);
        String^ parentDir = Path::GetDirectoryName(selectedFilePath);
        String^ folderOut = Path::Combine(parentDir, fileName + "_decrypted");
        ZipFile::ExtractToDirectory(tempZip, folderOut);

        File::Delete(tempZip);

        MessageBox::Show("Folder decrypted to: " + folderOut);
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    progressBarOperation->Value = 0;
}

void encdata::encdata::textBoxPassword_Enter(System::Object^ sender, System::EventArgs^ e) {
    passwordlabel->Visible = false;
}

encdata::encdata::encdata(void)
{
    InitializeComponent();
}

encdata::encdata::~encdata()
{
    if (components)
    {
        delete components;
    }
}