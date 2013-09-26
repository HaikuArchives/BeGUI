//ResEDgarMain.cpp

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "ResEDgarApp.h"
const char * ResEDgarVersion = "ResEDgar 1.1.0, Ed Musgrove, BeDev#2076";

int main(void)
{
   MyApp my_app;
   my_app.Run();
   return B_OK;
}
