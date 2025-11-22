//
//  NuclearLoad.hpp
//  NuclearLoad
//
//  Created by DiCode77.
//

#ifndef NuclearLoad_hpp
#define NuclearLoad_hpp

#include <wx/wx.h>
#include <wx/valnum.h>
#include <wx/slider.h>
#include <thread>
#include "CollatzClass.hpp"

constexpr int MAX_IN_VALUE = 10000000;

class NuclearLoad : public wxFrame{
    wxTextCtrl     *txt_val;
    wxButton       *button_start;
    wxButton       *button_stop;
    wxSlider       *slider;
    wxGauge        *g_selected_th;
    wxStaticText   *s_text_min;
    wxStaticText   *s_text_selected;
    wxStaticText   *s_text_max;
public:
    NuclearLoad(const wxString& title);
    
private:
    void CallInTextMethod(wxCommandEvent&);
    void CallButtonStartMethod(wxCommandEvent&);
    void CallButtonStopMethod(wxCommandEvent&);
    void CallSliderMethod(wxCommandEvent&);
    
    unsigned GetMaxCpuThread();
};

#endif /* NuclearLoad_hpp */
