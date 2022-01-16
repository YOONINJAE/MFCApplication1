
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
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
public:
	afx_msg void OnBnClickedPlus();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Plus, &CAboutDlg::OnBnClickedPlus)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, result);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Plus, &CMFCApplication1Dlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_Substract, &CMFCApplication1Dlg::OnBnClickedSubstract)
	ON_BN_CLICKED(IDC_Multiply, &CMFCApplication1Dlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_Divide, &CMFCApplication1Dlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_Equal, &CMFCApplication1Dlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_Clear, &CMFCApplication1Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAboutDlg::OnBnClickedPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CMFCApplication1Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// wparma은 버튼의 아이디가 들어감.
	if (wParam >= IDC_num0 && wParam <= IDC_num9) {
		CString str, num_str;
		num_str.Format(L"%d", wParam - IDC_num0); // num의 값 출력
		if(m_step_flag == 0)GetDlgItemText(IDC_EDIT2, str);
		else {
			m_first_value = GetDlgItemInt(IDC_EDIT2); // 값 백업
			m_step_flag = 0;
		}
		SetDlgItemText(IDC_EDIT2, str+ num_str);
	}
	return CDialogEx::OnCommand(wParam, lParam);
}


void CMFCApplication1Dlg::OnBnClickedPlus()
{
	m_op_flag = PLUS;
	GetDlgItemText(IDC_EDIT2,m_history);
	SetDlgItemText(IDC_EDIT1, m_history + "+");
	m_step_flag = 1;
}

void CMFCApplication1Dlg::OnBnClickedSubstract()
{
	m_op_flag = SUBTRACT;
	GetDlgItemText(IDC_EDIT2, m_history);
	SetDlgItemText(IDC_EDIT1, m_history + "-");
	m_step_flag = 1;
}

void CMFCApplication1Dlg::OnBnClickedMultiply()
{
	m_op_flag = MULTIPLY;
	GetDlgItemText(IDC_EDIT2, m_history);
	SetDlgItemText(IDC_EDIT1, m_history + "×");
	m_step_flag = 1;
}

void CMFCApplication1Dlg::OnBnClickedDivide()
{
	m_op_flag = DIVIDE;
	GetDlgItemText(IDC_EDIT2, m_history);
	SetDlgItemText(IDC_EDIT1, m_history + "÷");
	m_step_flag = 1;
}


void CMFCApplication1Dlg::OnBnClickedEqual()
{
	int second_value = GetDlgItemInt(IDC_EDIT2); // 결과 값 백업
	CString str;
	GetDlgItemText(IDC_EDIT2,str);
	//operation flag
	switch (m_op_flag) {
	case PLUS:
		m_first_value += second_value;
		SetDlgItemText(IDC_EDIT1, m_history + "+" + str); // history 표시
		break;
	case SUBTRACT:
		m_first_value -= second_value;
		SetDlgItemText(IDC_EDIT1, m_history + "-" + str);
		break;
	case MULTIPLY:
		m_first_value *= second_value;
		SetDlgItemText(IDC_EDIT1, m_history + "*" + str);
		break;
	case DIVIDE:
		if (second_value != 0) { 
			m_first_value /= second_value;
			SetDlgItemText(IDC_EDIT1, m_history + "/" + str);
		}
		else m_first_value = 0;
		break;
	}
	m_history.Format(_T("%d"), m_first_value); // history update
	SetDlgItemInt(IDC_EDIT2, m_first_value);
	m_step_flag = 1;
}


void CMFCApplication1Dlg::OnBnClickedClear()
{
	m_history = "";
	SetDlgItemText(IDC_EDIT2, m_history);
	SetDlgItemText(IDC_EDIT1, m_history);
}
