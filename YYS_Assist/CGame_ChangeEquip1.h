#pragma once


// CGame_ChangeEquip1 对话框

class CGame_ChangeEquip1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_ChangeEquip1)

public:
	CGame_ChangeEquip1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_ChangeEquip1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEEQUIP1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_yhg;
	CComboBox m_yht;
	CComboBox m_jxg;
	CComboBox m_jxt;
	CComboBox m_tsg;
	CComboBox m_tst;
	CComboBox m_rlzyg;
	CComboBox m_rlzyt;
	CComboBox m_yszhg;
	CComboBox m_yszht1;
	CComboBox m_yszht2;
	CComboBox m_ylg;
	CComboBox m_ylt;
	CComboBox m_yyhg;
	CComboBox m_yyht;
	CComboBox m_jjtpg;
	CComboBox m_jjtpt;
	CComboBox m_yqfyg;
	CComboBox m_yqfyt;
	CButton m_ispreset;
};
