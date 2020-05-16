# 机器学习C语言重现

### 1.作业说明

写代码时是以一个完整的C 语言 project形式进行，上传文件是实现算法的代码。完整的Xcode Project链接为。 其中每一个文件夹内包含头文件与C文件。 因为实现不同算法时使用了部分相同的函数，文件之间存在相互引用。 实现过程中，除C语言标准库外并未使用任何第三方库。 且算法均可应用在不同数据集上。 所有代码均有详细注释



### 2.实现算法

1. **简单线性回归(Sample Linear Regression)**
2. **多元线性回归(Multivariate Linear Regression)**
3. **感知机算法(Perceptron)**
4. **K近邻算法(K-Nearest Neighbors)**
5. **朴素贝叶斯(Naive Bayes)**
6. **学习矢量量化算法(Learning Vector Quantization)**

### 3.代码测试

以上的算法均实现泛化，可应用在不同的数据集上。 为确保准确性，均参照书《Machine Learning Algorithms  From Scratch  With Python》 数据使用书中数据，将程序学习结果与书中结果对比，进行测试。 所用数据在Data文件夹中

#### 		1.简单线性回归

书上测试过程

<img src="https://s1.ax1x.com/2020/05/01/JXnl1e.png" alt="1.1" border="0" width=70%>

使用相同数据 进行测试的结果

<img src="https://s1.ax1x.com/2020/05/01/JXn3Xd.png" alt="1.2" border="0" width=80%>



代码结果与书中结果相同

### 2.多元线性回归

多元线性回归测试采用以下数据，书中多元回归的过程将数据规范化后再计算。

<img src="https://s1.ax1x.com/2020/05/01/JXn16H.png" alt="2.1" border="0" width=70%>

用EXCEL 回归分析 结果如下

<img src="https://s1.ax1x.com/2020/05/01/JXnQpD.png" alt="2.2" border="0" width=70%>

代码测试结果如下

<img src="https://s1.ax1x.com/2020/05/01/JXu9HI.png" alt="JXu9HI.png" border="0" width=80%/></a>

输出系数与EXCEL中相同 

### 3.感知机

书中测试过程如下

<img src="https://s1.ax1x.com/2020/05/01/JXnGnA.png" alt="3.1" border="0" width=70%>

使用相同数据集 代码测试结果： 打印出的权重与书中相同  

<img src="https://s1.ax1x.com/2020/05/01/JXnY7t.png" alt="3.2" border="0" width=80%>

在 sonar 数据集上测试结果如下

<img src="https://s1.ax1x.com/2020/05/01/JX3cM8.png" alt="JX3cM8.png" border="0" width=80% height=80%>

### 4.K近邻

书中测试过程如下

<img src="https://s1.ax1x.com/2020/05/01/JXnJ0I.png" alt="4.1" border="0" width=70%>

使用相同数据为训练集，以下为测试结果  正确率为100%

<img src="https://s1.ax1x.com/2020/05/01/JXnNAP.png" alt="4.2" border="0" width=80% height=80%>

测试结果相同

在abalone 数据集上测试如下

<img src="https://s1.ax1x.com/2020/05/01/JX8CQK.png" alt="JX8CQK.png" border="0" width=80% height=80%/>



<img src="https://s1.ax1x.com/2020/05/01/JX3rGt.png" alt="JX3rGt.png" border="0" width=70%>




### 5.朴素贝叶斯

书中测试过程如下，结果为属于不同类别的概率

<img src="https://s1.ax1x.com/2020/05/01/JXnUtf.png" alt="5.1" border="0" width=70%>

使用相同数据 测试结果如下 与书中相同

<img src="https://s1.ax1x.com/2020/05/01/JXnah8.png" alt="5.2" border="0" width=80%>

然后在iris 数据集上测试完整的算法 测试集选取训练集的子集，以下为结果  正确率为：91.66%

<img src="https://s1.ax1x.com/2020/05/01/JXnw9S.png" alt="5.3" border="0" width=80%>



### 6.学习向量量化

书中测试结果 如下  

<img src="https://s1.ax1x.com/2020/05/01/JXn01g.png" alt="6.1" border="0" width=70%>

使用相同数据集 打印出的 原型向量 结果如下  与书中结果相同 

<img src="https://s1.ax1x.com/2020/05/01/JXnDXj.png" alt="6.2" border="0" width=80%>

在 ionosphere 数据集上测试完整算法结果如下 正确率为80.95%

<img src="https://s1.ax1x.com/2020/05/01/JXnBcQ.png" alt="6.3" border="0" width=80%>







​				

