//
//  main.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/13.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Sample_linear_regression.h"
#include "Read_CSV.h"
#include "Multivariate_Linear_regression.h"
#include "Perceptron.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    float weights[]={};
    
//    float value[Sample_num][feature_num];
//    read_csv("/Users/zcl271828/Desktop/sonar.all-data.csv", value);
//    //printf("%f\n",value[10][60]);
////
////    //printf("%f\n",31.5/2);
//    int col_num=GetTotalColCount("/Users/zcl271828/Desktop/sonar.all-data.csv");
//    int row_num=GetTotalLineCount("/Users/zcl271828/Desktop/sonar.all-data.csv");
//    Two_fold_cross_validation_perceptron(value,row_num, col_num,0.01,500);
//    //shuffle_array(value,  row_num,col_num);
    //printf("%f\n",value[10][60]);
    
//    for(int m=0;m<col_num;m++){
//        weights[m]=0.0;
//    }
//    //printf("%f",weights[60]);
//    //printf("%d",row_num);
//    //printf("%f\n",perceptron_predict(value[5],weights,col_num));
//    train_weights(value, weights,0.01,1000,row_num, col_num);
//    printf("%f\n",weights[60]);
//    printf("%f\n",perceptron_predict(value[60],weights,col_num));
     //Multi_Linear_Regression("/Users/zcl271828/Desktop/sample.csv",0.1, 1000);
    //accuracy_perceptron(value,weights,row_num,col_num);
    Perceptron("/Users/zcl271828/Desktop/sonar.all-data.csv",0.01,500);
}


