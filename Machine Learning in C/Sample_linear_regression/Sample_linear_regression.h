//
//  Sample_linear_regression.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef Sample_linear_regression_h
#define Sample_linear_regression_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Read_CSV.h"



#endif /* Sample_linear_regression_h */

void mean(float value[Sample_num][feature_num],float avg[2],int m);
float variance(float value[Sample_num][feature_num],float avg[2],int row_num);
float covariance(float avg[2],float value[Sample_num][feature_num],int row_num);
float *coefficients(float avg[2],float value[Sample_num][feature_num],int row_num);
void Sample_liner_regression(char *file);
