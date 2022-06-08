#pragma once
#include "pch.h"
#include "yys_function.h"
#include "CGame1.h"
#include "CGame_RunLog1.h"
#include "CGame_RunLog2.h"
#include<random>
#include<ctime>
#include<iomanip>
#define EXIT_THREAD -10

extern CGame_RunLog1 *plog1;
extern CGame_RunLog2 *plog2;
extern bool readyFlag;
ThreadInfo threadState[2];

//初始化线程状态信息
int initThreadInfo() {
	int i;
	for (i=0;i<2;i++)
	{
		threadState[i].pause = false;
		threadState[i].start = false;
		threadState[i].stop = false;
		threadState[i].suspend_flag = false;
	}
	return 1;
}
//拆分字符串
int yys_function::SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString)
{
	rArrString.RemoveAll();
	CString szStr = lpszStr;
	szStr.TrimLeft();
	szStr.TrimRight();

	if (szStr.GetLength() == 0)
	{
		return 0;
	}

	CString szSplit = lpszSplit;

	if (szSplit.GetLength() == 0)
	{
		rArrString.Add(szStr);
		return 1;
	}

	CString s;
	int n;

	do
	{
		n = szStr.Find(szSplit);

		if (n > 0)
		{
			rArrString.Add(szStr.Left(n));
			szStr = szStr.Right(szStr.GetLength() - n - szSplit.GetLength());
			szStr.TrimLeft();
		}
		else if (n == 0)
		{
			if (bAllowNullString)
			{
				rArrString.Add(_T(""));
			}

			szStr = szStr.Right(szStr.GetLength() - szSplit.GetLength());
			szStr.TrimLeft();
		}
		else
		{
			if ((szStr.GetLength() > 0) || bAllowNullString)
			{
				rArrString.Add(szStr);
			}

			break;
		}
	} while (1);

	return (int)rArrString.GetSize();
}
//读文件
int yys_function::ReadFile(CString filePath, CStringArray& ListArray)
{
	ListArray.RemoveAll();
	if (!PathFileExists(filePath))
	{
		MessageBox(NULL, _T("文件路径不存在!!!"), _T(""), 0);
		return 0;
	}
	//解决乱码
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");

	CStdioFile file;
	if (!file.Open(filePath, CFile::modeRead))
	{
		MessageBox(NULL, _T("读取文件失败!!!"), _T(""), 0);
		return 0;
	}
	CString strValue = _T("");
	while (file.ReadString(strValue))
	{
		ListArray.Add(strValue);
	}
	file.Close();
	//释放资源
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return (int)ListArray.GetSize();
}
//写文件
int yys_function::WriteFile(CString filePath, CStringArray& ListArray)
{
	//解决乱码
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	
	CStdioFile file;
	int listSize = ListArray.GetSize();
	if (listSize == 0) {
		MessageBox(NULL, _T("任务列表为空!!!"), _T(""), 0);
		return 0;
	}
	if (!file.Open(filePath, CFile::modeWrite| CFile::modeCreate))
	{
		MessageBox(NULL, _T("写入文件失败!!!"), _T(""), 0);
		return 0;
	}
	
	for (int i = 0; i < listSize; i++) {
		file.SeekToEnd();
		file.WriteString(ListArray.GetAt(i)+ _T("\n"));
	}
	file.Close();
	if (ListArray.GetSize() != 0) {
		MessageBox(NULL, _T("任务列表导出成功!!!"), _T(""), 0);
	}
	ListArray.RemoveAll();
	//释放资源
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return 1;
}
//获取子窗口句柄
HWND yys_function::findHandle(CString windowname) {
	HWND hd = FindWindow(NULL, windowname);
	HWND sub_hd = GetWindow(hd, GW_CHILD);
	return sub_hd;
}

//编辑框结尾追加数据
void yys_function::print_log(TCHAR szMsg[],int gameclass) {
	if (gameclass==0)
	{
		int iLen = plog1->m_runLog.GetWindowTextLength();
		plog1->m_runLog.SetSel(iLen, iLen, FALSE);
		plog1->m_runLog.ReplaceSel(szMsg, FALSE);
	}else if (gameclass == 1)
	{

		int iLen = plog2->m_runLog.GetWindowTextLength();
		plog2->m_runLog.SetSel(iLen, iLen, FALSE);
		plog2->m_runLog.ReplaceSel(szMsg, FALSE);
	}
	
	return;
}
//鼠标点击事件 click_x,click_y:相对子句柄坐标
void yys_function::mouse_click_event(CString windowname, int click_x, int click_y) {
	HWND sub_hd = findHandle(windowname);

	SendMessage(sub_hd, WM_LBUTTONDOWN, 0, MAKELPARAM(click_x, click_y));
	Sleep(50);
	SendMessage(sub_hd, WM_LBUTTONUP, 0, MAKELPARAM(click_x, click_y));
	return;
}

//鼠标移动
void yys_function::mouse_move(CString windowname, int start_x, int start_y, int end_x, int end_y) {
	HWND sub_hd = findHandle(windowname);
	SendMessage(sub_hd, WM_LBUTTONDOWN, 0, MAKELPARAM(start_x, start_y));
	Sleep(500);
	SendMessage(sub_hd, WM_MOUSEMOVE, 0, MAKELPARAM(end_x, end_y));
	Sleep(500);
	SendMessage(sub_hd, WM_LBUTTONUP, 0, MAKELPARAM(end_x, end_y));
	Sleep(1000);
	return;
}

//随即偏移坐标，防止游戏外挂检测
CPoint yys_function::random_pos(int pos_x, int pos_y, int offsetX, int offsetY) {
	std::default_random_engine e;
	//设置种子
	e.seed(unsigned(time(NULL)));
	//offsetX到offsetY
	std::uniform_real_distribution<double> u(offsetX, offsetY);
	CPoint pos;
	pos.x = pos_x + u(e), pos.y = pos_y + u(e);
	return pos;
}
//随机延迟点击，防止游戏外挂检测
int yys_function::random_delay(int index, int gameclass, dmsoft *dm, int time_min, int time_max) {
	std::default_random_engine e;
	//设置种子
	e.seed(unsigned(time(NULL)));
	//time_min到time_max
	std::uniform_real_distribution<double> u(time_min, time_max);
	Sleep(u(e));
	//暂停
	if (threadState[index].pause)
	{
		print_log(_T("线程已挂起\r\n"), gameclass);
		if (dm!=NULL)
		{
			dm->EnableBind(5);
		}
		while (1)
		{
			Sleep(3000);
			if (!threadState[index].pause)
			{
				print_log(_T("线程已恢复\r\n"), gameclass);
				if (dm != NULL)
				{
					dm->EnableBind(1);
				}
				break;
			}//暂停时退出
			if (threadState[index].stop)
			{
				break;
			}
		}
	}//停止
	if (threadState[index].stop) {
		threadState[index].start = false;
		return EXIT_THREAD;
	}
	return 1;
}

//判断是否在庭院 true:在 false:不在
bool yys_function::IsInYard(dmsoft *dm, int gameclass,int index) {
	if (dm==NULL)
	{
		return false;
	}
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long exploreRes, FpRes, rewordRes;
	int i = 20;
	while (i > 0)
	{
		//找探索灯笼
		FpRes = dm->FindPic(0, 0, 960, 275, _T("探索灯笼.bmp|探索灯笼1.bmp|探索灯笼2.bmp|探索灯笼3.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exploreRes = dm->FindStrFast(0, 0, 960, 275, _T("探索|探索1|探索2|探索3"), _T("1D1914-1E1915"), 0.85, &intX, &intY);
		//找悬赏封印
		rewordRes = dm->FindPic(290, 10, 346, 80, _T("加成1.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exploreRes !=-1) || (rewordRes !=-1)|| (FpRes!=-1))
		{
			break;
		}
		random_delay(index, gameclass, dm, 200, 250);
		i--;
	}
	//判断是否找到
	if ((exploreRes != -1) || (rewordRes != -1) || (FpRes != -1))
	{
		print_log(_T("已在庭院界面...\r\n"), gameclass);
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//判断庭院是否展开 true:展开 false:关闭
bool yys_function::IsShowYard(dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return false;
	}
	//组队、阴阳寮  C1B7AE-232827
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long teamRes, teamRes2, organizeReg;
	int i = 20;
	while (i > 0)
	{
		//找组队
		teamRes = dm->FindStrFast(261, 484, 427, 514, _T("组队"), _T("C1B7AE-232827"), 0.95, &intX, &intY);
		teamRes2=dm->FindPic(262, 444, 323, 510, _T("组队.bmp|灰色组队.bmp"), _T("202020"), 0.95, 0, &intX, &intY);
		//找阴阳寮
		organizeReg = dm->FindStrFast(261, 484, 427, 514, _T("阴阳寮"), _T("C1B7AE-232827"), 0.95, &intX, &intY);
		if (teamRes2!=-1||teamRes != -1 || organizeReg != -1)
		{
			break;
		}
		random_delay(index, gameclass, dm, 200, 250);
		i--;
	}
	//判断是否找到
	if (teamRes2!=-1|| teamRes != -1 || organizeReg != -1)
	{
		print_log(_T("庭院已展开...\r\n"), gameclass);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//展开庭院
int yys_function::showYard(dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	BOOL isShow = IsShowYard(dm, gameclass, index);
	if (!isShow)
	{
		if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("展开庭院...\r\n"), gameclass);
		dm->MoveToEx(901, 468, 14, 43);
		dm->delay(1000);
		dm->LeftClick();
		return 1;
	}
	return 0;
}

//寻找探索灯笼并点击
int yys_function::FindExploreLanTernAndClick(long hd, dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long FpX, FpY;
	long exploreRes,FpRes;
	int i = 20;
	print_log(_T("寻找探索灯笼...\r\n"), gameclass);
	while (i > 0)
	{
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//找探索灯笼1B1703-1C1803
		exploreRes = dm->FindStrFast(0, 0, 960, 275, _T("探索|探索1|探索2|探索3|探索4|探索5"), _T("1D1914-1E1915"), 0.85, &intX, &intY);
		FpRes = dm->FindPic(0, 0, 960, 275, _T("探索灯笼.bmp|探索灯笼1.bmp|探索灯笼2.bmp|探索灯笼3.bmp"), _T("202020"), 0.85, 0, &FpX, &FpY);
		if (exploreRes != -1|| FpRes!=-1)
		{
			print_log(_T("找到探索灯笼\r\n"), gameclass);
			//获取父窗口标题
			long parentHandle = dm->GetWindow(hd, 0);
			CString title = dm->GetWindowTitle(parentHandle);
			//点击
			if (exploreRes != -1) {
				if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 5, intY + 15);
				return 1;
			}else if (FpRes != -1) {
				if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, FpX + 5, FpY + 15);
				return 1;
			}
			
		}
		if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//点击组队
int yys_function::CombineTeamAction(long hd, dmsoft *dm, int gameclass, int index) {
	//点击组队
	if (dm == NULL)
	{
		return false;
	}
	//组队、阴阳寮  C1B7AE-232827
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);

	long intX, intY;
	long teamRes, organizeReg;

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	int i = 20;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//找组队
		teamRes = dm->FindStrFast(261, 484, 427, 514, _T("组队"), _T("C1B7AE-232827"), 0.95, &intX, &intY);
		organizeReg = dm->FindPic(262, 444, 323, 510, _T("组队.bmp|灰色组队.bmp"), _T("202020"), 0.95, 0, &intX, &intY);
		if (teamRes != -1 || organizeReg != -1)
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 250) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//判断是否找到
	if (teamRes != -1 || organizeReg != -1)
	{
		print_log(_T("点击组队...\r\n"), gameclass);
		if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, intX, intY);
		return 1;
	}
	else {
		return 0;
	}
}

//获取当前位置
long yys_function::findNowSection(CString sourcePic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long findLoc;
	int i = 20;
	long intX, intY;

	while (i > 0)
	{
		findLoc = dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, sourcePic, _T("202020"), 0.75, 0, &intX, &intY);
		if (findLoc != -1)
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	if (findLoc != -1)
	{
		return findLoc;
	}
	else {
		return -1;
	}
}
//寻找目标位置并点击---不触发停止
int yys_function::findDestination(long hd, CString allpic, long destinationLoc, CString destPic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	long intX, intY;
	//区域
	int startx = (startXY.x + endXY.x) / 2;
	int starty = startXY.y+(endXY.y - startXY.y)*0.2, endy = startXY.y + (endXY.y - startXY.y)*0.85;
	int i = 15;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//找目前所在位置
		long nowLoc = findNowSection(allpic, startXY, endXY, dm, gameclass, index);
		if (nowLoc == -1) {
			if(allpic.Left(7) == _T("1-1.bmp")){ print_log(_T("未找到当前所在位置（NowLoc）...\r\n"), gameclass); }
			return 0;
		}
		//下移
		if (destinationLoc <= nowLoc)
		{
			if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, destPic, _T("202020"), 0.75, 0, &intX, &intY) != -1)
			{
				random_delay(index, gameclass, dm, 2000, 2500);
				mouse_click_event(title, intX + 24, intY + 20);
				return 1;
			}
			else
			{
				random_delay(index, gameclass, dm, 500, 800);
				mouse_move(title, startx, starty, startx, endy);
			}

		}//上移
		else if (destinationLoc > nowLoc)
		{
			if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, destPic, _T("202020"), 0.75, 0, &intX, &intY) != -1)
			{
				random_delay(index, gameclass, dm, 2000, 2500);
				mouse_click_event(title, intX + 24, intY + 20);
				return 1;
			}
			else
			{
				random_delay(index, gameclass, dm, 500, 800);
				mouse_move(title, startx, endy, startx, starty);
			}

		}
		random_delay(index, gameclass, dm, 480, 520);
		i--;
	}
	return 0;
}

//创建队伍---点击邀请
int yys_function::CreatTeamToInvite(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//点击创建队伍
	int i = 20;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(741, 443, 875, 498, _T("创建队伍.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("创建队伍...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//设置公开权限
	i = 20;
	while (i > 0)
	{
		if (dm->FindPic(555, 361, 592, 398, _T("不公开(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("权限不公开...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}//557,365,591,398,
		if (dm->FindPic(557, 365, 591, 398, _T("不公开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//点击创建
	i = 20;
	long creatRes, cancelRes;
	while (i > 0)
	{
		cancelRes = dm->FindPic(247, 415, 360, 472, _T("取消.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		creatRes = dm->FindPic(603, 412, 712, 475, _T("创建.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((cancelRes != -1) && (creatRes != -1))
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 1200, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}

	//邀请好友
	i = 20;
	while (i > 0)
	{
		if (dm->FindPic(449, 159, 517, 219, _T("加.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("邀请好友...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 10);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		else if (dm->FindPic(770, 146, 862, 234, _T("探索加.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("邀请好友...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 10);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//点击最近组队
	i = 20;
	while (i > 0)
	{
		if (dm->FindPic(353, 61, 434, 109, _T("最近(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("最近组队好友...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 20, intY + 10);
			if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//判断是否为最近组队，是则邀请，否则退出
	i = 20;
	long recentRes;
	while (i > 0)
	{
		recentRes = dm->FindPic(404, 119, 483, 157, _T("最近组队.bmp"), _T("202020"), 0.95, 0, &intX, &intY);
		if (recentRes != -1)
		{
			print_log(_T("邀请...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX - 50, intY + 40);
			if (random_delay(index, gameclass, dm, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//不是最近组队好友，返回庭院
	if (recentRes == -1)
	{
		print_log(_T("未找到最近组队好友，返回庭院中...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	//点击邀请
	i = 20;
	long inviteRes, inCancelRes;
	while (i > 0)
	{
		inCancelRes = dm->FindPic(327, 401, 432, 458, _T("邀请取消.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		inviteRes = dm->FindPic(536, 407, 632, 454, _T("邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if ((inCancelRes != -1) && (inviteRes != -1))
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//解锁
int yys_function::unlock(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	int i = 10;
	//处理锁定or解锁
	if (random_delay(index, gameclass, dm, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(17, 481, 44, 509, _T("解锁状态.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (dm->FindPic(17, 481, 44, 509, _T("锁定状态.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 6, intY + 8);
			break;
		}
		if (random_delay(index, gameclass, dm, 400, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}

//检测好友进入队伍点挑战 
int yys_function::IsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//检查好友是否进入队伍
	print_log(_T("等待好友加入队伍...\r\n"), gameclass);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//点挑战
		if (dm->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("好友已加入队伍...\r\n"), gameclass);
			if (count == 0)
			{
				//等待好友操作解锁与锁定
				if (random_delay(index, gameclass, dm, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
				if (unlock(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//随机偏移坐标防检测
			CPoint pos = random_pos(intX, intY, 5, 10);
			if (random_delay(index, gameclass, dm, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//邀请进入副本
int yys_function::InviteEnterEvent(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//点准备
		if (readyFlag && (dm->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			print_log(_T("点击准备...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//胜利结算

		if (dm->FindPic(286, 34, 438, 169, _T("胜利.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("战斗结算中...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 429, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//接受邀请进入副本  public
int yys_function::ReceiveEnterEvent(long hd, dmsoft *dm,int count, CString gameMode, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	CString count_str;
	count_str.Format(_T("%d"), count + 2);
	int flag = 0;
	//开始
	while (1)
	{
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//接受默认邀请
		if (dm->FindPic(147, 163, 207, 219, _T("接受默认邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count_str.Format(_T("%d"), count +1);
			print_log(_T("接受默认邀请...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			print_log(_T("第" + count_str + "轮" + gameMode + "开始...\r\n"), gameclass);
			flag = 2;
			readyFlag = FALSE;
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}//接受普通邀请
		else if (dm->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY)!=-1) {
			count_str.Format(_T("%d"), count + 1);
			print_log(_T("接受普通邀请...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			print_log(_T("第" + count_str + "轮" + gameMode + "开始...\r\n"), gameclass);
			flag = 1;
			readyFlag = TRUE;
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点准备
		if (readyFlag &&(dm->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			print_log(_T("点击准备...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//胜利结算

		if (dm->FindPic(286, 34, 438, 169, _T("胜利.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("战斗结算中...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 429, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			if (flag==0)
			{
				print_log(_T("第" + count_str + "轮" + gameMode + "开始...\r\n"), gameclass);
			}
			if (flag == 2)
			{
				count_str.Format(_T("%d"), count + 2);
				print_log(_T("第" + count_str + "轮"+gameMode+"开始...\r\n"), gameclass);
			}
			break;
		}
		if (dm->FindPic(421, 289, 538, 350, _T("满御魂确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//默认邀请好友  public
int yys_function::DefalutInvite(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	int i = 10;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//默认邀请
		if (dm->FindPic(401, 251, 555, 289, _T("默认邀请队友.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("默认邀请好友...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	i = 10;
	while (i > 0)
	{
		//点击确定
		if (dm->FindPic(505, 302, 634, 343, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			if (random_delay(index, gameclass, dm, 1800, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}

//自动开加成
int yys_function::auto_open_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//是否选择自动开关加成
	//御魂
	if (jc_category==_T("御魂"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("正在打开加成...\r\n"), gameclass);
			//点击加成灯笼
			int yh_move = 0;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("御魂加成.bmp"), _T("202020"), 0.85, 0, &intX, &intY) !=-1)
				{
					long yhjc_X = intX, yhjc_Y = intY;
					if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("打开御魂加成...\r\n"), gameclass);
						//打开御魂加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("加成已打开，关闭加成界面...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (yh_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((yh_move >= 2)&&(yh_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						yh_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//觉醒
	else if (jc_category == _T("觉醒"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("正在打开加成...\r\n"), gameclass);
			int jx_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("觉醒加成.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					long jxjc_X = intX, jxjc_Y = intY;
					if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("打开觉醒加成...\r\n"), gameclass);
						//打开加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("加成已打开，关闭加成界面...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jx_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jx_move >= 2) && (jx_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jx_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//探索
	else if (jc_category == _T("探索"))
	{
		//4B4744-4C4744
		//开关全部经验
		if (jc_index == _T("1"))
		{
			print_log(_T("正在打开加成...\r\n"), gameclass);
			//点击加成
			int jy_move = 0;
			bool jy100Flag = false, jy50Flag = false;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验50.bmp|经验50-1.bmp|经验50-2.bmp|经验50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("打开50%经验加成...\r\n"), gameclass);
						//打开加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy50Flag = true;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%经验加成已打开...\r\n"), gameclass);
						jy50Flag = true;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验100.bmp|经验100-1.bmp|经验100-2.bmp|经验100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("打开100%经验加成...\r\n"), gameclass);
						//打开加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy100Flag = true;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%经验加成已打开...\r\n"), gameclass);
						jy100Flag = true;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//若都打开则关闭加成弹窗
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (jy50Flag && jy100Flag) {
					print_log(_T("加成已全部打开，关闭加成界面...\r\n"), gameclass);
					//关闭加成框
					if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, 128, 364);
						if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					print_log(_T("加成打开失败，请留意...\r\n"), gameclass);
					break;
				}
			}
			return 1;
		}
		//开启金币
		else if (jc_index == _T("2"))
		{
			print_log(_T("正在打开加成...\r\n"), gameclass);
			print_log(_T("金币加成功能暂未实现，请手动打开加成后再开启脚本...\r\n"), gameclass);
			//暂不实现此功能
			return 1;
		}
		//开启50%经验
		else if (jc_index == _T("3"))
		{
			print_log(_T("正在打开加成...\r\n"), gameclass);
			int jy_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验50.bmp|经验50-1.bmp|经验50-2.bmp|经验50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("打开50%经验加成...\r\n"), gameclass);
						//打开加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%经验加成已打开...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//开启100%经验
		else if (jc_index == _T("4"))
		{
		int jy_move = 0;
		print_log(_T("正在打开加成...\r\n"), gameclass);
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}

			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验100.bmp|经验100-1.bmp|经验100-2.bmp|经验100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("打开100%经验加成...\r\n"), gameclass);
						//打开加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%经验加成已打开...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }	
			}
			return 1;
		}
	}
}
//自动关加成
int yys_function::auto_close_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//是否选择自动开关加成
	//御魂
	if (jc_category == _T("御魂"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("正在关闭加成...\r\n"), gameclass);
			//点击加成灯笼
			int yh_move = 0;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("御魂加成.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					long yhjc_X = intX, yhjc_Y = intY;
					if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("关闭御魂加成...\r\n"), gameclass);
						//关闭御魂加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("加成已关闭，关闭加成界面...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (yh_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((yh_move >= 2) && (yh_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						yh_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//觉醒
	else if (jc_category == _T("觉醒"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("正在关闭加成...\r\n"), gameclass);
			int jx_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("觉醒加成.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					long jxjc_X = intX, jxjc_Y = intY;
					if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("关闭觉醒加成...\r\n"), gameclass);
						//关闭加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("加成已关闭，关闭加成界面...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jx_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jx_move >= 2) && (jx_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jx_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//探索
	else if (jc_category == _T("探索"))
	{
		//4B4744-4C4744
		//开关全部经验
		if (jc_index == _T("1"))
		{
			print_log(_T("正在关闭加成...\r\n"), gameclass);
			//点击加成
			int jy_move = 0;
			bool jy100Flag = true, jy50Flag = true;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验50.bmp|经验50-1.bmp|经验50-2.bmp|经验50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("关闭50%经验加成...\r\n"), gameclass);
						//关闭加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy50Flag = false;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%经验加成已关闭...\r\n"), gameclass);
						jy50Flag = false;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验100.bmp|经验100-1.bmp|经验100-2.bmp|经验100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("关闭100%经验加成...\r\n"), gameclass);
						//关闭加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy100Flag = false;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%经验加成已关闭...\r\n"), gameclass);
						jy100Flag = false;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//若都打开则关闭加成弹窗
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if ((!jy50Flag) && (!jy100Flag)) {
					print_log(_T("加成已全部关闭，关闭加成界面...\r\n"), gameclass);
					//关闭加成框
					if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, 128, 364);
						if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					print_log(_T("加成关闭失败，请留意...\r\n"), gameclass);
					break;
				}
			}
			return 1;
		}
		//关闭金币
		else if (jc_index == _T("2"))
		{
			print_log(_T("正在关闭加成...\r\n"), gameclass);
			print_log(_T("金币加成功能暂未实现，请手动关闭金币加成...\r\n"), gameclass);
			//暂不实现此功能
			return 1;
		}
		//关闭50%经验
		else if (jc_index == _T("3"))
		{
			print_log(_T("正在关闭加成...\r\n"), gameclass);
			int jy_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验50.bmp|经验50-1.bmp|经验50-2.bmp|经验50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("关闭50%经验加成...\r\n"), gameclass);
						//关闭加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%经验加成已关闭...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//关闭100%经验
		else if (jc_index == _T("4"))
		{
			int jy_move = 0;
			print_log(_T("正在关闭加成...\r\n"), gameclass);
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成1.bmp|加成2.bmp|加成3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("点击加成灯笼...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("已在加成界面...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}

			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (dm->FindPic(360, 92, 570, 358, _T("经验100.bmp|经验100-1.bmp|经验100-2.bmp|经验100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("关闭100%经验加成...\r\n"), gameclass);
						//关闭加成
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%经验加成已关闭...\r\n"), gameclass);
						//关闭加成框
						if (dm->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
}
//自动拒绝悬赏封印
int yys_function::AutoRejectXS(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//拒绝悬赏封印
	if (dm->FindPic(380, 109, 422, 151, _T("协.bmp|享.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
		if (dm->FindPic(614, 361, 668, 416, _T("拒绝.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("拒绝悬赏...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 300, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			if (random_delay(index, gameclass, dm, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
	}
	return 1;
}

//返回庭院
int yys_function::returnYard(long hd,dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	long intX, intY;
	long exitRes1, exitRes2;
	while (true)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//找红叉叉
		exitRes1=dm->FindPic(735, 29, 968, 175, _T("叉.bmp|叉1.bmp|叉2.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1!=-1)
		{
			mouse_click_event(title, intX+5, intY+5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//找返回
		exitRes1 = dm->FindPic(0, 0, 217, 107, _T("返回1.bmp|返回2.bmp|返回3.bmp|返回4.bmp|返回5.bmp|返回6.bmp|返回7.bmp|返回8.bmp|退出.bmp|退出2.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1 != -1)
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//创建队伍退出 case3：退出邀请面板
		exitRes1 = dm->FindPic(512, 396, 649, 468, _T("邀请.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(303, 397, 448, 465, _T("邀请取消.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//探索退出
		exitRes1= dm->FindPic(299, 271, 457, 337, _T("探索取消.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(505, 274, 656, 334, _T("探索确认.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1!=-1)&&(exitRes2!=-1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//创建队伍退出 case1：取消创建队伍
		exitRes1 = dm->FindPic(598, 406, 714, 481, _T("创建.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(239, 408, 363, 481, _T("取消.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//创建队伍退出 case2：退出组队面板
		exitRes1 = dm->FindPic(312, 289, 466, 360, _T("退队取消.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(488, 293, 644, 356, _T("确定.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
		if (IsInYard(dm,gameclass,index))
		{
			print_log(_T("成功返回庭院！\r\n"), gameclass);
			break;
		}
	}
	return 1;
}
/*
 *				【七绝·敲代码】
 *			夜半千行鬼画符，未成一字亦难读。
 *		    男儿熬作秃头盖，女子娇容岁月枯。
 *
 */