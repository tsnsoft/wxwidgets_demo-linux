/***************************************************************
 * Name:      wxwidgets_testApp.h
 * Purpose:   Defines Application Class
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#ifndef WXWIDGETS_TESTAPP_H
#define WXWIDGETS_TESTAPP_H

#include <wx/app.h>

class wxwidgets_testApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXWIDGETS_TESTAPP_H
