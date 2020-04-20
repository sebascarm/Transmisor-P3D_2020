#pragma once

#include "Socket.h"

#include <stdio.h>
#include <stdlib.h>

//#include <winsock2.h>
//#include <ws2tcpip.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

#include <Windows.h>

#include <string>
//using namespace std;	//para COUT y string

class C_Socket : public Socket {
protected:

	char SendBuff[512], RecvBuff[512];

	WSADATA wsaData;
	SOCKET conn_socket, comm_socket;
	SOCKET comunicacion;
	struct sockaddr_in server;
	struct sockaddr_in client;
	struct hostent *hp;
	int resp, stsize;
	std::string IP;
	int Port;
	void Hilo_Servidor();		
	void Hilo_Cliente();		
	bool Es_Servidor;
	void Initialize();			
	int State;
	static void SinAccion(std::string Enviar);
	static void Ev_SinAccion(int Estado, std::string Texto);
	void(*Ev_Status)(int Estado, std::string Texto) = &Ev_SinAccion;
	void(*Ev_Entrada)(std::string Enviar) = &SinAccion;
public:
	//C_Socket();
	~C_Socket();
	void Listen(std::string IP, int Port);			
	void Connect(std::string IP, int Port);
	void Send(std::string Data);					
	int Get_State();	
	void Disconnect();								
	// Estados: 0: Desconectado					
	// Estados: 1: Inicializando / Conectando	
	// Estados: 2: Conectado					
	// Estados: 3: Error						
	// Estados: 4: Esperando conexion (Servidor)
	
	void Event_Status(void(*Function)(int State, std::string Text));
	void Event_Input(void(*Function)(std::string Data_out));
};