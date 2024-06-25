#include<iostream>
#define n 9
using namespace std;

void imprimeVect(int vector[]){
	cout<<" ";
	for(int i = 0; i < n; i++){
		cout<<" "<<vector[i]<< "  ";
	}
	cout<<"\n";
}

void intercambio(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void HeapSort(int vec[]){
    int i,j;
    for (i = 0; i < n ;i++){
       j = i+1;
       while(j>1)
          if (vec[j-1] > vec[j/2-1]){
              intercambio(vec[j-1],vec[j/2-1]);
              j /= 2;
          }
          else
              break;
    }
    for(i = n-1; i >= 0;i--){
        intercambio(vec[0],vec[i]);
        j = 1;
        while (j*2<i)
           if (j*2+1>i)
             if(vec[j-1] > vec[j*2-1])
                break;
             else{
                intercambio (vec[j-1],vec[j*2-1]);
                j*=2;
             }
           else
              if (vec[j*2-1] > vec[j*2])
                if (vec[j-1] > vec[j*2-1])
                   break;
                else{
                   intercambio (vec[j-1],vec[j*2-1]);
                   j *=2;
                }
              else
                if(vec[j-1] > vec[j*2])
                   break;
                else{
                   intercambio (vec[j-1],vec[j*2]);
                    j *= 2+1;
                }
        
    }
}//cierra la función HeapSort

main(){
	int vect[n] ={ 44,55,12,42,94,18,06,67,0};
	cout<<"\n Secuencia original\n";
	imprimeVect(vect);
	cin.get();
	HeapSort(vect);
	cout<<"\n Secuencia ordenada por metodo Heapsort\n";
	imprimeVect(vect);
}
