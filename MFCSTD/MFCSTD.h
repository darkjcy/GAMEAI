
// MFCSTD.h : MFCSTD ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCSTDApp:
// �� Ŭ������ ������ ���ؼ��� MFCSTD.cpp�� �����Ͻʽÿ�.
//

class CMFCSTDApp : public CWinApp
{
public:
	CMFCSTDApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSTDApp theApp;
