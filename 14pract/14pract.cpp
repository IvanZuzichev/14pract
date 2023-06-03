#include <string>

#include <windows.h>

#include <iostream>

#include <memory>

#include <cctype>
using namespace std;
class PersonException
{
public:
	PersonException(string text) : txt(text) {}
	string getMessage() const { return txt; }

private:
	string txt;
};
class Person
{
public:
	Person(string name, int age, int id)
	{
		if (!age || age > 110 || age < 0)
		{
			throw PersonException{ "InvitedAge" };
		}
		if (!id || id < 0)
		{
			throw PersonException{ "InvitedId" };
		}
		if (name == "")
		{
			throw PersonException{ "InvitedString" };
		}

		this->name = name;
		this->age = age;
		this->id = id;
		show();
	}
	void show() const
	{
		cout << "Name " << name << "\tAge " << age << "\tId " << id << endl;
	}
private:
	string name;
	int age;
	int id;
};

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RU");
		int age;
		int id;
		string name;
	try
	{
		cout << "Введите имя: " << endl;
		cin >> name;
		cout << "Введите возраст: " << endl;
		cin >> age;
		cout << "Введите id: " << endl;
		cin >> id;

		unique_ptr<Person> peopl(new Person(name, age, id));
	}
	catch (const PersonException& ex)
	{
		cout << ex.getMessage() << endl;
	}
}

