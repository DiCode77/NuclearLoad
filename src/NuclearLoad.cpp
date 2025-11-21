#include "NuclearLoad.hpp"
#include <wx/valnum.h>

NuclearLoad::NuclearLoad(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 300), wxCLOSE_BOX | wxMINIMIZE_BOX){
    this->SetMinSize(this->GetSize());
    this->SetMaxSize(this->GetSize());
    
    this->txt_val = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 20), wxSize(100, 50), wxTE_PROCESS_ENTER, wxIntegerValidator<int>());
    this->txt_val->Bind(wxEVT_TEXT, &NuclearLoad::CellInText, this);
    
    this->button_start = new wxButton(this, wxID_ANY, "Start", wxPoint(10, 100), wxDefaultSize);
    this->button_start->Bind(wxEVT_BUTTON, &NuclearLoad::CellButtonStart, this);
    
    this->button_stop  = new wxButton(this, wxID_ANY, "Stop",  wxPoint(10, 150), wxDefaultSize);
    this->button_stop->Bind(wxEVT_BUTTON, &NuclearLoad::CellButtonStop, this);
}


void NuclearLoad::CellInText(wxCommandEvent &inv){
    long val = 0;
    if (this->txt_val->GetValue().ToLong(&val)){
        if (val > MAX_IN_VALUE){
            this->txt_val->SetValue(std::to_string(MAX_IN_VALUE));
        }
    }
}

void NuclearLoad::CellButtonStart(wxCommandEvent&){
}

void NuclearLoad::CellButtonStop(wxCommandEvent&){
}
