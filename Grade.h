#pragma once
#include "Student.h";
 
typedef struct grade GRD;
struct grade
{
	int n_students;
	STD *students;
};
 
std::istream& operator >> (std::istream &, GRD *);
std::istream& operator >> (std::istream &, GRD &);
std::ostream& operator << (std::ostream &, GRD *);
std::ostream& operator << (std::ostream &, GRD &);