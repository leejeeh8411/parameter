#pragma once

#include <map>
#include <vector>
#include <string>

using namespace std;

enum DataType
{
	TYPE_BOOLEAN = 0,
	TYPE_INT = 1,
	TYPE_DOUBLE = 2,
	TYPE_STRING = 3
};

static const int STRING_DATA_LENGTH = 50;

struct PARAM {
	int nDataType;
	bool bValue;
	int nValue;
	double dValue;
	char chValue[STRING_DATA_LENGTH];
	PARAM() {
		nDataType = 0;
		bValue = 0;
		nValue = 0;
		dValue = 0;
		memset(chValue, NULL, STRING_DATA_LENGTH);
	}
};


class gParameter
{
public:
	gParameter();
	~gParameter();

	pair<string, PARAM> MakeParam(CString _strKey, bool bVal);
	pair<string, PARAM> MakeParam(CString _strKey, int nVal);
	pair<string, PARAM> MakeParam(CString _strKey, float fVal);
	pair<string, PARAM> MakeParam(CString _strKey, double dVal);
	pair<string, PARAM> MakeParam(CString _strKey, CString strVal);

	pair<string, PARAM> GetParam(string strKey);
	bool				SetParam(pair<string, PARAM> data);

	vector<string>		GetListParam();


private:
	map<string, PARAM>	m_map;

};

