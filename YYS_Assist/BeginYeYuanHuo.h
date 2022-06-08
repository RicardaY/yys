#pragma once
#include "yys_function.h"
class BeginYeYuanHuo :public yys_function
{
public:
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//进副本
	int FindYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index);
	//锁定阵容
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	
	//进入副本
	int EnterYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index);
	//开始
	int StartYeYuanHuo(long hd, int round, int layer, dmsoft *dm, int gameclass, int index);
};

