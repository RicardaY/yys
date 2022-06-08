// CGame_RiLunZhiYun2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_RiLunZhiYun2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_RiLunZhiYun2 对话框

IMPLEMENT_DYNAMIC(CGame_RiLunZhiYun2, CDialog)

CGame_RiLunZhiYun2::CGame_RiLunZhiYun2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RiLunZhiYun2_DLG, pParent)
{

}

CGame_RiLunZhiYun2::~CGame_RiLunZhiYun2()
{
}

void CGame_RiLunZhiYun2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RLZY2_ROUND, m_rlzy2_round);
	DDX_Control(pDX, IDC_COMBO_RLZY2_LAYER, m_rlzy2_layer);
	DDX_Control(pDX, IDC_COMBO_RLZY2_AUTO_BONUS, m_rlzy2_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_RLZY2_PPW, m_rlzy2_ppw);
	DDX_Control(pDX, IDC_COMBO_RLZY2_PREFER_FRIEND, m_rlzy2_prefer_friend);
	DDX_Control(pDX, IDC_VICTORY_RLZY2, m_rlzy2_win);
	DDX_Control(pDX, IDC_CHECK_RLZY2_TRIPLE_GROUP, m_rlzy2_triple_group);
	DDX_Control(pDX, IDC_CHECK_RLZY2_RECENT_GROUP, m_rlzy2_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_RiLunZhiYun2, CDialog)
	ON_BN_CLICKED(IDC_BTN_RLZY2_ADDTOLIST, &CGame_RiLunZhiYun2::OnBnClickedBtnRlzy2Addtolist)
END_MESSAGE_MAP()


// CGame_RiLunZhiYun2 消息处理程序


BOOL CGame_RiLunZhiYun2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_rlzy2_round.SetWindowTextW(_T("50"));
	m_rlzy2_layer.SetCurSel(2);
	m_rlzy2_auto_bonus.SetCurSel(0);
	m_rlzy2_ppw.SetCurSel(2);
	m_rlzy2_prefer_friend.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_BEASKED, IDC_RADIO_RLZY_BEASKED);
	//check box default select
	m_rlzy2_win.SetCheck(TRUE);
	//m_yuhun1_triple_group.SetCheck(TRUE);
	m_rlzy2_recent_group.SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_RiLunZhiYun2::OnBnClickedBtnRlzy2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_RLZY2_ROUND, round_str);
	UpdateData(FALSE);
	//层数
	CString layer_str;
	int layer_int = m_rlzy2_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_rlzy2_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_rlzy2_ppw.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("日轮之陨-" + round_str + layer_str + jiacheng_str + zudui_str + right_str));
}
