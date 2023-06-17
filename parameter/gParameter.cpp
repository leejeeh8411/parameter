#include "stdafx.h"
#include "gParameter.h"


gParameter::gParameter()
{
	InsertParam("white th", 30);
	InsertParam("dark th", 20);
	InsertParam("edge th", 12);
	InsertParam("ratio w", 2.4);

	vector<string> paramList = GetListParam();


	int nWhiteTh = 0;
	int nDarkTh = 0;
	int nEdgeTh = 0;
	double dRatioW = 0;
	int nRatioW = 0;

	GetParam("white th", nWhiteTh);
	GetParam("dark th", nDarkTh);
	GetParam("edge th", nEdgeTh);
	GetParam("ratio w", dRatioW);
	GetParam("ratio w", nRatioW);


	int a = 10;
}


gParameter::~gParameter()
{
}

//map에 실제 넣는 부분
bool gParameter::InsertParam(string key, PARAM value)
{
	bool bRet = false;

	m_map.insert(pair<string, PARAM>(key, value));

	return bRet;
}

//map 넣기 전 변수타입에 따입별 함수
bool gParameter::InsertParam(string key, bool value)
{
	bool bRet = false;

	PARAM param;
	param.DataType = TYPE_BOOLEAN;
	param.bValue = value;

	bRet = InsertParam(key, param);

	return bRet;
}

//map 넣기 전 변수타입에 따입별 함수
bool gParameter::InsertParam(string key, int value)
{
	bool bRet = false;

	PARAM param;
	param.DataType = TYPE_INT;
	param.nValue = value;

	bRet = InsertParam(key, param);

	return bRet;
}

//map 넣기 전 변수타입에 따입별 함수
bool gParameter::InsertParam(string key, double value)
{
	bool bRet = false;

	PARAM param;
	param.DataType = TYPE_DOUBLE;
	param.dValue = value;

	bRet = InsertParam(key, param);

	return bRet;
}

//파라미터 리스트를 호출한다
vector<string> gParameter::GetListParam()
{
	int nSize = m_map.size();

	vector<string> vtParamList;

	for (const auto & pair : m_map) {
		string str = pair.first;
		vtParamList.emplace_back(str);
	}

	return vtParamList;
}


//
void gParameter::GetParam(string key, bool& value)
{
	bool ret = false;

	for (const auto & pair : m_map) {
		string str = pair.first;
		if (key == str) {
			PARAM v = pair.second;
			if (v.DataType == TYPE_BOOLEAN) {
				ret = (bool)v.bValue;
			}
			else if (v.DataType == TYPE_INT) {
				ret = (bool)v.nValue;
			}
			else if (v.DataType == TYPE_DOUBLE) {
				ret = (bool)v.dValue;
			}
			break;
		}
	}
	value = ret;
}
void gParameter::GetParam(string key, int& value)
{
	int ret = false;

	for (const auto & pair : m_map) {
		string str = pair.first;
		if (key == str) {
			PARAM v = pair.second;
			if (v.DataType == TYPE_BOOLEAN) {
				ret = (int)v.bValue;
			}
			else if (v.DataType == TYPE_INT) {
				ret = (int)v.nValue;
			}
			else if (v.DataType == TYPE_DOUBLE) {
				ret = (int)v.dValue;
			}
			break;
		}
	}
	value = ret;
}
void gParameter::GetParam(string key, double& value)
{
	double ret = false;

	for (const auto & pair : m_map) {
		string str = pair.first;
		if (key == str) {
			PARAM v = pair.second;
			if (v.DataType == TYPE_BOOLEAN) {
				ret = (double)v.bValue;
			}
			else if (v.DataType == TYPE_INT) {
				ret = (double)v.nValue;
			}
			else if (v.DataType == TYPE_DOUBLE) {
				ret = (double)v.dValue;
			}
			break;
		}
	}
	value = ret;
}