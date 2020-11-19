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
  for (int i = 0; i < S_nbr_cibles; i++) {
    // Vérifier l'apartenance Vi
  }
}

void C_Solution::CreationTabVji(){
  for (int i = 0; i < S_nbr_cibles; i++) {
    for (int j = 0; j < S_nbr_capteurs; j++){
      // Vérifier l'apartenance Vj
    }
  }
}

//Constructeur
C_Solution::C_Solution(int p_nbr_capteurs, int p_nbr_cibles, std::vector<int> p_Tab_Cout){
  for (int i=0; i< p_nbr_capteurs ; i++){
    S_Xi.push_back(0);
  }
  S_Cout = 0;
  S_Tab_Cout = p_Tab_Cout;
  S_nbr_capteurs = p_nbr_capteurs;
  S_nbr_cibles = p_nbr_cibles;
  S_M = p_nbr_cibles;
}

C_Solution::C_Solution(){

}