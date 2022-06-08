// CGame_NewEvent1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_NewEvent1.h"
#include "afxdialogex.h"
#include "CGame1.h"

// CGame_NewEvent1 对话框

IMPLEMENT_DYNAMIC(CGame_NewEvent1, CDialog)

CGame_NewEvent1::CGame_NewEvent1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NEW_EVENT1_DLG, pParent)
{

}

CGame_NewEvent1::~CGame_NewEvent1()
{
}

void CGame_NewEvent1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NE_ROUND, m_round);
}


BEGIN_MESSAGE_MAP(CGame_NewEvent1, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADDTOLIST, &CGame_NewEvent1::OnBnClickedBtnAddtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_NewEvent1 消息处理程序

BOOL CGame_NewEvent1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_round.SetWindowTextW(_T("40"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_NewEvent1::OnBnClickedBtnAddtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_NE_ROUND, round_str);
	UpdateData(FALSE);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("新活动-" + round_str ));
}

HBRUSH CGame_NewEvent1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
