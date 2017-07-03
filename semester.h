#include<iostream>
using namespace std;

#ifndef Semester_H
#define Semester_H
class Semester{
public:
	Semester(char * s = " 2016ÄêÇï ");
	void SetSemester(char *s);
	char * GetSemester();
private:
	char semester[20];
};



#endif // !Semester_H
