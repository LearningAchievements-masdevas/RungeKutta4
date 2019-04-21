#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RungeKuttaGraphic::MyForm form;   //Project2 - name of your project
	Application::Run(%form);
}
