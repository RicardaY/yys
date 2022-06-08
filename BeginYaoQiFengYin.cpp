#include "pch.h"
#include "BeginYaoQiFengYin.h"
#define EXIT_THREAD -10

//选层	博观而约取，厚积而薄发。
int BeginYaoQiFengYin::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_pic = _T("跳跳哥哥.bmp|椒图.bmp|骨女.bmp|饿鬼.bmp|二口女.bmp|海坊主.bmp|鬼使黑.bmp|小松丸.bmp|日和坊.bmp");

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start 选择层
	print_log(_T("选择妖气封印妖怪...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("跳跳哥哥.bmp|跳跳哥哥(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("椒图.bmp|椒图(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("骨女.bmp|骨女(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("饿鬼.bmp|饿鬼(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("二口女.bmp|二口女(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("海坊主.bmp|海坊主(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("鬼使黑.bmp|鬼使黑(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("小松丸.bmp|小松丸(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("日和坊.bmp|日和坊(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
int BeginYaoQiFengYin::EnterYaoQiFengYin(long hd, int condition, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//自动匹配
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//点击组队
		if (dm->FindPic(262, 444, 323, 510, _T("组队.bmp|灰色组队.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("点击组队...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
		}
		//点击自动匹配
		if (dm->FindPic(517, 443, 665, 495, _T("自动匹配.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("排队中...\r\n"), gameclass);
		}
		//若自己成为房主，点挑战
		if (dm->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (condition==0) {
				print_log(_T("自己成为房主，点击挑战...\r\n"), gameclass);
				//随机偏移坐标防检测
				CPoint pos = random_pos(intX, intY, 5, 10);
				if (random_delay(index, gameclass, dm, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (condition == 1) {
				print_log(_T("成为房主，正在退出返回庭院...\r\n"), gameclass);
				if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		//点准备
		if (dm->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
//开始
int BeginYaoQiFengYin::StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	
	//判断是否在庭院
	if (!IsInYard(dm, gameclass, index))
	{
		print_log(_T("请确保在庭院界面!!!\r\n"), gameclass);
		return 0;
	}
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//退出线程
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(hd, dm, gameclass, index);
	if (resultCombine == 0) {
		print_log(_T("很抱歉，未找到组队按钮...\r\n"), gameclass);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择妖气封印

	//获取目标位置
	CString bmp_pic = _T("探索(困难).bmp|觉醒业火轮.bmp|觉醒风转符.bmp|觉醒水灵鲤.bmp|觉醒天雷鼓.bmp|御魂.bmp|日轮之陨.bmp|永生之海.bmp|妖气封印.bmp|经验妖怪.bmp|金币妖怪.bmp|年兽.bmp|结界突破.bmp");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//找到妖气封印并点击
	findDestination(hd, bmp_pic, 8, _T("妖气封印.bmp|妖气封印(选中).bmp"), startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(hd, monsterKind, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("未找到目标!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		
		//进入妖气封印副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮妖气封印开始...\r\n"), gameclass);
		if(EnterYaoQiFengYin(hd, condition, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
