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
  int S_R;
  std::vector<std::vector<int>> S_Tab_Vij; // Tableau des capteurs qui couvrent les cibles
  std::vector<std::vector<int>> S_Tab_Vji; // Tableau des cibles couverte par les capteurs
  std::vector<int> S_Capteurs_Inutiles; // Listes des capteurs Inutiles
  std::vector<int> S_Tab_Cout; // Couts des capteurs
  std::vector<int> S_Xi; // Liste des capteurs déployés (0 = non | 1 = oui)
  std::vector<int> S_Cibles_Couvertes; // Liste des cibles couvertes (0 = non | 1 = oui)
  //Methode de la classe
  void CalculeCiblesCouvertes();
  void CalculeRedondance();
  void CreationTabVji();
  int Heuristique();
  int Heuristique2();
  int AlgorythmeGlouton();
  C_Solution();
public:
  int CalculeCout();
  //void SetXi(int p_index);

  int AlgorythmeGloutonAmeliore();
  //constructeur de la classe
  C_Solution(int p_nbr_capteurs, int p_nbr_cibles, std::vector<int> p_Tab_Cout, std::vector<std::vector<int>> p_Tab_Vij);

};

#endif
