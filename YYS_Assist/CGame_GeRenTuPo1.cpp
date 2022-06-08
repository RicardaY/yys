// CGame_GeRenTuPo1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_GeRenTuPo1.h"
#include "afxdialogex.h"
#include "CGame1.h"


// CGame_GeRenTuPo1 对话框

IMPLEMENT_DYNAMIC(CGame_GeRenTuPo1, CDialog)

CGame_GeRenTuPo1::CGame_GeRenTuPo1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_GeRenTuPo1_DLG, pParent)
{

}

CGame_GeRenTuPo1::~CGame_GeRenTuPo1()
{
}

void CGame_GeRenTuPo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRTP1_ROUND, m_grtp1_round);
	DDX_Control(pDX, IDC_TUPOMODE, m_mode);
}


BEGIN_MESSAGE_MAP(CGame_GeRenTuPo1, CDialog)
	ON_BN_CLICKED(IDC_BTN_GRTP1_ADDTOLIST, &CGame_GeRenTuPo1::OnBnClickedBtnGrtp1Addtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_GeRenTuPo1 消息处理程序


BOOL CGame_GeRenTuPo1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_grtp1_round.SetWindowTextW(_T("30"));
	m_mode.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void CGame_GeRenTuPo1::OnBnClickedBtnGrtp1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_GRTP1_ROUND, round_str);
	UpdateData(FALSE);
	//模式
	CString mode_str;
	int mode = m_mode.GetCurSel();
	mode_str.Format(_T("-%d"), mode);
	UpdateData(FALSE);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("结界突破-" + round_str + mode_str));
}


HBRUSH CGame_GeRenTuPo1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	return hbr;
}
