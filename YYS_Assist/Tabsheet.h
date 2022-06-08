//Download by http://www.NewXing.com
#if !defined(AFX_TABSHEET_H__42EE262D_D15F_46D5_8F26_28FD049E99F4__INCLUDED_)
#define AFX_TABSHEET_H__42EE262D_D15F_46D5_8F26_28FD049E99F4__INCLUDED_
 
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabSheet.h : header file
//
 
/////////////////////////////////////////////////////////////////////////////
// CTabSheet window
#define MAXPAGE 16
 
class CTabSheet : public CTabCtrl
{
// Construction
public:
    CTabSheet();
 
// Attributes
public:
 
// Operations
public:
 
// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CTabSheet)
    //}}AFX_VIRTUAL
 
// Implementation
public:
    int GetCurSel();
    int SetCurSel(int nItem);
    void Show();
    void SetRect();
    BOOL AddPage(LPCTSTR title, CDialog *pDialog, UINT ID);
    virtual ~CTabSheet();
 
    // Generated message map functions
protected:
    LPCTSTR m_Title[MAXPAGE];
    UINT m_IDD[MAXPAGE];
    CDialog* m_pPages[MAXPAGE];
    int m_nNumOfPages;
    int m_nCurrentPage;
    //{{AFX_MSG(CTabSheet)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
 
    //}}AFX_MSG
 
    DECLARE_MESSAGE_MAP()
};
 
/////////////////////////////////////////////////////////////////////////////
 
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
 
#endif // !defined(AFX_TABSHEET_H__42EE262D_D15F_46D5_8F26_28FD049E99F4__INCLUDED_)