#pragma once


// CGame_YeYuanHuo1 对话框

class CGame_YeYuanHuo1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YeYuanHuo1)

public:
	CGame_YeYuanHuo1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YeYuanHuo1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YeYuanHuo1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 业原火次数
	CEdit m_yeYuanHuo1_round;
	// 业原火层数
	CComboBox m_yeYuanHuo1_layer;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYyh1Addtolist();
};
