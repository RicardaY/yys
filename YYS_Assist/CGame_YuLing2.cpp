// CGame_YuLing2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YuLing2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_YuLing2 对话框

IMPLEMENT_DYNAMIC(CGame_YuLing2, CDialog)

CGame_YuLing2::CGame_YuLing2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YuLing2_DLG, pParent)
{

}

CGame_YuLing2::~CGame_YuLing2()
{
}

void CGame_YuLing2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YL2_ROUND, m_yuLing2_round);
	DDX_Control(pDX, IDC_COMBO_YL2_MODE, m_yuLing2_mode);
	DDX_Control(pDX, IDC_COMBO_YL2_LAYER, m_yuLing2_layer);
}


BEGIN_MESSAGE_MAP(CGame_YuLing2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YL2_ADDTOLIST, &CGame_YuLing2::OnBnClickedBtnYl2Addtolist)
END_MESSAGE_MAP()


// CGame_YuLing2 消息处理程序


BOOL CGame_YuLing2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yuLing2_round.SetWindowTextW(_T("0"));
	m_yuLing2_mode.SetCurSel(0);
	m_yuLing2_layer.SetCurSel(2);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_YuLing2::OnBnClickedBtnYl2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YL2_ROUND, round_str);
	UpdateData(FALSE);
	//怪物种类
	CString mode_str, layer_str;
	int mode_int = m_yuLing2_mode.GetCurSel();//模式索引
	int layer_int = m_yuLing2_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	layer_str.Format(_T("-%d"), layer_int);

	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("御灵-" + round_str + mode_str + layer_str));
}
