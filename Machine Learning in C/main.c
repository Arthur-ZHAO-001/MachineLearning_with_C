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
#include "Naive_Bayes.h"
#include "Learning_Vector_Quantization.h"


int main(int argc, const char * argv[]) {
    
    //Sample_liner_regression("/Users/zcl271828/Desktop/Sample_linear_regression_test.csv");
 
    //Learing_Vector_quantization("/Users/zcl271828/Desktop/ionosphere.data.csv", "/Users/zcl271828/Desktop/LVQ_test.csv", 20, 0.3, 50);
    // Learing_Vector_quantization("/Users/zcl271828/Desktop/perceptron.csv", "/Users/zcl271828/Desktop/perceptron.csv", 2, 0.3, 10);
    //Multi_Linear_Regression("/Users/zcl271828/Desktop/Data/Linear_regression_test.csv",0.01, 800);
    //Naive_Bayes("/Users/zcl271828/Desktop/iris.data.csv", "/Users/zcl271828/Desktop/iris_test.csv");
       KNN("/Users/zcl271828/Desktop/abalone.data_train.csv", "/Users/zcl271828/Desktop/abalone_test.csv", 3);
    //Perceptron("/Users/zcl271828/Desktop/sonar.all-data.csv",0.1,500);
}
