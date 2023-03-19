#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;


class Student {
private:
    string id;
    string name;
    string sex;
    string phoneNumber;
    string address;
    string dateOfBirth;
    string password;

public:
    Student(string id, string name, string sex, string phoneNumber, string address, string dateOfBirth, string password)
        : id(id), name(name), sex(sex), phoneNumber(phoneNumber), address(address), dateOfBirth(dateOfBirth), password(password) {}

    virtual void viewInfo() {
        cout << "ID           : " << id << "\t";
        cout << "Name         : " << name << "\t";
        cout << "Sex          : " << sex << "\t";
        cout << "Phone        : " << phoneNumber << "\t";
        cout << "Address      : " << address << "\t";
        cout << "Date Of Birth: " << dateOfBirth << "\t";
    }

    string getId() {
        return id;
    }
    void setId(string newId) {
        id = newId;
    }
    string getName() {
        return name;
    }
    void setName(string newName) {
        name = newName;
    }
    string getSex() {
        return sex;
    }
    void setSex(string newSex) {
        sex = newSex;
    }
    string getPhoneNumber() {
        return phoneNumber;
    }
    void setPhoneNumber(string newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    string getAddress() {
        return address;
    }
    void setAddress(string newAddress) {
        address = newAddress;
    }
    string getDateOfBirth() {
        return dateOfBirth;
    }
    void setDateOfBirth(string newDateOfBirth) {
        dateOfBirth = newDateOfBirth;
    }
    string getPassword() {
        return password;
    }
    void setPassword(string newPassword) {
        password = newPassword;
    }
};

class FulltimeStudent : public Student {
public:
    string nameClass;
    FulltimeStudent(string id, string name, string sex, string phoneNumber, string address, string dateOfBirth, string password, string nameClass)
        : Student(id, name, sex, phoneNumber, address, dateOfBirth, password), nameClass(nameClass) {}

    void viewInfo() override {
        Student::viewInfo();
        cout << "Enter Class: " << nameClass << "'t";
    }
};

class PartimeStudent : public Student {
public:
    string nameClass;
    string course;
    string shift;

    PartimeStudent(string id, string name, string sex, string phoneNumber, string address, string dateOfBirth, string password, string nameClass, string course, string shift)
        : Student(id, name, sex, phoneNumber, address, dateOfBirth, password), nameClass(nameClass), course(course), shift(shift) {}

    void viewInfo() override {
        Student::viewInfo();
        cout << "Enter Class : " << nameClass << endl;
        cout << "Enter course: " << course << endl;
        cout << "Enter Shift : " << shift << endl;
    }
    string getNameClass() {
        return nameClass;
    }
    void setAddress(string newNameClass) {
        nameClass = newNameClass;
    }
    string getCourse() {
        return course;
    }
    void setCourse(string newCourse) {
        course = newCourse;
    }
    string getShift() {
        return shift;
    }
    void setPassword(string newShift) {
        shift = newShift;
    }
};

class StudentManagementSystem {
private:
    vector<Student*> Students;

public:
    vector<Student*> getStudents() {
        return Students;
    }
    void createStudents() {
        system("cls");
        char userChoice;
        while (1) {
            cout << "Which Student's type do you want to create?\n\t[1] Full time Student \n\t[2] Part time Student\n\t[0] Exit\n\n Enter Your Choice(0-2): ";
            cin >> userChoice;
            cout << endl << endl;
            if (userChoice == '1') {
                createFulltimeStudent();
            }
            else if (userChoice == '2') {
                createPartimeStudent();
            }
            else if (userChoice == '0') {
                break;
            }
        }
    }
    void createFulltimeStudent() {
        string id, name, sex, phoneNumber, address, dateOfBirth, nameClass, password;
        cout << "Enter Student ID           : ";
        cin >> id;
        cout << "Enter Student name         : ";
        cin >> name;
        cout << "Enter Student sex          : ";
        cin >> sex;
        cout << "Enter Student phone number : ";
        cin >> phoneNumber;
        cout << "Enter Student address      : ";
        cin >> address;
        cout << "Enter date of birth        : ";
        cin >> dateOfBirth;
        cout << "Enter Class                :";
        cin >> nameClass;
        cout << "Assign password for that Student: ";
        cin >> password;
        FulltimeStudent* newStudent = new FulltimeStudent(id, name, sex, phoneNumber, address, dateOfBirth, nameClass, password);
        Students.push_back(newStudent);
        cout << "Full-time Student created successfully...\n\n" << endl;
    }

    void createPartimeStudent() {
        string id, name, sex, phoneNumber, address, dateOfBirth, password;
        cout << "Enter Student ID          : ";
        cin >> id;
        cout << "Enter Student name        : ";
        cin >> name;
        cout << "Enter Student sex         : ";
        cin >> sex;
        cout << "Enter Student phone number: ";
        cin >> phoneNumber;
        cout << "Enter Student address     : ";
        cin >> address;
        cout << "Enter date of birth       : ";
        cin >> dateOfBirth;
        // cout << "Enter Student type (1: Full-time, 2: Part-time): ";

        string nameClass, course, shift;
        cout << "Enter class                  : ";
        cin >> nameClass;
        cout << "Enter Course                 : ";
        cin >> course;
        cout << "Enter shift                  : ";
        cin >> shift;
        cout << "Assign password for Student  : ";
        cin >> password;

        PartimeStudent* newStudent = new PartimeStudent(id, name, sex, phoneNumber, address, dateOfBirth, password, nameClass, course, shift);
        Students.push_back(newStudent);
        cout << "Part-time Student created successfully...\n\n" << endl;
    }

    void deleteStudent() {
        system("cls");
        string id;
        cout << "Enter Student ID to delete: ";
        cin >> id;
        for (int i = 0; i < Students.size(); i++) {
            if (Students[i]->getId() == id) {
                int choiceChoosed;
                Students[i]->viewInfo();
                cout << "Are you sure to delete?\n1. Yes\n2. No\n Enter your choice(1-2): ";
                cin >> choiceChoosed;
                if (choiceChoosed == 1) {
                    delete Students[i];
                    Students.erase(Students.begin() + i);
                    cout << "Student deleted successfully..." << endl;
                }
                else {
                    cout << "Deleting canceled successfully..." << endl;
                }
                return;
            }
            else {
                cout << "Student not found..." << endl;
            }
        }

    }

    void searchStudent() {
        system("cls");
        string id;
        cout << "Enter Student ID to search: ";
        cin >> id;
        for (int i = 0; i < Students.size(); i++) {
            if (Students[i]->getId() == id) {
                Students[i]->viewInfo();
                return;
            }
            else {
                cout << "Student not found!" << endl;
            }
        }

    }

    void editStudent() {
        system("cls");
        string id;
        cout << "Enter Student ID to edit: ";
        cin >> id;
        for (int i = 0; i < Students.size(); i++) {
            if (Students[i]->getId() == id) {
                Students[i]->viewInfo();
                int option;
                cout << "Enter option to edit (1: Name, 2: Sex, 3: Phone Number, 4: Address, 5: Date of Birth: ";
                cin >> option;
                if (option == 1) {
                    string name;
                    cout << "Enter new name: ";
                    cin >> name;
                    Students[i]->setName(name);
                    break;
                }
                else if (option == 2) {
                    string sex;
                    cout << "Enter new sex: ";
                    cin >> sex;
                    Students[i]->setSex(sex);
                    break;
                }
                else if (option == 3) {
                    string phoneNumber;
                    cout << "Enter new phone number: ";
                    cin >> phoneNumber;
                    Students[i]->setPhoneNumber(phoneNumber);
                    break;
                }
                else if (option == 4) {
                    string address;
                    cout << "Enter new address: ";
                    cin >> address;
                    Students[i]->setAddress(address);
                    break;
                }
                else if (option == 5) {
                    string dateOfBirth;
                    cout << "Enter new date of birth: ";
                    cin >> dateOfBirth;
                    Students[i]->setDateOfBirth(dateOfBirth);
                    break;
                }
                else {
                    cout << "Invalid field!" << endl;
                    return;
                }
                cout << "Student's information updated successfully..." << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    void showAllStudent() {
        system("cls");
        if (Students.size() <= 0) {
            cout << "There is no Student yet!\n\n\n\n";
        }
        else {
            for (int i = 0; i < Students.size(); i++) {
                system("cls");
                cout << "======================================================================" << endl;
                cout << "               \t  Student's Record Info                " << endl;
                cout << "\n====================================================================\n";
                Students[i]->viewInfo();
                cout << "\n====================================================================\n\n\n\n";
            }
        }
    }
};

class AuthenticationManager {
public:
    tuple<int, int> login(vector<Student*> Students) {
        string username, password;
        cout << "========================================================\n";
        cout << "\t\t\tLogin Panel\n";
        cout << "========================================================\n";
        cout << "\t[!] Please log in to use this software\n\tUsername: ";
        cin >> username;
        cout << "\tPassword: ";
        cin >> password;
        if (username == "admin" && password == "admin123") {
            cout << "Login successfully..." << endl << endl;
            return make_tuple(1, 0);
        }
        else {
            for (int i = 0; i < Students.size(); i++) {
                if (Students[i]->getId() == username) {
                    if (Students[i]->getId() == username) {
                        cout << "Login successful!" << endl << endl;
                        return make_tuple(2, i);
                    }
                }
            }
            system("cls");
            cout << "[!] Invalid username or password. Please try again.\n" << endl;
            return make_tuple(0, 0);;
        }
    }
    void loginAsAdmin(vector<Student*> Students) {
        system("cls");
        char choiceChar;
        StudentManagementSystem sManageSystem;
        AuthenticationManager authh;
        while (1) {
            cout << "===============================\n";
            cout << "    Admin Control Panel!!!\n";
            cout << "===============================\n";
            cout << "\n\t[1]. Add Students"
                << "\n\t[2]. Edit Students"
                << "\n\t[3]. Delete Students"
                << "\n\t[4]. Search Students"
                << "\n\t[5]. Show All Students"
                << "\n\t[6]. Log out"
                << "\n\t[0]. Exit\n";
            cout << "\nEnter Your choice(0-6): ";
            cin >> choiceChar;
            if (choiceChar == '0') {
                exit(0);
            }
            else if (choiceChar == '1') {
                sManageSystem.createStudents();
            }
            else if (choiceChar == '2') {
                sManageSystem.editStudent();
            }
            else if (choiceChar == '3') {
                sManageSystem.deleteStudent();
            }
            else if (choiceChar == '4') {
                sManageSystem.searchStudent();
            }
            else if (choiceChar == '5') {
                sManageSystem.showAllStudent();
            }
            else if (choiceChar == '6') {
                system("cls");
                cout << "signed out!\n";
                break;
            }
        }
    }
    void loginAsStudent(Student* Student) {
        system("cls");
        char choiceChar;
        StudentManagementSystem sManageSystem;
        AuthenticationManager authh;
        while (1) {
            cout << ">> Welcome, Student\n";
            cout << "\n\t[1] -> View your info"
                << "\n\t[2] -> Logout"
                << "\n\t[0] -> Exit\n";
            cout << "Enter Your Choice(0-2): ";
            cin >> choiceChar;
            if (choiceChar == '0') {
                exit(0);
            }
            else if (choiceChar == '1') {
                Student->viewInfo();
            }
            else if (choiceChar == '2') {
                system("cls");
                cout << "signed out!\n";
                break;
            }
            else {
                cout << "Invalid Choice.";
            }
        }
    }
};

int main() {
    StudentManagementSystem StudentSystem;
    AuthenticationManager auth;
    while (1) {
        tuple<int, int> loginNumber = auth.login(StudentSystem.getStudents());
        if (get<0>(loginNumber) == 1) {
            auth.loginAsAdmin(StudentSystem.getStudents());
        }
        else if (get<0>(loginNumber) == 2) {
            vector<Student*> tempStudents = StudentSystem.getStudents();
            auth.loginAsStudent(tempStudents[get<1>(loginNumber)]);
        }
    }
    return 0;
}
