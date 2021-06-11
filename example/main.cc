#include <chrono>
#include <cmath>
#include <iostream>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wxFFmpegView.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    wxFFmpegView *ffmpegView;
};

enum { ID_Hello = 1 };

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL,
              wxID_ANY,
              "Hello wxFFmpeg",
              wxDefaultPosition,
              wxSize(640, 480)) {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello,
                     "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxFFmpeg!");
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    ffmpegView = new wxFFmpegView(this);
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(ffmpegView, 1, wxEXPAND);
    SetSizer(mainSizer);

    if (wxTheApp->argc > 1) {
        wxString filename = wxTheApp->argv[1];
        ffmpegView->open(filename.ToStdString());
    } else {
        std::cout << "You can pass a movie file as command line argument, as:\n";
        std::cout << "./build/example/wxFFmpegPlayer movie.mp4\n\n";
    }
}

void MyFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World",
                 wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent &event) {
    wxLogMessage("Hello world from wxWidgets!");
}

wxIMPLEMENT_APP(MyApp);
