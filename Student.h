#pragma once
#include "Subject.h";
 
typedef struct student STD;
struct student
{
	std::string name;
	std::string code;
	int n_subjects;
	SJ *sjs;
};
 
std::istream& operator >> (std::istream &, STD *);
std::istream& operator >> (std::istream &, STD &);
std::ostream& operator << (std::ostream &, STD *);
std::ostream& operator << (std::ostream &, STD &);