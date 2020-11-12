#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <string>

void help(bool r = true); // r -> return ou non ?
void err(std::string e, bool h = false); // e -> erreur | h -> help ou non ?
std::string myName();

#endif // UTILS_H