// CGame_RunLog1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_RunLog1.h"
#include "afxdialogex.h"

CGame_RunLog1 *plog1;
// CGame_RunLog1 对话框

IMPLEMENT_DYNAMIC(CGame_RunLog1, CDialog)

CGame_RunLog1::CGame_RunLog1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RunLog1, pParent)
{
	plog1 = this;
}

CGame_RunLog1::~CGame_RunLog1()
{
}

void CGame_RunLog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RUN_LOG, m_runLog);
}


BEGIN_MESSAGE_MAP(CGame_RunLog1, CDialog)
END_MESSAGE_MAP()


// CGame_RunLog1 消息处理程序


BOOL CGame_RunLog1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_runLog.SetLimitText(0);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
