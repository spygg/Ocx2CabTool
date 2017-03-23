// stdafx.cpp : source file that includes just the standard includes
//	dirFinder.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"



void GetModulePath(char *szPath)
{
	ASSERT(szPath != NULL);
	
	char szFileName[_MAX_PATH] = {0};
	char szDrive[_MAX_DRIVE] = {0};
	char szDir[_MAX_DIR] = {0};
	
	if (0 != ::GetModuleFileName(0, szFileName, _MAX_PATH))
	{
		_tsplitpath(szFileName, szDrive, szDir, 0, 0);
		
		strcpy(szPath, szDrive);
		strcat(szPath, szDir);
	}
	else
	{
		GetCurrentDirectory(_MAX_PATH, szFileName);
		
		strcpy(szPath, szFileName);
	}
}

BOOL SaveIniFile( const char *szSession, const char *szKey, const char * szSaveValue)
{

	char szFilePath[255] = {0};
	char szFileName[255] = {0};
	
	GetModulePath(szFilePath);	
	sprintf(szFileName, "%s%s", szFilePath, "sample_xxxxxx_sample.ini");
	
	if(szSession == NULL && szKey == NULL && szSaveValue == NULL)
	{
		CFile file;
		file.Remove(szFileName);
	}

	
	BOOL bRet = WritePrivateProfileString(szSession, szKey, szSaveValue, szFileName);	
	
	return bRet;
}

BOOL LoadIniFile( const char *szSession, const char *szKey, char *szGetResult)
{
	if(szGetResult == NULL)
	{
		return FALSE;
	}
	
	char szFilePath[255] = {0};
	char szFileName[255] = {0};
	char szRet[256] = {0};
	
	GetModulePath(szFilePath);	
	sprintf(szFileName, "%s%s", szFilePath, "sample_xxxxxx_sample.ini");
	
	
	int iRet = GetPrivateProfileString(szSession, szKey, (""), szRet, 256, szFileName);
	strcpy(szGetResult, szRet);
	
	return iRet;
}
