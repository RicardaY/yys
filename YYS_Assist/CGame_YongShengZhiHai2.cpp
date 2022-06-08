// CGame_YongShengZhiHai2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YongShengZhiHai2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_YongShengZhiHai2 对话框

IMPLEMENT_DYNAMIC(CGame_YongShengZhiHai2, CDialog)

CGame_YongShengZhiHai2::CGame_YongShengZhiHai2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YongShengZhiHai2_DLG, pParent)
{

}

CGame_YongShengZhiHai2::~CGame_YongShengZhiHai2()
{
}

void CGame_YongShengZhiHai2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YSZH2_ROUND, m_yszh2_round);
	DDX_Control(pDX, IDC_COMBO_YSZH2_LAYER, m_yszh2_layer);
	DDX_Control(pDX, IDC_COMBO_YSZH2_AUTO_BONUS, m_yszh2_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_YSZH2_PPW, m_yszh2_ppw);
	DDX_Control(pDX, IDC_COMBO_YSZH2_PREFER_FRIEND, m_yszh2_prefer_friend);
	DDX_Control(pDX, IDC_CHECK_YSZH2_RECENT_GROUP, m_yszh2_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_YongShengZhiHai2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YSZH2_ADDTOLIST, &CGame_YongShengZhiHai2::OnBnClickedBtnYszh2Addtolist)
END_MESSAGE_MAP()


// CGame_YongShengZhiHai2 消息处理程序


BOOL CGame_YongShengZhiHai2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yszh2_round.SetWindowTextW(_T("30"));
	m_yszh2_layer.SetCurSel(3);
	m_yszh2_auto_bonus.SetCurSel(0);
	m_yszh2_ppw.SetCurSel(2);
	m_yszh2_prefer_friend.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_BEASKED, IDC_RADIO_YSZH_BEASKED);
	//check box default select
	//m_yuhun1_triple_group.SetCheck(TRUE);
	m_yszh2_recent_group.SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_YongShengZhiHai2::OnBnClickedBtnYszh2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YSZH2_ROUND, round_str);
	UpdateData(FALSE);
	//层数
	CString layer_str;
	int layer_int = m_yszh2_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_yszh2_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_yszh2_ppw.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("永生之海-" + round_str + layer_str + jiacheng_str + zudui_str + right_str));

}
