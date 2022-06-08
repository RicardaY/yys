#pragma once
#include "yys_function.h"
class BeginRiLunZhiYun :public yys_function
{
public:
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//单刷选择层数
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//寻副本
	int FindRiLunZhiYun(long hd, dmsoft *dm, int gameclass, int index);
	//锁定阵容
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);

	//进入副本
	int EnterRiLunZhiYun(long hd, dmsoft *dm, int gameclass, int index);
	//开始
	int SingleRiLunZhiYun(long hd, int round, int layer,CString jc, dmsoft *dm, int gameclass, int index);
	//庭院邀请好友模式
	int inviteRiLunZhiYun(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//庭院接受邀请模式
	int BeinvitedRiLunZhiYun(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
};

