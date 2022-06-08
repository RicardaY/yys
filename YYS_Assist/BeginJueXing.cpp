#include "pch.h"
#include "BeginJueXing.h"

#define EXIT_THREAD -10

extern bool readyFlag;
//选层
int BeginJueXing::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_pic = _T("壹层.bmp|贰层.bmp|叁层.bmp|肆层.bmp|伍层.bmp|陆层.bmp|柒层.bmp|捌层.bmp|玖层.bmp|拾层.bmp");

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start 选择层
	print_log(_T("选择觉醒层数...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("壹层.bmp|壹层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("贰层.bmp|贰层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("叁层.bmp|叁层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("肆层.bmp|肆层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("伍层.bmp|伍层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("陆层.bmp|陆层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("柒层.bmp|柒层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("捌层.bmp|捌层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("玖层.bmp|玖层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("拾层.bmp|拾层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//单刷选择层数
int BeginJueXing::SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_pic = _T("单刷觉醒壹层.bmp|单刷觉醒贰层.bmp|单刷觉醒叁层.bmp|单刷觉醒肆层.bmp|单刷觉醒伍层.bmp|单刷觉醒陆层.bmp|单刷觉醒柒层.bmp|单刷觉醒捌层.bmp|单刷觉醒玖层.bmp|单刷觉醒拾层.bmp");

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start 选择层
	print_log(_T("选择觉醒层数...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒壹层.bmp|单刷觉醒壹层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒贰层.bmp|单刷觉醒贰层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒叁层.bmp|单刷觉醒叁层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒肆层.bmp|单刷觉醒肆层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒伍层.bmp|单刷觉醒伍层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒陆层.bmp|单刷觉醒陆层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒柒层.bmp|单刷觉醒柒层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒捌层.bmp|单刷觉醒捌层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒玖层.bmp|单刷觉醒玖层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("单刷觉醒拾层.bmp|单刷觉醒拾层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//抽象出选择哪只麒麟方法，方便调用
int BeginJueXing::WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 15;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	long intX, intY;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//开启了
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic, _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			return 1;
		}
		if (random_delay(index, gameclass, dm, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//选打哪个
int BeginJueXing::ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index) {
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
	CString source_pic;
	switch (monster_kind)
	{
		//火  54,275,101,393,
	case 0: {
		startXY.x = 54, startXY.y = 275;
		endXY.x = 101, endXY.y = 393;
		source_pic = _T("火麒麟.bmp");
		print_log(_T("选择火麒麟...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1){ break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if(resultSelect == 0){ return 0; }
	}//风 279,281,329,396,
	case 1: {
		startXY.x = 279, startXY.y = 281;
		endXY.x = 329, endXY.y = 396;
		source_pic = _T("风麒麟.bmp");
		print_log(_T("选择风麒麟...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultSelect == 0) { return 0; }
	}//水  501,279,552,394,
	case 2: {
		startXY.x = 501, startXY.y = 279;
		endXY.x = 552, endXY.y = 394;
		source_pic = _T("水麒麟.bmp");
		print_log(_T("选择水麒麟...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultSelect == 0) { return 0; }
	}//雷 728,269,770,390,
	case 3: {
		startXY.x = 728, startXY.y = 269;
		endXY.x = 770, endXY.y = 390;
		source_pic = _T("雷麒麟.bmp");
		print_log(_T("选择雷麒麟...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultSelect == 0) { return 0; }
	}
	default:
		break;
	}
	return 1;
}

//寻副本
int BeginJueXing::FindJueXing(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(25, 453, 109, 537, _T("觉醒材料.bmp|觉醒材料2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
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
int BeginJueXing::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(411, 415, 452, 454, _T("解锁阵容.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("锁定阵容...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 13, intY + 13);
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
int BeginJueXing::EnterJueXing(long hd, dmsoft *dm, int gameclass, int index) {
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

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//庭院邀请好友模式
int BeginJueXing::inviteJueXing(long hd, int round, int mode, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//判断庭院是否展开,若未展开使之展开
	if (showYard(dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(hd, dm, gameclass, index);
	if (resultCombine == 0) {
		print_log(_T("很抱歉，未找到组队按钮...\r\n"), gameclass);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择御魂

	//获取目标位置
	CString bmp_pic = _T("探索(困难).bmp|觉醒业火轮.bmp|觉醒风转符.bmp|觉醒水灵鲤.bmp|觉醒天雷鼓.bmp|御魂.bmp|日轮之陨.bmp|永生之海.bmp|妖气封印.bmp|经验妖怪.bmp|金币妖怪.bmp|年兽.bmp|结界突破.bmp");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//找到觉醒并点击
	CString mode_str;
	if (mode==0)
	{
		mode_str = _T("觉醒业火轮.bmp|觉醒业火轮(选中).bmp");
	}else if (mode == 1) {
		mode_str = _T("觉醒风转符.bmp|觉醒风转符(选中).bmp");
	}
	else if (mode == 2) {
		mode_str = _T("觉醒水灵鲤.bmp|觉醒水灵鲤(选中).bmp");
	}
	else if (mode == 3) {
		mode_str = _T("觉醒天雷鼓.bmp|觉醒天雷鼓(选中).bmp");
	}
	findDestination(hd, bmp_pic, mode+1, mode_str, startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("未找到目标层数!!!\r\n"), gameclass);
		return 0;
	}
	else if (resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	int resultCreat = CreatTeamToInvite(hd, dm, gameclass, index);
	if (resultCreat == 0) {
		print_log(_T("创建队伍失败!!!\r\n"), gameclass);
		//未找到最近好友，返回庭院后关闭加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (random_delay(index, gameclass, dm, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}else if(resultCreat == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if (IsEnterTeam(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动开加成
		if (count == 0)
		{
			startXY.x = 82, startXY.y = 479;
			endXY.x = 121, endXY.y = 539;
			if (auto_open_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入觉醒副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮觉醒开始...\r\n"), gameclass);
		if (InviteEnterEvent(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }

		if (count == 0)
		{
			if (DefalutInvite(hd, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
		}
		count++;

	}
	//刷完退出
	if (count >= round)
	{
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//自动关加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//庭院接受邀请模式
int BeginJueXing::BeinvitedJueXing(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入八岐大蛇副本
		print_log(_T("等待好友邀请...\r\n"), gameclass);
		if (ReceiveEnterEvent(hd, dm, count, _T("觉醒"), gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//刷完退出
	if (count >= round)
	{
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//自动关加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//开始单刷
int BeginJueXing::SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(hd, dm, gameclass, index);
	if (result == 0) {
		print_log(_T("在庭院界面，但未找到探索灯笼!!!\r\n"), gameclass);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻觉醒
	if(FindJueXing(hd, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//选打哪个
	int resultChooseMonster = ChooseMonster(hd, dm, monster_kind, gameclass, index);
	if (resultChooseMonster == 0) {
		print_log(_T("未找到麒麟！\r\n"), gameclass);
		return 0;
	}else if(resultChooseMonster == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击 
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultSingleChoose = SingleChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultSingleChoose == 0) {
		print_log(_T("未找到目标!!!\r\n"), gameclass);
		return 0;
	}
	else if (resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }

		//进入觉醒副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮觉醒开始...\r\n"), gameclass);
		if (EnterJueXing(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//刷完退出
	if (count >= round)
	{
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("觉醒"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
/**
 *                      江城子 . 程序员之歌
 *
 *                  十年生死两茫茫，写程序，到天亮。
 *                      千行代码，Bug何处藏。
 *                  纵使上线又怎样，朝令改，夕断肠。
 *
 *                  领导每天新想法，天天改，日日忙。
 *                      相顾无言，惟有泪千行。
 *                  每晚灯火阑珊处，夜难寐，加班狂。
 */