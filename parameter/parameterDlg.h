
// parameterDlg.h : ��� ����
//

#pragma once

#include "gParameter.h"


// CparameterDlg ��ȭ ����
class CparameterDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CparameterDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	gParameter m_param;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARAMETER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
