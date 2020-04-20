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

#include "Read_CSV.h"
#include "Sample_linear_regression.h"
#include "Multivariate_Linear_regression.h"
#include "Perceptron.h"
#include "KNN.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    float p1[]={0,0};
//    float p2[]={0.385,0.105,0.556,0.296,0.104,0.133,7,1};
//   float train[Sample_num][feature_num];
//    read_csv("/Users/zcl271828/Desktop/KNN_test.csv", train);
//    printf("%f\n",train[0][8]);
////    int row_num = GetTotalLineCount("/Users/zcl271828/Desktop/abalone.data_train.csv");
//    int col_num =GetTotalColCount("/Users/zcl271828/Desktop/abalone.data_train.csv");
//     printf("%d",col_num);
//    float i=prediction_KNN( p2, train, row_num, col_num,5);
   printf("%d\n",7/2);
//
   KNN("/Users/zcl271828/Desktop/Train_KNN.csv", "/Users/zcl271828/Desktop/test_KNN.csv", 3);
    //Perceptron("/Users/zcl271828/Desktop/sonar.all-data.csv",0.01,500);
}


