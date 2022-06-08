#pragma once
#include "yys_function.h"
class BeginYuLing :public yys_function
{
public:
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//抽象出选择哪只御灵方法，方便调用
	int WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic[2], int gameclass, int index);
	//选打哪个
	int ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index);
	//找副本
	int FindYuLing(long hd, dmsoft *dm, int gameclass, int index);
	//锁定阵容
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);

	//进入副本
	int EnterYuLing(long hd, dmsoft *dm, int gameclass, int index);
	//开始
	int StartYuLing(long hd, int round, int monster_kind, int layer, dmsoft *dm, int gameclass, int index);
};

