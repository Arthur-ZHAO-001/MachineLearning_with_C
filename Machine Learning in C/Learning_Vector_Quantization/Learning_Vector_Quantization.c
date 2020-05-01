//
//  Learning_Vector_Quantization.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/28.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Learning_Vector_Quantization.h"
//欧式距离的计算 使用KNN.h中的函数
int get_best_matching_unit(float codebooks[][feature_num],float test[],int n_codebooks,int col_num, float bmu[]){ //获取最佳匹配的数据点。 返回int型整数：次最佳匹配的点在原型向量中 的位置 （数组里的index）
    float distance[n_codebooks][col_num+2];
    for(int p=0;p<n_codebooks;p++){
        distance[p][col_num]=euclidean_diatance(codebooks[p], test, col_num);
        distance[p][col_num+1]=(float)p;
        for(int q=0;q<col_num;q++){
            distance[p][q]=codebooks[p][q];
        }
    }
    
    //根据距离排序
    for(int i=0;i<n_codebooks-1;i++){
        for(int j=0;j<n_codebooks-i-1;j++){
            if(distance[j][col_num]>distance[j+1][col_num])
                exchange_array(distance[j],distance[j+1],col_num+2);
        }
    }
    //赋值 找到 beat matching unit
    for(int k=0;k<col_num;k++){
        bmu[k]=distance[0][k];
    }
    
    return (int)distance[0][col_num+1];
    
}

void random_codebooks(float train[][feature_num],int row_num,int col_num,float codebook[][feature_num],int n_codebooks){ //随机生成一组原型向量
    unsigned int seed = 4;
    srand(seed);
    for(int n=0;n<n_codebooks;n++){
    for(int i=0;i<col_num;i++){
        int rN1 = (rand() % row_num);
        codebook[n][i]=train[rN1][i];
    }
    }
}
void train_codebooks(float train[][feature_num],int row_num,int col_num,float codebooks[][feature_num],int n_codebooks,float learning_rate,int epochs){ //训练更新原型向量
    random_codebooks(train, row_num, col_num, codebooks, n_codebooks);
    for(int epoch=0;epoch<epochs;epoch++){
        float rate = learning_rate*(1.0-((float)epoch/(float)epochs));
        for(int row=0;row<row_num;row++){
            float bmu[col_num];
            for(int b=0;b<col_num;b++){
                bmu[b]=0.0;
            }
            int index=get_best_matching_unit(codebooks, train[row], n_codebooks, col_num, bmu);
            for(int ii =0;ii<col_num-1;ii++){
                float error= train[row][ii]-bmu[ii];
                if(bmu[col_num-1]==train[row][col_num-1]){
                    bmu[ii]+=rate*error;
                }
                else{
                    bmu[ii]-=rate*error;//进行更新
                }
            }
            for(int col=0;col<col_num;col++){
                codebooks[index][col]=bmu[col]; //用新的最佳匹配点 代替 原型向量中的 同位置的点
            }
                
        }
    }
    //以下打印代码仅作测试使用
//    printf("%f\n",codebooks[0][0]);
//    printf("%f\n",codebooks[0][1]);
//    printf("%f\n",codebooks[0][2]);
//    printf("%f\n",codebooks[1][0]);
//    printf("%f\n",codebooks[1][1]);
//    printf("%f\n",codebooks[1][2]);
}
float predict_LVQ(float codebook[][feature_num], float test[],int n_codebooks,int col_num){ //输入一条数据 预测其类别
    float bmu[col_num];
    int f = get_best_matching_unit(codebook, test, n_codebooks, col_num, bmu);
    return bmu[col_num-1];
}
void Learing_Vector_quantization(char *train_file, char *test_file, int n_codebooks,float learning_rate, int epochs){ ///算法封装 输入训练/测试集文件  及相关超参数。 打印出预测类别  及 总体 正确率
    float train[Sample_num][feature_num];
    float test[Sample_num][feature_num];
    
    read_csv(train_file, train);
    read_csv(test_file, test);
    int correct_num=0;
    int row_num = GetTotalLineCount(train_file);
    int col_num =GetTotalColCount(train_file);
    int test_num=GetTotalLineCount(test_file);
    float prediction[test_num];
    float codebooks[n_codebooks][feature_num];
    for(int mm=0;mm<2;mm++){
        for(int nn=0;nn<feature_num;nn++){
            codebooks[mm][nn]=0.0;
        }
    }
    train_codebooks( train, row_num, col_num, codebooks, n_codebooks, learning_rate, epochs);
    for(int w =0;w<test_num;w++){
        prediction[w]=predict_LVQ(codebooks, test[w], n_codebooks, col_num);
        if(prediction[w]==test[w][col_num-1]){
            correct_num++;
        }
        printf("Expect %f Got %f\n",test[w][col_num-1],prediction[w]);
    }
    printf("Accuracy is %f\n",(float)correct_num/test_num);
}
