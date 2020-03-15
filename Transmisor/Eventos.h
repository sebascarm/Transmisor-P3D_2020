#pragma once


extern P3D* Prep3d;

void Event_Conexion_Sim() {
	if (Prep3d->Connect()) {
		MultiLineGeneral->Add_Line("Conexion establecida");
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
		MultiLineGeneral->Add_Line("Conexion no establecida");
		
	}
}

void Event_Desconexion_Sim() {
	Prep3d->Disconnect();
	MultiLineGeneral->Add_Line("Conexion cerrada");
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
	int Ancho1 = (int)(Ancho * 4 / 12);
	int Ancho2 = (int)(Ancho * 2.5 / 12);
	int Ancho3 = (int)(Ancho * 2.5 / 12);
	int Ancho4 = (int)(Ancho * 3 / 12);
	int X1 = 10;
	int X2 = X1 + Ancho1;
	int X3 = X2 + Ancho2;
	int X4 = X3 + Ancho3;
	MultiLineGeneral->Set_Pos(X1, 210, Ancho1, Alto);
	MultiLineSerie1->Set_Pos(X2, 210, Ancho2, Alto);
	MultiLineSerie2->Set_Pos(X3, 210, Ancho3, Alto);
	MultiLineSimu->Set_Pos(X4, 210, Ancho4, Alto);
}

void Event_Recep_P3D(string Comando, string Valor) {
	MultiLineSimu->Add_Line(Comando + "=" + Valor);
}

void Event_Activar_GlShield() {
	Prep3d->Activate_Glareshield();
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
}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	// Cambiar fuentes de Listbox
	ListBoardSimu->Set_Font("Courier new");
	ListSimuBoard->Set_Font("Courier new");
	// Cargar List Box Board Simu
	std::vector <EST_BOARD_SIMU> vecBoarSimu;
	vecBoarSimu = Prep3d->Get_Board_Simu();
	for (int i = 0; i < vecBoarSimu.size(); i++) {
		string ID = to_string(vecBoarSimu[i].ID);
		string Board = vecBoarSimu[i].Board;
		string Simu = vecBoarSimu[i].Simu;
		ListBoardSimu->Add_Line(ID + " - " + Board + " -> " + Simu);
	}
	// Cargar List Box Simu Board
	std::vector <EST_SIMU_BOARD> vecSimuBoard;
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
	
}