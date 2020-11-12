#include "main.h"

int main(int argc, char *argv[]) {

    // Vérification de la présence d'un argument
    if(argc != 2)
        err("Entrez un argument", true);

    std::string filename = argv[1];

    // Vérification d'une demande d'aide
    if(filename.compare("-h") == 0 || filename.compare("--help") == 0 || filename.compare("/?") == 0)
        help();

    // Création d'une instance ifstream et ouverture du fichier indiquez en paramètres
    std::ifstream instance;
	instance.open(argv[1]);

    // Vérification de l'ouverture du fichier
    if(!instance.is_open())
        err("Le fichier n'a pas pu être ouvert");

    std::string line;

    // Récupération de M et N
	std::getline(instance, line);    
    line = line.substr(1, line.length() -1); // Suppréssion des espace avant M et après n
    int m = std::stoi(line.substr(0, line.find_first_of(" ")));
    int n = std::stoi(line.substr(line.find_first_of(" ") + 1, line.length()));

    // Récupération du coûts de capteurs
    int *cost = (int*) malloc(n * sizeof(int));
    getCost(cost, &instance, n);

    // Récupération des capteurs pour chaque cible
    int **cibles = (int **)malloc(m * sizeof(int*));
    getCibles(cibles, &instance, m);

    return 0;

}

void getCost(int *cost, std::ifstream *instance, int n){

    std::string line;

    // Calcule du nombre de boucles
    int count = n / 12;

    // Vérifie si le nombre est exact
    if(((float)n / 12) != (float)count)
        count++;

    // Récupération des coûts des capteurs
    for (int i = 0; i < count; i++) {

        std::getline(*instance, line);
        line = line.substr(1, line.length() -1); // Suppréssion des espace avant et après

        for (int j = 0; j < 12; j++) {

            // Vérifie si il reste des valeurs (dernière ligne ne possède pas 12 valeurs)
            if(line.length() == 0)
                break;

            cost[i * 12 + j] = std::stoi(line.substr(0, line.find_first_of(" ")));
            line = line.substr(line.find_first_of(" ") + 1, line.length());

        }
        
    }
}

void getCibles(int **cibles, std::ifstream *instance, int m){

    std::string line;

    for (int i = 1; i < m; i++){

        std::getline(*instance, line);
        line = line.substr(1, line.length() -1); // Suppréssion des espace avant et après

        // récupère le nombre de capteurs
        int nbc = std::stoi(line);

        cibles[i - 1] = (int*)malloc((nbc + 1) * sizeof(int));
        cibles[i - 1][0] = nbc;

        // Calcule du nombre de boucles
        int count = nbc / 12;

        // Vérifie si le nombre est exact
        if(((float)nbc / 12) != (float)count)
            count++;

        for (int j = 0; j < count; j++){

            std::getline(*instance, line);
            line = line.substr(1, line.length() -1); // Suppréssion des espace avant et après

            for (int k = 0; k < 12; k++){

                // Vérifie si il reste des valeurs (dernière ligne ne possède pas 12 valeurs)
                if(line.length() == 0)
                    break;

                cibles[i - 1][j * 12 + k] = std::stoi(line.substr(0, line.find_first_of(" ")));
                line = line.substr(line.find_first_of(" ") + 1, line.length());

            }

        }

    }
    
}
