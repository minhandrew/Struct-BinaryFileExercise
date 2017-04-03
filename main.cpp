/*
Bài tập: Nhập vào danh sách các sinh viên trong 1 lớp học biết thông tin mỗi sinh viên gồm có: họ tên, mã số, điểm thi các môn tự chọn. Yêu cầu: Ghi danh sách lớp học này xuống file nhị phân theo thứ tự bảng chữ cái Alphabet.
Đọc danh sách lớp học từ file nhị phân đã được tạo ra ở bài tập 1, yêu cầu: 
+ Sắp xếp danh sách lớp tăng/giảm dần theo điểm trung bình.
+ Tìm thông tin sinh viên có điểm trung bình cao nhất/thấp nhất rồi in lên màn hình.
+ Làm thêm tính năng thêm/xóa/cập nhật thông tin học sinh, sau đó lưu lại vào file.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Grade.h";
 
void WriteFile(std::fstream &, GRD *); // đọc thông tin từ struct vào file nhị phân
void SortList(GRD *); // sắp xếp danh sách lớp học theo thứ tự Alphabet
std::string CutStrName(std::string); // lấy ra tên chính trong 1 tên
void ReadFile(std::fstream &, GRD *); // đọc thông tin từ file nhị phân vào biến struct
bool Bigger(double , double ); // con trỏ hàm
bool Smaller(double , double ); // con trỏ hàm
double AverageMark(GRD *, int ); // trả về điểm trung bình của 1 học sinh có chỉ số là tham số index của hàm
void SortList_AverageMark(GRD *, bool(*)(double, double)); // sắp xếp danh sách lớp tăng/giảm theo điểm trung bình
int PrntInf_BestAvrgMark(GRD *g, bool(*)(double, double)); // xuất thông tin của học sinh có điểm trung bình cao/thấp nhất
 
void WriteFile(std::fstream &FileOut, GRD *g)
{
	std::cin.ignore();
	FileOut.write((char *)g, sizeof(GRD));
}
 
std::string CutStrName(std::string str) // This function gets the last name of a name
{
	int length = str.length();
	std::string string;
	for (int i = length - 1; i >= 0; --i)
	{
		if (str.at(i) != ' ')
			string.push_back(str.at(i));
		else
			break;
	}
	std::reverse(std::begin(string), std::end(string));
	return string;
}
 
void SortList(GRD *g)
{
	for (int i = 0; i < g->n_students - 1; ++i)
	{
		for (int j = i + 1; j < g->n_students; ++j)
		{
			if (CutStrName(g->students[i].name) > CutStrName(g->students[j].name))
				std::swap(g->students[i], g->students[j]);
		}
	}
}
 
void ReadFile(std::fstream &FileIn, GRD *_g)
{
	FileIn.read((char *)_g, sizeof(GRD));
}
 
bool Bigger(double a, double b)
{
	return a > b;
}
 
bool Smaller(double a, double b)
{
	return a < b;
}
 
double AverageMark(GRD *g, int index)
{
	double sum = 0;
	double count = 0;
	for (int i = 0; i < g->students[index].n_subjects; ++i)
	{
		sum += g->students[index].sjs[i].mark;
		++count;
	}
	return sum / count;
}
 
void SortList_AverageMark(GRD *g, bool(*ptr)(double, double))
{
	for (int i = 0; i < g->n_students - 1; ++i)
	{
		for (int j = i + 1; j < g->n_students; ++j)
		{
			if (ptr(AverageMark(g, i), AverageMark(g, j)))
				std::swap(g->students[i], g->students[j]);
		}
	}
}
 
int PrntInf_BestAvrgMark(GRD *g, bool(*ptr)(double, double))
{
	double MaxMin = g->students[0].sjs[0].mark;
	int index = 0;
	for (int i = 0; i < g->n_students; ++i)
	{
		if (ptr(AverageMark(g, i), MaxMin))
			index = i;
	}
	return index;
}
 
int main()
{
	GRD *g = new GRD;
 
	std::cin >> g;
	//std::cout << g;
 
	SortList(g);
	std::fstream FileOut("DanhSachLopHoc.doc", std::ios_base::out | std::ios_base::binary);
	WriteFile(FileOut, g);
	FileOut.close();
 
	GRD *_g = new GRD;
	FileOut.open("DanhSachLopHoc.doc", std::ios::in | std::ios::binary);
	ReadFile(FileOut, _g);
	FileOut.close();
	std::cout << _g;
 
	std::cout << "\n\t DANH SACH LOP HOC SAU KHI SAP XEP THEO YEU CAU \t\n";
	SortList_AverageMark(_g, Smaller);
	std::cout << _g;
 
	std::cout << "\n\t THONG TIN SINH VIEN CO DTB THEO YEU CAU \t\n";
	std::cout << _g->students[PrntInf_BestAvrgMark(g, Bigger)] << std::endl;
 
	delete[] _g->students->sjs;
	delete[] _g->students;
	delete _g;
	/*delete[] g->students->sjs;
	delete[] g->students;
	delete g;*/
	system("pause");
	return 0;
}