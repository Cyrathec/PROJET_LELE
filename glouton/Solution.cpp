#include "Solution.h"



void C_Solution::CalculeCout(){
  S_Cout = 0;
  for(int i = 0; i < S_nbr_capteurs; i++){
    S_Cout += S_Xi[i]*S_Tab_Cout[i];
  }
}

int C_Solution::Heuristique(){
  for( int i = 0; i < S_nbr_capteurs ; i++){
    for( int j = 0 ; j < S_nbr_cibles ; j++){
      
    }
  }

  return 0 ;
}

void C_Solution::CalculeCiblesCouvertes(){

  S_Cibles_Couvertes.clear();

  for (int i = 0; i < S_nbr_cibles; i++) {

    S_Cibles_Couvertes.push_back(0);

    for (int j = 0; j < S_Tab_Vij.at(i).size(); j++) {

        if(S_Xi.at(S_Tab_Vij.at(i).at(j) - 1) == 1){
          S_Cibles_Couvertes.at(i) = 1;
        }

    }

  }  

}

void C_Solution::CreationTabVji(){

  std::vector<int> capteur;

  // Pour chaque capteur
  for (int i = 0; i < S_nbr_capteurs; i++) {

    // On vérifie si la cible est couverte
    for (int j = 0; j < S_nbr_cibles; j++) {

      for (int k = 0; k < S_Tab_Vij.at(j).size(); k++){

        if(i == (S_Tab_Vij.at(j).at(k) - 1)){

          capteur.push_back(j + 1);

        }

      }

    }

    S_Tab_Vji.push_back(capteur);

    capteur.clear();

  }

}

//Constructeur
C_Solution::C_Solution(int p_nbr_capteurs, int p_nbr_cibles, std::vector<int> p_Tab_Cout, std::vector<std::vector<int>> p_Tab_Vij){
  for (int i=0; i< p_nbr_capteurs ; i++){
    S_Xi.push_back(0);
  }
  S_Cout = 0;
  S_Tab_Cout = p_Tab_Cout;
  S_nbr_capteurs = p_nbr_capteurs;
  S_nbr_cibles = p_nbr_cibles;
  S_M = p_nbr_cibles;
  S_Tab_Vij = p_Tab_Vij;
}

C_Solution::C_Solution(){

}