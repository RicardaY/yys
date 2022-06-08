#include "pch.h"
#include "BeginYongShengZhiHai.h"
#define EXIT_THREAD -10
//慢品人间烟火色，闲观万事岁月长。
extern bool readyFlag;

int BeginYongShengZhiHai::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_pic = _T("壹层.bmp|贰层.bmp|叁层.bmp|肆层.bmp");

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start 选择层
	print_log(_T("选择永生之海层数...\r\n"), gameclass);
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
	default:
		return 0;
	}
	return 1;
}

//创建队伍---点击邀请
int BeginYongShengZhiHai::CreatYszhTeamToInvite(long hd, dmsoft *dm, int gameclass, int index) {
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
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(555, 361, 592, 398, _T("不公开(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("权限不公开...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
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
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(630, 187, 691, 248, _T("永生之海加.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("邀请好友...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 10);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if (dm->FindPic(235, 184, 296, 246, _T("永生之海加.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (dm->FindPic(444, 197, 520, 279, _T("切换位置.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("切换位置...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 12, intY + 10);
				if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//点击最近组队
	i = 20;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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

//检测好友进入队伍点挑战 
int BeginYongShengZhiHai::InnerIsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index) {
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
		if (dm->FindPic(860, 429, 946, 510, _T("永生之海挑战.bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1)
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
	}
	return 1;
}

//单刷选层
int BeginYongShengZhiHai::SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
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
	CString bmp_pic = _T("永生壹层.bmp|永生贰层.bmp|永生叁层.bmp|永生肆层.bmp");
	//start 选择层
	print_log(_T("选择永生之海...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("永生壹层.bmp|永生壹层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("永生贰层.bmp|永生贰层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("永生叁层.bmp|永生叁层(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("永生肆层.bmp|永生肆层(选中).bmp"), startXY, endXY, dm, gameclass, index))
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
int BeginYongShengZhiHai::FindYongShengZhiHai(long hd, dmsoft *dm, int gameclass, int index) {
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
		//点击御魂
		if (dm->FindPic(111, 456, 193, 537, _T("探索御魂.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点日轮之陨
		if (dm->FindPic(857, 79, 919, 234, _T("单刷永生之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
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
int BeginYongShengZhiHai::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
int BeginYongShengZhiHai::EnterYongShengZhiHai(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(824, 437, 902, 505, _T("单刷永生挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
//开始单刷
int BeginYongShengZhiHai::SingleYongShengZhiHai(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//寻永生之海
	if(FindYongShengZhiHai(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultSingleChoose = SingleChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultSingleChoose == 0) {
		print_log(_T("未找到目标!!!\r\n"), gameclass);
		return 0;
	}else if(resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
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
		print_log(_T("第" + count_str + "轮永生之海开始...\r\n"), gameclass);
		if(EnterYongShengZhiHai(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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

//庭院邀请好友模式
int BeginYongShengZhiHai::inviteYongShengZhiHai(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//选择永生之海

	//获取目标位置
	CString bmp_pic = _T("探索(困难).bmp|觉醒业火轮.bmp|觉醒风转符.bmp|觉醒水灵鲤.bmp|觉醒天雷鼓.bmp|御魂.bmp|日轮之陨.bmp|永生之海.bmp|妖气封印.bmp|经验妖怪.bmp|金币妖怪.bmp|年兽.bmp|结界突破.bmp");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//找到御魂并点击
	findDestination(hd, bmp_pic, 7, _T("永生之海.bmp|永生之海(选中).bmp"), startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("未找到目标层数!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	int resultCreat = CreatYszhTeamToInvite(hd, dm, gameclass, index);
	if (resultCreat == 0) {
		print_log(_T("创建队伍失败!!!\r\n"), gameclass);
		return 0;
	}else if(resultCreat == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }

	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if(InnerIsEnterTeam(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入永生之海副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮永生之海开始...\r\n"), gameclass);
		if (InviteEnterEvent(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }

		if (count == 0)
		{
			if (DefalutInvite(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
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
//庭院接受邀请模式
int BeginYongShengZhiHai::BeinvitedYongShengZhiHai(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入八岐大蛇副本
		print_log(_T("等待好友邀请...\r\n"), gameclass);
		if (ReceiveEnterEvent(hd, dm, count, _T("永生之海"), gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
