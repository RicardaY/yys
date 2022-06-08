#pragma once


// CGame_YongShengZhiHai2 对话框

class CGame_YongShengZhiHai2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YongShengZhiHai2)

public:
	CGame_YongShengZhiHai2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YongShengZhiHai2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YongShengZhiHai2_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 次数
	CEdit m_yszh2_round;
	// 层数
	CComboBox m_yszh2_layer;
	// 加成
	CComboBox m_yszh2_auto_bonus;
	// 公开权限
	CComboBox m_yszh2_ppw;
	// 邀请同/跨区好友
	CComboBox m_yszh2_prefer_friend;
	// 最近组队
	CButton m_yszh2_recent_group;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYszh2Addtolist();
};
