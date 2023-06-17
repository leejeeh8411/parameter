#include "stdafx.h"
#include "gParameter.h"


gParameter::gParameter()
{
	InsertParam("white th", 30);
	InsertParam("dark th", 20);
	InsertParam("edge th", 12);

	vector<string> paramList = GetListParam();

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
