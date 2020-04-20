//
//  KNN.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/17.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "KNN.h"
float euclidean_diatance(float point1[feature_num],float point2[feature_num],int col_num){
    float distance=0.0;
    for(int i=0;i<col_num-1;i++){
        distance+=(point1[i]-point2[i])*(point1[i]-point2[i]);
    }
    return sqrtf(distance);
}
void get_neighbors(float test[],float train[][feature_num],float neighbor[],int row_num,int col_num,int K){
    float distance[Sample_num][2];
    
    for(int i=0;i<row_num;i++){
        distance[i][0]=euclidean_diatance(test, train[i], col_num);
        distance[i][1]=train[i][col_num-1];
    
    }
    //printf("%f\n",distance[199][1]);
    sort(distance, row_num);
    for(int j=0;j<K;j++){
        neighbor[j]=distance[j][1];
        
    }
      
}
void sort(float dis[][2],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(dis[j][0]>dis[j+1][0])
                exchange_array(dis[j], dis[j+1], 2);
        }
    }
}
float majority(float array[],int K){
    int i,j;
    int m;
    int count;
    float max[K];
    for(int n=0;n<K;n++){
        max[n]=0;
    }
    for(i=0;i<K;i++){
        count=0;
        for(j=i;j<K;j++){
            if(array[i]==array[j]){
                max[i]++;
            }
        }
    }
    m=0;
    for(i=0;i<K;i++){
        if(max[m]<max[i]){
            m=i;
        }
    }
    return array[m];
}
float prediction_KNN(float test[],float train[][feature_num],int row_num,int col_num,int K){
    float neighbor[K];
    get_neighbors(test,train,neighbor,row_num,col_num, K);
    float class =majority(neighbor, K);
    return class;
}
int prediction_KNN_regression(float test[],float train[][feature_num],int row_num,int col_num,int K){
    float neighbor[K];
    float sum=0.0;
    get_neighbors(test,train,neighbor,row_num,col_num, K);
    for(int j=0;j<K;j++){
        sum+=neighbor[j];
    }
    
    int class = sum/K;
    return class;
}
void KNN(char *train_file, char *test_file,int K){
    float train[Sample_num][feature_num];
    float test[Sample_num][feature_num];
    read_csv(train_file, train);
    read_csv(test_file, test);
    int row_num = GetTotalLineCount(train_file);
    int col_num =GetTotalColCount(train_file);
    int test_num=GetTotalLineCount(test_file);
    for(int i=0;i<test_num;i++){
        float predict = prediction_KNN(test[i], train, row_num, col_num, K);
        printf("Expected %f Got %f\n",test[i][col_num-1],predict);
    }
    
}
void KNN_with_regression(char *train_file, char *test_file,int K){
    float train[Sample_num][feature_num];
    float test[Sample_num][feature_num];
    read_csv(train_file, train);
    read_csv(test_file, test);
    int row_num = GetTotalLineCount(train_file);
    int col_num =GetTotalColCount(train_file);
    int test_num=GetTotalLineCount(test_file);
    for(int i=0;i<test_num;i++){
        int predict = prediction_KNN_regression(test[i], train, row_num, col_num, K);
        printf("Expected %f Got %d\n",test[i][col_num-1],predict);
    }
    
}
