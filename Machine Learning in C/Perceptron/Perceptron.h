//
//  Perceptron.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/17.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef Perceptron_h
#define Perceptron_h
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Read_CSV.h"
#endif /* Perceptron_h */
float perceptron_predict(float value[feature_num],float weights[],int col_num);
void train_weights(float value[Sample_num][feature_num],float weights[],float learning_rate,int n_epoch,int row_num,int col_num);
float accuracy_perceptron(float test[Sample_num][feature_num],float weights[],int row_num,int col_num);
void Perceptron(char *file,float learning_rate,int n_epoch);
void exchange_array(float a[], float b[],int col_num);
void shuffle_array(float value[Sample_num][feature_num], int row_num,int col_num);
void Two_fold_cross_validation_perceptron(float value[Sample_num][feature_num],int row_num,int col_num,float learning_rate,int n_epoch);
