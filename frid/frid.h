// frid.h : main header file for the FRID application
//

#if !defined(AFX_FRID_H__C5460EAD_0C45_4782_8091_26F009D86369__INCLUDED_)
#define AFX_FRID_H__C5460EAD_0C45_4782_8091_26F009D86369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFridApp:
// See frid.cpp for the implementation of this class
//

class CFridApp : public CWinApp
{
public:
	CFridApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFridApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFridApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRID_H__C5460EAD_0C45_4782_8091_26F009D86369__INCLUDED_)
