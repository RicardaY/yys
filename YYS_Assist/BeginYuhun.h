#pragma once
#include "yys_function.h"
class BeginYuhun :public yys_function
{
public:
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//单刷选择层数
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//寻副本
	int FindYuHun(long hd, dmsoft *dm, int gameclass, int index);
	//锁定阵容
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	//进入副本
	int EnterYuHun(long hd, dmsoft *dm, int gameclass, int index);
	//庭院邀请好友模式
	int inviteYuhun(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//庭院接受邀请模式
	int BeinvitedYuhun(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
	//单刷
	int SingleYuHun(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//返回庭院
	int YuHunReturnYard(long hd, dmsoft *dm, int gameclass, int index);
};
