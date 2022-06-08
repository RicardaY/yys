#pragma once


// CGame_NewEvent2 对话框

class CGame_NewEvent2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_NewEvent2)

public:
	CGame_NewEvent2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_NewEvent2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_EVENT2_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_round;
	afx_msg void OnBnClickedBtnAddtolist();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
