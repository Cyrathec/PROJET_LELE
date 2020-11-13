#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <string>

void help(bool r = true); // r -> return ou non ?
void err(std::string e, bool r = true, bool h = false); // e -> erreur | r -> return ou non ? | h -> help ou non ?
std::string myName();
std::string GetName(std::string file);

#endif // UTILS_H