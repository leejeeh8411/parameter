#include "stdafx.h"
#include "gParameter.h"


gParameter::gParameter()
{
}


gParameter::~gParameter()
{
}



//파라미터 리스트를 호출
vector<string> gParameter::GetListParam()
{
	int nSize = static_cast<int>(m_map.size());
	vector<string> vtParamList;

	for (const auto& pair : m_map)
	{
		string str = pair.first;
		vtParamList.emplace_back(str);
	}

	return vtParamList;
}


pair<string, PARAM> gParameter::MakeParam(CString _strKey, bool bVal)
{

	pair<string, PARAM> pair_param;
	PARAM stParam;
	stParam.nDataType = TYPE_BOOLEAN;
	stParam.bValue = bVal;

	string strKey = _strKey;

	pair_param.first = strKey;
	pair_param.second = stParam;

	return pair_param;
}

pair<string, PARAM> gParameter::MakeParam(CString _strKey, int nVal)
{
	pair<string, PARAM> pair_param;
	PARAM stParam;
	stParam.nDataType = TYPE_INT;
	stParam.nValue = nVal;

	string strKey = _strKey;
	
	pair_param.first = strKey;
	pair_param.second = stParam;

	return pair_param;
}

pair<string, PARAM> gParameter::MakeParam(CString _strKey, float fVal)
{
	pair<string, PARAM> pair_param;
	PARAM stParam;
	stParam.nDataType = TYPE_DOUBLE;
	stParam.dValue = fVal;

	string strKey = _strKey;

	pair_param.first = strKey;
	pair_param.second = stParam;


	return pair_param;
}



pair<string, PARAM> gParameter::MakeParam(CString _strKey, double dVal)
{
	pair<string, PARAM> pair_param;
	PARAM stParam;
	stParam.nDataType = TYPE_DOUBLE;
	stParam.dValue = dVal;

	string strKey = _strKey;

	pair_param.first = strKey;
	pair_param.second = stParam;


	return pair_param;
}

pair<string, PARAM> gParameter::MakeParam(CString _strKey, CString strVal)
{
	pair<string, PARAM> pair_param;
	PARAM stParam;
	stParam.nDataType = TYPE_STRING;

	strncpy_s(stParam.chValue, strVal, STRING_DATA_LENGTH);

	string strKey = _strKey;

	pair_param.first = strKey;
	pair_param.second = stParam;


	return pair_param;
}

pair<string, PARAM> gParameter::GetParam(string strKey)
{
	pair<string, PARAM> pair_param;

	for (const auto& pair : m_map) {
		string str = pair.first;
		if (strKey == str) {
			pair_param = pair;
			break;
		}
	}

	return pair_param;
}


//map에 실제 넣는 함수
bool gParameter::SetParam(pair<string, PARAM> data)
{
	bool bRet = false;

	for (const auto& pair : m_map) {
		string strMapKey = pair.first;
		//기존에 있다면 set
		if (data.first == strMapKey) {
			PARAM stParam = pair.second;
			stParam = data.second;
			m_map[strMapKey] = stParam;
			bRet = true;
			break;
		}
	}

	//기존에 없다면 insert
	if (bRet == false) {
		m_map.insert(pair<string, PARAM>(data.first, data.second));
	}

	return true;
}


