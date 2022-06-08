// CGame2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame2.h"
#include "afxdialogex.h"
#include "yys_function.h"
#include "BeginExplore.h"
#include "BeginYuhun.h"
#include "BeginJueXing.h"
#include "BeginRiLunZhiYun.h"
#include "BeginYongShengZhiHai.h"
#include "BeginYaoQiFengYin.h"
#include "BeginYeYuanHuo.h"
#include "BeginTuPo.h"
#include "BeginYuLing.h"
#include "BeginRest.h"
#include "InDependentFunction.h"
#include "BeginChangeYuHun.h"
#define EXIT_THREAD -10

CGame2 *p;
extern CString g_path;
extern CString version;
extern ThreadInfo threadState[2];
extern CGame_inDependentFunc2 *depend;
extern CGame_ChangeEquip2 *changeEquip;
// CGame2 对话框

IMPLEMENT_DYNAMIC(CGame2, CDialogEx)

CGame2::CGame2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAME2, pParent)
{
	p = this;
}

CGame2::~CGame2()
{
}

void CGame2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MODE2, m_tab_game2_mode);
	DDX_Control(pDX, IDC_WINDOW_TYPE2, m_windowType2);
	DDX_Control(pDX, IDC_COMBO_W_OR_H2, m_win_or_handle2);
	DDX_Control(pDX, IDC_LIST_SHOW_ADDTASK, m_list_taskshow);
	DDX_Control(pDX, IDC_TAB_RIGHT2, m_tab2_right);
	DDX_Control(pDX, IDC_DRAG_HANDLE2, m_DragStatic2);
	DDX_Control(pDX, IDC_GET_HD1, m_hadleText);
	DDX_Control(pDX, IDC_VERSION, m_version);
	DDX_Control(pDX, IDC_CIRCLE, m_circle);
}


BEGIN_MESSAGE_MAP(CGame2, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_DELETE_SELECT_TASK2, &CGame2::OnBnClickedBtnDeleteSelectTask2)
	ON_BN_CLICKED(IDC_BTN_CLEAR_TASK_LIST2, &CGame2::OnBnClickedBtnClearTaskList2)
	ON_BN_CLICKED(IDC_BTN_START2, &CGame2::OnBnClickedBtnStart2)
	ON_BN_CLICKED(IDC_BTN_SUSPEND2, &CGame2::OnBnClickedBtnSuspend2)
	ON_BN_CLICKED(IDC_BTN_STOP2, &CGame2::OnBnClickedBtnStop2)
	ON_BN_CLICKED(IDC_TASKUP, &CGame2::OnBnClickedTaskup)
	ON_BN_CLICKED(IDC_TASKDOWN, &CGame2::OnBnClickedTaskdown)
	ON_BN_CLICKED(IDC_BTN_IMPORT, &CGame2::OnBnClickedBtnImport)
	ON_BN_CLICKED(IDC_BTN_EXPORT, &CGame2::OnBnClickedBtnExport)
END_MESSAGE_MAP()


// CGame2 消息处理程序


BOOL CGame2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tab_game2_mode.AddPage(_T("御魂"), &yuhun2, IDD_YUHUN2_DLG);
	m_tab_game2_mode.AddPage(_T("觉醒"), &juexing2, IDD_JueXing2_DLG);
	m_tab_game2_mode.AddPage(_T("日轮之陨"), &riLunZhiYun2, IDD_RiLunZhiYun2_DLG);
	m_tab_game2_mode.AddPage(_T("永生之海"), &yongShengZhiHai2, IDD_YongShengZhiHai2_DLG);
	m_tab_game2_mode.AddPage(_T("探索"), &tanSuo2, IDD_TanSuo2_DLG);
	m_tab_game2_mode.AddPage(_T("妖气封印"), &yaoQiFengYin2, IDD_YaoQiFengYin2_DLG);
	m_tab_game2_mode.AddPage(_T("业原火"), &yeYuanHuo2, IDD_YeYuanHuo2_DLG);
	m_tab_game2_mode.AddPage(_T("御灵"), &yuLing2, IDD_YuLing2_DLG);
	m_tab_game2_mode.AddPage(_T("个人突破"), &geRenTuPo2, IDD_GeRenTuPo2_DLG);
	m_tab_game2_mode.AddPage(_T("新活动"), &newEvent2, IDD_NEW_EVENT2_DLG);
	m_tab_game2_mode.AddPage(_T("休息"), &rest2, IDD_Rest2_DLG);
	m_tab_game2_mode.Show();
	m_tab2_right.AddPage(_T("独立功能"), &independent_func2, IDD_INDEPENDENT2);
	m_tab2_right.AddPage(_T("御魂预设"), &changeEquip2, IDD_CHANGEEQUIP2);
	m_tab2_right.AddPage(_T("运行日志"), &runlog2, IDD_RunLog2);
	m_tab2_right.Show();
	//初始化数据
	m_windowType2.SetCurSel(0);
	m_win_or_handle2.SetCurSel(0);
	m_circle.SetWindowTextW(_T("1"));
	//初始化版本号
	m_version.SetWindowTextW(version);
	//高级列表默认值
	m_list_taskshow.InsertColumn(0, _T("↓任务列表按上往下执行[修改上面的设置必须重新添加]↓"), LVCFMT_LEFT, 550);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//上移选中任务
void CGame2::OnBnClickedTaskup()
{
	//获取当前行号
	POSITION ps;
	int nCurrentItem;
	ps = m_list_taskshow.GetFirstSelectedItemPosition();
	if (ps == NULL) {
		return;
	}
	nCurrentItem = m_list_taskshow.GetNextSelectedItem(ps);
	//已经到最顶端则不上移
	if (nCurrentItem <= 0)
	{
		MessageBox(_T("已经移动到最顶端！"), NULL, MB_ICONINFORMATION);
		return;
	}
	//提取行所有信息
	int nColumnCount = m_list_taskshow.GetHeaderCtrl()->GetItemCount();
	CString strCurrentItem[30];	//给予更大的空间
	for (int i = 0; i <= nColumnCount; i++)
	{
		strCurrentItem[i] = m_list_taskshow.GetItemText(nCurrentItem, i);
	}
	//删除该行
	m_list_taskshow.DeleteItem(nCurrentItem);
	// 在nCurrentItem -1位置处插入上面所删列表项的各列
	int strNewItem = m_list_taskshow.InsertItem(nCurrentItem - 1, strCurrentItem[0]);

	for (int j = 1; j <= nColumnCount; j++)
	{
		m_list_taskshow.SetItemText(strNewItem, j, strCurrentItem[j]);
	}
	// 使得IndexInFieldList-1位置处项目高亮显示并获得焦点
	nCurrentItem--;
	m_list_taskshow.SetFocus();
	m_list_taskshow.SetItemState(nCurrentItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
}
//下移选中任务
void CGame2::OnBnClickedTaskdown()
{
	//获取当前行号
	POSITION ps;
	int nCurrentItem;
	ps = m_list_taskshow.GetFirstSelectedItemPosition();
	if (ps == NULL) {
		return;
	}
	nCurrentItem = m_list_taskshow.GetNextSelectedItem(ps);
	//已经到最顶端则不上移
	if (nCurrentItem >= m_list_taskshow.GetItemCount() - 1)
	{
		MessageBox(_T("已经移动到最底端！"), NULL, MB_ICONINFORMATION);
		return;
	}
	//提取行所有信息
	int nColumnCount = m_list_taskshow.GetHeaderCtrl()->GetItemCount();
	CString strCurrentItem[30];	//给予更大的空间
	for (int i = 0; i <= nColumnCount; i++)
	{
		strCurrentItem[i] = m_list_taskshow.GetItemText(nCurrentItem, i);
	}
	//删除该行
	m_list_taskshow.DeleteItem(nCurrentItem);
	// 在nCurrentItem +1位置处插入上面所删列表项的各列
	int strNewItem = m_list_taskshow.InsertItem(nCurrentItem + 1, strCurrentItem[0]);

	for (int j = 1; j <= nColumnCount; j++)
	{
		m_list_taskshow.SetItemText(strNewItem, j, strCurrentItem[j]);
	}
	// 使得IndexInFieldList+1位置处项目高亮显示并获得焦点
	nCurrentItem++;
	m_list_taskshow.SetFocus();
	m_list_taskshow.SetItemState(nCurrentItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);

}

//删除选中任务
void CGame2::OnBnClickedBtnDeleteSelectTask2()
{
	POSITION pos = m_list_taskshow.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nItem = m_list_taskshow.GetNextSelectedItem(pos);
		m_list_taskshow.DeleteItem(nItem);
	}
}

//清空任务列表
void CGame2::OnBnClickedBtnClearTaskList2()
{
	m_list_taskshow.DeleteAllItems();
}


UINT __cdecl ThreadProc2(LPVOID lpParameter) {
	//初始化当前线程com组件为MTA模式
	CoInitializeEx(NULL, 0);
	dmsoft *dm = new dmsoft;
	//设置字库
	dm->SetPath(g_path);

	CGame2 *game2 = (CGame2*)lpParameter;
	CString m_handle;
	game2->m_hadleText.GetWindowTextW(m_handle);

	if (m_handle.IsEmpty())
	{
		MessageBox(NULL, _T("请选择句柄！"), _T("提示"), 0);
		threadState[1].start = false;
		threadState[1].stop = true;
		return 0;
	}
	long handle = StrToInt(m_handle);
	long dm_band = dm->BindWindowEx(handle, _T("gdi"), _T("windows"), _T("windows"), _T(""), 101);
	if (dm_band != 1)
	{
		MessageBox(NULL, _T("绑定窗口句柄失败！"), _T("提示"), 0);
		return 0;
	}

	//遍历列表
	int nCount = game2->m_list_taskshow.GetItemCount();
	int dependFlag = depend->m_baigui.GetCheck();
	if (nCount == 0 && (dependFlag == 0))
	{
		MessageBox(NULL, _T("任务列表未添加任何任务！"), _T("提示"), 0);
		threadState[1].start = false;
		threadState[1].stop = true;
		return 0;
	}
	if (dependFlag == 1) {
		InDependentFunction dependFunc;
		int threadRes = dependFunc.StartBaiGui(handle, 1000, dm, 1, 1);
		//中途结束线程
		if (threadRes == EXIT_THREAD)
		{
			dependFunc.print_log(_T("线程已停止!\r\n"), 1);
			//解绑
			if (dm->IsBind(handle))
			{
				dm->UnBindWindow();
			}
			//释放资源
			if (dm != NULL)
			{
				delete dm;
				dm = NULL;
			}
			return EXIT_THREAD;
		}
	}
	CString get_item[20];
	for (int i = 0; i < nCount; i++) {
		get_item[i] = game2->m_list_taskshow.GetItemText(i, 0);
	}
	//拆分字符串
	CStringArray strResult[20];
	for (int i = 0; i < nCount; i++)
	{
		yys_function function;
		function.SplitString(get_item[i], _T("-"), strResult[i], FALSE);
	}
	//开始任务
	CString circle_str;
	game2->m_circle.GetWindowTextW(circle_str);
	int circle = StrToInt(circle_str);
	for (int j = 0; j < circle; j++) {
		for (int i = 0; i < nCount; i++)
		{
			if (strResult[i].GetAt(0) == _T("探索")) {
				BeginExplore explore;
				CString round_str = strResult[i].GetAt(1);
				CString mode_str = strResult[i].GetAt(2);
				CString layer_str = strResult[i].GetAt(3);
				CString diff_str = strResult[i].GetAt(4);
				CString jc_str = strResult[i].GetAt(6);
				CString preferArea_str = strResult[i].GetAt(7);
				CString speed_str = strResult[i].GetAt(8);
				CString material_str = strResult[i].GetAt(9);
				CString materialKinds_int = strResult[i].GetAt(10);
				CString progressBar_str = strResult[i].GetAt(11);

				int round = StrToInt(round_str);
				int mode = StrToInt(mode_str);
				int layer = StrToInt(layer_str);
				int diff = StrToInt(diff_str);
				int preferArea = StrToInt(preferArea_str);
				int speed = StrToInt(speed_str);
				int material = StrToInt(material_str);
				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_tsg.GetCurSel();
					int team = changeEquip->m_tst.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				if (mode == 0)
				{
					threadRes = explore.BeinvitedExplore(handle, round, jc_str, dm, 1, 1);
				}
				else if (mode == 1)
				{
					threadRes = explore.inviteExplore(handle, round, layer, jc_str, preferArea, speed, dm, 1, 1);
				}
				else if (mode == 2)
				{
					threadRes = explore.SingleExplore(handle, round, layer, diff, jc_str, speed, progressBar_str, materialKinds_int, material, dm, 1, 1);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					explore.print_log(_T("线程已停止！\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("御魂")) {
				BeginYuhun yuhun;
				CString round_str = strResult[i].GetAt(1);
				CString layer_str = strResult[i].GetAt(2);
				CString jc_str = strResult[i].GetAt(3);
				CString mode_str = strResult[i].GetAt(4);

				int round = StrToInt(round_str);
				int layer = StrToInt(layer_str);
				int mode = StrToInt(mode_str);

				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_yhg.GetCurSel();
					int team = changeEquip->m_yht.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				if (mode == 1119)
				{
					threadRes = yuhun.inviteYuhun(handle, round, layer, jc_str, dm, 1, 1);
				}
				else if (mode == 1118)
				{
					threadRes = yuhun.BeinvitedYuhun(handle, round, jc_str, dm, 1, 1);
				}
				else if (mode == 1116)
				{
					threadRes = yuhun.SingleYuHun(handle, round, layer, jc_str, dm, 1, 1);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					yuhun.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("觉醒")) {
				BeginJueXing juexing;
				CString round_str = strResult[i].GetAt(1);
				CString mode_str = strResult[i].GetAt(2);
				CString layer_str = strResult[i].GetAt(3);
				CString jc_str = strResult[i].GetAt(4);
				CString monster_mode_str = strResult[i].GetAt(5);

				int round = StrToInt(round_str);
				int mode = StrToInt(mode_str);
				int layer = StrToInt(layer_str);
				int monster_mode = StrToInt(monster_mode_str);

				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_jxg.GetCurSel();
					int team = changeEquip->m_jxt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				if (monster_mode == 1075)
				{
					threadRes = juexing.inviteJueXing(handle, round, mode, layer, jc_str, dm, 1, 1);
				}
				else if (monster_mode == 1073)
				{
					threadRes = juexing.BeinvitedJueXing(handle, round, jc_str, dm, 1, 1);
				}
				else if (monster_mode == 1069)
				{
					threadRes = juexing.SingleJueXing(handle, round, mode, layer, jc_str, dm, 1, 1);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					juexing.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("日轮之陨")) {
				BeginRiLunZhiYun rilunzhiyun;
				CString round_str = strResult[i].GetAt(1);
				CString layer_str = strResult[i].GetAt(2);
				CString jc_str = strResult[i].GetAt(3);
				CString mode_str = strResult[i].GetAt(4);

				int round = StrToInt(round_str);
				int layer = StrToInt(layer_str);
				int mode = StrToInt(mode_str);

				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_rlzyg.GetCurSel();
					int team = changeEquip->m_rlzyt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				if (mode == 1109)
				{
					threadRes = rilunzhiyun.inviteRiLunZhiYun(handle, round, layer, jc_str, dm, 1, 1);
				}
				else if (mode == 1108)
				{
					threadRes = rilunzhiyun.BeinvitedRiLunZhiYun(handle, round, jc_str, dm, 1, 1);
				}
				else if (mode == 1106)
				{
					threadRes = rilunzhiyun.SingleRiLunZhiYun(handle, round, layer, jc_str, dm, 1, 1);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					rilunzhiyun.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("永生之海")) {
				BeginYongShengZhiHai yongshengzhihai;
				CString round_str = strResult[i].GetAt(1);
				CString layer_str = strResult[i].GetAt(2);
				CString jc_str = strResult[i].GetAt(3);
				CString mode_str = strResult[i].GetAt(4);

				int round = StrToInt(round_str);
				int layer = StrToInt(layer_str);
				int mode = StrToInt(mode_str);

				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_yszhg.GetCurSel();
					int team1 = changeEquip->m_yszht1.GetCurSel();
					int team2 = changeEquip->m_yszht2.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHunDouble(handle, dm, group, team1, team2, 1, 1);
				}

				if (mode == 1132)
				{
					threadRes = yongshengzhihai.inviteYongShengZhiHai(handle, round, layer, jc_str, dm, 1, 1);
				}
				else if (mode == 1131)
				{
					threadRes = yongshengzhihai.BeinvitedYongShengZhiHai(handle, round, jc_str, dm, 1, 1);
				}
				else if (mode == 1130)
				{
					threadRes = yongshengzhihai.SingleYongShengZhiHai(handle, round, layer, jc_str, dm, 1, 1);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					yongshengzhihai.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("妖气封印")) {
				BeginYaoQiFengYin yaoqifengyin;
				CString round_str = strResult[i].GetAt(1);
				CString monster_kind_str = strResult[i].GetAt(2);
				CString condition_str = strResult[i].GetAt(3);

				int round = StrToInt(round_str);
				int monster_kind = StrToInt(monster_kind_str);
				int condition = StrToInt(condition_str);

				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_yqfyg.GetCurSel();
					int team = changeEquip->m_yqfyt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				threadRes = yaoqifengyin.StartYaoQiFengYin(handle, round, monster_kind, condition, dm, 1, 1);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					yaoqifengyin.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("业原火")) {
				BeginYeYuanHuo yeyuanhuo;
				CString round_str = strResult[i].GetAt(1);
				CString monster_kind_str = strResult[i].GetAt(2);

				int round = StrToInt(round_str);
				int monster_kind = StrToInt(monster_kind_str);

				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_yyhg.GetCurSel();
					int team = changeEquip->m_yyht.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				threadRes = yeyuanhuo.StartYeYuanHuo(handle, round, monster_kind, dm, 1, 1);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					yeyuanhuo.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("结界突破")) {
				BeginTuPo tupo;
				CString round_str = strResult[i].GetAt(1);
				CString mode_str = strResult[i].GetAt(2);
				int round = StrToInt(round_str);
				int mode = StrToInt(mode_str);
				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_jjtpg.GetCurSel();
					int team = changeEquip->m_jjtpt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				if (mode == 0) {
					threadRes = tupo.StartTuPo(handle, round, dm, 1, 1);
				}
				else if (mode == 1) {
					threadRes = tupo.StartTuPoByExitFourAttackNine(handle, round, dm, 1, 1);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					tupo.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("御灵")) {
				BeginYuLing yuling;
				CString round_str = strResult[i].GetAt(1);
				CString monster_kind_str = strResult[i].GetAt(2);
				CString layer_str = strResult[i].GetAt(3);
				int round = StrToInt(round_str);
				int monster_kind = StrToInt(monster_kind_str);
				int layer = StrToInt(layer_str);
				//控制线程结束标志
				int threadRes;

				//是否预设御魂
				if (changeEquip->m_ispreset.GetCheck() == 1) {
					int group = changeEquip->m_ylg.GetCurSel();
					int team = changeEquip->m_ylt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, dm, group, team, 1, 1);
				}

				threadRes = yuling.StartYuLing(handle, round, monster_kind, layer, dm, 1, 1);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					yuling.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}

					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("休息")) {
				BeginRest rest;
				CString minite_str = strResult[i].GetAt(1);
				int minite = StrToInt(minite_str);

				//控制线程结束标志
				int threadRes;
				threadRes = rest.StartRest(handle, dm, minite, 1, 1);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					rest.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}

					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("新活动")) {
				InDependentFunction dependFunc;
				CString round_str = strResult[i].GetAt(1);
				int round = StrToInt(round_str);
				//控制线程结束标志
				int threadRes;
				threadRes = dependFunc.StartNewEvent(handle, round, dm, 1, 1);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					dependFunc.print_log(_T("线程已停止!\r\n"), 1);
					//解绑
					if (dm->IsBind(handle))
					{
						dm->UnBindWindow();
					}
					//释放资源
					if (dm != NULL)
					{
						delete dm;
						dm = NULL;
					}

					return EXIT_THREAD;
				}
			}
		}
	}
	//解绑
	if (dm->IsBind(handle))
	{
		dm->UnBindWindow();
	}
	//释放资源
	if (dm != NULL)
	{
		delete dm;
		dm = NULL;
	}
	yys_function yys;
	yys.print_log(_T("助手执行完毕!\r\n"), 1);
	threadState[1].stop = true;
	threadState[1].start = false;
	return 1;
}

void CGame2::OnBnClickedBtnStart2()
{
	//显示日志
	m_tab2_right.SetCurSel(2);
	//开启一个线程
	if (!threadState[1].start) {
		threadState[1].start = true;
		threadState[1].stop = false;
		AfxBeginThread(ThreadProc2, this);
	}else {
		MessageBox(_T("请勿重复启动！"));
	}
}


void CGame2::OnBnClickedBtnSuspend2()
{
	yys_function yysFunc;
	threadState[1].suspend_flag = !threadState[1].suspend_flag;
	if (threadState[1].suspend_flag)
	{
		if (!threadState[1].start) {
			yysFunc.print_log(_T("线程状态为停止，无需挂起！\r\n"), 1);
			return;
		}
		yysFunc.print_log(_T("正在挂起线程...\r\n"),1);
		threadState[1].pause = true;

	}
	else {
		if (!threadState[1].start) {
			yysFunc.print_log(_T("线程状态为停止，无需恢复！\r\n"), 1);
			return;
		}
		yysFunc.print_log(_T("正在恢复线程...\r\n"),1);
		threadState[1].pause = false;
	}
}


void CGame2::OnBnClickedBtnStop2()
{
	yys_function yysFunc;
	if (threadState[1].stop) {
		yysFunc.print_log(_T("线程未开启，无需停止！\r\n"), 1);
		return;
	}
	yysFunc.print_log(_T("正在停止线程...\r\n"), 1);
	threadState[1].stop = true;
}

//导入
void CGame2::OnBnClickedBtnImport()
{
	//单选；
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt||"));
	if (fileDlg.DoModal() == IDOK) {
		CString filePath = fileDlg.GetPathName();
		yys_function yysFunc;
		CStringArray taskList;
		int listSize = yysFunc.ReadFile(filePath, taskList);
		for (int i = 0; i < listSize; i++) {
			m_list_taskshow.InsertItem(m_list_taskshow.GetItemCount(), taskList.GetAt(i));
		}
	}
}

//导出
void CGame2::OnBnClickedBtnExport()
{
	//单选；
	CFileDialog fileDlg(FALSE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt||"));
	if (fileDlg.DoModal() == IDOK) {
		CStringArray taskList;
		CString filePath = fileDlg.GetPathName();
		int listSize = m_list_taskshow.GetItemCount();
		for (int i = 0; i < listSize; i++) {
			taskList.Add(m_list_taskshow.GetItemText(i, 0));
		}
		yys_function yysFunc;

		yysFunc.WriteFile(filePath, taskList);
	}
}
HBRUSH CGame2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_HANDLE_TIPS2 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS3 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS4 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}