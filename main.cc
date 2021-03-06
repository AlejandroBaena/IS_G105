#include <iostream>
#include <string>
#include <fstream>
#include "funciones.cc"
using namespace std;

int main(){
	//Declaración e inicialización de variables y punteros
	string nombre_usuario="";							
	string password="";
	int tipo_usuario=0;
	int *puntero_tipo_usuario=&tipo_usuario;	
	string nombre="";
	string *puntero_nombre=&nombre;
	string correo="";
	string *puntero_correo=&correo;
	int limite_nucleos=0;
	int *puntero_limite_nucleos=&limite_nucleos;
	int limite_ram=0;
	int *puntero_limite_ram=&limite_ram;
	int limite_dias=0;
	int *puntero_limite_dias=&limite_dias;				
	int inicio_sesion=0;															
	int opcion=0;
	//Variables para la función realizar reserva
	int id_maquina=0;
	int nucleos_maquina=0;
	int *puntero_nucleos_maquina=&nucleos_maquina;
	int ram_maquina=0;
	int *puntero_ram_maquina=&ram_maquina;
	int nucleos_reserva=0;
	int ram_reserva=0;
	int fecha_reserva=0;
	int nuevos_nucleos=0;
	int nueva_ram=0;
	//Mostramos el menú de opciones
	while(opcion!=2){
		cout<<"---------------------------"<<endl;
		cout<<"1. Iniciar sesión"<<endl;
		cout<<"2. Salir"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Introduce tu opción: ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				cout<<"---------------------------"<<endl;
				cout<<endl;
				cout<<"Usuario: ";								
				cin>>nombre_usuario;								
				cout<<"Contraseña: ";				
				cin>>password;	
				cout<<endl;								
				cout<<"---------------------------"<<endl;
				inicio_sesion=login(nombre_usuario, password, puntero_tipo_usuario, puntero_nombre, puntero_correo, puntero_limite_nucleos, puntero_limite_ram, puntero_limite_dias);
													
				if(inicio_sesion==1){								
					password="";
					cout<<endl;
					cout<<"Sesión iniciada correctamente como "<<nombre_usuario<<"."<<endl;
					if(tipo_usuario==1){
						Usuario investigador(nombre_usuario, password, tipo_usuario, nombre, correo, limite_nucleos, limite_ram, limite_dias);
						cout<<endl<<"Datos del usuario"<<endl;
						cout<<"------------------------------------------------------"<<endl;
						cout<<"Nombre usuario: "<<investigador.getUsername()<<endl;
						cout<<"Tipo de usuario: "<<investigador.getUserType()<<" --> Investigador"<<endl;
						cout<<"Nombre: "<<investigador.getName()<<endl;
						cout<<"E-mail: "<<investigador.getEmail()<<endl;
						cout<<"------------------------------------------------------"<<endl;
						cout<<endl;
						//MENÚ USUARIO
						int opcion_usuario=0;
						while(opcion_usuario!=3){
							cout<<"---------------------------"<<endl;
							cout<<"OPCIONES DE USUARIO"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"1. Listar máquinas"<<endl;
							cout<<"2. Realizar reserva"<<endl;
							cout<<"3. Cerrar sesión"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"Introduce tu opción: ";
							cin>>opcion_usuario;
							cout<<endl;
							switch(opcion_usuario){
							
								case 1:
									listarMaquinas();									
								break;
								
								case 2:{
									cout<<"Introduce la ID de la máquina a reservar"<<endl;
									cin>>id_maquina;
									if (buscarMaquina(id_maquina, puntero_nucleos_maquina, puntero_ram_maquina)){
										cout<<"La máquina con ID: "<<id_maquina<<" tiene "<<nucleos_maquina<<" núcleos y "<<ram_maquina<<" de RAM."<<endl;
										cout<<"Su límite de nucleos es de "<<limite_nucleos<<", su límite de RAM es de "<<limite_ram<<" y su límite de días es de "<<limite_dias<<endl;
									}
									nucleos_reserva=0;
									ram_reserva=0;
									fecha_reserva=0;
									while((limite_nucleos<nucleos_reserva) || (nucleos_maquina<nucleos_reserva) || nucleos_reserva==0){
										cout<<"Introduce el número de núcleos a reservar: ";
										cin>>nucleos_reserva;
									}
									while((limite_ram<ram_reserva) || (ram_maquina<ram_reserva) || ram_reserva==0){
										cout<<"Introduce el número de RAM a reservar: ";
										cin>>ram_reserva;
									}
									while(limite_dias<fecha_reserva || fecha_reserva==0){
										cout<<"Introduce el número de días a reservar: ";
										cin>>fecha_reserva;
									}
									nuevos_nucleos=nucleos_maquina-nucleos_reserva;
									nueva_ram=ram_maquina-ram_reserva;
									Reserva r(investigador.getUsername(),id_maquina, ram_reserva, nucleos_reserva, fecha_reserva);
									if(investigador.realizarReserva(r,nuevos_nucleos, nueva_ram)){
										cout<<"Reserva realizada correctamente."<<endl;
									}
									else{
										cout<<"Error en la realización de la reserva"<<endl;
									}
								}						
								break;
								
								case 3:
									cout<<"Sesión como "<<nombre_usuario<<" cerrada correctamente."<<endl;
									cout<<endl;
									nombre_usuario="";
									tipo_usuario=0;
									inicio_sesion=0;									
								break;
								
								default:
									cout<<"La opción debe ser un número del 1 al 2"<<endl;
								break;
							}
						}
					}
					else if(tipo_usuario==2){
						Admin_user admin_usuarios(nombre_usuario, password, tipo_usuario, nombre, correo, limite_nucleos, limite_ram, limite_dias);
						cout<<endl<<"Datos del usuario"<<endl;
						cout<<"------------------------------------------------------"<<endl;
						cout<<"Nombre usuario: "<<admin_usuarios.getUsername()<<endl;
						cout<<"Tipo de usuario: "<<admin_usuarios.getUserType()<<" --> Administrador de usuarios"<<endl;
						cout<<"Nombre: "<<admin_usuarios.getName()<<endl;
						cout<<"E-mail: "<<admin_usuarios.getEmail()<<endl;
						cout<<"------------------------------------------------------"<<endl;
						cout<<endl;
						//MENÚ ADMINISTRADOR USUARIOS
						int opcion_admin_usuario=0;
						while(opcion_admin_usuario!=3){
							cout<<"---------------------------"<<endl;
							cout<<"1. Registrar usuario"<<endl;
							cout<<"2. Listar usuarios"<<endl;
							cout<<"3. Cerrar sesión"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"Introduce tu opción: ";
							cin>>opcion_admin_usuario;
							cout<<endl;
							switch(opcion_admin_usuario){
								case 1:
									if(admin_usuarios.registerUser()){
										cout<<endl;
										cout<<"Usuario creado correctamente"<<endl;
										cout<<endl;
									}
									else{
										cout<<endl;
										cout<<"Error al crear el usuario"<<endl;
										cout<<endl;
									}							
								break;
								
								case 2:
									admin_usuarios.listarUsuarios();							
								break;
								
								case 3:
									cout<<"Sesión como "<<nombre_usuario<<" cerrada correctamente."<<endl;
									cout<<endl;
									nombre_usuario="";
									tipo_usuario=0;
									inicio_sesion=0;									
								break;
								
								default:
									cout<<"La opción debe ser un número del 1 al 2"<<endl;
								break;
							}
						}
					}
					else{
						Admin_machine admin_maquinas(nombre_usuario, password, tipo_usuario, nombre, correo, limite_nucleos, limite_ram, limite_dias);
						cout<<endl<<"Datos del usuario"<<endl;
						cout<<"------------------------------------------------------"<<endl;
						cout<<"Nombre usuario: "<<admin_maquinas.getUsername()<<endl;
						cout<<"Tipo de usuario: "<<admin_maquinas.getUserType()<<" --> Administrador de máquinas"<<endl;
						cout<<"Nombre: "<<admin_maquinas.getName()<<endl;
						cout<<"E-mail: "<<admin_maquinas.getEmail()<<endl;
						cout<<"------------------------------------------------------"<<endl;
						cout<<endl;
						//MENÚ ADMINISTRADOR máquinas
						int opcion_admin_maquinas=0;
						while(opcion_admin_maquinas!=3){
							cout<<"---------------------------"<<endl;
							cout<<"1. Registrar nueva máquina"<<endl;
							cout<<"2. Listar máquinas"<<endl;
							cout<<"3. Cerrar sesión"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"Introduce tu opción: ";
							cin>>opcion_admin_maquinas;
							cout<<endl;
							switch(opcion_admin_maquinas){
								case 1:
									if(admin_maquinas.addMachine()){
										cout<<endl;
										cout<<"Máquina añadida correctamente"<<endl;
										cout<<endl;
									}
									else{
										cout<<endl;
										cout<<"Error al añadir la máquina"<<endl;
										cout<<endl;
									}							
								break;

								case 2:
									listarMaquinas();									
								break;

								case 3:
									cout<<"Sesión como "<<nombre_usuario<<" cerrada correctamente."<<endl;
									cout<<endl;
									nombre_usuario="";
									tipo_usuario=0;
									inicio_sesion=0;									
								break;
								
								default:
									cout<<"La opción debe ser un número del 1 al 2"<<endl;
								break;
							}
						}
					}
				}
				else{
					cout<<endl;									
					cout<<"Usuario o contraseña incorrecta"<<endl;
					cout<<endl;
				}
			}
			break;
			
			case 2:
				cout<<endl;
				cout<<"Saliendo del programa..."<<endl;
			break;
			
			default:
				cout<<"La opción debe ser un número del 1 al 2"<<endl;
			break;
		}
	
	}
}
