#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "HOD.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;
class Administrator : public Student, public Teacher {
private:
	//Pre-defined usernames and passwords of admin
	string admin_id = "Hamza";
	string admin_password = "001";
public:
	Administrator();
	void set_admin_id();
	void set_admin_password();

	string get_admin_id();
	string get_admin_password();

	//For login of admin, password and id would be saved in the code
	void login();

	//Addition of teacher
	void add_new_teacher();

	//Addition of student
	void add_new_student();

	//For editing the teacher details
	void edit_teacher_details();

	//For editing student details
	void edit_student_details();
	
	//For viewing all teachers
	void view_all_teachers();

	//For viewing all students
	void view_all_students();

	//For deletion of teachers
	void delete_teacher();

	//For deletion of students
	void delete_student();

	//For setting time table of Teachers
	void set_time_table();

	//For viewing time table of teachers
	void get_teacher_timetable();
};