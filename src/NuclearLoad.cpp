#include "NuclearLoad.hpp"

NuclearLoad::NuclearLoad(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 300), wxCLOSE_BOX | wxMINIMIZE_BOX){
    this->SetMinSize(this->GetSize());
    this->SetMaxSize(this->GetSize());
    
    wxPoint pos = {10, 0};
    this->txt_val = new wxTextCtrl(this, wxID_ANY, "1", wxPoint(pos.x, 20), wxSize(100, 50), wxTE_PROCESS_ENTER, wxIntegerValidator<int>());
    this->txt_val->Bind(wxEVT_TEXT, &NuclearLoad::CallInTextMethod, this);
    
    this->button_start = new wxButton(this, wxID_ANY, "Start", wxPoint(pos.x, 85), wxDefaultSize);
    this->button_start->Bind(wxEVT_BUTTON, &NuclearLoad::CallButtonStartMethod, this);
    
    this->button_stop  = new wxButton(this, wxID_ANY, "Stop",  wxPoint(pos.x, 120), wxDefaultSize);
    this->button_stop->Bind(wxEVT_BUTTON, &NuclearLoad::CallButtonStopMethod, this);
    
    this->slider = new wxSlider(this, wxID_ANY, 1, 1, this->GetMaxCpuThread(), wxPoint(pos.x, 200), wxSize(200, 20),  wxSL_HORIZONTAL);
    this->Bind(wxEVT_SLIDER, &NuclearLoad::CallSliderMethod, this);
    
    this->g_selected_th = new wxGauge(this, wxID_ANY, this->slider->GetMax(), wxPoint(pos.x, 245), this->slider->GetSize());
    
    const int s_pixel = 5; // Here we specify the size in pixels of the value that can occupy the frame.
    this->s_text_min      = new wxStaticText(this, wxID_ANY, std::to_string(this->slider->GetMin()),   wxPoint(pos.x,                              235));
    this->s_text_selected = new wxStaticText(this, wxID_ANY, std::to_string(this->slider->GetValue()), wxPoint(this->slider->GetSize().x /2,       235));
    this->s_text_max      = new wxStaticText(this, wxID_ANY, std::to_string(this->slider->GetMax()),   wxPoint(this->slider->GetSize().x -s_pixel, 235));
}


void NuclearLoad::CallInTextMethod(wxCommandEvent &inv){
    long val = 0;
    if (this->txt_val->GetValue().ToLong(&val)){
        if (val > MAX_IN_VALUE){
            this->txt_val->SetValue(std::to_string(MAX_IN_VALUE));
        }
    }
}

void NuclearLoad::CallButtonStartMethod(wxCommandEvent&){
}
 
void NuclearLoad::CallButtonStopMethod(wxCommandEvent&){
}

void NuclearLoad::CallSliderMethod(wxCommandEvent &evt){
    int s_val = evt.GetInt();
    if (s_val >= 1){
        std::cout << s_val << std::endl;
        this->g_selected_th->SetValue(s_val);
        this->s_text_selected->SetLabel(wxString::Format("%d", s_val));
    }
}

unsigned NuclearLoad::GetMaxCpuThread(){
    return std::thread::hardware_concurrency();
}
