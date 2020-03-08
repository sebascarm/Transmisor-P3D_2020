#pragma once

#include "WinApi.h"

//******************************************************************//
//**** OBJETOS GLOBALES											****//
//******************************************************************//
Win_Api*	WinApi	= New_Api();
Win_Frame*	Frame1	= New_Frame();
Win_Menu*	Menu1	= New_Menu();

Win_MessageBox* Mensaje = New_MessageBox();

Win_MultiLine* MultiLineGeneral = New_MultiLine();
Win_MultiLine* MultiLineSerie1	= New_MultiLine();
Win_MultiLine* MultiLineSerie2	 = New_MultiLine();
Win_MultiLine* MultiLineSimu	= New_MultiLine();
//Gruop1
Win_GroupBox*	GroupBox1		= New_GroupBox();
Win_Label*		Label1			= New_Label();
Win_Label*		Label2			= New_Label();
Win_Button*		Boton_Serie1	= New_Button();
Win_Button*		Boton_Serie2	= New_Button();
Win_Button*		Boton_Serie_Desc= New_Button();
Win_Button*		Boton_Med_Esc	= New_Button();
Win_Button*		Boton4			= New_Button();
Win_TextBox*	Text_Com1		= New_TextBox();
Win_TextBox*	Text_Com2		= New_TextBox();
Win_Label*		Label13			= New_Label();
Win_TextBox*	Text_Speed		= New_TextBox();
//Gruop2
Win_GroupBox* GroupBox2 = New_GroupBox();
Win_Label* Label3 = New_Label();
Win_Label* Label4 = New_Label();
Win_Label* Label5 = New_Label();
Win_TextBox* Text_Server = New_TextBox();
Win_TextBox* Text_PortServ = New_TextBox();
//Win_TextBox* Text_PortSimu = New_TextBox();
Win_Button* Boton5 = New_Button();
Win_Button* Boton6 = New_Button();
Win_Button* Boton_Sim_Conect = New_Button();
Win_Button* Boton_Sim_DesCon = New_Button();
//Gruop 3
Win_GroupBox* GroupBox3 = New_GroupBox();
Win_Label* Label6 = New_Label();
Win_Label* Label7 = New_Label();
Win_TextBox* Text_Mediador = New_TextBox();
Win_TextBox* Text_PortMedia = New_TextBox();
Win_Button* Boton10 = New_Button();
//Grupo4
Win_Button* Boton_THR = New_Button();
Win_Button* Boton_MCP = New_Button();
Win_Button* Boton_MIP = New_Button();
Win_Button* Boton_YOK = New_Button();
Win_Button* Boton_FIR = New_Button();
//Grupo5
Win_TextBox* Text_Enviar = New_TextBox();
Win_Button* Boton_AServidor = New_Button();
Win_Button* Boton17 = New_Button();
Win_Button* Boton_APlaca1 = New_Button();
Win_Button* Boton_APlaca2 = New_Button();
Win_Button* Boton20 = New_Button();
Win_Button* Boton21 = New_Button();
//Grupo6 (Retardos)
Win_GroupBox* GroupBox4 = New_GroupBox();
Win_Label* Label8 = New_Label();
Win_Label* Label9 = New_Label();
Win_Label* Label10 = New_Label();
Win_TextBox* Text_EnvioSock = New_TextBox();
Win_TextBox* Text_EnvioSerie = New_TextBox();
Win_TextBox* Text_EnvioMed = New_TextBox();
Win_TextBox* Text_RecepSock = New_TextBox();
Win_TextBox* Text_RecepSerie = New_TextBox();
Win_TextBox* Text_Recep_Med = New_TextBox();
Win_Label* Label11 = New_Label();
Win_Label* Label12 = New_Label();

Win_Label* Label18 = New_Label();

// Grupo8 (List box)
Win_GroupBox* GroupBox5 = New_GroupBox();
Win_ListBox* ListBoardSimu = New_ListBox();
Win_ListBox* ListSimuBoard = New_ListBox();

//******************************************************************//
//**** CREAR OBJETOS											****//
//******************************************************************//
void CrearObjetos(HINSTANCE hInstance) {
	//Principal
	WinApi->Create(hInstance);
	Frame1->Create(WinApi, "P3D Tránsmisor", 50, 50, 1100, 600, true);
	//Frame2->Create(WinApi, "test", 50, 50, 100, 100, true);
	Menu1->Create(Frame1, "Menú", { "Cargar Configuración",
									"Guardar Configuración","-",
									"Mostrar Logs",
									"Limpiar Logs", "Motrar Warnings", "-" ,
									"Pedir Configuración",
									"Envíar Configuración", "-",
									"Salir" });
	//Grupo1
	GroupBox1->Create(Frame1, "Conexión con Placas", 10, 5, 210, 95);
	Label1->Create(Frame1, "Placas", 15, 20, 42, 20, W_Align::A_DER);
	Boton_Serie1->Create(Frame1, "Co1", 60, 20, 30);
	Boton_Serie2->Create(Frame1, "Co2", 95, 20, 30);
	Boton_Serie_Desc->Create(Frame1, "Desc", 130, 20, 80);
	Label2->Create(Frame1, "COM", 15, 45, 42, 20, W_Align::A_DER);
	Text_Com1->Create(Frame1, "", 60, 45, 30);
	Text_Com2->Create(Frame1, "", 95, 45, 30);
	Boton4->Create(Frame1, "Pedir", 130, 45, 80, 20);
	Label13->Create(Frame1, "Speed", 15, 70, 42, 20, W_Align::A_DER);
	Text_Speed->Create(Frame1, "", 60, 70, 65);
	//Grupo2
	GroupBox2->Create(Frame1, "Conexión con Servidor", 225, 5, 210, 95);
	Label3->Create(Frame1, "Server", 230, 20, 42, 20, W_Align::A_DER);
	Label4->Create(Frame1, "P. Serv", 230, 45, 42, 20, W_Align::A_DER);
	Label5->Create(Frame1, "Sim", 230, 70, 42, 20, W_Align::A_DER);
	Text_Server->Create(Frame1, "192.168.1.1", 275, 20, 150);
	Text_PortServ->Create(Frame1, "8085", 275, 45, 40);
	//Text_PortSimu->Create(Frame1, "8083", 275, 70, 40);
	Boton5->Create(Frame1, "Conec", 320, 45, 50);
	Boton6->Create(Frame1, "Desc", 375, 45, 50);
	Boton_Sim_Conect->Create(Frame1, "Conec", 320, 70, 50);
	Boton_Sim_DesCon->Create(Frame1, "Desc", 375, 70, 50);
	//Gruop3
	GroupBox3->Create(Frame1, "Conexión con Mediador", 440, 5, 210, 95);
	Label6->Create(Frame1, "Media", 445, 20, 42, 20, W_Align::A_DER);
	Label7->Create(Frame1, "Puerto", 445, 45, 42, 20, W_Align::A_DER);
	Text_Mediador->Create(Frame1, "192.168.1.5", 490, 20, 150);
	Text_PortMedia->Create(Frame1, "8085", 490, 45, 40);
	Boton_Med_Esc->Create(Frame1, "Escuch", 535, 45, 50);
	Boton10->Create(Frame1, "Desc", 590, 45, 50);
	//Grupo4
	Boton_THR->Create(Frame1, "THR", 10, 105, 50);
	Boton_MCP->Create(Frame1, "MCP", 65, 105, 50);
	Boton_MIP->Create(Frame1, "MIP", 120, 105, 50);
	Boton_YOK->Create(Frame1, "YOK", 175, 105, 50);
	Boton_FIR->Create(Frame1, "FIR", 230, 105, 50);
	//Grupo5
	Text_Enviar->Create(Frame1, "", 10, 130, 270);
	Boton_AServidor->Create(Frame1, "A Sim", 10, 155, 50);
	Boton17->Create(Frame1, "De Sim", 65, 155, 50);
	Boton_APlaca1->Create(Frame1, "A Placa1", 120, 155, 50);
	Boton_APlaca2->Create(Frame1, "A Placa2", 175, 155, 50);
	Boton20->Create(Frame1, "De Placa", 230, 155, 50);
	Boton21->Create(Frame1, "A Calib", 285, 155, 50);
	//Grupo6 (retardos)
	GroupBox4->Create(Frame1, "Retardos", 440, 105, 210, 95);
	Label8->Create(Frame1, "Sock", 510, 115, 40);
	Label9->Create(Frame1, "Serie", 555, 115, 40);
	Label10->Create(Frame1, "Med", 600, 115, 40);
	Text_EnvioSock->Create(Frame1, "1", 510, 140, 40);
	Text_EnvioSerie->Create(Frame1, "2", 555, 140, 40);
	Text_EnvioMed->Create(Frame1, "3", 600, 140, 40);
	Text_RecepSock->Create(Frame1, "4", 510, 165, 40);
	Text_RecepSerie->Create(Frame1, "5", 555, 165, 40);
	Text_Recep_Med->Create(Frame1, "6", 600, 165, 40);
	Label11->Create(Frame1, "Envio", 470, 140, 37, 20, W_Align::A_DER);
	Label12->Create(Frame1, "Recep", 470, 165, 37, 20, W_Align::A_DER);

	//Label18->Create(Frame1, "Logs", 10, 220, 45, 20);

	//Grupo 7
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
	MultiLineGeneral->Create(Frame1, "", X1, 210, Ancho1, Alto);
	MultiLineSerie1->Create(Frame1, "", X2, 210, Ancho2, Alto);
	MultiLineSerie2->Create(Frame1, "", X3, 210, Ancho3, Alto);
	MultiLineSimu->Create(Frame1, "", X4, 210, Ancho4, Alto);

	//Gupo 8
	GroupBox5->Create(Frame1,"Comandos" ,655, 5, 370, 195);
	ListBoardSimu->Create(Frame1, 665, 20, 280, 85);
	ListSimuBoard->Create(Frame1, 665, 110, 350, 85);

}















