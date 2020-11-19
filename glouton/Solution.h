#ifndef SOLUTION_H
#define SOLUTION_H

#include "utils.h"

class C_Solution {
  //Membre de la classe
protected:
  int S_Cout;
  int S_nbr_capteurs;
  int S_nbr_cibles;
  int S_M;
  int** S_Tab_Vij;
  int* S_Tab_Cout;
  int* S_Xi;
  //Methode de la classe
public:
  void CalculeCout();
  void SetXi(int p_index);
  int Heuristique();
  //constructeur de la classe
  C_Solution(int p_nbr_capteurs, int p_nbr_cibles, int* p_Tab_Cout);
  //Destruction de la classe
  ~C_Solution();

};
 #endif
