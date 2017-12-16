#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//TRABALHO LISTA ENCADEA 
//Alunos: Paulo Vitor Carvalho Santos

struct node {
	int elemento;
	struct node *prox;
};
typedef struct node no; 

struct node * CriaListaVazia(){
	return NULL;
}

//------------------------------------------------------------------------------------------------------------------------
struct node * addNoLista(int info, struct node * p1){ //Insere o elemento especificado na posição especificada nesta lista
	// Cria novo no
	struct node * novo_no;
	novo_no= (struct node * ) malloc(sizeof(struct node ));
	//salva informacao
	novo_no->elemento=info;
	//conecta ao primeiro
	novo_no->prox=p1;
	return novo_no;
}

//------------------------------------------------------------------------------------------------------------------------
struct node *addAll_Lista1(struct node *lista1, struct node *lista2){//Anexa todos os elementos da coleção especificada ao final desta lista
    struct node *aux;
    struct node *atual;
    if(lista1==NULL){
        return lista2;
    }
    aux=lista1;
    do{
        atual=aux;
        aux=aux->prox;
    }while(aux!=NULL);
    atual->prox=lista2;
    return lista1;
}

//------------------------------------------------------------------------------------------------------------------------
struct node *addAll_Lista2 (int ant, int suc, struct node *p1, struct node *p2) {//Insere todos os elementos da coleção especificada nesta lista, começando na posição especificada.
struct node *aux=CriaListaVazia();
int i=0,j=0,y=0,z=0,size,*vetor1,*vetor2;
size = tamanho(p2);
vetor1 =(int*)malloc(sizeof(int) * size);
vetor2 =(int*)malloc(sizeof(int) * size);

if(suc>0){
	for(;j<suc;p1=p1->prox){
		vetor1[j]=p1->elemento;
		j++;
	}
}
if(ant>0){
	for(;y<ant-1;p2=p2->prox){
		y++;
	}
}
	while (p2!=NULL){	
		p1=addNoLista(p2->elemento, p1);
		p2=p2->prox;
	}

if(suc>0){	
	while(p1!=NULL){
		vetor2[z]=p1->elemento;
		p1=p1->prox;
		z++;
	}	
	for(i=z-1;i>=0;i--){
		aux=addNoLista(vetor2[i], aux);
	}
	for(i=j-1;i>=0;i--){
		aux = addNoLista(vetor1[i], aux);
	}
}
p1 = aux;
printf("\n\n----------addAll_Lista2----------");
return p1;
}
//------------------------------------------------------------------------------------------------------------------------

/*void freeLista(struct node* p1){ //Remove todos os elementos desta lista.
	if(!isEmpty(p1)){
		 no *aux, *atual;
		atual=p1->prox;
		while(atual != NULL){
			aux = atual->prox;
			free(atual);
			atual = aux;
		}	
	}
}*/
void lol_free (struct node* p1){ ////Remove todos os elementos desta lista.
    no* aux; // declara um auxiliar

    while(p1 != NULL) //percorre a lista enquanto foi diferente de null
    {
        aux = p1->prox; //aux recebe p1 e aponta pro proximo
        free(p1); //libera até a lista ficar vazia
        p1 = aux;
    }
    printf("\n\n--------- clear ---------\n");
    printf("Lista Apagada\n");
}

//------------------------------------------------------------------------------------------------------------------------

int isEmpty(struct node* p1){ //Retorna verdadeiro se esta lista não contiver elementos.
	if(p1==NULL)  // p1 se refere a litsa(estrutura)
		return 1;
		
	return 0;	//lista  não esta vazia
	
}

//------------------------------------------------------------------------------------------------------------------------
int tamanho(struct node * p1){ //Tamanho da lista
	int cont=0;
	struct node * aux = p1;
	while(aux!=NULL){
		aux=aux->prox;
		cont++;
	}
	return cont;
}

//------------------------------------------------------------------------------------------------------------------------
struct node * Remove (int elemento, struct node * inicio){//Remove o elemento na posição especificada nesta lista.
	struct node *aux, *ant;

	if (inicio==NULL) 
		return NULL;  // Lista vazia !!!
	else
	{   // se não estiver vazia, percorre a lista
		aux = inicio;
		ant = NULL;
		while (aux !=NULL && aux->elemento != elemento)
		{
	 	    ant = aux;
		    aux = aux->prox;
		}
	    if (aux == inicio) // removendo o primeiro da lista
	    {
			inicio = inicio->prox;
			free(aux);
	    }
	    else  // removendo do meio da lista
	    {
			ant->prox = aux->prox;  // aponta proximo recriando lista
			free(aux);                // Libera a area do nodo
	    }
	}
    return inicio; // apagada !!!
}

//------------------------------------------------------------------------------------------------------------------------
struct node * get(int posicao, struct node *p1){//Retorna o elemento na posição especificada nesta lista.
	int cont=0;
	while(p1!=NULL){
		if(posicao==cont){

			return p1;
		}else{
			p1 = p1->prox;
            cont++;
		}
	}
	return NULL;
}

//------------------------------------------------------------------------------------------------------------------------
struct node * set(int posicao, int new, struct node *p1){//muda o elemento na posição especificada.
	int cont=0;
	while(p1!=NULL){
		if(posicao==cont){
		    p1->elemento=new;
			return p1;
		}else{
			p1->elemento=new;
			p1 = p1->prox;
            cont++;
		}
	}
	return NULL;
}

//------------------------------------------------------------------------------------------------------------------------
int contains(struct node * p1, int elemento){//Retorna true se esta lista contiver o elemento especificado.
	struct node * aux = p1;
	while(aux!=NULL){
		if(aux->elemento == elemento)
			return 1;
		aux = aux->prox;
	}
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------
int arrayList(struct node *p1){
  struct node *aux = p1;
  int cont=0;
    while(aux!=NULL){
      aux=aux->prox;
        cont++;
    }
    //printf("\n\n---------- toArray -----------");
    //printf("\nTamanho Array: %d\n", cont);
  return  cont;
}

struct node * toArray(struct node* p1){//Retorna um vetor contendo todos os elementos desta lista na sequência apropriada (do primeiro ao último elemento).
	int *vetor;
	int tamLista=arrayList(p1);
	int i;
	
	vetor =(int*)malloc(sizeof(int) * tamLista);
	
	while(p1!=NULL){
		vetor[i]=p1->elemento;
		printf(" %d ",vetor[i]);
		p1=p1->prox;
		i++;
	}
}

//------------------------------------------------------------------------------------------------------------------------
void imprimir(struct node * p1){ //Exibindo os elementos da lista
	struct node * aux;
	for(aux=p1; aux!=NULL; aux=aux->prox)
		printf("\n %d", aux->elemento);
			
	}	


























int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	struct node * p1,*p2;
	
	
	
	p1=CriaListaVazia();
	
	//---------- add -----------
	printf("\n------------ Add -------------");
	p1=addNoLista(1, p1);
    p1=addNoLista(2, p1);
    p1=addNoLista(3, p1);
	p1=addNoLista(4, p1);
    
    
    imprimir(p1); //exibir lista
    
    //---------- addAll1 -------------
    //printf("\n------------ addAll_Lista1 -------------");
    p2=CriaListaVazia();
    p2=addNoLista(5,p2);
	p2=addNoLista(6,p2);
	p2=addNoLista(7,p2);
	p2=addNoLista(8,p2);
   //p2=addAll_Lista1(p1,p2);
   //imprimir(p1);
	
    //---------- addAllIndice2; -------------
   	//p1=addAll_Lista2(0,1,p1,p2);
	//imprimir(p1);
	
    /*
    //------------ size ----------------
    printf("\n------------ Size -------------");
    printf("\nTamanho %d\n", tamanho(p1));
    
	//-------- isEmpty --------------
	printf("\n-------- isEmpty --------------");
	if(isEmpty(p1) == 0)
		printf("\nA lista NAO esta vazia!!\n\n");
	else
		printf("\n\nLista vazia!!\n\n"); 
	
	//---------- get -----------
	printf("---------- Get -----------");
	get(1,p1);
	printf("\n1º posicao- %d", p1->prox->prox->prox->elemento);
	printf("\n2º posicao- %d", p1->prox->prox->elemento);
	printf("\n3º posicao- %d", p1->prox->elemento);
	printf("\n4º posicao- %d", p1->elemento);
	
	//---------- remove -----------
	printf("\n\n---------- Remove -----------");
	p1=Remove(3,p1);
	imprimir(p1);
	
	//---------- contains -----------
	printf("\n\n---------- Contains -----------");
	if (contains(p1,2))
	printf("\nElemento encontrado!");
	else
	printf("\nElemento NAO encontrado!");
		
	//---------- set -------------
	printf("\n\n---------- set -------------");	
	p1=set(0,50,p1);//posição\modificação
	imprimir(p1);	
		
	//---------- toArray -------------
	printf("\n\n---------- toArray -----------\n");	
	toArray(p1);
		
	//---------- clear -----------
	//free(p1); printf("\n\nLista liberada!");
	lol_free(p1);	
		
*/
	
//add	
//isEmpty	
//clear
//size
//remove
//get
//contains
//set
	
	return 0;
	
}
