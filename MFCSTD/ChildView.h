#pragma once
// ChildView.h : CChildView Ŭ������ �������̽�
//
#include "gameobj.h"


// CChildView â


class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	double pointx;
	double pointy;
	double xspeed;
	double yspeed;

	
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	void DrawImage(CDC * pDC);
	void firevector();
	void ballmoveout();

	void plcol(Player &p, Land &l);
	void blcol(Land &l);
};

