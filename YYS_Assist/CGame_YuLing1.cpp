// CGame_YuLing1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YuLing1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_YuLing1 对话框

IMPLEMENT_DYNAMIC(CGame_YuLing1, CDialog)

CGame_YuLing1::CGame_YuLing1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YuLing1_DLG, pParent)
{

}

CGame_YuLing1::~CGame_YuLing1()
{
}

void CGame_YuLing1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YL1_ROUND, m_yuLing1_round);
	DDX_Control(pDX, IDC_COMBO_YL1_MODE, m_yuLing1_mode);
	DDX_Control(pDX, IDC_COMBO_YL1_LAYER, m_yuLing1_layer);
}


BEGIN_MESSAGE_MAP(CGame_YuLing1, CDialog)
	ON_BN_CLICKED(IDC_BTN_YL1_ADDTOLIST, &CGame_YuLing1::OnBnClickedBtnYl1Addtolist)
END_MESSAGE_MAP()


// CGame_YuLing1 消息处理程序


BOOL CGame_YuLing1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yuLing1_round.SetWindowTextW(_T("0"));
	m_yuLing1_mode.SetCurSel(0);
	m_yuLing1_layer.SetCurSel(2);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void CGame_YuLing1::OnBnClickedBtnYl1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YL1_ROUND, round_str);
	UpdateData(FALSE);
	//怪物种类
	CString mode_str, layer_str;
	int mode_int = m_yuLing1_mode.GetCurSel();//模式索引
	int layer_int = m_yuLing1_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	layer_str.Format(_T("-%d"), layer_int);

	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("御灵-" + round_str + mode_str + layer_str));
}
