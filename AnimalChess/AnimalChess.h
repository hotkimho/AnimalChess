
// AnimalChess.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAnimalChessApp:
// �� Ŭ������ ������ ���ؼ��� AnimalChess.cpp�� �����Ͻʽÿ�.
//

class CAnimalChessApp : public CWinApp
{
public:
	CAnimalChessApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAnimalChessApp theApp;
