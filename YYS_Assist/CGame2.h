#pragma once
#include "Tabsheet.h"
#include "CGame_YuHun2.h"
#include "CGame_JueXing2.h"
#include "CGame_RiLunZhiYun2.h"
#include "CGame_YongShengZhiHai2.h"
#include "CGame_TanSuo2.h"
#include "CGame_YaoQiFengYin2.h"
#include "CGame_YeYuanHuo2.h"
#include "CGame_YuLing2.h"
#include "CGame_GeRenTuPo2.h"
#include "CGame_NewEvent2.h"
#include "CGame_Rest2.h"
#include "CGame_inDependentFunc2.h"
#include "CGame_RunLog2.h"
#include "CGame_ChangeEquip2.h"
#include "CDragStatic.h"


// CGame2 对话框

class CGame2 : public CDialogEx
{
	DECLARE_DYNAMIC(CGame2)

public:
	CGame2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// game2 mode
	CTabSheet m_tab_game2_mode;
	// 右侧Tab Control
	CTabSheet m_tab2_right;
	//game2 all mode class
	CGame_YuHun2 yuhun2;
	CGame_JueXing2 juexing2;
	CGame_RiLunZhiYun2 riLunZhiYun2;
	CGame_YongShengZhiHai2 yongShengZhiHai2;
	CGame_TanSuo2 tanSuo2;
	CGame_YaoQiFengYin2 yaoQiFengYin2;
	CGame_YeYuanHuo2 yeYuanHuo2;
	CGame_YuLing2 yuLing2;
	CGame_GeRenTuPo2 geRenTuPo2;
	CGame_NewEvent2 newEvent2;
	CGame_Rest2 rest2;
	CGame_inDependentFunc2 independent_func2;
	CGame_RunLog2 runlog2;
	CGame_ChangeEquip2 changeEquip2;
	virtual BOOL OnInitDialog();
	// game2客户端类型
	CComboBox m_windowType2;
	// 句柄还是窗口
	CComboBox m_win_or_handle2;
	// 任务列表展示
	CListCtrl m_list_taskshow;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	// 拖动的图片控件
	CDragStatic m_DragStatic2;
	afx_msg void OnBnClickedBtnDeleteSelectTask2();
	afx_msg void OnBnClickedBtnClearTaskList2();
	afx_msg void OnBnClickedBtnStart2();
	afx_msg void OnBnClickedBtnSuspend2();
	afx_msg void OnBnClickedBtnStop2();
	// 句柄显示
	CStatic m_hadleText;
	CStatic m_version;
	afx_msg void OnBnClickedTaskup();
	afx_msg void OnBnClickedTaskdown();
	afx_msg void OnBnClickedBtnImport();
	afx_msg void OnBnClickedBtnExport();
	// 循环次数
	CEdit m_circle;
};
