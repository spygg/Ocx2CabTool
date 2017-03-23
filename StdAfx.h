// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__29D9379C_A9D6_4D01_A498_AAAFCE4AA9D6__INCLUDED_)
#define AFX_STDAFX_H__29D9379C_A9D6_4D01_A498_AAAFCE4AA9D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT



void GetModulePath(char *szPath);
BOOL LoadIniFile( const char *szSession, const char *szKey, char *szGetResult);
BOOL SaveIniFile( const char *szSession, const char *szKey, const char * szSaveValue);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__29D9379C_A9D6_4D01_A498_AAAFCE4AA9D6__INCLUDED_)
