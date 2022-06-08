#include "pch.h"
#include "BeginTuPo.h"
#define EXIT_THREAD -10
//高山仰止,景行行止.虽不能至,心向往之。
extern bool readyFlag;
//寻副本
int BeginTuPo::FindTuPo(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int i = 20;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i>0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//结界突破
		if (dm->FindPic(198, 460, 268, 538, _T("探索结界突破.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 20, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}

	return 1;
}
//刷新规则
int BeginTuPo::ReFreshRule(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int Rule[9] = {0,0,0,0,0,0,0,0,0};
	//判断失败与击败  1
	if ((dm->FindPic(105, 106, 141, 130, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) ||((dm->FindPic(105, 106, 134, 127, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(317, 110, 349, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[0] = 1;
	} //2
	if ((dm->FindPic(358, 106, 394, 130, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(353, 105, 383, 130, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(572, 110, 598, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[1] = 1;
	}//3
	if ((dm->FindPic(607, 106, 643, 130, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(603, 104, 634, 129, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(817, 110, 850, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[2] = 1;
	}//4
	if ((dm->FindPic(107, 208, 143, 232, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(105, 207, 137, 228, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(317, 210, 349, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[3] = 1;
	}//5
	if ((dm->FindPic(358, 208, 394, 232, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(355, 209, 384, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(568, 210, 601, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[4] = 1;
	}//6
	if ((dm->FindPic(607, 208, 643, 232, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(604, 207, 638, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(817, 210, 850, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[5] = 1;
	}//7
	if ((dm->FindPic(109, 309, 145, 333, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(105, 310, 137, 332, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(317, 312, 349, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[6] = 1;
	}//8
	if ((dm->FindPic(359, 309, 394, 333, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(356, 309, 386, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(567, 312, 600, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[7] = 1;
	}//9
	if ((dm->FindPic(607, 309, 643, 333, _T("突破(击败).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(602, 311, 636, 330, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(817, 312, 850, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[8] = 1;
	}
	for (int i = 0; i < 9; i++) {
		if (Rule[i] == 0) { return 0; }
	}
	return 1;
}
//刷新副本&&退四
int BeginTuPo::ReFresh(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int i = 10;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i > 0) 
	{
		if (dm->FindPic(721, 426, 851, 473, _T("刷新.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("刷新...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(506, 303, 632, 344, _T("确定.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 10, intY + 10);
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				if(ExitFour(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				return 1;
			}
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//锁定阵容
int BeginTuPo::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int i = 10;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(609, 433, 646, 468, _T("结突解锁阵容.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("锁定阵容...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 13, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (dm->FindPic(609, 433, 646, 468, _T("结突阵容锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//进入副本
int BeginTuPo::ReadyToFinish(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (readyFlag && (dm->FindPic(838, 405, 935, 474, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			print_log(_T("点击准备...\r\n"), gameclass);
			CPoint pos = random_pos(intX, intY, 1, 3);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(233, 60, 536, 253, _T("胜利.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("战斗结算中...\r\n"), gameclass);
			CPoint pos = random_pos(798, 429, 5, 10);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			count++;
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (dm->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("挑战失败，不计次数...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
	}
	return count;
}
//判断是否有突破券
int BeginTuPo::isHaveTicket(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int i = 3;
	while (i > 0) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((dm->FindPic(867, 6, 886, 37, _T("突破券0.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(858, 2, 885, 37, _T("突破券10.bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1)) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//退出突破操作：返回-->确定-->失败
int BeginTuPo::ExitDo(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int flag = 0;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1) {
		//退出位置 0, 0, 56, 58
		if ((flag==0)&&(dm->FindPic(0, 0, 56, 58, _T("退出(透明).bmp|退出1.bmp|退出.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			if (random_delay(index, gameclass, dm, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(506, 293, 606, 344, _T("满御魂确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			flag = 1;
		}
		if (dm->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//退出条件  418,49,529,92,
		if (dm->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
	}
	
	return 1;
}
//退四
int BeginTuPo::ExitFour(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//坐标定义
	CPoint startXY, endXY;
	int exitFlag = 0;
	CString exitFlag_str;
	//退四
	while (1) {
		if (!isHaveTicket(hd, dm, gameclass, index)) {
			break;
		}//第一行第一个  ,
		if ((dm->FindPic(317, 110, 349, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 240, startXY.y = 267;
			endXY.x = 339, endXY.y = 310;
			//点击进攻
			if(SelectAttack(hd, startXY, endXY, _T("进攻1.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//退一
			exitFlag_str.Format(_T("%d"),exitFlag+1);
			print_log(_T("退出第"+exitFlag_str+"次...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}//第一行第二个  
		else if ((dm->FindPic(572, 110, 598, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 491, startXY.y = 267;
			endXY.x = 590, endXY.y = 310;
			//点击进攻
			if(SelectAttack(hd, startXY, endXY, _T("进攻2.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//退二
			exitFlag_str.Format(_T("%d"), exitFlag + 1);
			print_log(_T("退出第" + exitFlag_str + "次...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}//第一行第三个  
		else if ((dm->FindPic(817, 110, 850, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 267;
			endXY.x = 834, endXY.y = 310;
			//点击进攻
			if(SelectAttack(hd, startXY, endXY, _T("进攻3.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//退三
			exitFlag_str.Format(_T("%d"), exitFlag + 1);
			print_log(_T("退出第" + exitFlag_str + "次...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}//第二行第一个  
		else if ((dm->FindPic(317, 210, 349, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 242, startXY.y = 370;
			endXY.x = 336, endXY.y = 413;
			//点击进攻
			if(SelectAttack(hd, startXY, endXY, _T("进攻4.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//退四
			exitFlag_str.Format(_T("%d"), exitFlag + 1);
			print_log(_T("退出第" + exitFlag_str + "次...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}
		if (exitFlag == 4) {
			break;
		}
		
	}
	return 1;
}
//点击进攻
int BeginTuPo::SelectAttack(long hd, CPoint startXY, CPoint endXY, CString attackImg, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start Attack
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y,attackImg, _T("202020"), 0.95, 0, &intX, &intY) != -1) {
			print_log(_T("进攻...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+10, intY + 10);
			if (random_delay(index, gameclass, dm, 4000, 5000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(0, 0, 56, 58, _T("退出(透明).bmp|退出1.bmp|退出.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//领取下方宝箱
int BeginTuPo::CheckReward(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int i = 20;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i>0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		i--;
		if (random_delay(index, gameclass, dm, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//开始
int BeginTuPo::StartTuPo(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//初始化准备标志
	readyFlag = TRUE;
	//判断是否在庭院
	if (!IsInYard(dm, gameclass, index))
	{
		print_log(_T("请确保在庭院界面!!!\r\n"), gameclass);
		return 0;
	}
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(hd, dm, gameclass, index);
	if (result == 0) {
		print_log(_T("在庭院界面，但未找到探索灯笼!!!\r\n"), gameclass);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻突破
	if (FindTuPo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	
	//锁定阵容
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//坐标定义
	CPoint startXY, endXY;
	//次数与标志位
	int count = 0, flag=0;
	CString count_str;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		//start
		//判断是否有券    突破卷10:858,2,885,37
		int resultTicket = isHaveTicket(hd, dm, gameclass, index);
		if (resultTicket == 0) {
			flag = 1;
			print_log(_T("没有突破券...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if(resultTicket == EXIT_THREAD) { return EXIT_THREAD; }
		//每三把领一次的奖励
		if (dm->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第一行第一个
		if ((dm->FindPic(317, 110, 349, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&isHaveTicket(hd,dm,gameclass,index)) {
			print_log(_T("点击第一行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 240, startXY.y = 267;
			endXY.x = 339, endXY.y = 310;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻1.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if(count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第一行第二个
		else if ((dm->FindPic(572, 110, 598, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 491, startXY.y = 267;
			endXY.x = 590, endXY.y = 310;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻2.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第一行第三个
		else if ((dm->FindPic(817, 110, 850, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 267;
			endXY.x = 834, endXY.y = 310;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻3.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第二行第一个
		else if ((dm->FindPic(317, 210, 349, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 242, startXY.y = 370;
			endXY.x = 336, endXY.y = 413;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻4.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第二行第二个
		else if ((dm->FindPic(568, 210, 601, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 490, startXY.y = 370;
			endXY.x = 587, endXY.y = 413;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻5.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第二行第三个
		else if ((dm->FindPic(817, 210, 850, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 370;
			endXY.x = 836, endXY.y = 413;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻6.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第三行第一个
		else if ((dm->FindPic(317, 312, 349, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第三行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 240, startXY.y = 470;
			endXY.x = 338, endXY.y = 515;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻7.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第三行第二个
		else if ((dm->FindPic(567, 312, 600, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第三行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 491, startXY.y = 470;
			endXY.x = 586, endXY.y = 515;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻8.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//第三行第三个
		else if ((dm->FindPic(817, 312, 850, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第三行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 470;
			endXY.x = 836, endXY.y = 515;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻9.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((dm->FindPic(721, 426, 851, 473, _T("刷新.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&ReFreshRule(hd,dm,gameclass,index))
		{
			print_log(_T("当前没有剩余突破，点击刷新...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(506, 303, 632, 344, _T("确定.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 10, intY + 10);
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}

		//判断是否有券    突破卷10:858,2,885,37
		resultTicket = isHaveTicket(hd, dm, gameclass, index);
		if (resultTicket == 0) {
			flag = 1;
			print_log(_T("没有突破券...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if(resultTicket == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round||flag==1)
	{
		if(CheckReward(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1200, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (TupoReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}

	return 1;
}
//退四打九
int BeginTuPo::StartTuPoByExitFourAttackNine(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//初始化准备标志
	readyFlag = TRUE;
	//判断是否在庭院
	if (!IsInYard(dm, gameclass, index))
	{
		print_log(_T("请确保在庭院界面!!!\r\n"), gameclass);
		return 0;
	}
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(hd, dm, gameclass, index);
	if (result == 0) {
		print_log(_T("在庭院界面，但未找到探索灯笼!!!\r\n"), gameclass);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻突破
	if (FindTuPo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	//锁定阵容
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//循环开始
	//定义局部变量
	long intX, intY;
	//记录进入每一副本次数的数组
	int enterNum[9] = {0,0,0,0,0,0,0,0,0};
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//坐标定义
	CPoint startXY, endXY;
	//次数与标志位
	int count = 0, flag = 0;
	CString count_str;
	//退四打九模式需要打之前刷新一下消除影响-->退四在刷新内执行
	int resultReFresh = ReFresh(hd, dm, gameclass, index);
	if (resultReFresh == 0) {
		print_log(_T("请确保刷新按钮未在冷却中！\r\n"), gameclass);
		return 0;
	}else if(resultReFresh == EXIT_THREAD) { return EXIT_THREAD; }
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		//start
		//判断是否有券    突破卷10:858,2,885,37
		if (!isHaveTicket(hd, dm, gameclass, index)) {
			flag = 1;
			print_log(_T("没有突破券...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		
		//每三把领一次的奖励
		if (dm->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (isHaveTicket(hd, dm, gameclass, index)&&((dm->FindPic(317, 110, 349, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)|| dm->FindPic(572, 110, 598, 133, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)) {
			int resultExitFour = ExitFour(hd, dm, gameclass, index);
			if(resultExitFour == EXIT_THREAD) { return EXIT_THREAD; }
			else if (resultExitFour == 1) {
				for (int i = 0; i < 9; i++) {
					enterNum[i] = 0;
				}
			}
		}
		//第一行第一个
		if ((enterNum[0]<3)&&(dm->FindPic(105, 106, 134, 127, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 240, startXY.y = 267;
			endXY.x = 339, endXY.y = 310;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻1.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[0]+=1;
		}
		//第一行第二个
		else if ((enterNum[1] < 3) && (dm->FindPic(353, 105, 383, 130, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 491, startXY.y = 267;
			endXY.x = 590, endXY.y = 310;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻2.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[1] += 1;
		}
		//第一行第三个
		else if ((enterNum[2] < 3) && (dm->FindPic(603, 104, 634, 129, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第一行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 267;
			endXY.x = 834, endXY.y = 310;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻3.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[2] += 1;
		}
		//第二行第一个
		else if ((enterNum[3] < 3) && (dm->FindPic(105, 207, 137, 228, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 242, startXY.y = 370;
			endXY.x = 336, endXY.y = 413;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻4.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[3] += 1;
		}
		//第二行第二个
		else if ((enterNum[4] < 3) && (dm->FindPic(355, 209, 384, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 490, startXY.y = 370;
			endXY.x = 587, endXY.y = 413;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻5.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[4] += 1;
		}
		//第二行第三个
		else if ((enterNum[5] < 3) && (dm->FindPic(604, 207, 638, 231, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第二行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 370;
			endXY.x = 836, endXY.y = 413;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻6.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[5] += 1;
		}
		//第三行第一个
		else if ((enterNum[6] < 3) && (dm->FindPic(105, 310, 137, 332, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第三行第一个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 240, startXY.y = 470;
			endXY.x = 338, endXY.y = 515;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻7.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[6] += 1;
		}
		//第三行第二个
		else if ((enterNum[7] < 3) && (dm->FindPic(356, 309, 386, 331, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第三行第二个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 491, startXY.y = 470;
			endXY.x = 586, endXY.y = 515;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻8.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[7] += 1;
		}
		//第三行第三个
		else if ((enterNum[8] < 3) && (dm->FindPic(602, 311, 636, 330, _T("突破(未挑战).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("点击第三行第三个...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//进攻按钮位置范围
			startXY.x = 739, startXY.y = 470;
			endXY.x = 836, endXY.y = 515;
			//点击进攻
			print_log(_T("第" + count_str + "轮突破开始...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("进攻9.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[8] += 1;
		}
		else if ((dm->FindPic(721, 426, 851, 473, _T("刷新.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&ReFreshRule(hd, dm, gameclass, index)){
		print_log(_T("当前没有剩余突破，点击\r\n"), gameclass);
		if(ReFresh(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			for (int i = 0; i < 9; i++) {
				enterNum[i] = 0;
			}
			if (random_delay(index, gameclass, dm, 2800, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		//判断是否有券    突破卷10:858,2,885,37
		int resultTicket = isHaveTicket(hd, dm, gameclass, index);
		if (resultTicket == 0) {
			flag = 1;
			print_log(_T("没有突破券...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if(resultTicket == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round || flag == 1)
	{
		if(CheckReward(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1200, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (TupoReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}
	return 1;
}
//返回庭院
int BeginTuPo::TupoReturnYard(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//开始返回
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(861, 59, 948, 139, _T("叉1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(14, 17, 67, 71, _T("返回1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsInYard(dm, gameclass, index))
		{
			print_log(_T("成功返回庭院！\r\n"), gameclass);
			break;
		}
	}
	return 1;
}

