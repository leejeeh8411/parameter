
// parameter.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CparameterApp:
// �� Ŭ������ ������ ���ؼ��� parameter.cpp�� �����Ͻʽÿ�.
//

class CparameterApp : public CWinApp
{
public:
	CparameterApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CparameterApp theApp;