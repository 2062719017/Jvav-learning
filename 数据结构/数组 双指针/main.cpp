#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string>
using namespace std;
//�濿�� ż����
void AdjustArray(int arr[],int size) {
    int *p=arr;
    int *q=arr+size-1;
    while (p<q) {

        //p->��
        while (p<q){
            if ((*p & 0x1)==1) {
            break;
            }
            p++;
        }

        //q->ż��
        while (p<q) {
            if ((*q & 0x1)==0) {
            break;
            }
            q--;
        }

        if (p<q){
            //p->���� q->ż��
            int temp=*p;
            *p=*q;
            *q=temp;
            p++;
            q--;
        }
    }
}

//�����ַ���
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

//�����ʵ��
class Array {
private:
    int *mpArry;//ָ������ݵ�����
    int mCap;//��������capacity
    int mCur;//������ЧԪ�ظ��� ���һ��Ԫ�صĺ��λ��
private:
    void expand(int size) {
        int *p=new int [size];
        memcpy(p,mpArry,sizeof(int )*mCap);
        mpArry=p;
        mCap=size;
    }//����
public:
    Array(int size=10):mCur(0),mCap(size) {
        mpArry = new int[mCap]();
    }
    ~Array() {
        delete[] mpArry;
        mpArry = nullptr;
    }
public:
    //ĩβ����Ԫ��
    void push_back(int val) {
        if (mCur==mCap) {
            expand(2*mCap); //O(n)
        }//�������->����

        mpArry[mCur++] = val;
    }
    //ĩβɾ��Ԫ��
    void pop_back() {
        if (mCur==0) {
            return;
        }
        mCur--;
    }
    //��λ������Ԫ��
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
    //��λ��ɾ��
    void erase(int pos) {
        if (pos<0 || pos>=mCur) {
            return;
        }

        for (int i=pos+1;i<mCur-1;i++) {
            mpArry[i-1] = mpArry[i];
        }
        mCur--;
    }
    //��ѯԪ��
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
    //��������
    {std::cout << "Hello World!" << std::endl;
        Array arr;
        srand(time(0));
        std::cout<<"�������������"<<std::endl;
        for (int i=0;i<10;i++) {
            arr.push_back(rand()%100);
        }
        arr.show();
        std::cout<<"ɾ��ĩβԪ��"<<std::endl;
        arr.pop_back();
        arr.show();
        std::cout<<"�����һ��Ԫ��100"<<std::endl;
        arr.insert(0,100);
        arr.show();
        std::cout<<"�����ʮ��Ԫ��200"<<std::endl;
        arr.insert(10,200);
        arr.show();
        std::cout<<"Ѱ�ҵڡ�100��Ԫ�ز�ɾ��"<<std::endl;
        int pos=arr.find(100);
        if (pos!=-1) {
            arr.erase(pos);
            arr.show();
        }}
    std::cout<<"---------------------"<<std::endl;
    //˫ָ�� �����ַ�����
    {
        char ch[]="HELLO WORLD";
        cout<<ch<<endl;
        Reverse(ch,strlen(ch));
        std::cout<<ch<<std::endl;}
    std::cout<<"---------------------"<<std::endl;
    //˫ָ��ʵ����ż����������ż ���棩
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