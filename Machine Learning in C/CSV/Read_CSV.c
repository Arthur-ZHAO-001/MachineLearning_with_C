//
//  Read_CSV.c
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#include "Read_CSV.h"
int GetTotalLineCount(char *file){
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
int GetTotalColCount(char *file){
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
void read_csv(char *file, float value[Sample_num][feature_num])
{
//    int row_num=GetTotalLineCount(file);
//    int col_num=GetTotalColCount(file);
    
    char delim[] = ",";
    FILE *fp = NULL;
       char *line,*record;
       char buffer[MAX_LINE_SIZE];//这个数组大小也根据自己文件的列数进行相应修改。
    int i = 0,j =0;
       //long siz=sizeof(fir_line);
       
       if((fp = fopen(file, "r")) != NULL)
       {
           fseek(fp, 0, SEEK_SET);
           while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//当没有读取到文件末尾时循环继续
           {
               
//              printf("%s\n",line);
               record = strtok(line,delim);
               
               while (record != NULL)//读取每一行的数据
               {
                   float v;
                   
                   v=atof(record);
                   //atof(record);
                   //printf("%f\n", v);
                   value[i][j]=v;
                   
                   record = strtok(NULL,delim);
                   j++;
               }
               j=0;
               i++;
           }
           fclose(fp);
           fp = NULL;
       }
    //printf("%f\n", value[3][1]);
    
    
 }
