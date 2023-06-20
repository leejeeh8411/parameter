#include "stdafx.h"
#include "gParameter.h"


gParameter::gParameter()
{
	//InsertParam("white th", 30);
	//InsertParam("dark th", 20);
	//InsertParam("edge th", 12);
	//InsertParam("ratio w", 2.4);

	//vector<string> paramList = GetListParam();


	//int nWhiteTh = 0;
	//int nDarkTh = 0;
	//int nEdgeTh = 0;
	//double dRatioW = 0;
	//int nRatioW = 0;

	//GetParam("white th", nWhiteTh);
	//GetParam("dark th", nDarkTh);
	//GetParam("edge th", nEdgeTh);
	//GetParam("ratio w", dRatioW);
	//GetParam("ratio w", nRatioW);


	//int a = 10;
}


gParameter::~gParameter()
{
}

//map에 실제 넣는 함수
bool gParameter::InsertParam(string strKey, PARAM stParam)
{
	m_map.insert(pair<string, PARAM>(strKey, stParam));
	return true;
}

bool gParameter::InsertParam(string strKey, bool bValue)
{
	bool bRet = false;
	PARAM stParam;

	stParam.nDataType = TYPE_BOOLEAN;
	stParam.bValue = bValue;
	bRet = InsertParam(strKey, stParam);

	return bRet;
}

bool gParameter::InsertParam(string strKey, int nValue)
{
	bool bRet = false;
	PARAM stParam;

	stParam.nDataType = TYPE_INT;
	stParam.nValue = nValue;
	bRet = InsertParam(strKey, stParam);

	return bRet;
}

bool gParameter::InsertParam(string strKey, double dValue)
{
	bool bRet = false;
	PARAM stParam;

	stParam.nDataType = TYPE_DOUBLE;
	stParam.dValue = dValue;
	bRet = InsertParam(strKey, stParam);

	return bRet;
}

bool gParameter::InsertParam(string strKey, CString strValue)
{
	bool bRet = false;
	PARAM stParam;

	stParam.nDataType = TYPE_STRING;
	stParam.strValue = strValue;
	bRet = InsertParam(strKey, stParam);
	
	return bRet;
}


//파라미터 리스트를 호출
vector<string> gParameter::GetListParam()
{
	int nSize = m_map.size();
	vector<string> vtParamList;

	for (const auto& pair : m_map)
	{
		string str = pair.first;
		vtParamList.emplace_back(str);
	}

	return vtParamList;
}


// strKey에 들어 있는 값을 bValue에 복사
void gParameter::GetParam(string strKey, bool& bValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			if (stParam.nDataType == TYPE_BOOLEAN)
				bValue = (bool)stParam.bValue;
			else if (stParam.nDataType == TYPE_INT)
				bValue = (bool)stParam.nValue;
			else if (stParam.nDataType == TYPE_DOUBLE)
				bValue = (bool)stParam.dValue;
			break;
		}
	}
}

// strKey에 들어 있는 값을 nValue에 복사
void gParameter::GetParam(string strKey, int& nValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			if (stParam.nDataType == TYPE_BOOLEAN)
				nValue = (int)stParam.bValue;
			else if (stParam.nDataType == TYPE_INT)
				nValue = (int)stParam.nValue;
			else if (stParam.nDataType == TYPE_DOUBLE)
				nValue = (int)stParam.dValue;
			break;
		}
	}
}

// strKey에 들어 있는 값을 dValue에 복사
void gParameter::GetParam(string strKey, double& dValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			if (stParam.nDataType == TYPE_BOOLEAN)
				dValue = (double)stParam.bValue;
			else if (stParam.nDataType == TYPE_INT)
				dValue = (double)stParam.nValue;
			else if (stParam.nDataType == TYPE_DOUBLE)
				dValue = (double)stParam.dValue;
			break;
		}
	}
}

// strKey에 들어 있는 값을 strValue에 복사
void gParameter::GetParam(string strKey, CString& strValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			if (stParam.nDataType == TYPE_STRING)
				strValue = stParam.strValue;
			break;
		}
	}
}

// Parameter 정보가 저장되어 있는 경로를 입력받아 정보를 읽음
bool gParameter::LoadParameter(CString strPath)
{
	string line;
	ifstream file(strPath);
	string strValue;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			int nLen = line.find((":"), 0);
			string strKey = line.substr(0, nLen);
			strValue = line.substr(nLen + 1, nLen);
			for (const auto& pair : m_map)
			{
				string str = pair.first;
				if (strKey == str)
				{
					PARAM stParam = pair.second;
					if (stParam.nDataType == TYPE_BOOLEAN)
					{
						bool bFlag;
						istringstream iss(strValue);
						iss >> boolalpha >> bFlag;
						SetParam(strKey, bFlag);
					}
					else if (stParam.nDataType == TYPE_INT)
						SetParam(strKey, stoi(strValue));
					else if (stParam.nDataType == TYPE_DOUBLE)
					{
						double dTemp = stof(strValue);
						dTemp = round(dTemp * 1000) / 1000.;
						SetParam(strKey, dTemp);
					}
					else if (stParam.nDataType == TYPE_STRING)
						SetParam(strKey, CString(strValue.c_str()));
					break;
				}
			}
		}
		file.close();
	}
	else
		return false;
	return true;
}

// Parameter 정보를 입력받은 경로에 저장
bool gParameter::SaveParameter(CString strPath)
{
	CStdioFile file;
	if (!file.Open(strPath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
	{
		AfxMessageBox(_T("INI 파일을 생성할 수 없습니다."));
		return false;
	}

	// INI 파일 데이터 입력
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		PARAM stParam = pair.second;
		CString strTemp;
		if (stParam.nDataType == TYPE_BOOLEAN)
			strTemp.Format(_T("%s:%s\n"), str.c_str(), stParam.bValue ? _T("true") : _T("false"));
		else if (stParam.nDataType == TYPE_INT)
			strTemp.Format(_T("%s:%d\n"), str.c_str(), stParam.nValue);
		else if (stParam.nDataType == TYPE_DOUBLE)
			strTemp.Format(_T("%s:%.3f\n"), str.c_str(), stParam.dValue);
		else if (stParam.nDataType == TYPE_STRING)
			strTemp.Format(_T("%s:%s\n"), str.c_str(), stParam.strValue);
		file.WriteString(strTemp);
	}
	file.Close();
	return true;
}

// strKey에 해당하는 값을 bValue로 Update
bool gParameter::SetParam(string strKey, bool bValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			stParam.bValue = bValue;
			m_map[strKey] = stParam;
			return true;
		}
	}
	return false;
}

// strKey에 해당하는 값을 nValue로 Update
bool gParameter::SetParam(string strKey, int nValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			stParam.nValue = nValue;
			m_map[strKey] = stParam;
			return true;
		}
	}
	return false;
}

// strKey에 해당하는 값을 dValue로 Update
bool gParameter::SetParam(string strKey, double dValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			stParam.dValue = dValue;
			m_map[strKey] = stParam;
			return true;
		}
	}
	return false;
}

// strKey에 해당하는 값을 strValue로 Update
bool gParameter::SetParam(string strKey, CString strValue)
{
	for (const auto& pair : m_map)
	{
		string str = pair.first;
		if (strKey == str)
		{
			PARAM stParam = pair.second;
			stParam.strValue = strValue;
			m_map[strKey] = stParam;
			return true;
		}
	}
	return false;
}