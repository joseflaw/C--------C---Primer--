/*
 * =====================================================================================
 *
 *       Filename:  8_14.cpp
 *
 *    Description:  8_14 C++ Primer
 *
 *        Version:  1.0
 *        Created:  09/11/2012 11:14:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  astrol  (astrol ), astrotycoon@yahoo.cn 
 *   Organization:  astrol 
 *
 * =====================================================================================
 */
#include <iostream>
using std::cin;  using std::cout;
using std::endl; using std::cerr; using std::getline;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream; using std::ofstream;
#include "get.h"

int file_to_vector(const string &filename, vector<string> &svec);
void show_file_from_vector(const vector<string> &svec);

int main(int argc, const char *argv[])
{
	string filename;
	vector<string> svec;
	
	cout << "Enter filename: ";
	cin >> filename; 

	switch(file_to_vector(filename, svec))
	{
		case 1:
			cerr << "error: unable to open input file" 
			<< filename << endl;
			return -1;
		case 2:
			cout << "error: system failure" << endl;
			return -1;
		case 3:
			cout << "error: read failure" << endl;
			return -1; 
	}
	show_file_from_vector(svec);
	
	return 0;
}

int file_to_vector(const string &filename, vector<string> &svec)
{
	ifstream infile;
	if (!open_file(infile, filename))
		return 1;

	string s;
	while (getline(infile, s))
	{
		svec.push_back(s);
	}

	infile.close();
	if (infile.eof())
		return 4;
	if (infile.bad())
		return 2;
	if (infile.fail())
		return 3;
}

void show_file_from_vector(const vector<string> &svec)
{
	for (vector<string>::const_iterator iter = svec.begin();
			iter != svec.end(); ++iter)
	{
		cout << *iter << endl;
	}
}
