// CGame_YaoQiFengYin1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YaoQiFengYin1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_YaoQiFengYin1 对话框

IMPLEMENT_DYNAMIC(CGame_YaoQiFengYin1, CDialog)

CGame_YaoQiFengYin1::CGame_YaoQiFengYin1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YaoQiFengYin1_DLG, pParent)
{

}

CGame_YaoQiFengYin1::~CGame_YaoQiFengYin1()
{
}

void CGame_YaoQiFengYin1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YQFY1_ROUND, m_yqfy1_round);
	DDX_Control(pDX, IDC_COMBO_YQFY1_KINDS, m_yqfy1_kinds);
	DDX_Control(pDX, IDC_CONDITION, m_condition);
}


BEGIN_MESSAGE_MAP(CGame_YaoQiFengYin1, CDialog)
	ON_BN_CLICKED(IDC_BTN_YQFY1_ADDTOLIST, &CGame_YaoQiFengYin1::OnBnClickedBtnYqfy1Addtolist)
END_MESSAGE_MAP()


// CGame_YaoQiFengYin1 消息处理程序


BOOL CGame_YaoQiFengYin1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yqfy1_round.SetWindowTextW(_T("0"));
	m_yqfy1_kinds.SetCurSel(8);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void CGame_YaoQiFengYin1::OnBnClickedBtnYqfy1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YQFY1_ROUND, round_str);
	UpdateData(FALSE);
	//怪物种类
	CString mode_str;
	int mode_int = m_yqfy1_kinds.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	//是否跟随房主退队
	CString condition_str;
	int condition = m_condition.GetCheck();
	UpdateData(FALSE);
	condition_str.Format(_T("-%d"), condition);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("妖气封印-" + round_str + mode_str+condition_str));
}
