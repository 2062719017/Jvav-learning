#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string>
using namespace std;
//奇靠右 偶靠左
void AdjustArray(int arr[],int size) {
    int *p=arr;
    int *q=arr+size-1;
    while (p<q) {

        //p->奇
        while (p<q){
            if ((*p & 0x1)==1) {
            break;
            }
            p++;
        }

        //q->偶数
        while (p<q) {
            if ((*q & 0x1)==0) {
            break;
            }
            q--;
        }

        if (p<q){
            //p->奇数 q->偶数
            int temp=*p;
            *p=*q;
            *q=temp;
            p++;
            q--;
        }
    }
}

//逆序字符串
void Reverse(char arr[],int size) {
    char *p = arr;
    char *q = arr+size-1;
    while (p < q) {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}

//数组的实现
class Array {
private:
    int *mpArry;//指向可扩容的数组
    int mCap;//数组容量capacity
    int mCur;//数组有效元素个数 最后一个元素的后继位置
private:
    void expand(int size) {
        int *p=new int [size];
        memcpy(p,mpArry,sizeof(int )*mCap);
        mpArry=p;
        mCap=size;
    }//扩容
public:
    Array(int size=10):mCur(0),mCap(size) {
        mpArry = new int[mCap]();
    }
    ~Array() {
        delete[] mpArry;
        mpArry = nullptr;
    }
public:
    //末尾增加元素
    void push_back(int val) {
        if (mCur==mCap) {
            expand(2*mCap); //O(n)
        }//如果满了->扩容

        mpArry[mCur++] = val;
    }
    //末尾删除元素
    void pop_back() {
        if (mCur==0) {
            return;
        }
        mCur--;
    }
    //按位置增加元素
    void insert(int pos, int val) {
        if (pos<0 || pos>mCur) {
            return;//throw "pos in"
        }
        if (pos==mCap) {
            expand(2*mCap);
        }
        for (int i=mCur;i>pos;i--) {
            mpArry[i] = mpArry[i-1];
        }
        mpArry[pos] = val;
    }
    //按位置删除
    void erase(int pos) {
        if (pos<0 || pos>=mCur) {
            return;
        }

        for (int i=pos+1;i<mCur-1;i++) {
            mpArry[i-1] = mpArry[i];
        }
        mCur--;
    }
    //查询元素
    int find(int val) {
        for (int i=0;i<mCur;i++) {
            if (mpArry[i]==val) {
                return i;
            }
        }
        return -1;
    }
    void show() {
        for (int i=0;i<mCur;i++) {
            std::cout << mpArry[i] << " ";
        }
        std::cout<<std::endl;
    }
};
int main() {
    //测试数组
    {std::cout << "Hello World!" << std::endl;
        Array arr;
        srand(time(0));
        std::cout<<"随机数存入数组"<<std::endl;
        for (int i=0;i<10;i++) {
            arr.push_back(rand()%100);
        }
        arr.show();
        std::cout<<"删除末尾元素"<<std::endl;
        arr.pop_back();
        arr.show();
        std::cout<<"插入第一个元素100"<<std::endl;
        arr.insert(0,100);
        arr.show();
        std::cout<<"插入第十个元素200"<<std::endl;
        arr.insert(10,200);
        arr.show();
        std::cout<<"寻找第“100”元素并删除"<<std::endl;
        int pos=arr.find(100);
        if (pos!=-1) {
            arr.erase(pos);
            arr.show();
        }}
    std::cout<<"---------------------"<<std::endl;
    //双指针 交换字符数组
    {
        char ch[]="HELLO WORLD";
        cout<<ch<<endl;
        Reverse(ch,strlen(ch));
        std::cout<<ch<<std::endl;}
    std::cout<<"---------------------"<<std::endl;
    //双指针实现奇偶数交换（左偶 右奇）
    int arr2[10]={ 0 };
    for (int i=0;i<10;i++) {
        arr2[i]=rand()%1000;
        std::cout<<arr2[i]<<' ';
    }
    std::cout<<std::endl;
    AdjustArray(arr2,sizeof(arr2)/sizeof(int));
    for (int i=0;i<10;i++) {
        std::cout<<arr2[i]<<' ';
    }
    return 0;
}