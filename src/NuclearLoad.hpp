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
#include "CollatzClass.hpp"

constexpr int MAX_IN_VALUE = 10000000;

class NuclearLoad : public wxFrame{
    wxTextCtrl *txt_val;
    wxButton *button_start;
    wxButton *button_stop;
public:
    NuclearLoad(const wxString& title);
    
private:
    void CellInText(wxCommandEvent&);
    void CellButtonStart(wxCommandEvent&);
    void CellButtonStop(wxCommandEvent&);
};

#endif /* NuclearLoad_hpp */
