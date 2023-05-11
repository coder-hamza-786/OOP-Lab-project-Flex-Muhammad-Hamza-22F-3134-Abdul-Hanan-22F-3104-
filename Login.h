#pragma once
#include "Admin.h"
#include "HOD.h"
#include "Teacher.h"
#include "Student.h"

struct Login {
	Administrator admin;
	HOD hod;
	Teacher teacher;
	Student student;

	string id;
	string password;

	Login();

	bool login(int choice);
};