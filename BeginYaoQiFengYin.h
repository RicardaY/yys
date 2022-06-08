#pragma once
#include "yys_function.h"
class BeginYaoQiFengYin :public yys_function
{
public:
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//进入副本
	int EnterYaoQiFengYin(long hd, int condition, dmsoft *dm, int gameclass, int index);
	//开始
	int StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, dmsoft *dm, int gameclass, int index);
};

