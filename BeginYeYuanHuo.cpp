#include "pch.h"
#include "BeginYeYuanHuo.h"
#define EXIT_THREAD -10
//春风得意马蹄疾，一日看尽长安花。
extern bool readyFlag;
//选层
int BeginYeYuanHuo::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//获取目标位置
	CString bmp_pic = _T("贪之阵.bmp|嗔之阵.bmp|痴之阵.bmp");
	//start 选择层
	print_log(_T("选择业原火贪|嗔|痴...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("贪之阵.bmp|贪之阵(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("嗔之阵.bmp|嗔之阵(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("痴之阵.bmp|痴之阵(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//寻副本
int BeginYeYuanHuo::FindYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index) {
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
		//点击自动匹配
		if (dm->FindPic(111, 456, 193, 537, _T("探索御魂.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+10, intY+20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点业原火
		if (dm->FindPic(308, 80, 381, 224, _T("单刷业原火.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	
	return 1;
}
//锁定阵容
int BeginYeYuanHuo::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
	while (i>0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(411, 415, 452, 454, _T("解锁阵容.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("锁定阵容...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+13, intY+13);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (dm->FindPic(411, 415, 452, 454, _T("阵容锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//进入副本
int BeginYeYuanHuo::EnterYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(824, 437, 902, 505, _T("挑战业原火.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("点击挑战...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 10, 20);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
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
		if (dm->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (dm->FindPic(421, 289, 538, 350, _T("满御魂确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//开始
int BeginYeYuanHuo::StartYeYuanHuo(long hd, int round, int layer,  dmsoft *dm, int gameclass, int index) {
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
	//寻业原火
	if(FindYeYuanHuo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("未找到目标!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }

		//进入业原火副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮业原火开始...\r\n"), gameclass);
		if(EnterYeYuanHuo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//刷完退出
	if (count >= round)
	{
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}

	return 1;
}
