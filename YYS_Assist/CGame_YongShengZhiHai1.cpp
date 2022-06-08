// CGame_YongShengZhiHai1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YongShengZhiHai1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_YongShengZhiHai1 对话框

IMPLEMENT_DYNAMIC(CGame_YongShengZhiHai1, CDialog)

CGame_YongShengZhiHai1::CGame_YongShengZhiHai1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YongShengZhiHai1_DLG, pParent)
{

}

CGame_YongShengZhiHai1::~CGame_YongShengZhiHai1()
{
}

void CGame_YongShengZhiHai1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YSZH1_ROUND, m_yszh1_round);
	DDX_Control(pDX, IDC_COMBO_YSZH1_LAYER, m_yszh1_layer);
	DDX_Control(pDX, IDC_COMBO_YSZH1_AUTO_BONUS, m_yszh1_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_YSZH1_PPW, m_yszh1_ppw);
	DDX_Control(pDX, IDC_COMBO_YSZH1_PREFER_FRIEND, m_yszh1_prefer_friend);
	DDX_Control(pDX, IDC_CHECK_YSZH1_RECENT_GROUP, m_yszh1_recent_group);
}


BEGIN_MESSAGE_MAP(CGame_YongShengZhiHai1, CDialog)
	ON_BN_CLICKED(IDC_BTN_YSZH1_ADDTOLIST, &CGame_YongShengZhiHai1::OnBnClickedBtnYszh1Addtolist)
END_MESSAGE_MAP()


// CGame_YongShengZhiHai1 消息处理程序


BOOL CGame_YongShengZhiHai1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yszh1_round.SetWindowTextW(_T("30"));
	m_yszh1_layer.SetCurSel(3);
	m_yszh1_auto_bonus.SetCurSel(0);
	m_yszh1_ppw.SetCurSel(2);
	m_yszh1_prefer_friend.SetCurSel(1);
	//radio default select
	CheckRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_BEASKED, IDC_RADIO_YSZH_BEASKED);
	//check box default select
	//m_yuhun1_triple_group.SetCheck(TRUE);
	m_yszh1_recent_group.SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void CGame_YongShengZhiHai1::OnBnClickedBtnYszh1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YSZH1_ROUND, round_str);
	UpdateData(FALSE);
	//层数
	CString layer_str;
	int layer_int = m_yszh1_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_yszh1_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//公开权限
	CString right_str;
	int right_int = m_yszh1_ppw.GetCurSel();//公开权限索引
	UpdateData(FALSE);
	right_str.Format(_T("-%d"), right_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("永生之海-" + round_str + layer_str + jiacheng_str + zudui_str + right_str));

}
