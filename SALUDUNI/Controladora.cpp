#include "Controladora.h"

void  Controladora::control_0() {
	int op = 0;
	control_66();
	do {
		op = control_1();
		control_65(op);
	} while (op != 4);
}
//----------------------------------------
int Controladora::control_1() {
	return Vista::menu_1();
}
int Controladora::control_2() {
	return Vista::menuCita();
}
void Controladora::control_3() {
	Vista::ingresaCita();
}
void Controladora::control_4() {
	Vista::eliminaCita();
}
void Controladora::control_5() {
	Vista::editaCita();
}
void Controladora::control_6() {
	Vista::citasPorPaciente();
}
void Controladora::control_7() {
	Vista::salir_menu1();
}
void Controladora::control_8(int opx) {
	switch (opx) {
	case 1: control_3(); break;
	case 2: control_67(); break;
	case 3: control_4(); break;
	case 4: control_5(); break;
	case 5: control_6(); break;
	case 6: control_7(); break;
	}
}
//----------------------------------------

//****
int Controladora::control_9() {
	return Vista::menu_2();
}
int Controladora::control_10() {
	return Vista::menuIngresaPaciente();
}
void Controladora::control_11() {
	Vista::ingresaProfProp();
}
void Controladora::control_12() {
	Vista::ingresaProfInte();
}
void Controladora::control_13() {
	Vista::ingresaEstNac();
}
void Controladora::control_14() {
	Vista::ingresaEstInt();
}
void Controladora::control_15(int opx) {
	switch (opx) {
	case 1: control_11(); break;
	case 2: control_12(); break;
	case 3: control_13(); break;
	case 4: control_14(); break;
	}
}
void Controladora::control_16() {
	Vista::eliminaPaciente();
}
int Controladora::control_17() {
	return Vista::menuEditaPaciente();
}
void Controladora::control_18() {
	Vista::editaPP();
}
void Controladora::control_19() {
	Vista::editaPI();
}
void Controladora::control_20() {
	Vista::editaEN();
}
void Controladora::control_21() {
	Vista::editaEI();
}
void Controladora::control_22(int opx) {
	switch (opx) {
	case 1: control_18(); break;
	case 2: control_19(); break;
	case 3: control_20(); break;
	case 4: control_21(); break;
	}
}
//****

void Controladora::control_23() {
	Vista::ingresaMedico();
}
void Controladora::control_24() {
	Vista::eliminaMedico();
}
void Controladora::control_25() {
	Vista::editarMedico();
}
int Controladora::control_26() {
	return Vista::menuIngresaTransporte();
}
void Controladora::control_27() {
	Vista::ingresaTaxi();
}
void Controladora::control_28() {
	Vista::ingresaAmbulancia();
}
void Controladora::control_29(int opx) {
	switch (opx) {
	case 1: control_27(); break;
	case 2: control_28(); break;
	}
}
void Controladora::control_30() {
	Vista::eliminaTransporte();
}

int Controladora::control_31() {
	return Vista::menuEditaTransporte();
}

void Controladora::control_32() {
	Vista::editaTaxi();
}
void Controladora::control_33() {
	Vista::editaAmbulancia();
}
void Controladora::control_34(int opx) {
	switch (opx) {
	case 1: control_32(); break;
	case 2: control_33(); break;
	}
}
void Controladora::control_35() {
	Vista::salir_menu2();
}
int Controladora::control_36() {
	return Vista::menu_3();
}
//--------------------------------
void Controladora::control_37() {
	Vista::mostrarPacientes();
}
void Controladora::control_38() {
	Vista::mostrarProfesores();
}
void Controladora::control_39() {
	Vista::mostrarEstudiantes();
}
void Controladora::control_40() {
	Vista::buscarPaciente();
}
void Controladora::control_41() {
	Vista::muestraTransportes();
}
void Controladora::control_42() {
	Vista::mostrarAmbulancias();
}
void Controladora::control_43() {
	Vista::mostrarTaxis();
}
void Controladora::control_44() {
	Vista::buscarTransporte();
}
void Controladora::control_45() {
	Vista::mostrarMedicos();
}
void Controladora::control_46() {
	Vista::buscarMedico();
}
void Controladora::control_47() {
	Vista::mostrarDatosEmpresa();
}
void Controladora::control_48() {
	Vista::montoPagarTaxis();
}
void Controladora::control_49() {
	Vista::personaConMasCitas();
}
void Controladora::control_50() {
	Vista::fechaConMasPacientes();
}
void Controladora::control_51() {
	Vista::transporteMasUsado();
}
void Controladora::control_52() {
	Vista::ambulanciasOcupadas();
}
void Controladora::control_53() {
	Vista::ProfesInterinos_Calificacion();
}
void Controladora::control_54() {
	Vista::listaExiliados();
}
void Controladora::control_55() {
	Vista::salir_menu3();
}
void Controladora::control_55_1() {
	Vista::salir_menuP();
}

void Controladora::control_56(int opx) {
	switch (opx) {
	case 1:control_37(); break;
	case 2:control_38(); break;
	case 3:control_39(); break;
	case 4:control_40(); break;
	case 5:control_41(); break;
	case 6:control_42(); break;
	case 7:control_43(); break;
	case 8:control_44(); break;
	case 9:control_45(); break;
	case 10:control_46(); break;
	case 11:control_47(); break;
	case 12:control_48(); break;
	case 13:control_49(); break;
	case 14:control_50(); break;
	case 15:control_51(); break;
	case 16:control_52(); break;
	case 17:control_53(); break;
	case 18:control_54(); break;
	case 19:control_55(); break;
	case 20:control_55_1(); break;
	}
}

void Controladora::control_57() { //SUBEMENU #1 -> subemnu de citas
	int op = 0;
	do {
		op = control_2();
		control_8(op); system("pause");
	} while (op != 6);
}

void Controladora::control_58() { //SUBMENU #2 -> submenu de mantenimiento
	int op1 = 0;
	do {
		op1 = control_9();
		control_64(op1);
	} while (op1 != 10);
}

void Controladora::control_59() { //SUBMENU #3 -> submenu de busquedas
	int op = 0;
	do {
		op = control_36();
		control_56(op);
	} while (op != 19);
}

//Menu Editar e Ingresar
void Controladora::control_60() {
	int op = 0;
	op = control_10();
	control_15(op);
}
void Controladora::control_61() {
	int op = 0;
	op = control_17();
	control_22(op);
}

void Controladora::control_62() {
	int op = 0;
	op = control_26();
	control_29(op);
}

void Controladora::control_63() {
	int op = 0;
	op = control_31();
	control_34(op);
}

void Controladora::control_64(int opx) {
	switch (opx) {
	case 1: control_60(); break;
	case 2: control_16(); break;
	case 3: control_61(); break;
		//---------------------
	case 4: control_23(); break;
	case 5: control_24(); break;
	case 6: control_25(); break;
		//---------------------
	case 7: control_62(); break;
	case 8: control_30(); break;
	case 9: control_63(); break;
	case 10: control_35(); break;
	}
}
void Controladora::control_65(int opx){
	switch (opx) {
	case 1: control_57(); break;
	case 2: control_58(); break;
	case 3: control_59(); break;
	case 4: control_55(); break;
	}
}

void Controladora::control_66() {
	Vista::infoProyecto();
}

void Controladora::control_67() {
	Vista::citaPorCod();
}
