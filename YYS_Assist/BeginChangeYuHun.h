#pragma once
#include "yys_function.h"

class BeginChangeYuHun : public yys_function
{
public:
	//选择分组
	int SelectGroup(long hd, dmsoft *dm, CPoint clickXY, int gameclass, int index);
	//预设御魂
	int StartChangeYuHun(long hd, dmsoft *dm, int group, int team, int gameclass, int index);

	//预设两组御魂
	int StartChangeYuHunDouble(long hd, dmsoft *dm, int group, int team1, int team2, int gameclass, int index);
};

