#include <stdio.h>
#include <iostream>
using namespace std;

class classStack3{
	public:
		classStack3(int size){
			this->size = size;
			buf = new int[size * 3];	
			top[0] = top[1] = top[2] = -1;
		}

		~classStack3(){
			delete[] buf;
		}

		void push(int stackNum,int val){
			int point = stackNum * size + top[stackNum] + 1;
			if(stackNum == 1 && point < 300){
				buf[point] = val;
				++top[stackNum];
			}
			else if(stackNum == 2 && point < 600){
				buf[point] = val;
				++top[stackNum];
			}
			else if(stackNum == 3 && point < 900){
				buf[point] = val;
				++top[stackNum];
			}
			else{
				printf("except error");
				return;
			}
		}

		void pop(int stackNum){
			--top[stackNum];
		}

		int gtop(int stackNum){
			int point = stackNum * size + top[stackNum];
			return buf[point];
		}

		bool empty(int stackNum){
			if(top[stackNum] == -1)
				return true;
			else
				return false;
		}
	private:
		int top[3];
		int size;
		int* buf;
};
