#include <afxwin.h>
class CMainFrame : public CFrameWnd {
public:
    CMainFrame();
protected:
    // Step 1 ? To create ON_WM_CREATE, add afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct); before the DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP()
};

CMainFrame::CMainFrame() {
    // Create the window's frame
    Create(NULL, L"MFC Messages Demo", WS_OVERLAPPEDWINDOW,
        CRect(120, 100, 700, 480), NULL);
}

// Step 3 ? Implementation of OnCreate()
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

class CMessagesApp : public CWinApp {
public:
    BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    // Step 2 ? Add the ON_WM_CREATE() after the BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd) and before END_MESSAGE_MAP()
    ON_WM_CREATE()
END_MESSAGE_MAP()
BOOL CMessagesApp::InitInstance() {
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
CMessagesApp theApp;