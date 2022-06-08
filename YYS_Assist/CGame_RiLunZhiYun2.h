#pragma once


// CGame_RiLunZhiYun2 对话框

class CGame_RiLunZhiYun2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_RiLunZhiYun2)

public:
	CGame_RiLunZhiYun2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_RiLunZhiYun2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RiLunZhiYun2_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 日轮之陨次数
	CEdit m_rlzy2_round;
	// 日轮之陨层数
	CComboBox m_rlzy2_layer;
	// 日轮之陨加成
	CComboBox m_rlzy2_auto_bonus;
	// 公开权限
	CComboBox m_rlzy2_ppw;
	// 邀请同/跨区好友
	CComboBox m_rlzy2_prefer_friend;
	// 胜利继续邀请
	CButton m_rlzy2_win;
	// 三人组队
	CButton m_rlzy2_triple_group;
	// 最近组队
	CButton m_rlzy2_recent_group;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnRlzy2Addtolist();
};
