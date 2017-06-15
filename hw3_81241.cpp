#include<iostream>

using namespace std;

class Student
{
public:
	Student();

	Student(const char* , const char* , const char* );
	
	Student(const Student&);

	Student& operator=(const Student& other)
	{
		if (this == &other)
			return *this;

		delete[] this->name;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);

		if (this == &other)
			return *this;

		delete[] this->fac;
		this->fac = new char[strlen(other.fac) + 1];
		strcpy_s(this->fac, strlen(other.fac) + 1,other.fac);

		strcpy_s(this->facnumb, other.facnumb);

		return *this;
	}

	void setName(const char* name)
	{
		if (this->name != NULL)
		{
			delete[] this->name;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	char* getName()
	{
		return this->name;
	}

	void setFac(const char* fac)
	{
		if (this->fac != NULL)
		{
			delete[] this->fac;
		}
		this->fac = new char[strlen(fac) + 1];
		strcpy_s(this->fac, strlen(fac) + 1,fac);
	}

	char* getFac()
	{
		return this->fac;
	}

	void setfacnumb(const char* facnumb)
	{
		strcpy_s(this->facnumb,strlen(facnumb)+1, facnumb);
	}

	char* getfacnumb()
	{
		return this->facnumb;
	}

	void print() const
	{
		cout << this->name << "-" << this->facnumb <<"-"<<this->fac<< endl;
	}

	~Student()
	{
		delete[] this->name;
		delete[] this->fac;
	}
private:
	char facnumb[6];
	char *name;
	char* fac;
	
};

Student::Student()
{
	this->name = new char[1];
	strcpy_s(this->name,1, "\0");

	this->fac = new char[1];
	strcpy_s(this->fac,1, "\0");

	strcpy_s(this->facnumb,6, "00000");
}

Student::Student(const char* name, const char* facnumb, const char* fac)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->fac = new char[strlen(fac) + 1];
	strcpy_s(this->fac, strlen(fac) + 1, fac);

	strcpy_s(this->facnumb,6, facnumb);
}

Student::Student(const Student& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(name) + 1, other.name);

	this->fac = new char[strlen(other.fac) + 1];
	strcpy_s(this->name, strlen(other.fac)+1, other.fac);

	strcpy_s(this->facnumb,6, other.facnumb);
}

class ForeignStudent : public Student
{
public:
	ForeignStudent();

	ForeignStudent(const char*, unsigned int);

	ForeignStudent(const ForeignStudent&);

	ForeignStudent& operator=(const ForeignStudent& other)
	{
		if (this == &other)
			return *this;

		delete[] this->nat;
		this->nat = new char[strlen(other.nat) + 1];
		strcpy_s(this->nat, strlen(other.nat) + 1, other.nat);

		this->tt= other.tt;

		return *this;
	}

	void setName(const char* nat)
	{
		if (this->nat != NULL)
		{
			delete[] this->nat;
		}
		this->nat = new char[strlen(nat) + 1];
		strcpy_s(this->nat, strlen(nat) + 1, nat);
	}

	char* getNat()
	{
		return this->nat;
	}

	void setTT(unsigned int tt)
	{
		this->tt= tt;
	}

	unsigned int getTT()
	{
		return this->tt;
	}

	void printForeignStudent() const
	{
		Student::print();
		cout << this->nat << "-" << this->tt << endl;
	}

	~ForeignStudent()
	{
		delete[] this->nat;
	}

private:
	char* nat;
	unsigned int tt;
};
	
ForeignStudent::ForeignStudent() :Student()
{
	this->nat = new char[1];
	strcpy_s(this->nat,1, "\0");
	tt = 0;
}

ForeignStudent::ForeignStudent(const char* name, const char* facnumb, const char* fac,const char* nat, unsigned int tt) :Student(name, facnumb, fac)
{
	this->nat = new char[strlen(nat) + 1];
	strcpy_s(this->nat, strlen(nat) + 1, nat);

	this->tt = tt;
}

ForeignStudent::ForeignStudent(const ForeignStudent& other) :Student(other)
{
	this->nat = new char[strlen(other.nat) + 1];
	strcpy_s(this->nat, strlen(other.nat) + 1, nat);

	this->tt = other.tt;
}
	int main()
	{
		ForeignStudent a("srb", 375);
		a.printForeignStudent();

		Student *s = &a;
		s->print();

	system("pause");
	return 0;
}