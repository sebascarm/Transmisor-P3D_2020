#pragma once

//class P3D;


extern P3D* Prep3d;

void Event_Conexion_Sim() {
	if (Prep3d->Connect()) {
		RichSimu->TextLine("Conexion establecida");
		// Habilitar botones
		// Deshabilitar elementos
		Boton_GlareShield->Set_Enable();
		Boton_MCP->Set_Enable();
		Boton_MIP->Set_Enable();
		Boton_YOK->Set_Enable();
		Boton_FIR->Set_Enable();
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
	Boton_GlareShield->Set_Disable();
	Boton_MCP->Set_Disable();
	Boton_MIP->Set_Disable();
	Boton_YOK->Set_Disable();
	Boton_FIR->Set_Disable();
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

void Event_Activar_GlShield() {
	Prep3d->Activate_Glareshield();
}

void Test() {
	string Comando, Valor;
	Comando = "THR_SENG1";
	Valor = "50";
	RichSimu->ColorTextEnd("-> " + Comando + " = " + Valor, RGB(0, 150, 150));
	Prep3d->Send(Comando, Valor);
}
void Test2() {
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
//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Frame1->Assign_Event_Resize(Event_Resize);
	Boton_Sim_Conect->Assign_Event_Click(Event_Conexion_Sim);
	Boton_Sim_DesCon->Assign_Event_Click(Event_Desconexion_Sim);
	Boton_GlareShield->Assign_Event_Click(Event_Activar_GlShield);

	Prep3d->Assign_Event_Reception(Event_Recep_P3D);
	Prep3d->Assign_Event_Send(Event_Send_P3D);
	//Prep3d.aas

	// Test
	Boton_a_Sim->Assign_Event_Click(Test);
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
		ListBoardSimu->Add_Line(ID + " - " + Board + " -> " + Simu);
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
	Boton_GlareShield->Set_Disable();
	Boton_MCP->Set_Disable();
	Boton_MIP->Set_Disable();
	Boton_YOK->Set_Disable();
	Boton_FIR->Set_Disable();
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