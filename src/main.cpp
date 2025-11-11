#include "main.hpp"
#include "NuclearLoad.hpp"

bool MyApp::OnInit(){
    NuclearLoad* frame = new NuclearLoad("NuclearLoad");
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);