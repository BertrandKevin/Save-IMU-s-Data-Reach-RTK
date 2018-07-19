//
//  main.cpp
//  Wifi-Client
//
//  Created by Kevin Bertrand on 17/07/18.
//  Copyright © 2018 KevinBertrand. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include "../includes/compression.h"
#include "../includes/getData.h"
#include "../includes/MPU9250.h"
#include "../includes/searchFilePath.h"

using namespace std;

int main()
{
    // Initialisation et configuration de l'IMU
    MPU9250 imu;
    imu.initialize();
    
    // Verification de le connection avec l'IMU
    if(imu.doSelfTest())
    {
        cout << "MPU9250 connecté!" << endl;
    }
    else
    {
        cout << "MPU9250 non connecté!" << endl;
    }
    
    // Initialisation des variables
    bool start = true;
    char lastSecond(' ');
    char lastHour(' ');
    string toWrite;
    string path;
    
    // Boucle infinie de réception des données
    while(true)
    {
        // Recherche du temps actuel
        time_t startProgram = time(0);
        char* temp = ctime(&startProgram);
        string now = temp;
        
        /*
            Vérifier si l'heure a changé pour modifier le chemin vers le fichier
         */
        if(lastHour != now[12])
        {
            // Compression de l'ancien fichier
            if(!start)
            {
                thread compressionThread(compression, path);
                compressionThread.detach();
            }
            
            // Changer le chemin du fichier
            path = searchPath();
            
            // Creation du fichier
            ofstream file(path.c_str(), ios::out | ios::trunc);
            if(file)
            {
                file << "";
            }
            file.close();
            lastHour = now[12];
            start = false;
        }
        
        /*
            Vérifie si la seconde à changer pour écrire dans le fichier
         */
        if(lastSecond != now[18])
        {
            // Ecrire dans le fichier
            ofstream file(path.c_str(), ios::out | ios::app);
            if(file)
            {
                file << toWrite;
                toWrite = "";
            }
            file.close();
            lastSecond = now[18];
        }
        
        // Réception des données de l'IMU
        string receive = getData(imu);
        toWrite += receive;

	usleep(7000);
    }
    
    return 0;
}
