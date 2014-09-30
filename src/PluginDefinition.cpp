//this file is part of notepad++
//Copyright (C)2003 Don HO <donho@altern.org>
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "PluginDefinition.h"
#include "menuCmdID.h"
#include "sqlFormat.h"
#include "HelpDialog.h"

//
// The plugin data that Notepad++ needs
//
FuncItem funcItem[nbFunc];

//
// The data of Notepad++ that you can use in your plugin commands
//
NppData nppData;

HelpDlg	helpDlg;

HINSTANCE hInstance = NULL;
//
// Initialize your plugin data here
// It will be called while plugin loading   
void pluginInit(HANDLE hModule)
{
	hInstance = (HINSTANCE)hModule;
}

//
// Here you can do the clean up, save the parameters (if any) for the next session
//
void pluginCleanUp()
{
}

//
// Initialization of your plugin commands
// You should fill your plugins commands here
void commandMenuInit()
{

    //--------------------------------------------//
    //-- STEP 3. CUSTOMIZE YOUR PLUGIN COMMANDS --//
    //--------------------------------------------//
    // with function :
    // setCommand(int index,                      // zero based number to indicate the order of command
    //            TCHAR *commandName,             // the command name that you want to see in plugin menu
    //            PFUNCPLUGINCMD functionPointer, // the symbol of function (function pointer) associated with this command. The body should be defined below. See Step 4.
    //            ShortcutKey *shortcut,          // optional. Define a shortcut to trigger this command
    //            bool check0nInit                // optional. Make this menu item be checked visually
    //            );
    setCommand(0, TEXT("Format"), format, NULL, false);
	setCommand(1, TEXT("About"), about, NULL, false);
}

//
// Here you can do the clean up (especially for the shortcut)
//
void commandMenuCleanUp()
{
	// Don't forget to deallocate your shortcut here
}


//
// This function help you to initialize your plugin commands
//
bool setCommand(size_t index, TCHAR *cmdName, PFUNCPLUGINCMD pFunc, ShortcutKey *sk, bool check0nInit) 
{
    if (index >= nbFunc)
        return false;

    if (!pFunc)
        return false;

    lstrcpy(funcItem[index]._itemName, cmdName);
    funcItem[index]._pFunc = pFunc;
    funcItem[index]._init2Check = check0nInit;
    funcItem[index]._pShKey = sk;

    return true;
}

//----------------------------------------------//
//-- STEP 4. DEFINE YOUR ASSOCIATED FUNCTIONS --//
//----------------------------------------------//

DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// Get the current scintilla
	int which = -1;
	::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
	if (which == -1)
		return 0;
	HWND curScintilla = (which == 0)?nppData._scintillaMainHandle:nppData._scintillaSecondHandle;

	int start = ::SendMessage(curScintilla, SCI_GETSELECTIONNSTART, 0, NULL);
	int end = ::SendMessage(curScintilla, SCI_GETSELECTIONNEND, 0, NULL);

	int nLength = end - start;
	if(nLength > 0){
		CHAR * pBuffer = new CHAR[nLength + 1];

		::memset ((void *)pBuffer, 0, sizeof(CHAR) * (nLength + 1));

		int nTempLength = (int) ::SendMessageA(curScintilla, SCI_GETSELTEXT, nLength + 1, (LPARAM)pBuffer);

		CHAR * result = sqlFormat(pBuffer);

		if(result!=NULL){
			int posCurrent = ::SendMessage(curScintilla,SCI_GETCURRENTPOS,0,0);
			::SendMessage(curScintilla, SCI_REPLACESEL, 0, (LPARAM)result);
			::SendMessage(curScintilla,SCI_SETSEL,start, start+strlen(result));
			//::SendMessage(curScintilla,SCI_GOTOPOS,posCurrent,0);
			delete result;
		}

		delete pBuffer;

	}
	else{
		nLength = ::SendMessage(curScintilla, SCI_GETLENGTH, 0, NULL);

		CHAR * pBuffer = new CHAR[nLength + 1];

		::memset ((void *)pBuffer, 0, sizeof(CHAR) * (nLength + 1));

		int nTempLength = (int) ::SendMessageA(curScintilla, SCI_GETTEXT, nLength + 1, (LPARAM)pBuffer);

		// Say hello now :
		// Scintilla control has no Unicode mode, so we use (char *) here
		CHAR * result = sqlFormat(pBuffer);

		if(result!=NULL){
			::SendMessage(curScintilla, SCI_SETTEXT, 0, (LPARAM)result);
			delete result;
		}

		delete pBuffer;
	}
	return 0;
}

void format()
{
	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(ThreadProc, INFINITE);
}

void about()
{
	helpDlg.init(hInstance, nppData);
	helpDlg.doDialog();
}