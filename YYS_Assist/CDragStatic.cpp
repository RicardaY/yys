// CDragStatic1.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CDragStatic.h"
#include "obj.h"


// CDragStatic1
extern dmsoft *g_dm;
IMPLEMENT_DYNAMIC(CDragStatic, CStatic)

CDragStatic::CDragStatic()
{

}

CDragStatic::~CDragStatic()
{
}


BEGIN_MESSAGE_MAP(CDragStatic, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CDragStatic1 消息处理程序



//鼠标左键按下
void CDragStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();//设定鼠标消息的发送窗口为当前窗口
	//鼠标光标变化
	/*HCURSOR hc = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON_ACTIVE));
	::SetCursor(hc);*/
	//拖动后原位置图标变化
	HICON hIcon = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON_ML));
	this->SetIcon(hIcon);
	//启动定时器，调用OnTimer()
	SetTimer(1, 400, NULL);

	CStatic::OnLButtonDown(nFlags, point);
}

//鼠标左键弹起
void CDragStatic::OnLButtonUp(UINT nFlags, CPoint point)
{
	ReleaseCapture();
	HICON hIcon = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON_FIRST));
	this->SetIcon(hIcon);
	//关闭定时器
	KillTimer(1);

	CStatic::OnLButtonUp(nFlags, point);
}


void CDragStatic::OnTimer(UINT_PTR nIDEvent)
{
	HWND deskWnd = ::GetDesktopWindow();//获取桌面窗口
	HDC deskDC = ::GetWindowDC(deskWnd);//获取桌面窗口DC
	int oldRop2 = SetROP2(deskDC, R2_NOTXORPEN);//边框闪烁
	long w_hd = g_dm->GetMousePointWindow();
	CString handle;
	handle.Format(_T("%d"), w_hd);
	GetParent()->SetDlgItemTextW(IDC_GET_HD1, handle);//显示到编辑框


	long left, top, right, bottom;
	g_dm->GetWindowRect(w_hd, &left, &top, &right, &bottom);
	if (left < 0) left = 0;
	if (top < 0) top = 0;

	HPEN newPen = ::CreatePen(0, 3, RGB(125, 0, 125));
	HGDIOBJ oldPen = ::SelectObject(deskDC, newPen);


	::Rectangle(deskDC, left, top, right, bottom);
	Sleep(200);
	::Rectangle(deskDC, left, top, right, bottom);

	::SetROP2(deskDC, oldRop2);
	::SelectObject(deskDC, oldPen);

	::DeleteObject(newPen);
	::ReleaseDC(deskWnd, deskDC);
	deskDC = NULL;


	CStatic::OnTimer(nIDEvent);
}
