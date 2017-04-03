#include "Student.h";
 
std::istream& operator >> (std::istream &is, STD *s)
{
	std::cout << "\nNhap ho va ten: ";
	while (getchar() != '\n' && getchar() != EOF) {}
	std::getline(is, s->name);
	std::cout << "\nNhap ma so: ";
	is >> s->code;
	std::cout << "\nNhap so luong mon hoc: ";
	is >> s->n_subjects;
	std::cout << "\n\t---------- Nhap danh sach mon hoc ----------\t" << std::endl;
	s->sjs = new SJ[s->n_subjects];
	for (int i = 0; i < s->n_subjects; ++i)
	{
		std::cout << "\nNhap thong tin mon " << i + 1 << ":\n";
		is >> s->sjs[i];
	}
	return is;
}
std::istream& operator >> (std::istream &is, STD &s)
{
	std::cout << "\nNhap ho va ten: ";
	while (getchar() != '\n' && getchar() != EOF) {}
	std::getline(is, s.name);
	std::cout << "\nNhap ma so: ";
	is >> s.code;
	std::cout << "\nNhap so luong mon hoc: ";
	is >> s.n_subjects;
	std::cout << "\n\t---------- Nhap danh sach mon hoc ----------\t" << std::endl;
	s.sjs = new SJ[s.n_subjects];
	for (int i = 0; i < s.n_subjects; ++i)
	{
		std::cout << "\nNhap thong tin mon " << i + 1 << ":\n";
		is >> s.sjs[i];
	}
	return is;
}
std::ostream& operator << (std::ostream &os, STD *s)
{
	os << "\nHo va ten: " << s->name << std::endl;
	os << "\nMa so: " << s->code << std::endl;
	os << "\n\t---------- Danh sach mon hoc ----------\t\n";
	for (int i = 0; i < s->n_subjects; ++i)
	{
		os << "\nMon " << i + 1 << ":\n";
		os << s->sjs[i];
	}
	return os;
}
std::ostream& operator << (std::ostream &os, STD &s)
{
	os << "\nHo va ten: " << s.name << std::endl;
	os << "\nMa so: " << s.code << std::endl;
	os << "\n\t---------- Danh sach mon hoc ----------\t\n";
	for (int i = 0; i < s.n_subjects; ++i)
	{
		os << "\nMon " << i + 1 << ":\n";
		os << s.sjs[i];
	}
	return os;
}