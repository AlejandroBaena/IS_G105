#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <string>
using namespace std;

class Persona
{
private:
  string username_{ "null" };
  string password_{ "null" };
  string name_{ "null" };
  string email_{ "null" };
  int user_type_{ 0 };

public:
  Persona(string nombre_usuario, string password, int tipo_usuario, string nombre, string correo){
  	username_=nombre_usuario;
  	password_=password;
  	user_type_=tipo_usuario;
  	name_=nombre;
  	email_=correo;
  };

  inline string getUsername(){ return username_; }
  inline string getName() {return name_; }
  inline string getEmail() {return email_; }
  inline int getUserType() {return user_type_; }
  inline void setUsername(string username){ username_ = username; }
  inline void setPassword(string password){ password_ = password; }
  inline void setName(string name){ name_ = name; }
  inline void setEmail(string email){ email_=email; }
  inline void setUserType(int user_type) {user_type_ =user_type; }
};

//////////////////////////////////////////////////////////////////////////

class Admin : private Persona
{
private:
  int rol_;

public:
  Admin();
  bool modifyBooking();
  bool deleteBooking();
  void showBooking();
  int getRol();
  bool setRol();
};

//////////////////////////////////////////////////////////////////////////

class Admin_user : public Persona
{
private:
	int limite_nucleos_{ 0 };
	int limite_ram_{ 0 };
	int limite_dias_{ 0 };

public:
  Admin_user(string nombre_usuario, string password, int tipo_usuario, string nombre, string correo, int limite_nucleos, int limite_ram, int limite_dias):Persona(nombre_usuario, password, tipo_usuario, nombre, correo){
  	limite_nucleos_=limite_nucleos;
  	limite_ram_=limite_ram;
	limite_dias_=limite_dias;
  };
  bool modifyUser();
  bool deleteUser();
  bool registerUser();
  bool listarUsuarios();
};

//////////////////////////////////////////////////////////////////////////

class Admin_machine : public Persona
{
private:
	int limite_nucleos_{ 0 };
	int limite_ram_{ 0 };
	int limite_dias_{ 0 };

public:
  Admin_machine(string nombre_usuario, string password, int tipo_usuario, string nombre, string correo, int limite_nucleos, int limite_ram, int limite_dias):Persona(nombre_usuario, password, tipo_usuario, nombre, correo){
  	limite_nucleos_=limite_nucleos;
  	limite_ram_=limite_ram;
	limite_dias_=limite_dias;
  };
  bool addMachine();
  bool modifyMachine();
  bool deleteMachine();
  void showMachine();
};


//////////////////////////////////////////////////////////////////////////

class Maquina
{
private:
 // int cantidad_{ 0 };
  int id_maquina_{ 0 };
  int ram_{ 0 };
  int nucleos_{ 0 };
  int grupo_{ 0 };
  bool disponibilidad_{ 0 };
public:
  inline int getIDMaquina(){ return id_maquina_; }
  inline void setIDMaquina(int id_maquina){ id_maquina_ = id_maquina; }
  inline int getRam(){ return ram_; }
  inline void setRam(int ram){ ram_ = ram ; }
  inline int getGrupo(){ return grupo_; }
  inline void setGrupo(int grupo){ grupo_ = grupo; }
  inline bool getDisponibilidad(){ return disponibilidad_;}
  inline void setDisponibilidad(bool disponibilidad){ disponibilidad_ = disponibilidad; }
  inline int getNucleos(){ return nucleos_; }
  inline void setNucleos(int nucleos){ nucleos_ = nucleos; }
};

class Reserva
{
private:
  string nombre_usuario_ { "null" };
  int id_maquina_ { 0 };
  int ram_ { 0 } ;
  int nucleos_ { 0 } ;
  int fecha_ { 0 } ;

public:
  inline Reserva(string nombre_usuario, int id_maquina, int ram, int nucleos, int fecha){ nombre_usuario_ = nombre_usuario; id_maquina_ = id_maquina; ram_ = ram; nucleos_ = nucleos; fecha_ = fecha; }
  inline string getNombreUsuario(){ return nombre_usuario_;}
  inline void setNombreUsuario(string nombre_usuario){ nombre_usuario_ = nombre_usuario; }
  inline int getIDMaquina(){ return id_maquina_; }
  inline void setIDMaquina(int id_maquina){ id_maquina_ = id_maquina; }
  inline int getRam(){ return ram_; }
  inline void setRam(int ram){ ram_ = ram; }
  inline int getNucleos(){ return nucleos_; }
  inline void setNucleos(int nucleos){ nucleos_ = nucleos; }
  inline int getFechaReserva(){ return fecha_; }
  inline void setFechaReserva(int fecha){ fecha_ = fecha; }
};
//////////////////////////////////////////////////////////////////////////

class Usuario :public Persona
{
private:
	int limite_nucleos_{ 0 };
	int limite_ram_{ 0 };
	int limite_dias_{ 0 };
public:
  inline Usuario(string nombre_usuario, string password, int tipo_usuario, string nombre, string correo, int limite_nucleos, int limite_ram, int limite_dias):Persona(nombre_usuario, password, tipo_usuario, nombre, correo){
  	limite_nucleos_=limite_nucleos;
  	limite_ram_=limite_ram;
	limite_dias_=limite_dias;
  };
  bool realizarReserva(Reserva r,int nucleos, int ram);
};

#endif
