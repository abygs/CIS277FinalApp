#include "StudentClass.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;

Student::Student()
{
  //setting beginning values for student variables
  fname = "";
  lname = "";
  ID = "";
  year = "";
  major = "";
  credits = 0;
  maxClasses = 5;
  for(int i = 0; i < maxClasses; i++)
    enrolledClasses[i] = 0;
}

//student functions
void Student::printClasses()
{
  cout << "Printing classes for " << fname << " " << lname << "\n";

  for (int i = 0; i < maxClasses; ++i) 
    if(enrolledClasses[i] != 0)
      cout << enrolledClasses[i]->getID() << "\n";
}

string Student::getID()
  {return ID;}

void Student::setFname(string fname)
  {this->fname = fname;}

void Student::setLname(string lname)
  {this->lname = lname;}

void Student::setID(string ID)
  {this->ID = ID;}

void Student::setYear(string year)
  {this->year = year;}

void Student::setMajor(string major)
  {this->major = major;}

void Student::setMaxClasses(int maxClasses)
  {this->maxClasses = maxClasses;}

string Student::getFname()
  {return this->fname;}

string Student::getLname()
  {return this->lname;}

string Student::getYear()
  {return this->year;}

string Student::getMajor()
  {return this->major;}

string Student::getStudentID()
  {return this->ID;}

void Student::addClass(Class * c)
{
  for(int i = 0; i < maxClasses; i++)
    if(enrolledClasses[i] == 0)
    {
      enrolledClasses[i] = c;
      break;
    }
}

void Student::dropClass(Class * c)
{
  for(int i = 0; i < maxClasses; i++)
    if(enrolledClasses[i] != 0)
      if(enrolledClasses[i]->getID() == c->getID())
        enrolledClasses[i] = 0;
}

Class * Student::getEnrolledClass(int ndx)
{
  return this->enrolledClasses[ndx];
}

//default constructor
Class::Class()
{
  //setting beginning values for class variables
  classID = "";
  creditHours = 0;
  maxCapacity = 10;
  numEnrolled = 0;
  for(int i = 0; i < maxCapacity; i++)
    enrolledStudents[i] = 0;
}

//class functions
void Class::enrollStudent(Student * s)
{
  if (numEnrolled == maxCapacity)
  {
    cout << "Class " << classID << " is full\n";
    return;
  }

  for (int i = 0; i < maxCapacity; i++)
  {
    if(enrolledStudents[i] == s)
      {
        cout << "Student is already enrolled in this class\n";
        return;
      }
      if(enrolledStudents[i] == 0)
      {
        enrolledStudents[i] = s;
        s->addClass(this);
        break;
      }
  }
  cout << "Succesfully enrolled Student " << s->getID() << " into class: " << classID << "\n";
  return;
}

void Class::dropStudent(Student * s)
{
  for(int i = 0; i < maxCapacity; i++)
    if(enrolledStudents[i] != 0)
      if(enrolledStudents[i]->getID() == s->getID())
      {
          enrolledStudents[i] = 0;
          
          for(int j = 0; j < 5; j++)
          {
            if(s->getEnrolledClass(j) != 0)
            {
              s->dropClass(s->getEnrolledClass(j));
            }
          }

          cout << "Succesfully dropped Student: " << s->getID() << " from class: " << classID << "\n";
          return;
      }

  cout << "Student does not exist in this class\n";
  return;
}

void Class::printEnrolled()
{
  cout << "Printing enrolled students for " << classID << "\n";

  for (int i = 0; i < maxCapacity; ++i)
    if(enrolledStudents[i] != 0)
      cout << enrolledStudents[i]->getID() << ": " << enrolledStudents[i]->getFname() << " " << enrolledStudents[i]->getLname() << "\n";
}

void Class::setClassID(string ID)
  {this->classID = ID;}

void Class::setCreditHours(int credits)
  {this->creditHours = credits;}

void Class::setNumEnrolled(int enrolled)
  {this->numEnrolled = enrolled;}

void Class::setMaxCapacity(int capacity)
  {this->maxCapacity = capacity;}

string Class::getID()
  {return this->classID;}

int Class::getCreditHours()
  {return this->creditHours;}

int Class::getMaxCapacity()
{return this->maxCapacity;}

Student * Class::getEnrolledStudent(int ndx)
{
  return this->enrolledStudents[ndx];
}