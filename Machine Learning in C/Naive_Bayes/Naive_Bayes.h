//
//  Naive_Bayes.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/28.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef Naive_Bayes_h
#define Naive_Bayes_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Read_CSV.h"
#include "Perceptron.h"
#include "KNN.h"
#endif /* Naive_Bayes_h */
#define pi 3.14159265
int Get_class_num(float data[][feature_num],int col_num,int row_num);
void Get_sample_num_by_class(float data[][feature_num],int row_num,int col_num,float summary[][5]);
float calculate_probability(float x,float mean,float stdev);
int predict_NB(float test[],float summary[][5],int class_num,int col_num,int row_num);
void Naive_Bayes(char *train_file, char *test_file);
