//
//  Learning_Vector_Quantization.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/28.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef Learning_Vector_Quantization_h
#define Learning_Vector_Quantization_h

#include <stdio.h>
#include "Perceptron.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Read_CSV.h"
#include "KNN.h"
#endif /* Learning_Vector_Quantization_h */
int get_best_matching_unit(float dataset[][feature_num],float test[],int row_num,int col_num,float bmu[]);
void random_codebooks(float train[][feature_num],int row_num,int col_num,float codebooks[][feature_num],int n_codebooks);
void train_codebooks(float train[][feature_num],int row_num,int col_num,float codebooks[][feature_num],int n_codebooks,float learning_rate,int epochs);
float predict_LVQ(float codebook[][feature_num], float test[],int n_codebooks,int col_num);
void Learing_Vector_quantization(char *train_file, char *test_file, int n_codebooks,float learning_rate, int epochs);
