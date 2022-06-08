#pragma once


// CGame_Rest2 对话框

class CGame_Rest2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_Rest2)

public:
	CGame_Rest2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_Rest2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Rest2_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 休息时长
	CEdit m_rest2_time;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnRest2Addtolist();
};
