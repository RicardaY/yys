#include "pch.h"
#include "BeginYuLing.h"
#define EXIT_THREAD -10

extern bool readyFlag;
//选层
int BeginYuLing::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
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
	CString bmp_pic = _T("御灵壹层.bmp|御灵贰层.bmp|御灵叁层.bmp");
	//start 选择层
	print_log(_T("选择御灵层数...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("御灵壹层.bmp|御灵壹层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("御灵贰层.bmp|御灵贰层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("御灵叁层.bmp|御灵叁层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//抽象出选择哪只御灵方法，方便调用
int BeginYuLing::WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic[2], int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 15;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	long intX, intY;
	while (i>0)
	{	
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//开启了
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[0], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			return 1;
		}//未开启
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[1], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			return 0;
		}
		if (random_delay(index, gameclass, dm, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//选打哪个
int BeginYuLing::ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 15;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//定义一些变量
	CPoint startXY, endXY;
	CString source_pic[2];
	switch (monster_kind)
	{
	//神龙  96,360,146,485,
	case 0: {
		startXY.x = 96, startXY.y = 360;
		endXY.x = 146, endXY.y = 485;
		source_pic[0] = _T("暗神龙.bmp"), source_pic[1] = _T("暗神龙(未开启).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("选择暗神龙...\r\n"), gameclass);
			break;
		}else if(resultToSelect == 0){ return 0; }
		else if(resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//白藏主
	case 1: {
		startXY.x = 316, startXY.y = 319;
		endXY.x = 364, endXY.y = 479;
		source_pic[0] = _T("暗白藏主.bmp"), source_pic[1] = _T("暗白藏主(未开启).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("选择暗白藏主...\r\n"), gameclass);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//黑豹 526,356,587,486,
	case 2: {
		startXY.x = 526, startXY.y = 356;
		endXY.x = 587, endXY.y = 486;
		source_pic[0] = _T("暗黑豹.bmp"), source_pic[1] = _T("暗黑豹(未开启).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("选择暗黑豹...\r\n"), gameclass);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//孔雀  750,358,801,483
	case 3: {
		startXY.x = 750, startXY.y = 358;
		endXY.x = 801, endXY.y = 483;
		source_pic[0] = _T("暗孔雀.bmp"), source_pic[1] = _T("暗孔雀(未开启).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("选择暗孔雀...\r\n"), gameclass);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}
	default:
		break;
	}
	return 1;
}

//寻副本
int BeginYuLing::FindYuLing(long hd, dmsoft *dm, int gameclass, int index) {
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
		//点击御灵
		if (dm->FindPic(273, 460, 352, 537, _T("探索御灵.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//锁定阵容
int BeginYuLing::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(411, 415, 452, 454, _T("御灵解锁阵容.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("锁定阵容...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 13, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (dm->FindPic(411, 415, 452, 454, _T("御灵阵容锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//进入副本
int BeginYuLing::EnterYuLing(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(824, 437, 902, 505, _T("挑战御灵.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
		if (dm->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("挑战失败\r\n"), gameclass);
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
int BeginYuLing::StartYuLing(long hd, int round, int monster_kind, int layer, dmsoft *dm, int gameclass, int index) {
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
	//寻御灵
	if(FindYuLing(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//选打哪个
	if (!ChooseMonster(hd, dm, monster_kind, gameclass, index)) {
		print_log(_T("此御灵今日可能未开启！\r\n"), gameclass);
		print_log(_T("正在返回庭院...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	//选层点击
	CPoint startXY, endXY;
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("未找到目标!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
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

		//进入御灵副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮御灵开始...\r\n"), gameclass);
		if(EnterYuLing(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
