#pragma once


// CGame_inDependentFunc2 对话框

class CGame_inDependentFunc2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_inDependentFunc2)

public:
	CGame_inDependentFunc2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_inDependentFunc2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INDEPENDENT2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_baigui;
};
