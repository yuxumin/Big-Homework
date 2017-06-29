#include"App.h"
#include"Student.h"
#include"User.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#pragma warning(disable:4996)
using namespace std;
void Aixin();
extern Student list[500];
extern user UserList[500];
static int number;
static int usernumber;
static int UserRight = 1;
static int Buff = 0;        //一旦登入就变为1，注销变为0
const char Subject[3][20]={"微积分","线性代数","离散数学"};
void CopyUserList(ifstream&inf)
{
	int count = 0;
	while(inf.good())
	{
		UserList[count++].Fin(inf);
	}
	usernumber = count;
}
void FlushUserList(ofstream&of)
{
	for(int i =0;i<usernumber-1;i++)
	{
		of<<UserList[i].Getname()<<'*'<<UserList[i].Getpassword()<<'*'<<UserList[i].GetType()<<endl;
	}
}
void CopyList(ifstream&inf)
{
	int count = 0;
	while(inf.good())
	{
		list[count++].Fin(inf);
	}
	number = count;
}
void FlushList(ofstream&of)
{
	for(int i =0;i<number-1;i++)
	{
		of<<list[i].GetName()<<'*'<<list[i].GetGrade()[0]<<'*'<<list[i].GetGrade()[1]<<'*'<<list[i].GetGrade()[2]<<endl;
	}
}
void App::ChangeScore(){
	if(UserRight == 1) 
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"┌—————————————————————————┐\n";
		cout<<"│              Forbidden Action!!!                 │\n";
		cout<<"│                                                  │\n";
		cout<<"│          抱歉！您没有权限修改成绩！              │\n";
		cout<<"│                                                  │\n";
		cout<<"└—————————————————————————┘\n";
		cout<<"      感谢您的使用，谢谢！按任意键回到主菜单...\n";
		system("pause>nul 2>nul");          
	}
	else
	{

		int FindIt;
		bool Continue = true;
		while(Continue)
		{
			FindIt = 0;
			system("cls");
			cout<<"输入需要修改成绩的同学的名字"<<endl;
			char Tempname[20];
			int i = 0;
			cin.clear();
			cin.sync();
			cin.getline(Tempname,20);
			for(;i<number;i++)
			{
				if(strcmp(list[i].GetName(),Tempname)==0)  {FindIt = 1; break;}
			}
			if(FindIt == 1)
			{
				cout<<"┌—————————————————————————┐\n";
				cout<<"│                    查找成功!!                    │\n";
				cout<<"│                想要修改的科目是：                │\n";
				cout<<"│                  [1]: 微积分                     │\n";
				cout<<"│                  [2]: 线性代数                   │\n";
				cout<<"│                  [3]: 离散数学                   │\n";
				cout<<"│                  [4]: 各科成绩                   │\n";
				cout<<"│    [简单说明]：修改成绩界面，谢谢您的使用！      │\n";
				cout<<"└—————————————————————————┘\n";
				int SubjectNumber;
				cin>>SubjectNumber;
				system("cls");
				if(SubjectNumber==1)
				{
					cout<<"确定要修改"<<Tempname<<"同学的微积分成绩吗？(y/n)"<<endl;
					char a;
					cin>>a;
					if (a=='n'||a=='N')  {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
					else 
						{
							cout<<Tempname<<"的原始微积分成绩为: "<<list[i].GetGrade()[0]<<" "<<endl;
							cout<<"请输入新成绩： ";
							int NewScore;
							cin>>NewScore;
							list[i].SetCalculus(NewScore);
							cout<<"***********************修改成功！***********************"<<endl;
						}
				}
				if(SubjectNumber==2)
				{
					cout<<"确定要修改"<<Tempname<<"同学的线性代数成绩吗？(y/n)"<<endl;
					char a;
					cin>>a;
					if (a=='n'||a=='N')  {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
					else 
						{
							cout<<Tempname<<"的原始线性代数成绩为: "<<list[i].GetGrade()[1]<<" "<<endl;
							cout<<"请输入新成绩： ";
							int NewScore;
							cin>>NewScore;
							list[i].SetLinear(NewScore);
							cout<<"***********************修改成功！**********************"<<endl;
						}
				}
				if(SubjectNumber==3)
				{
					cout<<"确定要修改"<<Tempname<<"同学的离散数学成绩吗？(y/n)"<<endl;
					char a;
					cin>>a;
					if (a=='n'||a=='N')  {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
					else 
						{
							cout<<Tempname<<"的原始离散数学成绩为: "<<list[i].GetGrade()[2]<<" "<<endl;
							cout<<"请输入新成绩： ";
							int NewScore;
							cin>>NewScore;
							list[i].SetDiscrete(NewScore);
							cout<<"***********************修改成功！***********************"<<endl;
						}
				}
				if(SubjectNumber==4)
				{
					cout<<"确定要修改"<<Tempname<<"同学的全部成绩吗？(y/n)"<<endl;
					char a;
					cin>>a;
					if (a=='n'||a=='N')  {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
					else 
						{
							cout<<Tempname<<"的原始成绩为: "<<endl;
							cout<<"┌—————————————————————————┐\n";
							cout<<" "<<Tempname<<"      "<<Subject[0]<<"                       ";
							cout<<left<<setw(4)<<list[i].GetGrade()[0]<<"    \n";
							cout<<" "<<Tempname<<"      "<<Subject[1]<<"                     ";
							cout<<left<<setw(4)<<list[i].GetGrade()[1]<<"    \n";
							cout<<" "<<Tempname<<"      "<<Subject[2]<<"                     ";
							cout<<left<<setw(4)<<list[i].GetGrade()[2]<<"    \n";
							cout<<"└—————————————————————————┘\n";
							cout<<"请输入新微积分成绩： ";
							int NewScore[3];
							cin>>NewScore[0];
							cout<<endl;
							cout<<"请输入新线性代数成绩： ";
							cin>>NewScore[1];
							cout<<endl;
							cout<<"请输入新离散数学成绩： ";
							cin>>NewScore[2];
							cout<<endl;
							list[i].SetScore(NewScore);
							cout<<"*********************修改成功！*************************"<<endl;
						}
				}
			
			}
			else cout<<"抱歉，没有找到该学生"<<endl;
			cout<<"是否继续修改成绩？<y/n>"<<endl;
				char z;
				cin>>z;
			if(z=='y'||z=='Y')  {}
			else {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
		}
		ofstream FlushSource;
		FlushSource.open("StudentList.txt",ios_base::trunc);
		FlushList(FlushSource);
		FlushSource.close();
	}
}
void App::FindScore()
{
	int FindIt;
	bool Continue = true;
	while(Continue)
	{
		FindIt = 0;
		system("cls");
		cout<<"输入需要查找的学生姓名"<<endl;
		char Tempname[20];
		int i = 0;
		cin.clear();
		cin.sync();
		cin.getline(Tempname,20);
		for(;i<number;i++)
		{
			if(strcmp(list[i].GetName(),Tempname)==0)  {FindIt = 1; break;}
		}
		if(FindIt==1)
		{
			cout<<"┌—————————————————————————┐\n";
			cout<<"│                    查找成功!!                    │\n";
			cout<<"│                  输入查询的科目                  │\n";
			cout<<"│                  [1]: 微积分                     │\n";
			cout<<"│                  [2]: 线性代数                   │\n";
			cout<<"│                  [3]: 离散数学                   │\n";
			cout<<"│                  [4]: 各科成绩                   │\n";
			cout<<"│    [简单说明]：查询成绩界面，谢谢您的使用！      │\n";
			cout<<"└—————————————————————————┘\n";
			int SubjectNumber;
			cin>>SubjectNumber;
			system("cls");
		if(SubjectNumber==1||SubjectNumber==2||SubjectNumber==3)
	//		cout<<"这门课程的成绩是:"<<list[i].GetGrade()[SubjectNumber-1]<<endl;
			{
			cout<<"┌—————————————————————————┐\n";
			cout<<"│"<<Tempname<<"      "<<Subject[SubjectNumber-1]<<"                       ";
			cout<<left<<setw(4)<<list[i].GetGrade()[SubjectNumber-1]<<"   │\n";
			cout<<"└—————————————————————————┘\n";
			}
		if(SubjectNumber==4)
			{
			cout<<"┌—————————————————————————┐\n";
			cout<<" "<<Tempname<<"      "<<Subject[0]<<"                       ";
			cout<<left<<setw(4)<<list[i].GetGrade()[0]<<"    \n";
			cout<<" "<<Tempname<<"      "<<Subject[1]<<"                     ";
			cout<<left<<setw(4)<<list[i].GetGrade()[1]<<"    \n";
			cout<<" "<<Tempname<<"      "<<Subject[2]<<"                     ";
			cout<<left<<setw(4)<<list[i].GetGrade()[2]<<"    \n";
			cout<<"└—————————————————————————┘\n";
			}
		}
		else cout<<"抱歉，没有找到该学生"<<endl;
		cout<<"是否继续查找？<y/n>"<<endl;
			char z;
			cin>>z;
		if(z=='y'||z=='Y')  {}
		else {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
	}
}
void App::SetScore(){
	if(UserRight == 1) 
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"┌—————————————————————————┐\n";
		cout<<"│              Forbidden Action!!!                 │\n";
		cout<<"│                                                  │\n";
		cout<<"│          抱歉！您没有权限写入成绩！              │\n";
		cout<<"│                                                  │\n";
		cout<<"└—————————————————————————┘\n";
		cout<<"      感谢您的使用，谢谢！按任意键回到主菜单...\n";
		system("pause>nul 2>nul");          
	}
	else
	{
		system("cls");
		cin.clear();
		cin.sync();
		bool Continue = true;
		char Temp[20];
		int Tempscore[3];
		ofstream Setfile;
		Setfile.open("StudentList.txt",ios_base::app);
		int FindIt;
		while(Continue)
		{
			cout<<"输入学生姓名（小于20个字符）"<<endl;
			cin.getline(Temp,19);
			FindIt = 0;
			cin.clear();
			cin.sync();
			for(int i=0;i<number;i++)
			{
				if(strcmp(list[i].GetName(),Temp)==0)  {FindIt = 1; break;}
			}
			if (FindIt ==1)  {cout<<"不能重复写入！"<<endl;}
			else
			{
				cout<<"输入微积分成绩"<<endl;
				cin>>Tempscore[0];
				cout<<"输入线代成绩"<<endl;
				cin>>Tempscore[1];	
				cout<<"输入离散数学成绩"<<endl;
				cin>>Tempscore[2];
				Student Tempstudent(Temp,Tempscore[0],Tempscore[1],Tempscore[2]);
				Tempstudent.Fout(Setfile);
			}
			cout<<"是否继续添加？<y/n>"<<endl;
			char z;
			cin>>z;
			if(z=='y'||z=='Y')  {}
			else {Continue = false;	cout<<"任意键返回主菜单... ..."<<endl;system("pause>nul 2>nul");}
			cin.clear();
			cin.sync();
		}
		Setfile.close();
	}
}
bool App::SignInMune(){
	
	if(Buff==0)
	{
		ifstream CopySource;
		CopySource.open("UserList.txt",ios_base::in);
		CopyUserList(CopySource);
		CopySource.close();
		system("cls");
		system("color 3f");
		system("title 学生管理系统登陆");
		system("mode con cols=56 lines=20"); 
		cout<<"┌—————————————————————————┐\n";
		cout<<"│                  学生成绩管理系统                │\n";
		cout<<"│[1]、登陆账号                                     │\n";
		cout<<"│                                                  │\n";
		cout<<"│[2]、注册账号                                     │\n";
		cout<<"│                                                  │\n";
		cout<<"│[3]、修改密码                                     │\n";
		cout<<"│                                                  │\n";
		cout<<"│[4]、退出                                         │\n";
	if(UserRight ==0)
	{
		cout<<"│                                                  │\n";
		cout<<"│[作者]、翁丽霞的男朋友                            │\n";
	}
		cout<<"└—————————————————————————┘\n";
		cout<<"请选择：";
		int SignInSuccess;
		cin>>SignInSuccess;
	/*                                       注册账号                                                                    */	
		if(SignInSuccess == 2)
		{
			system("cls");
			cout<<"┌—————————————————————————┐\n";
			cout<<"│                  学生成绩管理系统                │\n";
			cout<<"│[1]、学生                                         │\n";
			cout<<"│                                                  │\n";
			cout<<"│[2]、老师                                         │\n";
			cout<<"│                                                  │\n";
			cout<<"│[3]、返回                                         │\n";
	if(UserRight ==0)	
		{
			cout<<"│                                                  │\n";
			cout<<"│[作者]、翁丽霞的男朋友                            │\n";
		}
			cout<<"└—————————————————————————┘\n";
			int choice;
			int FindIt = 0;
			cin>>choice;
			if(choice !=1&&choice!=2) return true;
			else 
				{
					system("cls");
					ofstream RegisterFile;
					RegisterFile.open("UserList.txt",ios_base::app);
					cout<<"输入账号（小于20个字符）"<<endl;
					cin.clear();
					cin.sync();
					char TempName[20];
					char TempPass[20];
					cin.getline(TempName,19);
						for(int i=0;i<usernumber;i++)
							{
								if(strcmp(UserList[i].Getname(),TempName)==0)  {FindIt = 1; break;}
							}
					if(FindIt == 0)
					{
						cout<<"输入密码（小于20个字符）"<<endl;
						cin.getline(TempPass,19);
						user NewUser(TempName,TempPass,choice);
						NewUser.Fout(RegisterFile);
						RegisterFile.close();
						cout<<"注册成功！"<<endl;
						return true;
					}
					else cout<<"注册失败！用户名已存在！"<<endl;
				cout<<"即将跳转至登陆界面";
				cout<<"按任意键继续... ..."<<endl;system("pause>nul 2>nul");
				return true;
				}
		}
	/*------------------------------------修改密码---------------------------------------------------------------------*/
		else if(SignInSuccess == 3)
			{
				//账号判断
				int FindIt;
				int i=0;
				cin.clear();
				cin.sync();
				char TempName[20];
				char TempPass[20];
				cout<<"请输入账号："<<endl;
				cin.getline(TempName,19);
				for(;i<usernumber;i++)
							{
								if(strcmp(UserList[i].Getname(),TempName)==0)  {FindIt = 1; break;}
							}
				if(FindIt ==1)
				{
					cin.clear();
					cin.sync();
					cout<<"请输入密码："<<endl;
					cin.getline(TempPass,19);
					if(strcmp(TempPass,UserList[i].Getpassword())==0)
					{
						system("cls");
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<"┌—————————————————————————┐\n";
						cout<<"│       Check Completed!!  Check Completed!!!      │\n";
						cout<<"│                                                  │\n";
						cout<<"│                  账号密码验证成功！              │\n";
						cout<<"│                                                  │\n";
						cout<<"└—————————————————————————┘\n";
						cout<<"                 即将跳转修改密码界面......\n";
						cout<<"                      按任意键..."<<endl;
						system("pause>nul 2>nul");    
						system("cls");
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<"┌—————————————————————————┐\n";
						cout<<"│                                                  │\n";
						cout<<"│                欢迎来到修改密码界面              │\n";
						cout<<"│                    安全跳转中 ....               │\n";
						cout<<"│                                                  │\n";
						cout<<"└—————————————————————————┘\n";
						cout<<"                 按任意键..."<<endl;
						system("pause>nul 2>nul");    
						bool success = true;
						while(success)
						{
							system("cls");
							char NewPassWord[20],NewPassWord2[20];
							cin.clear();
							cin.sync();
							cout<<"输入新的密码："<<endl;
							cin.getline(NewPassWord,19);
							cin.clear();
							cin.sync();
							cout<<"请再次输入新的密码："<<endl;
							cin.getline(NewPassWord2,19);
							if(strcmp(NewPassWord,NewPassWord2)==0)  
							 {
								 	UserList[i].SetPassWord(NewPassWord);
									system("cls");
									cout<<endl;
									cout<<endl;
									cout<<endl;
									cout<<endl;
									cout<<endl;
									cout<<"┌—————————————————————————┐\n";
									cout<<"│       ChangeCompleted!!  Change Completed!!!     │\n";
									cout<<"│                                                  │\n";
									cout<<"│                  账号密码修改成功！              │\n";
									cout<<"│                                                  │\n";
									cout<<"└—————————————————————————┘\n";
									cout<<"          即将跳转登陆界面......\n";
									cout<<"              按任意键..."<<endl;
									ofstream FlushUserSource;
									FlushUserSource.open("UserList.txt",ios_base::trunc);
									FlushUserList(FlushUserSource);
									FlushUserSource.close();
									success = false;
									system("pause>nul 2>nul");   
							 }
							else 
							{
								system("cls");
									cout<<endl;
									cout<<endl;
									cout<<endl;
									cout<<endl;
									cout<<endl;
									cout<<"┌—————————————————————————┐\n";
									cout<<"│          A Unexpected error occurred!!!          │\n";
									cout<<"│                                                  │\n";
									cout<<"│    两次输入密码不同    账号密码修改失败！        │\n";
									cout<<"│                                                  │\n";
									cout<<"└—————————————————————————┘\n";
									cout<<"          即将跳转重新输入新密码界面......\n";
									cout<<"              按任意键..."<<endl;
									system("pause>nul 2>nul");  
							}
						}
						return true;
					}
					else
					{
						system("cls");
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<"┌—————————————————————————┐\n";
						cout<<"│          A Unexpected error occurred!!!          │\n";
						cout<<"│                                                  │\n";
						cout<<"│                  账号密码验证失败！              │\n";
						cout<<"│                                                  │\n";
						cout<<"└—————————————————————————┘\n";
						cout<<"             即将跳转回登陆界面......\n";
						cout<<"                按任意键..."<<endl;
						system("pause>nul 2>nul");   
						return true;
					}
				}
				else 
				{
					system("cls");
					cout<<endl;
					cout<<endl;
					cout<<endl;
					cout<<endl;
					cout<<endl;
					cout<<"┌—————————————————————————┐\n";
					cout<<"│          A Unexpected error occurred!!!          │\n";
					cout<<"│                                                  │\n";
					cout<<"│                  未找到该用户！                  │\n";
					cout<<"│                                                  │\n";
					cout<<"└—————————————————————————┘\n";
					cout<<"            即将跳转回登陆界面......\n";
					cout<<"               按任意键..."<<endl;
					system("pause>nul 2>nul");         
					return true;
				}
				
				
		}
	/*-                                      登陆账号                                                                  --*/	
		else if(SignInSuccess == 1)
		{
			//账号判断
			cin.clear();
			cin.sync();
			char TempName[20];
			char TempPass[20];
			cout<<"请输入账号："<<endl;
			cin.getline(TempName,19);
			cin.clear();
			cin.sync();
			cout<<"请输入密码："<<endl;
			cin.getline(TempPass,19);
			for(int i=0;i<usernumber;i++)
							{
								if(strcmp(UserList[i].Getname(),TempName)==0&&
									strcmp(UserList[i].Getpassword(),TempPass)==0)  {Buff = 1;UserRight = UserList[i].GetType(); break;}
							}
			if(Buff==1)
			{
				system("cls");
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<"┌—————————————————————————┐\n";
				cout<<"│          Valid User Number and PassWord!!!       │\n";
				cout<<"│                                                  │\n";
				cout<<"│                  正在登陆...                     │\n";
				cout<<"│                                                  │\n";
				cout<<"└—————————————————————————┘\n";
				cout<<"          即将跳转回登陆界面......\n";
				system("pause>nul 2>nul"); 
				Exwhile = true;
				int flag = 0;
				while(Exwhile)
				{
					int Select = MainMune();
					switch(Select)
					{
					case 1:Exwhile = false ; flag = 1; break;
					case 2:Exwhile = false ; flag = 2; break;
					case 3:Exwhile = false ; flag = 3; break;
					case 4:Quit();Exwhile = false ; break;
					default:cout<<"输入错误，请重新输入"<<endl;cin.clear();cin.sync();system("pause 2>nul");break;  
					}
				}
				if(flag == 1) SetScore();
				else if(flag == 2) ChangeScore();
				else if(flag == 3) FindScore();
				flag = 0;
				return true;
			}
			//如果未登陆
			else
			{
				system("cls");
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<"┌—————————————————————————┐\n";
				cout<<"│          A Unexpected error occurred!!!          │\n";
				cout<<"│                                                  │\n";
				cout<<"│                  账号密码错误！                  │\n";
				cout<<"│                                                  │\n";
				cout<<"└—————————————————————————┘\n";
				cout<<"          即将跳转回登陆界面......\n";
				system("pause>nul 2>nul"); 
				return true;
			}
		}
	/*                                                   退出                                              */
		else if(SignInSuccess == 4)  {Continue = false;Exit();return false;}
		else
		{
			system("cls");
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"┌—————————————————————————┐\n";
			cout<<"│          A Unexpected error occurred!!!          │\n";
			cout<<"│                                                  │\n";
			cout<<"│                  非法指令！  ！                  │\n";
			cout<<"│                                                  │\n";
			cout<<"└—————————————————————————┘\n";
			cout<<"            即将跳转回登陆界面......\n";
			cout<<"               按任意键..."<<endl;
			system("pause>nul 2>nul");         
			return true;
		}


	}
	else//Buff为1直接到Mune
	{
				Exwhile = true;
				int flag = 0;
				while(Exwhile)
				{
					int Select = MainMune();
					switch(Select)
					{
					case 1:Exwhile = false ; flag = 1; break;
					case 2:Exwhile = false ; flag = 2; break;
					case 3:Exwhile = false ; flag = 3; break;
					case 4:Quit();Exwhile = false ; break;
					default:cout<<"输入错误，请重新输入"<<endl;cin.clear();cin.sync();system("pause 2>nul");break;  
					}
				}
				if(flag == 1) SetScore();
				else if(flag == 2) ChangeScore();
				else if(flag == 3) FindScore();
				flag = 0;
		return true;
	}
}
void App::Start(){
	//登入循环
	bool SignIn = true;
	while(SignIn)
	{
		SignIn = SignInMune();
	}
}
void App::Quit()
{
	system("cls");
	Buff = 0;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"┌—————————————————————————┐\n";
	cout<<"│              正在注销账号...                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│          感谢您使用：学生成绩管理系统            │\n";
	cout<<"│                                                  │\n";
	cout<<"│   [简单说明]：程序登出界面，谢谢您的使用！       │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"      感谢您的使用，谢谢！按任意键回到登陆界面...\n";
	system("pause>nul 2>nul");          
}
void App::Exit()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"┌—————————————————————————┐\n";
	cout<<"│          感谢您使用：学生成绩管理系统            │\n";
	cout<<"│                                                  │\n";
	cout<<"│[程序制作]: 於城城城城                            │\n";
	cout<<"│[联系Q Q ]: 1090414006                            │\n";
	cout<<"│[联系邮箱]：yuxumin980417@126.com                 │\n";
	cout<<"│[简单说明]：程序结束界面，谢谢您的使用！          │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"感谢您的使用，谢谢！按任意键退出程序...\n";
	system("pause>nul 2>nul");          
}
int App::MainMune()
{
	if(UserRight == 0)
	{
		Aixin();
		system("pause>nul 2>nul");
		system("cls");
		system("mode con cols=56 lines=20"); 
		cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"┌—————————————————————————┐\n";
			cout<<"│         Big Big Big  Big Big   Surprise!!!       │\n";
			cout<<"│                                                  │\n";
			cout<<"│          Yxm Love Wlx   sooooooooMuch            │\n";
			cout<<"│                                                  │\n";
			cout<<"│            一定要天天开心~宝贝！                 │\n";
			cout<<"└—————————————————————————┘\n";
			cout<<"            点击表示Wlx also love Yxm......\n";   
			system("pause>nul 2>nul");
	}

	ifstream CopySource;
	CopySource.open("StudentList.txt",ios_base::in);
	CopyList(CopySource);
	CopySource.close();
	system("cls");
	system("color 3f");
	system("mode con cols=56 lines=20"); 
if(UserRight == 0)	system("title Yxm 给Wlx一个么么扎");
else system("title 学生成绩管理系统");
	cout<<"┌—————————————————————————┐\n";
	cout<<"│                  学生成绩管理系统                │\n";
	cout<<"│[1]、写入成绩                                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│[2]、修改成绩                                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│[3]、查询成绩                                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│[4]、注销账号                                     │\n";
if(UserRight == 0)	
{
	cout<<"│                                                  │\n";
	cout<<"│[作者]、翁丽霞的男朋友                            │\n";
}
	cout<<"└—————————————————————————┘\n";
	cout<<"请选择：";
	int select;
	cin>>select;
	return select;
}