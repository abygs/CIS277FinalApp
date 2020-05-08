//Final App for CIS-277-H010
//Abigail Shulgan (s0506869)
#include <iostream>
#include "StudentClass.h"

//usings
using std::cout;
using std::cin;

//globals
const int MAX_SIZE = 50;
Class * Classes[MAX_SIZE];
Student * Students[MAX_SIZE];

//helper functions
Student * FindStudent(string id);
Class * FindClass(string id);

//functions for menu
void AddClass(Class *);
void DeleteClass(string);
void AddStudent(Student *);
void DeleteStudent(string);
void ViewAllClasses();
void ViewAllStudents();
void CreateClass();
void CreateStudent();
void EnrollStudent();
void DropStudent();
void ViewStudentsInAClass();
void ViewClassesOfAStudent();
void PrintMenu();

int main()
{
  char menuChoice;
  string id = "";
  //initialize Classes and Students global variables
  for(int i = 0; i < MAX_SIZE; i++)
  {
    Classes[i] = 0;
    Students[i] = 0;
  }

  //sample classes
  Class * c1;
  c1 = new Class();
  c1->setClassID("CIS247");
  c1->setCreditHours(3);
  Classes[0] = c1;
  
  Class * c2;
  c2 = new Class();
  c2->setClassID("PSY101");
  c2->setCreditHours(3);
  Classes[1] = c2;

  //sample students
  Student * s1;
  s1 = new Student();
  s1->setID("123");
  s1->setFname("Greg");
  s1->setLname("Gregson");
  s1->setYear("Freshman");
  s1->setMajor("Computer Science");
  Students[0] = s1;

  Student * s2;
  s2 = new Student();
  s2->setID("321");
  s2->setFname("Winifred");
  s2->setLname("Wilson");
  s2->setYear("Junior");
  s2->setMajor("Psychology");
  Students[1] = s2;

  PrintMenu(); //printing menu

  cout << "Select a menu option a-l: ";
  cin >> menuChoice;
  
  do //loop for repeating
  {
    switch (tolower(menuChoice))
    {
      case 'a':
        ViewAllClasses();
        break;
      case 'b':
        ViewAllStudents();
        break;
      case 'c':
        CreateClass();
        break;
      case 'd':
        cout << "Type the ID of the class you want to delete: ";
        cin >> id;
        DeleteClass(id);
        cout << "Class deleted\n";
        break;
      case 'e':
        CreateStudent();
        break;
      case 'f':
        cout << "Type the ID of the student you want to delete: ";
        cin >> id;
        DeleteStudent(id);
        cout << "Student deleted\n";
        break;
      case 'g':
        EnrollStudent();
        break;
      case 'h':
        DropStudent();
        break;
      case 'i':
        ViewStudentsInAClass();
        break;
      case 'j':
        ViewClassesOfAStudent();
        break;
      case 'k':
        PrintMenu();
        break;
      case 'l':
        cout << "Exiting menu...Thank you!";
        return 0;
      default:
        cout << "Invalid choice";
    }

    cout << "\nSelect a menu option a-l: ";
    cin >> menuChoice;
  }
  while (menuChoice != 'l'); //validation

  return 0; //option l
}

//FUNCTIONS BELOW

void ViewAllClasses() //option a
{
  for(int i = 0; i < MAX_SIZE; i++)
  {
    if (Classes[i] != 0) //checks for classes
    {
      cout << Classes[i]->getID() << "    ";
      cout << "Credit hours: " << Classes[i]->getCreditHours() << "\n";
    }
  }
}

void ViewAllStudents() //option b
{
  for(int i = 0; i < MAX_SIZE; i++)
  {
    if (Students[i] != 0) //checks for students
    {
      cout << Students[i]->getID() << ": ";
      cout << Students[i]->getFname() << " " << Students[i]->getLname() << ", ";
      cout << Students[i]->getYear() << " in " << Students[i]->getMajor() << "\n";
    }
  }
}

void CreateClass() //option c
{
  string str = "";
  int credits;
  Class * c;

  cout << "Enter new Class ID: ";
  cin >> str;

  c = FindClass(str); //checks for duplicate IDs
  if(c != 0)
  {
    cout << "Class ID has already been used\n";
    return;
  }

  c = new Class();
  c->setClassID(str);

  cout << "Enter Class Credit Hours: ";
  cin >> credits;
  c->setCreditHours(credits);

  AddClass(c);
  cout << "Class created\n";
  return;
}

void DeleteClass(string id) //option d
{
  for(int i = 0; i < MAX_SIZE; i++)
    if (Classes[i] != 0)
      if(Classes[i]->getID() == id)
      {
        for(int j = 0; j < Classes[i]->getMaxCapacity(); j++)
          if(Classes[i]->getEnrolledStudent(j) != 0)
            Classes[i]->dropStudent(Classes[i]->getEnrolledStudent(j));

        Classes[i] = 0;
        return;
      }
  cout << "Class does not exist";
  return;
}

void CreateStudent() //option e
{
  string str = "";

  Student * s;

  cout << "Enter new student ID: ";
  cin >> str;

  s = FindStudent(str);
  if(s != 0)
  {
    cout << "Student ID has already been used\n";
    return;
  }

  s = new Student();
  s->setID(str);

  cout << "Enter student's first name: ";
  cin >> str;
  s->setFname(str);

  cout << "Enter student's last name: ";
  cin >> str;
  s->setLname(str);

  cout << "Enter student's academic year (Freshman, Sophmore, Junior, Senior): ";
  cin >> str;
  s->setYear(str);

  cout << "Enter student's major: ";
  cin >> str;
  s->setMajor(str);

  AddStudent(s);
  cout << "Student created\n";
  return;
}

void DeleteStudent(string id) //option f
{
  for(int i = 0; i < MAX_SIZE; i++)
    if (Students[i] != 0)
      if(Students[i]->getStudentID() == id)
      {
        //WIPdrop student from all of their classes
        Students[i] = 0;
        return;
      }
  cout << "Student does not exist";
  return;
}

void EnrollStudent() //option g
{
  Class * c;
  Student * s;
  string sId;
  string cId;

  cout << "Enter the Class ID: ";
  cin >> cId;

  cout << "Enter the Student ID: ";
  cin >> sId;

  c = FindClass(cId); //find the class I need
  if(c == 0)
  {
    cout << "Could not find a class with that ID";
    return;
  }

  s = FindStudent(sId);
  if(s == 0)
  {
    cout << "Could not find a student with that ID";
    return;
  }

  c->enrollStudent(s);
  return;
}

void DropStudent() //option h
{
  Class * c;
  Student * s;
  string sId;
  string cId;

  cout << "Enter the Class ID: ";
  cin >> cId;

  cout << "Enter the Student ID: ";
  cin >> sId;

  c = FindClass(cId); //find the class I need
  if(c == 0)
  {
    cout << "Could not find a class with that ID";
    return;
  }

  s = FindStudent(sId);
  if(s == 0)
  {
    cout << "Could not find a student with that ID";
    return;
  }

  c->dropStudent(s);
  return;
}

void ViewStudentsInAClass() //option i
{
  Class * c;
  string cId;

  cout << "Enter the Class ID: ";
  cin >> cId;

  c = FindClass(cId);
  if(c == 0)
  {
    cout << "Could not find a class with that ID";
    return;
  }

  c->printEnrolled();
  return;
}

void ViewClassesOfAStudent() //option j
{
  Student * s;
  string sID;

  cout << "Enter student's ID: ";
  cin >> sID;

  s = FindStudent(sID);
  if(s == 0)
  {
    cout << "Could not find a student with that ID";
    return;
  }

  s->printClasses();
  return;
}

void PrintMenu() //option k
{
  //main menu output
  cout << "**STUDENT REGISTRATION MANAGMENT SYSTEM**\n";
  cout << "     a. View all classes\n";
  cout << "     b. View all students\n";
  cout << "     c. Create class\n";
  cout << "     d. Delete class\n";
  cout << "     e. Create student\n";
  cout << "     f. Delete student\n";
  cout << "     g. Enroll student in a class\n";
  cout << "     h. Drop student from a class\n";
  cout << "     i. View enrolled students in a class\n";
  cout << "     j. View a students enrolled classes\n";
  cout << "     k. Print Menu\n";
  cout << "     l. Exit Menu\n";

  return;
}

//HELPER FUNCTIONS
void AddStudent(Student * s)
{
  for(int i = 0; i < MAX_SIZE; i++)
    if(Students[i] == 0)
    {
      Students[i] = s;
      return;
    }
  cout << "Not enough room to add more students... limit reached.";
  return;
}

void AddClass(Class * c) //aids in creating classes
{
  for(int i = 0; i < MAX_SIZE; i++)
    if(Classes[i] == 0)
    {
      Classes[i] = c;
      return;
    }
  cout << "Not enough room to make more classes... limit reached.";
  return;
}

Student * FindStudent(string id) //aids in finding students
{
  for(int i = 0; i < MAX_SIZE; i++)
    if(Students[i] != 0)
      if(Students[i]->getID() == id)
        return Students[i];

  return 0;
}

Class * FindClass(string id) //aids in finding classes
{
  for(int i = 0; i < MAX_SIZE; i++)
    if(Classes[i] != 0)
      if(Classes[i]->getID() == id)
        return Classes[i];

  return 0;
}

