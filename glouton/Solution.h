#ifndef SOLUTION_H
#define SOLUTION_H

#include "utils.h"

class C_Solution {
  //Membre de la classe
protected:
  int S_Cout; // Cout de la solution
  int S_nbr_capteurs;
  int S_nbr_cibles;
  int S_M;
  std::vector<std::vector<int>> S_Tab_Vij; // Tableau des capteurs qui couvrent les cibles
  std::vector<std::vector<int>> S_Tab_Vji; // Tableau des cibles couverte par les capteurs
  std::vector<int> S_Tab_Cout; // Couts des capteurs
  std::vector<int> S_Xi; // Capteurs déployés
  std::vector<int> S_Cibles_Couvertes;
  //Methode de la classe
  void CalculeCiblesCouvertes();
  void CreationTabVji();
  C_Solution();
public:
  void CalculeCout();
  void SetXi(int p_index);
  int Heuristique();
  //constructeur de la classe
  C_Solution(int p_nbr_capteurs, int p_nbr_cibles, std::vector<int> p_Tab_Cout);

};
 #endif
