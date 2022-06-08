#pragma once


// CGame_TanSuo1 对话框

class CGame_TanSuo1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_TanSuo1)

public:
	CGame_TanSuo1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_TanSuo1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TanSuo1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 探索次数
	CEdit m_tansuo_round;
	// 探索组队模式
	CComboBox m_tansuo_mode;
	// 探索层数
	CComboBox m_tansuo_layer;
	// 探索难度
	CComboBox m_tansuo_diff;
	// 探索怪物类型
	CComboBox m_tansuo_monster;
	// 最近组队
	CButton m_tansuo_rencent_group;
	// 好友类型
	CComboBox m_tansuo_prefer_friend;
	virtual BOOL OnInitDialog();
	// 探索加成
	CComboBox m_tansuo_auto_bonus;
	afx_msg void OnBnClickedBtnTansuo1Addtolist();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	// 找怪速度
	CButton m_speed;
	CButton m_material;
	CComboBox m_materialkinds;
	CComboBox m_progressbar;
};
