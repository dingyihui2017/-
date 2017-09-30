#include <iostream>
#include <malloc.h> 
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
struct List{
	ElemType *elem;
	int length;
	int listsize;};
bool InitList (List *&L){  //创建一个空的顺序表 
	L->elem=new ElemType [LIST_INIT_SIZE];//分配内存 
	if(!L->elem){
		return false;}
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return true;
}
bool Search(List *&L,int n){ //二分查找 
	int high;
	int low;
	low=0;
	high=L->length-1;
	while(high>=low){
		if(n>L->elem[(high+low)/2]){
			low=(high+low)/2+1;
		}
		else if(n<L->elem[(high+low)/2]){
			high=(high+low)/2-1;
		}
		else if(n==(L->elem[(high+low)/2])){
			return (high+low)/2;
		}
	}
	return false;
}
void Sort(List*&L){  //冒泡 递增 
	int i,j;
	for(i=0;i<L->length-1;i++){
		for(j=0;j<(L->length-i-1);j++){
			if(L->elem[j]>L->elem[j+1]){
				int temp=0;
				temp=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=temp;
			}
		}
	}
}
bool ListInsert(List *&L,int i,int e){
	if(i<1||i>L->length+1){ //输入的值不规范 
		cout<<"输入错误"<<endl;
		return false;
	}
	if(L->length>=L->listsize){ //超出当前的内存空间，增加分配量 
	L->elem=(ElemType*)realloc(L->elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType)); 
	if(!L->elem){
		cout<<"内存分配失败";
		return false;
	}
	L->listsize+=LISTINCREMENT;
	}
	int *p,*q;
	p=&(L->elem[L->length-1]);//未移动前最后一个元素的地址赋给p 
	q=&(L->elem[i-1]);//插入位置的地址赋给q 
	for(p;p>=q;p--){ //插入位置之后及插入位置的元素右移 
		*(p+1)=*(p);
	}
	*q=e;
	++L->length;
	return true;
}
bool ListDelete (List *&L,int i,int &e){ //删除第i个位置的元素，并返回其值； 
	if(i<1||i>L->length){//输入的值不规范 
		cout<<"输入错误";
		return false;
	}
	int *p,*q;
	p=&(L->elem[i-1]);//删除的数据
	e=*p;//返回删除的数据 
	q=L->elem+L->length-1;//最后一个元素的地址赋给q
	for(p;p<q;p++){ //被删除之后的元素左移 
		*(p)=*(p+1);
	} 
	--L->length;
	return true;
} 
void print(List*L){ //输出顺序表 
	int i;
	 for(i=0;i<L->length;i++){
	 	cout<<L->elem[i]<<" ";
	 }
	 cout<<endl;
}	
int main (){
	 List *L;
	 L=new List;
     InitList(L);
     int i;
     int n;
     cout<<"请输入一个整数：";
     cin>>n;
     cout<<"请输入"<<n<<"个数据"<<endl; 
     for(i=0;i<n;i++){
     	L->length++;
     	cin>>L->elem[i];
	 }
	 int e1=0;
	 int e2=0;
	 int i1,i2;
	 cout<<"请输入想删除的位置：";
	 cin>>i1;
	 ListDelete(L,i1,e1);
	 cout<<"删除的数据为:"<<e1<<endl;
	 print(L);
	 cout<<"请输入想添加的位置和数据："<<endl;
	 cin>>i2>>e2; 
	 ListInsert(L,i2,e2);
	 print(L);
	 cout<<"递增排序后"<<endl;
	 Sort(L);
	 print(L); 
	 int number;
	 cout<<"请输入想查找的数据："<<endl;
	 cin>>number;
	 if(Search(L,number)){
	 	cout<<"成功找到数据"<<number<<endl;
	 }
	 return 0;
}
