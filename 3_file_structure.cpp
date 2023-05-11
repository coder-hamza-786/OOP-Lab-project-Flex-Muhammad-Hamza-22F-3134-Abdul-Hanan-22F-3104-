#include "Admin.h"
#include "HOD.h"
#include "Teacher.h"
#include "Student.h"
#include "Login.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

//Made these strings special for 4 modes (A, H, T, S) to go back to their modes
string go_back;
string go_back_HOD;
string go_back_teacher;
string go_back_student;
string id, password;

//defined these cources for every other student because everyone will be of 22nd batch
string cource1 = "Programming Fundamentals";
string cource2 = "Linear Algebra";
string cource3 = "Calculus & Analytical Geometry";
string cource4 = "English Grammer and Comprehension";
string cource5 = "Pakistan Studies";
string cource6 = "Programming Fundamentals (Lab)";
string cource7 = "English Grammer and Comprehension (Lab)";
string cource8 = "Information and Communication Technology (Lab)";

Administrator :: Administrator() {}

void Administrator :: set_admin_id() {  cin.ignore(); getline(cin, admin_id); }
void Administrator :: set_admin_password() {  cin >> admin_password; }

string Administrator :: get_admin_id() { return admin_id; }
string Administrator :: get_admin_password() { return admin_password; }

Login :: Login() {
    id = "\0";
    password = "\0";
}

bool Login :: login(int choice) {
    //for administrator login
    while (true) {
        if (choice == 1) {
            string admin_password = "Hamza";
            string admin_id = "001";

            cout << "\n\nId = ";
            admin.set_admin_id();
            cout << "Password = ";
            admin.set_admin_password();

            if (admin_id == admin.get_admin_id() && admin_password == admin.get_admin_password()) {
                system("cls");
                cout << "\t\t\t\t\tWelcome Muhammad " << admin.get_admin_password() << endl << endl;
                cout << "Enter your password again to confirm.\n";
                return true;
                break;
            }
            else if (admin_id != admin.get_admin_id() || admin_password != admin.get_admin_password()) {
                cout << "Wrong ID or Password.\n\n";
                return false;
            }
        }
        //for login of teacher
        else if (choice == 2) {

            bool signed_in = false;
            ifstream teacher_file;
            teacher_file.open("Teacher.txt");

            if (!teacher_file) {
                cout << "Error: Unable to open file.\n";
            }

            bool found = false;
            cin.ignore();
            cout << "Enter your ID = "; getline(cin, id);
            cout << "Enter the password = "; getline(cin, password);

            string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, salarys;
            string teachers_passwords;

            while (!teacher_file.eof()) {
                getline(teacher_file, t_id);
                getline(teacher_file, p);
                getline(teacher_file, u_n);
                getline(teacher_file, d);
                getline(teacher_file, r_d);
                getline(teacher_file, salarys);
                getline(teacher_file, g);
                getline(teacher_file, c_n);
                getline(teacher_file, q);
                getline(teacher_file, a);

                if (id == t_id && password == p) {
                    cout << "Login Successful!" << endl;
                    /*logged_in_teacher = u_n;*/
                    found = true;
                    break;
                }
            }

            system("cls");
            if (found == true) {

                system("cls");
                cout << "\t\t\t\tWelcome " << u_n << endl << endl;
                /*teacher++;*/

            }
            else if (found == false) {
                while (true) {
                    cout << "\n\n\t\t\t\t\t\tWelcome to Flex";
                    cout << "\n\n1.Administrator" << endl;
                    cout << "2.Teacher" << endl;
                    cout << "3.Student" << endl;
                    cout << "4.HOD" << endl;
                    cout << "0.Exit" << endl << endl;
                    cout << "Incorrect ID or Password." << endl << endl;
                    cout << "\n\nEnter your ID = "; getline(cin, id);
                    cout << "Enter the password = "; getline(cin, password);
                    system("cls");
                    cout << "\t\t\t\tWelcome " << u_n << endl << endl;

                    while (!teacher_file.eof()) {
                        getline(teacher_file, t_id);
                        getline(teacher_file, p);
                        getline(teacher_file, u_n);
                        getline(teacher_file, d);
                        getline(teacher_file, r_d);
                        getline(teacher_file, salarys);
                        getline(teacher_file, g);
                        getline(teacher_file, c_n);
                        getline(teacher_file, q);
                        getline(teacher_file, a);

                        if (id == t_id && password == p) {
                            cout << "Login Successful!" << endl;
                            /*logged_in_teacher = u_n;*/
                            found = true;
                            break;
                        }
                    }
                    break;
                }

            }
            teacher_file.close();
            system("color 9");
            return found;
        }
        //for login of student
        else if (choice == 3) {
            fstream student_file;
            student_file.open("Student.txt", ios::in);
            if (!student_file) {
                cout << "Unable to open file.\n";
                system("cls");
            }
            bool found = false;
            string s_rn, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
            cout << "\nEnter your roll number = ";
            student.set_roll_number();
            cout << "Enter your password = ";
            student.set_student_password();
            while (!student_file.eof()) {
                getline(student_file, s_rn);
                getline(student_file, p);
                getline(student_file, u_n);
                getline(student_file, d);
                getline(student_file, r_d);
                getline(student_file, g);
                getline(student_file, c_n);
                getline(student_file, b_g);
                getline(student_file, f_s);
                getline(student_file, q);
                getline(student_file, m);
                getline(student_file, a);

                if (s_rn == student.get_roll_number() && p == student.get_student_password()) {
                    cout << "\n\nStudent Found!!";
                    found = true;
                    break;
                    system("cls");
                }
            }
            student_file.close();
            if (found) {
                system("cls");
                system("color 2");
                cout << "\t\t\t\tWelcome " << u_n << endl << endl;
                return true;
            }
            else {
                cout << "Incorrect ID or Password." << endl << endl;
                Sleep(500);
                system("cls");
            }
            return found;
        }
        //for login of HOD
        else if (choice == 4) {
            bool found = false;

            ifstream HOD_file;
            HOD_file.open("HOD.txt");

            string u_n, d, p;
            string HOD_id;

            getline(HOD_file, HOD_id);
            getline(HOD_file, p);
            getline(HOD_file, u_n);
            getline(HOD_file, d);

            while (true) {
                cout << "\n\nEnter the ID = ";
                hod.set_HOD_ID();

                cout << "\nEnter the password = ";
                hod.set_HOD_password();

                if (HOD_id == hod.get_HOD_ID() && p == hod.get_HOD_password()) {
                    cout << "\n\nHOD Found!!";
                    Sleep(500);
                    system("cls");
                    cout << "\t\t\t\tWelcome " << u_n << endl << endl;
                    break;
                }
                else if (HOD_id != hod.get_HOD_ID() && p != hod.get_HOD_password()) {
                    cout << "\n\nHOD not Found!!";
                    Sleep(500);
                    system("cls");
                }
            }
            system("color 4");
            HOD_file.close();
            break;
        }
    }
}

//This place is reserved for login of admin, HOD, teacher and student

void Administrator :: add_new_teacher() {

    Teacher teacher_obj;
    string gender, qualification, address, t_ID;
    bool found = false;
    while (true) {
        cout << "Enter the teacher ID = ";
        teacher_obj.set_teacher_ID();
        ifstream id_check;
        id_check.open("Teacher.txt");
        while (!id_check.eof()) {
            getline(id_check, t_ID);
            if (t_ID == teacher_obj.get_teacher_ID()) {
                cout << "Please enter another ID, this ID exists.\n\n";
            }
            else if (t_ID != teacher_obj.get_teacher_ID()) {
                found = true;
                break;
            }
        }
        if (found == true) {
            break;
        }
        id_check.close();
    }
    cout << "Enter the password = ";
    teacher_obj.set_teacher_password();
    cout << "Enter the first name of the teacher = ";
    teacher_obj.set_teacher_first_name();
    cout << "Enter the last name of the teacher = ";
    teacher_obj.set_teacher_last_name();

    teacher_obj.set_teacher_department();

    /*cout << "Enter the username of the teacher = ";
    teacher_obj.set_teacher_username();*/

    cout << "Enter the salary of the teacher = ";
    teacher_obj.set_teacher_salary();
    cout << "Enter the registration date(MM-DD-YYYY) = ";
    teacher_obj.set_teacher_registration_date();
    cout << "Enter the gender of the teacher = ";
    getline(cin, gender);
    cout << "Enter the contact number of the teacher = ";
    teacher_obj.set_teacher_contact_number();
    cout << "Enter the qualification of the teacher = ";
    cin.ignore();
    getline(cin, qualification);
    cout << "Enter the address of the teacher = ";
    getline(cin, address);

    ofstream teacher_file;
    teacher_file.open("Teacher.txt", ios::app);

    if (!teacher_file) {
        cout << "Unable to open file." << endl;
    }
    else {
        teacher_file << endl << teacher_obj.get_teacher_ID() << endl;
        teacher_file << teacher_obj.get_teacher_password() << endl;
        teacher_file << teacher_obj.get_teacher_first_name() << " ";
        teacher_file << teacher_obj.get_teacher_last_name() << endl;
        teacher_file << teacher_obj.get_teacher_department() << endl;
        teacher_file << teacher_obj.get_teacher_registration_date() << endl;
        teacher_file << teacher_obj.get_teacher_salary() << endl;
        teacher_file << gender << endl;
        teacher_file << teacher_obj.get_teacher_contact_number() << endl;
        teacher_file << qualification << endl;
        teacher_file << address;
    }
    teacher_file.close();

    cout << "\nTeacher successfully created.\n";
    Sleep(500);
}

void Administrator ::  add_new_student() {
    Student student_obj;
    cout << "Enter the roll number of the student = ";
    student_obj.set_roll_number();
    cout << "Enter the password = ";
    student_obj.set_student_password();
    cout << "Enter the first name of the student = ";
    student_obj.set_first_name();
    cout << "Enter the last name of the student = ";
    student_obj.set_last_name();
    cout << "Enter the department of the student = ";
    student_obj.set_department();

    /*cout << "Enter the username of the student = ";
    teacher_obj.set_student_username();*/


    cout << "Enter the registration date(MM-DD-YYYY) = ";
    student_obj.set_reg_date_student();
    cout << "Enter the gender of the student = ";
    student_obj.set_gender();
    cout << "Enter the contact number of the student = ";
    student_obj.set_student_contact_number();
    cout << "Enter the qualification of the student = ";
    student_obj.set_qualification();
    cout << "Enter the blood group of the student = ";
    student_obj.set_blood_group();
    cout << "Enter the fee status(P/NP) = ";
    student_obj.set_fee_status();
    cout << "Enter the percentage of marks students got in intermediate or O/A levels = ";
    student_obj.set_marks();
    cout << "Enter the address of the student = ";
    student_obj.set_address();

    ofstream student_file;
    student_file.open("Student.txt", ios::app);

    if (!student_file) {
        cout << "Unable to open file.\n";
    }
    else {

        student_file << endl << student_obj.get_roll_number() << endl;
        student_file << student_obj.get_student_password() << endl;
        student_file << student_obj.get_first_name() << " ";
        student_file << student_obj.get_last_name() << endl;
        student_file << student_obj.get_department() << endl;
        student_file << student_obj.get_reg_date_student() << endl;
        student_file << student_obj.get_gender() << endl;
        student_file << student_obj.get_contact_number() << endl;
        student_file << student_obj.get_blood_group() << endl;
        student_file << student_obj.get_fee_status() << endl;
        student_file << student_obj.get_qualification() << endl;
        student_file << student_obj.get_marks() << endl;
        student_file << student_obj.get_address();
    }
    student_file.close();

    cout << "Student successfully created.\n";
    Sleep(500);
}

void Administrator :: edit_teacher_details() {
    Teacher obj;

    string teacher_first_name, teacher_last_name, teacher_id, teacher_age, teacher_qualifcation;
    string teacher_department, teacher_gender, teacher_contactno, teacher_salary, teacher_password;
    string teacher_reg_date, teacher_address, teacher_usernames;

    cout << "Enter id of teacher you want to edit = ";
    string teacher_stored_data;
    cin.ignore();
    getline(cin, teacher_stored_data);
    ifstream teacher_delete;
    teacher_delete.open("Teacher.txt");
    ofstream teacher_new_data;
    teacher_new_data.open("new_teacher.txt");

    getline(teacher_delete, teacher_id);
    getline(teacher_delete, teacher_password);
    getline(teacher_delete, teacher_usernames);
    getline(teacher_delete, teacher_department);
    getline(teacher_delete, teacher_reg_date);
    getline(teacher_delete, teacher_salary);
    getline(teacher_delete, teacher_gender);
    getline(teacher_delete, teacher_contactno);
    getline(teacher_delete, teacher_qualifcation);
    getline(teacher_delete, teacher_address);

    while (!teacher_delete.eof())
    {
        if (teacher_id != teacher_stored_data)
        {
            teacher_new_data << teacher_id << endl;
            teacher_new_data << teacher_password << endl;
            teacher_new_data << teacher_usernames << endl;
            teacher_new_data << teacher_department << endl;
            teacher_new_data << teacher_reg_date << endl;
            teacher_new_data << teacher_salary << endl;
            teacher_new_data << teacher_gender << endl;
            teacher_new_data << teacher_contactno << endl;
            teacher_new_data << teacher_qualifcation << endl;
            teacher_new_data << teacher_address << endl;
        }
        else
        {
            cout << "Enter teacher ID ";
            obj.set_teacher_ID();
            cout << "Enter new teacher password = ";
            obj.set_teacher_password();
            cout << "Enter teacher username = ";
            obj.set_teacher_username();

            obj.set_teacher_department();
            cout << "Enter the registration date = ";
            obj.set_teacher_registration_date();
            cout << "Enter the new salary = ";
            obj.set_teacher_salary();
            cout << "Enter the gender = ";
            obj.set_teacher_gender();
            cout << "Enter the updated contact number = ";
            obj.set_teacher_contact_number();
            cout << "Enter the updated qualification of the teacher = ";
            obj.set_teacher_qualification();
            cout << "Enter the address = ";
            obj.set_teacher_address();

            teacher_new_data << obj.get_teacher_ID() << endl;
            teacher_new_data << obj.get_teacher_password() << endl;
            teacher_new_data << obj.get_teacher_user_name() << endl;
            teacher_new_data << obj.get_teacher_department() << endl;
            teacher_new_data << obj.get_teacher_registration_date() << endl;
            teacher_new_data << obj.get_teacher_salary() << endl;
            teacher_new_data << obj.get_teacher_gender() << endl;
            teacher_new_data << obj.get_teacher_contact_number() << endl;
            teacher_new_data << obj.get_teacher_qualification() << endl;
            teacher_new_data << obj.get_teacher_address() << endl;

        }
        getline(teacher_delete, teacher_id);
        getline(teacher_delete, teacher_password);
        getline(teacher_delete, teacher_usernames);
        getline(teacher_delete, teacher_department);
        getline(teacher_delete, teacher_reg_date);
        getline(teacher_delete, teacher_salary);
        getline(teacher_delete, teacher_gender);
        getline(teacher_delete, teacher_contactno);
        getline(teacher_delete, teacher_qualifcation);
        getline(teacher_delete, teacher_address);

    }
    teacher_delete.close();
    teacher_new_data.close();
    remove("Teacher.txt");
    rename("new_teacher.txt", "Teacher.txt");
}

void Administrator :: edit_student_details() {
    Student obj;
    string student_first_name, student_last_name, student_roll_number, student_qualifcation;
    string student_department, student_gender, student_contact_no, student_password, student_marks;
    string student_reg_date, student_address, student_blood_group, percentage_in_inter, student_fee_status;
    string student_usernames;

    cout << "Enter roll number of student you want to edit = ";
    string student_stored_data;
    cin >> student_stored_data;

    ifstream student_delete;
    student_delete.open("Student.txt");

    ofstream student_new_data;
    student_new_data.open("new_student.txt");
    getline(student_delete, student_roll_number);
    getline(student_delete, student_password);
    getline(student_delete, student_usernames);
    getline(student_delete, student_department);
    getline(student_delete, student_reg_date);
    getline(student_delete, student_gender);
    getline(student_delete, student_contact_no);
    getline(student_delete, student_blood_group);
    getline(student_delete, student_fee_status);
    getline(student_delete, student_qualifcation);
    getline(student_delete, student_marks);
    getline(student_delete, student_address);

    while (!student_delete.eof())
    {
        if (student_roll_number != student_stored_data)
        {
            student_new_data << student_roll_number << endl;
            student_new_data << student_password << endl;
            student_new_data << student_usernames << endl;
            student_new_data << student_department << endl;
            student_new_data << student_reg_date << endl;
            student_new_data << student_gender << endl;
            student_new_data << student_contact_no << endl;
            student_new_data << student_blood_group << endl;
            student_new_data << student_fee_status << endl;
            student_new_data << student_qualifcation << endl;
            student_new_data << student_marks << endl;
            student_new_data << student_address << endl;
        }
        else
        {
            cout << "Enter roll number = ";
            obj.set_roll_number();
            cout << "Enter new student password = ";
            obj.set_student_password();
            cout << "Enter student user name = ";
            obj.set_first_name();

            obj.set_department();
            cout << "Enter the registration date = ";
            obj.set_reg_date_student();
            cout << "Enter the gender = ";
            obj.set_gender();
            cout << "Enter the updated contact number = ";
            obj.set_student_contact_number();
            cout << "Enter the blood group = ";
            obj.set_blood_group();
            cout << "Enter the fee status = ";
            obj.set_fee_status();
            cout << "Enter the updated qualification of the student = ";
            obj.set_qualification();
            cout << "Enter the marks student got in " << obj.get_qualification() << ") = ";
            obj.set_marks();
            cout << "Enter the address = ";
            obj.set_address();

            student_new_data << obj.get_roll_number() << endl;
            student_new_data << obj.get_student_password() << endl;
            student_new_data << obj.get_student_user_name() << endl;
            student_new_data << obj.get_department() << endl;
            student_new_data << obj.get_reg_date_student() << endl;
            student_new_data << obj.get_gender() << endl;
            student_new_data << obj.get_contact_number() << endl;
            student_new_data << obj.get_blood_group() << endl;
            student_new_data << obj.get_fee_status() << endl;
            student_new_data << obj.get_qualification() << endl;
            student_new_data << obj.get_address() << endl;

        }

        getline(student_delete, student_roll_number);
        getline(student_delete, student_password);
        getline(student_delete, student_usernames);
        getline(student_delete, student_department);
        getline(student_delete, student_reg_date);
        getline(student_delete, student_gender);
        getline(student_delete, student_contact_no);
        getline(student_delete, student_blood_group);
        getline(student_delete, student_fee_status);
        getline(student_delete, student_qualifcation);
        getline(student_delete, student_marks);
        getline(student_delete, student_address);

    }
    student_delete.close();
    student_new_data.close();
    remove("Student.txt");
    rename("new_student.txt", "Student.txt");
}

void Administrator :: view_all_teachers() {
    int choice = 0;

    cout << "1.View All Teachers\n";
    cout << "2.View Teachers of certain Departments\n";
    cout << "3.Search Teacher by their Roll numbers\n";
    cout << "\n\nEnter your choice = ";
    cin >> choice;

    if (choice == 1) {
        string Teach_ID;

        fstream teacher_file;

        teacher_file.open("Teacher.txt");
        if (!teacher_file) {
            cout << "Unable to open file.\n";
        }

        string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, salary;
        while (!teacher_file.eof()) {

            getline(teacher_file, t_id);
            getline(teacher_file, p);
            getline(teacher_file, u_n);
            getline(teacher_file, d);
            getline(teacher_file, r_d);
            getline(teacher_file, salary);
            getline(teacher_file, g);
            getline(teacher_file, c_n);
            getline(teacher_file, q);
            getline(teacher_file, a);

            if (t_id == "") { continue; }

            cout << "Teacher ID = " << d << "-" << t_id << endl;
            cout << "Password = " << p << endl;
            cout << "Username = " << u_n << endl;
            cout << "Department = " << d << endl;
            cout << "Registration date = " << r_d << endl;
            cout << "Salary = " << salary << endl;
            cout << "Gender = " << g << endl;
            cout << "Contact number = " << c_n << endl;
            cout << "Qualification = " << q << endl;
            cout << "Address = " << a << endl << endl;

        }
        cout << "\n\nPress any key to go back = ";
        go_back = _getch();
        teacher_file.close();
    }
    else if (choice == 2) {
        string dep;
        int dep_choice = 0;
        cout << "\n\nSelect the Department: \n\n";
        cout << "1. Computer Sciences\n";
        cout << "2. Software Engeenering\n";
        cout << "3. Social Sciences\n";
        cout << "4. Electrical Engeneering\n";
        cout << "5. Bussiness\n";
        cout << "\nEnter your choice = ";
        cin >> dep_choice;
        while (true) {
            if (dep_choice == 1) {
                dep = "CS";
                break;
            }
            else if (dep_choice == 2) {
                dep = "SE";
                break;
            }
            else if (dep_choice == 3) {
                dep = "SC";
                break;
            }
            else if (dep_choice == 4) {
                dep = "EE";
                break;
            }
            else if (dep_choice == 5) {
                dep = "B";
                break;
            }
            else if (dep_choice != 1 && dep_choice != 2 && dep_choice != 3 && dep_choice != 4 && dep_choice != 5) {
                cout << "Invalid input.\n";
            }
            cout << "\nEnter your choice = ";
            cin >> dep_choice;
        }
        ifstream teacher_file;
        teacher_file.open("Teacher.txt");
        string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, salary;
        while (!teacher_file.eof()) {

            getline(teacher_file, t_id);
            getline(teacher_file, p);
            getline(teacher_file, u_n);
            getline(teacher_file, d);
            getline(teacher_file, r_d);
            getline(teacher_file, salary);
            getline(teacher_file, g);
            getline(teacher_file, c_n);
            getline(teacher_file, q);
            getline(teacher_file, a);

            if (d == dep) {
                cout << "Roll number = 22F-" << t_id << endl;
                cout << "Password = " << p << endl;
                cout << "User name = " << u_n << endl;
                cout << "Department = " << dep << endl;
                cout << "Registration date = " << r_d << endl;
                cout << "Salary = " << salary << endl;
                cout << "Gender = " << g << endl;
                cout << "Contact number = " << c_n << endl;
                cout << "Qualification = " << q << endl;
                cout << "Address = " << a << endl << endl;
            }
        }
        cout << "Press any key to go back.\n";
        go_back_student = _getch();
        teacher_file.close();
    }
    else if (choice == 3) {
        string Teach_ID;
        cout << "Enter the teacher ID = ";
        cin.ignore();
        getline(cin, Teach_ID);

        fstream teacher_file;
        teacher_file.open("Teacher.txt");
        if (!teacher_file) {
            cout << "Unable to open file.\n";
        }

        string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, salary;
        while (!teacher_file.eof()) {
            //teacher_file >> t_id >> p >> f_n >> l_n >> d >> r_d >> g >> c_n >> q >> a
            getline(teacher_file, t_id);
            getline(teacher_file, p);
            getline(teacher_file, u_n);
            getline(teacher_file, d);
            getline(teacher_file, r_d);
            getline(teacher_file, salary);
            getline(teacher_file, g);
            getline(teacher_file, c_n);
            getline(teacher_file, q);
            getline(teacher_file, a);

            if (t_id == Teach_ID) {

                cout << "Teacher ID = " << d << "-" << t_id << endl;
                cout << "Password = " << p << endl;
                cout << "Username = " << u_n << endl;
                cout << "Department = " << d << endl;
                cout << "Registration date = " << r_d << endl;
                cout << "Salary = " << salary << endl;
                cout << "Gender = " << g << endl;
                cout << "Contact number = " << c_n << endl;
                cout << "Qualification = " << q << endl;
                cout << "Address = " << a << endl << endl;
            }

        }
        cout << "\n\nPress any key to go back = ";
        go_back = _getch();
        teacher_file.close();
    }
}

void Administrator :: view_all_students() {
    int choice = 0;
    cout << "1.View All Students\n";
    cout << "2.View Students of certain Departments\n";
    cout << "3.Search Student by their Roll numbers\n";
    cout << "\n\nEnter your choice = ";
    cin >> choice;
    if (choice == 1) {
        ifstream student_file;
        student_file.open("Student.txt");
        if (!student_file) {
            cout << "Unable to open file.\n";
        }
        string s_RollNumber, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
        while (!student_file.eof()) {
            getline(student_file, s_RollNumber);
            getline(student_file, p);
            getline(student_file, u_n);
            getline(student_file, d);
            getline(student_file, r_d);
            getline(student_file, g);
            getline(student_file, c_n);
            getline(student_file, b_g);
            getline(student_file, f_s);
            getline(student_file, q);
            getline(student_file, m);
            getline(student_file, a);

            if (s_RollNumber == "") { continue; }

            cout << "Roll number = 22F-" << s_RollNumber << endl;
            cout << "Password = " << p << endl;
            cout << "User name = " << u_n << endl;
            cout << "Department = " << d << endl;
            cout << "Registration date = " << r_d << endl;
            cout << "Gender = " << g << endl;
            cout << "Contact number = " << c_n << endl;
            cout << "Blood Group = " << b_g << endl;
            cout << "Fee status = " << f_s << endl;
            cout << "Qualification = " << q << endl;
            cout << "Marks = " << m << "%" << endl;
            cout << "Address = " << a << endl << endl;
        }
        student_file.close();
        cout << "Press any key to go back.";
        go_back = _getch();
    }
    else if (choice == 2) {
        string dep;
        int dep_choice = 0;
        cout << "\n\nSelect the Department: \n\n";
        cout << "1. Computer Sciences\n";
        cout << "2. Software Engeenering\n";
        cout << "3. Social Sciences\n";
        cout << "4. Electrical Engeneering\n";
        cout << "5. Bussiness\n";
        cout << "\nEnter your choice = ";
        cin >> dep_choice;
        while (true) {
            if (dep_choice == 1) {
                dep = "CS";
                break;
            }
            else if (dep_choice == 2) {
                dep = "SE";
                break;
            }
            else if (dep_choice == 3) {
                dep = "SC";
                break;
            }
            else if (dep_choice == 4) {
                dep = "EE";
                break;
            }
            else if (dep_choice == 5) {
                dep = "B";
                break;
            }
            else if (dep_choice != 1 && dep_choice != 2 && dep_choice != 3 && dep_choice != 4 && dep_choice != 5) {
                cout << "Invalid input.\n";
            }
            cout << "\nEnter your choice = ";
            cin >> dep_choice;
        }
        ifstream student_file;
        student_file.open("Student.txt");
        string s_RollNumber, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
        while (!student_file.eof()) {
            getline(student_file, s_RollNumber);
            getline(student_file, p);
            getline(student_file, u_n);
            getline(student_file, d);
            getline(student_file, r_d);
            getline(student_file, g);
            getline(student_file, c_n);
            getline(student_file, b_g);
            getline(student_file, f_s);
            getline(student_file, q);
            getline(student_file, m);
            getline(student_file, a);

            if (dep == d) {
                cout << "Roll number = 22F-" << s_RollNumber << endl;
                cout << "Password = " << p << endl;
                cout << "User name = " << u_n << endl;
                cout << "Department = " << d << endl;
                cout << "Registration date = " << r_d << endl;
                cout << "Gender = " << g << endl;
                cout << "Contact number = " << c_n << endl;
                cout << "Blood Group = " << b_g << endl;
                cout << "Fee status = " << f_s << endl;
                cout << "Qualification = " << q << endl;
                cout << "Marks = " << m << "%" << endl;
                cout << "Address = " << a << endl << endl;

            }
        }
        cout << "Press any key to go back.\n";
        go_back_student = _getch();
        student_file.close();
    }
    else if (choice == 3) {
        string find_roll_number;
        cout << "Enter roll number = ";
        cin.ignore();
        getline(cin, find_roll_number);

        ifstream student_file;
        student_file.open("Student.txt");
        string s_RollNumber, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
        while (!student_file.eof()) {

            getline(student_file, s_RollNumber);
            getline(student_file, p);
            getline(student_file, u_n);
            getline(student_file, d);
            getline(student_file, r_d);
            getline(student_file, g);
            getline(student_file, c_n);
            getline(student_file, b_g);
            getline(student_file, f_s);
            getline(student_file, q);
            getline(student_file, m);
            getline(student_file, a);

            if (find_roll_number == s_RollNumber) {

                cout << "\nRoll number = 22F-" << s_RollNumber << endl;
                cout << "Password = " << p << endl;
                cout << "User name = " << u_n << endl;
                cout << "Department = " << d << endl;
                cout << "Registration date = " << r_d << endl;
                cout << "Gender = " << g << endl;
                cout << "Contact number = " << c_n << endl;
                cout << "Blood Group = " << b_g << endl;
                cout << "Fee status = " << f_s << endl;
                cout << "Qualification = " << q << endl;
                cout << "Marks = " << m << "%" << endl;
                cout << "Address = " << a << endl << endl;
                break;
            }
        }
        cout << "Press any key to go back.\t";
        go_back_student = _getch();
        student_file.close();
    }
}

void Administrator :: delete_teacher() {
    fstream out;
    fstream teacher_file;
    out.open("temp_teacher.txt", ios::out);
    teacher_file.open("Teacher.txt", ios::in);
    string Teacher_id;
    string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, s;
    cout << "Enter the teacher ID you want to delete = ";
    cin.ignore();
    getline(cin, Teacher_id);
    while (!teacher_file.eof()) {
        getline(teacher_file, t_id);
        getline(teacher_file, p);
        getline(teacher_file, u_n);
        getline(teacher_file, d);
        getline(teacher_file, r_d);
        getline(teacher_file, s);
        getline(teacher_file, g);
        getline(teacher_file, c_n);
        getline(teacher_file, q);
        getline(teacher_file, a);

        if (Teacher_id == t_id || t_id == "") { continue; }

        out << t_id << endl;
        out << p << endl;
        out << u_n << endl;
        out << d << endl;
        out << r_d << endl;
        out << s << endl;
        out << g << endl;
        out << c_n << endl;
        out << q << endl;
        out << a << endl;

        cout << "Teacher ID = " << t_id << endl;
        cout << "Password = " << p << endl;
        cout << "Username = " << u_n << endl;
        cout << "Department = " << d << endl;
        cout << "Registration date = " << r_d << endl;
        cout << "Salary = " << s << endl;
        cout << "Gender = " << g << endl;
        cout << "Contact number = " << c_n << endl;
        cout << "Qualification = " << q << endl;
        cout << "Address = " << a << endl << endl;
    }
    go_back = _getch();
    out.close();
    teacher_file.close();

    out.open("temp_teacher.txt", ios::in);
    teacher_file.open("Teacher.txt", ios::out);

    while (!out.eof()) {
        getline(out, t_id);
        getline(out, p);
        getline(out, u_n);
        getline(out, d);
        getline(out, r_d);
        getline(out, s);
        getline(out, g);
        getline(out, c_n);
        getline(out, q);
        getline(out, a);

        if (t_id == "") { continue; }

        teacher_file << t_id << endl;
        teacher_file << p << endl;
        teacher_file << u_n << endl;
        teacher_file << d << endl;
        teacher_file << r_d << endl;
        teacher_file << s << endl;
        teacher_file << g << endl;
        teacher_file << c_n << endl;
        teacher_file << q << endl;
        teacher_file << a << endl;
    }
    out.close();
    teacher_file.close();
}

void Administrator :: delete_student() {
    fstream out;
    fstream student_file;
    out.open("temp_student.txt", ios::out);
    student_file.open("Student.txt", ios::in);
    string roll_number;
    cout << "Enter the roll number = ";
    cin.ignore();
    getline(cin, roll_number);
    string s_Roll_Number, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
    while (!student_file.eof()) {
        getline(student_file, s_Roll_Number);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (roll_number == s_Roll_Number || s_Roll_Number == "") { continue; }

        out << s_Roll_Number << endl;
        out << p << endl;
        out << u_n << endl;
        out << d << endl;
        out << r_d << endl;
        out << g << endl;
        out << c_n << endl;
        out << b_g << endl;
        out << f_s << endl;
        out << q << endl;
        out << m << endl;
        out << a << endl;
    }
    cout << "\nStudent file deleted.\n";
    go_back = _getch();
    out.close();
    student_file.close();
    out.open("temp_student.txt", ios::in);
    student_file.open("Student.txt", ios::out);
    while (!out.eof()) {
        getline(out, s_Roll_Number);
        getline(out, p);
        getline(out, u_n);
        getline(out, d);
        getline(out, r_d);
        getline(out, g);
        getline(out, c_n);
        getline(out, b_g);
        getline(out, f_s);
        getline(out, q);
        getline(out, m);
        getline(out, a);

        if (s_Roll_Number == "") { continue; }

        student_file << s_Roll_Number << endl;
        student_file << p << endl;
        student_file << u_n << endl;
        student_file << d << endl;
        student_file << r_d << endl;
        student_file << g << endl;
        student_file << c_n << endl;
        student_file << b_g << endl;
        student_file << f_s << endl;
        student_file << q << endl;
        student_file << m << endl;
        student_file << a << endl;
    }
    out.close();
    student_file.close();
}

void Administrator :: set_time_table() {
    //in progress
    ofstream att;
    ifstream teacher_file;
    bool found = false;
    string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, subject, teacher_id, salary;
    string id, day;
    cout << "Enter the teacher ID = ";
    cin.ignore();
    getline(cin, teacher_id);
    teacher_file.open("Teacher.txt");
    while (!teacher_file.eof()) {
        getline(teacher_file, t_id);
        getline(teacher_file, p);
        getline(teacher_file, u_n);
        getline(teacher_file, d);
        getline(teacher_file, r_d);
        getline(teacher_file, salary);
        getline(teacher_file, g);
        getline(teacher_file, c_n);
        getline(teacher_file, q);
        getline(teacher_file, a);

        if (teacher_id == t_id) {
            teacher_id = t_id;
            found = true;
            break;
        }
    }

    int lectures = 0;
    int total_lectures = 0;
    string lecture_choice;
    string first_lecture;
    string second_lecture;
    string third_lecture;
    string fourth_lecture;
    string fifth_lecture;

    att.open("TimeTable.txt", ios::app);
    if (found == true) {
        cout << "You can set upto 5 classes in a days in a week:\n";
        cout << "Setting of " << u_n << "'s time table.\n";
        cout << "\n\nHow many lectures do you want to add = ";
        cin >> total_lectures;
        system("cls");
        //If total lectures are 5
        att << endl << t_id;
        if (total_lectures == 5) {
            while (lectures < total_lectures) {
                cout << "\nEnter the time slot in which you want to add the lecture:\n\n";
                cout << "1.	8:45	to	10:15\n";
                cout << "2.	10:15	to	11:45\n";
                cout << "3.	11:45	to	1:15\n";
                cout << "Namaaz and lunch break\n";
                cout << "4.	1:45	to	3:15\n";
                cout << "5.	3:15	to	4:45\n";

                cout << "\n\nEnter your choice = ";
                cin >> lecture_choice;
                string subject;
                if (lecture_choice == "1") {
                    first_lecture = "08:45	to	10:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":\t" << first_lecture << "\t";
                    att << subject << "\t on	";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "2") {
                    second_lecture = "\t10:15	to	11:45";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << second_lecture << "\t";
                    att << subject << "\t on	";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "3") {
                    third_lecture = "\t11:45	to	1:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << third_lecture << "\t";
                    att << subject << "\t on	";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "4") {
                    fourth_lecture = "\t01:45	to	03:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << fourth_lecture << "\t";
                    att << subject << "\t on	";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "5") {
                    fifth_lecture = "\t03:15	to	04:45";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << fifth_lecture << "\t";
                    att << subject << "\t on	";
                    att << day;
                    system("cls");
                }
                lectures++;
            }
        }
        //If total lectures are 4
        else if (total_lectures == 4) {
            lectures = 0;
            while (lectures < total_lectures) {
                cout << "Enter the time slot in which you want to add the lecture:\n\n";
                cout << "1.	08:45	to	10:15\n";
                cout << "2.	10:15	to	11:45\n";
                cout << "3.	11:45	to	1:15\n";
                cout << "Namaaz and lunch break\n";
                cout << "4.	01:45	to	3:15\n";
                cout << "5.	03:15	to	4:45\n";

                cout << "Enter your choice = ";
                cin >> lecture_choice;
                string subject;
                if (lecture_choice == "1") {
                    first_lecture = "\t08:45	to	10:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << first_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "2") {
                    second_lecture = "\t10:15	to	11:45";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << second_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "3") {
                    third_lecture = "\t11:45	to	01:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << third_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "4") {
                    fourth_lecture = "\t01:45	to	03:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << fourth_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "5") {
                    fifth_lecture = lectures + "\t 03:15	to	04:45";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":" << fifth_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                lectures++;
            }
            if (lectures == 4) {
                att << endl << "No Lecture";
            }
        }
        //If total lectures are 3
        else if (total_lectures == 3) {
            lectures = 0;
            while (lectures < total_lectures) {
                cout << "Enter the time slot in which you want to add the lecture:\n\n";
                cout << "1.	08:45	to	10:15\n";
                cout << "2.	10:15	to	11:45\n";
                cout << "3.	11:45	to	01:15\n";
                cout << "Namaaz and lunch break\n";
                cout << "4.	01:45	to	03:15\n";
                cout << "5.	03:15	to	04:45\n";

                cout << "Enter your choice = ";
                cin >> lecture_choice;
                string subject;
                if (lecture_choice == "1") {
                    first_lecture = "08:45	to	10:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":\t" << first_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "2") {
                    second_lecture = "10:15	to	11:45";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":\t" << second_lecture << "\t";
                    att << subject << "\ton ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "3") {
                    third_lecture = "11:45	to	01:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no." << lectures + 1 << ":\t" << third_lecture << "\t";
                    att << subject << "\ton ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "4") {
                    fourth_lecture = "01:45	to	03:15";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no. " << lectures + 1 << ":\t" << fourth_lecture << "\t";
                    att << subject << "\ton ";
                    att << day;
                    system("cls");
                }
                else if (lecture_choice == "5") {
                    fifth_lecture = "03:15	to	04:45";
                    cout << "Enter the subject = ";
                    cin >> subject;
                    cout << "Enter the day = ";
                    cin >> day;
                    att << endl << "Lecture no. " << lectures + 1 << ":\t" << fifth_lecture << "\t";
                    att << subject << "\t on ";
                    att << day;
                    system("cls");
                }
                lectures++;
                if (lectures == 3) {
                    att << endl << "No Lecture";
                    att << endl << "No Lecture";
                }
            }
        }
        else if (total_lectures > 5) {
            cout << "Too much lectures.\n";
        }
        else if (total_lectures < 3) {
            cout << "Too little lectures.\n";
        }
    }
    else {
        cout << "Teacher not found.\n";
        Sleep(500);
    }
    att.close();
}

void Administrator :: get_teacher_timetable() {
    bool found = false;
    string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, Username;
    string Teacher_ID, first_lecture, second_lecture, third_lecture, fourth_lecture, fifth_lecture;

    cout << "\n\nEnter the teacher's ID = ";
    cin.ignore();
    getline(cin, Teacher_ID);

    ifstream teacher_file;
    teacher_file.open("Teacher.txt");

    while (!teacher_file.eof()) {

        getline(teacher_file, t_id);
        getline(teacher_file, p);
        getline(teacher_file, u_n);
        getline(teacher_file, d);
        getline(teacher_file, r_d);
        getline(teacher_file, salary);
        getline(teacher_file, g);
        getline(teacher_file, c_n);
        getline(teacher_file, q);
        getline(teacher_file, a);

        if (Teacher_ID == t_id) {
            found = true;
            cout << "Teacher Found\n";
            Username = u_n;
            t_id = Teacher_ID;
            Sleep(500);
            system("cls");
            break;
        }
        else {
            cout << "Teacher not found.";
            system("cls");
        }

    }
    teacher_file.close();

    if (g == "Male" || g == "M" || g == "male" || g == "m") {
        cout << "Time table of Mr. " << u_n << ":\n\n";
    }
    else if (g == "Female" || g == "F" || g == "female" || g == "f") {
        cout << "Time table of Madam " << u_n << ":\n\n";
    }
    if (found == true) {
        ifstream att;
        ofstream show_att;

        att.open("TimeTable.txt");
        while (!att.eof()) {
            getline(att, t_id);
            getline(att, first_lecture);
            getline(att, second_lecture);
            getline(att, third_lecture);
            getline(att, fourth_lecture);
            getline(att, fifth_lecture);

            if (t_id == Teacher_ID) {
                cout << endl << first_lecture << endl;
                cout << second_lecture << endl;
                cout << third_lecture << endl;
                cout << fourth_lecture << endl;
                cout << fifth_lecture << endl << endl;
            }

        }
        cout << "Press any key to go back = ";
        go_back = _getch();
        att.close();
    }
}


HOD :: HOD() {}
HOD :: HOD(string d, string name, string p) :department(d), HOD_user_name(name), HOD_Password(p) {
    department = d;
    HOD_user_name = name;
    HOD_Password = p;
}

void HOD :: set_department() {
    cin >> department;
}
void HOD :: set_HOD_username() {
    cin.ignore();
    getline(cin, HOD_user_name);
}
void HOD :: set_HOD_password() {
    cin >> HOD_Password;
}
void HOD :: set_HOD_ID() {
    cin >> HOD_ID;
}
string HOD :: get_department() {
    return department;
}
string HOD :: get_HOD_username() {
    return HOD_user_name;
}
string HOD :: get_HOD_password() {
    return HOD_Password;
}
string HOD :: get_HOD_ID() {
    return HOD_ID;
}


//view all teachers
void HOD :: view_all_teachers() {
    fstream teacher_file;
    teacher_file.open("Teacher.txt");
    if (!teacher_file) {
        cout << "Unable to open file.\n";
    }
    bool b = false;
    string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p, salary;
    while (!teacher_file.eof()) {
        //teacher_file >> t_id >> p >> f_n >> l_n >> d >> r_d >> g >> c_n >> q >> a
        getline(teacher_file, t_id);
        getline(teacher_file, p);
        getline(teacher_file, u_n);
        getline(teacher_file, d);
        getline(teacher_file, r_d);
        getline(teacher_file, salary);
        getline(teacher_file, g);
        getline(teacher_file, c_n);
        getline(teacher_file, q);
        getline(teacher_file, a);

        if (t_id == "") { continue; }
        cout << "Teacher ID = " << d << "-" << t_id << endl;
        cout << "Password = " << p << endl;
        cout << "Username = " << u_n << endl;
        cout << "Department = " << d << endl;
        cout << "Registration date = " << r_d << endl;
        cout << "Salary = " << salary << endl;
        cout << "Gender = " << g << endl;
        cout << "Contact number = " << c_n << endl;
        cout << "Qualification = " << q << endl;
        cout << "Address = " << a << endl << endl;
    }
    cout << "\n\nPress any key to go back = ";
    go_back_HOD = _getch();
    system("cls");
    teacher_file.close();
}
//view all students
void HOD :: view_all_students() {
    ifstream student_file;
    student_file.open("Student.txt");
    if (!student_file) {
        cout << "Unable to open file.\n";
    }
    string s_RollNumber, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
    while (!student_file.eof()) {
        getline(student_file, s_RollNumber);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (s_RollNumber == "") { continue; }

        cout << "Roll number = 22F-" << s_RollNumber << endl;
        cout << "Password = " << p << endl;
        cout << "User name = " << u_n << endl;
        cout << "Department = " << d << endl;
        cout << "Registration date = " << r_d << endl;
        cout << "Gender = " << g << endl;
        cout << "Contact number = " << c_n << endl;
        cout << "Blood Group = " << b_g << endl;
        cout << "Fee status = " << f_s << endl;
        cout << "Qualification = " << q << endl;
        cout << "Marks = " << m << "%" << endl;
        cout << "Address = " << a << endl << endl;
    }
    student_file.close();
    cout << "Press any key to go back.";
    go_back_HOD = _getch();
}
//for viewing teacher's timetable
void HOD :: get_teacher_timetable() {

    string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p;
    string Teacher_ID, first_lecture, second_lecture, third_lecture, fourth_lecture, fifth_lecture;

    if (g == "Male" || g == "M" || g == "male" || g == "m") {
        cout << "\nTime table of Mr. " << u_n << ":\n\n";
    }
    else if (g == "Female" || g == "F" || g == "female" || g == "f") {
        cout << "\nTime table of Madam " << u_n << ":\n\n";
    }
    ifstream att;
    att.open("TimeTable.txt");

    while (!att.eof()) {
        getline(att, t_id);
        getline(att, first_lecture);
        getline(att, second_lecture);
        getline(att, third_lecture);
        getline(att, fourth_lecture);
        getline(att, fifth_lecture);

        cout << endl << first_lecture << endl;
        cout << second_lecture << endl;
        cout << third_lecture << endl;
        cout << fourth_lecture << endl;
        cout << fifth_lecture << endl << endl;

    }
    cout << "Press any key to go back = ";
    go_back_HOD = _getch();
    att.close();
}
//For viewing teacher activities

//These variables were created for recording data
//of teacher's movements into teacher_activities.txt
int teacher = 0;
int mark_att = 0;
int time_table = 0;
int check_att = 0;
int ass_marks = 0;
int ass_grades = 0;
int log_out = 0;
//to get logged in teacher's name
string logged_in_teacher;

void HOD :: check_teacher_activities() {
    int new_student = 0;
    int teach_activity = 0;
    ofstream teacher_open;
    teacher_open.open("Teacher_activities.txt", ios::app);
    //when teacher logs into the system
    if (teach_activity < teacher) {

        teacher_open << logged_in_teacher << " logged in." << endl;
        /*cout << endl << logged_in_teacher << " logged in." << endl;*/
        teach_activity++;

    }
    //when time table gets accesed in the teacher's mode
    if (time_table > 0) {

        teacher_open << logged_in_teacher << " checked time table." << endl;
        /*cout << logged_in_teacher << " checked time table." << endl;*/
        teach_activity++;

    }
    //for marking attendance
    if (mark_att > 0) {

        teacher_open << logged_in_teacher << " marked attendance." << endl;
        /*cout << logged_in_teacher << " marked attendance." << endl;*/
        teach_activity++;

    }
    //for checking attendance
    if (check_att > 0) {

        teacher_open << logged_in_teacher << " checked attendance." << endl;
        /*cout << logged_in_teacher << "checked attendance." << endl;*/
        teach_activity++;
    }
    //for assigning marks
    if (ass_marks > 0) {
        teacher_open << logged_in_teacher << " marked quizzez." << endl;
        /*cout << logged_in_teacher << " marked quizzez." << endl;*/
        teach_activity++;
    }
    //for assigning grades
    if (ass_grades > 0) {
        teacher_open << logged_in_teacher << " assigned grades." << endl;
        /*cout << logged_in_teacher << " assigned grades." << endl;*/
        teach_activity++;
    }
    //for logging out
    if (log_out > 0) {
        teacher_open << logged_in_teacher << " logged out." << endl;
        /*cout << logged_in_teacher << " logged out." << endl;*/
        teach_activity++;
        teacher = 0;
    }
    cout << "Teacher's activities have been updated, you can view them in their file.\n";
    teacher_open.close();
    go_back_HOD = _getch();
}

void Teacher :: set_teacher_first_name() {
    cin >> first_name;
}
void Teacher::set_teacher_last_name() {
    cin >> last_name;
}
//Just in case, we don't want to overload our operator of +
void Teacher :: set_teacher_username() {
    cin.ignore();
    getline(cin, teacher_username);
}
void Teacher :: set_teacher_ID() {
    while (true) {
        cin >> teacher_ID;
        if (teacher_ID == "001" || teacher_ID == "002" || teacher_ID == "003" || teacher_ID == "004" ||
            teacher_ID == "005" || teacher_ID == "006" || teacher_ID == "007" || teacher_ID == "008" ||
            teacher_ID == "009" || teacher_ID == "010") {

            break;

        }
        else {
            cout << "There are only ten teachers allowed in Fast (our) university.\n";
            cout << "Enter the teacher ID again = ";
        }
    }
}
void Teacher :: set_teacher_password() {
    cin.ignore();
    getline(cin, password);
}
void Teacher :: set_teacher_salary() {
    cin >> salary;
}
void Teacher :: set_teacher_department() {
    cout << "\n\nSelect the Department: \n\n";
    cout << "1. Computer Sciences\n";
    cout << "2. Software Engeenering\n";
    cout << "3. Social Sciences\n";
    cout << "4. Electrical Engeneering\n";
    cout << "5. Bussiness\n";
    while (true) {
        cout << "\nEnter your choice = ";
        cin >> department;
        if (department == "1") {
            department = "CS";
            break;
        }
        else if (department == "2") {
            department = "SE";
            break;
        }
        else if (department == "3") {
            department = "SC";
            break;
        }
        else if (department == "4") {
            department = "EE";
            break;
        }
        else if (department == "5") {
            department = "B";
            break;
        }
        else if (department != "1" && department != "2" && department != "3" && department != "4" && department != "5") {
            cout << "Invalid input.\n";
        }
    }
}
void Teacher :: set_teacher_registration_date() {
    cin.ignore();
    getline(cin, reg_date);
}
void Teacher :: set_teacher_gender() {
    cin >> gender;
}
void Teacher :: set_teacher_contact_number() {
    cin >> contact_number;
}
void Teacher :: set_teacher_qualification() {
    cin.ignore();
    getline(cin, qualification);
}
void Teacher :: set_teacher_address() {
    cin.ignore();
    getline(cin, address);
}

string Teacher :: get_teacher_salary() {
    return salary;
}
string Teacher :: get_teacher_first_name() {
    return first_name;
}
string Teacher :: get_teacher_last_name() {
    return last_name;
}
string Teacher :: get_teacher_username() {
    teacher_username = first_name + " " + last_name;
    return teacher_username;
}
string Teacher :: get_teacher_user_name() {
    return teacher_username;
}
string Teacher :: get_teacher_password() {
    return password;
}
string Teacher :: get_teacher_ID() {
    return teacher_ID;
}
string Teacher :: get_teacher_department() {
    return department;
}
string Teacher :: get_teacher_registration_date() {
    return reg_date;
}
string Teacher :: get_teacher_gender() {
    return gender;
}
string Teacher :: get_teacher_contact_number() {
    return contact_number;
}
string Teacher :: get_teacher_qualification() {
    return qualification;
}
string Teacher :: get_teacher_address() {
    return address;
}


void Teacher :: check_time_table() {
    bool found = false;
    string t_id, f_n, l_n, u_n, d, r_d, g, c_n, q, a, p;
    string Teacher_ID, first_lecture, second_lecture, third_lecture, fourth_lecture, fifth_lecture;
    ifstream teacher_file;

    teacher_file.open("Teacher.txt");
    while (!teacher_file.eof()) {
        getline(teacher_file, t_id);
        getline(teacher_file, p);
        getline(teacher_file, u_n);
        getline(teacher_file, d);
        getline(teacher_file, r_d);
        getline(teacher_file, g);
        getline(teacher_file, c_n);
        getline(teacher_file, q);
        getline(teacher_file, a);

        if (t_id == get_teacher_ID()) {

            cout << "Teacher found.\n";
            Sleep(500);
            system("cls");

            break;
        }
    }
    teacher_file.close();
    if (g == "Male" || g == "M" || g == "male" || g == "m") {
        cout << "Time table of Mr. " << u_n << ":\n\n";
    }
    else if (g == "Feale" || g == "F" || g == "female" || g == "f") {
        cout << "Time table of Madam " << u_n << ":\n\n";
    }

    ifstream att;
    ofstream show_att;
    att.open("TimeTable.txt");
    while (!att.eof()) {

        getline(att, t_id);
        getline(att, first_lecture);
        getline(att, second_lecture);
        getline(att, third_lecture);
        getline(att, fourth_lecture);
        getline(att, fifth_lecture);

        if (t_id == id) {

            cout << endl << first_lecture << endl;
            cout << second_lecture << endl;
            cout << third_lecture << endl;
            cout << fourth_lecture << endl;
            cout << fifth_lecture << endl << endl;
            time_table++;
            logged_in_teacher = u_n;
        }

    }
    cout << "Press any key to go back = ";
    go_back_teacher = _getch();
    att.close();
}

void Teacher :: mark_attendance() {
    ifstream student_file;
    student_file.open("Student.txt");
    bool present_or_not = 0;
    string s_Roll_Number, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p, date;
    cout << "Attendance:\n\n";
    ofstream attendance;
    attendance.open("Attendance.txt", ios::app);
    cout << "Enter the date(mm-dd-yyyy) = ";
    cin >> date;
    while (!student_file.eof()) {
        getline(student_file, s_Roll_Number);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (s_Roll_Number == "") { continue; }

        cout << "22F-" << s_Roll_Number << endl;
        cout << "Enter (P = 1 / NP = 0) = ";
        cin >> present_or_not;
        if (present_or_not == 0) {
            cout << date << ":\t";
            cout << "Absent" << endl << endl;
            attendance << endl << s_Roll_Number << "\n";
            attendance << date << "\t";
            attendance << f_n << "\t";
            attendance << l_n << "\t";
            attendance << "Absent";
            logged_in_teacher = u_n;
            mark_att++;
        }
        else if (present_or_not == 1) {
            cout << date << ":\t";
            cout << "Present" << endl << endl;
            attendance << endl << s_Roll_Number << "\n";
            attendance << date << "\t";
            attendance << f_n << "\t";
            attendance << l_n << "\t";

            attendance << "Present";

            logged_in_teacher = u_n;
            mark_att++;
        }
    }
    attendance.close();
    cout << "\nPress any key to go back.";
    go_back_teacher = _getch();
    student_file.close();
}

void Teacher :: check_attendance() {
    int b = 0;
    ifstream student_file;
    string date, att, s_rn, new_date;
    ifstream st_file;
    cout << endl << endl;

    student_file.open("Attendance.txt");
    while (!student_file.eof()) {

        student_file >> s_rn;
        student_file >> date;
        student_file >> att;
        if (s_rn == "") { continue; }
        if (date != new_date) { cout << endl; }
        new_date = date;
        cout << "(" << date << "):" << " 22F-" << s_rn << "------>" << att << endl;
        /*if (s_rn == get_roll_number())*/

    }
    check_att++;
    cout << "\n\nPress any key to go back.";
    go_back_teacher = _getch();
}

void Teacher :: assign_marks() {
    Student obj;
    ifstream student_file;
    ofstream marks_student;
    string roll_number;
    string s_Roll_Number, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p, date, registration_date_student;
    int total_marks, marks, quiz_number;

    student_file.open("Student.txt");
    marks_student.open("Student_marks.txt", ios::app);
    cout << "Enter the total marks of the quiz:";
    cin >> total_marks;
    cout << "Enter the number of quiz = ";
    cin >> quiz_number;
    while (!student_file.eof()) {
        getline(student_file, s_Roll_Number);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        cout << "22F-" << s_Roll_Number << " = ";
        while (true) {
            cin >> marks;
            if (marks > total_marks) {
                cout << "Invalid marks. (Marks greater than total marks)\n";
                cout << "Enter again = ";
                cin >> marks;
            }
            else if (marks <= total_marks) {
                break;
            }
        }
        marks_student << endl << quiz_number << "\t";
        marks_student << s_Roll_Number << "\t ";
        marks_student << marks << "\t";
        marks_student << total_marks;
    }
    ass_marks++;
    marks_student.close();
    cout << "Enter any key to go back.";
    go_back_teacher = _getch();
}

void Teacher :: assign_grades() {
    ifstream student_file;

    string Student_roll_number, Student_user_name;
    cout << "Enter the roll number of the student = ";
    cin.ignore();
    getline(cin, Student_roll_number);
    string s_rn, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
    student_file.open("Student.txt");
    while (!student_file.eof()) {
        getline(student_file, s_rn);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (s_rn == Student_roll_number) {
            Student_user_name = u_n;
            break;
        }
    }
    student_file.close();

    ifstream cource;
    cource.open("Cources.txt");

    ofstream Student_cources;
    Student_cources.open("Student_cources.txt", ios::app);

    string cource_1, cource_2, cource_3, cource_4, cource_5, cource_6, cource_7, cource_8, grade;
    while (!cource.eof()) {
        getline(cource, cource_1);
        getline(cource, cource_2);
        getline(cource, cource_3);
        getline(cource, cource_4);
        getline(cource, cource_5);
        getline(cource, cource_6);
        getline(cource, cource_7);
        getline(cource, cource_8);

        cout << "\n\nEnter the grade of " << Student_user_name << " in " << cource_1 << " = ";
        cin >> grade;
        Student_cources << endl << Student_roll_number << endl;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_2 << " = ";
        cin >> grade;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_3 << " = ";
        cin >> grade;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_4 << " = ";
        cin >> grade;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_5 << " = ";
        cin >> grade;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_6 << " = ";
        cin >> grade;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_7 << " = ";
        cin >> grade;
        Student_cources << grade << endl;

        cout << "Enter the grade of " << Student_user_name << " in " << cource_8 << " = ";
        cin >> grade;
        Student_cources << grade;

    }
    ass_grades++;
    Student_cources.close();
    cource.close();
}

void Teacher :: teacher_log_out() {
    log_out++;
    teacher++;
}


Student :: Student() {

    roll_number = "\0";
    first_name = "\0";
    last_name = "\0";
    student_username = "\0";
    department = "\0";
    password = "\0";
    reg_date_student = "\0";
    gender = "\0";
    contact_number = "\0";
    blood_group = "\0";
    address = "\0";
    fee_status = "\0";
    qualification = "\0";
    marks = "\0";

}

Student :: Student(string r, string f_n, string l_n, string u_n, string d, string p, string r_g_s, string g, string c_n,
    string b_g, string a, string f_s, string q, string m) {
    roll_number = r;
    first_name = f_n;
    last_name = l_n;
    student_username = u_n;
    department = d;
    password = p;
    reg_date_student = r_g_s;
    gender = g;
    contact_number = c_n;
    blood_group = b_g;
    address = a;
    fee_status = f_s;
    qualification = q;
    marks = m;
}

void Student :: set_first_name() {
    cin >> first_name;
}
void Student :: set_last_name() {
    cin >> last_name;
}
void Student :: set_student_user_name() {
    cin.ignore();
    getline(cin, student_username);
}
void Student :: set_roll_number() {
    cin >> roll_number;
}
void Student :: set_department() {
    cout << "\n\nSelect the Department: \n\n";
    cout << "1. Computer Sciences\n";
    cout << "2. Software Engeenering\n";
    cout << "3. Social Sciences\n";
    cout << "4. Electrical Engeneering\n";
    cout << "5. Bussiness\n";
    while (true) {
        cout << "\nEnter your choice = ";
        cin >> department;
        if (department == "1") {
            department = "CS";
            break;
        }
        else if (department == "2") {
            department = "SE";
            break;
        }
        else if (department == "3") {
            department = "SC";
            break;
        }
        else if (department == "4") {
            department = "EE";
            break;
        }
        else if (department == "5") {
            department = "B";
            break;
        }
        else if (department != "1" && department != "2" && department != "3" && department != "4" && department != "5") {
            cout << "Invalid input.\n";
        }
    }
}
void Student :: set_reg_date_student() {
    cin.ignore();
    getline(cin, reg_date_student);
}
void Student :: set_gender() {
    getline(cin, gender);
}
void Student :: set_student_contact_number() {
    cin >> contact_number;
}
void Student :: set_blood_group() {
    cin >> blood_group;
}
void Student :: set_address() {
    cin.ignore();
    getline(cin, address);
}
void Student :: set_fee_status() {
    cin >> fee_status;
}
void Student :: set_qualification() {
    string option;
    cout << "\n\nSelect the following option: \n\n";
    cout << "1.FSc(Pre-Engeenering)\n";
    cout << "2.FSc(Pre-Medical)\n";
    cout << "3.ICS(Pre-Engeenering)\n";
    while (true) {
        cout << "\nEnter the option = ";
        cin >> option;
        if (option == "1") {
            qualification = "FSc(Pre-Engeenering)";
            break;
        }
        else if (option == "2") {
            qualification = "FSc(Pre-Medical)";
            break;
        }
        else if (option == "3") {
            qualification = "ICS(Computer-Science)";
            break;
        }
        else {
            cout << "Invalid input.\n\n";
        }
    }
}
void Student :: set_marks() {
    cin.ignore();
    getline(cin, marks);
    if (marks > "0.0" && marks < "100.0") {
        cout << marks << endl;
    }
    else {
        cout << "Invalid input.\n";
    }
}
void Student :: set_student_password() {
    cin >> password;
}

string Student :: get_first_name() {
    return first_name;
}
string Student :: get_last_name() {
    return last_name;
}
string Student :: get_roll_number() {
    return roll_number;
}
string Student :: get_department() {
    return department;
}
string Student :: get_reg_date_student() {
    return reg_date_student;
}
string Student :: get_gender() {
    return gender;
}
string Student :: get_contact_number() {
    return contact_number;
}
string Student :: get_blood_group() {
    return blood_group;
}
string Student :: get_address() {
    return address;
}
string Student :: get_fee_status() {
    return fee_status;
}
string Student :: get_qualification() {
    return qualification;
}
string Student :: get_marks() {
    return marks;
}
string Student :: get_student_password() {
    return password;
}
string Student :: get_student_user_name() {
    student_username = first_name + ' ' + last_name;
    return student_username;
}


void Student :: view_attendance() {

    ifstream student_file;
    string s_rn, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
    string b = roll_number;
    string att, date;
    ifstream st_file;
    string attendance_rn;
    cout << endl << endl;
    st_file.open("Attendance.txt");
    while (!st_file.eof()) {
        st_file >> s_rn;
        st_file >> date;
        st_file >> att;

        if (s_rn == b) {
            cout << "Date: (" << date << ")----------->" << att << endl << endl;
        }
    }
    st_file.close();

    cout << "\n\nPress any key to go back.";
    go_back_student = _getch();
}

void Student :: view_marks() {
    ifstream student_file;
    student_file.open("Student_marks.txt");
    int c = 0;
    string s_rn, quiz_number, quiz_marks, total_marks, rOll_number;
    cout << endl;
    while (!student_file.eof()) {
        student_file >> quiz_number;
        student_file >> s_rn;
        student_file >> quiz_marks;
        student_file >> total_marks;

        if (s_rn == "") { continue; }
        if (c == 0) {
            cout << "Quiz.no    Roll number     Obtained marks      Total Marks\n\n";
            c++;
        }

        if (s_rn == get_roll_number()) {
            cout << "   " << quiz_number << "\t    22F-";
            cout << s_rn << " \t\t";
            cout << quiz_marks << "\t\t";
            cout << "   " << total_marks << endl;
        }
    }
    student_file.close();
    cout << "\n\nPress any key to go back.\n";
    go_back_student = _getch();
}

void Student :: view_grades() {
    string student_roll_number, Student_username;
    ifstream student_file;
    string s_rn, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p;
    student_file.open("Student.txt");
    while (!student_file.eof()) {
        getline(student_file, s_rn);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (s_rn == get_roll_number()) {
            student_roll_number = s_rn;
            Student_username = u_n;
            break;
        }
    }
    student_file.close();

    string cource_1, cource_2, cource_3, cource_4, cource_5, cource_6, cource_7, cource_8;
    ifstream Student_cources;
    Student_cources.open("Student_cources.txt");
    while (!Student_cources.eof()) {
        getline(Student_cources, s_rn);
        getline(Student_cources, cource_1);
        getline(Student_cources, cource_2);
        getline(Student_cources, cource_3);
        getline(Student_cources, cource_4);
        getline(Student_cources, cource_5);
        getline(Student_cources, cource_6);
        getline(Student_cources, cource_7);
        getline(Student_cources, cource_8);

        if (s_rn == student_roll_number) {

            cout << "\nGrades of " << Student_username << ":\n\n";
            cout << "Grade of " << Student_username << " in " << cource1 << " " << cource_1 << endl;
            cout << "Grade of " << Student_username << " in " << cource2 << " " << cource_2 << endl;
            cout << "Grade of " << Student_username << " in " << cource3 << " " << cource_3 << endl;
            cout << "Grade of " << Student_username << " in " << cource4 << " " << cource_4 << endl;
            cout << "Grade of " << Student_username << " in " << cource5 << " " << cource_5 << endl;
            cout << "Grade of " << Student_username << " in " << cource6 << " " << cource_6 << endl;
            cout << "Grade of " << Student_username << " in " << cource7 << " " << cource_7 << endl;
            cout << "Grade of " << Student_username << " in " << cource8 << " " << cource_8 << endl;

        }
    }
    cout << "\n\nPress any key to go back.\n";
    go_back_student = _getch();
    Student_cources.close();
}

void Student :: view_registered_cources() {
    ifstream student_file;
    string s_rn, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p, Roll_numbers;
    student_file.open("Student.txt");
    while (!student_file.eof()) {
        getline(student_file, s_rn);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (s_rn == get_roll_number()) {
            cout << "\n\n";
            cout << "Cources of " << u_n << ":\n\n";
            cout << "1. " << cource1 << endl;
            cout << "2. " << cource2 << endl;
            cout << "3. " << cource3 << endl;
            cout << "4. " << cource4 << endl;
            cout << "5. " << cource5 << endl;
            cout << "6. " << cource6 << endl;
            cout << "7. " << cource7 << endl;
            cout << "8. " << cource8 << endl;
        }
    }
    student_file.close();
    cout << "\nPress any key to continue.\n";
    go_back_student = _getch();
}

void Student :: view_fee_status() {

    string s_rn, f_n, l_n, u_n, d, r_d, g, c_n, b_g, f_s, q, m, a, p, Username, Fee_status;
    ifstream student_file;
    student_file.open("Student.txt");
    while (!student_file.eof()) {
        getline(student_file, s_rn);
        getline(student_file, p);
        getline(student_file, u_n);
        getline(student_file, d);
        getline(student_file, r_d);
        getline(student_file, g);
        getline(student_file, c_n);
        getline(student_file, b_g);
        getline(student_file, f_s);
        getline(student_file, q);
        getline(student_file, m);
        getline(student_file, a);

        if (s_rn == get_roll_number()) {
            if (f_s == "P") {
                Fee_status = "Paid";
                Username = u_n;
            }
            else if (f_s == "NP") {
                Fee_status = "Not Paid";
                Username = u_n;
            }
        }
    }

    cout << "\nFee status of " << Username << " :------------> " << Fee_status << endl << endl;
    cout << "Press any key to go back.";
    go_back_student = _getch();
}