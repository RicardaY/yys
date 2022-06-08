// CGame_RiLunZhiYun1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_RiLunZhiYun1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_RiLunZhiYun1 对话框

IMPLEMENT_DYNAMIC(CGame_RiLunZhiYun1, CDialog)

CGame_RiLunZhiYun1::CGame_RiLunZhiYun1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RiLunZhiYun1_DLG, pParent)
{

}

CGame_RiLunZhiYun1::~CGame_RiLunZhiYun1()
{
}

void CGame_RiLunZhiYun1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RLZY1_ROUND, m_rlzy1_round);
	DDX_Control(pDX, IDC_COMBO_RLZY1_LAYER, m_rlzy1_layer);
	DDX_Control(pDX, IDC_COMBO_RLZY1_AUTO_BONUS, m_rlzy1_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_RLZY1_PPW, m_rlzy1_ppw);
	DDX_Control(pDX, IDC_COMBO_RLZY1_PREFER_FRIEND, m_rlzy1_prefer_friend);
	DDX_Control(pDX, IDC_VICTORY_RLZY1, m_rlzy1_win);
	DDX_Control(pDX, IDC_CHECK_RLZY1_TRIPLE_GROUP, m_rlzy1_triple_group);
	DDX_Control(pDX, IDC_CHECK_RLZY1_RECENT_GROUP, m_rlzy1_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_RiLunZhiYun1, CDialog)
	ON_BN_CLICKED(IDC_BTN_RLZY1_ADDTOLIST, &CGame_RiLunZhiYun1::OnBnClickedBtnRlzy1Addtolist)
END_MESSAGE_MAP()


// CGame_RiLunZhiYun1 消息处理程序


BOOL CGame_RiLunZhiYun1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_rlzy1_round.SetWindowTextW(_T("50"));
	m_rlzy1_layer.SetCurSel(2);
	m_rlzy1_auto_bonus.SetCurSel(0);
	m_rlzy1_ppw.SetCurSel(2);
	m_rlzy1_prefer_friend.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_BEASKED, IDC_RADIO_RLZY_BEASKED);
	//check box default select
	m_rlzy1_win.SetCheck(TRUE);
	//m_yuhun1_triple_group.SetCheck(TRUE);
	m_rlzy1_recent_group.SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void CGame_RiLunZhiYun1::OnBnClickedBtnRlzy1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_RLZY1_ROUND, round_str);
	UpdateData(FALSE);
	//层数
	CString layer_str;
	int layer_int = m_rlzy1_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_rlzy1_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_rlzy1_ppw.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("日轮之陨-" + round_str + layer_str + jiacheng_str + zudui_str + right_str));

}
