// CGame_GeRenTuPo2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_GeRenTuPo2.h"
#include "afxdialogex.h"
#include "CGame2.h"


// CGame_GeRenTuPo2 对话框

IMPLEMENT_DYNAMIC(CGame_GeRenTuPo2, CDialog)

CGame_GeRenTuPo2::CGame_GeRenTuPo2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_GeRenTuPo2_DLG, pParent)
{

}

CGame_GeRenTuPo2::~CGame_GeRenTuPo2()
{
}

void CGame_GeRenTuPo2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRTP2_ROUND, m_grtp2_round);
	DDX_Control(pDX, IDC_TUPOMODE, m_mode);
}


BEGIN_MESSAGE_MAP(CGame_GeRenTuPo2, CDialog)
	ON_BN_CLICKED(IDC_BTN_GRTP2_ADDTOLIST, &CGame_GeRenTuPo2::OnBnClickedBtnGrtp2Addtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_GeRenTuPo2 消息处理程序


BOOL CGame_GeRenTuPo2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_grtp2_round.SetWindowTextW(_T("30"));
	m_mode.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame2 *p;
void CGame_GeRenTuPo2::OnBnClickedBtnGrtp2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_GRTP2_ROUND, round_str);
	UpdateData(FALSE);
	//模式
	CString mode_str;
	int mode = m_mode.GetCurSel();
	mode_str.Format(_T("-%d"), mode);
	UpdateData(FALSE);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("结界突破-" + round_str + mode_str));
}


HBRUSH CGame_GeRenTuPo2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
