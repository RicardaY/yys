#include "pch.h"
#include "BeginChangeYuHun.h"

#define EXIT_THREAD -10
//莫愁前路无知己，天下谁人不识君。——唐高适《别董大》
//选择分组
int BeginChangeYuHun::SelectGroup(long hd, dmsoft *dm, CPoint clickXY, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	if (dm->FindPic(540, 56, 647, 105, _T("队伍预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		CPoint posx = random_pos(clickXY.x, clickXY.y, -20, 20);
		CPoint posy = random_pos(clickXY.x, clickXY.y, -10, 10);
		mouse_click_event(title, posx.x, posy.y);
		if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, posx.x, posy.y);
		if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//预设御魂  
int BeginChangeYuHun::StartChangeYuHun(long hd, dmsoft *dm, int group, int team, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	if (team == 0) {
		return 0;
	}
	//设置字库
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	long intX, intY;
	CPoint clickXY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	CString team_str;
	team_str.Format(_T("更换%d.bmp"), team);
	print_log(_T("正在更换御魂预设...\r\n"), gameclass);
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
	//点击式神录
	print_log(_T("点击式神录...\r\n"), gameclass);
	while (1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindStrFast(812, 425, 903, 512, _T("式神录"), _T("BFB7AD-252828"), 0.9, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY - 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(812, 425, 903, 512, _T("式神录(透明).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY - 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击预设
	print_log(_T("点击预设...\r\n"), gameclass);
	while (1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(540, 56, 647, 105, _T("队伍预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击分组group
	print_log(_T("选择预设分组...\r\n"), gameclass);
	switch (group)
	{
	case 0: {//877，87
		clickXY.x = 877, clickXY.y = 87;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 1: {
		clickXY.x = 877, clickXY.y = 140;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 2: {
		clickXY.x = 877, clickXY.y = 194;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 3: {
		clickXY.x = 877, clickXY.y = 246;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 4: {
		clickXY.x = 877, clickXY.y = 300;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 5: {
		clickXY.x = 877, clickXY.y = 352;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 6: {
		clickXY.x = 877, clickXY.y = 404;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	default:
		break;
	}
	
	//点击队伍team
	print_log(_T("选择预设队伍...\r\n"), gameclass);
	int i = 3;
	while (i>0) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(722, 101, 765, 481, team_str, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(504, 297, 635, 345, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//退出式神录  是否庭院界面？return:继续判断
	print_log(_T("预设完成，退出式神录...\r\n"), gameclass);
	while (1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(12, 1, 55, 40, _T("返回8.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (IsInYard(dm, gameclass, index)) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//预设两组御魂
int BeginChangeYuHun::StartChangeYuHunDouble(long hd, dmsoft *dm, int group, int team1, int team2, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	if ((team1 == 0) && (team2 == 0)) {
		return 0;
	}
	long intX, intY;
	CPoint clickXY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	CString team1_str, team2_str;
	team1_str.Format(_T("更换%d.bmp"), team1);
	team2_str.Format(_T("更换%d.bmp"), team2);
	print_log(_T("正在更换御魂预设...\r\n"), gameclass);
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
	//点击式神录
	print_log(_T("点击式神录...\r\n"), gameclass);
	while (1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(812, 425, 903, 512, _T("式神录1.bmp|式神录2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击预设
	print_log(_T("点击预设...\r\n"), gameclass);
	while (1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(540, 56, 647, 105, _T("队伍预设.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击分组group
	print_log(_T("选择预设分组...\r\n"), gameclass);
	switch (group)
	{
	case 0: {//877，87
		clickXY.x = 877, clickXY.y = 87;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 1: {
		clickXY.x = 877, clickXY.y = 140;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 2: {
		clickXY.x = 877, clickXY.y = 194;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 3: {
		clickXY.x = 877, clickXY.y = 246;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 4: {
		clickXY.x = 877, clickXY.y = 300;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 5: {
		clickXY.x = 877, clickXY.y = 352;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	case 6: {
		clickXY.x = 877, clickXY.y = 404;
		SelectGroup(hd, dm, clickXY, gameclass, index);
		break;
	}
	default:
		break;
	}

	//点击队伍team
	print_log(_T("选择预设队伍...\r\n"), gameclass);
	int i = 3;
	int teamFlag1 = 0, teamFlag2 = 0;
	while (i > 0) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(722, 101, 765, 481, team1_str, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			teamFlag1++;
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(722, 101, 765, 481, team2_str, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			teamFlag2++;
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(504, 297, 635, 345, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			if ((teamFlag1 == 1)&&(teamFlag2 == 1)) {
				break;
			}
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//退出式神录  是否庭院界面？return:继续判断
	print_log(_T("预设完成，退出式神录...\r\n"), gameclass);
	while (1) {
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(12, 1, 55, 40, _T("返回8.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (IsInYard(dm, gameclass, index)) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
