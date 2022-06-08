#pragma once


// CGame_GeRenTuPo1 对话框

class CGame_GeRenTuPo1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_GeRenTuPo1)

public:
	CGame_GeRenTuPo1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_GeRenTuPo1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GeRenTuPo1_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 个人突破次数
	CEdit m_grtp1_round;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnGrtp1Addtolist();
	// 突破模式
	CComboBox m_mode;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
