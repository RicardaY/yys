#pragma once


// CDragStatic1

class CDragStatic : public CStatic
{
	DECLARE_DYNAMIC(CDragStatic)

public:
	CDragStatic();
	virtual ~CDragStatic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


