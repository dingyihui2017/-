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
bool InitList (List *&L){  //����һ���յ�˳��� 
	L->elem=new ElemType [LIST_INIT_SIZE];//�����ڴ� 
	if(!L->elem){
		return false;}
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return true;
}
bool Search(List *&L,int n){ //���ֲ��� 
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
void Sort(List*&L){  //ð�� ���� 
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
	if(i<1||i>L->length+1){ //�����ֵ���淶 
		cout<<"�������"<<endl;
		return false;
	}
	if(L->length>=L->listsize){ //������ǰ���ڴ�ռ䣬���ӷ����� 
	L->elem=(ElemType*)realloc(L->elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType)); 
	if(!L->elem){
		cout<<"�ڴ����ʧ��";
		return false;
	}
	L->listsize+=LISTINCREMENT;
	}
	int *p,*q;
	p=&(L->elem[L->length-1]);//δ�ƶ�ǰ���һ��Ԫ�صĵ�ַ����p 
	q=&(L->elem[i-1]);//����λ�õĵ�ַ����q 
	for(p;p>=q;p--){ //����λ��֮�󼰲���λ�õ�Ԫ������ 
		*(p+1)=*(p);
	}
	*q=e;
	++L->length;
	return true;
}
bool ListDelete (List *&L,int i,int &e){ //ɾ����i��λ�õ�Ԫ�أ���������ֵ�� 
	if(i<1||i>L->length){//�����ֵ���淶 
		cout<<"�������";
		return false;
	}
	int *p,*q;
	p=&(L->elem[i-1]);//ɾ��������
	e=*p;//����ɾ�������� 
	q=L->elem+L->length-1;//���һ��Ԫ�صĵ�ַ����q
	for(p;p<q;p++){ //��ɾ��֮���Ԫ������ 
		*(p)=*(p+1);
	} 
	--L->length;
	return true;
} 
void print(List*L){ //���˳��� 
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
     cout<<"������һ��������";
     cin>>n;
     cout<<"������"<<n<<"������"<<endl; 
     for(i=0;i<n;i++){
     	L->length++;
     	cin>>L->elem[i];
	 }
	 int e1=0;
	 int e2=0;
	 int i1,i2;
	 cout<<"��������ɾ����λ�ã�";
	 cin>>i1;
	 ListDelete(L,i1,e1);
	 cout<<"ɾ��������Ϊ:"<<e1<<endl;
	 print(L);
	 cout<<"����������ӵ�λ�ú����ݣ�"<<endl;
	 cin>>i2>>e2; 
	 ListInsert(L,i2,e2);
	 print(L);
	 cout<<"���������"<<endl;
	 Sort(L);
	 print(L); 
	 int number;
	 cout<<"����������ҵ����ݣ�"<<endl;
	 cin>>number;
	 if(Search(L,number)){
	 	cout<<"�ɹ��ҵ�����"<<number<<endl;
	 }
	 return 0;
}
