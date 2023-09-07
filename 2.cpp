#include <iostream>
#include <string>
#include<vector>
#include <conio.h>
using namespace std;


class book {
public:
	book(string n = " ", string c = " ", int sal = 0) : name(n), WRname(c), sal(sal) {}
	book(){}
	~book(){}

	string getName() { return name; }
	string getwrname() { return WRname; }
	int getsal(){ return sal; }
	
	void printbook(){
		cout << "name: " << name << endl << "writer name: " << WRname << endl << "sal chap :" << sal << endl ;
	
	}
protected:
	int sal ;
	string WRname, name;
};

class Ebook : public book {
public:
	Ebook(string n, string wr, int sa, int gh = 0, string fo = " ", int si= 0)
		: book(n, wr, sa), gheymat(gh),format(fo), size(si) {}

	string getformat() { return format; }
	int getsize() { return size; }
	void printebook(){
		cout << " format : " << format << endl << "size :" << size << endl;
	
	}
	int getgheymat(){ return gheymat; }
private:
	string format;
	int size, gheymat;
};

class notebook : public book {
public:
	notebook (string n, string wr, int sa ,int too= 0 , int ar=0)
		: book(n, wr, sa),tool(too), arz(ar) {}

	int gettool() { return tool; }
	int getarz(){ return arz; }
	void printnotebook(){
		printbook();
		cout << "tool : " << tool << endl << "arze: " << arz << endl;
	}
private:
	int tool , arz;
};

int main(){
	string name = "books";
	string wr = "shekspier";
	int gheymat = 100;
	int sal = 1397;
	int tool = 2;
	int arz = 1;
	notebook s(name, wr, sal , tool, arz);
	s.printnotebook();

	system("puase");
	 return 0;
}