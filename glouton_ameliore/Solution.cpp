#include "Solution.h"



int C_Solution::CalculeCout(){
  S_Cout = 0;
  for(int i = 0; i < S_nbr_capteurs; i++){
    S_Cout += S_Xi[i]*S_Tab_Cout[i];
  }
  return S_Cout;
}
int C_Solution::Heuristique2(){
  int Index = 0;
  for (int i = 0; i < S_Capteurs_Inutiles.size(); i++) {
    if (S_Tab_Cout.at(S_Capteurs_Inutiles.at(i)) > S_Tab_Cout.at(S_Capteurs_Inutiles.at(Index))){
      Index = i;
    }
  }
  return S_Capteurs_Inutiles.at(Index);
}

int C_Solution::Heuristique(){
  CalculeCiblesCouvertes();
  std::vector<float> Score;
  int Index = 0;
  for( int i = 0; i < S_nbr_capteurs ; i++){
    Score.push_back(0.0f);
    for( int j = 0 ; j < S_Tab_Vji.at(i).size() ; j++){
      if (S_Cibles_Couvertes.at(S_Tab_Vji.at(i).at(j) - 1) == 0 ){
        Score.at(i)++;
      }
    }
    Score.at(i) = (float) Score.at(i) / S_Tab_Cout.at(i);
    if (Score.at(i) > Score.at(Index)){
      Index = i;
    }

  }

  return Index ;
}
void C_Solution::CalculeRedondance(){
  S_Capteurs_Inutiles.clear();
  for (int i = 0 ; i < S_nbr_capteurs ; i++ ){
    if (S_Xi.at(i) == 1) {
      for (int j = 0; j < S_Tab_Vji.at(i).size(); j++) {
        //printf ("VJI = %d\n",S_Tab_Vji.at(i).at(j));
        for (int k = 0; k < S_Tab_Vij.at(S_Tab_Vji.at(i).at(j) - 1).size(); k++) {
          //printf(" i= %d ,j = %d,k = %d\n",i,j,k);
          if (i != S_Tab_Vij.at(S_Tab_Vji.at(i).at(j)- 1).at(k) && S_Xi.at(S_Tab_Vij.at(S_Tab_Vji.at(i).at(j) - 1).at(k) - 1) == 1) {
            S_Capteurs_Inutiles.push_back(i);
          }
       }
      }
    }
  }
  S_R = S_Capteurs_Inutiles.size();
}


int C_Solution::AlgorythmeGlouton(){
  while ( S_M > 0){
    int i = Heuristique();
    S_Xi.at(i) = 1;
    S_M = S_nbr_cibles;
    CalculeCiblesCouvertes();
    for (int j = 0 ; j < S_nbr_cibles ; j++){
      S_M -= S_Cibles_Couvertes.at(j);
    }
  }
  return CalculeCout();
}

int C_Solution::AlgorythmeGloutonAmeliore(){
  AlgorythmeGlouton();
  CalculeRedondance();
  while(S_R > 0){
    int H2 = Heuristique2();
    S_Xi.at(H2) = 0;
    CalculeRedondance();
  }
  return CalculeCout();
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
  CreationTabVji();
}

C_Solution::C_Solution(){

}
