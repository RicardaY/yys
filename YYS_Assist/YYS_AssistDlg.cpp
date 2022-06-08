
// YYS_AssistDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "YYS_Assist.h"
#include "YYS_AssistDlg.h"
#include "yys_function.h"
#include "afxdialogex.h"
#include "obj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#if UNICODE
#define SetDllPath "SetDllPathW"
#else
#define SetDllPath _T("SetDllPathA")
#endif

// 全局的dm对象
dmsoft * g_dm = NULL;
//字库地址
CString g_path = _T("pic_font");


//此处添加注册大漠代码即可 (因为大漠收费，故需自己实现注册)
int RegisterDm(){
	// 初始化COM模型为mta
	CoInitializeEx(NULL, 0);
	// 创建对象,此对象必须全局保持
	g_dm = new dmsoft;
	if (g_dm == NULL)
	{
		//Log(_T("对象创建失败"));
		return -500;
	}
	//下面写注册 两个参数：大漠注册码   附加码
	long registerResult = g_dm->Reg(_T(""), _T(""));
	if (registerResult != 1)
	{
		//Log(_T("收费注册失败,返回值:%d"), dm_ret);
		delete g_dm;
		return registerResult;
	}
	return registerResult;
}


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CYYSAssistDlg 对话框



CYYSAssistDlg::CYYSAssistDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YYS_MAIN_DLG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_LOGO);
}

void CYYSAssistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MIAN, m_tab_main);
}

BEGIN_MESSAGE_MAP(CYYSAssistDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CYYSAssistDlg 消息处理程序

BOOL CYYSAssistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab_main.AddPage(_T("游戏一"),&game1,IDD_DIALOG_GAME1);
	m_tab_main.AddPage(_T("游戏二"), &game2, IDD_DIALOG_GAME2);
	m_tab_main.Show();
	//初始化线程状态
	initThreadInfo();
	int dmres = RegisterDm();
	CString strRes;
	strRes.Format(_T("%d"), dmres);

	if (dmres != 1) {
		if (dmres == -1) {
			MessageBox(_T("请检查网络连接！！！,错误码：" + strRes));
			return TRUE;
		}
		else if (dmres == -2) {
			MessageBox(_T("请检查是否以管理员身份运行！！！,错误码：" + strRes));
			return TRUE;
		}
		else if (dmres == 0) {
			MessageBox(_T("请检查防火墙设置！！！,错误码=" + strRes + "，点击确定查看解决方案引导"));
			MessageBox(_T("点击确定跳转至浏览器打开解决方案"));
			CString codePath = _T("https://jingyan.baidu.com/article/9faa7231e4a08c473c28cba5.html");
			ShellExecute(NULL, _T("open"), codePath, NULL, NULL, SW_SHOW);
			MessageBox(_T("照着前面设置完成之后，删除电脑C盘下的gameData文件夹，然后重新启动脚本，如果还是不行，多启动1-2次脚本"));
			return TRUE;
		}
		else if (dmres == -500) {
			MessageBox(_T("注册COM组件失败，如果有杀毒提示警告框，要全部允许并信任。错误码：" + strRes));
			return TRUE;
		}
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CYYSAssistDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CYYSAssistDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CYYSAssistDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/***
 * ░░░░░░░░░░░░░░░░░░░░░░░░▄░░
 * ░░░░░░░░░▐█░░░░░░░░░░░▄▀▒▌░
 * ░░░░░░░░▐▀▒█░░░░░░░░▄▀▒▒▒▐
 * ░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐
 * ░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐
 * ░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌
 * ░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒
 * ░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐
 * ░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄
 * ░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒
 * ▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒
 * 单身狗就这样默默地看着你，一句话也不说。
 */


HBRUSH CYYSAssistDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}
