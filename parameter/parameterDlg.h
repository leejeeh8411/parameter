
// parameterDlg.h : 헤더 파일
//

#pragma once

#include "gParameter.h"
#include "afxcmn.h"


// CparameterDlg 대화 상자
class CparameterDlg : public CDialogEx
{
// 생성입니다.
public:
	CparameterDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	gParameter m_param;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARAMETER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	void CparameterDlg::InitParamControl();

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	gParameter Parameter;
	int m_nTest1;
	double m_dTest1;
	BOOL m_bTest1;
	CString m_strTest1;
	void InitParameterMap();
	afx_msg void OnBnClickedButtonSaveParameter();
	afx_msg void OnBnClickedButtonLoadParameter();
	CListCtrl m_listParam;
	CString CparameterDlg::GetType();
	int m_nDataType;
	afx_msg void RadioCtrl(UINT ID);
	CString m_strKey;
	CString m_strValue;
	afx_msg void OnBnClickedButton1();
	void CparameterDlg::UpdateParam();
};
