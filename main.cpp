#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    int age;
};

vector<Student> database;

void addStudent()
{
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    // Check for duplicate roll number
    for(auto student : database)
    {
        if(student.rollNo == s.rollNo)
        {
            cout << "\nRoll Number Already Exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    database.push_back(s);

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    if(database.empty())
    {
        cout << "\nDatabase is Empty!\n";
        return;
    }

    cout << "\n===== Student Records =====\n";

    for(auto student : database)
    {
        cout << "Roll No: " << student.rollNo << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "---------------------\n";
    }
}

void searchStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for(auto student : database)
    {
        if(student.rollNo == roll)
        {
            cout << "\nStudent Found!\n";

            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void deleteStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    for(auto it = database.begin(); it != database.end(); it++)
    {
        if(it->rollNo == roll)
        {
            database.erase(it);

            cout << "\nStudent Deleted Successfully!\n";

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void updateStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    for(auto &student : database)
    {
        if(student.rollNo == roll)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, student.name);

            cout << "Enter New Age: ";
            cin >> student.age;

            cout << "\nStudent Updated Successfully!\n";

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void saveToFile()
{
    ofstream file("students.txt");

    for(auto student : database)
    {
        file << student.rollNo << endl;
        file << student.name << endl;
        file << student.age << endl;
    }

    file.close();

    cout << "\nDatabase Saved Successfully!\n";
}

void loadFromFile()
{
    ifstream file("students.txt");

    if(!file)
    {
        return;
    }

    Student s;

    while(file >> s.rollNo)
    {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        database.push_back(s);
    }

    file.close();

    cout << "\nDatabase Loaded Successfully!\n";
}

int main()
{
    int choice;

    loadFromFile();

    do
    {
        cout << "\n===== Mini Database Engine =====\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Save Database\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                updateStudent();
                break;

            case 6:
                saveToFile();
                break;

            case 7:
                saveToFile();

                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}