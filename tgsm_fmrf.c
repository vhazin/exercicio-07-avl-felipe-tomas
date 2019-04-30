#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int altura;
  int nome;
  struct node* esquerda;
  struct node* direita;
}Node;

Node* inserir (Node* raiz, int x);
int getAlturas (Node* raiz);
Node* rotacaoEsquerda(Node*raiz);
Node* rotacaoDireita(Node* raiz);
int getAltura(Node* raiz);
void acharIndex(Node* raiz, int y, int size, );
void emOrdem(Node* raiz);

int main(){
  Node* raiz = NULL;
  int q;
  scanf("%d", &q);

  for (int i = 0; i < q; i++){
    int x, y;
    scanf("%d %d",&x, &y);

    if(x == 1){
      raiz = inserir(raiz, y);
    }else{
      acharIndex(raiz, y, q-1, output);
    }

  }
}

Node* inserir(Node* raiz,int x){

  if(raiz == NULL){
    raiz = (struct node*)malloc(sizeof(struct node));
    raiz->nome = x;
    raiz->esquerda = NULL;
    raiz->direita  = NULL;
  }
  else{
    if(x > raiz->nome){
      raiz->direita = inserir(raiz->direita , x);
      if(getAlturas(raiz) == -2){
        if(x > raiz->direita->nome){
          raiz = rotacaoEsquerda(raiz);
        }else{
          raiz->direita = rotacaoDireita(raiz->direita);
          raiz = rotacaoEsquerda(raiz);
        }
      }
    }
    else{
      if(x < raiz->nome){
        raiz->esquerda = inserir(raiz->esquerda , x);
        if(getAlturas(raiz) == 2){
          if(x < raiz->esquerda->nome){
            raiz = rotacaoDireita(raiz);
          }else{

            raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
            raiz = rotacaoDireita(raiz);
          }
        }
      }
    
    raiz->altura = getAltura(raiz);
    }
  }
  return(raiz);
}

int getAlturas(Node* raiz){
  int esquerdah;
  int direitah;
  if(raiz == NULL){
    return(0);
  }
 
  if(raiz->esquerda==NULL){
    esquerdah = 0;
  }
  else{
    esquerdah = 1 + raiz->esquerda->altura;
  }
 
  if(raiz->direita == NULL){
    direitah = 0;
  }
  else{
    direitah = 1 + raiz->direita->altura;
  }
 
  return(esquerdah - direitah);
}

Node* rotacaoEsquerda(Node*raiz){
  Node* temp;
  temp = raiz->direita;
  raiz->direita = temp->esquerda;
  temp->esquerda = raiz;
  raiz->altura = getAltura(raiz);
  temp->altura = getAltura(temp);
  
  return temp;
}

Node* rotacaoDireita(Node* raiz){
  Node* temp;
  temp = raiz->esquerda;
  raiz->esquerda = temp->direita;
  temp->direita = raiz;
  raiz->altura = getAltura(raiz);
  temp->altura = getAltura(temp);
  return temp;
}

int getAltura(Node* raiz){
  int esquerdah;
  int direitah;
  if(raiz == NULL){
    return 0;
  }
  
  if(raiz->esquerda == NULL){
    esquerdah = 0;
  }else{
    esquerdah = 1 + raiz->esquerda->altura;
  }
    
  if(raiz->direita == NULL){
    direitah = 0;
  }else{
    direitah = 1 + raiz->direita->altura;
  }
  
  if(esquerdah > direitah){
    return(esquerdah);
  }
  
  return(direitah);
}

void acharIndex(Node* raiz, int y, int size){
  static int count = 0;
  if(raiz != NULL){
    acharIndex(raiz->esquerda, y, size);
    count++;
    if(raiz->nome == y){
      printf("%d \n", count - 1);
      return;
    }else if(count == size){
      printf("Data tidak ada\n");
    }
    acharIndex(raiz->direita, y, size);

  }
  
}

void emOrdem(Node* raiz){
  if(raiz != NULL){
    emOrdem(raiz->esquerda);
    printf("%d\n",raiz->nome);
    emOrdem(raiz->direita);
  }
}
	}

	return 0;
}
