#pragma once
#include "yys_function.h"
class InDependentFunction :public yys_function
{
public:
	//百鬼夜行
	int StartBaiGui(long hd, int round, dmsoft *dm, int gameclass, int index);
	//新活动
	int StartNewEvent(long hd, int round, dmsoft *dm, int gameclass, int index);
};

