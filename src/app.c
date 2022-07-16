#include "ui/main.h"
#include "wordles.h"
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif 
{
  updateWordle();
  #ifdef _WIN32
  SetEnvironmentVariableA("GTK_CSD", "0");
  #endif
  startWindow();
  return 0;
}