#pragma once


// CGame_YaoQiFengYin1 对话框

class CGame_YaoQiFengYin1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YaoQiFengYin1)

public:
	CGame_YaoQiFengYin1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YaoQiFengYin1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YaoQiFengYin1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 妖气封印次数
	CEdit m_yqfy1_round;
	// 妖气封印种类
	CComboBox m_yqfy1_kinds;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYqfy1Addtolist();
	// 是否跟随房主退出队伍
	CButton m_condition;
};
