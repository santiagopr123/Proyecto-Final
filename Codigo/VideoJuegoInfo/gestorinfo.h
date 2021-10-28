#ifndef GESTORINFO_H
#define GESTORINFO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <QDebug>

using namespace std;

class GestorInfo
{
private:

    string Frase;
    string NameU;
    string Password;
    string MultiP;
    string HealthFPlayer;
    string HealthSPlayer;
    string Score;
    string Level;

    bool StartGame,Multijugador;

public:
    GestorInfo();
    GestorInfo(string NameUIngresado, string PasswordIngresado);
    GestorInfo(string NameUIngresado, string PasswordIngresado,bool PlayerCouple);

    void IdentificadorVariables(const std::string &Phrase);
    bool ExisteUsuario(std::string UsuarioExiste,std::string ClaveExiste);
    void ReescribirInformacion(std::string Usuario, std::string Clave, bool CantidadUsers, double Health1, double Health2, int Score, int NivelU);
    void InscribirNuevoJugador(string NameUIngresado, string PasswordIngresado, string PlayerCouple, double Health1, double Health2);
    string bool_string(bool Boolean) const;
    bool string_bool(string Cadena) const;
    bool getStartGame() const;


    string getNameU() const;
    string getPassword() const;
    int getHealthFPlayer() const;
    int getHealthSPlayer() const;
    int getScore() const;
    int getLevel() const;
    bool getMultiP() const;
};

#endif // GESTORINFO_H
