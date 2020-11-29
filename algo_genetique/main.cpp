#include "main.h"
#include "glouton.cpp"
#include "Solution.cpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
//On v�rifie qu'on a bien un argument
if (argc != 1) {
    err("Nombre d'arguments invalide", true);
    return 0;
}
//Initialisation

//On initialise les diff�rentes variable
int nb_individus;
 C_Solution SO = glouton(argc, argv);
 std::vector<int> Population(0,0);
 int taille_SO = 0;
  float random_number = 0;

  //On stocke les solutions dans la population
 for (int i = 0; SO[i] != SO[-1] ;i++){
 Population.push_back(SO[i]);
 taille_SO = i;
 }

 C_Solution Solutions[nb_individus-1][0]
 //On utilise le glouton am�lior� pour finir d'initialiser la population
 for (int i = 0; i <= (nb_individus-1) ; i++) {
 
  for (int j = 0; j <= taille_SO ;i++){
 Solutions[i].push_back(glouton(argc, argv));
 Population.push_back(Solutions[i][j]);
 }

 }

 //On stocke la taille de la population
 int taille_population = 0;

 for (int i = 0; Population[i] != Population[-1] ; i++){
     taille_population += 1;
 }

 //S�lection

 std::vector<int> Population_selectionee(1,0);

 std::vector<float> proba(taille_population, 0);
 float somme_proba = 0;
 //On caclcule la somme des probabilit�s des solutions
 for (int i = 0; i <= taille_population; i++){
     somme_proba += Solutions[i].S_Cout;
 }
 //On calcule la probabilit� de chaque solution
 for (int i = 0; i <= taille_population; i++){
     proba[i] = (1/Solutions[i].S_Cout)/somme_proba;
 }

 std::vector<int> Population_finale(0,0);
 
 int population_finale_number = 0;
 std::vector<C_Solution> Solutions_finales[0]

 //On teste al�atoirement la probabilit� pour chaque individu
  for (int i = 0; i <= taille_population; i++){

     random_number = rand() % somme_proba;

     //Si le test est concluant, alors on prend l'individu dans la population finale
     if (random_number <= proba[i]){
     Population_finale.push_back(Population[i]);
     population_finale_number += 1;
     Solutions_finales.push_back(Solutions[i]);
	 }
 }

 float proba_croisement = 0.8;
 int N_taille = population_finale_number;
 int pt_croisement = 0;
 std::vector<C_Solution> Enfants[0];
 C_Solution temp;

 float proba_mutation = 0;


 //Croisement

//On va parcourir toute la population 2 par 2 (pour les parents)
 for (int i = 0; i <= population_finale_number; i += 2) {
 random_number = rand() % 100;
 //Si le test �choue, alors les enfants auront les m�mes chromosomes que les parents
 if (random_number >= proba_croisement*100){
 Enfants.push_back(Population_finale[i]);
 Enfants.push_back(Population_finale[i+1]);
  
 }//Si le teste r�usit alors
 else {
 //On calcule un point de croisement al�atoire � chaque it�ration, et on indique qu'on va avoir deux enfants
 pt_croisement = rand () % N_taille;
 Enfants.push_back(temp);
  Enfants.push_back(temp);
  //On ajoute tous les chromosomes du parent 1 ant�rieurs au chromosome pt_croisement � l'enfant 1
 for (int j = 0; j < pt_croisement; j++){
 Enfants[i].push_back(Population_finale[i][j]);

 }
 //On ajoute tous les chromosomes du parent 2 ult�rieurs au chromosome pt_croisement � l'enfant 1, et on fait de m�me du parent 1 � l'enfant 2
 for (int j = pt_croisement; j < N_taille; j++){
 Enfants[i].push_back(Population_finale[i+1][j]);
 Enfants[i+1].push_back(Population_finale[i][j]);
 //On ajoute tous les chromosomes du parent 2 ant�rieurs au chromosome pt_croisement � l'enfant 2
 }
 for (int j = 0; j < pt_croisement; j++){
 Enfants[i+1].push_back(Population_finale[i+1][j]);
 
 }
 }


 }

 
 


 //R�paration

 //S�letion pour la survie et Mutation

 int d = 0;
 int somme = 0;
 int temporaire = 0;
 //On effectue la mutation dans le while pour �tre s�r de ne pas sortir tant qu'on a une diversit� trop proche de 0

 while (d < 0.05){

 //On augmente la probabilit� de mutation de 1/N_taille (qui augmentera si on n'a pas assez de diversit�)
 proba_mutation += 1/N_taille;

 //On teste al�atoirement pour chaque chromosome de chaque enfant si on mute le g�ne
 for (int i = 0; i <= population_finale_number; i ++) {
 random_number = rand() % 100;
 for (int j = 0; j < N_taille; j++){
  if (random_number < proba_mutation*100){
      Enfants[i][j] = Population_finale[i][j];
  }
  }
  }
  //On calcule d la mesure de diversit�
 for (int i = 1; i <= taille_population-1; i++){
     for (int j = i+1; j <= taille_population; j++){
     for (int k = 1; k <= N_taille; k++){
     temporaire = Enfants[i][k] - Enfants[j][k];
     if (temporaire < 0){
      somme -= temporaire;
	 }
     else{
      somme += temporaire;
	 }

	 }
      	 }
 }
 //calcul final de d
 d = (2/(N_taille*taille_population*(taille_population-1)))*somme;
 
 }





}