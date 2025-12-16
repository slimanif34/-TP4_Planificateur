////////////// TP2 ROBOT  ///////////////////////////////////////
//#include "contexterobot.h"
//#include "sequenceactions.h"
//#include "ouvrirpince.h"
//#include "fermerpince.h"
//#include "deplacer.h"
//#include "allera.h" //bonus
//#include "poserobjet.h" // bonus
//int main() {
//    ContexteRobot ctx(0, 0, 100, true);

//    SequenceActions plan;
//    plan.ajouter(new Deplacer(100, 0, 0));
//    plan.ajouter(new FermerPince());
//   //plan.ajouter(new AllerA(0, 0, 60)); //bonus
//    plan.ajouter(new PoserObjet(100, 0, 50)); // on le dépose
//    //plan.ajouter(new Deplacer(0, 0, -50));
//    plan.ajouter(new OuvrirPince());

//    plan.executer(ctx);
//    ctx.afficherPosition();
//    plan.nettoyer();

//    return 0;
//}

//////////////// TP3 ROBOT  ///////////////////////////////////////

//#include <iostream>
//#include <fstream>
//#include <string>

//#include "contexterobot.h"
//#include "sequenceactions.h"
//#include "ouvrirpince.h"
//#include "fermerpince.h"
//#include "deplacer.h"
//#include "allera.h" //bonus
//#include "poserobjet.h" // bonus

//int main() {
//    ContexteRobot ctx(0, 0, 100, true);
//    SequenceActions plan;


//    std::ifstream fichier("data/plan.txt");
//    if (!fichier.is_open()) {
//        std::cerr << "Erreur : impossible d'ouvrir le fichier plan.txt" << std::endl;
//        return 1;
//    }

//    std::string commande;
//    while (fichier >> commande) {
//        if (commande == "DEPLACER") {
//            double dx, dy, dz;
//            fichier >> dx >> dy >> dz;
//            plan.ajouter(new Deplacer(dx, dy, dz));
//        }
//        else if (commande == "OUVRIR_PINCE") {
//            plan.ajouter(new OuvrirPince());
//        }
//        else if (commande == "FERMER_PINCE") {
//            plan.ajouter(new FermerPince());
//        }
//        else if (commande == "ALLERA") {
//            double x, y, z;
//            fichier >> x >> y >> z;
//            plan.ajouter(new AllerA(x, y, z));
//        }
//        else if (commande == "POSEROBJET") {
//            double x, y, z;
//            fichier >> x >> y >> z;
//            plan.ajouter(new PoserObjet(x, y, z));
//        }
//        else {
//            std::cerr << "Commande inconnue : " << commande << std::endl;
//        }
//    }

//    fichier.close();

//    std::cout << "\n--- Execution du plan ---" << std::endl;
//    plan.executer(ctx);

//    std::cout << "\n--- Etat final du robot ---" << std::endl;
//    ctx.afficherPosition();

//    plan.nettoyer();
//    return 0;
//}

////////////////// BONUS TP3 ROBOT  ///////////////////////////////////////
//// Ajout du journal d'actions
//// Ajout tempo

//#include <thread> // pour gestion de la tempo
//#include <chrono> // pour gestion de la tempo


//#include <iostream>
//#include <fstream>
//#include <string>

//#include "contexterobot.h"
//#include "sequenceactions.h"
//#include "ouvrirpince.h"
//#include "fermerpince.h"
//#include "deplacer.h"
//#include "allera.h" //bonus
//#include "poserobjet.h" // bonus

//int main() {
//    ContexteRobot ctx(0, 0, 100, true);
//    SequenceActions plan;

//    std::ofstream journal("data/journal.txt");
//    if (!journal) {
//        std::cerr << "Impossible de créer journal.txt\n";
//    }

//    std::ifstream fichier("data/plan.txt");
//    if (!fichier.is_open()) {
//        std::cerr << "Erreur : impossible d'ouvrir le fichier plan.txt" << std::endl;
//        return 1;
//    }

//    std::string commande;
//    while (fichier >> commande) {
//        if (commande == "DEPLACER") {
//            double dx, dy, dz;
//            fichier >> dx >> dy >> dz;
//            plan.ajouter(new Deplacer(dx, dy, dz));
//            journal << "DEPLACER " << dx << " " << dy << " " << dz << "\n";
//        }
//        else if (commande == "OUVRIR_PINCE") {
//            plan.ajouter(new OuvrirPince());
//            journal << "OUVRIR_PINCE\n";
//        }
//        else if (commande == "FERMER_PINCE") {
//            plan.ajouter(new FermerPince());
//            journal << "FERMER_PINCE\n";
//        }
//        else if (commande == "ALLERA") {
//            double x, y, z;
//            fichier >> x >> y >> z;
//            plan.ajouter(new AllerA(x, y, z));
//            journal << "ALLERA " << x << " " << y << " " << z << "\n";
//        }
//        else if (commande == "POSEROBJET") {
//            double x, y, z;
//            fichier >> x >> y >> z;
//            plan.ajouter(new PoserObjet(x, y, z));
//            journal << "POSEROBJET " << x << " " << y << " " << z << "\n";
//        }
//        else {
//            std::cerr << "Commande inconnue : " << commande << std::endl;
//        }
//    }

//    fichier.close();
//    journal.close();

//    std::cout << "\n--- Execution du plan ---" << std::endl;
//    plan.executer(ctx);

//    std::cout << "\n--- Etat final du robot ---" << std::endl;
//    ctx.afficherPosition();

//    plan.nettoyer();
//    return 0;
//}


//////////////// TP4 ///////////////////////////////////////
// Ajout rotation

#include <thread> // pour gestion de la tempo
#include <chrono> // pour gestion de la tempo
#include "attendre.h"

#include <iostream>
#include <fstream>
#include <string>

#include "contexterobot.h"
#include "sequenceactions.h"
#include "ouvrirpince.h"
#include "fermerpince.h"
#include "deplacer.h"
#include "allera.h" //bonus
#include "poserobjet.h" // bonus
#include "rotation.h" // ajout TP4

int main() {
    ContexteRobot ctx(0, 0, 100, true);
    SequenceActions plan;

    std::ofstream journal("data/journal.txt");
    if (!journal) {
        std::cerr << "Impossible de creer journal.txt\n";
    }

    journal << "===== JOURNAL D'ACTIONS =====\n";
    journal << "Format: Action + paramètres\n";
    journal << "============================\n";

    std::ifstream fichier("data/plan.txt");
    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier plan.txt" << std::endl;
        return 1;
    }

    std::string commande;
    while (fichier >> commande) {
        if (commande == "DEPLACER") {
            double dx, dy, dz;
            if (!(fichier >> dx >> dy >> dz))
               {
                std::cerr <<"Erreur : parametres invalides pour DEPLACER\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            plan.ajouter(new Deplacer(dx, dy, dz));
            //journal << "DEPLACER " << dx << " " << dy << " " << dz << "\n";
            journal << "Action exécutée : DEPLACER | dx=" << dx << " mm"
                    << ", dy=" << dy << " mm"
                    << ", dz=" << dz << " mm\n";

        }
        else if (commande == "OUVRIR_PINCE") {
            plan.ajouter(new OuvrirPince());
            journal << "OUVRIR_PINCE\n";
        }
        else if (commande == "FERMER_PINCE") {
            plan.ajouter(new FermerPince());
            journal << "FERMER_PINCE\n";
        }
        else if (commande == "ALLERA") {
            double x, y, z;
            if (!(fichier >> x >> y >> z))
               {
                std::cerr <<"Erreur : parametres invalides pour ALLERA\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            plan.ajouter(new AllerA(x, y, z));
            journal << "ALLERA " << x << " " << y << " " << z << "\n";
        }
        else if (commande == "POSEROBJET") {
            double x, y, z;
            if (!(fichier >> x >> y >> z))
               {
                std::cerr <<"Erreur : parametres invalides pour POSEROBJET\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            plan.ajouter(new PoserObjet(x, y, z));
            journal << "POSEROBJET " << x << " " << y << " " << z << "\n";
        }
        else if (commande == "ATTENDRE") {
            int ms;
            if (!(fichier >> ms))
               {
                std::cerr <<"Erreur : parametres invalides pour ATTENDRE\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // vérifie qu'il ne reste pas un caractere colle au nombre (ex: 100b)
            int next = fichier.peek();
            if (next != EOF && next != ' ' && next != '\n' && next != '\r' && next != '\t') {
                std::cerr << "Erreur : parametre invalide pour ATTENDRE (caractere en trop)\n";
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            plan.ajouter(new Attendre(ms));
            //journal << "ATTENDRE " << ms << "\n";
            journal << "Action exécutée : ATTENDRE | durée=" << ms << " ms\n";

        }
        else if (commande == "ROTATION") {     // <-- AJOUT TP4
                   int angle;
                   if (!(fichier >> angle))
                      {
                       std::cerr <<"Erreur : parametres invalides pour ROTATION\n";
                       fichier.clear();
                       fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                       continue;
                   }
                   plan.ajouter(new Rotation(angle));
                   //journal << "ROTATION " << angle << "\n";
                   journal << "Action exécutée : ROTATION | angle=" << angle << " degrés\n";

               }
        else {
            std::cerr << "Commande inconnue : " << commande << std::endl;
        }
    }

    fichier.close();
    journal.close();

    std::cout << "\n--- Execution du plan ---" << std::endl;
    plan.executer(ctx);

    std::cout << "\n--- Etat final du robot ---" << std::endl;
    ctx.afficherPosition();
    plan.nettoyer();
    return 0;
}
