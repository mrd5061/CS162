

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
using std::queue;


int randNum();


void addNum(queue<int>*, int, int);
int removeNum(queue<int>*, int);
void outputBuffer(queue<int>* ptr);






#endif