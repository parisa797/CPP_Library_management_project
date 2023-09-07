#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <iomanip>

using namespace std;

struct student
{
	string Fname;
	string Lname;
	string studentId;
	string enterYear;
	string nationalnum;
};
int InsertStudent();
int EditStudent();
string coding(string s);
int ShowStudent();
void bubblesort();
vector<student> s1;

student s;

int studentcounter = 0;

int main()
{
	ifstream countsave("counter.txt");
	countsave >> studentcounter;
	countsave.close();
	ifstream std("student.txt");
	if (studentcounter != 0)
	{
		for (int i = 0; i < studentcounter; i++)
		{
			std >> s.Fname;
			std >> s.Lname;
			std >> s.studentId;
			std >> s.enterYear;
			std >> s.nationalnum;
			s.Fname = coding(s.Fname);
			s.Lname = coding(s.Lname);
			s.studentId = coding(s.studentId);
			s.enterYear = coding(s.enterYear);
			s.nationalnum = coding(s.nationalnum);
			s1.push_back(s);

		}
	}
	std.close();
	int opt;
	cout << "1:management student" << endl;
	cout << "2:management professor" << endl;
	cout << "3:Lessons" << endl;
	cout << "4:Lesson in progress" << endl;
	cout << "5:Exit" << endl;
	cout << "please enter your option= " << endl;
	cin >> opt;
	while (opt != 5)
	{
		if (opt == 1)
		{
			cout << "1:Insert information" << endl;
			cout << "2:Edit information" << endl;
			cout << "3:Show student information" << endl;
			cout << "please enter your option= " << endl;
			cin >> opt;
			if (opt == 1)
			{
				InsertStudent();
			}
			else if (opt == 2)
			{
				EditStudent();
			}
			else if (opt == 3)
			{
				ShowStudent();
			}
		}
		cout << "1:management student" << endl;
		cout << "2:management professor" << endl;
		cout << "3:Lessons" << endl;
		cout << "4:Lesson in progress" << endl;
		cout << "5:Exit" << endl;
		cout << "please enter your option= " << endl;
		cin >> opt;
	}
	ofstream st("student.txt", ios::app);
	for (int i = 0; i < studentcounter; i++)
	{
		s1[i].Fname = coding(s1[i].Fname);
		s1[i].Lname = coding(s1[i].Lname);
		s1[i].studentId = coding(s1[i].studentId);
		s1[i].enterYear = coding(s1[i].enterYear);
		s1[i].nationalnum = coding(s1[i].nationalnum);
		st << s1[i].Fname << endl;
		st << s1[i].Lname << endl;
		st << s1[i].studentId << endl;
		st << s1[i].enterYear << endl;
		st << s1[i].nationalnum << endl;
	}
	st.close();
	ofstream counts("counter.txt");
	counts << studentcounter;
	counts.close();
}
int InsertStudent()
{

	bool num = false;
	bool found = false;
	string stId;
	string nationalnum;
	int size;
	student s;
	for (int i = studentcounter; i < 1000; i++)
	{
		cout << "Please introdouce the student(first name=end for finished): " << endl;
		cout << "First name: " << endl;
		cin >> s.Fname;
		if (s.Fname == "end")
		{
			return 0;
		}
		cout << "Last name: " << endl;
		cin >> s.Lname;
		do {
			cout << "Student Id: " << endl;
			cin >> stId;
			for (int counter = 0; counter < studentcounter; counter++)
			{
				found = false;
				if (s1[counter].studentId == stId)
				{
					cout << "Your Id is exited" << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				break;
			}

		} while (true);

		s.studentId = stId;
		cout << "Enter year of entring: " << endl;
		cin >> s.enterYear;
		do
		{
			cout << "National number: " << endl;
			cin >> nationalnum;
			size = nationalnum.size();
		} while (size != 10);
		s.nationalnum = nationalnum;
		s1.push_back(s);
		studentcounter++;
	}
}
int ShowStudent()
{
	student s;
	bubblesort();
	for (int i = 0; i < studentcounter; i++)
	{
		cout << "First name: " << s1[i].Fname << endl;
		cout << "Last name: " << s1[i].Lname << endl;
		cout << "Student Id: " << s1[i].studentId << endl;
		cout << "Entery year: " << s1[i].enterYear << endl;
		cout << "National number: " << s1[i].nationalnum << endl;
	}
	return 0;
}
int EditStudent()
{
	string Id;
	string nationalnum;
	int size;
	student s;
	bool found = false;
	cout << "Please enter student Id for editing= " << endl;
	cin >> Id;
	for (int i = 0; i < studentcounter; i++)
	{
		if (s1[i].studentId == Id)
		{
			cout << "First name: " << s1[i].Fname << endl;
			cout << "Last name: " << s1[i].Lname << endl;
			cout << "Student Id: " << s1[i].studentId << endl;
			cout << "Entery year: " << s1[i].enterYear << endl;
			cout << "National number: " << s1[i].nationalnum << endl;
			cout << "First name: " << endl;
			cin >> s1[i].Fname;
			cout << "Last name: " << endl;
			cin >> s1[i].Lname;
			cout << "Enter year of entring: " << endl;
			cin >> s1[i].enterYear;
			do
			{
				cout << "National number: " << endl;
				cin >> nationalnum;
				size = nationalnum.size();
			} while (size != 10);
			s1[i].nationalnum = nationalnum;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "This student is not found in this university!" << endl;
	}
	return 0;
}
string coding(string s)
{
	string Encrkey = "ABC";
	string scode;
	int kylen = Encrkey.length();
	for (int k = 0; k < s.length(); k++)
	{
		scode += s[k] ^ Encrkey[k%kylen];
	}
	return scode;
}
void bubblesort()
{
	for (int i = 0; i < studentcounter - 1; i++)
	{
		for (int j = 0; j < studentcounter - 1-i; j++)
		{
			if (s1[j].Lname > s1[j + 1].Lname)
			{
				student temp = s1[j];
				s1[j] = s1[j + 1];
				s1[j + 1] = temp;
			}
		}
	}
}

