#include "Subject.h"
 
std::istream& operator >> (std::istream &is, SJ *s)
{
	std::cout << "Nhap ten mon hoc: ";
	while (getchar() != '\n' && getchar() != EOF) {}
	std::getline(is, s->subject_name);
	std::cout << "Nhap diem mon hoc: ";
	is >> s->mark;
	return is;
}
std::istream& operator >> (std::istream &is, SJ &s)
{
	std::cout << "Nhap ten mon hoc: ";
	while (getchar() != '\n' && getchar() != EOF) {}
	std::getline(is, s.subject_name);
	std::cout << "Nhap diem mon hoc: ";
	is >> s.mark;
	return is;
}
std::ostream& operator << (std::ostream &os, SJ *s)
{
	os << "Ten mon hoc: " << s->subject_name << std::endl;
	os << "Diem mon hoc: " << s->mark << std::endl;
	return os;
}
std::ostream& operator << (std::ostream &os, SJ &s)
{
	os << "Ten mon hoc: " << s.subject_name << std::endl;
	os << "Diem mon hoc: " << s.mark << std::endl;
	return os;
}