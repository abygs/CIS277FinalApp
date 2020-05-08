#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H
#include <string>

using std::string;
class Class; //forward delcartion of Class

//Student class variables and function prototypes
class Student
{
  private:
    string fname;
    string lname;
    string ID;
    string year;
    string major;
    int credits;
    int maxClasses = 5;
    Class * enrolledClasses[5];

  public:
    Student();
    void printClasses();
    void addClass(Class *);
    void dropClass(Class *);
    string getID();
    void setFname(string fname);
    void setLname(string lname);
    void setID(string ID);
    void setYear(string year);
    void setMajor(string major);
    void setMaxClasses(int maxClasses);
    string getFname();
    string getLname();
    string getYear();
    string getMajor();
    string getStudentID();
    Class * getEnrolledClass(int);
};


//Class class variables and function prototypes
class Class
{
  private:
    string classID;
    int creditHours;
    int maxCapacity;
    int numEnrolled;
    Student * enrolledStudents[10];

  public:
    Class();
    void enrollStudent(Student * s);
    void dropStudent(Student * s);
    void printEnrolled();
    void setClassID(string ID);
    void setCreditHours(int credits);
    void setNumEnrolled(int enrolled);
    void setMaxCapacity(int capacity);
    string getID();
    int getCreditHours();
    int getMaxCapacity();
    Student * getEnrolledStudent(int);
};

#endif