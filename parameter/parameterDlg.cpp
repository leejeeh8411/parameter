
// parameterDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "parameter.h"
#include "parameterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CparameterDlg 대화 상자



CparameterDlg::CparameterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PARAMETER_DIALOG, pParent)
	, m_nTest1(0)
	, m_dTest1(0)
	, m_strTest1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CparameterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INT1, m_nTest1);
	DDX_Text(pDX, IDC_EDIT_DOUBLE1, m_dTest1);
	DDX_Check(pDX, IDC_CHECK_BOOL1, m_bTest1);
	DDX_Text(pDX, IDC_EDIT_STRING1, m_strTest1);
}

BEGIN_MESSAGE_MAP(CparameterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SAVE_PARAMETER, &CparameterDlg::OnBnClickedButtonSaveParameter)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_PARAMETER, &CparameterDlg::OnBnClickedButtonLoadParameter)
END_MESSAGE_MAP()


// CparameterDlg 메시지 처리기

BOOL CparameterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	InitParameterMap();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CparameterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CparameterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CparameterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 변수 초기화
void CparameterDlg::InitParameterMap()
{
	Parameter.InsertParam("Int 1", 1);
	Parameter.InsertParam("Double 1", 2.2);
	Parameter.InsertParam("Bool 1", false);
	Parameter.InsertParam("String 1", CString(_T("abcd")));
}

// Parameter 저장
void CparameterDlg::OnBnClickedButtonSaveParameter()
{
	CString strPath;
	strPath.Format(_T("C:\\glim\\test.ini"));
	Parameter.SaveParameter(strPath);
	
	Parameter.SetParam("Int 1", 100);
	Parameter.SetParam("Double 1", 200.2);
	Parameter.SetParam("Bool 1", true);
	Parameter.SetParam("String 1", CString(_T("wxyz")));

	Parameter.GetParam("Int 1", m_nTest1);
	Parameter.GetParam("Double 1", m_dTest1);
	Parameter.GetParam("Bool 1", m_bTest1);
	Parameter.GetParam("String 1", m_strTest1);

	UpdateData(FALSE);
}

// Parameter 불러오기
void CparameterDlg::OnBnClickedButtonLoadParameter()
{
	CString strPath;
	strPath.Format(_T("C:\\glim\\test.ini"));
	Parameter.LoadParameter(strPath);
	
	Parameter.GetParam("Int 1", m_nTest1);
	Parameter.GetParam("Double 1", m_dTest1);
	Parameter.GetParam("Bool 1", m_bTest1);
	Parameter.GetParam("String 1", m_strTest1);

	UpdateData(FALSE);
}