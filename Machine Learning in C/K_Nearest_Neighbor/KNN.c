//
//  KNN.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/17.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "KNN.h"
float euclidean_diatance(float point1[feature_num],float point2[feature_num],int col_num){ //计算欧式距离  返回float 型浮点数
    float distance=0.0;
    for(int i=0;i<col_num-1;i++){
        distance+=(point1[i]-point2[i])*(point1[i]-point2[i]);
    }
    return sqrtf(distance);
}
void get_neighbors(float test[],float train[][feature_num],float neighbor[],int row_num,int col_num,int K){ //获取最近的K个点 存储在 neighbor[]中
    float distance[Sample_num][2];
    
    for(int i=0;i<row_num;i++){
        distance[i][0]=euclidean_diatance(test, train[i], col_num); //距离
        distance[i][1]=train[i][col_num-1];//标签
    
    }
    //printf("%f\n",distance[199][1]);
    sort_up(distance, row_num);
    for(int j=0;j<K;j++){
        neighbor[j]=distance[j][1];
        
    }
      
}
void sort_up(float dis[][2],int n){ //冒泡排序法 将二维数组 按某一列升序排列
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(dis[j][0]>dis[j+1][0])
                exchange_array(dis[j], dis[j+1], 2);
        }
    }
}
void sort_down(float dis[][2],int n){ //冒泡排序法 将二维数组 按某一列降序排列
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(dis[j][0]<dis[j+1][0])
                exchange_array(dis[j], dis[j+1], 2);
        }
    }
}
float majority(float array[],int K){ // 获取K个近邻中 较多的标签值
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
float prediction_KNN(float test[],float train[][feature_num],int row_num,int col_num,int K){ //输入一条数据 进行预测
    float neighbor[K];
    get_neighbors(test,train,neighbor,row_num,col_num, K);
    float class =majority(neighbor, K);
    return class;
}
int prediction_KNN_regression(float test[],float train[][feature_num],int row_num,int col_num,int K){ // 改进的regression KNN
    float neighbor[K];
    float sum=0.0;
    get_neighbors(test,train,neighbor,row_num,col_num, K);
    for(int j=0;j<K;j++){
        sum+=neighbor[j];
    }
    
    int class = sum/K;
    return class;
}
void KNN(char *train_file, char *test_file,int K){ // 算法封装。输入训练集文件路径  测试集文件路径   打印出预测值  和正确率
    float train[Sample_num][feature_num];
    float test[Sample_num][feature_num];
    int correct_num=0; //正确分类数
    read_csv(train_file, train);
    read_csv(test_file, test);//读取文件
    int row_num = GetTotalLineCount(train_file);
    int col_num =GetTotalColCount(train_file);//获取行数 和列数
    int test_num=GetTotalLineCount(test_file);
    for(int i=0;i<test_num;i++){
        float predict = prediction_KNN(test[i], train, row_num, col_num, K);
        if( predict==test[i][col_num-1]){
            correct_num++;
        }
        printf("Expected %f Got %f\n",test[i][col_num-1],predict);
    }
    printf("Accuracy is %f\n",(float)correct_num/test_num);
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
