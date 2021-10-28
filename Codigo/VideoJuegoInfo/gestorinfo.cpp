#include "gestorinfo.h"

GestorInfo::GestorInfo()
{

}

GestorInfo::GestorInfo(string NameUIngresado, string PasswordIngresado)
{
    StartGame = ExisteUsuario(NameUIngresado,PasswordIngresado);
}

GestorInfo::GestorInfo(string NameUIngresado, string PasswordIngresado, bool PlayerCouple)
{   
    Multijugador = PlayerCouple;
    StartGame = ExisteUsuario(NameUIngresado,PasswordIngresado);

}

void GestorInfo::IdentificadorVariables(const std::string &Phrase)
{
    std::stringstream s(Phrase);

    int cont = 0;

    std::string Aux;

    const char SS = '-';

    while(std::getline(s,Aux,SS))
    {
        if(cont == 0)
        {
            NameU = Aux;
            cont++;
        }
        else if(cont == 1)
        {
            Password = Aux;
            cont++;
        }
        else if(cont == 2)
        {
            MultiP = Aux;
            cont++;
        }
        else if(cont == 3)
        {
            HealthFPlayer = Aux;
            cont++;
        }
        else if(cont == 4)
        {
            HealthSPlayer = Aux;
            cont++;
        }
        else if(cont == 5)
        {
            Score = Aux;
            cont++;
        }
        else if(cont == 6)
        {
            Level = Aux;
            cont++;
        }
    }
}

bool GestorInfo::ExisteUsuario(std::string UsuarioExiste, std::string ClaveExiste)
{
    string FraseFichero;
    ifstream Archivo;

    Archivo.open("../VideoJuegoInfo/Usuarios.txt");

    while(std::getline(Archivo,FraseFichero))
    {
        IdentificadorVariables(FraseFichero);
        if(NameU == UsuarioExiste && Password == ClaveExiste)
        {
            return true;
        }
    }

    Archivo.close();
    return false;
}

void GestorInfo::ReescribirInformacion(string Usuario, string Clave, bool CantidadUsers, double Health1, double Health2, int Score, int NivelU)
{

    ifstream Archivoaux;
    string FraseFichero_0;
    int ContadorLineas = 0;

    Archivoaux.open("../VideoJuegoInfo/Usuarios.txt",ios::in);

    while(getline(Archivoaux, FraseFichero_0))
    {
        ContadorLineas++;
    }

    Archivoaux.close();

    ifstream Archivo;
    ofstream Escribir;

    string FraseFichero;
    int Contador;
    Contador = 1;

    Archivo.open("../VideoJuegoInfo/Usuarios.txt");
    Escribir.open("../VideoJuegoInfo/Rescribir.txt",ios::out);

    while(std::getline(Archivo,FraseFichero))
    {
        IdentificadorVariables(FraseFichero);
        if(NameU == Usuario && Password == Clave)
        {
            if(Contador == ContadorLineas)
            {
                Escribir<<Usuario<<"-"<<Clave<<"-"<<bool_string(CantidadUsers)<<"-"<<Health1<<"-"<<Health2<<"-"<<Score<<"-"<<NivelU;
            }
            else
            {
                Escribir<<Usuario<<"-"<<Clave<<"-"<<bool_string(CantidadUsers)<<"-"<<Health1<<"-"<<Health2<<"-"<<Score<<"-"<<NivelU<<endl;
            }
        }
        else
        {

            if(Contador == ContadorLineas)
            {
                Escribir<<FraseFichero;
            }
            else
            {
                Escribir<<FraseFichero<<endl;
            }
        }
        Contador++;
    }

    Archivo.close();
    Escribir.close();
    remove("../VideoJuegoInfo/Usuarios.txt");
    rename("../VideoJuegoInfo/Rescribir.txt","../VideoJuegoInfo/Usuarios.txt");

}

void GestorInfo::InscribirNuevoJugador(string NameUIngresado, string PasswordIngresado, string PlayerCouple, double Health1, double Health2)
{
    ifstream Archivoaux;
    string FraseFichero_0;
    int ContadorLineas = 0;

    Archivoaux.open("../VideoJuegoInfo/Usuarios.txt",ios::in);

    while(getline(Archivoaux, FraseFichero_0))
    {
        ContadorLineas++;
    }

    Archivoaux.close();

    ofstream Escribir;
    Escribir.open("../VideoJuegoInfo/Usuarios.txt",ios::app);

    if(ContadorLineas == 0)
    {
        Escribir<<NameUIngresado<<"-"<<PasswordIngresado<<"-"<<PlayerCouple<<"-"<<Health1<<"-"<<Health2<<"-"<<0<<"-"<<1;
    }
    else
    {
        Escribir<<endl<<NameUIngresado<<"-"<<PasswordIngresado<<"-"<<PlayerCouple<<"-"<<Health1<<"-"<<Health2<<"-"<<0<<"-"<<1;

    }

     NameU = NameUIngresado;
     Password= PasswordIngresado;
     MultiP = PlayerCouple;
     HealthFPlayer = to_string(Health1);
     HealthSPlayer = to_string(Health2);
     Score = "0";
     Level = "1";

     Escribir.close();
}

string GestorInfo::bool_string(bool Boolean) const
{
    if(Boolean == true)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

bool GestorInfo::string_bool(string Cadena) const
{
    if(Cadena == "true")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GestorInfo::getStartGame() const
{
    return StartGame;
}

string GestorInfo::getNameU() const
{
    return NameU;
}

string GestorInfo::getPassword() const
{
    return Password;
}

int GestorInfo::getHealthFPlayer() const
{
    return stoi(HealthFPlayer);
}

int GestorInfo::getHealthSPlayer() const
{
    return stoi(HealthSPlayer);
}

int GestorInfo::getScore() const
{
    return stoi(Score);
}

int GestorInfo::getLevel() const
{
    return stoi(Level);
}

bool GestorInfo::getMultiP() const
{
    return string_bool(MultiP);
}
