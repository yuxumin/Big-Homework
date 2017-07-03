#include"Student.h"
#include<cstring>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
Student::Student(char *s ,int GradeCalculus ,int GradeLinear ,int GradeDiscrete )
{
	strcpy(name,s);
	Grade[Calculus] = GradeCalculus;
	Grade[Linear] = GradeLinear;
	Grade[Discrete] = GradeDiscrete;
}
void Student::SetScore(int NewScore[3])
{
	Grade[Calculus] = NewScore[Calculus];
	Grade[Linear] = NewScore[Linear];
	Grade[Discrete] = NewScore[Discrete];
}
void Student::SetCalculus(int a)
{
	
	Grade[Calculus] = a;
}
void Student::SetLinear(int a)
{
	Grade[Linear] = a;
}
void Student::SetDiscrete(int a)
{
	Grade[Discrete] = a;
}
void Student::Fout(ofstream& of)
{
	of<<this->name<<'*'<<this->Grade[0]<<'*'<<this->Grade[1]<<'*'<<this->Grade[2]<<'*'<<GetSemester()<<endl;
}
void Student::Fin(ifstream& inf)
{
	char Tempname[20];
	inf.getline(Tempname,19,'*');
	char Tempscore0[4];
	inf.getline(Tempscore0,4,'*');
	char Tempscore1[4];
	inf.getline(Tempscore1,4,'*');
	char Tempscore2[4];
	inf.getline(Tempscore2,4,'*');
	char TempSemester[20];
	inf.getline(TempSemester,19);
	int tempscore[3];
	sscanf(Tempscore0,"%d",&tempscore[0]);
	sscanf(Tempscore1,"%d",&tempscore[1]);
	sscanf(Tempscore2,"%d",&tempscore[2]);
	this->SetName(Tempname);
	this->SetScore(tempscore);
	this->SetSemester(TempSemester);
}
void Student::SetName(char *s)
{
	strcpy(name,s);
}
char* Student::GetName(){
	return name;
}
int* Student::GetGrade(){
	return Grade;
}



