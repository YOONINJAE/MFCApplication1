
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once
#define PLUS 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4

// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif
private:
	char m_op_flag; //   사용자가 어떤 연산자를 사용하는지 구분하는 척도
	char m_step_flag; // 사용자가 연산자를 클릭했는지 여부를 따지는 척도
	int m_first_value = 0; // temp 저장
	CString m_history; // 계산 값 history 표시용 변수

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


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
	afx_msg void OnBnClickedButton12();
	CString result;
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedSubstract();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedClear();
};
