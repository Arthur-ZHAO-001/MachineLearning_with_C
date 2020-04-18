//
//  Perceptron.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/17.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Perceptron.h"
float perceptron_predict(float value[feature_num],float weights[],int col_num){
    float activation=weights[0];
    for(int i=0;i<col_num-1;i++){
        activation+=weights[i+1]*value[i];
    }
    return (activation>=0.0)? 1.0:0.0;
}

void train_weights(float value[Sample_num][feature_num],float weights[],float learning_rate,int n_epoch,int row_num,int col_num){
    float prediction=0.0;
    float error=0.0;
    for(int n=0;n<n_epoch;n++){
        
        for(int i=0;i<row_num;i++){
            prediction= perceptron_predict(value[i],weights,col_num);
            //printf("%f\n",prediction);
            error= value[i][col_num-1]-prediction;
            //printf("%f\n",error);
            weights[0]=weights[0]+learning_rate*error;
            for(int j=0;j<col_num-1;j++){
                weights[j+1]=weights[j+1]+learning_rate*error*value[i][j];
            }
            error=0;
            prediction=0;
        }
        
        
    }
   
}

float accuracy_perceptron(float test[Sample_num][feature_num],float weights[],int row_num,int col_num){
    float prediction=0.0;
    int acc=0;
    for(int i =0;i<row_num;i++){
        prediction= perceptron_predict(test[i],weights,col_num);
        //printf("%f",prediction);
        if(prediction==test[i][col_num-1]){
            acc=acc+1;
        }
    }
    
    float a= (float)acc/row_num;
    //printf("The accuracy is %f\n",a*100);
    return a;
}
void Perceptron(char *file,float learning_rate,int n_epoch){
    float weights[]={};
    
    float value[Sample_num][feature_num];
    read_csv(file, value);
    int col_num=GetTotalColCount(file);
    int row_num=GetTotalLineCount(file);
    Two_fold_cross_validation_perceptron(value,row_num,col_num,learning_rate,n_epoch);
//    for(int m=0;m<col_num;m++){
//        weights[m]=0.0;
//    }
    printf("Take whole dataset as train set\n");
    train_weights(value, weights,learning_rate,n_epoch,row_num, col_num);
    for(int k=0;k<col_num;k++){
        printf("coefficients B%d = %f\n",k,weights[k]);
    }
    
    
}
void Two_fold_cross_validation_perceptron(float value[Sample_num][feature_num],int row_num,int col_num,float learning_rate,int n_epoch){
    float weights_set1[feature_num];
    float weights_set2[feature_num];
    float accuracy[2];
    float set1[Sample_num][feature_num];
    float set2[Sample_num][feature_num];
    shuffle_array(value,  row_num,col_num);
    int half = row_num/2;
    
    for(int i=0;i<half;i++){
        for(int j=0;j<col_num;j++){
            set1[i][j]=value[i][j];
            set2[i][j]=value[half+i][j];
        }//将整个数据集平分
    }
        train_weights(set1, weights_set1, learning_rate, n_epoch, half, col_num);
       //printf(" w %f",weights_set1[0]);
        accuracy[0]=accuracy_perceptron(set2, weights_set1, half, col_num);
        train_weights(set2, weights_set2, learning_rate, n_epoch, half, col_num);
        accuracy[1]= accuracy_perceptron(set1, weights_set2, half, col_num);
        float mean_accuracy=(accuracy[0]+accuracy[1])/2;
        printf("Mean Accuracy is %f\n",mean_accuracy*100);
    

}
void shuffle_array(float value[Sample_num][feature_num], int row_num,int col_num)
{
    unsigned int seed = 1;
    srand(seed);
    int rN1 = (rand() % row_num);
    int rN2 = (rand() % row_num);
    for (int i = 0; i < 1000; i++) {
        if (rN1 != rN2) {
            exchange_array(value[rN1], value[rN2],col_num);
                    }
        rN1 = (rand() % row_num);
        rN2 = (rand() % row_num);
    }
}
void exchange_array(float a[], float b[],int col_num)
{
    for(int i=0;i<col_num;i++){
    float t;
    t = a[i];
    a[i] = b[i];
    b[i] = t;
    }
}
