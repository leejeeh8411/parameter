#pragma once

#include <map>
#include <vector>
#include <typeinfo>

using namespace std;

enum DataType
{
	TYPE_BOOLEAN = 0,
	TYPE_INT = 1,
	TYPE_DOUBLE = 2
};

struct PARAM {
	int DataType;
	bool bValue;
	int nValue;
	double dValue;
};


class gParameter
{
public:
	gParameter();
	~gParameter();

	
	bool gParameter::InsertParam(string key, bool value);
	bool gParameter::InsertParam(string key, int value);
	bool gParameter::InsertParam(string key, double value);

	vector<string> gParameter::GetListParam();

	void gParameter::GetParam(string key, bool& value);
	void gParameter::GetParam(string key, int& value);
	void gParameter::GetParam(string key, double& value);

private:
	map<string, PARAM> m_map;
	bool gParameter::InsertParam(string key, PARAM value);
};

