#include<cstring>
#include<fstream>
#include"vclass.h"
#include"Semester.h"
#pragma warning(disable:4996)
using namespace std;
enum subject{Calculus,Linear,Discrete};
#ifndef K
#define K

class Student:public vclass ,public Semester
{
public:
	Student(char *s = "*",int GradeCalculus = 0,int GradeLinear = 0,int GradeDiscrete = 0);
	void SetName(char *s);
	void SetScore(int NewScore[3]);
	void Fout(ofstream&of);
	void Fin(ifstream&inf);
	void SetCalculus(int a);
	void SetLinear(int a);
	void SetDiscrete(int a);
	char* GetName();
	int* GetGrade();
//	void (*f[3])(int x) ;
private:
	char name[20];
	int Grade[3];
};
#endif // !K