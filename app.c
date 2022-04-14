#include "common.h"
#include "gui.h"
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
#else
int main(int argc, char **argv)
#endif 
{
  gtkMain(
  #ifndef _WIN32
  argc, argv
  #endif
  );
  return 0;
}