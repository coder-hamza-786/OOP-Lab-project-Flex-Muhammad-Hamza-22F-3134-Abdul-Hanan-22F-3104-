#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    //attributes of students
    string roll_number;
    string first_name;
    string last_name;
    string student_username;
    string department;
    string password;
    string reg_date_student;
    string gender;
    string contact_number;
    string blood_group;
    string address;
    string fee_status;
    string qualification;
    string marks;

public:
    //Default constructor
    Student();

    //Parameterised constructor
    Student(string r, string f_n, string l_n, string u_n, string d, string p, string r_g_s, string g, string c_n,
        string b_g, string a, string f_s, string q, string m);

    //setters and getters of students
    void set_first_name();
    void set_last_name();
    void set_student_user_name();
    void set_roll_number();
    void set_department();
    void set_reg_date_student();
    void set_gender();
    void set_student_contact_number();
    void set_blood_group();
    void set_address();
    void set_fee_status();
    void set_qualification();
    void set_marks();
    void set_student_password();

    string get_first_name();
    string get_last_name();
    string get_roll_number();
    string get_department();
    string get_reg_date_student();
    string get_gender();
    string get_contact_number();
    string get_blood_group();
    string get_address();
    string get_fee_status();
    string get_qualification();
    string get_marks();
    string get_student_password();
    string get_student_user_name();

    //definitions of options of students
    void view_attendance();

    //For viewing marks
    void view_marks();

    //For viewing grades set by teacher
    void view_grades();

    //For viewing registered cources
    void view_registered_cources();

    //For viewing fee status
    void view_fee_status();

    //Made this class as friend class for accessing Admins functions
    void friend operator+(const string obj, const string obj1) {
        string u_n;
        u_n = obj + ' ' + obj1;
        cout << u_n;
    }

    friend class Administrator;
};