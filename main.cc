#include <iostream>
#include <string>
#include <fstream>
#include "class.h"
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
						while(opcion_usuario!=1){
							cout<<"---------------------------"<<endl;
							cout<<"OPCIONES DE USUARIO"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"1. Cerrar sesión"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"2. Realizar una reserva"<<endl;
							cout<<"---------------------------"<<endl;
							cout<<"Introduce tu opción: ";
							cin>>opcion_usuario;
							cout<<endl;
							switch(opcion_usuario){
								case 1:
									cout<<"Sesión como "<<nombre_usuario<<" cerrada correctamente."<<endl;
									cout<<endl;
									nombre_usuario="";
									tipo_usuario=0;
									inicio_sesion=0;									
								break;

								case 2:
								{
									int id_maquina;
  									int ram;
									int nucleos;
									int fecha;
									
									cout<<"Introduzca el id de la máquina que desea reservar ->";
									cin>>id_maquina;
									
									cout<<"Introzca la ram que desea reservar de dicha máquina ->";
									cin>>ram;
									if (ram > limite_ram)
									{
										cout<<"ERROR : Desea realizar una reserva por encima de sus limites de usuario"<<endl;
										exit(-1);
									}
									
									cout<<"Introduzca la cantidad de núcleos que va a necesitar ->";
									cin>>nucleos;
									if (nucleos > limite_nucleos)
									{
										cout<<"ERROR : Desea realizar una reserva por encima de sus limites de usuario"<<endl;
										exit(-1);
									}
									
									cout<<"Indique cuántos días durará la reserva ->";
									cin>>fecha;

									if (fecha > limite_dias)
									{
										cout<<"ERROR : Desea realizar una reserva por encima de sus limites de usuario"<<endl;
										exit(-1);
									}

									Reserva solicitud(nombre_usuario, id_maquina, ram, nucleos, fecha);

									if (realizarReserva(solicitud))
									{
										cout<<"La reserva ha sido realizada comn éxito"<<endl;
									}
									else
									{
										cout<<"La reserva no ha podido realizarse"<<endl;
									}
								}
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
						while(opcion_admin_usuario!=2){
							cout<<"---------------------------"<<endl;
							cout<<"1. Registrar usuario"<<endl;
							cout<<"2. Cerrar sesión"<<endl;
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
						while(opcion_admin_maquinas!=2){
							cout<<"---------------------------"<<endl;
							cout<<"1. Registrar nueva máquina"<<endl;
							cout<<"2. Cerrar sesión"<<endl;
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
