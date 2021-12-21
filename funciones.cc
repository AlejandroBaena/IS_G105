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
bool buscarMaquina(int id_maquina, int *puntero_nucleos_maquina, int *puntero_ram_maquina){
	int maquina_encontrada=0;
	std::ifstream f("fichero_base_maquinas.txt");										
	if(!f){												
		std::cout<<"Error al abrir el fichero\n";
		return false;
	}
	//Declaración de variables para la lectura del fichero									
	string id_maquina_fichero="";						
	string ram_maquina_fichero="";							
	string nucleos_maquina_fichero="";
	string grupo_maquina_fichero="";
	string disponibilidad_maquina_fichero="";					
	getline(f,id_maquina_fichero,'\n');			
	while((!f.eof())&&(maquina_encontrada==0)){					
		if(stoi(id_maquina_fichero)==id_maquina){				
			getline(f,ram_maquina_fichero,'\n');
			getline(f,nucleos_maquina_fichero,'\n');
			getline(f,grupo_maquina_fichero,'\n');
			getline(f,disponibilidad_maquina_fichero,'\n');
			*puntero_ram_maquina=stoi(ram_maquina_fichero);
			*puntero_nucleos_maquina=stoi(nucleos_maquina_fichero);
			maquina_encontrada=1;
			
		}
		else{									
			getline(f,ram_maquina_fichero,'\n');
			getline(f,nucleos_maquina_fichero,'\n');
			getline(f,grupo_maquina_fichero,'\n');
			getline(f,disponibilidad_maquina_fichero,'\n');
			getline(f,id_maquina_fichero,'\n');
		}
	}	
	f.close();
	if (maquina_encontrada==1){
		return true;
	}
	else{
		return false;
	}
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
				f<<"1"<<endl;
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

bool Usuario::realizarReserva(Reserva r,int nucleos, int ram){
	//Declaración de variables para la lectura del fichero									
	string id_maquina_fichero="";						
	string ram_maquina_fichero="";							
	string nucleos_maquina_fichero="";
	string grupo_maquina_fichero="";
	string disponibilidad_maquina_fichero="";

	string id_maquina_modificar="";					
	int ram_maquina_modificar=ram;							
	int nucleos_maquina_modificar=nucleos;
	string grupo_maquina_modificar="";
	string disponibilidad_maquina_modificar="";
	std::ifstream f("fichero_base_maquinas.txt");										
	if(!f){												
		std::cout<<"Error al abrir el fichero\n";
		return false;
	}
	std::ofstream fich("fichero_base_maquinas_nuevo.txt");										
	if(!fich){												
		std::cout<<"Error al abrir el fichero\n";
		return false;
	}
	getline(f,id_maquina_fichero,'\n');			
	while((!f.eof())){					
		if(stoi(id_maquina_fichero)==r.getIDMaquina()){
			id_maquina_modificar=id_maquina_fichero;			
			getline(f,ram_maquina_fichero,'\n');
			getline(f,nucleos_maquina_fichero,'\n');
			getline(f,grupo_maquina_fichero,'\n');
			grupo_maquina_modificar=grupo_maquina_fichero;
			getline(f,disponibilidad_maquina_fichero,'\n');
			disponibilidad_maquina_modificar=disponibilidad_maquina_fichero;
			getline(f,id_maquina_fichero,'\n');
		}
		else{									
			getline(f,ram_maquina_fichero,'\n');
			getline(f,nucleos_maquina_fichero,'\n');
			getline(f,grupo_maquina_fichero,'\n');
			getline(f,disponibilidad_maquina_fichero,'\n');
			
			fich<<id_maquina_fichero<<endl;
			fich<<ram_maquina_fichero<<endl;
			fich<<nucleos_maquina_fichero<<endl;
			fich<<grupo_maquina_fichero<<endl;
			fich<<disponibilidad_maquina_fichero<<endl;
			getline(f,id_maquina_fichero,'\n');
		}
	}	
	f.close();
	fich.close();
	std::ofstream fichero("fichero_base_maquinas_nuevo.txt",ios::app);
	if(!fichero){												
		std::cout<<"Error al abrir el fichero\n";
		return false;
	}
	fichero<<id_maquina_modificar<<endl;
	fichero<<ram_maquina_modificar<<endl;
	fichero<<nucleos_maquina_modificar<<endl;
	fichero<<grupo_maquina_modificar<<endl;
	fichero<<disponibilidad_maquina_modificar<<endl;
	fichero.close();
	
	std::ofstream reservas("fichero_reservas.txt",ios::app);
	if(!reservas){												
		std::cout<<"Error al abrir el fichero\n";
		return false;
	}
	reservas<<r.getNombreUsuario()<<endl;
	reservas<<r.getIDMaquina()<<endl;
	reservas<<r.getRam()<<endl;
	reservas<<r.getNucleos()<<endl;
	reservas<<r.getFechaReserva()<<endl;
	
	reservas.close();
	remove("fichero_base_maquinas.txt");
	rename("fichero_base_maquinas_nuevo.txt","fichero_base_maquinas.txt");
	return true;
}

