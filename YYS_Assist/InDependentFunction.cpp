#include "pch.h"
#include "InDependentFunction.h"
#define EXIT_THREAD -10

//百鬼夜行
int InDependentFunction::StartBaiGui(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	if (dm->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)
	{
		print_log(_T("请进入百鬼夜行页面...\r\n"), gameclass);
		return 0;
	}
	print_log(_T("默认1000张票，暂时不可更改...\r\n"), gameclass);
	int count = 0;
	while (count < round) {
		//拒绝悬赏
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("进入百鬼夜行...\r\n"), gameclass);
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}//416,3,553,59,
		if (dm->FindPic(416, 3, 553, 59, _T("百鬼夜行.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(442, 69, 521, 441, _T("百鬼押.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				print_log(_T("押式神...\r\n"), gameclass);
				CPoint pos = random_pos(477, 314, 1, 4);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(442, 69, 521, 441, _T("百鬼押.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (dm->FindPic(833, 427, 915, 481, _T("百鬼开始.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					CString count_str;
					count_str.Format(_T("%d"), count + 1);
					print_log(_T("第"+count_str+"轮百鬼夜行开始...\r\n"), gameclass);
					mouse_click_event(title, intX + 10, intY + 5);
					if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (dm->FindPic(44, 473, 101, 514, _T("百鬼豆子.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("开始撒豆...\r\n"), gameclass);
			count++;
			while (1) {
				AutoRejectXS(hd, dm, gameclass, index);
				CPoint posx = random_pos(507, 295, -200, 200);
				CPoint posy = random_pos(507, 295, -5, 5);
				if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, posx.x, posy.y);
				int beanRes = dm->FindPic(34, 468, 134, 515, _T("正常0豆.bmp|冰冻0豆.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				int timeRes = dm->FindPic(448, 1, 508, 50,  _T("时间零.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				while ((beanRes != -1) || (timeRes != -1)) {
					if (dm->FindPic(72, 165, 117, 335, _T("百鬼契约书.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 5);
						if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (dm->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					break;
				}
			}
			//34,468,134,515,  0豆
			//448,1,508,50,    时间零
		}
	}
	if (count >= round) {
		print_log(_T("完成百鬼夜行...\r\n"), gameclass);
		return 1;
	}
}
//新活动
int InDependentFunction::StartNewEvent(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	/*if (dm->FindPic(670, 299, 919, 505, _T("开始巡逻.bmp|战场巡逻.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)
	{
		print_log(_T("请进入活动页面...\r\n"), gameclass);
		return 0;
	}*/
	print_log(_T("开始前请自己锁定阵容...\r\n"), gameclass);
	int count = 0;
	while (count < round) {
		//拒绝悬赏
		AutoRejectXS(hd, dm, gameclass, index);
		/*if (dm->FindPic(670, 299, 707, 423, _T("战场巡逻.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("进入战场巡逻...\r\n"), gameclass);
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(612, 145, 669, 267, _T("战场巡逻1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("进入战场巡逻...\r\n"), gameclass);
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(825, 412, 919, 505, _T("开始巡逻.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("开始巡逻...\r\n"), gameclass);
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}*/
		if (dm->FindPic(0, 0, 960, 540, _T("活动挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			CString count_str;
			count_str.Format(_T("%d"), count + 1);
			print_log(_T("第" + count_str + "轮挑战开始...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("开始挑战...\r\n"), gameclass);
			mouse_click_event(title, intX + 10, intY + 10);
			count++;
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(286, 34, 438, 169, _T("胜利.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("战斗结算中...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 429, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("领取奖励...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	//刷完退出
	if (count >= round)
	{
		print_log(_T("任务已完成.\r\n"), gameclass);
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
/*
					  .::::.
					 .::::::::.
					:::::::::::
				 ..:::::::::::'
			  '::::::::::::'
				.::::::::::
		   '::::::::::::::..
				..::::::::::::.
			  ``::::::::::::::::
			   ::::``:::::::::'        .:::.
			  ::::'   ':::::'       .::::::::.
			.::::'      ::::     .:::::::'::::.
		   .:::'       :::::  .:::::::::' ':::::.
		  .::'        :::::.:::::::::'      ':::::.
		 .::'         ::::::::::::::'         ``::::.
	 ...:::           ::::::::::::'              ``::.
	```` ':.          ':::::::::'                  ::::..
					   '.:::::'                    ':'````..
*/