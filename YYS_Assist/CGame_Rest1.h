#pragma once


// CGame_Rest1 对话框

class CGame_Rest1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_Rest1)

public:
	CGame_Rest1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_Rest1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Rest1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 休息时长
	CEdit m_rest1_time;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnRest1Addtolist();
};
