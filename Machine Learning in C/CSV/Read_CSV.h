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
#define Sample_num 1000
#define MAX_LINE_SIZE 20480
#define feature_num 100
#endif /* Read_CSV_h */
void read_csv(char *file,float value[Sample_num][feature_num]);
int GetTotalColCount(char *file);
int GetTotalLineCount(char *file);
