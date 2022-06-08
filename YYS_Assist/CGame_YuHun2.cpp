// CGame_YuHun2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YuHun2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_YuHun2 对话框

IMPLEMENT_DYNAMIC(CGame_YuHun2, CDialog)

CGame_YuHun2::CGame_YuHun2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YUHUN2_DLG, pParent)
{

}

CGame_YuHun2::~CGame_YuHun2()
{
}

void CGame_YuHun2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YH2_ROUND, m_yuhun_round2);
	DDX_Control(pDX, IDC_COMBO_YH2_LAYER, m_yuhun_layer2);
	DDX_Control(pDX, IDC_COMBO_YH2_AUTO_BONUS, m_yuhun_auto_bonus2);
	DDX_Control(pDX, IDC_COMBO_YH2_PPW, m_yuhun_ppw2);
	DDX_Control(pDX, IDC_COMBO_YH2_PREFER_FRIENG, m_yuhun_prefer_friend2);
	DDX_Control(pDX, IDC_CHECK_YH2_VICTORY, m_yuhun2_win);
	DDX_Control(pDX, IDC_CHECK_YH2_TRIPLE_GROUP, m_yuhun2_triple_group);
	DDX_Control(pDX, IDC_CHECK_YH2_RECENT_GROUP, m_yuhun2_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_YuHun2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YH2_ADDTOLIST, &CGame_YuHun2::OnBnClickedBtnYh2Addtolist)
END_MESSAGE_MAP()


// CGame_YuHun2 消息处理程序


BOOL CGame_YuHun2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yuhun_round2.SetWindowTextW(_T("0"));
	m_yuhun_layer2.SetCurSel(10);
	m_yuhun_auto_bonus2.SetCurSel(1);
	m_yuhun_ppw2.SetCurSel(2);
	m_yuhun_prefer_friend2.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK, IDC_RADIO_YH_BEASKED);
	//check box default select
	m_yuhun2_win.SetCheck(TRUE);
	//m_yuhun2_triple_group.SetCheck(TRUE);
	m_yuhun2_recent_group.SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_YuHun2::OnBnClickedBtnYh2Addtolist()
{
	//获取参数
	UpdateData(true);
	//御魂次数
	CString round_str;
	GetDlgItemText(IDC_YH2_ROUND, round_str);
	UpdateData(FALSE);
	//御魂层数
	CString layer_str;
	int layer_int = m_yuhun_layer2.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_yuhun_auto_bonus2.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_yuhun_ppw2.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("御魂-" + round_str + layer_str + jiacheng_str + zudui_str + right_str));


}
