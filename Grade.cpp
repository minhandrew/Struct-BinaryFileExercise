#include "Grade.h"
 
std::istream& operator >> (std::istream &is, GRD *g)
{
	std::cout << "Nhap so luong hoc sinh: ";
	is >> g->n_students;
	g->students = new STD[g->n_students];
	for (int i = 0; i < g->n_students; ++i)
	{
		std::cout << "\n\t------------ NHAP THONG TIN HOC SINH " << i + 1 << " ------------\t\n";
		is >> g->students[i];
	}
	return is;
}
std::istream& operator >> (std::istream &is, GRD &g)
{
	std::cout << "Nhap so luong hoc sinh: ";
	is >> g.n_students;
	g.students = new STD[g.n_students];
	for (int i = 0; i < g.n_students; ++i)
	{
		std::cout << "\n\t------------ NHAP THONG TIN HOC SINH " << i + 1 << " ------------\t\n";
		is >> g.students[i];
	}
	return is;
}
std::ostream& operator << (std::ostream &os, GRD *g)
{
	for (int i = 0; i < g->n_students; ++i)
	{
		os << "\n\t------------ THONG TIN HOC SINH " << i + 1 << " ------------\t\n";
		os << g->students[i];
	}
	return os;
}
std::ostream& operator << (std::ostream &os, GRD &g)
{
	for (int i = 0; i < g.n_students; ++i)
	{
		os << "\n\t------------ THONG TIN HOC SINH " << i + 1 << " ------------\t\n";
		os << g.students[i];
	}
	return os;
}