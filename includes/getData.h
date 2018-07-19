//
//  getData.h
//  Wifi-Client
//
//  Created by Kevin Bertrand on 17/07/18.
//  Copyright © 2018 KevinBertrand. All rights reserved.
//

#ifndef getData_h
#define getData_h

#include <stdio.h>
#include <string>

#include "MPU9250.h"

std::string floatToString(float);

std::string getData(MPU9250);

#endif /* getData_h */
