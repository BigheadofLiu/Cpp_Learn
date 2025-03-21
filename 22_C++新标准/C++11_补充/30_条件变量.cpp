//
// Created by ZYB on 2025/3/14.
//
// condition_variable
// condition_variable_any

//线程同步之条件变量
//https://subingwen.cn/cpp/condition/

//condition_variable
//成员函数：线程等待（阻塞）函数、线程通知（唤醒）函数
//调用wait线程被阻塞
// ①
//void wait (unique_lock<mutex>& lck);
// ②
// template <class Predicate>
// void wait (unique_lock<mutex>& lck, Predicate pred);
// 函数①：调用该函数的线程直接被阻塞
// 函数②：该函数的第二个参数是一个判断条件，是一个返回值为布尔类型的函数

// 条件变量通常用于生产者和消费者模型