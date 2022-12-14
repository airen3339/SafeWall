#ifndef __UIACTIVEX_H__
#define __UIACTIVEX_H__

#pragma once
#include <mshtmhst.h>
#include "Utils/downloadmgr.h"
#include "Utils/Internal.h"
struct IOleObject;


namespace UiLib {
/////////////////////////////////////////////////////////////////////////////////////
//

class CActiveXCtrl;

/////////////////////////////////////////////////////////////////////////////////////
//

class UILIB_API CActiveXUI : public CControlUI, public IMessageFilterUI
{
    friend class CActiveXCtrl;
public:
    CActiveXUI();
    virtual ~CActiveXUI();

    LPCTSTR GetClass() const;
	LPVOID GetInterface(LPCTSTR pstrName);

    HWND GetHostWindow() const;

    bool IsDelayCreate() const;
    void SetDelayCreate(bool bDelayCreate = true);

    bool CreateControl(const CLSID clsid);
    bool CreateControl(LPCTSTR pstrCLSID);
    HRESULT GetControl(const IID iid, LPVOID* ppRet);
	CLSID GetClisd() const;
    CDuiString GetModuleName() const;
    void SetModuleName(LPCTSTR pstrText);

    void SetVisible(bool bVisible = true);
    void SetInternVisible(bool bVisible = true);
    void SetPos(RECT rc);
    void DoPaint(HDC hDC, const RECT& rcPaint);

    void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
	void SetExternalUIHandler(IDocHostUIHandler* handler);
	void SetDownloadManager(IDownloadManager* handler);
	void SetDispatchHandler(IDispatch* handler);

    LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);

protected:
    virtual void ReleaseControl();
    virtual bool DoCreateControl();

protected:
    CLSID m_clsid;
    CDuiString m_sModuleName;
    bool m_bCreated;
    bool m_bDelayCreate;
    IOleObject* m_pUnk;
    CActiveXCtrl* m_pControl;
    HWND m_hwndHost;
	IDocHostUIHandler* m_HostUIHandler;
	IDownloadManager* m_pDownMan;
	IDispatch*	m_pHostDispatch;
};

} // namespace UiLib

#endif // __UIACTIVEX_H__
