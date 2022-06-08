#pragma once
#include "yys_function.h"
class BeginJueXing :public yys_function
{
public:
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//单刷选择层数
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//抽象出选择哪只麒麟方法，方便调用
	int WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic, int gameclass, int index);
	//选打哪个
	int ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index);
	//找副本
	int FindJueXing(long hd, dmsoft *dm, int gameclass, int index);
	//锁定阵容
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	//进入副本
	int EnterJueXing(long hd, dmsoft *dm, int gameclass, int index);
	//庭院邀请好友模式
	int inviteJueXing(long hd, int round, int mode,  int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//庭院接受邀请模式
	int BeinvitedJueXing(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
	//单刷
	int SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, dmsoft *dm, int gameclass, int index);
};

