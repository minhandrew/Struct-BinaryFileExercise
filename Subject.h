#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
 
typedef struct subject SJ;
struct subject
{
	std::string subject_name;
	double mark;
};
 
std::istream& operator >> (std::istream &, SJ *);
std::istream& operator >> (std::istream &, SJ &);
std::ostream& operator << (std::ostream &, SJ *);
std::ostream& operator << (std::ostream &, SJ &);