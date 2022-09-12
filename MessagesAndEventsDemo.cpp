#include <afxwin.h>
class CMainFrame : public CFrameWnd {
public:
    CMainFrame();
protected:
    DECLARE_MESSAGE_MAP()
};

CMainFrame::CMainFrame() {
    // Create the window's frame
    Create(NULL, L"MFC Messages Demo", WS_OVERLAPPEDWINDOW,
        CRect(120, 100, 700, 480), NULL);
}

class CMessagesApp : public CWinApp {
public:
    BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()
BOOL CMessagesApp::InitInstance() {
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
CMessagesApp theApp;