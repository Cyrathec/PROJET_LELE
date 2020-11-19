#include "Solution.h"



void C_Solution::CalculeCout(){
  S_Cout = 0;
  for(int i = 0; i < S_nbr_capteurs; i++){
    S_Cout += S_Xi[i]*S_Tab_Cout[i];
  }
}
int Heuristique(){
  for( int i = 0; i < S_nbr_capteurs ; i++){
    for( int j = 0 ; j < S_nbr_cible ; j++){
      
    }
  }

  return 0 ;
}
//Constructeur
C_Solution::C_Solution(int p_nbr_capteurs, int p_nbr_cibles, int* p_Tab_Cout){
  S_Xi = (int*) malloc(p_nbr_capteurs*sizeof(int));
  for (int i=0; i< p_nbr_capteurs ; i++){
    S_Xi[i] = 0;
  }
  S_Cout = 0;
  S_Tab_Cout = p_Tab_Cout;
  S_nbr_capteurs = p_nbr_capteurs;
  S_nbr_cibles = p_nbr_cibles;
  S_M = p_nbr_cibles;
}

//Destructeur
C_Solution::~C_Solution(){
  delete S_Xi;
  delete S_Tab_Cout;
}
