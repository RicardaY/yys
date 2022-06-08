#pragma once
#include"obj.h"

extern struct ThreadInfo {
	bool pause;
	bool start;
	bool stop;
	bool suspend_flag;
};

//线程状态初始化
int initThreadInfo();

class yys_function
{
public:
	//拆分字符串
	int SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString);
	//读文件
	int ReadFile(CString filePath, CStringArray& ListArray);
	//写文件
	int WriteFile(CString filePath, CStringArray& ListArray);
	//获取窗口句柄
	HWND findHandle(CString windowname);

	//编辑框结尾追加数据
	void print_log(TCHAR szMsg[], int gameclass);
	//鼠标事件若分辨率为125% 像素坐标需要click_x和click_y  都除以1.25
	//click_x,click_y:相对子句柄坐标
	void mouse_click_event(CString windowname, int click_x, int click_y);

	//鼠标移动
	void mouse_move(CString windowname, int start_x, int start_y, int end_x, int end_y);

	//随即偏移坐标，防止游戏外挂检测  (从左往右，从上往下偏移,可为负值)
	CPoint random_pos(int pos_x, int pos_y, int offsetX, int offsetY);

	//随机延迟点击，防止游戏外挂检测
	int random_delay(int index, int gameclass, dmsoft *dm,int time_min = 1000, int time_max = 2500);

	//判断是否在庭院
	bool IsInYard(dmsoft *dm,int gameclass, int index);
	//判断庭院是否展开
	bool IsShowYard(dmsoft *dm,int gameclass, int index);
	//展开庭院
	int showYard(dmsoft *dm, int gameclass, int index);
	//寻找探索灯笼并点击
	int FindExploreLanTernAndClick(long hd, dmsoft *dm,int gameclass, int index);

	//点击组队
	int CombineTeamAction(long hd, dmsoft *dm, int gameclass, int index);
	//获取当前位置
	long findNowSection(CString sourcePic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//寻找目标位置并点击
	int findDestination(long hd, CString allpic, long destinationLoc, CString destPic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//创建队伍
	int CreatTeamToInvite(long hd, dmsoft *dm, int gameclass, int index);
	//解锁
	int unlock(long hd, dmsoft *dm, int gameclass, int index);
	//好友是否进入队伍
	int IsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index);
	//邀请进入副本
	int InviteEnterEvent(long hd, dmsoft *dm, int gameclass, int index);
	//接受邀请进入副本
	int ReceiveEnterEvent(long hd, dmsoft *dm, int count, CString gameMode, int gameclass, int index);

	//默认邀请好友
	int DefalutInvite(long hd, dmsoft *dm, int gameclass, int index);
	//自动开加成
	int auto_open_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index);
	//自动关加成
	int auto_close_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index);
	//自动拒绝悬赏封印
	int AutoRejectXS(long hd, dmsoft *dm, int gameclass, int index);
	//返回庭院
	int returnYard(long hd, dmsoft *dm, int gameclass, int index);
};

