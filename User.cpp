#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include"user.h"
#pragma warning(disable:4996)
using namespace std;
user::user(char*n,char *p,int type){
	strcpy(UserName,n);
	strcpy(PassWord,p);
	this->type = type;
}
void user::SetUserName(char *a){
	strcpy(UserName,a);
}
void user::SetPassWord(char *a){
	strcpy(PassWord,a);
}
void user::SetType(int a){
	type = a;
}
char *user:: Getname(){
	return UserName;
}
char * user::Getpassword(){
	return PassWord;
}
int user::GetType(){
	return type;
}
void user::Fout(ofstream&of){
	of<<UserName<<'*'<<PassWord<<'*'<<type<<endl;
}
void user::Fin(ifstream&inf){
	char Tempname[20];
	inf.getline(Tempname,19,'*');
	char TempPassWord[20];
	inf.getline(TempPassWord,19,'*');
	char TempType[4];
	inf.getline(TempType,3);
	int Type;
	sscanf(TempType,"%d",&Type);
	this->SetUserName(Tempname);
	this->SetPassWord(TempPassWord);
	this->SetType(Type);
}




