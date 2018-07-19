//
//  compression.cpp
//  Wifi-Client
//
//  Created by Kevin Bertrand on 17/07/18.
//  Copyright © 2018 KevinBertrand. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "../includes/getData.h"
#include "../includes/MPU9250.h"

using namespace std;

void compression(string path)
{
    string action = "gzip " + path;
    system(action.c_str());
}
