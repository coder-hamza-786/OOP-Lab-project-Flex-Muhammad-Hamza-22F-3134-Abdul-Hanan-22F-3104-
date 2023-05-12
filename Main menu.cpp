#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include "HOD.h"
#include "Login.h"
using namespace std;
int main()
{
	//choice for selection modes i.e: Students, Teachers, HODs, Admin
	int choice = 0;
	
	while (true) {
		//Menu driven program
		system("color 3");
		cout << "\n\n\t\t\t\t\tWelcome to Flex Management System";
		cout << "\n\n1.Administrator" << endl;
		cout << "2.Teacher" << endl;
		cout << "3.Student" << endl;
		cout << "4.HOD" << endl;
		cout << "0.Exit" << endl << endl;
		cout << "Enter your choice = ";
		cin >> choice;
		//first choice is for admin
		if (choice == 1) {
			Login log_in;
			Administrator obj;
			//for login of administrator
			while (log_in.login(choice) != true) {
				if (log_in.login(choice) == true) {
					log_in.login(choice);
				}
				else if (log_in.login(choice) == false) {
					break;
				}
			}
			while (true) {
				//Options for Admin
				cout << "1.Add new teacher" << endl;
				cout << "2.Add new student" << endl;
				cout << "3.Edit teacher details" << endl;
				cout << "4.Edit student details" << endl;
				cout << "5.View all students" << endl;
				cout << "6.View all teachers" << endl;
				cout << "7.Delete a student" << endl;
				cout << "8.Delete a teacher" << endl;
				cout << "9.Set Teacher's time table" << endl;
				cout << "10.View Teacher's time table" << endl;
				cout << "0.Sign out" << endl;

				cout << "\nEnter your choice = ";	cin >> choice;
				//choice modes for admin
				if (choice == 1) {
					cout << endl;
					//function for addition of a new teacher
					obj.add_new_teacher();
					system("cls");
				}
				else if (choice == 2) {
					cout << endl;
					//function for addition of a new teacher
					obj.add_new_student();
					system("cls");
				}
				else if (choice == 3) {
					cout << endl;
					//function for editing teacher details
					obj.edit_teacher_details();
					system("cls");
				}
				else if (choice == 4) {
					cout << endl;
					//function for editing student details
					obj.edit_student_details();
					system("cls");
				}
				else if (choice == 5) {
					cout << endl;
					//function for viewing all students
					obj.view_all_students();
					system("cls");
				}
				else if (choice == 6) {
					cout << endl;
					//function for viewing all teachers
					obj.view_all_teachers();
					system("cls");
				}
				else if (choice == 7) {
					cout << endl;
					//for deleting a block of student
					obj.delete_student();
					system("cls");
				}
				else if (choice == 8) {
					cout << endl;
					//for deleting a block of teacher
					obj.delete_teacher();
					system("cls");
				}
				else if (choice == 9) {
					cout << endl;
					//for setting of time table of teacher
					obj.set_time_table();
					system("cls");
				}
				else if (choice == 10) {
					//for seeing the time table of teachers
					obj.get_teacher_timetable();
					system("cls");
				}
				//exiting flex
				else if (choice == 0) {
					cout << "\n\nThank you for using flex." << endl;
					Sleep(500);
					system("cls");
					break;
				}
			}
		}
		//second choice is for teacher
		else if (choice == 2) {
			Login log_in;
			Teacher obj;

			log_in.login(choice);

			while (choice) {
				system("color B");
				//Options for teachers
				cout << "1. Check your time table" << endl;
				cout << "2. Marking attandance" << endl;
				cout << "3. Checking attendance" << endl;
				cout << "4. Assign marks" << endl;
				cout << "5. Assign grades" << endl;
				cout << "0. Sign out" << endl;

				cout << "\nEnter your choice = ";
				cin >> choice;

				//function for checking time table made by admin
				if (choice == 1) {
					obj.check_time_table();
					system("cls");
				}
				//function for marking attendance
				else if (choice == 2) {
					obj.mark_attendance();
					system("cls");
				}
				//function for checking attendance
				else if (choice == 3) {
					obj.check_attendance();
					system("cls");
				}
				//function for assigning marks
				else if (choice == 4) {
					obj.assign_marks();
					system("cls");
				}
				//function for assigning grades
				else if (choice == 5) {
					obj.assign_grades();
					system("cls");
				}
				//for exiting teacher mode
				else if (choice == 0) {
					cout << "\nThank you for using flex.\n";
					//for keeping data of the teacher, i.e: checking time table, marking attendance etc
					obj.teacher_log_out();
					Sleep(500);
					system("cls");
					break;
				}
			}
		}
		//third choice is for student
		else if (choice == 3) {
			Student obj;
			Login log_in;
			log_in.login(choice);
			//Options for students
			while (choice) {
				cout << "1.View Attandance" << endl;
				cout << "2.View Marks" << endl;
				cout << "3.View Grades" << endl;
				cout << "4.View Registered cources" << endl;
				cout << "5.View Fee Status" << endl;
				cout << "0.Sign out" << endl;

				cout << "\nEnter your choice = ";
				cin >> choice;
				//function for viewing attendance
				if (choice == 1) {
					obj.view_attendance();
					system("cls");
				}
				//function for viewing marks in quizzez
				else if (choice == 2) {
					obj.view_marks();
					system("cls");
				}
				//function for viewing grades
				else if (choice == 3) {
					obj.view_grades();
					system("cls");
				}
				//function for viewing registered cources
				else if (choice == 4) {
					obj.view_registered_cources();
					system("cls");
				}
				//function for viewing fee status
				else if (choice == 5) {
					obj.view_fee_status();
					system("cls");
				}
				//for exiting student mode
				else if (choice == 0) {
					cout << "Thank you for using flex.\n";
					Sleep(500);
					system("cls");
					break;
				}
			}
		}
		//fourth choice is for HOD
		else if (choice == 4){

			HOD obj;
			Login log_in;
			log_in.login(choice);

			//Options for HOD
			while (choice) {
				cout << "\n1.View all Students" << endl;
				cout << "2.View all Teachers" << endl;
				cout << "3.Check time table" << endl;
				cout << "4.Checking for Teacher activities" << endl;
				cout << "0.Exit" << endl;

				cout << "\nEnter your choice = ";
				cin >> choice;
				//function for viewing all students
				if (choice == 1) {
					obj.view_all_students();
					system("cls");
				}
				//function for viewing all teachers
				else if (choice == 2) {
					obj.view_all_teachers();
					system("cls");
				}
				//function for checking time table of the teacher logged in
				else if (choice == 3) {
					obj.get_teacher_timetable();
					system("cls");
				}
				//function for checking activities of teacher
				else if (choice == 4) {
					obj.check_teacher_activities();
					system("cls");
				}
				//for exiting modes of HOD
				else if (choice == 0) {
					cout << "\nThank you for using flex.\n";
					Sleep(500);
					system("cls");
					break;
				}
			}
		}
		//for ending flex
		else if (choice == 0) {
			cout << "\nThank you for using flex.\n\n\n\n";
			break;
		}
		else if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			cout << "\nInvalid input.\n";
			Sleep(500);
			system("cls");
		}
		else if ((choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4)) {
			cout << "Invalid input.\n";
		}
	}
	return 0;
}
