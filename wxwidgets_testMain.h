/***************************************************************
 * Name:      wxwidgets_testMain.h
 * Purpose:   Defines Application Frame
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#ifndef WXWIDGETS_TESTMAIN_H
#define WXWIDGETS_TESTMAIN_H

//(*Headers(wxwidgets_testDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class wxwidgets_testDialog: public wxDialog
{
    public:

        wxwidgets_testDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxwidgets_testDialog();

    private:

        //(*Handlers(wxwidgets_testDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OndoCalcClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxwidgets_testDialog)
        static const long ID_STATICTEXT1;
        static const long ID_STATICLINE1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(wxwidgets_testDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxButton* doCalc;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText_Sum;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXWIDGETS_TESTMAIN_H
