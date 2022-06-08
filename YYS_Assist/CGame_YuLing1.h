#pragma once


// CGame_YuLing1 对话框

class CGame_YuLing1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YuLing1)

public:
	CGame_YuLing1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YuLing1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YuLing1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 御灵次数
	CEdit m_yuLing1_round;
	// 御灵模式
	CComboBox m_yuLing1_mode;
	// 御灵层数
	CComboBox m_yuLing1_layer;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYl1Addtolist();
};
