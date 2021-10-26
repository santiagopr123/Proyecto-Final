#ifndef GESTORINFO_H
#define GESTORINFO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

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

    bool StartGame;

public:
    GestorInfo(string NameUIngresado,string PasswordIngresado);

    void IdentificadorVariables(const std::string &Phrase);
    bool ExisteUsuario(std::string UsuarioExiste,std::string ClaveExiste);

    bool getStartGame() const;
};

#endif // GESTORINFO_H
