// CGame_JueXing1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_JueXing1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_JueXing1 对话框

IMPLEMENT_DYNAMIC(CGame_JueXing1, CDialog)

CGame_JueXing1::CGame_JueXing1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_JueXing1_DLG, pParent)
{

}

CGame_JueXing1::~CGame_JueXing1()
{
}

void CGame_JueXing1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_JX1_ROUND, m_jueXing1_round);
	DDX_Control(pDX, IDC_COMBO_JX1_MODE, m_jueXing1_mode);
	DDX_Control(pDX, IDC_COMBO_JX1_LAYER, m_jueXing1_layer);
	DDX_Control(pDX, IDC_COMBO_JX1_AUTO_BONUS, m_jueXing1_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_JX1_PPW, m_jueXing1_ppw);
	DDX_Control(pDX, IDC_COMBO_JX1_PREFER_FRIEND, m_jueXing1_prefer_friend);
	DDX_Control(pDX, IDC_CHECK_JX1_VICTORY, m_jueXing1_win);
	DDX_Control(pDX, IDC_CHECK_JX1_TRIPLE_GROUP, m_juexing1_triple_group);
	DDX_Control(pDX, IDC_CHECK_JX1_RECENT_GROUP, m_jueXing1_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_JueXing1, CDialog)
	ON_BN_CLICKED(IDC_BTN_JX1_ADDTOLIST, &CGame_JueXing1::OnBnClickedBtnJx1Addtolist)
END_MESSAGE_MAP()


// CGame_JueXing1 消息处理程序


BOOL CGame_JueXing1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_jueXing1_round.SetWindowTextW(_T("0"));
	m_jueXing1_mode.SetCurSel(0);
	m_jueXing1_layer.SetCurSel(9);
	m_jueXing1_auto_bonus.SetCurSel(1);
	m_jueXing1_ppw.SetCurSel(2);
	m_jueXing1_prefer_friend.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_JX_SINGLE, IDC_RADIO_JX_ASK, IDC_RADIO_JX_BEASKED);
	//check box default select
	m_jueXing1_win.SetCheck(TRUE);
	//m_yuhun1_triple_group.SetCheck(TRUE);
	m_jueXing1_recent_group.SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void CGame_JueXing1::OnBnClickedBtnJx1Addtolist()
{
	//获取参数
	UpdateData(true);
	//觉醒次数
	CString round_str;
	GetDlgItemText(IDC_JX1_ROUND, round_str);
	UpdateData(FALSE);
	//觉醒模式
	CString mode_str;
	int mode_int = m_jueXing1_mode.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	//觉醒层数
	CString layer_str;
	int layer_int = m_jueXing1_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_jueXing1_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_JX_SINGLE, IDC_RADIO_JX_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_jueXing1_ppw.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("觉醒-" + round_str + mode_str + layer_str + jiacheng_str + zudui_str + right_str));

}
