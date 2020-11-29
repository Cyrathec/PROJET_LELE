#ifndef UTILS_H 
#define UTILS_H 
 
#include <cstdio> 
#include <string> 
 
#include <bits/stdc++.h>  
#include <iostream>  
#include <sys/stat.h>  
#include <sys/types.h>  
 
void help(bool r = true); // r -> return ou non ? 
void err(std::string e, bool r = true, bool h = false); // e -> erreur | r -> return ou non ? | h -> help ou non ? 
std::string myName(); 
 
#endif // UTILS_H