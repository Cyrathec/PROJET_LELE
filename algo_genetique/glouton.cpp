#include "main.h" 
 
int glouton(int argc, char *argv[]) { 
 
    // V�rification de la pr�sence d'un argument 
    if(argc == 1) 
        err("Entrez un argument", true); 
 
    // V�rification de la pr�sence d'un SEUL argument 
    if(argc > 2) 
        err("N'entrez qu'un seul argument", true); 
 
    std::string filename = argv[1]; 
 
    // V�rification d'une demande d'aide 
    if(filename.compare("-h") == 0 || filename.compare("--help") == 0 || filename.compare("/?") == 0) 
        help(); 
 
    // Cr�ation d'une instance ifstream et ouverture du fichier indiquez en param�tres 
    std::ifstream instance; 
	instance.open(argv[1]); 
 
    // V�rification de l'ouverture du fichier 
    if(!instance.is_open()) 
        err("Le fichier de lecture n'a pas pu �tre ouvert"); 
 
    std::string line; 
 
    // R�cup�ration de M et N 
	std::getline(instance, line);     
    line = line.substr(1, line.length() -1); // Suppr�ssion des espace avant M et apr�s n 
    int m = std::stoi(line.substr(0, line.find_first_of(" "))); 
    int n = std::stoi(line.substr(line.find_first_of(" ") + 1, line.length())); 
 
    // R�cup�ration du co�ts de capteurs 
    int *cost = (int*) malloc(n * sizeof(int)); 
    getCost(cost, &instance, n); 
 
    // R�cup�ration des capteurs pour chaque cible 
    int **cibles = (int **)malloc(m * sizeof(int*)); 
     
    getCibles(cibles, &instance, m); 
 
    // Fermeture du fichier 
    instance.close(); 
    if(instance.is_open()) 
        err("Le fichier de lecture n'a pas pu �tre ferm�", false); 
 
    return 0; 
 
} 
 
void getCost(int *cost, std::ifstream *instance, int n){ 
 
    std::string line; 
 
    // Calcule du nombre de boucles 
    int count = n / 12; 
 
    // V�rifie si le nombre est exact 
    if(((float)n / 12) != (float)count) 
        count++; 
 
    // R�cup�ration des co�ts des capteurs 
    for (int i = 0; i < count; i++) { 
 
        std::getline(*instance, line); 
        line = line.substr(1, line.length() -1); // Suppr�ssion des espace avant et apr�s 
 
        for (int j = 0; j < 12; j++) { 
 
            // V�rifie si il reste des valeurs (derni�re ligne ne poss�de pas 12 valeurs) 
            if(line.length() == 0) 
                break; 
 
            cost[i * 12 + j] = std::stoi(line.substr(0, line.find_first_of(" "))); 
            line = line.substr(line.find_first_of(" ") + 1, line.length()); 
 
        } 
 
    } 
} 
 
void getCibles(int **cibles, std::ifstream *instance, int m){ 
 
    std::string line; 
 
    for (int i = 1; i <= m; i++){ 
 
        std::getline(*instance, line); 
        line = line.substr(1, line.length() -1); // Suppr�ssion des espace avant et apr�s 
 
        // r�cup�re le nombre de capteurs 
        int nbc = std::stoi(line); 
 
        cibles[i - 1] = (int*)malloc((nbc + 1) * sizeof(int)); 
        cibles[i - 1][0] = nbc; 
 
        // Calcule du nombre de boucles 
        int count = nbc / 12; 
 
        // V�rifie si le nombre est exact 
        if(((float)nbc / 12) != (float)count) 
            count++; 
 
        for (int j = 0; j < count; j++){ 
 
            std::getline(*instance, line); 
            line = line.substr(1, line.length() -1); // Suppr�ssion des espace avant et apr�s 
 
            for (int k = 0; k < 12; k++){ 
 
                // V�rifie si il reste des valeurs (derni�re ligne ne poss�de pas 12 valeurs) 
                if(line.length() == 0) 
                    break; 
 
                cibles[i - 1][j * 12 + k + 1] = std::stoi(line.substr(0, line.find_first_of(" "))); 
                line = line.substr(line.find_first_of(" ") + 1, line.length()); 
 
            } 
 
        } 
 
    } 
     
} 
