//
// Created by zhanghao on 2022/4/23.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using  namespace std;

struct Student{
    string name;
    int score;

    bool operator<(const Student & otherStudent){
        //如果两人的成绩相等，名字字典序在前的返回；
        if(score == otherStudent.score)
            return name < otherStudent.name;
        return score < otherStudent.score;
    }
    //声明友元函数，operator<< 是我的朋友，所以他可以调用我的私有变量；
    friend ostream& operator<<(ostream & os,const Student &student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};


#endif //SELECTIONSORT_STUDENT_H
