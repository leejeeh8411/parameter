#pragma once

#include <map>
#include <vector>
#include <typeinfo>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

enum DataType
{
	TYPE_BOOLEAN = 0,
	TYPE_INT = 1,
	TYPE_DOUBLE = 2,
	TYPE_STRING = 3
};

struct PARAM {
	int nDataType;
	bool bValue;
	int nValue;
	double dValue;
	CString strValue;
	PARAM() {
		nDataType = 0;
		bValue = 0;
		nValue = 0;
		dValue = 0;
		strValue = _T("");
	}
};


class gParameter
{
public:
	gParameter();
	~gParameter();


	bool gParameter::InsertParam(string strKey, bool bValue);
	bool gParameter::InsertParam(string strKey, int nValue);
	bool gParameter::InsertParam(string strKey, double dValue);
	bool gParameter::InsertParam(string strKey, CString strValue);

	vector<string> gParameter::GetListParam();

	void gParameter::GetParam(string strKey, bool& bValue);
	void gParameter::GetParam(string strKey, int& nValue);
	void gParameter::GetParam(string strKey, double& dValue);
	void gParameter::GetParam(string strKey, CString& strValue);

	bool LoadParameter(CString strPath);
	bool SaveParameter(CString strPath);

	bool SetParam(string strKey, bool bValue);
	bool SetParam(string strKey, int nValue);
	bool SetParam(string strKey, double dValue);
	bool SetParam(string strKey, CString strValue);
private:
	map<string, PARAM> m_map;
	bool gParameter::InsertParam(string key, PARAM value);
};

