/***************************************************************
 * Name:      wxwidgets_testApp.cpp
 * Purpose:   Code for Application Class
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#include "wxwidgets_testApp.h"

//(*AppHeaders
#include "wxwidgets_testMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxwidgets_testApp);

bool wxwidgets_testApp::OnInit()
{
    //(*AppInitialize
    wxLocale m_locale;
 	m_locale.Init(wxLANGUAGE_RUSSIAN);

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxwidgets_testDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
