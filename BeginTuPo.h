#pragma once
#include "yys_function.h"
class BeginTuPo :public yys_function
{
public:
	//进副本
	int FindTuPo(long hd, dmsoft *dm, int gameclass, int index);
	//刷新规则
	int ReFreshRule(long hd, dmsoft *dm, int gameclass, int index);
	//刷新副本
	int ReFresh(long hd, dmsoft *dm, int gameclass, int index);
	//锁定阵容
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	//判断是否有突破券
	int isHaveTicket(long hd, dmsoft *dm, int gameclass, int index);
	//退出突破操作：返回-->确定-->失败
	int ExitDo(long hd, dmsoft *dm, int gameclass, int index);
	//退四
	int ExitFour(long hd, dmsoft *dm, int gameclass, int index);
	//选择关卡
	int SelectAttack(long hd, CPoint startXY, CPoint endXY, CString attackImg, dmsoft *dm, int gameclass, int index);
	//准备---结算
	int ReadyToFinish(long hd, dmsoft *dm,int count, int gameclass, int index);
	//领取下方宝箱
	int CheckReward(long hd, dmsoft *dm, int gameclass, int index);
	//开始
	int StartTuPo(long hd, int round, dmsoft *dm, int gameclass, int index);
	//退四打九
	int StartTuPoByExitFourAttackNine(long hd, int round, dmsoft *dm, int gameclass, int index);
	int TupoReturnYard(long hd, dmsoft *dm, int gameclass, int index);
};

