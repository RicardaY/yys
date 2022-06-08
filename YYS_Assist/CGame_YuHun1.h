#pragma once


// CGame_YuHun1 对话框

class CGame_YuHun1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YuHun1)

public:
	CGame_YuHun1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YuHun1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YUHUN1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 御魂次数
	CEdit m_yuhun_round1;
	// 御魂层数
	CComboBox m_yuhun_layer1;
	// 御魂加成
	CComboBox m_yuhun_auto_bonus1;
	// 公开权限
	CComboBox m_yuhun_ppw1;
	// 邀请同/跨区好友
	CComboBox m_yuhun_prefer_friend1;
	virtual BOOL OnInitDialog();
	// 胜利自动接受邀请
	CButton m_yuhun1_win;
	// 三人组队
	CButton m_yuhun1_triple_group;
	// 最近组队
	CButton m_yuhun1_recent_group;
	afx_msg void OnBnClickedBtnYh1Addtolist();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
