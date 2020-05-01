//
//  Read_CSV.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Read_CSV.h"
int GetTotalLineCount(char *file){  //获取csv文件的总行数 返回 int型整数：总行数
   int i = 0;
    FILE *fp = NULL;
      char *line;
      char strLine[MAX_LINE_SIZE];
      if((fp = fopen(file, "r")) != NULL){
        fseek(fp,0,SEEK_SET);
          while ((line = fgets(strLine, MAX_LINE_SIZE, fp))!=NULL){
          i++;
          }
      }
     fclose(fp);
      return i;
}
int GetTotalColCount(char *file){  //获取csv文件的总列数 返回 int型整数：总列数
     int i = 0;
        FILE *fp = NULL;
            char *line,*record;
            char strLine[MAX_LINE_SIZE];
    if((fp = fopen(file, "r")) != NULL){
     line = fgets(strLine, MAX_LINE_SIZE, fp);
     record = strtok(line,",");
     while (record != NULL){
        record = strtok(NULL,",");
        i++;
     }
    }
        fclose(fp);
        return i;
}
void read_csv(char *file, float value[Sample_num][feature_num]) //读取csv文件  将整个csv文件 存储到一个二维数组中 每一行是一个一维数组
{

    
    char delim[] = ",";
    FILE *fp = NULL;
       char *line,*record;
       char buffer[MAX_LINE_SIZE];//这个数组大小也根据自己文件的列数进行相应修改。
    int i = 0,j =0;
       
       
       if((fp = fopen(file, "r")) != NULL) //确保读到文件
       {
           fseek(fp, 0, SEEK_SET);
           while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//当没有读取到文件末尾时循环继续
           {
               
//
               record = strtok(line,delim);
               
               while (record != NULL)//读取每一行的数据
               {
                   float v;
                   
                   v=atof(record); //将字符串转为float
                   
                   value[i][j]=v; //将每一个数据点储存到二维数组中
                   
                   record = strtok(NULL,delim);
                   j++;
               }
               j=0;
               i++;
           }
           fclose(fp);
           fp = NULL;
       }
   
    
    
 }
