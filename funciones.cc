#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime> 
#include "class.h"
using namespace std;

int login(string nombre_usuario, string password, int *puntero_tipo_usuario, string *puntero_nombre, string *puntero_correo, int *puntero_limite_nucleos, int *puntero_limite_ram, int *puntero_limite_dias){
	int inicio_sesion=0;
	std::ifstream f("fichero_base_de_datos.txt");										
	if(!f){												
		std::cout<<"Error al abrir el fichero\n";
		inicio_sesion=-1;
		return inicio_sesion;
	}
	//Declaración de variables para la lectura del fichero									
	string nombre_usuario_fichero="";						
	string password_fichero="";							
	string tipo_usuario_fichero="";
	string nombre_fichero="";
	string correo_fichero="";
	string limite_nucleos_fichero="";
	string limite_ram_fichero="";
	string limite_dias_fichero="";														
	getline(f,nombre_usuario_fichero,'\n');					
				
	while((!f.eof())&&(inicio_sesion==0)){					
		if(nombre_usuario_fichero==nombre_usuario){				
			getline(f,password_fichero,'\n');				
			if(password_fichero==password){				
				getline(f,tipo_usuario_fichero,'\n');
				getline(f,nombre_fichero,'\n');
				getline(f,correo_fichero,'\n');
				getline(f,limite_nucleos_fichero,'\n');
				getline(f,limite_ram_fichero,'\n');
				getline(f,limite_dias_fichero,'\n');
				*puntero_tipo_usuario=stoi(tipo_usuario_fichero);
				*puntero_nombre=nombre_fichero;
				*puntero_correo=correo_fichero;
				*puntero_limite_nucleos=stoi(limite_nucleos_fichero);
				*puntero_limite_ram=stoi(limite_ram_fichero);
				*puntero_limite_dias=stoi(limite_dias_fichero);
				inicio_sesion=1;
			}
			else{								
				inicio_sesion=-1;
			}
		}
		else{									
			getline(f,password_fichero,'\n');
			getline(f,tipo_usuario_fichero,'\n');
			getline(f,nombre_fichero,'\n');
			getline(f,correo_fichero,'\n');
			getline(f,limite_nucleos_fichero,'\n');
			getline(f,limite_ram_fichero,'\n');
			getline(f,limite_dias_fichero,'\n');
			getline(f,nombre_usuario_fichero,'\n');
		}
		if(f.eof()){							
			inicio_sesion==-1;
		}
	}	
	f.close();
	return inicio_sesion;					
}

bool Admin_machine::addMachine(){

		int id_maquina_{ 0 };
		string id_maquina_string="";
		int ram_{ 0 };
		int nucleos_{ 0 };
		int grupo_{ 0 };
		bool disponibilidad_{ 1 };
		int id_disponible=0;
		int id_encontrado=0;
		
		while(id_disponible==0){

			srand(time(NULL));
			id_maquina_= 1 + rand() % 100;
			id_maquina_string = to_string(id_maquina_);
			id_encontrado=0;
			std::ifstream f("fichero_base_maquinas.txt");
			if(!f){											
				std::cout<<"Error al abrir el fichero\n";
				return false;
			}
			else{										
				string id_fichero ="";
				string ram_fichero ="";
				string nucleos_fichero ="";
				string grupo_fichero ="";
				string disponibilidad_fichero ="";
				getline(f,id_fichero,'\n');								
				while((!f.eof())&&(id_encontrado==0)){					
					if(id_fichero==id_maquina_string){
						id_encontrado=1;
					}
					else{									
						getline(f,ram_fichero,'\n');
						getline(f,nucleos_fichero,'\n');
						getline(f,grupo_fichero,'\n');
						getline(f,disponibilidad_fichero,'\n');
					}
				}	
				f.close();
				if(id_encontrado==0){
					id_disponible=1;
				}
			}
		}

		cout<<"Introduzca la memoria ram: ";
		cin>>ram_;

		cout<<"Introduzca el número de núcleos: ";
		cin>>nucleos_;
		
		cout<<"Introduzca el grupo al que pertenece: ";
		cin>>grupo_;
		
		std::ofstream f("fichero_base_maquinas.txt",ios::app);	
			if(!f){												
				std::cout<<"Error al abrir el fichero\n";
				return false;
			}
			else{
				f<<id_maquina_<<endl;
				f<<ram_<<endl;
				f<<nucleos_<<endl;
				f<<grupo_<<endl;
			}
			f.close();
			return true;	
}


bool Admin_user::registerUser(){
	
		string nombre_usuario;
		string password;
		string tipo_usuario = "0";
		string nombre;
		string apellido1;
		string apellido2;
		string correo;
		string limite_nucleos = "0";
		int limite_nucleos_int = 0;
		string limite_ram = "";
		int limite_ram_int = 0;
		string limite_dias = "";
		int limite_dias_int = 0;
		int usuario_libre=0;
		int usuario_encontrado=0;
		
		while(usuario_libre==0){
			cout<<"Introduce el nombre de usuario: ";
			cin>>nombre_usuario;
			usuario_encontrado=0;	
			std::ifstream f("fichero_base_de_datos.txt");	
			if(!f){												
				std::cout<<"Error al abrir el fichero\n";
				return false;
			}
			else{										
				string nombre_usuario_fichero="";						
				string password_fichero="";							
				string tipo_usuario_fichero="";
				string nombre_fichero="";
				string correo_fichero="";
				string limite_nucleos_fichero="";
				string limite_ram_fichero="";
				string limite_dias_fichero="";
																	
				getline(f,nombre_usuario_fichero,'\n');								
				while((!f.eof())&&(usuario_encontrado==0)){					
					if(nombre_usuario_fichero==nombre_usuario){
						cout<<endl;
						cout<<"Nombre de usuario ya en uso. Introduzca uno distinto por favor."<<endl;
						cout<<endl;
						usuario_encontrado=1;		
					}
					else{									
						getline(f,password_fichero,'\n');
						getline(f,tipo_usuario_fichero,'\n');
						getline(f,nombre_fichero,'\n');
						getline(f,correo_fichero,'\n');
						getline(f,limite_nucleos_fichero,'\n');
						getline(f,limite_ram_fichero,'\n');
						getline(f,limite_dias_fichero,'\n');
						getline(f,nombre_usuario_fichero,'\n');
					}
				}	
				f.close();
				if(usuario_encontrado==0){
					usuario_libre=1;
				}
			}
		}

		cout<<"Introduce la contraseña: ";
		cin>>password;

		while((tipo_usuario!="1")&&(tipo_usuario!="2")&&(tipo_usuario!="3")){
		cout<<"Introduce el tipo de usuario 1(Usuario), 2(Administrador de usuarios) o 3(Administrador de máquinas): ";
		cin>>tipo_usuario;
			if((tipo_usuario!="1")&&(tipo_usuario!="2")&&(tipo_usuario!="3")){
				cout<<"Valor no válido.\n";
			}
		}
		
		cout<<"Introduce el nombre: ";
		cin>>nombre;
		
		cout<<"Introduce el primer apellido: ";
		cin>>apellido1;
		
		cout<<"Introduce el segundo apellido: ";
		cin>>apellido2;
		
		cout<<"Introduce el E-mail: ";
		cin>>correo;

		cout<<"Introduce el número límite de nucleos que podrá usar el usuario: ";
		cin>>limite_nucleos;

		cout<<"Introduce el número límite de ram que podrá usar el usuario: ";
		cin>>limite_ram;

		cout<<"Introduce el número límite de días que podrá reservar el usuario: ";
		cin>>limite_dias;
		
		std::ofstream f("fichero_base_de_datos.txt",ios::app);	
			if(!f){												
				std::cout<<"Error al abrir el fichero\n";
				return false;
			}
			else{
				f<<nombre_usuario<<endl;
				f<<password<<endl;
				f<<tipo_usuario<<endl;
				f<<nombre<<" "<<apellido1<<" "<<apellido2<<endl;
				f<<correo<<endl;
				f<<limite_nucleos<<endl;
				f<<limite_ram<<endl;
				f<<limite_dias<<endl;
			}
			f.close();
			return true;	
}

bool realizarReserva(Reserva solicitud)
{
	string backup;
	string linea;
	string id_maquina_fich="";
	string ram_fich="";
	string nucleos_fich="";
	string grupo_fich="";
	string disponibilidad_fich="";
	int encontrada=0;
	int nueva_ram=0;
	int nuevos_nucleos=0;
	string copia;

	ifstream fich("fichero_base_maquinas.txt");
	cout<<"Abriendo fich de maquinas..."<<endl;
	if(!fich)
	{												
		cout<<"Error al abrir el fichero de las maquinas"<<endl;;
		return false;
	}
	else
	{
  		getline(fich,id_maquina_fich,'\n');
		while((!fich.eof()) && (encontrada==0))
		{					
			if(stoi(id_maquina_fich) == solicitud.getIDMaquina())
			{
				cout<<"Máquina encontrada"<<endl;
				encontrada=1;
				getline(fich,ram_fich,'\n');
				getline(fich,nucleos_fich,'\n');
				getline(fich,grupo_fich,'\n');
				getline(fich,disponibilidad_fich,'\n');	
			}
			else
			{
				
				getline(fich,ram_fich,'\n');
				getline(fich,nucleos_fich,'\n');
				getline(fich,grupo_fich,'\n');
				getline(fich,disponibilidad_fich,'\n');
				getline(fich,id_maquina_fich,'\n');
			}
			
			

			if (stoi(ram_fich) < solicitud.getRam())
			{
				cout<<"La máquina deseada dispone de menos ram de la que requiere en su reserva"<<endl;
				fich.close();
				return false;
			}

			if (stoi(nucleos_fich) < solicitud.getNucleos())
			{
				cout<<"La máquina deseada dispone de menos nucleos de los que requiere en su reserva"<<endl;
				fich.close();
				return false;
			}
		}	
	}
	fich.close();
	cout<<"Cerrando fich de maquinas..."<<endl;

	ifstream fich_aux("fichero_base_maquinas.txt");
	if (!fich_aux)
	{
		cout<<"Error al abrir el fich de maquinas"<<endl;
		return false;
	}
	else
	{
		

		while(getline(fich_aux,linea,'\n'))
		{
			if (stoi(linea) == solicitud.getIDMaquina())
			{
				id_maquina_fich = linea;
				linea = "";
				getline(fich_aux,ram_fich,'\n');
				getline(fich_aux,nucleos_fich,'\n');
				getline(fich_aux,grupo_fich,'\n');
				getline(fich_aux,disponibilidad_fich,'\n');
			}

			copia = copia + linea + "\n";
		}
		
		nueva_ram = stoi(ram_fich) - solicitud.getRam();
		if (nueva_ram == 0)
		{
			disponibilidad_fich= "0";
		}
		
		nuevos_nucleos = stoi(nucleos_fich) - solicitud.getNucleos();
		if (nuevos_nucleos == 0)
		{
			disponibilidad_fich= "0";
		}
	}

	fich_aux.close();


	ofstream fich_aux2("fichero_base_maquinas.txt");
	if (!fich_aux2)
	{
		cout<<"Error al actualizar la base de datos de maquinas"<<endl;
	}
	else
	{
		fich_aux2<<copia<<endl;
		fich_aux2<<id_maquina_fich<<endl;
		fich_aux2<<nueva_ram<<endl;
		fich_aux2<<nuevos_nucleos<<endl;
		fich_aux2<<grupo_fich<<endl;
		fich_aux2<<disponibilidad_fich<<endl;
	}

	fich_aux2.close();
	cout<<"Base de datos de maquinas actualizada correctamente.."<<endl;



	ifstream fich2("base_reservas.txt");
	cout<<"Abriendo fich de reservas..."<<endl;
	if (!fich2)
	{
		cout<<"Error al abrir el fichero de las reservas"<<endl;
		return false;
	}
	else
	{

		while(getline(fich2, linea))
		{
			backup = backup + linea + "\n";
		}
	}
	fich2.close();
	cout<<"Cerrando fich de reservas..."<<endl;

	ofstream fich3("base_reservas.txt");
	cout<<"Abriendo fich de reservas de nuevo..."<<endl;
	if (!fich3)
	{
		cout<<"Error al abrir el fichero de las reservas"<<endl;
		return false;
	}
	else
	{
		fich3 << backup <<endl;
		fich3 << solicitud.getNombreUsuario()<<endl;
		fich3 << solicitud.getIDMaquina()<<endl;
		fich3 << solicitud.getRam()<<endl;
		fich3 << solicitud.getNucleos()<<endl;
		fich3 << solicitud.getFechaReserva()<<endl;
	}

	fich3.close();
	cout<<"Cerrando fich de reservas..."<<endl;
	return true;


}