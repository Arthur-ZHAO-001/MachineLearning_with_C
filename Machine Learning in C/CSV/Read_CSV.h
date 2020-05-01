//
//  Read_CSV.h
//  Machine Learning in C
//
//  Created by 赵呈亮 on 2020/4/15.
//  Copyright © 2020 赵呈亮. All rights reserved.
//

#ifndef Read_CSV_h
#define Read_CSV_h
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define Sample_num 1000 //定义最大样本数 可手动修改
#define MAX_LINE_SIZE 20480 // 定义读csv文件时一行的大小
#define feature_num 100//定义最大feature数 可手动
#endif /* Read_CSV_h */
void read_csv(char *file,float value[Sample_num][feature_num]);
int GetTotalColCount(char *file);
int GetTotalLineCount(char *file);
