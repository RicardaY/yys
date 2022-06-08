// CGame_ChangeEquip2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_ChangeEquip2.h"
#include "afxdialogex.h"


// CGame_ChangeEquip2 对话框
CGame_ChangeEquip2 *changeEquip;

IMPLEMENT_DYNAMIC(CGame_ChangeEquip2, CDialog)

CGame_ChangeEquip2::CGame_ChangeEquip2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHANGEEQUIP2, pParent)
{
	changeEquip = this;
}

CGame_ChangeEquip2::~CGame_ChangeEquip2()
{
}

void CGame_ChangeEquip2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GROUP1, m_yhg);
	DDX_Control(pDX, IDC_TEAM1, m_yht);
	DDX_Control(pDX, IDC_GROUP2, m_jxg);
	DDX_Control(pDX, IDC_TEAM2, m_jxt);
	DDX_Control(pDX, IDC_GROUP3, m_tsg);
	DDX_Control(pDX, IDC_TEAM3, m_tst);
	DDX_Control(pDX, IDC_GROUP4, m_rlzyg);
	DDX_Control(pDX, IDC_TEAM4, m_rlzyt);
	DDX_Control(pDX, IDC_GROUP5, m_yszhg);
	DDX_Control(pDX, IDC_TEAM5, m_yszht1);
	DDX_Control(pDX, IDC_TEAM51, m_yszht2);
	DDX_Control(pDX, IDC_GROUP6, m_ylg);
	DDX_Control(pDX, IDC_TEAM6, m_ylt);
	DDX_Control(pDX, IDC_GROUP7, m_yyhg);
	DDX_Control(pDX, IDC_TEAM7, m_yyht);
	DDX_Control(pDX, IDC_GROUP8, m_jjtpg);
	DDX_Control(pDX, IDC_TEAM8, m_jjtpt);
	DDX_Control(pDX, IDC_GROUP9, m_yqfyg);
	DDX_Control(pDX, IDC_TEAM9, m_yqfyt);
	DDX_Control(pDX, IDC_ISCHANGE, m_ispreset);
}


BEGIN_MESSAGE_MAP(CGame_ChangeEquip2, CDialog)
END_MESSAGE_MAP()


// CGame_ChangeEquip2 消息处理程序


BOOL CGame_ChangeEquip2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//御魂组
	m_yhg.SetCurSel(0);
	m_jxg.SetCurSel(0);
	m_tsg.SetCurSel(0);
	m_rlzyg.SetCurSel(0);
	m_yszhg.SetCurSel(0);
	m_ylg.SetCurSel(0);
	m_yyhg.SetCurSel(0);
	m_jjtpg.SetCurSel(0);
	m_yqfyg.SetCurSel(0);
	//御魂队伍
	m_yht.SetCurSel(0);
	m_jxt.SetCurSel(0);
	m_tst.SetCurSel(0);
	m_rlzyt.SetCurSel(0);
	m_yszht1.SetCurSel(0);
	m_yszht2.SetCurSel(0);
	m_ylt.SetCurSel(0);
	m_yyht.SetCurSel(0);
	m_jjtpt.SetCurSel(0);
	m_yqfyt.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
