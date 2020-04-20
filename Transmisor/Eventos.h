#pragma once

//class P3D;


extern P3D* Prep3d;
extern Socket* Sock;

// test
void Evento_Estado(int Estado, string Detalle) {
	Funciones::Debug(to_string(Estado), Detalle);
}
void Evento_Input(string Data) {

}
//

void Event_Conexion_Sim() {
	// test
	Sock->Event_Status(Evento_Estado);
	Sock->Event_Input(Evento_Input);
	Sock->Listen("127.0.0.1", 6000);
	//

	if (Prep3d->Connect()) {
		RichSimu->TextLine("Conexion establecida");
		// Habilitar botones
		// Deshabilitar elementos
		Boton_AftOverHead->Set_Enable();
		Boton_FwdOverHead->Set_Enable();
		Boton_GlareShield->Set_Enable();
		Boton_FwdPanel->Set_Enable();
		Boton_LowPanel->Set_Enable();
		Boton_ContStand->Set_Enable();

		Boton_a_Sim->Set_Enable();
		Boton_de_Sim->Set_Enable();
		Boton_a_Placa1->Set_Enable();
		Boton_a_Placa2->Set_Enable();
		Boton_de_Placa->Set_Enable();
		Boton_a_Calib->Set_Enable();
	}
	else {
		RichSimu->TextLine("Conexion no establecida");

	}
}

void Event_Desconexion_Sim() {
	Prep3d->Disconnect();
	RichSimu->TextLine("Conexion cerrada");
	// Deshabilitar elementos
	Boton_AftOverHead->Set_Disable();
	Boton_FwdOverHead->Set_Disable();
	Boton_GlareShield->Set_Disable();
	Boton_FwdPanel->Set_Disable();
	Boton_LowPanel->Set_Disable();
	Boton_ContStand->Set_Disable();

	Boton_a_Sim->Set_Disable();
	Boton_de_Sim->Set_Disable();
	Boton_a_Placa1->Set_Disable();
	Boton_a_Placa2->Set_Disable();
	Boton_de_Placa->Set_Disable();
	Boton_a_Calib->Set_Disable();
}

void Event_Resize() {
	//OutputDebugString("CALL FRAME RESIZE\n");
	int Alto = Frame1->Get_Height() - 220;
	int Ancho = Frame1->Get_Width() - 15;
	int Ancho1 = (int)(Ancho * 4.5 / 12);
	int Ancho2 = (int)(Ancho * 2.5 / 12);
	int Ancho3 = (int)(Ancho * 2.5 / 12);
	int Ancho4 = (int)(Ancho * 2.5 / 12);
	int X1 = 10;
	int X2 = X1 + Ancho1;
	int X3 = X2 + Ancho2;
	int X4 = X3 + Ancho3;
	RichSimu->Set_Pos(X1, 210, Ancho1, Alto);
	RichSerie1->Set_Pos(X2, 210, Ancho2, Alto);
	RichSerie2->Set_Pos(X3, 210, Ancho3, Alto);
	RichDebug->Set_Pos(X4, 210, Ancho4, Alto);
}

void Event_Recep_P3D(string Comando, string aPlaca, string Valor_Comando, string Valor_aPlaca) {
	//MultiLineSimu->Add_Line(Comando + "=" + Valor);
	RichSimu->ColorTextEnd("<- " + Comando + "=" + Valor_Comando, RGB(0, 0, 150));
	RichSimu->ColorTextEnd("<< " + aPlaca + "=" + Valor_aPlaca, RGB(150, 0, 150));
}
void Event_Send_P3D(string Comando, string Definicion, string Valor) {
	RichSimu->ColorTextEnd(">> " + Definicion + "(" + Comando + ") = " + Valor, RGB(0, 150, 0));
}

void Event_Activar_After_Overhead() {
	RichSimu->TextLine("AFTER OVER HEAD: ADIRU, PSEU (ENGINE, OXYGEN, ETC)");
	Prep3d->Activate_After_Overhead();
}
void Event_Activar_Fordward_Overhead() {
	RichSimu->TextLine("FORDWARD OVER HEAD: FLIGHT CONTROLS, NAVEGATION, FUEL, ELECTRICAL, APU, ETC");
	Prep3d->Activate_Fordward_Overhead();
}
void Event_Activar_Glareshield() {
	RichSimu->TextLine("GLARE SHIELD: WARNINGS, EFIS, MCP");
	Prep3d->Activate_Glareshield();
}
void Event_Activar_Fordward_Panel() {
	RichSimu->TextLine("FORDWARD PANEL: CENTRAL PANEL");
	Prep3d->Activate_Fordward_Panel();
}
void Event_Activar_Low_Fordward_Panel() {
	RichSimu->TextLine("LOW FORDWARD PANEL: LOWER CENTRAL PANEL");
	Prep3d->Activate_Low_Fordward_Panel();
}
void Event_Activar_Control_Stand() {
	RichSimu->TextLine("CONTROL STAND: CDU, FIRE, CARGO, COMM, FMC, SP2, OTHERS ");
	Prep3d->Activate_Control_Stand();
}

void Test2() {
	string Comando, Valor;
	Comando = "THR_SENG1";
	Valor = "50";
	RichSimu->ColorTextEnd("-> " + Comando + " = " + Valor, RGB(0, 150, 150));
	Prep3d->Send(Comando, Valor);
}
void Test1() {
	string Comando, Valor;
	for (int i = 0; i < 50; i++) {
		Comando = "MCP_COUR1";
		Valor = "UP";
		RichSimu->ColorTextEnd("-> " + Comando + " = " + Valor, RGB(0, 150, 150));
		Prep3d->Send(Comando, Valor);

		Comando = "MCP_COUR1";
		Valor = "262144";
		RichSimu->ColorTextEnd("-> " + Comando + " = " + Valor, RGB(0, 150, 150));
		Prep3d->Send(Comando, Valor);
	}
}

void Event_List_DobleClick() {
	string Text;
	Text = Funciones::Split_String(ListBoardSimu->Get_Text(), '-',0);
	Text_Enviar->Set_Text(Text + "=");
}

void Click_aSim() {
	string Comando, Valor;
	Comando = Funciones::Split_String(Text_Enviar->Get_Text(), '=', 0);
	Valor = Funciones::Split_String(Text_Enviar->Get_Text(), '=', 1);
	RichSimu->ColorTextEnd("-> " + Comando + " = " + Valor, RGB(0, 150, 150));
	Prep3d->Send(Comando, Valor);
}

//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Frame1->Assign_Event_Resize(Event_Resize);
	Boton_Sim_Conect->Assign_Event_Click(Event_Conexion_Sim);
	Boton_Sim_DesCon->Assign_Event_Click(Event_Desconexion_Sim);
	
	Boton_AftOverHead->Assign_Event_Click(Event_Activar_After_Overhead);
	Boton_FwdOverHead->Assign_Event_Click(Event_Activar_Fordward_Overhead);
	Boton_GlareShield->Assign_Event_Click(Event_Activar_Glareshield);
	Boton_FwdPanel->Assign_Event_Click(Event_Activar_Fordward_Panel);
	Boton_LowPanel->Assign_Event_Click(Event_Activar_Low_Fordward_Panel);
	Boton_ContStand->Assign_Event_Click(Event_Activar_Control_Stand);
			
	ListBoardSimu->Assign_Event_DobleClick(Event_List_DobleClick);

	Prep3d->Assign_Event_Reception(Event_Recep_P3D);
	Prep3d->Assign_Event_Send(Event_Send_P3D);
	//Prep3d.aas

	// Test
	Boton_a_Sim->Assign_Event_Click(Click_aSim);
	Boton_de_Sim->Assign_Event_Click(Test2);

}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	// Cambiar fuentes de Listbox
	ListBoardSimu->Set_Font("Consolas");
	ListSimuBoard->Set_Font("Consolas");
	RichSimu->Set_Font("Consolas");
	// Cargar List Box Board Simu
	std::vector <ST_BOARD_SIMU> vecBoarSimu;
	vecBoarSimu = Prep3d->Get_Board_Simu();
	for (int i = 0; i < vecBoarSimu.size(); i++) {
		string ID = to_string(vecBoarSimu[i].ID);
		string Board = vecBoarSimu[i].Board;
		string Simu = vecBoarSimu[i].Simu;
		ListBoardSimu->Add_Line(Board + " -> " + Simu + " (" + ID + ")");
	}
	// Cargar List Box Simu Board
	std::vector <ST_SIMU_BOARD> vecSimuBoard;
	vecSimuBoard = Prep3d->Get_Simu_Board();
	for (int i = 0; i < vecSimuBoard.size(); i++) {
		string Simu = vecSimuBoard[i].Simu;
		string Board = vecSimuBoard[i].Board;
		Funciones::RedimSTR(Simu, 30);
		ListSimuBoard->Add_Line(Simu + " -> " + Board);
	}
	// Deshabilitar elementos
	Boton_AftOverHead->Set_Disable();
	Boton_FwdOverHead->Set_Disable();
	Boton_GlareShield->Set_Disable();
	Boton_FwdPanel->Set_Disable();
	Boton_LowPanel->Set_Disable();
	Boton_ContStand->Set_Disable();

	Boton_a_Sim->Set_Disable();
	Boton_de_Sim->Set_Disable();
	Boton_a_Placa1->Set_Disable();
	Boton_a_Placa2->Set_Disable();
	Boton_de_Placa->Set_Disable();
	Boton_a_Calib->Set_Disable();

	//Test
	//RichGeneral->ColorText("hola", RGB(250, 0, 0));
	//RichGeneral->ColorText("como", RGB(0, 250, 0));
	//RichGeneral->ColorTextEnd("Estas", RGB(0, 0, 250));
	//RichGeneral->ColorText("NUEVO?", RGB(250, 0, 0));
}