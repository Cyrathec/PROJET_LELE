#include "Solution.h"



void C_Solution::CalculeCout(){
  S_Cout = 0;
  for(int i = 0; i < S_nbr_capteurs; i++){
    S_Cout += S_Xi[i]*S_Tab_Cout[i];
  }
}
//Constructeur
C_Solution::C_Solution(int p_nbr_capteurs,int* p_Tab_Cout){
  S_Xi = (int*) malloc(p_nbr_capteurs*sizeof(int));
  for (int i=0; i< p_nbr_capteurs ; i++){
    S_Xi[i] = 0;
  }
  S_Cout = 0;
  printf("oui c'est moi booba %d", S_Cout);
  S_Tab_Cout = p_Tab_Cout;
  S_nbr_capteurs = p_nbr_capteurs;
}

//Destructeur
C_Solution::~C_Solution(){
  delete S_Xi;
}
