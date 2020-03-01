#include "C_MessageBox.h"

int C_MessageBox::Create(string Titulo, string Message, M_Message Tipo) {
	// No requiere crear ni contener
	DWORD Estilo;
	switch (Tipo) {
	case M_Message::M_OK:
		Estilo = MB_OK | MB_ICONINFORMATION;
		break;
	case M_Message::M_OKCANCEL:
		Estilo = MB_OKCANCEL | MB_ICONINFORMATION;
		break;
	case M_Message::M_YESNO:
		Estilo = MB_YESNO | MB_ICONINFORMATION;
		break;
	default:
		Estilo = MB_OK | MB_ICONINFORMATION;
		break;
	}
	return MessageBox(NULL, Message.c_str(), Titulo.c_str(), Estilo);

}

Win_MessageBox* New_MessageBox() {
	return new C_MessageBox();
}
