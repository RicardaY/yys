#pragma once
#include "CGame_YuHun1.h"
#include "Tabsheet.h"
#include "CGame_jueXing1.h"
#include "CGame_RiLunZhiYun1.h"
#include "CGame_YongShengZhiHai1.h"
#include "CGame_TanSuo1.h"
#include "CGame_YaoQiFengYin1.h"
#include "CGame_YeYuanHuo1.h"
#include "CGame_YuLing1.h"
#include "CGame_GeRenTuPo1.h"
#include "CGame_NewEvent1.h"
#include "CGame_Rest1.h"
#include "CGame_inDependentFunc1.h"
#include "CGame_RunLog1.h"
#include "CGame_ChangeEquip1.h"
#include "CDragStatic.h"


// CGame1 对话框

class CGame1 : public CDialog
{
	DECLARE_DYNAMIC(CGame1)

public:
	CGame1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// game1 mode
	CTabSheet m_tab_game1_mode;
	// 右侧Tab Control
	CTabSheet m_tab1_right;
	//game1 all mode class
	CGame_YuHun1 yuhun1;
	CGame_JueXing1 juexing1;
	CGame_RiLunZhiYun1 riLunZhiYun1;
	CGame_YongShengZhiHai1 yongShengZhiHai1;
	CGame_TanSuo1 tanSuo1;
	CGame_YaoQiFengYin1 yaoQiFengYin1;
	CGame_YeYuanHuo1 yeYuanHuo1;
	CGame_YuLing1 yuLing1;
	CGame_GeRenTuPo1 geRenTuPo1;
	CGame_NewEvent1 newEvent1;
	CGame_Rest1 rest1;
	CGame_inDependentFunc1 dependent_func1;
	CGame_RunLog1 runlog1;
	CGame_ChangeEquip1 changeEquip1;
	virtual BOOL OnInitDialog();
	// game1客户端类型
	CComboBox m_windowType1;
	// 句柄还是窗口
	CComboBox m_win_or_handle1;
	// 显示任务
	CListCtrl m_list_taskshow;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	// 拖动的图片控件
	CDragStatic m_DragStatic1;
	afx_msg void OnBnClickedBtnDeleteSelectTask1();
	afx_msg void OnBnClickedBtnClearTaskList1();
	afx_msg void OnBnClickedBtnStart1();
	// 获得句柄
	CStatic m_hadleText;
	afx_msg void OnBnClickedBtnSuspend1();
	afx_msg void OnBnClickedBtnStop1();
	CStatic m_version;
	afx_msg void OnBnClickedTaskup();
	afx_msg void OnBnClickedTaskdown();
	afx_msg void OnBnClickedBtnImport();
	afx_msg void OnBnClickedBtnExport();
	// 循环次数
	CEdit m_circle;
};
