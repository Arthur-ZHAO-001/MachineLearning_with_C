//
//  KNN.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/17.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef KNN_h
#define KNN_h
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Read_CSV.h"


#endif /* KNN_h */
float euclidean_diatance(float point1[feature_num],float point2[feature_num],int col_num);
void sort(float dis[][2],int n);
float majority(float array[],int K);
float prediction_KNN(float test[],float train[][feature_num],int row_num,int col_num,int K);
int prediction_KNN_regression(float test[],float train[][feature_num],int row_num,int col_num,int K);
void KNN(char *train_file, char *test_file,int K);
void KNN_with_regression(char *train_file, char *test_file,int K);
