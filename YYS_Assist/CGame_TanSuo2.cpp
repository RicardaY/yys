// CGame_TanSuo2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_TanSuo2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_TanSuo2 对话框

IMPLEMENT_DYNAMIC(CGame_TanSuo2, CDialog)

CGame_TanSuo2::CGame_TanSuo2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TanSuo2_DLG, pParent)
{

}

CGame_TanSuo2::~CGame_TanSuo2()
{
}

void CGame_TanSuo2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TANSUO2_ROUND, m_tansuo_round);
	DDX_Control(pDX, IDC_COMBO_TanSuo2_MODE, m_tansuo_mode);
	DDX_Control(pDX, IDC_COMBO_TanSuo2_LAYER, m_tansuo_layer);
	DDX_Control(pDX, IDC_COMBO_TanSuo2_DIFF, m_tansuo_diff);
	DDX_Control(pDX, IDC_COMBO_TanSuo2_MONSTER, m_tansuo_monster);
	DDX_Control(pDX, IDC_CHECK_TanSuo2_RECENT_GROUP, m_tansuo_rencent_group);
	DDX_Control(pDX, IDC_COMBO_TanSuo2_PREFER_FRIEND, m_tansuo_prefer_friend);
	DDX_Control(pDX, IDC_COMBO_TanSuo2_AUTO_BONUS, m_tansuo_auto_bonus);
	DDX_Control(pDX, IDC_SPEED, m_speed);
	DDX_Control(pDX, IDC_MATERIAL, m_material);
	DDX_Control(pDX, IDC_COMBO_MAKINDS, m_materialkinds);
	DDX_Control(pDX, IDC_COMBO_PROGRESSBAR, m_progressbar);
}


BEGIN_MESSAGE_MAP(CGame_TanSuo2, CDialog)
	ON_BN_CLICKED(IDC_BTN_Tansuo2_ADDTOLIST, &CGame_TanSuo2::OnBnClickedBtnTansuo2Addtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_TanSuo2 消息处理程序


BOOL CGame_TanSuo2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tansuo_round.SetWindowTextW(_T("0"));
	m_tansuo_mode.SetCurSel(0);
	m_tansuo_layer.SetCurSel(27);
	m_tansuo_diff.SetCurSel(1);
	m_tansuo_monster.SetCurSel(0);
	m_tansuo_auto_bonus.SetCurSel(1);
	m_tansuo_rencent_group.SetCheck(TRUE);
	m_tansuo_prefer_friend.SetCurSel(1);
	m_materialkinds.SetCurSel(0);
	m_progressbar.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_TanSuo2::OnBnClickedBtnTansuo2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_TANSUO2_ROUND, round_str);
	UpdateData(FALSE);

	//副本组队模式
	CString mode_str;
	int mode_int = m_tansuo_mode.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	//层数
	CString layer_str;
	int layer_int = m_tansuo_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//难度
	CString diff_str;
	int diff_int = m_tansuo_diff.GetCurSel();//难度索引
	UpdateData(FALSE);
	diff_str.Format(_T("-%d"), diff_int);
	//怪物种类
	CString monster_str;
	int monster_int = m_tansuo_monster.GetCurSel();//怪物种类索引
	UpdateData(FALSE);
	monster_str.Format(_T("-%d"), monster_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_tansuo_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//区服好友
	CString preFriend_str;
	int preFriend_int = m_tansuo_prefer_friend.GetCurSel();//区服好友索引
	UpdateData(FALSE);
	preFriend_str.Format(_T("-%d"), preFriend_int);
	//找怪速度
	CString speed_str;
	int speed = m_speed.GetCheck();
	UpdateData(FALSE);
	speed_str.Format(_T("-%d"), speed);
	//是否自动狗粮
	CString material_str;
	int material = m_material.GetCheck();
	UpdateData(FALSE);
	material_str.Format(_T("-%d"), material);
	//狗粮种类
	CString materialKinds_str;
	int materialKinds_int = m_materialkinds.GetCurSel();//狗粮种类索引
	UpdateData(FALSE);
	materialKinds_str.Format(_T("-%d"), materialKinds_int);
	//狗粮进度条
	CString progressBar_str;
	int progressBar_int = m_progressbar.GetCurSel();//狗粮进度条
	UpdateData(FALSE);
	progressBar_str.Format(_T("-%d"), progressBar_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("探索-" + round_str + mode_str + layer_str + diff_str + monster_str + jiacheng_str + preFriend_str + speed_str + material_str + materialKinds_str + progressBar_str));

}


HBRUSH CGame_TanSuo2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS2 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
