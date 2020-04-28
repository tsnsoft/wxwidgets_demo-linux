/***************************************************************
 * Name:      wxwidgets_testMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#include "wxwidgets_testMain.h"
#include <wx/msgdlg.h>

#include <iostream>
#include <sstream>
#include <cmath>

//(*InternalHeaders(wxwidgets_testDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxwidgets_testDialog)
const long wxwidgets_testDialog::ID_STATICTEXT1 = wxNewId();
const long wxwidgets_testDialog::ID_STATICLINE1 = wxNewId();
const long wxwidgets_testDialog::ID_TEXTCTRL2 = wxNewId();
const long wxwidgets_testDialog::ID_TEXTCTRL1 = wxNewId();
const long wxwidgets_testDialog::ID_BUTTON1 = wxNewId();
const long wxwidgets_testDialog::ID_STATICTEXT3 = wxNewId();
const long wxwidgets_testDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxwidgets_testDialog,wxDialog)
    //(*EventTable(wxwidgets_testDialog)
    //*)
END_EVENT_TABLE()

wxwidgets_testDialog::wxwidgets_testDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxwidgets_testDialog)
    Create(parent, id, _("Пример с  wxWidgets"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Я люблю\nwxWidgets !"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND, 4);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    doCalc = new wxButton(this, ID_BUTTON1, _("Сумма"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(doCalc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_Sum = new wxStaticText(this, ID_STATICTEXT3, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer2->Add(StaticText_Sum, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Выход"), wxDefaultPosition, wxSize(175,43), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxwidgets_testDialog::OndoCalcClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxwidgets_testDialog::OnQuit);
    //*)
}

wxwidgets_testDialog::~wxwidgets_testDialog()
{
    //(*Destroy(wxwidgets_testDialog)
    //*)
}

void wxwidgets_testDialog::OnQuit(wxCommandEvent& event)
// Выход из программы
{
    wxMessageBox(_("С++ с wxWidgets - это круто!"), _("До свидания!"));
    Close();
}

void wxwidgets_testDialog::OndoCalcClick(wxCommandEvent& event)
// Кнопка расчета значения
{
    double a = strtod(TextCtrl1->GetValue(), NULL);
    double b = strtod(TextCtrl2->GetValue(), NULL);
    double c = a + b;
    std::ostringstream foo;
    foo.precision(10);
    foo << c;
    StaticText_Sum->SetLabel(foo.str());
}
