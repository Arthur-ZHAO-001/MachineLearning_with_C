//
//  Multivariate_Linear_regression.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef Multivariate_Linear_regression_h
#define Multivariate_Linear_regression_h

#include <stdio.h>
#include "Read_CSV.h"
#endif /* Multivariate_Linear_regression_h */
float predict(float value_one_sample[feature_num], float coefficients[], int col_num);
void normalize_dataset(float value[Sample_num][feature_num],int row_num,int col_num);
float *coefficients_sgd(float value[Sample_num][feature_num],float learning_rate, int n_epoch,int row_num,int col_num);
float *coefficients_gd(float value[Sample_num][feature_num],float learning_rate, int n_epoch,int row_num,int col_num);
void Multi_Linear_Regression(char *file,float learning_rate, int n_epoch);
