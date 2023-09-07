#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;


//************************MOTEGHAYER HAYE OMUMI**********************************

int error;

struct ozvinf
{
	int id, melliid, day, month, year, stuid, pass;
	double jarime;
	string name, family, noe;

};
struct ketabdarinf
{
	string name, family, madrak, semat;
	int id, melliid, day, month, year, pass;

};
struct bookinf
{
	int id, bookpage, tedad, mojodi;
	string onvan, daste;
};
struct majaleinf{

	int id, bookpage, tedad, mojodi;
	string onvan;

};
struct payanname
{
	int id, bookpage, mojodi;
	string onvan, maghta, daneshkade, gorup;
};



//*********************************************************************

bool isLeapYear(int year)
{
	int r = year % 33;
	return r == 1 || r == 5 || r == 9 || r == 13 || r == 17 || r == 22 || r == 26 || r == 30;
}
int daysOfMonth(int m, int y)
{

	if (m < 7)
		return 31;
	else if (m < 12)
		return 30;
	else if (m == 12)
		return isLeapYear(y) ? 30 : 29;

}




//************************ Classes*****************************


class Date {
public:
	Date(int d, int m, int y)
	{
		setDate(d, m, y);
	}
	void print() { cout << day << '/' << month << '/' << year; }

	void setDate(int d, int m, int y)
	{
		if (y < 0 || m < 1 || m > 12 || d < 1 || d > daysOfMonth(m, y))
		{
			error = 1;
			return;
		}

		day = d;
		month = m;
		year = y;
		error = 0;
	}
	Date(){}



	void setbday(int day){ this->day = day; }
	void setmonth(int month){ this->month = month; }
	void setyear(int year){ this->year = year; }
	int getday(){ return day; }
	int getmonth(){ return month; }
	int getyear(){ return year; }

private:
	int day, month, year;
};
Date readDate()
{
	int d, m, y;
	cout << "please enter day, month and year of birthdate: ";
	cin >> d >> m >> y;
	Date bd = Date(d, m, y);

	while (error == 1)
	{
		cout << "please enter day, month and year of birthdate: ";
		cin >> d >> m >> y;
		bd = Date(d, m, y);
	}

	return bd;

}

class dad{
public:

	dad(int id, int bookpage, string onvan){
		this->id = id;
		this->bookpage = bookpage;
		this->onvan = onvan;
	}
	dad(){}
	~dad(){}

	void setid(int id){ this->id = id; }
	void setbookpage(int bookpage){ this->bookpage = bookpage; }
	void setonvan(string onvan){ this->onvan = onvan; }

	int getid(){ return id; }
	int getbookpage(){ return bookpage; }
	string getonvan(){ return onvan; }




protected:
	int id, bookpage;
	string onvan;


};
class book : public dad{
public:

	book(int id, string onvan, int bookpage, string daste, int tedad, int mojodi) : dad(id, bookpage, onvan){
		try{
			this->daste = daste;
			this->tedad = tedad;
			this->mojodi = mojodi;
			if (mojodi > tedad){
				throw mojodi;
			}
		}
		catch (int mojodi){

			cout << "\n\n\t\t THE tedad OF MOJODI IS FEWER THAN tedad !\n";
		}
	}
	book(){}
	~book() {  }


	void setmojodi(int c){ mojodi = c; }
	void setdaste(string t){ daste = t; }
	void settedad(int n){ tedad = n; }

	int getmojodi(){ return mojodi; }
	int gettedad(){ return tedad; }
	string getdaste(){ return daste; }


	void plustedad(){

		int num = gettedad();
		num = num + 1;
		settedad(num);

	}
	void plusmojodi(){
		int num = getmojodi();
		num = num + 1;
		setmojodi(num);

	}
	void minestedad(){
		int num = gettedad();
		num = num - 1;
		settedad(num);

	}
	void minesmojodi(){
		int num = getmojodi();
		num = num - 1;
		setmojodi(num);

	}
	void changedaste(){

		cout << "\n\t\tENTER NEW DASTE : \n";
		string newdaste;
		cin >> newdaste;
		setdaste(newdaste);


	}
	void changetedad(){

		cout << "\n\t\tENTER NEW tedad : \n";
		int newtedad;
		cin >> newtedad;
		settedad(newtedad);


	}
	void changemojodi(){

		cout << "\n\t\tENTER NEW MOJODI : \n";
		int newmojodi;
		cin >> newmojodi;
		setmojodi(newmojodi);


	}
	void changeonvan(){

		cout << "\n\t\tENTER NEW ONVAN : \n";
		string newonvan;
		cin >> newonvan;
		setonvan(newonvan);


	}
	void changebookpage(){

		cout << "\n\t\tENTER NEW bookPAGE : \n";
		int newbookpage;
		cin >> newbookpage;
		setbookpage(newbookpage);


	}
private:
	string daste;
	int  tedad, mojodi;

};
class majale : public dad{
public:

	majale(int id, string onvan, int bookpage, int tedad, int mojodi) :dad(id, bookpage, onvan){
		try{
			this->tedad = tedad;
			this->mojodi = mojodi;
			if (mojodi > tedad){
				throw mojodi;
			}
		}
		catch (int mojodi){

			cout << "\n\n\t\t THE tedad OF MOJODI IS FEWER THAN tedad !\n";
		}

	}
	majale(){}
	~majale(){}
	void setmojodi(int c){ mojodi = c; }
	void setbookpage(int t){ bookpage = t; }
	void settedad(int n){ tedad = n; }
	void setid(int id){ this->id = id; }
	void setonvan(string onvan){ this->onvan = onvan; }

	int getid(){ return id; }
	int getbookpage(){ return bookpage; }
	string getonvan(){ return onvan; }
	int getmojodi(){ return mojodi; }
	int gettedad(){ return tedad; }



	void plustedad(){

		int num = gettedad();
		num = num + 1;
		settedad(num);

	}
	void plusmojodi(){
		int num = getmojodi();
		num = num + 1;
		setmojodi(num);

	}
	void changetedad(){

		cout << "\n\t\tENTER NEW tedad : \n";
		int newtedad;
		cin >> newtedad;
		settedad(newtedad);


	}
	void changemojodi(){

		cout << "\n\t\tENTER NEW MOJODI : \n";
		int newmojodi;
		cin >> newmojodi;
		setmojodi(newmojodi);


	}
	void changeonvan(){

		cout << "\n\t\tENTER NEW ONVAN : \n";
		string newonvan;
		cin >> newonvan;
		setonvan(newonvan);


	}
	void changebookpage(){

		cout << "\n\t\tENTER NEW bookPAGE : \n";
		int newbookpage;
		cin >> newbookpage;
		setbookpage(newbookpage);


	}



private:
	int tedad, mojodi;

};
class thesis : public dad{
public:

	thesis(int id, string onvan, int bookpage, string maghta, string daneshkade, string gorup, int mojodi) :dad(id, bookpage, onvan){
		this->maghta = maghta;
		this->daneshkade = daneshkade;
		this->gorup = gorup;
		this->mojodi = mojodi;
	}
	thesis(){}
	~thesis(){}

	void setmaghta(string c){ maghta = c; }
	void setdaneshkade(string t){ daneshkade = t; }
	void setgorup(string n){ gorup = n; }
	void setmojodi(int c){ mojodi = c; }


	string getmaghta(){ return maghta; }
	int getmojodi(){ return mojodi; }
	string getdaneshkade(){ return daneshkade; }
	string getgroup(){ return gorup; }


	void plusmojodi(){
		int num = getmojodi();
		num = num + 1;
		setmojodi(num);

	}

	void minesmojodi(){
		int num = getmojodi();
		num = num - 1;
		setmojodi(num);

	}

	void changemaghta(){

		cout << "\n\t\tENTER NEW maghta : \n";
		string newmaghta;
		cin >> newmaghta;
		setmaghta(newmaghta);


	}
	void changedaneshkade(){

		cout << "\n\t\tENTER NEW COLLAGE : \n";
		string newdaneshkade;
		cin >> newdaneshkade;
		setdaneshkade(newdaneshkade);


	}
	void changemojodi(){

		cout << "\n\t\tENTER NEW MOJODI : \n";
		int newmojodi;
		cin >> newmojodi;
		setmojodi(newmojodi);


	}
	void changeonvan(){

		cout << "\n\t\tENTER NEW ONVAN : \n";
		string newonvan;
		cin >> newonvan;
		setonvan(newonvan);


	}
	void changegroup(){

		cout << "\n\t\tENTER NEW GROUP : \n";
		string newgroup;
		cin >> newgroup;
		setgorup(newgroup);


	}
	void changebookpage(){

		cout << "\n\t\tENTER NEW bookPAGE : \n";
		int newbookpage;
		cin >> newbookpage;
		setbookpage(newbookpage);


	}

private:

	string maghta, daneshkade, gorup;
	int mojodi;

};
class dadoz :public Date{
public:

	dadoz(int id, int melliid, string name, string family, int day, int month, int year, int pass) : Date(day, month, year){

		this->id = id;
		this->melliid = melliid;
		this->name = name;
		this->family = family;
		/*this->day = day;
		this->month = month;
		this->year = year;*/
		this->pass = pass;

	}
	dadoz(){}
	~dadoz(){}

	void setid(int id){ this->id = id; }
	void setmelliid(int melliid){ this->melliid = melliid; }
	void setname(string name){ this->name = name; }
	void setfamily(string family){ this->family = family; }
	void setpass(int pass){ this->pass = pass; }
	int getpass(){ return pass; }
	int getid(){ return id; }
	int getmelliid(){ return melliid; }
	string getname(){ return name; }
	string getfamily(){ return family; }

protected:

	int id, melliid, pass;
	string name, family;


};
class ozv : public dadoz{
public:
	ozv(int id, int melliid, string name, string family, int day, int month, int year, double jarime, string noe, int stuid, int pass) :
		dadoz(id, melliid, name, family, day, month, year, pass){

		this->jarime = jarime;
		this->noe = noe;
		this->stuid = stuid;
	}
	ozv(){}
	~ozv(){}
private:
	double jarime;
	string noe;
	int stuid;

};
class ketabdar : public dadoz{
public:
	ketabdar(int id, int melliid, string name, string family, int day, int month, int year, string madrak, string semat, int pass)
		:dadoz(id, melliid, name, family, day, month, year, pass){

		this->madrak = madrak;
		this->semat = semat;

	}
	ketabdar(){}
	~ketabdar(){}
private:
	string madrak, semat;
};
class AM{
public:
	AM(int idOZV, int idneveshtar, int daygive, int monthgive, int yeargive, int dayback, int monthback, int yearback){

		this->idOZV = idOZV;
		this->idneveshtar = idneveshtar;
		this->daygive = daygive;
		this->monthgive = monthgive;
		this->yeargive = yeargive;
		this->dayback = dayback;
		this->monthback = monthback;
		this->yearback = yearback;
	}
	AM(){}
	~AM(){}


private:
	int idOZV, idneveshtar, daygive, monthgive, yeargive, dayback, monthback, yearback;
};


//************************ book***************************

vector<book> bookvector;

void addbook(){

	char q;
	do
	{

		system("cls");
		ifstream addbook("book.txt");
		ofstream editfinal("bookfinal.txt");
		if (!addbook)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		bookinf a;
		bookinf b;
		bool found = false;

		cout << "\n\n\t\t please enter new book id : ";
		cin >> a.id;
		while (addbook >> b.id)
		{

			addbook >> b.onvan;
			addbook >> b.bookpage;
			addbook >> b.tedad;
			addbook >> b.daste;
			addbook >> b.mojodi;
			if (a.id == b.id){
				found = true;
				//int p = b.tedad + 1;
				//int m = b.mojodi + 1 ;


				cout << "\n\t\t This book is available ! \n\n";

				cout << "\n\t\t\t| " << "book id    : " << b.id;
				cout << "\n\t\t\t| " << "onvan book : " << b.onvan;
				cout << "\n\t\t\t| " << "bookpage  : " << b.bookpage;
				cout << "\n\t\t\t| " << "daste : " << b.daste;
				cout << "\n\t\t\t| " << "tedad: " << b.tedad;
				cout << "\n\t\t\t| " << "mojudi: " << b.mojodi;
				cout << "\n\n\t\tdo you want to add new book ? (y/n)\n\t\t";
				char chp;
				cin >> chp;
				if (chp == 'y'){

					book bok(a.id, b.onvan, b.bookpage, b.daste, b.tedad, b.mojodi);
					bookvector.push_back(bok);
					bok.plustedad();
					bok.plusmojodi();
					editfinal << bok.getid() << " " << bok.getonvan() << " " << bok.getbookpage() << " " << bok.getdaste() << " " <<
						bok.gettedad() << " " << bok.getmojodi() << " " << endl;

					cout << "\n\t\t\t\t*********************************************************************\n";
					cout << "\t\t\t\t*                ok your book is added                                *\n";
					cout << "\t\t\t\t***********************************************************************\n";

				}
				else if (chp == 'n'){

					cout << "\n\n\t\tOK !ID IS UNIQ AND PLEASE ENTER NEW ID FOR BOOK: ";
					cin >> a.id;

					cout << "\n\n\t\t please enter book onvan: ";
					cin >> a.onvan;
					cout << "\n\n\t\t enter book pages of new book: ";
					cin >> a.bookpage;
					cout << "\n\n\t\t please enter daste of new book: ";
					cin >> a.daste;
					int mojo = 1;
					int num = 1;
					editfinal << a.id << " " << a.onvan << " " << a.bookpage << " " << a.daste << " " << mojo << " " << num << " " << endl;

					cout << "\n\t\t\t\t*********************************************************************\n";
					cout << "\t\t\t\t*                       your book is add                              *\n";
					cout << "\t\t\t\t***********************************************************************\n";
				}
			}
			else{
				editfinal << b.id << " " << b.onvan << " " << b.bookpage << " " << b.daste << " " << b.tedad << " " << b.mojodi << " " << endl;
			}

		}if (!found){

			cout << "\n\n\t\t please enter onvan new book: ";
			cin >> a.onvan;
			cout << "\n\n\t\t please enter book pages of new book: ";
			cin >> a.bookpage;
			cout << "\n\n\t\t please enter daste new book: ";
			cin >> a.daste;
			int mojo = 1;
			int num = 1;
			editfinal << a.id << " " << a.onvan << " " << a.bookpage << " " << a.daste << " " << mojo << " " << num << " " << endl;

			cout << "\n\t\t\t\t******************************************************************************\n";
			cout << "\t\t\t\t*                    your book is add correctly                                *\n";
			cout << "\t\t\t\t********************************************************************************\n";
		}
		addbook.close();
		editfinal.close();

		//remove("book.txt");
		//rename("bookfinal.txt", "book.txt");
		if (remove("book.txt") != 0){
			cout << "error in deleting original file" << endl;
		}

		if (rename("bookfinal.txt", "book.txt") != 0){
			cout << "error in renaming output file" << endl;
		}
		cout << "\n\t\t\t\t do you want add other book again?(y/n) \n";

		cin >> q;

	} while (q != 'n');

	//int id, string onvan, int bookpage, string daste, int tedad, int mojodi

}
void modifybook(){
	char q;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter your book id that you want modify it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream editbook("book.txt");
		ofstream editfinal("editbook.txt");
		if (!editbook)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		bookinf b;
		bool found = false;

		system("cls");

		while (editbook >> b.id)
		{
			editbook >> b.onvan;
			editbook >> b.bookpage;
			editbook >> b.daste;
			editbook >> b.tedad;
			editbook >> b.mojodi;

			if (searchid == b.id){
				char a;
				found = true;
				book bk(b.id, b.onvan, b.bookpage, b.daste, b.tedad, b.mojodi);
				do
				{
					system("cls");
					cout << "\n\n\t\t\t wich one do you want to modify ? \n ";
					cout << "\t\t\t ******************************************************************** \n";
					cout << "\t\t\t*                                                                    *\n";
					cout << "\t\t\t*                            1  ONVAN                                *\n";
					cout << "\t\t\t*                            2  bookPAGE                             *\n";
					cout << "\t\t\t*                            3  DASTE                                *\n";
					cout << "\t\t\t*                            4  tedad                                *\n";
					cout << "\t\t\t*                            5  MOJODI                               *\n";
					cout << "\t\t\t*                                                                    *\n";
					cout << "\t\t\t********************************************************************\n\n";
					int choice;
					cin >> choice;
					switch (choice)
					{
					case 1: {
								bk.changeonvan();
								cout << "\n\t\t\t\t******************************************************\n";
								cout << "\t\t\t\t*                  onvan is changing                   *\n";
								cout << "\t\t\t\t********************************************************\n";
								break; }
					case 2:{
							   bk.changebookpage();
							   cout << "\n\t\t\t\t*******************************************************\n";
							   cout << "\t\t\t\t*                 bookpage is changing                  *\n";
							   cout << "\t\t\t\t*********************************************************\n";
							   break; }
					case 3:{
							   bk.changedaste();
							   cout << "\n\t\t\t\t*******************************************************\n";
							   cout << "\t\t\t\t*                 daste is changing                     *\n";
							   cout << "\t\t\t\t*********************************************************\n";
							   break; }
					case 4: {
								bk.changetedad();
								cout << "\n\t\t\t\t*******************************************************\n";
								cout << "\t\t\t\t*                 tedad is changing                     *\n";
								cout << "\t\t\t\t*********************************************************\n";
								break; }
					case 5: {
								bk.changemojodi();
								cout << "\n\t\t\t\t*******************************************************\n";
								cout << "\t\t\t\t*                mojodi is changing                     *\n";
								cout << "\t\t\t\t*********************************************************\n";
								break; }
					default: cout << "\n\t\t\t Oops,error!!\n"; break;
					}
					cout << "\n\t\t\t do you want to changing another things ? (y/n)\n";
					cin >> a;


				} while (a != 'n');

				editfinal << bk.getid() << " " << bk.getonvan() << " " << bk.getbookpage() << " " << bk.getdaste()
					<< " " << bk.gettedad() << " " << bk.getmojodi() << " " << endl;

			}
			else
			{
				editfinal << b.id << " " << b.onvan << " " << b.bookpage << " " << b.daste
					<< " " << b.tedad << " " << b.mojodi << " " << endl;
			}
		}

		//ifstream editbook("book.txt");
		//ofstream editfinal("editbook.txt");
		editbook.close();
		editfinal.close();

		if (remove("book.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("editbook.txt", "book.txt") != 0){
			cout << "error in renaming output file" << endl;
		}

		if (!found){

			cout << " \n\t\t\t Oops not find ! \n";

		}

		cout << "\n\t\t\t do you want change another book (y/n) ?\n";
		cin >> q;

	} while (q != 'n');


}
void deletebook(){
	char y;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter your book id that you want delete it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream deletebook("book.txt");
		ofstream deletefinal("delbook.txt");
		if (!deletebook)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		bookinf b;
		bool found = false;

		system("cls");

		while (deletebook >> b.id)
		{

			deletebook >> b.onvan;
			deletebook >> b.bookpage;
			deletebook >> b.daste;
			deletebook >> b.tedad;
			deletebook >> b.mojodi;
			book bg(b.id, b.onvan, b.bookpage, b.daste, b.tedad, b.mojodi);
			if (searchid == b.id){
				found = true;


				cout << "\n\t\t\t " << "ID    : " << b.id;
				cout << "\n\t\t\t " << "onvan : " << b.onvan;
				cout << "\n\t\t\t " << "bookpage  : " << b.bookpage;
				cout << "\n\t\t\t " << "daste : " << b.daste;
				cout << "\n\t\t\t " << "tedad: " << b.tedad;
				cout << "\n\t\t\t " << "mojodi: " << b.mojodi;

				cout << "\n\n\t\t are you sure you want to delete this book?(y/n)) \n\t\t";
				char r;
				cin >> r;
				if (r == 'y' || r == 'Y'){

					cout << "\n\t\t\t\t***********************************************************\n";
					cout << "\t\t\t\t*                      book is deleting                     *\n";
					cout << "\t\t\t\t*************************************************************\n";

				}
				else if (r == 'n' || r == 'N')
				{
					deletefinal << bg.getid() << " " << bg.getonvan() << " " << bg.getbookpage() << " " << bg.getdaste() << " " << bg.gettedad()
						<< " " << bg.getmojodi() << " " << endl;
				}
				else
				{
					cout << "\n\n\n\t\t\t\tOops,error! ";
					abort();
				}

			}
			else
			{
				deletefinal << bg.getid() << " " << bg.getonvan() << " " << bg.getbookpage() << " " << bg.getdaste() << " " << bg.gettedad()
					<< " " << bg.getmojodi() << " " << endl;
			}

		}
		if (!found){

			cout << " \n\n\t\t\t we cant found this id ! book is not delete \n";

		}

		deletebook.close();
		deletefinal.close();

		if (remove("book.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("delbook.txt", "book.txt") != 0){
			cout << "error in renaming output file" << endl;
		}
		cout << "\n\n\t\t do you wanr to deleting another book? (y/n)\n\t\t";
		cin >> y;

	} while (y != 'n');


}
void searchbook(){

	char g;
	do
	{


		system("cls");
		cout << "\n\n\t\t plese enter your book id that you want searching : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream searchbook("book.txt");
		if (!searchbook)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		bookinf b;
		bool found = false;

		system("cls");

		while (searchbook >> b.id)
		{

			searchbook >> b.onvan;
			searchbook >> b.bookpage;
			searchbook >> b.daste;
			searchbook >> b.tedad;
			searchbook >> b.mojodi;
			book bs(b.id, b.onvan, b.bookpage, b.daste, b.tedad, b.mojodi);
			if (searchid == b.id){
				found = true;


				cout << "\n\t\t\t " << "id    : " << b.id;
				cout << "\n\t\t\t " << "onvan : " << b.onvan;
				cout << "\n\t\t\t " << "bookpage : " << b.bookpage;
				cout << "\n\t\t\t " << "daste : " << b.daste;
				cout << "\n\t\t\t " << "tedad: " << b.tedad;
				cout << "\n\t\t\t " << "mojodi: " << b.mojodi;

			}
		}
		if (!found){

			cout << " \n\n\t\t\t we cant find this book whith this id !  \n";

		}

		searchbook.close();

		cout << "\n\n\t\t do you want to searching another book? (y/n)\n";
		cin >> g;

	} while (g != 'n');




}
void display1(string m){



part2:
	system("cls");
	cout << "\n\t\t*********************************************************************** \n";
	cout << "\t\t     ID\t      ONVAN\t        bookPAGE\t\t      DASTE\t      tedad    MOJODI    \n";
	cout << "\t\t********************************************************************\n\n\t\t";
	ifstream displaybook("book.txt");
	if (!displaybook)
	{
		cout << "the file could not be opened!" << endl;
		abort();
	}
	bookinf b;
	while (displaybook >> b.id)
	{

		displaybook >> b.onvan;
		displaybook >> b.bookpage;
		displaybook >> b.daste;
		displaybook >> b.tedad;
		displaybook >> b.mojodi;
		if (m == b.daste){

			cout << setw(5) << b.id << "\t" << setw(6) << b.onvan << "\t\t" << setw(4) << b.bookpage << "\t\t" << setw(9) << b.daste <<
				"\t\t" << setw(4) << b.tedad << "\t  " << setw(4) << b.mojodi << "\t\n\t\t";
		}
	}
	char u;
	cout << "\n\n\t\t\t\t do you want countinue? (y/n)\n\t\t\t\t";
	cin >> u;
	if (u = 'n') goto part2;
	displaybook.close();


}
void displaybook(){
	system("cls");
	cout << "\n\n\t\t\t | 1-show all information books in library \n";//نمایش کل کتابها
	cout << "\t\t\t | 2- show all information books in group \n\t\t\t";//نشون بده که جزو کدوم دسته هستن
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		  label1:
			  cout << "\n\t\t ********************************************************************* \n";
			  cout << "\t\t   ID\t     ONVAN\t        bookPAGE\t\t   DASTE\t      tedad    MOJODI   \n";
			  cout << "\t\t*******************************************************************\n\n\t\t";


			  ifstream displaybook("book.txt");
			  if (!displaybook)
			  {
				  cout << "the file could not be opened!" << endl;
				  abort();
			  }
			  bookinf b;
			  while (displaybook >> b.id)
			  {

				  displaybook >> b.onvan;
				  displaybook >> b.bookpage;
				  displaybook >> b.daste;
				  displaybook >> b.tedad;
				  displaybook >> b.mojodi;

				  cout << setw(3) << b.id << "\t" << setw(10) << b.onvan << "\t\t" << setw(4) << b.bookpage << "\t\t" << setw(9) << b.daste <<
					  "\t\t" << setw(4) << b.tedad << "\t  " << setw(4) << b.mojodi << "\t\n\t\t";
			  }
			  char u;
			  cout << "\n\n\t\t\t\t DO YOU WANT TO CONTINUE? (y/n)\n\t\t\t\t";
			  cin >> u;
			  if (u = 'n') goto label1;
			  displaybook.close();
			  break;
	}
	case 2:{

			   system("cls");

			   cout << "\n\n\t\t\t\t choose your group :";
			   cout << "\n\n\t\t\t  1 MOHANDESI \n";
			   cout << "\t\t\t  2 ADABIAT \n";
			   cout << "\t\t\t  3 ELAHIAT \n";
			   cout << "\t\t\t  4 MOTEFAREGHE \n";
			   cout << "\t\t\t  5 PAYE \n\t\t\t";
			   string mohandesi = "mohandesi";
			   string adabiat = "adabiat";
			   string elahiat = "elahiat";
			   string motefareghe = "motefareghe";
			   string paye = "paye";
			   int choice;
			   cin >> choice;
			   if (choice == 1) display1(mohandesi);
			   else if (choice == 2)display1(adabiat);
			   else if (choice == 3)display1(elahiat);
			   else if (choice == 4)display1(motefareghe);
			   else if (choice == 5)display1(paye);
			   else
			   {
				   cout << "\n\n\t\t\tOops!EROR!";
				   abort();
			   }
			   break;
	}
	default: cout << "ERROR!"; abort(); break;
	}

}



// ******************************** majale**************************


void addmajale(){

	char q;
	do
	{
		system("cls");
		ifstream addmajale("majale.txt");
		ofstream editmajale("majalefinal.txt");
		if (!addmajale)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		majaleinf a;
		majaleinf b;
		bool found = false;

		cout << "\n\n\t\t please enter the id new majale: ";
		cin >> a.id;
		while (addmajale >> b.id)
		{

			addmajale >> b.onvan;
			addmajale >> b.bookpage;
			addmajale >> b.tedad;
			addmajale >> b.mojodi;
			if (a.id == b.id){
				found = true;
				//int p = b.tedad + 1;
				//int m = b.mojodi + 1 ;


				cout << "\n\t\t Oops!this majale was in our library in the past !\n\n";


				cout << "\n\t\t\t " << "id    : " << b.id;
				cout << "\n\t\t\t " << "onvan : " << b.onvan;
				cout << "\n\t\t\t " << "bookpage  : " << b.bookpage;
				cout << "\n\t\t\t " << "tedad: " << b.tedad;
				cout << "\n\t\t\t " << "mojodi: " << b.mojodi;
				cout << "\n\n\t\tdo you want to add this majale ? (y/n)\n\t\t";
				char chp;
				cin >> chp;
				if (chp == 'y'){

					majale mag(a.id, b.onvan, b.bookpage, b.tedad, b.mojodi);
					//bookvector.push_back(mag);
					mag.plustedad();
					mag.plusmojodi();
					editmajale << mag.getid() << " " << mag.getonvan() << " " << mag.getbookpage() << " " <<
						mag.gettedad() << " " << mag.getmojodi() << " " << endl;

					cout << "\n\t\t\t\t*******************************************************************\n";
					cout << "\t\t\t\t*                       this majale is add                          *\n";
					cout << "\t\t\t\t*********************************************************************\n";

				}
				else if (chp == 'n'){

					cout << "\n\n\t\tOK !ID IS UNIQ AND PLEASE ENTER NEW ID FOR majale: ";
					cin >> a.id;

					cout << "\n\n\t\t please enter onvan new majale: ";
					cin >> a.onvan;
					cout << "\n\n\t\t please enter bookpage new majale: ";
					cin >> a.bookpage;
					int mojo = 1;
					int num = 1;
					editmajale << a.id << " " << a.onvan << " " << a.bookpage << " " << mojo << " " << num << " " << endl;

					cout << "\n\t\t\t\t*********************************************************************\n";
					cout << "\t\t\t\t*                     this majale is add                              *\n";
					cout << "\t\t\t\t***********************************************************************\n";

				}
			}
			else{
				editmajale << b.id << " " << b.onvan << " " << b.bookpage << " " << b.tedad << " " << b.mojodi << " " << endl;

			}

		}if (!found){

			cout << "\n\n\t\t please enter onvan majale: ";
			cin >> a.onvan;
			cout << "\n\n\t\t please enter bookpage majale: ";
			cin >> a.bookpage;
			int mojo = 1;
			int num = 1;
			editmajale << a.id << " " << a.onvan << " " << a.bookpage << " " << mojo << " " << num << " " << endl;

			cout << "\n\t\t\t\t*********************************************************************************\n";
			cout << "\t\t\t\t*                                       majale is add                             *\n";
			cout << "\t\t\t\t***********************************************************************************\n";


		}
		addmajale.close();
		editmajale.close();

		//remove("book.txt");
		//rename("bookfinal.txt", "book.txt");


		if (remove("majale.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("majalefinal.txt", "majale.txt") != 0){
			cout << "error in renaming output file" << endl;
		}


		cout << "\n\t\t\t\t do you want add anothermajale ?(y/n) \n\t\t\t\t";

		cin >> q;

	} while (q != 'n');

	//int id, string onvan, int bookpage, string daste, int tedad, int mojodi




}
void modifymajale(){
	char q;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter your majale id that you want modify it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream editmajale("majale.txt");
		ofstream editfinal("editfinal.txt");
		if (!editmajale)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		majaleinf b;
		bool found = false;

		system("cls");

		while (editmajale >> b.id)
		{

			editmajale >> b.onvan;
			editmajale >> b.bookpage;
			editmajale >> b.tedad;
			editmajale >> b.mojodi;

			if (searchid == b.id){
				char a;
				found = true;
				majale bk(b.id, b.onvan, b.bookpage, b.tedad, b.mojodi);
				do
				{
					system("cls");
					cout << "\n\n\t\t\t wich one do you want to modify ? \n ";
					cout << "\t\t\t ******************************************************************** \n";
					cout << "\t\t\t*                                                                    *\n";
					cout << "\t\t\t*                            1  ONVAN                                *\n";
					cout << "\t\t\t*                            2  bookPAGE                             *\n";
					cout << "\t\t\t*                            3  tedad                                *\n";
					cout << "\t\t\t*                            4  mojodi                               *\n";
					cout << "\t\t\t*                                                                    *\n";
					cout << "\t\t\t********************************************************************\n\n";
					int choice;
					cin >> choice;
					switch (choice)
					{
					case 1: {
								bk.changeonvan();
								cout << "\n\t\t\t\t*******************************************************\n";
								cout << "\t\t\t\t*                 onvan is changing                     *\n";
								cout << "\t\t\t\t*********************************************************\n";
								break; }
					case 2:{
							   bk.changebookpage();
							   cout << "\n\t\t\t\t*******************************************************\n";
							   cout << "\t\t\t\t*                bookpage is changing                   *\n";
							   cout << "\t\t\t\t*********************************************************\n";
							   break; }
					case 3:{
							   bk.changetedad();
							   cout << "\n\t\t\t\t*******************************************************\n";
							   cout << "\t\t\t\t*                 tedad is changing                     *\n";
							   cout << "\t\t\t\t*********************************************************\n";
							   break; }
					case 4: {
								bk.changemojodi();
								cout << "\n\t\t\t\t*******************************************************\n";
								cout << "\t\t\t\t*                 mojodi is changing                     *\n";
								cout << "\t\t\t\t*********************************************************\n";
								break; }

					default: cout << "\n\t\t\t Oops,error!!\n"; break;
					}
					cout << "\n\t\t\t do you want to change another thing ? (y/n)\n\t\t\t";
					cin >> a;


				} while (a != 'n');

				editfinal << bk.getid() << " " << bk.getonvan() << " " << bk.getbookpage() << " "
					<< bk.gettedad() << " " << bk.getmojodi() << " " << endl;

			}
			else
			{
				editfinal << b.id << " " << b.onvan << " " << b.bookpage << " " << b.tedad << " " << b.mojodi << " " << endl;
			}
		}

		//ifstream editbook("book.txt");
		//ofstream editfinal("editbook.txt");
		editmajale.close();
		editfinal.close();

		if (remove("majale.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("editfinal.txt", "majale.txt") != 0){
			cout << "error in renaming output file" << endl;
		}

		if (!found){

			cout << " \n\t\t\t we cant found this majale whith this id! \n";

		}

		cout << "\n\t\t\t do you want to change another majale (y/n) ?\n";
		cin >> q;

	} while (q != 'n');


}
void deletemajale(){
	char y;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter your majale id that you want delete it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream deletemajale("majale.txt");
		ofstream deletefinal("delmajale.txt");
		if (!deletemajale)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		majaleinf b;
		bool found = false;

		system("cls");

		while (deletemajale >> b.id)
		{

			deletemajale >> b.onvan;
			deletemajale >> b.bookpage;
			deletemajale >> b.tedad;
			deletemajale >> b.mojodi;
			majale bg(b.id, b.onvan, b.bookpage, b.tedad, b.mojodi);
			if (searchid == b.id){
				found = true;


				cout << "\n\t\t\t " << "id   : " << b.id;
				cout << "\n\t\t\t " << "onvan : " << b.onvan;
				cout << "\n\t\t\t " << "bookpage  : " << b.bookpage;
				cout << "\n\t\t\t " << "tedad: " << b.tedad;
				cout << "\n\t\t\t " << "mojodi: " << b.mojodi;

				cout << "\n\n\t\t are you sure to delete this majale?(y/n)) \n\t\t";
				char r;
				cin >> r;
				if (r == 'y' || r == 'Y'){

					cout << "\n\t\t\t\t***********************************************************\n";
					cout << "\t\t\t\t*                 majale is delete                          *\n";
					cout << "\t\t\t\t*************************************************************\n";

				}
				else if (r == 'n' || r == 'N')
				{
					deletefinal << bg.getid() << " " << bg.getonvan() << " " << bg.getbookpage() << " " << bg.gettedad()
						<< " " << bg.getmojodi() << " " << endl;
				}
				else
				{
					cout << "\n\n\n\t\t\t\tOops,error! ";
					abort();
				}


			}
			else
			{
				deletefinal << bg.getid() << " " << bg.getonvan() << " " << bg.getbookpage() << " " << bg.gettedad()
					<< " " << bg.getmojodi() << " " << endl;
			}

		}
		if (!found){

			cout << " \n\n\t\t\t we cant found this majale whith this id!  this majale is not delete\n\t\t\t";

		}

		deletemajale.close();
		deletefinal.close();

		if (remove("majale.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("delmajale.txt", "majale.txt") != 0){
			cout << "error in renaming output file" << endl;
		}
		cout << "\n\n\t\t do yoy want to deldete another majale ? (y/n)\n\t\t";
		cin >> y;

	} while (y != 'n');


}
void searchmajale(){

	char g;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter your majale id that you want to delete this : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream searchmajale("majale.txt");
		if (!searchmajale)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		majaleinf b;
		bool found = false;

		system("cls");

		while (searchmajale >> b.id)
		{

			searchmajale >> b.onvan;
			searchmajale >> b.bookpage;
			searchmajale >> b.tedad;
			searchmajale >> b.mojodi;
			majale bs(b.id, b.onvan, b.bookpage, b.tedad, b.mojodi);
			if (searchid == b.id){
				found = true;


				cout << "\n\t\t\t " << "id    : " << bs.getid();
				cout << "\n\t\t\t " << "onvan : " << bs.getonvan();//b.onvan;
				cout << "\n\t\t\t " << "bookpage  : " << bs.getbookpage();//b.bookpage;
				cout << "\n\t\t\t " << "tedad: " << bs.gettedad();//b.tedad;
				cout << "\n\t\t\t " << "mojodi: " << bs.getmojodi();//b.mojodi;
			}
		}
		if (!found){

			cout << " \n\n\t\t\t Oops this majale with this id isnt found !\n";

		}

		searchmajale.close();

		cout << "\n\n\t\t do you want to search another majale ? (y/n)\n\t\t";
		cin >> g;

	} while (g != 'n');




}
void displaymajale(){

	system("cls");

label1:
	cout << "\n\t\t*********************************************************** \n";
	cout << "\t\t  ID\t     ONVAN\t        bookPAGE\t  tedad      MOJODI       \n";
	cout << "\t\t********************************************************\n\n\t\t";


	ifstream displaymajale("majale.txt");
	if (!displaymajale)
	{
		cout << "the file could not be opened!" << endl;
		abort();
	}
	majaleinf b;
	while (displaymajale >> b.id)
	{

		displaymajale >> b.onvan;
		displaymajale >> b.bookpage;
		displaymajale >> b.tedad;
		displaymajale >> b.mojodi;

		cout << "  " << setw(4) << b.id << "\t" << setw(6) << b.onvan << "\t\t" << setw(4) << b.bookpage << "\t    " <<
			setw(4) << b.tedad << "      " << setw(4) << b.mojodi << "\t\n\t\t";
	}
	char u;
	cout << "\n\n\t\t\t\t do you want countinue? (y/n)\n\t\t\t\t";
	cin >> u;
	if (u = 'n') goto label1;
	displaymajale.close();

}



//**************************thesis*********************************

void addthesis(){

	char q;
	do
	{


		system("cls");
		ifstream addthesis("thesis.txt");
		ofstream editthesis("thesisfinal.txt");
		if (!addthesis)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		payanname a;
		payanname b;
		bool found = false;

		cout << "\n\n\t\t please enter id thesis: ";
		cin >> a.id;
		while (addthesis >> b.id)
		{

			addthesis >> b.onvan;
			addthesis >> b.bookpage;
			addthesis >> b.maghta;
			addthesis >> b.daneshkade;
			addthesis >> b.gorup;
			addthesis >> b.mojodi;


			if (a.id == b.id){
				found = true;
				//int p = b.tedad + 1;
				//int m = b.mojodi + 1 ;


				cout << "\n\t\t this thesis isnt avelabe in our library !\n\n";
				editthesis << b.id << " " << b.onvan << " " << b.bookpage << " " << b.maghta << " " << b.daneshkade << " "
					<< b.gorup << " " << b.mojodi << " " << endl;

			}
			else{
				editthesis << b.id << " " << b.onvan << " " << b.bookpage << " " << b.maghta << " " << b.daneshkade << " "
					<< b.gorup << " " << b.mojodi << " " << endl;

			}

		}if (!found){

			cout << "\n\n\t\t please enter onvan of thesis: ";
			cin >> a.onvan;
			cout << "\n\n\t\t please enter bookpage of thesis : ";
			cin >> a.bookpage;
			cout << "\n\n\t\t please enter maghta of thesis: ";
			cin >> a.maghta;
			cout << "\n\n\t\t please enter daneshkade of thesis: ";
			cin >> a.daneshkade;
			cout << "\n\n\t\t please enter group of thesis: ";
			cin >> a.gorup;
			int mojo = 1;
			thesis mag(a.id, a.onvan, a.bookpage, a.maghta, a.daneshkade, a.gorup, mojo);

			editthesis << mag.getid() << " " << mag.getonvan() << " " << mag.getbookpage() << " " << mag.getmaghta() << " "
				<< mag.getdaneshkade() << " " << mag.getgroup() << " " << mag.getmojodi() << " " << endl;

			cout << "\n\t\t\t\t************************************************************************\n";
			cout << "\t\t\t\t                          payanname is add                                \n";
			cout << "\t\t\t\t**************************************************************************\n";

		}
		addthesis.close();
		editthesis.close();

		//remove("book.txt");
		//rename("bookfinal.txt", "book.txt");


		if (remove("thesis.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("thesisfinal.txt", "thesis.txt") != 0){
			cout << "error in renaming output file" << endl;
		}


		cout << "\n\t\t\t\t do you want to add another thesis ?(y/n) \n\t\t\t\t";

		cin >> q;

	} while (q != 'n');

	//int id, string onvan, int bookpage, string daste, int tedad, int mojodi




}
void modifythesis(){
	char q;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter thesis id for modify it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream editthesis("thesis.txt");
		ofstream editfinal("thesisfinal.txt");
		if (!editthesis)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		payanname b;
		bool found = false;

		system("cls");

		while (editthesis >> b.id)
		{

			editthesis >> b.onvan;
			editthesis >> b.bookpage;
			editthesis >> b.maghta;
			editthesis >> b.daneshkade;
			editthesis >> b.gorup;
			editthesis >> b.mojodi;
			if (searchid == b.id){
				char a;
				found = true;
				thesis bk(b.id, b.onvan, b.bookpage, b.maghta, b.daneshkade, b.gorup, b.mojodi);
				do
				{
					system("cls");
					cout << "\n\n\t\t\t wich one do you want to modify ? \n ";
					cout << "\t\t\t ******************************************************************** \n";
					cout << "\t\t\t*                                                                    *\n";
					cout << "\t\t\t*                            1  ONVAN                                *\n";
					cout << "\t\t\t*                            2  bookPAGE                             *\n";
					cout << "\t\t\t*                            3  maghta                               *\n";
					cout << "\t\t\t*                            4  daneshkade                           *\n";
					cout << "\t\t\t*                            5  group                                *\n";
					cout << "\t\t\t*                            5  mojodi                               *\n";
					cout << "\t\t\t*                                                                    *\n";
					cout << "\t\t\t**************************************************************\n\n\t\t\t";
					int choice;
					cin >> choice;
					switch (choice)
					{
					case 1: {
								bk.changeonvan();
								cout << "\n\t\t\t\t*****************************************************\n";
								cout << "\t\t\t\t                   onvan is change                     \n";
								cout << "\t\t\t\t*******************************************************\n";
								break; }
					case 2:{
							   bk.changebookpage();
							   cout << "\n\t\t\t\t*****************************************************\n";
							   cout << "\t\t\t\t                   bookpage is change                  \n";
							   cout << "\t\t\t\t*******************************************************\n";
							   break; }
					case 3:{
							   bk.changemaghta();
							   cout << "\n\t\t\t\t*****************************************************\n";
							   cout << "\t\t\t\t                   maghta is change                    \n";
							   cout << "\t\t\t\t*******************************************************\n";
							   break; }
					case 4: {
								bk.changedaneshkade();
								cout << "\n\t\t\t\t*****************************************************\n";
								cout << "\t\t\t\t                   daneshkade is change                \n";
								cout << "\t\t\t\t*******************************************************\n";
								break; }
					case 5:{
							   bk.changegroup();
							   cout << "\n\t\t\t\t*****************************************************\n";
							   cout << "\t\t\t\t                   group is change                     \n";
							   cout << "\t\t\t\t*******************************************************\n";
							   break; }
					case 6:{
							   bk.changemojodi();
							   cout << "\n\t\t\t\t*****************************************************\n";
							   cout << "\t\t\t\t                       mojodi is change                \n";
							   cout << "\t\t\t\t*******************************************************\n";
							   break; }
					default: cout << "\n\t\t\t Oops,ERROR!!\n"; break;
					}
					cout << "\n\t\t\t do you want to change another thing ? (y/n)\n\t\t\t";
					cin >> a;


				} while (a != 'n');

				editfinal << bk.getid() << " " << bk.getonvan() << " " << bk.getbookpage() << " "
					<< bk.getmaghta() << " " << bk.getdaneshkade() << " " << bk.getgroup() << " " << bk.getmojodi() << " " << endl;

			}
			else
			{
				editfinal << b.id << " " << b.onvan << " " << b.bookpage << " " << b.maghta << " " << b.daneshkade << " " << b.gorup << " " <<
					b.mojodi << " " << endl;
			}
		}

		//ifstream editbook("book.txt");
		//ofstream editfinal("editbook.txt");
		editthesis.close();
		editfinal.close();

		if (remove("thesis.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("thesisfinal.txt", "thesis.txt") != 0){
			cout << "error in renaming output file" << endl;
		}

		if (!found){

			cout << " \n\t\t\t THAT ID IS NOT FOUND! \n";

		}

		cout << "\n\t\t\t DO YOU WANT TO CONTINUE AND CHANGE ANOTHER THESIS (y/n) ?\n";
		cin >> q;

	} while (q != 'n');


}
void deletethesis(){
	char y;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter thesis id that you want delete it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream deletethesis("thesis.txt");
		ofstream deletefinal("delthesis.txt");
		if (!deletemajale)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		payanname b;
		bool found = false;

		system("cls");

		while (deletethesis >> b.id)
		{

			deletethesis >> b.onvan;
			deletethesis >> b.bookpage;
			deletethesis >> b.maghta;
			deletethesis >> b.daneshkade;
			deletethesis >> b.gorup;
			deletethesis >> b.mojodi;
			thesis bg(b.id, b.onvan, b.bookpage, b.maghta, b.daneshkade, b.gorup, b.mojodi);
			if (searchid == b.id){
				found = true;


				cout << "\n\t\t\t " << "id    : " << b.id;
				cout << "\n\t\t\t " << "onvan  : " << b.onvan;
				cout << "\n\t\t\t " << "bookpage   : " << b.bookpage;
				cout << "\n\t\t\t " << "maghta: " << b.maghta;
				cout << "\n\t\t\t " << "daneshkade: " << b.daneshkade;
				cout << "\n\t\t\t " << "group  : " << b.gorup;
				cout << "\n\t\t\t " << "mojodi : " << b.mojodi;

				cout << "\n\n\t\t are you sure for delete this thesis  ?(y/n)) \n\t\t";
				char r;
				cin >> r;
				if (r == 'y' || r == 'Y'){

					cout << "\n\t\t\t\t********************************************\n";
					cout << "\t\t\t\t*             thesis is deliting             *\n";
					cout << "\t\t\t\t**********************************************\n";

				}
				else if (r == 'n' || r == 'N')
				{
					deletefinal << bg.getid() << " " << bg.getonvan() << " " << bg.getbookpage() << " " << bg.getmaghta()
						<< " " << bg.getdaneshkade() << " " << bg.getgroup() << " " << bg.getmojodi() << " " << endl;
				}
				else
				{
					cout << "\n\n\n\t\t\t\tOops,ERROR! ";
					abort();
				}

			}
			else
			{
				deletefinal << bg.getid() << " " << bg.getonvan() << " " << bg.getbookpage() << " " << bg.getmaghta()
					<< " " << bg.getdaneshkade() << " " << bg.getgroup() << " " << bg.getmojodi() << " " << endl;
			}

		}
		if (!found){

			cout << " \n\n\t\t\t we cant found this thesis whith this id ! cant delete it \n";

		}

		deletethesis.close();
		deletefinal.close();

		if (remove("thesis.txt") != 0){
			cout << "error in deleting original file" << endl;
		}


		if (rename("delthesis.txt", "thesis.txt") != 0){
			cout << "error in renaming output file" << endl;
		}
		cout << "\n\n\t\t do you want to delete another thesis? (y/n)\n\t\t";
		cin >> y;

	} while (y != 'n');


}
void searchthesis(){

	char g;
	do
	{


		system("cls");
		cout << "\n\n\t\t please enter your thesis id that you want search it : \n\t\t";
		int searchid;
		cin >> searchid;

		ifstream searchthesis("thesis.txt");
		if (!searchthesis)
		{
			cout << "the file could not be opened!" << endl;
			abort();
		}
		payanname b;
		bool found = false;

		system("cls");

		while (searchthesis >> b.id)
		{
			searchthesis >> b.onvan;
			searchthesis >> b.bookpage;
			searchthesis >> b.maghta;
			searchthesis >> b.daneshkade;
			searchthesis >> b.gorup;
			searchthesis >> b.mojodi;
			thesis bs(b.id, b.onvan, b.bookpage, b.maghta, b.daneshkade, b.gorup, b.mojodi);
			if (searchid == b.id){
				found = true;


				cout << "\n\t\t\t " << "id     : " << bs.getid();//b.id;
				cout << "\n\t\t\t " << "onvan  : " << bs.getonvan();
				cout << "\n\t\t\t " << "bookpage   : " << bs.getbookpage();//b.bookpage;
				cout << "\n\t\t\t " << "maghta: " << bs.getmaghta();//b.maghta;
				cout << "\n\t\t\t " << "daneshkade: " << bs.getdaneshkade();//b.daneshkade;
				cout << "\n\t\t\t " << "groupe  : " << bs.getgroup();//b.gorup;
				cout << "\n\t\t\t " << "mojodi : " << bs.getmojodi();//b.mojodi;
			}
		}
		if (!found){

			cout << " \n\n\t\t\t THIS ID NOT FOUND !\n";

		}

		searchthesis.close();

		cout << "\n\n\t\t do you want to search another thesis ? (y/n)\n";
		cin >> g;

	} while (g != 'n');




}
void displaythesis(){

	system("cls");

part1:
	cout << "\t\t\t******************************************************************************** \n";
	cout << "\t\t*                                                                                 * \n";
	cout << "\t\t* ID\t     ONVAN\tbookPAGE\t       maghta       COLLAGE         GROUP    MOJODI   *\n";
	cout << "\t\t*                                                                                 * \n";
	cout << "\t\t********************************************************************************\n\n\t\t";


	ifstream displaythesis("thesis.txt");
	if (!displaythesis)
	{
		cout << "the file could not be opened!" << endl;
		abort();
	}
	payanname b;
	while (displaythesis >> b.id)
	{

		displaythesis >> b.onvan;
		displaythesis >> b.bookpage;
		displaythesis >> b.maghta;
		displaythesis >> b.daneshkade;
		displaythesis >> b.gorup;
		displaythesis >> b.mojodi;

		cout << " " << setw(3) << b.id << "\t" << setw(10) << b.onvan << "\t" << setw(4) << b.bookpage << "\t    " <<
			setw(10) << b.maghta << "      " << setw(8) << b.daneshkade << "      " << setw(8) << b.gorup << "      " << setw(4) << b.mojodi
			<< "\t\n\t\t";
	}
	char u;
	cout << "\n\n\t\t\t\t DO YOU WANT TO CONTINUE? (y/n)\n\t\t\t\t";
	cin >> u;
	if (u = 'n') goto part1;
	displaythesis.close();





}



//***************************ozv******************************




//***************************menu*****************************


int passozv(string id, int  pass){

	ifstream passozv("ozv.txt");
	if (!passozv)
	{
		cout << "the file could not be opened!" << endl;
		abort();
	}
	ozvinf a;
	bool found = false;
	while (passozv >> a.id)
	{

		passozv >> a.name;
		passozv >> a.family;
		passozv >> a.melliid;
		passozv >> a.day;
		passozv >> a.month;
		passozv >> a.year;
		passozv >> a.jarime;
		passozv >> a.noe;
		passozv >> a.stuid;
		passozv >> a.pass;
		string id1 = to_string(a.id);
		if (id1 == id){
			found = true;
			if (pass == a.pass){

				return 1;
			}
			else
			{
				return 0;
			}

		}

	}
	if (!found){

		cout << "\n\n\t\tit is not found!" << endl;
		//stop

	}
	passozv.close();



}
int passketabdar(string id, int pass){


	ifstream passketabdar(" ketabdar.txt");
	if (!passketabdar)
	{
		cout << "the file could not be opened!" << endl;
		abort();
	}
	ketabdarinf a;
	bool found = false;

	while (passketabdar >> a.id)
	{
		passketabdar >> a.melliid;
		passketabdar >> a.name;
		passketabdar >> a.family;
		passketabdar >> a.day;
		passketabdar >> a.month;
		passketabdar >> a.year;
		passketabdar >> a.madrak;
		passketabdar >> a.semat;
		passketabdar >> a.pass;
		string id1 = to_string(a.id);
		if (id1 == id){
			found = true;
			if (pass == a.pass){

				return 1;
			}
			else
			{
				return 0;
			}

		}

	}
	if (!found){

		cout << "\n\n\t\tit is not found!" << endl;
		//stop

	}
	passketabdar.close();




}
void menuozv(){

	int a;
	do {
		system("cls");

		cout << "\n\t\t\t\t  welcome to our system \n\n";
		cout << "\n\n\t\t\tPlease,  Choose from the following Options: \n\n";
		cout << "\t\t\t*********************************************\n\n\t\t\t";
		cout << "\t\t\t*                                                  *\n";
		cout << "\t\t\t*          1  sabte amanat                         *\n";
		cout << "\t\t\t*          2  search                               *\n";
		cout << "\t\t\t*          3  gozareshgiri                         *\n";
		cout << "\t\t\t*                                                  *\n";
		cout << "\t\t\t*********************************************\n\n\t\t\t";


		cin >> a;
		system("cls");
		switch (a)
		{
		case 1: break;
		case 2:
		case 3:break;
		}
	} while (a != 3);



}
void menu(){


	cout << "\n\n\t\t\tPlease,  Choose from the following Options:\n\n ";
	cout << "\t\t\t*************************************************** \n";
	cout << "\t\t\t*                                                  *\n";
	cout << "\t\t\t*          1  add                                  *\n";
	cout << "\t\t\t*          2  modify                               *\n";
	cout << "\t\t\t*          3  delete                               *\n";
	cout << "\t\t\t*          4  search                               *\n";
	cout << "\t\t\t*          5  display                              *\n";
	cout << "\t\t\t*          6  back to menu                         *\n";
	cout << "\t\t\t*                                                  *\n";
	cout << "\t\t\t*********************************************\n\n\t\t\t";

}

void menuketabdar(){

	int a, b;
	do {
	partx:
		system("cls");

		cout << "\n\t\t\t\t  LIBRARY SYSTEM \n\n";
		cout << "\n\n\t\t\tPlease, choose one type : \n\n";
		cout << "\t\t\t**************************************************** \n";
		cout << "\t\t\t*                                                   *\n";
		cout << "\t\t\t*                     1   BOOK                      *\n";
		cout << "\t\t\t*                     2   majale                    *\n";
		cout << "\t\t\t*                     3   THESIS                    *\n";
		cout << "\t\t\t*                     4   OZV                       *\n";
		cout << "\t\t\t*                     5   KETABDAR                  *\n";
		cout << "\t\t\t*                     6   AMANAT                    *\n";
		cout << "\t\t\t*                     7   EXIT                      *\n";
		cout << "\t\t\t*                                                   *\n";
		cout << "\t\t\t*********************************************\n\n\t\t\t";


		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
		part1 :
			menu();
			  cin >> b;
			  if (b == 1){ addbook(); }
			  else if (b == 2){ modifybook(); }//منو به شکل تابع
			  else if (b == 3){ deletebook(); }
			  else if (b == 4){ searchbook(); }
			  else if (b == 5){ displaybook(); }
			  else if (b == 6){ goto partx; }//برگشت به منو اصلی
			  break;
		case 2:
			menu();
			cin >> b;
			if (b == 1){ addmajale(); }
			else if (b == 2){ modifymajale(); }
			else if (b == 3){ deletemajale(); }
			else if (b == 4){ searchmajale(); }
			else if (b == 5){ displaymajale(); }
			else if (b == 6){ goto partx; }
			break;
		case 3:
			menu();
			cin >> b;
			if (b == 1){}
			else if (b == 2){}
			else if (b == 3){}
			else if (b == 4){}
			else if (b == 5){}
			else if (b == 6){ goto partx; }
			break;
		case 4:
			menu();
			cin >> b;
			if (b == 1){}
			else if (b == 2){}
			else if (b == 3){}
			else if (b == 4){}
			else if (b == 5){}
			else if (b == 6){ goto partx; }
			break;
		case 5:
			menu();
			cin >> b;
			if (b == 1){}
			else if (b == 2){}
			else if (b == 3){}
			else if (b == 4){}
			else if (b == 5){}
			else if (b == 6){ goto partx; }
			break;
		case 6:
			menu();
			cin >> b;
			if (b == 1){}
			else if (b == 2){}
			else if (b == 3){}
			else if (b == 4){}
			else if (b == 5){}
			else if (b == 6){ goto partx; }
			break;
		case 7:
			abort();
		}
	} while (a != 7);



}


int main()
{

	cout << "\t\t\t\t******************welcome dear user******************";
	cout << "\n\t\t \t\t*                       LOGIN                       * \n";
	cout << "\t\t\t\t*****************************************************\n\n";
	string id;
	int pass = 0;

	cout << "\t enter your id tedad : ";
	cin >> id;
	cout << "\t enter your password : ";
	cin >> pass;
	system("cls");
	char b = id[0];

	if (id[0] == '97'){//چون مساوی مساوی یک گذاشتم یعنی اگر کاربر من دانشجو بودخونه صفر ای دی با 1 شزوغ شود

		int fi = passozv(id, pass);
		if (fi == 0){//چون مساوی صفره پسورد اشتباه وارد شدهfi  

			cout << "your password is uncorrect " << endl;
			for (int i = 0; i < 3; i++){
				cout << "\t\t\tyou can try for " << 3 - i << " time again . enter your password: " << endl;
				cin >> pass;
				int fi = passozv(id, pass);
				if (fi == 1) goto parta;//show menu ozv
				else{ cout << "\n\t\tyour password is wrong\n"; }
			}
		}
		else if (fi == 1){

		parta:

			menuozv();
			//stop

		}


	}
	else if (id[0] == '90')
	{


		int fi = passketabdar(id, pass);
		if (fi == 0){

			cout << "\n\tyour password is uncorrect " << endl;
			for (int i = 0; i < 3; i++){
				cout << "\t\t\tyou can try for " << 3 - i << " time again . enter your password: " << endl;
				cin >> pass;
				int fi = passozv(id, pass);
				if (fi == 1) goto partb;

			}
		}
		else if (fi == 1){//درغیراینصورت

		partb:

			menuketabdar();
			//stop
		}
	}
	else
	{
		system("cls");
		cout << "\n\n\tyour id is not true ! " << endl;
		//stop
	}
	/*
	int a;
	do {
	system("cls");

	cout << "\n\t\t\t\t  UNIVERSITY MANAGEMENT SYSTEM \n\n";
	cout << "\n\n\t\t\tPlease,  Choose from the following Options: \n\n";
	cout << "\t\t\t *************************************************************** \n";
	cout << "\t\t\t                                           	                     \n";
	cout << "\t\t\t             1   REPORT MENU                                   \n";
	cout << "\t\t\t             2   ENTRY/EDIT MENU                               \n";
	cout << "\t\t\t             3   EXIT                                          \n";
	cout << "\t\t\t                                                                 \n";
	cout << "\t\t\t                                                                 \n";
	cout << "\t\t\t****************************************************************\n\n";


	cin >> a;
	system("cls");
	switch (a)
	{
	case 1: break;
	case 2:
	case 3:break;
	}
	} while (a != 3);
	*/

	_getch();
	return 0;
}
