#include<iostream>
#include<cstring>
#include"semester.h"
#pragma warning(disable:4996)
using namespace std;

Semester::Semester(char *s)
{
	strcpy(semester,s);
}
void Semester:: SetSemester(char *s){
	strcpy(semester,s);
}
char* Semester::GetSemester(){
	return semester;
}

