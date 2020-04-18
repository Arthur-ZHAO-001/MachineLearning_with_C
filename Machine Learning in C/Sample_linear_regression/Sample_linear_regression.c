//
//  Sample_linear_regression.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Sample_linear_regression.h"
#include "Read_CSV.h"



void mean(float mat[Sample_num][feature_num],float avg[2],int row_num){
    float sum[2]={};
    //float *avg[2]={};
    
    for(int j=0;j<2;j++){
        for(int i=0;i<row_num;i++){
            sum[j]=sum[j]+mat[i][j];
        }
        avg[j]=sum[j]/row_num;
    }
   
}
float variance(float value[Sample_num][feature_num],float avg[2],int row_num){
    float var=0.0;
    for(int i=0;i<row_num;i++){
        var+=(value[i][0]-avg[0])*(value[i][0]-avg[0]);
    }
    
    return var;
}

//float
float covariance(float avg[2],float value[Sample_num][feature_num],int row_num){
    float covar=0.0;
    for(int i=0;i<row_num;i++){
        covar+=(value[i][0]-avg[0])*(value[i][1]-avg[1]);
    }
   return covar;
}
float *coefficients(float avg[2],float value[Sample_num][feature_num],int row_num){
    static float coeff[2];
    coeff[0]=covariance( avg, value,row_num)/variance(value,avg,row_num);
    coeff[1]=avg[1]-(avg[0]*coeff[0]);
    return coeff;
}

void Sample_liner_regression(char *file){
int row_num=GetTotalLineCount(file);

float value[Sample_num][feature_num];
 
float avg[2]={};
 read_csv(file,value);
 
 mean(value, avg, row_num);
 

float *coeff = coefficients(avg, value,row_num);
printf("B1=%f\n",*coeff);
printf("B0=%f\n",*(coeff+1));
}
