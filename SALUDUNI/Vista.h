// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "SALUD-UNI.h"

class Vista {
public: 
	static SaludUni* hospital;
public:
	static void infoProyecto();
	static int menu_1();
	//--------------------------------
	static int menuCita();
	static void ingresaCita();
	static void citaPorCod();
	static void eliminaCita();
	static void editaCita();
	static void citasPorPaciente();
	static void salir_menu1();
	//---------------------------------
	static int menu_2();
	//***
	static int menuIngresaPaciente();
	static void ingresaProfProp();
	static void ingresaProfInte();
	static void ingresaEstNac();
	static void ingresaEstInt();
	//***
	static void eliminaPaciente();
	//***
	static int menuEditaPaciente();
	static void editaPP();
	static void editaPI();
	static void editaEN();
	static void editaEI();
	//***
	static void ingresaMedico();
	static void eliminaMedico();
	static void editarMedico();
	//***
	static int menuIngresaTransporte();
	static void creaViaje(Transporte*);
	static void ingresaTaxi();
	static void ingresaAmbulancia();
	//***
	static void eliminaTransporte();
	//***
	static int menuEditaTransporte();
	static void editaTaxi();
	static void editaAmbulancia();
	//***
	static void salir_menu2();
	//------------------------------------
	static int menu_3();
	//***
	static void mostrarPacientes();
	static void mostrarProfesores();
	static void mostrarEstudiantes();
	static void buscarPaciente();
	//***
	static void muestraTransportes();
	static void mostrarAmbulancias();
	static void mostrarTaxis();
	static void buscarTransporte();
	//***
	static void mostrarMedicos();
	static void buscarMedico();
	//***
	static void mostrarDatosEmpresa();
	static void montoPagarTaxis();
	static void personaConMasCitas();
	static void fechaConMasPacientes();
	static void transporteMasUsado();
	static void ambulanciasOcupadas();
	static void ProfesInterinos_Calificacion();
	static void listaExiliados();
	static void salir_menu3();
	//***
	static void salir_menuP();


};