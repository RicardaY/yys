#pragma once


// CGame_RiLunZhiYun1 对话框

class CGame_RiLunZhiYun1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_RiLunZhiYun1)

public:
	CGame_RiLunZhiYun1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_RiLunZhiYun1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RiLunZhiYun1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 日轮之陨次数
	CEdit m_rlzy1_round;
	// 日轮之陨层数
	CComboBox m_rlzy1_layer;
	// 日轮之陨加成
	CComboBox m_rlzy1_auto_bonus;
	// 公开权限
	CComboBox m_rlzy1_ppw;
	// 邀请同/跨区好友
	CComboBox m_rlzy1_prefer_friend;
	// victory continue invite
	CButton m_rlzy1_win;
	// 3人组队
	CButton m_rlzy1_triple_group;
	// 最近组队
	CButton m_rlzy1_recent_group;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnRlzy1Addtolist();
};
