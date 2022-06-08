#include "pch.h"
#include "BeginExplore.h"
#define EXIT_THREAD -10

extern CString g_path;
int BeginExplore::isExplore(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 3;
	long intX, intY;
	while (i > 0)
	{
		//自动拒绝悬赏
		/**
		 *        山无陵，江水为竭，冬雷震震，夏雨雪。天地合,乃敢与君绝。
		 */
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(749, 81, 823, 142, _T("叉.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			long parentHandle = dm->GetWindow(hd, 0);
			CString title = dm->GetWindowTitle(parentHandle);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		i--;
		if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//选层
int BeginExplore::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_pic = _T("第一章.bmp|第二章.bmp|第三章.bmp|第四章.bmp|第五章.bmp|第六章.bmp|第七章.bmp|第八章.bmp|第九章.bmp|第十章.bmp|第十一章.bmp|第十二章.bmp|第十三章.bmp|第十四章.bmp|第十五章.bmp|第十六章.bmp|第十七章.bmp|第十八章.bmp|第十九章.bmp|第二十章.bmp|第二十一章.bmp|第二十二章.bmp|第二十三章.bmp|第二十四章.bmp|第二十五章.bmp|第二十六章.bmp|第二十七章.bmp|第二十八章.bmp");

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start 选择层
	print_log(_T("选择指定关卡...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("第一章.bmp|第一章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("第二章.bmp|第二章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("第三章.bmp|第三章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("第四章.bmp|第四章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("第五章.bmp|第五章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("第六章.bmp|第六章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("第七章.bmp|第七章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("第八章.bmp|第八章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("第九章.bmp|第九章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("第十章.bmp|第十章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestination(hd, bmp_pic, layer, _T("第十一章.bmp|第十一章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 11: {

		if (findDestination(hd, bmp_pic, layer, _T("第十二章.bmp|第十二章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 12: {

		if (findDestination(hd, bmp_pic, layer, _T("第十三章.bmp|第十三章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 13: {

		if (findDestination(hd, bmp_pic, layer, _T("第十四章.bmp|第十四章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 14: {

		if (findDestination(hd, bmp_pic, layer, _T("第十五章.bmp|第十五章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 15: {

		if (findDestination(hd, bmp_pic, layer, _T("第十六章.bmp|第十六章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 16: {

		if (findDestination(hd, bmp_pic, layer, _T("第十七章.bmp|第十七章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 17: {

		if (findDestination(hd, bmp_pic, layer, _T("第十八章.bmp|第十八章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 18: {

		if (findDestination(hd, bmp_pic, layer, _T("第十九章.bmp|第十九章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 19: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十章.bmp|第二十章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 20: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十一章.bmp|第二十一章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 21: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十二章.bmp|第二十二章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 22: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十三章.bmp|第二十三章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 23: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十四章.bmp|第二十四章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 24: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十五章.bmp|第二十五章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 25: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十六章.bmp|第二十六章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 26: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十七章.bmp|第二十七章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 27: {

		if (findDestination(hd, bmp_pic, layer, _T("第二十八章.bmp|第二十八章(选中).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//单刷选层
int BeginExplore::SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_pic = _T("1.bmp|2.bmp|3.bmp|4.bmp|5.bmp|6.bmp|7.bmp|8.bmp|9.bmp|10.bmp|11.bmp|12.bmp|13.bmp|14.bmp|15.bmp|16.bmp|17.bmp|18.bmp|19.bmp|20.bmp|21.bmp|22.bmp|23.bmp|24.bmp|25.bmp|26.bmp|27.bmp|28.bmp");
	CString bmp_pic2 = _T("1-1.bmp|2-1.bmp|3-1.bmp|4-1.bmp|5-1.bmp|6-1.bmp|7-1.bmp|8-1.bmp|9-1.bmp|10-1.bmp|11-1.bmp|12-1.bmp|13-1.bmp|14-1.bmp|15-1.bmp|16-1.bmp|17-1.bmp|18-1.bmp|19-1.bmp|20-1.bmp|21-1.bmp|22-1.bmp|23-1.bmp|24-1.bmp|25-1.bmp|26-1.bmp|27-1.bmp|28-1.bmp");

	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start 选择层
	print_log(_T("选择指定关卡...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("1.bmp|1-1.bmp"),startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("1.bmp|1-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("2.bmp|2-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("2.bmp|2-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("3.bmp|3-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("3.bmp|3-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("4.bmp|4-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("4.bmp|4-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("5.bmp|5-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("5.bmp|5-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("6.bmp|6-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("6.bmp|6-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("7.bmp|7-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic, layer, _T("7.bmp|7-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("8.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("8.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("9.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("9.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("10.bmp|10-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("10.bmp|10-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestination(hd, bmp_pic, layer, _T("11.bmp|11-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("11.bmp|11-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 11: {

		if (findDestination(hd, bmp_pic, layer, _T("12.bmp|12-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("12.bmp|12-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 12: {

		if (findDestination(hd, bmp_pic, layer, _T("13.bmp|13-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("13.bmp|13-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 13: {

		if (findDestination(hd, bmp_pic, layer, _T("14.bmp|14-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("14.bmp|14-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 14: {

		if (findDestination(hd, bmp_pic, layer, _T("15.bmp|15-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("15.bmp|15-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 15: {

		if (findDestination(hd, bmp_pic, layer, _T("16.bmp|16-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("16.bmp|16-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 16: {

		if (findDestination(hd, bmp_pic, layer, _T("17.bmp|17-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("17.bmp|17-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 17: {

		if (findDestination(hd, bmp_pic, layer, _T("18.bmp|18-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("18.bmp|18-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 18: {

		if (findDestination(hd, bmp_pic, layer, _T("19.bmp|19-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("19.bmp|19-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 19: {

		if (findDestination(hd, bmp_pic, layer, _T("20.bmp|20-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("20.bmp|20-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 20: {

		if (findDestination(hd, bmp_pic, layer, _T("21.bmp|21-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("21.bmp|21-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 21: {

		if (findDestination(hd, bmp_pic, layer, _T("22.bmp|22-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("22.bmp|22-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 22: {

		if (findDestination(hd, bmp_pic, layer, _T("23.bmp|23-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("23.bmp|23-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 23: {

		if (findDestination(hd, bmp_pic, layer, _T("24.bmp|24-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("24.bmp|24-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 24: {

		if (findDestination(hd, bmp_pic, layer, _T("25.bmp|25-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("25.bmp|25-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 25: {

		if (findDestination(hd, bmp_pic, layer, _T("26.bmp|26-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("26.bmp|26-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 26: {

		if (findDestination(hd, bmp_pic, layer, _T("27.bmp|27-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("27.bmp|27-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 27: {

		if (findDestination(hd, bmp_pic, layer, _T("28.bmp|28-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("28.bmp|28-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	print_log(_T("已选择...\r\n"), gameclass);
	return 1;
}
//选择难度
int BeginExplore::ChooseDiff(long hd, int diff, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//选择难度
	long intX, intY;
	int i = 10;
	//普通(未选中) 221,142,283,199,   困难(未选中)  320,142,386,201,
	if (diff)
	{
		while (i > 0)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(221, 142, 283, 199, _T("普通(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("已选择困难难度...\r\n"), gameclass);
				return 1;
			}
			else if (dm->FindPic(320, 142, 386, 201, _T("困难(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				print_log(_T("选择困难难度...\r\n"), gameclass);
				mouse_click_event(title, intX + 16, intY);
				if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			i--;
		}
	}
	else if (!diff)
	{
		while (i > 0)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(320, 142, 386, 201, _T("困难(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("已选择普通难度...\r\n"), gameclass);
				return 1;
			}
			else if (dm->FindPic(221, 142, 283, 199, _T("普通(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				print_log(_T("选择普通难度...\r\n"), gameclass);
				mouse_click_event(title, intX + 16, intY);
				if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			i--;
		}
	}
	return 0;
}

int BeginExplore::clickExplore(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 10;
	long intX, intY;
	long findRes;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = dm->FindPic(642, 367, 773, 438, _T("探索按钮.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	if (findRes != -1)
	{
		//获取父窗口标题
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//点击
		print_log(_T("进入探索副本...\r\n"), gameclass);
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, intX, intY);
		if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		return 1;
	}
	return 0;
}

int BeginExplore::autoRotate(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	long rotateRes;
	int i = 10;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		rotateRes = dm->FindPic(86, 493, 107, 515, _T("自动轮换.bmp|自动轮换1.bmp|自动轮换2.bmp|自动轮换3.bmp"), _T("101010"), 0.95, 0, &intX, &intY);
		if (rotateRes != -1)
		{

			break;
		}
		if (random_delay(index, gameclass, dm, 280, 320) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	if (rotateRes != -1)
	{
		//获取父窗口标题
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//点击
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, intX+1, intY+1);
		if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		return 1;
	}
	return 0;
}

int BeginExplore::findCommonMonster(long hd, dmsoft *dm, int gameclass, int index,int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	long findRes;
	int i = 15;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = dm->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (speed == 0) {
			if (random_delay(index, gameclass, dm, 180, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (speed == 1) {
			if (random_delay(index, gameclass, dm, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		i--;
	}
	if (findRes != -1)
	{
		//获取父窗口标题
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//点击
		print_log(_T("找到普通怪...\r\n"), gameclass);
		mouse_click_event(title, intX, intY);
		if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//点击
				print_log(_T("找到普通怪...\r\n"), gameclass);
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(838, 405, 935, 474, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				print_log(_T("点击准备...\r\n"), gameclass);
				CPoint pos = random_pos(intX, intY, 1, 3);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(233, 30, 536, 253, _T("胜利.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (dm->FindPic(421, 289, 538, 350, _T("满御魂确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}

		}
		return 1;
	}
	return 0;
}

int BeginExplore::findBossMonster(long hd, dmsoft *dm, int gameclass, int index, int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	long findRes;
	int i = 10;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = dm->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp"), _T("202020"), 0.8, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (speed == 0) {
			if (random_delay(index, gameclass, dm, 180, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (speed == 1) {
			if (random_delay(index, gameclass, dm, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		i--;
	}
	if (findRes != -1)
	{
		//获取父窗口标题
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//点击
		print_log(_T("发现Boss...\r\n"), gameclass);
		mouse_click_event(title, intX, intY);
		if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//点击
				print_log(_T("发现Boss...\r\n"), gameclass);
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(838, 405, 935, 474, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				print_log(_T("点击准备...\r\n"), gameclass);
				CPoint pos = random_pos(intX, intY, 1, 3);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(233, 30, 536, 253, _T("胜利.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				print_log(_T("战斗结算中...\r\n"), gameclass);
				CPoint pos = random_pos(798, 429, 5, 10);
				if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				CPoint pos = random_pos(798, 436, 5, 10);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (dm->FindPic(421, 289, 538, 350, _T("满御魂确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		return 1;
	}
	return 0;
}

//创建队伍---点击邀请
int BeginExplore::InnerCreatTeamToInvite(long hd, dmsoft *dm, int preferArea, int gameclass, int index) {
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
		if (dm->FindPic(552, 361, 595, 401, _T("不公开(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("权限不公开...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}//557,365,591,398,
		else if (dm->FindPic(557, 365, 591, 398, _T("不公开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
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
	//点击好友或跨区
	i = 20;
	while (i > 0)
	{
		if (preferArea==0)
		{
			if (dm->FindPic(353, 61, 434, 109, _T("好友(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("选择同区好友...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 20, intY + 10);
				if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}else if (preferArea == 1)
		{
			if (dm->FindPic(440, 68, 516, 103, _T("跨区(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("选择跨区好友...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 20, intY + 10);
				if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
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

int BeginExplore::EnterExplore(long hd, dmsoft *dm, int gameclass, int index, int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//走动标志
	int moveFlag = -5;
	//进入副本
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		int resultBoss = findBossMonster(hd, dm, gameclass, index, speed);
		if (resultBoss == 0)
		{
			int resultCommon = findCommonMonster(hd, dm, gameclass, index, speed);
			if ((resultCommon == 0) && (moveFlag < 0)) {
				if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, 790, 412);
				moveFlag++;
				if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if ((resultCommon == 0) && (moveFlag >= 0) && (moveFlag <5)) {
				if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, 226, 505);
				moveFlag++;
				if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if ((resultCommon == 0) && (moveFlag >= 5)) {
				moveFlag = -5;
			}
			else if (resultCommon == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (resultBoss == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultBoss == 1) { break; }
	}
	return 1;
}

int BeginExplore::SingleEnterExplore(long hd, dmsoft *dm, CString progressBar, CString materialKinds, int gameclass, int index, int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//走动标志
	int moveFlag = -5;
	//进入副本
	while (1)
	{
		if (IsChangeMaterial(hd, dm, gameclass, index) == 0) {
			//自动拒绝悬赏
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			int resultBoss = findBossMonster(hd, dm, gameclass, index, speed);
			if (resultBoss == 0)
			{
				int resultCommon = findCommonMonster(hd, dm, gameclass, index, speed);
				if ((resultCommon == 0) && (moveFlag < 0)) {
					if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, 790, 412);
					moveFlag++;
					if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				else if ((resultCommon == 0) && (moveFlag >= 0) && (moveFlag < 5)) {
					if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, 226, 505);
					moveFlag++;
					if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				else if ((resultCommon == 0) && (moveFlag >= 5)) {
					moveFlag = -5;
				}
				else if (resultCommon == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (resultBoss == EXIT_THREAD) { return EXIT_THREAD; }
			else if (resultBoss == 1) { break; }
		}
		else {
			AutoReplaceMaterial(hd, progressBar, materialKinds, dm, gameclass, index);
		}
	}
	return 1;
}

int BeginExplore::ReceiveTreasure(long hd, dmsoft *dm, int gameclass, int index) {
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
		long findRes = dm->FindPic(0, 0, 960, 540, _T("奖励.bmp|奖励二.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if (findRes != -1)
		{
			print_log(_T("领取掉落奖励...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(340, 110, 632, 228, _T("获得奖励.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("获得奖励...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD){ return EXIT_THREAD; }
			mouse_click_event(title, 798, 429);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(346, 144, 467, 212, _T("获得奖励(暗).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(427, 359, 788, 465, _T("组队按钮.bmp|探索按钮.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(502, 300, 636, 343, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = random_pos(intX, intY, 20, 25);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			break;
		}
		else if (dm->FindPic(27, 455, 116, 540, _T("觉醒材料.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(502, 300, 636, 343, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = random_pos(intX, intY, 20, 25);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			break;
		}
		else if (dm->FindPic(502, 300, 636, 343, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 20, 25);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		else if (IsOutExploreByYard(dm,gameclass,index)) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(502, 300, 636, 343, _T("确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = random_pos(intX, intY, 20, 25);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			break;
		}
	}
	return 1;
}
//判断是否需要换狗粮
int BeginExplore::IsChangeMaterial(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	int i = 3;
	while (i>0) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(86, 493, 107, 515, _T("自动轮换.bmp|自动轮换1.bmp|自动轮换2.bmp|自动轮换3.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1) {
			print_log(_T("候补出战狗粮已用完...\r\n"), gameclass);
			return 1;
		}
		if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//选择何种狗粮
int BeginExplore::WhatMaterialToSelect(long hd, dmsoft *dm, CString materialKinds, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	if (materialKinds == _T("0")) {
		if (dm->FindPic(103, 220, 151, 270, _T("N卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (materialKinds == _T("1")) {
		if (dm->FindPic(25, 211, 73, 257, _T("素材.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//狗粮进度条选择
int BeginExplore::SelectProgressBar(long hd, dmsoft *dm, CString progress, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	print_log(_T("选择进度...\r\n"), gameclass);
	if (progress == _T("0")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 45, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("1")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 75, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("2")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 105, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("3")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 135, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("4")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 165, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("5")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 195, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("6")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 225, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("7")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 255, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("8")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 285, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("9")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 315, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("10")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 345, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("11")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 375, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("12")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 405, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("13")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 435, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("14")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 465, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("15")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 495, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("16")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 525, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("17")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 555, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("18")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 585, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("19")) {
		if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 615, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//自动换狗粮
int BeginExplore::AutoReplaceMaterial(long hd, CString progressBar, CString materialKinds, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	int allFlag = 0;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("开始自动换狗粮...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 18);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(352, 78, 466, 122, _T("候补出战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			break;
		}
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((allFlag==0)&&(dm->FindPic(352, 78, 466, 122, _T("候补出战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			print_log(_T("选择置入候补式神...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 245, intY + 112);
			if (random_delay(index, gameclass, dm, 1000, 1100) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 245, intY + 112);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			allFlag = 1;
			break;
		}
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(19, 467, 76, 513, _T("全部.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			long clickX = intX, clickY = intY;
			if (dm->FindPic(103, 220, 151, 270, _T("N卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				print_log(_T("选择狗粮类型...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, clickX + 5, clickY + 5);
				if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if ((dm->FindPic(103, 220, 151, 270, _T("N卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)||(dm->FindPic(25, 211, 73, 257, _T("素材.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		WhatMaterialToSelect(hd, dm, materialKinds, gameclass, index);
		//27,466,73,509,
		if ((dm->FindPic(27, 466, 73, 509, _T("N卡(已选).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)|| (dm->FindPic(27, 466, 73, 509, _T("素材(已选).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
	}
	SelectProgressBar(hd, dm, progressBar, gameclass, index);
	long startX, startY, beginX = 81;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((beginX<735) && (dm->FindPic(beginX, 359, 863, 430, _T("出战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)){
			startX = intX, startY = intY;
			if (dm->FindPic(intX - 87, intY, intX - 20, intY + 100, _T("补.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1) {
				print_log(_T("加入出战列表...\r\n"), gameclass);
				HWND sub_hd = findHandle(title);
				SendMessage(sub_hd, WM_LBUTTONDOWN, 0, MAKELPARAM(startX + 9, startY + 7));
				Sleep(2500);
				SendMessage(sub_hd, WM_LBUTTONUP, 0, MAKELPARAM(startX + 9, startY + 7));
			}
			else {
				beginX = startX + 80;
			}
		}
		else if(beginX >= 735){
			if (dm->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_move(title, intX + 15, intY, intX + 37, intY);
				beginX = 81;
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (dm->FindPic(772, 79, 873, 122, _T("满狗粮.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("出战列表已满...\r\n"), gameclass);
			break;
		}
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(822, 289, 910, 371, _T("狗粮确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("确定候补出战...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("已返回副本...\r\n"), gameclass);
			break;
		}
	}
	if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	autoRotate(hd, dm, gameclass, index);
	return 1;
}
//通过庭院判断是否出副本---不触发停止事件
int BeginExplore::IsOutExploreByYard(dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long exploreRes, FpRes, rewordRes;
	//找探索灯笼
	FpRes = dm->FindPic(0, 0, 960, 275, _T("探索灯笼.bmp|探索灯笼1.bmp|探索灯笼2.bmp|探索灯笼3.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
	exploreRes = dm->FindStrFast(0, 0, 960, 275, _T("探索|探索1|探索2|探索3"), _T("1D1914-1E1915"), 0.95, &intX, &intY);
	//找悬赏封印
	rewordRes = dm->FindStrFast(0, 0, 960, 324, _T("悬赏封印"), _T("C9B7A7-364856"), 0.95, &intX, &intY);
	if ((exploreRes != -1) || (rewordRes != -1) || (FpRes != -1))
	{
		return 1;
	}
	else {
		return 0;
	}
}
//组队进入副本
int BeginExplore::receiveEnterExplore(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	int flag = 0;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1)
	{
		if (IsOutExploreByYard(dm, gameclass, index))
		{
			break;
		}
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (count == 0)
		{
			if (dm->FindPic(27, 518, 67, 540, _T("设置.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1)
			{
				if ((dm->FindPic(86, 493, 107, 515, _T("自动轮换.bmp|自动轮换1.bmp|自动轮换2.bmp|自动轮换3.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1) && flag == 0)
				{
					print_log(_T("自动轮换已开启...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX + 1, intY + 1);
					if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
					flag = 1;
				}
			}
			
		}
		//点准备
		if (dm->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
		if (dm->FindPic(388, 372, 567, 456, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(421, 289, 538, 350, _T("满御魂确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX,intY);
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(0, 0, 960, 540, _T("奖励.bmp|奖励二.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("领取掉落奖励...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(340, 110, 632, 228, _T("获得奖励.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("获得奖励...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, 798, 429);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(346, 144, 467, 212, _T("获得奖励(暗).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+5, intY+10);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsOutExploreByYard(dm, gameclass, index))
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//接受邀请
int BeginExplore::ReceiveInvite(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//获取父窗口标题
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	CString count_str;
	count_str.Format(_T("%d"), count + 1);
	print_log(_T("等待好友邀请...\r\n"), gameclass);
	while (1)
	{
		if (dm->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count_str.Format(_T("%d"), count + 1);
			print_log(_T("接受邀请...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			print_log(_T("第" + count_str + "轮探索开始...\r\n"), gameclass);
			count++;
			if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//检测好友进入队伍点挑战 
int BeginExplore::IsEnterTeamRepeat(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	int timerRecord = 0;
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
		Sleep(1000);
		timerRecord++;
		if (timerRecord >= 20) {
			while (1) {
				if (dm->FindPic(770, 146, 862, 234, _T("探索加.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
				{
					print_log(_T("邀请好友...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX + 12, intY + 10);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(404, 119, 483, 157, _T("最近组队.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
				{
					print_log(_T("邀请...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX - 50, intY + 40);
					if (random_delay(index, gameclass, dm, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(536, 407, 632, 454, _T("邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX + 10, intY + 5);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
			}
			timerRecord = 0;
		}
		
	}
	return 1;
}
//探索单刷
int BeginExplore::SingleExplore(long hd, int round,int layer, int diff, CString jc, int speed, CString progressBar, CString materialKinds, int MaterialMode, dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//判断是否在庭院
	if (!IsInYard(dm,gameclass,index))
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
	}else if(result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 310, startXY.y = 8;
	endXY.x = 351, endXY.y = 60;
	if (auto_open_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	//保持在选择层数界面
	if (isExplore(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//选择章节并点击
		CPoint startXY, endXY;
		startXY.x = 777, startXY.y = 131;
		endXY.x = 952, endXY.y = 508;
		//判断开始前是否在章节点开状态
		int resultExplore = dm->FindPic(642, 367, 773, 438, _T("探索按钮.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if (resultExplore == -1) {
			if (SingleChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//选择难度
		if (count == 0)
		{
			print_log(_T("选择难度...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (ChooseDiff(hd, diff, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		//点击探索按钮
		if (clickExplore(hd, dm, gameclass, index)== EXIT_THREAD) { return EXIT_THREAD; }
		//自动轮换
		if (count == 0)
		{
			print_log(_T("选中自动轮换...\r\n"), gameclass);
			if (autoRotate(hd, dm, gameclass, index)== EXIT_THREAD) { return EXIT_THREAD; }
		}
		//进入副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮探索开始...\r\n"),gameclass);
		if (MaterialMode == 0) {
			if (EnterExplore(hd, dm, gameclass, index, speed) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (MaterialMode == 1) {
			if (SingleEnterExplore(hd, dm, progressBar, materialKinds, gameclass, index, speed) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		//领取奖励宝箱
		if (ReceiveTreasure(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count>=round)
	{
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (ExploreReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		
		//自动关加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//组队邀请好友
int BeginExplore::inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, dmsoft *dm, int gameclass, int index) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(hd, dm, gameclass, index);
	if (resultCombine == 0) {
		print_log(_T("很抱歉，未找到组队按钮...\r\n"), gameclass);
		return 0;
	}else if(resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择探索

	//获取当前位置选项
	CString bmp_pic = _T("探索(困难).bmp|觉醒业火轮.bmp|觉醒风转符.bmp|觉醒水灵鲤.bmp|觉醒天雷鼓.bmp|御魂.bmp|日轮之陨.bmp|永生之海.bmp|妖气封印.bmp|经验妖怪.bmp|金币妖怪.bmp|年兽.bmp|结界突破.bmp");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//找到探索并点击
	findDestination(hd, bmp_pic, 5, _T("探索(困难).bmp|探索(困难)(选中).bmp"), startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	if (ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	if (!InnerCreatTeamToInvite(hd, dm, preferArea, gameclass, index)) {
		print_log(_T("创建队伍失败!!!\r\n"), gameclass);
		//未找到最近好友，返回庭院后关闭加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (random_delay(index, gameclass, dm, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if (IsEnterTeamRepeat(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动轮换
		if (count == 0)
		{
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("选中自动轮换...\r\n"), gameclass);
			if (autoRotate(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入探索副本
		//进入副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("第" + count_str + "轮探索开始...\r\n"), gameclass);
		if (EnterExplore(hd, dm, gameclass, index, speed) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//领取奖励宝箱
		if (ReceiveTreasure(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (ExploreReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//自动关加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//组队接受邀请
int BeginExplore::BeinvitedExplore(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		//接受邀请
		if (ReceiveInvite(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 2000, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入探索副本
		if (receiveEnterExplore(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		if (ReceiveTreasure(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("任务已完成，正在退出返回庭院...\r\n"), gameclass);
		if (ExploreReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//自动关加成
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("探索"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}

//返回庭院
int BeginExplore::ExploreReturnYard(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(760, 83, 814, 135, _T("叉.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(15, 13, 73, 72, _T("返回1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//760, 83, 814, 135,
		if (dm->FindPic(9, 18, 61, 76, _T("返回5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(523, 286, 640, 320, _T("探索确认.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(506, 303, 631, 346, _T("确定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(9, 1, 65, 59, _T("返回4.bmp|返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(506, 303, 631, 346, _T("确定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
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
