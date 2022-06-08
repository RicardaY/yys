#pragma once


// CGame_YuHun2 对话框

class CGame_YuHun2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YuHun2)

public:
	CGame_YuHun2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YuHun2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YUHUN2_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 御魂次数
	CEdit m_yuhun_round2;
	// 御魂层数
	CComboBox m_yuhun_layer2;
	// 御魂加成
	CComboBox m_yuhun_auto_bonus2;
	// 公开权限
	CComboBox m_yuhun_ppw2;
	// 邀请同/跨区好友
	CComboBox m_yuhun_prefer_friend2;
	virtual BOOL OnInitDialog();
	// 胜利自动接受邀请
	CButton m_yuhun2_win;
	// 三人组队
	CButton m_yuhun2_triple_group;
	// 最近组队
	CButton m_yuhun2_recent_group;
	afx_msg void OnBnClickedBtnYh2Addtolist();
};
