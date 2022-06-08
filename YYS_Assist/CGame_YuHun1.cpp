// CGame_YuHun1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YuHun1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_YuHun1 对话框

IMPLEMENT_DYNAMIC(CGame_YuHun1, CDialog)

CGame_YuHun1::CGame_YuHun1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YUHUN1_DLG, pParent)
{

}

CGame_YuHun1::~CGame_YuHun1()
{
}

void CGame_YuHun1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YH1_ROUND, m_yuhun_round1);
	DDX_Control(pDX, IDC_COMBO_YH1_LAYER, m_yuhun_layer1);
	DDX_Control(pDX, IDC_COMBO_YH1_AUTO_BONUS, m_yuhun_auto_bonus1);
	DDX_Control(pDX, IDC_COMBO_YH1_PPW, m_yuhun_ppw1);
	DDX_Control(pDX, IDC_COMBO_YH1_PREFER_FRIENG, m_yuhun_prefer_friend1);
	DDX_Control(pDX, IDC_CHECK_YH1_VICTORY, m_yuhun1_win);
	DDX_Control(pDX, IDC_CHECK_YH1_TRIPLE_GROUP, m_yuhun1_triple_group);
	DDX_Control(pDX, IDC_CHECK_YH1_RECENT_GROUP, m_yuhun1_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_YuHun1, CDialog)
	ON_BN_CLICKED(IDC_BTN_YH1_ADDTOLIST, &CGame_YuHun1::OnBnClickedBtnYh1Addtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_YuHun1 消息处理程序


BOOL CGame_YuHun1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yuhun_round1.SetWindowTextW(_T("0"));
	m_yuhun_layer1.SetCurSel(10);
	m_yuhun_auto_bonus1.SetCurSel(1);
	m_yuhun_ppw1.SetCurSel(2);
	m_yuhun_prefer_friend1.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK, IDC_RADIO_YH_BEASKED);
	//check box default select
	m_yuhun1_win.SetCheck(TRUE);
	//m_yuhun1_triple_group.SetCheck(TRUE);
	m_yuhun1_recent_group.SetCheck(TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
//添加单任务到列表
void CGame_YuHun1::OnBnClickedBtnYh1Addtolist()
{
	//获取参数
	UpdateData(true);
	//御魂次数
	CString round_str;
	GetDlgItemText(IDC_YH1_ROUND, round_str);
	UpdateData(FALSE);
	//御魂层数
	CString layer_str;
	int layer_int = m_yuhun_layer1.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_yuhun_auto_bonus1.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_yuhun_ppw1.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("御魂-" + round_str + layer_str + jiacheng_str + zudui_str + right_str));

}


HBRUSH CGame_YuHun1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}
