
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
	, m_nDataType(0)
	, m_strKey(_T(""))
	, m_strValue(_T(""))
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
	DDX_Control(pDX, IDC_LIST1, m_listParam);
	DDX_Radio(pDX, IDC_RADIO1, m_nDataType);
	DDX_Text(pDX, IDC_EDIT1, m_strKey);
	DDX_Text(pDX, IDC_EDIT2, m_strValue);
}

BEGIN_MESSAGE_MAP(CparameterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SAVE_PARAMETER, &CparameterDlg::OnBnClickedButtonSaveParameter)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_PARAMETER, &CparameterDlg::OnBnClickedButtonLoadParameter)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO4, RadioCtrl)
	ON_BN_CLICKED(IDC_BUTTON1, &CparameterDlg::OnBnClickedButton1)
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
	InitParamControl();
	CreateParam();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CparameterDlg::RadioCtrl(UINT radio_no)
{
	UpdateData(TRUE);

	switch (radio_no)
	{
	case 0:
		m_nDataType = 0;
		break;
	case 1:
		m_nDataType = 1;
		break;
	case 2:
		m_nDataType = 2;
		break;
	case 3:
		m_nDataType = 3;
		break;
	default:
		break;
	}

	UpdateData(FALSE);
}

//파라미터 형태를 초기화 한다.
void CparameterDlg::CreateParam()
{
	//파라미터 경로 설정
	m_param.SetParameterPath("D:\\para.ini");

	//그룹 설정
	CString strGroup[2];
	strGroup[0].Format("Input");
	strGroup[1].Format("Output");

	//파라미터 초기화
	//일단 이 작업을 프로그램 내에서 해줘야 ini 생성 및 로드가 가능함
	bool inb = true;
	pair<string, PARAM> makedParamIn1 = m_param.MakeParam(strGroup[0], "input_bool", inb);
	m_param.SetParam(makedParamIn1);
	int inn = 34;
	pair<string, PARAM> makedParamIn2 = m_param.MakeParam(strGroup[0], "input_int", inn);
	m_param.SetParam(makedParamIn2);
	float inf = 2.4;
	pair<string, PARAM> makedParamIn3 = m_param.MakeParam(strGroup[0], "input_float", inf);
	m_param.SetParam(makedParamIn3);
	double ind = 3.56;
	pair<string, PARAM> makedParamIn4 = m_param.MakeParam(strGroup[0], "input_double", ind);
	m_param.SetParam(makedParamIn4);
	CString instr = "abcdefg";
	pair<string, PARAM> makedParamIn5 = m_param.MakeParam(strGroup[0], "input_string", instr);
	m_param.SetParam(makedParamIn5);

	bool ob = true;
	pair<string, PARAM> makedParamOut1 = m_param.MakeParam(strGroup[1], "output_bool", ob);
	m_param.SetParam(makedParamOut1);
	int on = 34;
	pair<string, PARAM> makedParamOut2 = m_param.MakeParam(strGroup[1], "output_int", on);
	m_param.SetParam(makedParamOut2);
	float of = 2.4;
	pair<string, PARAM> makedParamOut3 = m_param.MakeParam(strGroup[1], "output_float", of);
	m_param.SetParam(makedParamOut3);
	double od = 3.56;
	pair<string, PARAM> makedParamOut4 = m_param.MakeParam(strGroup[1], "output_double", od);
	m_param.SetParam(makedParamOut4);
	CString ostr = "abcdefg";
	pair<string, PARAM> makedParamOut5 = m_param.MakeParam(strGroup[1], "output_string", ostr);
	m_param.SetParam(makedParamOut5);

	string param_path = m_param.GetParameterPath();
	CFileFind fileFind;
	BOOL bExist = fileFind.FindFile(param_path.c_str());

	if (bExist == true) {
		m_param.LoadParam();
	}
	
	m_param.SaveParam();
	
}

void CparameterDlg::InitParamControl()
{
	m_listParam.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_listParam.InsertColumn(
		0,              // Rank/order of item
		"ID",          // Caption for this header
		LVCFMT_LEFT,    // Relative position of items under header
		100);           // Width of items under header

	m_listParam.InsertColumn(1, "Name", LVCFMT_CENTER, 80);
	m_listParam.InsertColumn(2, "Age", LVCFMT_LEFT, 100);
	m_listParam.InsertColumn(3, "Address", LVCFMT_LEFT, 80);

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


// Parameter 저장
void CparameterDlg::OnBnClickedButtonSaveParameter()
{

	UpdateData(FALSE);
}

// Parameter 불러오기
void CparameterDlg::OnBnClickedButtonLoadParameter()
{
	
	UpdateData(FALSE);
}



//파라미터를 set test
void CparameterDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pair<string, PARAM> param = m_param.GetParam("input_string");
	string val = "input_string_edit";
	m_param.SetParam(param, val);
	m_param.SaveParam();
}

