// CGame_NewEvent2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_NewEvent2.h"
#include "afxdialogex.h"
#include "CGame2.h"

// CGame_NewEvent2 对话框

IMPLEMENT_DYNAMIC(CGame_NewEvent2, CDialog)

CGame_NewEvent2::CGame_NewEvent2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NEW_EVENT2_DLG, pParent)
{

}

CGame_NewEvent2::~CGame_NewEvent2()
{
}

void CGame_NewEvent2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NE1_ROUND, m_round);
}


BEGIN_MESSAGE_MAP(CGame_NewEvent2, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADDTOLIST, &CGame_NewEvent2::OnBnClickedBtnAddtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_NewEvent2 消息处理程序

BOOL CGame_NewEvent2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_round.SetWindowTextW(_T("40"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame2 *p;
void CGame_NewEvent2::OnBnClickedBtnAddtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_NE1_ROUND, round_str);
	UpdateData(FALSE);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("新活动-" + round_str));
}

HBRUSH CGame_NewEvent2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkMode(OPAQUE);
	}
	if (IDC_TIPS2 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkMode(OPAQUE);
	}
	if (IDC_TIPS3 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkMode(OPAQUE);
	}
	return hbr;
}
