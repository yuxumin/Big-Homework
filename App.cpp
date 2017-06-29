#include"App.h"
#include"Student.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#pragma warning(disable:4996)
using namespace std;
extern Student list[500];
static int number;
const char Subject[3][20]={"微积分","线性代数","离散数学"};
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
						cout<<"***********************修改成功！************************"<<endl;
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
						cout<<"***********************修改成功！***********************"<<endl;
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
						cout<<"***********************修改成功！************************"<<endl;
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
void App::Start(){
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
		case 4:Exit();Exwhile = false ;Continue = false; break;
		default:cout<<"输入错误，请重新输入"<<endl;cin.clear();cin.sync();system("pause 2>nul");break;  
		}
	}
	if(flag == 1) SetScore();
	else if(flag == 2) ChangeScore();
	else if(flag == 3) FindScore();
	flag = 0;
}
void App::Exit()
{
	system("cls");
	cout<<"┌—————————————————————————┐\n";
	cout<<"│          感谢您使用：学生成绩管理系统            │\n";
	cout<<"│                                                  │\n";
	cout<<"│[程序制作]: 於城城城城                            │\n";
	cout<<"│[联系Q Q ]: 1090414006                            │\n";
	cout<<"│[联系邮箱]：yuxumin980417@126.com                 │\n";
	cout<<"│[简单说明]：程序结束界面，谢谢您的使用！          │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"感谢您的使用，谢谢！按任意键退出查询程序...\n";
	system("pause>nul 2>nul");          
}
int App::MainMune()
{
	ifstream CopySource;
	CopySource.open("StudentList.txt",ios_base::in);
	CopyList(CopySource);
	CopySource.close();
	system("cls");
	system("color 3f");
	system("mode con cols=56 lines=20"); 
	system("title 学生成绩管理系统  给Wlx一个么么扎");
	cout<<"┌—————————————————————————┐\n";
	cout<<"│                  学生成绩管理系统                │\n";
	cout<<"│[1]、写入成绩                                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│[2]、修改成绩                                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│[3]、查询成绩                                     │\n";
	cout<<"│                                                  │\n";
	cout<<"│[4]、退出                                         │\n";
	cout<<"│                                                  │\n";
	cout<<"│[作者]、翁丽霞的男朋友                            │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"请选择：";
	int select;
	cin>>select;
	return select;
}