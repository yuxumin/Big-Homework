#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include"Student.h"
#include"App.h"
#pragma warning(disable:4996)
using namespace std;
Student list[500];
int main(){
	App first(true);
	while(first.Continue)
	{
		first.Start();
	}
	return 0;
}
