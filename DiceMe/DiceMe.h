
// DiceMe.h : main header file for the DiceMe application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDiceMeApp:
// See DiceMe.cpp for the implementation of this class
//

class CDiceMeApp : public CWinApp
{
public:
	CDiceMeApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDiceMeApp theApp;