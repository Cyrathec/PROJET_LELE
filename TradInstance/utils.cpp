#include "utils.h"

// Détermination du nom du programme
std::string mname = myName();

void help(bool r){

    printf("Utilisation : %s {nom du fichier instance}\n", mname.c_str());
    printf("Aide :\n%s -h\n%s --help\n%s /?\n", mname.c_str(), mname.c_str(), mname.c_str());

    if(r)
        exit(0);

}

void err(std::string e, bool r, bool h){

    printf("Erreur : %s\n", e.c_str());

    if(h)
        help(false);

    if(r)
        exit(1);

}

std::string myName(){

    std::string name = _argv[0];

    int n = name.find_last_of('\\', name.length());

    name = name.substr(n + 1, name.length());

    return name;

}

std::string GetName(std::string file){

    int n = file.find_last_of('\\', file.length());

    file = file.substr(n + 1, file.length());

    n = file.find_last_of('.', file.length());

    if(n > 0)
        file = file.substr(0, n);

    return file;

}