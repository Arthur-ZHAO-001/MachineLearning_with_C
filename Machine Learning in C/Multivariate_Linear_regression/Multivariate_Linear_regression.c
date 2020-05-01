//
//  Multivariate_Linear_regression.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Multivariate_Linear_regression.h"
void Multi_Linear_Regression(char *file,float learning_rate, int n_epoch){ //算法封装 输入数据集 打印出回归系数
    float value[Sample_num][feature_num];
    int col_num=GetTotalColCount(file);
    int row_num=GetTotalLineCount(file);
    read_csv(file,value);
    normalize_dataset(value,row_num,col_num);
    float *coeff= coefficients_sgd(value,learning_rate, n_epoch, row_num, col_num);
    for(int i=0;i<col_num;i++){
        printf("B%d=%f\n",i,*(coeff+i));
    }
}

float predict(float value_one_sample[], float coefficients[], int col_num){ //输入一条数据 输出计算结果
    float yhat=coefficients[0];
    for(int i=0;i<col_num-1;i++){
        yhat+=coefficients[i+1]*value_one_sample[i];
    }
    return yhat;
}

void normalize_dataset(float value[Sample_num][feature_num],int row_num,int col_num){ // 将数据规范化 至[0,1]之间
    float max[col_num];
    float min[col_num];
    for(int n=0;n<col_num;n++){
        max[n]=value[0][n];
        min[n]=value[0][n];//寻找最小值
    }
    
    
    for(int j=0;j<col_num;j++){
        for(int i=0;i<row_num;i++){
            if(value[i][j]>max[j]){
                max[j]=value[i][j];
            }
            if(value[i][j]<min[j]){
                min[j]=value[i][j];
            }
        }
    }//寻找最大值
   
    for(int y=0;y<col_num;y++){
        for(int x=0;x<row_num;x++){
            value[x][y]=(value[x][y]-min[y])/(max[y]-min[y]);
        }
    }
    
}

float *coefficients_sgd(float value[Sample_num][feature_num],float learning_rate, int n_epoch,int row_num,int col_num){ //随机下降法 更新系数
    static float coefficients[]={};
    float yhat=0.0;
    float error=0.0;
    for(int n=0;n<n_epoch;n++){
        for(int i=0;i<row_num;i++){
            //printf("%f\n",coefficients[0]);
            yhat = predict(value[i], coefficients, col_num);
            error =yhat-value[i][col_num-1];
            coefficients[0]-=learning_rate*error;
            for(int j=0;j<col_num-1;j++){
                coefficients[j+1]-=learning_rate*error*value[i][j];
            }
            yhat=0.0;
            //error=0.0;
        }
    }
    //printf("%f",coefficients[0]);
    return coefficients;
}
//float *coefficients_gd(float value[Sample_num][feature_num],float learning_rate, int n_epoch,int row_num,int col_num){ //梯度下降法更新系数（
//    static float coefficients[]={};
//    float yhat=0.0;
//    float error=0.0;
//    float dh[]={};
//
//    for(int n=0;n<n_epoch;n++){
//        for(int j=0;j<col_num;j++){
//            //printf("%f\n",coefficients[0]);
//            for(int i=0;i<row_num;i++){
//                 yhat = predict(value[i], coefficients, col_num);
//                 error = yhat-value[i][col_num-1];
//                //printf("%f\n",error);
//                if(j==0){
//                    dh[j]+=error;
//                    }
//                if(j>=1){
//                    dh[j]+=error*value[i][j-1];
//                    }
//                //error=0.0;
//                yhat=0.0;
//           }
//            //printf("%f\n",dh[2]);
//    }
//        //printf("%f\n",dh[2]);
//     for(int m=0;m<col_num;m++){
//         coefficients[m]=coefficients[m]-learning_rate*(dh[m]/row_num);
//         dh[m]=0.0;
//     }
//
//    }
//    //;
//    return coefficients;
//}
