#pragma once
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include <string>
#include <Windows.h>
#include <fstream>

class HOD : public Student, public Teacher {
private:
	string department, HOD_user_name, HOD_Password, HOD_ID;
public:
	HOD();
	HOD(string d, string name, string p);

	//Setters
	void set_department();
	void set_HOD_username();
	void set_HOD_password();
	void set_HOD_ID();
	//Getters
	string get_department();
	string get_HOD_username();
	string get_HOD_password();
	string get_HOD_ID();

	//view all teachers
    void view_all_teachers();
	//view all students
	void view_all_students();
	//for viewing teacher's timetable
	void get_teacher_timetable();
	//For checking teacher's activities
	void check_teacher_activities();
};