#include <iostream>
#include <string>
#include<vector>
#include <conio.h>

using namespace std;


class Name {
public:
	Name(string n = " ", string c = " ", string N = " ") : name(n), Family(c), Nick(N){}

	string getName(){ return name; }
	string getFamily(){ return Family; }
	void print(){

		cout << name << "  " << Family;

	}

protected:
	string Nick, name, Family;
};

class Person : public Name {
public:
	Person(string n, string c, int a= 0 , string edu =" " , int d = 1 , int m = 1 ,int y = 1)
		: Name(n, c, " "), age(a), education(edu), day(d), month(m), year(y) {
		count++;
	}
	~Person(){ count--; }
	static int count;
	string geteducation(){ return education; }
	int getage (){ return age; }
	int getday(){ return day; }
	int getmonth(){ return month; }
	int getyear(){ return year; }
	void show(){

		cout << "name: " << name.getName() << endl << "family : " << family.getFamily() << endl << "age : " << age <<
			endl << "education :" << education<< endl << " b.day: " << day << "/" << month << "/" << year << endl;
	
	}
	
private:
	Name name , family;
	int age, day, month, year;
	string education;
};
int Person::count = 0;



int main()
{
	vector <Person> list;
	for (;;){
		cout << "create a new person ? (Y/N)" << endl;
		char a;
		cin >> a;

		if (a == 'Y' || a == 'y'){
			string n, f, ed;
			int a, da, mo, ye;

			cout << "enter peson name: " << endl;
			cin >> n;

			cout << "enter peson family: " << endl;
			cin >> f;

			cout << "enter peson education: " << endl;
			cin >> ed;

			cout << "enter peson age: " << endl;
			cin >> a;

			cout << "enter peson day of birthday: " << endl;
			cin >> da;

			cout << "enter peson month of birthday: " << endl;
			cin >> mo;

			cout << "enter peson year of birthday: " << endl;
			cin >> ye;

			list.push_back(Person(n, f, a, ed, da, mo, ye));

		}
		else {
			break;
		}
	}

		cout << "there are " << Person::count << "objects of person here" << endl;

		cout <<  "are you want to show all information ? (Y/N)" << endl;
		char b = ' ';
		cin >> b;
		if (b == 'Y' || b == 'y'){
			for (int i = 0; i < list.size(); i++){

				list[i].show();
				cout << endl;

			}
		}
		

	system("puase");
	return 0;
	}
	