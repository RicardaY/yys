// CGame_YeYuanHuo2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YeYuanHuo2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_YeYuanHuo2 对话框

IMPLEMENT_DYNAMIC(CGame_YeYuanHuo2, CDialog)

CGame_YeYuanHuo2::CGame_YeYuanHuo2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YeYuanHuo2_DLG, pParent)
{

}

CGame_YeYuanHuo2::~CGame_YeYuanHuo2()
{
}

void CGame_YeYuanHuo2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YYH2_ROUND, m_yeYuanHuo2_round);
	DDX_Control(pDX, IDC_COMBO_YYH2_LAYER, m_yeYuanHuo2_layer);
}


BEGIN_MESSAGE_MAP(CGame_YeYuanHuo2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YYH2_ADDTOLIST, &CGame_YeYuanHuo2::OnBnClickedBtnYyh2Addtolist)
END_MESSAGE_MAP()


// CGame_YeYuanHuo2 消息处理程序


BOOL CGame_YeYuanHuo2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_yeYuanHuo2_round.SetWindowTextW(_T("0"));
	m_yeYuanHuo2_layer.SetCurSel(2);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_YeYuanHuo2::OnBnClickedBtnYyh2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YYH2_ROUND, round_str);
	UpdateData(FALSE);
	//怪物种类
	CString mode_str;
	int mode_int = m_yeYuanHuo2_layer.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);

	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("业原火-" + round_str + mode_str));
}
