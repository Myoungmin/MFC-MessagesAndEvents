#include <afxwin.h>
class CMainFrame : public CFrameWnd {
public:
    CMainFrame();
protected:
    // Step 1 : To create ON_WM_CREATE, add afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct); before the DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    
    afx_msg void OnFileNew();

    // Pressing a key causes a WM_KEYDOWN or WM_SYSKEYDOWN message to be placed in the thread message.
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    
    // ON_WM_LBUTTONUP message is sent.
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    // ON_WM_TBUTTONUP message is sent.
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

    DECLARE_MESSAGE_MAP()
};

CMainFrame::CMainFrame() {
    // Create the window's frame
    Create(NULL, L"MFC Messages Demo", WS_OVERLAPPEDWINDOW,
        CRect(120, 100, 700, 480), NULL);
}

// Step 3 : Implementation of OnCreate()
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    // Call the base class to create the window
    if (CFrameWnd::OnCreate(lpCreateStruct) == 0) {

        // If the window was successfully created, let the user know
        MessageBox(L"The window has been created!!!");
        // Since the window was successfully created, return 0
        return 0;
    }
    // Otherwise, return -1
    return -1;
}

void CMainFrame::OnFileNew()
{
    // Create New file
}


// Keyboard 메시지 처리
void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    switch (nChar) {

    case VK_RETURN:
        MessageBox(L"You pressed Enter");
        break;
    case VK_F1:
        MessageBox(L"Help is not available at the moment");
        break;
    case VK_DELETE:
        MessageBox(L"Can't Delete This");
        break;
    default:
        MessageBox(L"Whatever");
    }
}

// ON_WM_LBUTTONDOWN() 메시지 처리
void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
    CString MsgCoord;
    MsgCoord.Format(L"Left Button at P(%d, %d)", point.x, point.y);
    MessageBox(MsgCoord);
}

// ON_WM_RBUTTONUP() 메시지 처리
void CMainFrame::OnRButtonUp(UINT nFlags, CPoint point)
{
    MessageBox(L"Right Mouse Button Up");
}

class CMessagesApp : public CWinApp {
public:
    BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    // Step 2 : Add the ON_WM_CREATE() after the BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd) and before END_MESSAGE_MAP()
    ON_WM_CREATE()

    ON_COMMAND(ID_FILE_NEW, CMainFrame::OnFileNew)

    // Keyboard Message
    ON_WM_KEYDOWN()

    // Mouse Messages
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONUP()

END_MESSAGE_MAP()
BOOL CMessagesApp::InitInstance() {
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
CMessagesApp theApp;