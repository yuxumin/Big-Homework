#include<iostream>
#include<cstring>
#include"vclass.h"
#pragma warning(disable:4996)
using namespace std;
#ifndef USER_H
#define USER_H
class user:public vclass 
{
public:
	user(char*n="*",char *p="*",int type = 1);   //1ÊÇÑ§Éú
	char * Getname();
	char * Getpassword();
	int GetType();
	void Fout(ofstream&of);
	void Fin(ifstream&inf);
	void SetUserName(char *a);
	void SetPassWord(char *a);
	void SetType(int a);
private:
	char UserName[20];
	char PassWord[20];
	int type;
};
#endif // !USER_H