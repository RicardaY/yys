#pragma once


// CGame_JueXing1 对话框

class CGame_JueXing1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_JueXing1)

public:
	CGame_JueXing1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_JueXing1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JueXing1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 觉醒次数
	CEdit m_jueXing1_round;
	// 觉醒模式
	CComboBox m_jueXing1_mode;
	// 觉醒层数
	CComboBox m_jueXing1_layer;
	// 觉醒加成
	CComboBox m_jueXing1_auto_bonus;
	// 公开权限
	CComboBox m_jueXing1_ppw;
	// 邀请同/跨区好友
	CComboBox m_jueXing1_prefer_friend;
	// 胜利邀请好友
	CButton m_jueXing1_win;
	// 三人组队
	CButton m_juexing1_triple_group;
	// 最近组队
	CButton m_jueXing1_recent_group;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnJx1Addtolist();
};
