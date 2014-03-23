#pragma once
#include <string>
#include "../Utility/CommonSet.h"

using namespace std;

class Country {
public:
	Country();
	~Country();

	int get_id();
	Country set_id(int id);

	int get_emperor();
	Country set_emperor(int emperor);

	string get_name();
	Country set_name(const string& name);

	CommonSet<int> get_citys();
	Country set_citys(const CommonSet<int>& citys);

	int add_city(int city);
	int add_citys(const CommonSet<int>& citys);

	int remove_city(int city);
	int remove_citys(const CommonSet<int>& citys);

private:
	int id;
	string name;
	int emperor;
	CommonSet<int> citys;
};