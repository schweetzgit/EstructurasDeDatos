
typedef struct nodo{
	float dat;
	struct nodo *p;
}nod;
nod*tope=NULL;

void push(float ndat){
	nod *nvo;
	nvo = new nod;
	nvo->dat = ndat;
	if(tope == NULL){
		nvo->p = NULL;
	}
	else{
		nvo->p = tope;
	}
	tope = nvo;
}


typedef struct nodo{
	char x;
	struct nodo *p;
}sn;
sn *inic = NULL;

void inserta (int num){
	sn *aux, *aux2 = inic;
	aux = new sn;
	aux->x = num;
	aux->p = NULL;
	if(inic == NULL){
		inic=aux;
	} 
	else{
		while(aux2->p! = NULL){
			aux2 = aux2->p;
		} 
		aux2->p = aux;
	}
}

void sacar(){
	sn *aux = inic;
	if(inic == NULL) {
		cout<<"\nFila o Cola vacia";
		return;
	}
	inic = inic->p;
	cout<<"\nSale"<<aux->x; 
	delete(aux);
}



