#pragma once
#include "yys_function.h"
class BeginExplore : public yys_function
{
public:
	//判断是否在探索界面
	int isExplore(long hd, dmsoft *dm, int gameclass,int index);
	//选择层数
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//选择层数
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//选择难度
	int ChooseDiff(long hd, int diff, dmsoft *dm, int gameclass, int index);
	//点击探索
	int clickExplore(long hd, dmsoft *dm, int gameclass, int index);
	//进入副本后操作
	//检查自动轮换--以后会实现全自动轮换
	int autoRotate(long hd, dmsoft *dm, int gameclass, int index);
	//找小怪 speed:刷怪速度
	int findCommonMonster(long hd, dmsoft *dm, int gameclass, int index,int speed);
	//找boss
	int findBossMonster(long hd, dmsoft *dm, int gameclass, int index, int speed);
	//邀请好友
	int InnerCreatTeamToInvite(long hd, dmsoft *dm, int preferArea, int gameclass, int index);
	//进入副本并开始探索
	int EnterExplore(long hd, dmsoft *dm, int gameclass, int index, int speed);
	//单刷模式进入副本并开始探索
	int SingleEnterExplore(long hd, dmsoft *dm, CString progressBar, CString materialKinds, int gameclass, int index, int speed);
	//领取奖励宝箱
	int ReceiveTreasure(long hd, dmsoft *dm, int gameclass, int index);
	//通过庭院判断是否出副本
	int IsOutExploreByYard(dmsoft *dm, int gameclass, int index);
	//组队进入副本
	int receiveEnterExplore(long hd, dmsoft *dm, int count, int gameclass, int index);
	//检测好友进入队伍点挑战 
	int IsEnterTeamRepeat(long hd, dmsoft *dm, int count, int gameclass, int index);
	//判断是否需要换狗粮
	int IsChangeMaterial(long hd, dmsoft *dm, int gameclass, int index);
	//选择何种狗粮
	int WhatMaterialToSelect(long hd, dmsoft *dm, CString materialKinds, int gameclass, int index);
	//狗粮进度条选择
	int SelectProgressBar(long hd, dmsoft *dm, CString progress, int gameclass, int index);
	//自动换狗粮
	int AutoReplaceMaterial(long hd, CString progressBar, CString materialKinds, dmsoft *dm, int gameclass, int index);
	//接受邀请
	int ReceiveInvite(long hd, dmsoft *dm, int count, int gameclass, int index);
	//单刷
	int SingleExplore(long hd, int round, int layer, int diff, CString jc, int speed, CString progressBar, CString materialKinds, int MaterialMode, dmsoft *dm, int gameclass, int index);
	//组队邀请好友
	int inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, dmsoft *dm, int gameclass, int index);
	//组队接受邀请
	int BeinvitedExplore(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
	//返回庭院
	int ExploreReturnYard(long hd, dmsoft *dm, int gameclass, int index);
};
