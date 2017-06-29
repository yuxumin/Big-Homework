#include<fstream>
using namespace std;
#ifndef APP_H
#define APP_H
class App{	
public:
	friend class Student;
	App(bool a):Continue(a){}
	void Start();
	int MainMune();
	bool SignInMune();
	void SetScore();
	void ChangeScore();
	void FindScore();
	void Exit();
	bool Continue;
	bool Exwhile;
	void Quit();
//	friend void CopyList(ifstream& inf);
};
#endif // !APP_H
