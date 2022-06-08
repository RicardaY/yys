#pragma once


// CGame_YongShengZhiHai1 对话框

class CGame_YongShengZhiHai1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YongShengZhiHai1)

public:
	CGame_YongShengZhiHai1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YongShengZhiHai1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YongShengZhiHai1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 永生之海次数
	CEdit m_yszh1_round;
	// 层数
	CComboBox m_yszh1_layer;
	// 加成
	CComboBox m_yszh1_auto_bonus;
	// 公开权限
	CComboBox m_yszh1_ppw;
	// 邀请同/跨区好友
	CComboBox m_yszh1_prefer_friend;
	// 最近组队
	CButton m_yszh1_recent_group;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYszh1Addtolist();
};
