#include "C_Socket.h"

//#include <iostream>		//para COUT
#include <thread> 		//Para hilos (multiproceso)
#include "Funciones.h"

// using namespace Funciones;

//------------------------------------------------//
//--     SERVIDOR y Cliente						  //
//------------------------------------------------//


//C_Socket::C_Socket() {
//}

C_Socket::~C_Socket() {
	Disconnect();
}

void C_Socket::Initialize() {
	//Inicializamos la DLL de sockets			
	resp = WSAStartup(MAKEWORD(1, 0), &wsaData);
	if (resp) {
		Ev_Status(3, "Error al inicializar socket");
		State = resp;
	}
	else {
		//Obtenemos la IP que usará nuestro servidor...				
		// en este caso localhost indica nuestra propia máquina...	
		hp = (struct hostent*)gethostbyname("localhost");
		if (!hp) {
			Ev_Status(3, "No se ha encontrado servidor...");
			WSACleanup();
			State = WSAGetLastError();
		}
		else {
			// Creamos el socket...
			conn_socket = socket(AF_INET, SOCK_STREAM, 0);
			if (conn_socket == INVALID_SOCKET) {
				Ev_Status(3, "Error al crear socket");
				WSACleanup();
				State = WSAGetLastError();
			}
			else {
				memset(&server, 0, sizeof(server));
				//memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
				server.sin_family = hp->h_addrtype;
				server.sin_addr.s_addr = inet_addr(IP.c_str());
				//server.sin_port = htons(Port);					
				server.sin_port = Port;
				State = 1; // Inicializado
			}
		}
	}
}

void C_Socket::Listen(std::string IP, int Port) {
	this->IP = IP;
	this->Port = Port;
	//int IniResul;
	if (State != 2) { // conectado
		Ev_Status(1, "Inicializando");
		Initialize();
		// Asociamos ip y puerto al socket
		//bind(conn_socket, (struct sockaddr *)&server, sizeof(server));
		if (State == 1) { //Inicializado
			this->resp = ::bind(conn_socket, (struct sockaddr*) & server, sizeof(server));
			if (resp == SOCKET_ERROR) {
				Ev_Status(3, "SERV: Error al asociar puerto e ip al socket");
				closesocket(conn_socket); WSACleanup();
				State = WSAGetLastError();
			}
			else if (listen(conn_socket, 1) == SOCKET_ERROR) {
				Ev_Status(3, "SERV: Error al habilitar conexiones entrantes");
				closesocket(conn_socket); WSACleanup();
				State = WSAGetLastError();
			}
			else {
				// Crear hilo
				thread T_Servidor([this] {Hilo_Servidor(); });
				T_Servidor.detach();
			}
		}
	}
	else {
		Ev_Status(3, "SERV: Conexión Previamente establecida");
	}
}

void C_Socket::Hilo_Servidor() {
	// Aceptamos conexiones entrantes
	int Resul;
	std::string TextLog;
	TextLog = "SERV: Esperando en: " + IP + " " + to_string(Port);
	Ev_Status(4, TextLog);
	stsize = sizeof(struct sockaddr);
	comm_socket = accept(conn_socket, (struct sockaddr*) & client, &stsize);
	if (comm_socket == INVALID_SOCKET) {
		Ev_Status(3, "SERV: Error al aceptar conexión entrante");
		closesocket(conn_socket);
		WSACleanup();
		State = WSAGetLastError();
	}
	else {
		inet_ntoa(client.sin_addr);
		Ev_Status(2, "SERV: Conexión establecida");
		// Como no vamos a aceptar más conexiones cerramos el socket escucha
		closesocket(conn_socket);
		//loop de recepcion de datos
		State = 2; //Conectado
		Es_Servidor = true;
		while (State == 2) {
			Resul = recv(comm_socket, RecvBuff, sizeof(RecvBuff), 0);
			if (Resul == SOCKET_ERROR) {
				State = WSAGetLastError();
				if (State == 10053) {
					Ev_Status(0, "SERV: Conexión Cerrada: " + to_string(State));
				}
				else if (State == 10054) {
					Ev_Status(0, "SERV: Cliente Desconectado: " + to_string(State));
				}
				else {
					Ev_Status(3, "SERV: Error en Conexion: " + to_string(State));
				}
			}
			else {
				Ev_Entrada(RecvBuff);
				//Debug("SERV: Datos recibidos: ", RecvBuff);
			}
		}
		//Reconectar				
		if (State == 10054) {
			Disconnect();
			Listen(IP, Port);
		}
	}
}

//------------------------------------------------//
//--     CLIENTE								  //
//------------------------------------------------//
void C_Socket::Connect(std::string IP, int Port) {
	this->IP = IP;
	this->Port = Port;
	if (State != 2) { // conectado
		Ev_Status(1, "Conectando");
		Initialize();
		if (State == 1) { //Inicializado
			// Crear hilo
			thread T_Cliente([this] {Hilo_Cliente(); });
			T_Cliente.detach();
		}
	}
	else {
		Ev_Status(3, "CLI: Conexión Previamente establecida");
	}
}

void C_Socket::Hilo_Cliente() {
	int Resul;
	// Nos conectamos con el servidor...
	if (connect(conn_socket, (struct sockaddr*) & server, sizeof(server)) == SOCKET_ERROR) {
		Ev_Status(3, "CLI: Fallo al conectarse con el servidor");
		closesocket(conn_socket);
		WSACleanup();
		State = WSAGetLastError();
	}
	else {
		Es_Servidor = false;
		inet_ntoa(server.sin_addr);
		Ev_Status(2, "CLI: Conexión establecida con Servidor");
		State = 2;
		while (State == 2) {
			Resul = recv(conn_socket, RecvBuff, sizeof(RecvBuff), 0);
			if (Resul == SOCKET_ERROR) {
				State = WSAGetLastError();
				if (State == 10053) {
					Ev_Status(0, "CLI: Conexión Cerrada: " + to_string(State));
				}
				else if (State == 10054) {
					Ev_Status(0, "CLI: Servidor Desconectado: " + to_string(State));
				}
				else {
					Ev_Status(3, "CLI: Error en Conexion: " + to_string(State));
				}
			}
			else {
				Ev_Entrada(RecvBuff);
				//Debug("CLI: Datos recibidos: ", RecvBuff);
			}
		}
	}

}

//------------------------------------------------//
//--     AMBOS									  //
//------------------------------------------------//
void C_Socket::Disconnect() {
	// Cerramos el socket y liberamos la DLL de sockets
	State = 0;
	closesocket(conn_socket);
	WSACleanup();
	Ev_Status(0, "Socket Cerrado");
}


void C_Socket::Send(std::string Data) {
	if (State == 2) {
		//strcpy(SendBuff, Data.c_str());
		strcpy_s(SendBuff, strlen(Data.c_str()) + 1, Data.c_str());
		//Enviamos Datos
		//Debug("SEND: ", Data);
		if (Es_Servidor) {
			send(comm_socket, SendBuff, sizeof(SendBuff), 0);
		}
		else {
			send(conn_socket, SendBuff, sizeof(SendBuff), 0);
		}
	}
	else {
		Ev_Status(3, "No se encuentra la conexion establecida (" +  Data + ")");
	}
}

int C_Socket::Get_State() {
	return State;
}
//Export Eventos
void C_Socket::Event_Input(void(*Function)(std::string Data_out)) {
	Ev_Entrada = Function;
}
void C_Socket::Event_Status(void(*Function)(int State, std::string Text)) {
	Ev_Status = Function;
}

//Salida sin accion
void C_Socket::SinAccion(std::string Texto) {
	Funciones::Debug("Salida sin acción: ", Texto);
}

void C_Socket::Ev_SinAccion(int Estado, std::string Texto) {
	Funciones::Debug("Log: ", Texto, " ", to_string(Estado));
}

//EXPORT
Socket* New_Socket() {
	return new C_Socket();
}
