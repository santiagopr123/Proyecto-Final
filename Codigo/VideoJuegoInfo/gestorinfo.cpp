#include "gestorinfo.h"

GestorInfo::GestorInfo(string NameUIngresado,string PasswordIngresado)
{   
    StartGame = ExisteUsuario(NameUIngresado,PasswordIngresado);
}

void GestorInfo::IdentificadorVariables(const std::string &Phrase)
{
    std::cout<<"la frase es "<<Phrase<<std::endl;

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
    std::ifstream Archivo;
    std::string FraseFichero;
    Archivo.open("../VideoJuegoInfo/Usuarios.txt");

    while(std::getline(Archivo,FraseFichero))
    {
        //std::cout<<FraseFichero<<std::endl;
        IdentificadorVariables(FraseFichero);
        if(NameU == UsuarioExiste && Password == ClaveExiste)
        {
            return true;
        }
    }

    Archivo.close();
    return false;
}

bool GestorInfo::getStartGame() const
{
    return StartGame;
}
