// dirFinder.h : main header file for the DIRFINDER application
//

#if !defined(AFX_DIRFINDER_H__E2F33D0B_F1BA_4762_AB70_0DA5AEAA6967__INCLUDED_)
#define AFX_DIRFINDER_H__E2F33D0B_F1BA_4762_AB70_0DA5AEAA6967__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDirFinderApp:
// See dirFinder.cpp for the implementation of this class
//

class CDirFinderApp : public CWinApp
{
public:
	CDirFinderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirFinderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDirFinderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRFINDER_H__E2F33D0B_F1BA_4762_AB70_0DA5AEAA6967__INCLUDED_)
