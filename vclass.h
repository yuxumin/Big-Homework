#include<fstream>
using namespace std;
#ifndef  P
#define P
class vclass{	
public:
	virtual void Fout(ofstream&of) = 0;
	virtual void Fin(ifstream&inf) = 0;

};
#endif