#include "Bdd.h"

/*!
 * \file main.c
 * \brief Programme de tests.
 * \author Erwan CHERIAUX
 * \version 1.3
 * \date 15 novembre 2016
 *
 * Serveur d'un set-top box multimédia
 *
 */

const int PORT = 3331;


int main(int argc, char* argv[])
{
    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    shared_ptr<Bdd> bdd(new Bdd());

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*bdd, &Bdd::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
    }

    return 0;
}
