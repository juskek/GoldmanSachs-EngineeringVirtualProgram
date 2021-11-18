#include <iostream>
#include <fstream>
// #include <experimental/filesystem>
#include <string.h>
using std::string;

string readFile(string fileName);
void createFile(string fileName);
void writeFile(string fileName, string contents);
bool checkFileExists(string fileName);

int main()
{
    std::cout << __cplusplus << std::endl; // print c++ version no
    std::cout << "Password Cracker Tracker\n";
    std::cout << "Reading Password Dump...\n";

    string passwordDumpText = readFile("PasswordDump.txt");
    string passwordDumpPara = "// PASSWORD DUMP\n" + passwordDumpText + "\n\n";

    string crackedPara = "// CRACKED\n";
    string uncrackedPara = "// UNCRACKED\n";
    string fileText;

    bool fileExists = checkFileExists("CrackedTracker.txt");
    if (fileExists)
    {
        // check file contents
        std::cout << "File exists, editing...";
    }
    else
    {
        // create file
        std::cout << "No tracker file, creating...";
        createFile("CrackedTracker.txt");
        crackedPara = "// CRACKED\n";
        uncrackedPara = "// UNCRACKED\n";

        fileText = passwordDumpPara + crackedPara + uncrackedPara;
        writeFile("CrackedTracker.txt", fileText);
    }
}

bool checkFileExists(string fileName)
{
    return std::filesystem::exists(fileName);
}

void createFile(string fileName)
{
    std::ofstream outfile(fileName);

    outfile << "my text here!" << std::endl;

    outfile.close();
}
void writeFile(string fileName, string contents)
{
    std::ofstream myfile(fileName);
    if (myfile.is_open())
    {
        myfile << contents;
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
}

string readFile(string fileName)
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    std::ifstream MyReadFile(fileName);

    // Use a while loop together with the get() function to read the file char by char
    char value;
    string text;
    while (MyReadFile.get(value))
    {
        text.push_back(value);
    }
    // Output the text from the file
    // std::cout << text;

    // Close the file
    MyReadFile.close();
    return text;
}