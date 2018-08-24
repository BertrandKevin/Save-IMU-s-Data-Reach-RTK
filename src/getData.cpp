//
//  getData.cpp
//  Wifi-Client
//
//  Created by Kevin Bertrand on 17/07/18.
//  Copyright © 2018 KevinBertrand. All rights reserved.
//

#include <sstream>
#include <string>

#include "../includes/getData.h"
#include "../includes/MPU9250.h"

using namespace std;

// Allows to convert float values to string
string floatToString(float f)
{
    ostringstream os;
    os << f;
    return os.str();
}

string getData(MPU9250 imu)
{
    // Initialisation des variables
    float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;
    
    // Réception des données
    imu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
    
    // Mise en forme des données
    time_t now = time(0);
    char* temp = ctime(&now);
    
    string dt = temp;
    string toSend = "";
    
    toSend += dt.erase(dt.length()-1, 1) + "\t";
    toSend += "Acc (g): " + floatToString(ax) + "  " + floatToString(ay) + "  " + floatToString(az) + "\t";
    toSend += "Gyr (°/s): " + floatToString(gz) + "  " + floatToString(gy) + "  " + floatToString(gz) + "\t";
    toSend += "Mag (µT): " + floatToString(mx) + "  " + floatToString(my) + "  " + floatToString(mz) + "\n";
    
    return toSend;
}
