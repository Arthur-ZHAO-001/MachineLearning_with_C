//
//  Naive_Bayes.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/28.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Naive_Bayes.h"//朴素贝叶斯分类器

void Naive_Bayes(char *train_file, char *test_file){ //算法封装 输入训练/测试集  打印出测试集的分类结果
    float train[Sample_num][feature_num];
    float test[Sample_num][feature_num];
    read_csv(train_file, train);
    read_csv(test_file, test);
    int correct_num=0;
    int row_num = GetTotalLineCount(train_file);
    int col_num =GetTotalColCount(train_file);
    int test_num=GetTotalLineCount(test_file);
    int class_num=Get_class_num(train, col_num, row_num);
    float summary[class_num*(col_num-1)][5];
    Get_sample_num_by_class(train, row_num, col_num,summary);
    int predictions[test_num];
    for(int i=0;i<test_num;i++){
        predictions[i]=predict_NB(test[i], summary, class_num, col_num, row_num);
        if(predictions[i]==(int)test[i][col_num-1]){
            correct_num++;// 正确分类数
        }
        printf("EXpected %d Got %d\n",(int)test[i][col_num-1],predictions[i]);
    }
    printf("Accuracy is %f",(float)correct_num/test_num);
}


int Get_class_num(float data[][feature_num],int col_num,int row_num){ //获取数据集中 类别总数 ，
    int class_num=1;
    float class[10];
    int num=1;
    class[0]=data[0][col_num-1];
    for(int i=0;i<row_num;i++){
        num=0;
        for(int j=0;j<class_num;j++){
            if(data[i][col_num-1]!=class[j]){
                num++;
            }
        }
        if(num==class_num){
            class[class_num]=data[i][col_num-1];
            class_num++;
        }
        
    }
   return class_num;
}
void Get_sample_num_by_class(float data[][feature_num],int row_num,int col_num,float summary[][5]){ //将数据按 种类 区分 并分别计算 每种数据中 每一列的平均值 标准差等 均储存在二维数组中
    int class_num=1;
    float class[20];//种类最大个数
    int num=1;
    
    class[0]=data[0][col_num-1];
    for(int i=0;i<row_num;i++){
        num=0;
        for(int j=0;j<class_num;j++){
            if(data[i][col_num-1]!=class[j]){
                num++;
            }
        }
        if(num==class_num){
            class[class_num]=data[i][col_num-1];
            class_num++;
        }
    }
    //printf("%f\n",class[1]);
    //float summary[class_num*(col_num-1)][5];
    float sample_class[class_num][2];//每种样本的个数
    float sample_mean[class_num][col_num];//平均值
    float stander_deviation[class_num][col_num];
    for(int iii=0;iii<class_num;iii++){
        for(int jjj=0;jjj<col_num;jjj++){
            sample_mean[iii][jjj]=0.0;
            stander_deviation[iii][jjj]=0.0;
        }
    }
        for(int n=0;n<class_num;n++){
        sample_class[n][0]=class[n];
        sample_mean[n][col_num-1]=class[n];
        for(int m=0;m<row_num;m++){
            if(data[m][col_num-1]==class[n]){
                sample_class[n][1]++;
                for(int h=0;h<col_num-1;h++){
                    sample_mean[n][h]+=data[m][h];
                }
            }
        }
    }
    //计算平均值
    for(int ii=0;ii<class_num;ii++){
        for(int jj=0;jj<col_num-1;jj++){
            sample_mean[ii][jj]/=sample_class[ii][1];
        }
    }
    //计算标准差
    for(int x=0;x<class_num;x++){
        stander_deviation[x][col_num-1]=class[x];
        for(int y=0;y<row_num;y++){
            if(data[y][col_num-1]==class[x]){
                for(int z =0;z<col_num-1;z++){
                    stander_deviation[x][z]+=(data[y][z]-sample_mean[x][z])*(data[y][z]-sample_mean[x][z]);
                }
                
            }
        }
    }
    for(int xx=0;xx<class_num;xx++){
        for(int zz=0;zz<col_num-1;zz++){
            stander_deviation[xx][zz]=sqrtf(stander_deviation[xx][zz]/(sample_class[xx][1]-1));
        }
    }
    
    
    for(int q=0;q<class_num;q++){
        for(int p=0;p<col_num-1;p++){
            summary[q*(col_num-1)+p][0]=p;// 变量编号
            summary[q*(col_num-1)+p][1]=sample_mean[q][p];//平均值
            summary[q*(col_num-1)+p][2]=stander_deviation[q][p];//标准差
            summary[q*(col_num-1)+p][3]=sample_class[q][1];
            summary[q*(col_num-1)+p][4]=sample_class[q][0];
        }
    }
    //printf("%f\n",sample_class[1][1]);
   
}
float calculate_probability(float x,float mean,float stdev){//正态分布公式
    float expoent=expf(-((x-mean)*(x-mean))/(2*stdev*stdev));
    return (1/(sqrtf(2*pi)*stdev))*expoent;
}

int predict_NB(float test[],float summary[][5],int class_num,int col_num,int row_num){ //输入一条数据。进行分类
    float probabilities[class_num][2];
    for(int class=0;class<class_num;class++){
        
        probabilities[class][1]=summary[class*(col_num-1)+1][4];
        probabilities[class][0]=summary[class*(col_num-1)][3]/row_num;
        for(int c=0;c<col_num-1;c++){
            int i=0;
            i++;
            float mean=summary[class*(col_num-1)+c][1];
            float stdev=summary[class*(col_num-1)+c][2];
            float x = test[c];
            float prob=calculate_probability(x,mean,stdev);
            probabilities[class][0]*=prob;
        }
    }
    
    sort_down(probabilities, class_num);//排序 找出概率最大的一类
    //printf("%f",probabilities[0][1]);
    return (int)probabilities[0][1];
}
