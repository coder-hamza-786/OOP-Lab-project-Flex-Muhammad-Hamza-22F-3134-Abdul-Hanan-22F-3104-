#pragma once
#include "Student.h"
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class Teacher :public Student{
private:
    //attributes of teachers
    string first_name;
    string last_name;
    string department;
    string teacher_ID;
    string teacher_username;
    string password;
    string reg_date;
    string salary;
    string gender;
    string contact_number;
    string qualification;
    string address;
public:
    //setters and getters of teachers
    void set_teacher_first_name();
    void set_teacher_last_name();
    //Just in case, we don't want to overload our operator of +
    void set_teacher_username();
    void set_teacher_ID();
    void set_teacher_password();
    void set_teacher_salary();
    void set_teacher_department();
    void set_teacher_registration_date();
    void set_teacher_gender();
    void set_teacher_contact_number();
    void set_teacher_qualification();
    void set_teacher_address();

    string get_teacher_salary();
    string get_teacher_first_name();
    string get_teacher_last_name();
    string get_teacher_username();
    string get_teacher_user_name();
    string get_teacher_password();
    string get_teacher_ID();
    string get_teacher_department();
    string get_teacher_registration_date();
    string get_teacher_gender();
    string get_teacher_contact_number();
    string get_teacher_qualification();
    string get_teacher_address();


    //For viewing time table
    void check_time_table();

    //For marking attendance
    void mark_attendance();

    //For checking attendance
    void check_attendance();

    //For assigning marks
    void assign_marks();

    //For assigning grades
    void assign_grades();

    //For logging out
    //P.S: Made this function to keep the work data performed by teachers
    void teacher_log_out();

    //Made this class as friend class for accessing Admins functions
    friend class Administrator;
};