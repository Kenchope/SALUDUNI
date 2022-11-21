#include "Vista.h"

SaludUni* Vista::hospital = new SaludUni();

  void Vista::infoProyecto(){
	  cout << " UNIVERSIDAD NACIONAL" << endl;
	  cout << " Curso: Programacion I" << endl;
	  cout << " Estudiante: Santiago Solis Bolanos" << endl;
	  cout << " Estudiante: Kenny Wanchope Rodriguez" << endl;
	  cout << " Proyecto II " << endl;
	  cout << endl;
	  system("pause");
	  system("cls");
  }
  int Vista::menu_1(){
      string ced, num, dir, nom;
      system("cls");
      cout << "Digite los siguientes datos..." << endl;
      cout << "Digite la cedula juridica del hospital: " << endl;
      cin >> ced;
      cout << "Digite el numero de telefono del hospital: " << endl;
      cin >> num;
      cout << "Digite la direccion (sin espacios) del hospital: " << endl;
      cin >> dir;
      cout << "Digite el nombre del hospital: " << endl;
      cin >> nom;
      hospital = new SaludUni(ced, num, dir, nom);
      system("cls");
	  int opcion;
	  cout << "--------HOSPITAL UNIVERSITARIO-------" << endl;
	  cout << "-----------MENU---------" << endl;
	  cout << "     1- Citas           " << endl;
	  cout << "     2- Mantenimiento   " << endl;
	  cout << "     3- Busquedas       " << endl;
	  cout << "     4- Salir       " << endl;
	  cout << "------------------------" << endl;
	  cout << "     Digite la opcion: ";
	  cin >> opcion;
	  return opcion;
  }
//--------------------------------
  int Vista::menuCita() {
	  int opc;
	  system("cls");
	  cout << "-----------SubMenuCitas---------" << endl;
	  cout << "     1- Ingresar Citas           " << endl; 
      cout << "     2- Buscar Cita              " << endl;
	  cout << "     3- Eliminar Citas           " << endl; 
	  cout << "     4- Editar Citas             " << endl; 
	  cout << "     5- Citas por paciente       " << endl; 
	  cout << "     6- Salir                    " << endl;
	  cout << "------------------------" << endl;
	  cout << "     Digite la opcion: ";
	  cin >> opc;
	  return opc;
  }
  void Vista::ingresaCita(){
      string ced, id, pla, codC;
      int day, month, year, hour, min;
      int vehiculo = 0;
      Medico* ptr1 = NULL;
      Transporte* ptr2 = NULL;
      Paciente* ptr3 = NULL;
      Cita* ptr4 = NULL;
      Fecha* ptr5 = NULL;
      Hora* ptr6 = NULL;

      cout << "Verificando que hayan medicos disponibles..." << endl;
      if (hospital->getListaMedico()->isEmpty() == false) {
          cout << hospital->getListaMedico()->toString();
          cout << "Digite el numero de cedula del medico deseado..." << endl;
          cin >> ced;
          if (hospital->getListaMedico()->buscarMedicoCedula(ced) != NULL) {
              ptr1 = hospital->getListaMedico()->buscarMedicoCedula(ced);
              cout << "Listo medico seleccionado!" << endl;
              system("pause");
              system("cls");
              if (hospital->getContPac()->isEmpty() == false) {
                  cout << hospital->getContPac()->toString();
                  cout << "A continuacion seleccione el paciente con su numero de cedula" << endl;
                  cin >> id;
                  if (hospital->getContPac()->retornaPaciente(id) != NULL) {
                      ptr3 = hospital->getContPac()->retornaPaciente(id);
                      cout << "Paciente seleccionado!" << endl;
                      system("pause");
                      system("cls");
                      cout << "Desea solicitar un transporte? 1. Si 2. NO" << endl;
                      cin >> vehiculo;
                      if (vehiculo == 1) {
                          if (hospital->getContTrans()->isEmpty() == false) {
                              cout << hospital->getContTrans()->mostrarDisponibles();
                              cout << "Digite el numero de placa: ";
                              cin >> pla;
                              if (hospital->getContTrans()->retornaTransporte(pla) != NULL && hospital->getContTrans()->retornaTransporte(pla)->getOcupacion() == false) {
                                  system("cls");
                                  ptr2 = hospital->getContTrans()->retornaTransporte(pla);
                                  creaViaje(ptr2);
                                  cout << "Listo el viaje se ha generado correctamente..." << endl;
                              }
                              else {
                                  cout << "Vehiculo no disponible." << endl;
                                  return;
                              }
                          }
                          else {
                              cout << "No hay vehiculos disponibles" << endl;
                              return;
                          }
                      }
                      else
                          ptr2 = NULL;

                      system("cls");
                      cout << "Creando una fecha y una hora para la cita..." << endl;
                      cout << "Ingrese el dia: " << endl;
                      cin >> day;
                      cout << "Ingrese el mes: " << endl;
                      cin >> month;
                      cout << "Ingrese el annio: " << endl;
                      cin >> year;
                      cout << "Ingrese la hora (00 - 24)" << endl;
                      cin >> hour;
                      cout << "Ingrese los minutos (00 - 59)" << endl;
                      cin >> min;
                      ptr5 = new Fecha(day, month, year);
                      ptr6 = new Hora(hour, min);
                      cout << "Fecha y hora de la cita establecida..." << endl;
                      system("pause");
                      system("cls");
                      cout << "Ingrese el codigo para la cita: " << endl;
                      cin >> codC;
                      ptr4 = new Cita(ptr1, ptr3, ptr2, ptr5, ptr6, codC);
                      hospital->getContCita()->agregaCita(ptr4);
                      system("cls");
                      ptr4->toString();
                      system("pause");
                      return;
                  }
                  else {
                      cout << "Paciente no econtrado..." << endl;
                      cout << "No se puede realizar la cita." << endl;
                      return;
                  }
              }
              else {
                  cout << "No hay pacientes ingresados en el hospital.." << endl;
                  cout << "No se puede realizar la cita." << endl;
                  return;
              }
          }
          else {
              cout << "Medico no encontrado..." << endl;
              cout << "No se puede realizar la cita." << endl;
              return;
          }
          
      }
      else {
          cout << "Aun no hay medicos ingresados en el hospital..." << endl;
          cout << "No se puede realizar la cita." << endl;
          return;
      }
          
  }
  void Vista::citaPorCod() {
      string cod;
      system("cls");
      cout << "Ingrese el codigo de la cita deseada: " << endl;
      cin >> cod;
      if (hospital->getContCita()->retornaCita(cod) != NULL)
          cout << hospital->getContCita()->muestraCita(cod);
      else
          cout << "No se encontro la cita con ese codigo." << endl;
      system("pause>nul");
  }
  void Vista::eliminaCita(){
      system("cls");
      cout << hospital->getContCita()->toString() << endl;
      string codC;
      cout << "Introduzca el codigo de la cita: " << endl;
      cin >> codC;
      if(hospital->getContCita()->retornaCita(codC) != NULL)
          hospital->getContCita()->eliminaCita(codC);
      else {
          cout << "Cita no encontrada..." << endl;
      }
      //ELIMINA CITA
      system("pause>nul");
  }
  void Vista::editaCita(){
      system("cls");
      string codC;
      int d, m, a, h, mi;

      cout << hospital->getContCita()->toString() << endl;
      cout << "Introduzca el codigo de la cita: " << endl;
      cin >> codC;
      if (hospital->getContCita()->retornaCita(codC) != NULL) {
          cout << "Introduzca -> Dia - Mes - Anio" << endl;
          cin >> d;
          cin >> m;
          cin >> a;
          cout << "Introduzca -> Hora - Minuto - Segundo" << endl;
          cin >> h;
          cin >> mi;

          hospital->getContCita()->editaCita(codC, d, m, a, h, mi);
          cout << hospital->getContCita()->muestraCita(codC) << endl;
      }
      else
          cout << "Cita no encontrada..." << endl;
      //EDITA CITA
      system("pause>nul");
  }
  void Vista::citasPorPaciente(){
      system("cls");
      string cedPac;
      cout << "Ingrese la cedula del paciente " << endl;
      cin >> cedPac;
      cout << hospital->getContCita()->citaPorPaciente(cedPac) << endl;

      //CITAS POR PACIENTE
      system("pause>nul");
  }
  void Vista::salir_menu1(){
      cout << "Volviendo al menu Principal" << endl;
  }
//---------------------------------
  int Vista::menu_2(){
      int opc;
      system("cls");

      cout << "-----------MANTENIMIENTO---------" << endl;
      cout << "     1- Ingresar Paciente          " << endl; //V
      cout << "     2- Eliminar Paciente          " << endl; //V
      cout << "     3- Editar Paciente            " << endl; //V
      cout << "---------------------------------" << endl;
      cout << "     4- Ingresar Medico            " << endl; //V
      cout << "     5- Eliminar Medico            " << endl; //V
      cout << "     6- Editar Medico              " << endl; //V
      cout << "---------------------------------" << endl;
      cout << "     7- Ingresar Transporte        " << endl; //V
      cout << "     8- Eliminar Transporte        " << endl; //V
      cout << "     9- Editar Transporte          " << endl; //V
      cout << "---------------------------------" << endl;
      cout << "     10- Salir                   " << endl;
      cout << "     Digite la opcion: ";
      cin >> opc;
      return opc;
  }
//***
  int Vista::menuIngresaPaciente(){
      int op;
      cout << "Escoja que tipo de paciente ingresara: " << endl;
      cout << "1. Profesor en Propiedad" << endl;
      cout << "2. Profesor Interino" << endl;
      cout << "3. Estudiante Nacional" << endl;
      cout << "4. Estudiante Internacional" << endl;
      cin >> op;
      return op;
  }
  void Vista::ingresaProfProp(){
      string nomU, id, tit, codP;
      int aL;
      system("cls");
      cout << "Nombre de la Universidad: " << endl;
      cin >> nomU;
      cout << "Identificacion: " << endl;
      cin >> id;
      cout << "Titulo: " << endl;
      cin >> tit;
      cout << "Annios Laborados: " << endl;
      cin >> aL;
      cout << "Codigo de Plaza: " << endl;
      cin >> codP;

      Paciente* pac = new ProfProp(nomU, id, tit, aL, codP);
      cout << pac->toString() << endl;
      hospital->getContPac()->agregaPaciente(pac);

      system("pause>nul");
  }
  void Vista::ingresaProfInte(){
      string nomU, id, tit;
      int aL, cal;
      system("cls");
      cout << "Nombre de la Universidad: " << endl;
      cin >> nomU;
      cout << "Identificacion" << endl;
      cin >> id;
      cout << "Titulo: " << endl;
      cin >> tit;
      cout << "Annios Laborados: " << endl;
      cin >> aL;
      cout << "Calificacion: " << endl;
      cin >> cal;
      Paciente* pac = new ProfInte(nomU, id, tit, aL, cal);
      cout << pac->toString() << endl;
      hospital->getContPac()->agregaPaciente(pac);
      system("pause>nul");
  }
  void Vista::ingresaEstNac(){
      string nomU, id, cod, niv, nT, est;
      system("cls");
      cout << "Nombre de la Universidad: " << endl;
      cin >> nomU;
      cout << "Identificacion" << endl;
      cin >> id;
      cout << "Codigo de carrera: " << endl;
      cin >> cod;
      cout << "Nivel: " << endl;
      cin >> niv;
      cout << "Numero de telefono: " << endl;
      cin >> nT;
      cout << "Estado: " << endl;
      cin >> est;
      Paciente* pac = new EstNac(nomU, id, cod, niv, nT, est);
      cout << pac->toString() << endl;
      hospital->getContPac()->agregaPaciente(pac);
      system("pause>nul");
  }
  void Vista::ingresaEstInt(){
      string nomU, id, cod, niv, nT, cond, nac;
      system("cls");
      cout << "Nombre de la Universidad: " << endl;
      cin >> nomU;
      cout << "Identificacion" << endl;
      cin >> id;
      cout << "Codigo de carrera: " << endl;
      cin >> cod;
      cout << "Nivel: " << endl;
      cin >> niv;
      cout << "Numero de telefono: " << endl;
      cin >> nT;
      cout << "Condicion Migratoria: " << endl;
      cin >> cond;
      cout << "Nacionalidad: " << endl;
      cin >> nac;
      Paciente* pac = new EstInt(nomU, id, cod, niv, nT, nac, cond);
      cout << pac->toString() << endl;
      hospital->getContPac()->agregaPaciente(pac);
      system("pause>nul");
  }
//***
  void Vista::eliminaPaciente(){
      system("cls");
      string ced;
      cout << "Ingrese la cedula: " << endl;
      cin >> ced;

      if (hospital->getContPac()->eliminaConID(ced) == true) {
          cout << "ELIMINADO" << endl;
      }
      else {
          cout << "ERROR" << endl;
      }
      system("pause>nul");
  }
//***
  int Vista::menuEditaPaciente(){
      int op;
      cout << "Escoja que tipo de paciente editara: " << endl;
      cout << "1. Profesor en Propiedad" << endl;
      cout << "2. Profesor Interino" << endl;
      cout << "3. Estudiante Nacional" << endl;
      cout << "4. Estudiante Internacional" << endl;
      cin >> op;
      return op;
  }
  void Vista::editaPP(){
      string ced, cP;
      int aL;
      system("cls");
      cout << "Cedula: " << endl;
      cin >> ced;
      if (hospital->getContPac()->retornaPaciente(ced) != NULL) {
          cout << "Años laborados: " << endl;
          cin >> aL;
          cout << "Codigo de plaza: " << endl;
          cin >> cP;
          hospital->getContPac()->editaPP(ced, aL, cP);
          cout << hospital->getContPac()->mostrarConID(ced) << endl;
      }
      else
          cout << "No se encontro el profesor en propiedad." << endl;

      system("pause>nul");
  }
  void Vista::editaPI(){
      string ced;
      int aL, cal;
      system("cls");
      cout << "Cedula: " << endl;
      cin >> ced;
      if (hospital->getContPac()->retornaPaciente(ced) != NULL) {
          cout << "Años laborados: " << endl;
          cin >> aL;
          cout << "Calificacion:" << endl;
          cin >> cal;
          hospital->getContPac()->editaPI(ced, aL, cal);
          cout << hospital->getContPac()->mostrarConID(ced) << endl;
      }
      else
          cout << "No se encontro el Profesor interino." << endl;
      system("pause>nul");
  }
  void Vista::editaEN(){
      string ced, est, nT;
      system("cls");
      cout << "Cedula: " << endl;
      cin >> ced;
      if (hospital->getContPac()->retornaPaciente(ced) != NULL) {
          cout << "Estado: " << endl;
          cin >> est;
          cout << "Numero de telefono: " << endl;
          cin >> nT;
          hospital->getContPac()->editaEN(ced, est, nT);
          cout << hospital->getContPac()->mostrarConID(ced) << endl;
      }
      else
          cout << "No se encontro estudiante nacional." << endl;

      system("pause>nul");
  }
  void Vista::editaEI(){
      string ced, nT, cond;
      system("cls");
      cout << "Cedula: " << endl;
      cin >> ced;
      if (hospital->getContPac()->retornaPaciente(ced) != NULL) {
          cout << "Numero de telefono: " << endl;
          cin >> nT;
          cout << "Condicion Migratoria" << endl;
          cin >> cond;
          hospital->getContPac()->editaEI(ced, cond, nT);
          cout << hospital->getContPac()->mostrarConID(ced) << endl;
      }
      else
          cout << "No se encontro el estudiante internacional. " << endl;

      system("pause>nul");
  }
//***
  void Vista::ingresaMedico(){
      system("cls");
      string ced, nom, nT, ape, esp;
      cout << "Ingrese la cedula: ";
      cin >> ced;
      cout << "Ingrese el nombre: ";
      cin >> nom;
      cout << "Ingrese el apellido: ";
      cin >> ape;
      cout << "Ingrese el numero de telefono: ";
      cin >> nT;
      cout << "Ingrese la especialidad: ";
      cin >> esp;
      Medico* medico = new Medico(ced, nom, nT, ape, esp);
      cout << medico->toString() << endl;
      hospital->getListaMedico()->agregarMedico(medico);
      system("pause>nul");
  }
  void Vista::eliminaMedico(){
      system("cls");
      string ced;
      cout << "Ingrese la cedula: " << endl;
      cin >> ced;
      if (hospital->getListaMedico()->eliminaConCedula(ced) == true) {
          cout << "ELIMINADO" << endl;
      }
      else {
          cout << "ERROR" << endl;
      }
      system("pause>nul");
  }
  void Vista::editarMedico(){
      system("cls");
      string ced, nT, esp;
      cout << "Ingrese la cedula: " << endl;
      cin >> ced;
      if (hospital->getListaMedico()->buscarMedicoCedula(ced) != NULL) {
          cout << "Nueva especialidad: " << endl;
          cin >> nT;
          cout << "Nuevo numero de telefono: " << endl;
          cin >> esp;
          hospital->getListaMedico()->editarMedico(ced, esp, nT);
          cout << hospital->getListaMedico()->mostrarMedico(ced) << endl;
      }
      else
          cout << "No se encontro el medico." << endl;
      system("pause>nul");
  }
//***
  int Vista::menuIngresaTransporte() { 
    int op;
    cout << "Escoja que tipo de transporte ingresara: " << endl;
    cout << "1. Taxi" << endl;
    cout << "2. Ambulancia" << endl;
    cin >> op;
    return op;
  }
  void Vista::creaViaje(Transporte* ptr) {
      string tV;
      double dis;
      int nP;
      string tipo = typeid(*ptr).name();
      cout << "Ingrese el tipo de viaje: Ida, Ida-Vuelta." << endl;
      cin >> tV;
      ptr->setTipoViaje(tV);
      cout << "Ingrese la distancia del viaje: " << endl;
      cin >> dis;
      ptr->setDistancia(dis);
      if (tipo == "class Taxi") {
          cout << "Ingrese la cantidad de pasajeros: " << endl;
          cin >> nP;
          ptr->setNumPas(nP);
      }
      if (tipo == "class Ambulancia") {
          ptr->setOcupacion(true);
      }
  }
  void Vista::ingresaTaxi(){
      string pla, mar, tV = "";
      double dis = 0.0;
      int nP = 0;
      Cobro* cob = new Cobro();
      cout << "Placa: " << endl;
      cin >> pla;
      cout << "Marca: " << endl;
      cin >> mar;
      Transporte* t1 = new Taxi(pla, mar, tV, dis, nP);
      cout << t1->toString() << endl;
      cout << "Cobro: " << cob->calcularTotalD(t1) << endl;
      hospital->getContTrans()->agregaTransporte(t1);
      system("pause>nul");
  }
  void Vista::ingresaAmbulancia(){
      string pla, mar;
      string tV = "";
      double dis = 0.0;
      int op, cod;
      bool oc = false;
      cout << "Placa: " << endl;
      cin >> pla;
      cout << "Marca: " << endl;
      cin >> mar;
      cout << "Codigo: " << endl;
      cin >> cod;
      do {
          cout << "Ocupacion: (1. Ocupado, 2. Disponible)" << endl;
          cin >> op;
          if (op == 1)
              oc = true;
          else
              oc = false;
      } while (op > 2 || op < 1);
      Transporte* a1 = new Ambulancia(pla, mar, tV, dis, cod, oc);
      cout << a1->toString() << endl;
      hospital->getContTrans()->agregaTransporte(a1);
      system("pause>nul");
  }
//***
  void Vista::eliminaTransporte(){
      system("cls");
      string pla;
      cout << "Placa a eliminar: " << endl;
      cin >> pla;

      if (hospital->getContTrans()->eliminaConPlaca(pla) == true) {
          cout << "ELIMINADO" << endl;
      }
      else
          cout << "ERROR" << endl;
      system("pause>nul");
  }
//***
  int Vista::menuEditaTransporte(){
      int op;
      cout << "Escoja que tipo de transporte ingresara: " << endl;
      cout << "1. Taxi" << endl;
      cout << "2. Ambulancia" << endl;
      cin >> op;
      return op;
  }
  void Vista::editaTaxi(){
      string placa, mar;
      int nP;
      cout << hospital->getContTrans()->mostrarTaxis() << endl;
      cout << "Ingrese la placa: " << endl;
      cin >> placa;
      if (hospital->getContTrans()->retornaTransporte(placa) != NULL) {
          cout << "Ingrese la nueva marca: " << endl;
          cin >> mar;
          cout << "Numero de pasajeros: " << endl;
          cin >> nP;
          hospital->getContTrans()->editaTaxi(placa, mar, nP);
          cout << hospital->getContTrans()->mostrarPorPlaca(placa) << endl;
      }
      else
          cout << "No se encontro el Taxi." << endl;

      system("pause>nul");
  }
  void Vista::editaAmbulancia(){
      string placa, mar;
      bool oc;
      int op;
      cout << hospital->getContTrans()->mostrarAmbulancias() << endl;
      cout << "Ingrese la placa: " << endl;
      cin >> placa;
      if (hospital->getContTrans()->retornaTransporte(placa) != NULL) {
          cout << "Ingrese la nueva marca: " << endl;
          cin >> mar;
          do {
              cout << "Desea establecer el estado de la ambulancia en ocuapado? 1. Si 2. NO" << endl;
              cin >> op;
              if (op == 1)
                  oc = true;
              else
                  oc = false;
          } while (op > 2);

          hospital->getContTrans()->editaAmbulancia(placa, mar, oc);
          cout << hospital->getContTrans()->mostrarPorPlaca(placa) << endl;
      }
      else
          cout << "No se econtro la ambulancia." << endl;

      system("pause>nul");
  }
//***
  void Vista::salir_menu2(){ cout << "Volviendo al menu principal " << endl; }
//------------------------------------
  int Vista::menu_3(){
      system("cls");
      int opc;
      cout << "-----------BUSQUEDAS---------" << endl;
      cout << "     1- Mostrar Pacientes        " << endl; //V
      cout << "     2- Mostrar Profesores       " << endl; //V
      cout << "     3- Mostrar Estudiantes      " << endl; //V
      cout << "     4- Buscar Paciente          " << endl; //V
      cout << "---------------------------------" << endl;
      cout << "     5- Mostrar Transportes      " << endl; //V
      cout << "     6- Mostrar Ambulancias      " << endl; //V
      cout << "     7- Mostrar Taxis            " << endl; //V
      cout << "     8- Buscar Transporte        " << endl; //V
      cout << "---------------------------------" << endl;
      cout << "     9- Mostrar Medicos          " << endl; //V
      cout << "     10- Buscar Medico           " << endl; //V
      cout << "---------------------------------" << endl;
      cout << "     11- Datos de la empresa     " << endl; //V
      cout << "     12- Monto a pagar por taxis " << endl; //V
      cout << "     13- Persona con mas citas   " << endl;
      cout << "     14- Fecha con mas pacientes " << endl;
      cout << "     15- Transporte mas usado    " << endl; //V
      cout << "     16- Ambulancias ocupadas    " << endl; //V
      cout << "     17- Mejores Prof. Interinos " << endl;
      cout << "     18- Lista de est. exiliados " << endl; //V
      cout << "     19- Salir                   " << endl;
      cout << "     Digite la opcion: ";
      cin >> opc;
      return opc;
  }
//***
  void Vista::mostrarPacientes(){
      system("cls");
      cout << "-----PROFESORES---------" << endl;
      cout << hospital->getContPac()->mostrarProEnProp() << endl;
      cout << hospital->getContPac()->mostrarProInt() << endl;
      cout << "-----ESTUDIANTES-------" << endl;
      cout << hospital->getContPac()->mostrarEstInt() << endl;
      cout << hospital->getContPac()->mostrarEstNac() << endl;
      system("pause>nul");
  }
  void Vista::mostrarProfesores(){
      system("cls");
      cout << hospital->getContPac()->mostrarProEnProp() << endl;
      cout << hospital->getContPac()->mostrarProInt() << endl;
      system("pause>nul");
  }
  void Vista::mostrarEstudiantes(){
      system("cls");
      cout << hospital->getContPac()->mostrarEstInt() << endl;
      cout << hospital->getContPac()->mostrarEstNac() << endl;
      system("pause>nul");
  }
  void Vista::buscarPaciente(){
      system("cls");
      string ced;
      cout << "Ingrese la cedula: " << endl;
      cin >> ced;
      cout << hospital->getContPac()->mostrarConID(ced) << endl;
      system("pause>nul");
  }
//***
  void Vista::muestraTransportes(){
      system("cls");
      cout << hospital->getContTrans()->mostrarAmbulancias() << endl;
      cout << hospital->getContTrans()->mostrarTaxis() << endl;
      system("pause>nul");
  }
  void Vista::mostrarAmbulancias(){
      system("cls");
      cout << hospital->getContTrans()->mostrarAmbulancias() << endl;
      system("pause>nul");
  }
  void Vista::mostrarTaxis(){
      system("cls");
      cout << hospital->getContTrans()->mostrarTaxis() << endl;
      system("pause>nul");
  }
  void Vista::buscarTransporte(){
      string pla;
      system("cls");
      cout << "Ingrese la placa: " << endl;
      cin >> pla;
      cout << hospital->getContTrans()->mostrarPorPlaca(pla);
      system("pause>nul");
  }
//***
  void Vista::mostrarMedicos(){
      system("cls");
      cout << hospital->getListaMedico()->toString() << endl;
      system("pause>nul");
  }
  void Vista::buscarMedico(){
      system("cls");
      string ced;
      cout << "Ingrese la cedula del Medico: ";
      cin >> ced;
      cout << hospital->getListaMedico()->mostrarMedico(ced) << endl;
      system("pause>nul");
  }
//***
  void Vista::mostrarDatosEmpresa(){
      system("cls");
      cout << hospital->toString() << endl;
      system("pause>nul");
  }
  void Vista::montoPagarTaxis(){
      system("cls");
      cout << "Monto a pagar por taxis: " << hospital->getContTrans()->costoTotalTaxis() << endl;
      system("pause>nul");
  }
  void Vista::personaConMasCitas(){
      system("cls");
      cout << hospital->getContCita()->cuentaCitas(hospital->getContPac())->toString();
      system("pause>nul");
  }
  void Vista::fechaConMasPacientes(){ //********
      system("cls");
      cout << hospital->getContCita()->FechaConMasPacientes()->toString();
      system("pause>nul");
  }
  void Vista::transporteMasUsado(){
      system("cls");
      if (hospital->getContTrans()->isEmpty() == false) {
          cout << "Ambulancias: " << hospital->getContCita()->cantAmb() << endl;
          cout << "Taxis: " << hospital->getContCita()->cantTaxi() << endl;
      }
      else
          cout << "No hay transportes." << endl;

      system("pause>nul");
  }
  void Vista::ambulanciasOcupadas(){
      system("cls");
      cout << hospital->getContTrans()->ambulanciasOcupadas() << endl;
      system("pause>nul");
  }
  void Vista::ProfesInterinos_Calificacion(){ //********
      system("cls");
      cout << hospital->getContPac()->mejorCalificacionInterinos();
      system("pause>nul");
  }
  void Vista::listaExiliados(){
      system("cls");
      cout << hospital->getContPac()->listaExiliados() << endl;
      system("pause>nul");
  }
  void Vista::salir_menu3(){
      cout << "Volviendo al menu principal" << endl;
  }
//***
  void Vista::salir_menuP(){
      cout << "GRACIAS POR USAR EL SISTEMA DE CITAS" << endl;
  }

