//
//  Perceptron.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/17.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Perceptron.h"
void Perceptron(char *file,float learning_rate,int n_epoch){ //算法封装 输入数据集 学习率和循环次数  打印出权重向量  及经交叉验证所得的正确率
    
    int col_num=GetTotalColCount(file);
    int row_num=GetTotalLineCount(file);
    float weights[col_num];

    float value[Sample_num][feature_num];
    read_csv(file, value);
    printf("Take whole dataset as train set\n");
    train_weights_perceptron(value, weights,learning_rate,n_epoch,row_num, col_num);
    for(int k=0;k<col_num;k++){
        printf("Weights B%d = %f\n",k,weights[k]);
    }
    Two_fold_cross_validation_perceptron(value,row_num,col_num,learning_rate,n_epoch);
}
float perceptron_predict(float value[feature_num],float weights[],int col_num){ //判断是否激活
    float activation=weights[0];
    for(int i=0;i<col_num-1;i++){
        activation+=weights[i+1]*value[i];
    }
    return (activation>=0.0)? 1.0:0.0;
}

void train_weights_perceptron(float value[Sample_num][feature_num],float weights[],float learning_rate,int n_epoch,int row_num,int col_num){ //训练算法 更新权重
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

float accuracy_perceptron(float test[Sample_num][feature_num],float weights[],int row_num,int col_num){ //输入测试集 计算正确率
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

void Two_fold_cross_validation_perceptron(float value[Sample_num][feature_num],int row_num,int col_num,float learning_rate,int n_epoch){ //交叉验证 打印出平均正确率
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
        train_weights_perceptron(set1, weights_set1, learning_rate, n_epoch, half, col_num);
       //printf(" w %f",weights_set1[0]);
        accuracy[0]=accuracy_perceptron(set2, weights_set1, half, col_num);
        train_weights_perceptron(set2, weights_set2, learning_rate, n_epoch, half, col_num);
        accuracy[1]= accuracy_perceptron(set1, weights_set2, half, col_num);
        float mean_accuracy=(accuracy[0]+accuracy[1])/2;
        printf("Mean Accuracy is %f\n",mean_accuracy*100);
    

}
void shuffle_array(float value[Sample_num][feature_num], int row_num,int col_num) // 同python 中 shuffle函数  随机打乱数组顺序
{
    unsigned int seed = 1; //随机数种子
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
void exchange_array(float a[], float b[],int col_num) //交换两个一维数组的值
{
    for(int i=0;i<col_num;i++){
    float t;
    t = a[i];
    a[i] = b[i];
    b[i] = t;
    }
}
