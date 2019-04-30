
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *left;
	struct node *right;
	struct node *father;
	int alt;
}Node;

int getaltura (Node *no){
	if (no == NULL){
		return 0;
	}
	else{
		return(no->alt);
	}
}

void atualizaAlt (Node *no){
	int altDireita;
	int altEsquerda;

	if (no != NULL)
	{
		altDireita = getaltura(no->right);
		altEsquerda = getaltura(no->left);
	
	}
}

Node* createTree (int info, Node *esq, Node *dir){
	Node *raiz;
	raiz = (Node*)malloc(sizeof(Node));

	raiz->num = info;
	raiz->left = esq;
	raiz->right = dir;
	esq->father = raiz;
	dir->father = raiz;

	return(raiz);
}

Node* rotacaoEsquerda (Node *raiz){
	Node *aux = (Node*)malloc(sizeof(Node));
	aux = raiz->right;
	raiz->right = aux->left;
	aux->left = raiz;
	aux->father = raiz->father;
	raiz->father = aux;
	raiz->right->father = raiz;
	atualizaAlt(raiz->left);
	atualizaAlt(raiz);

	return (aux);
}

Node* rotacaoDireita (Node *raiz){
	Node *aux =(Node*) malloc(sizeof(Node));
	aux = raiz->left;
	raiz->left = aux->right;
	aux->right = raiz;
	aux->father = raiz->father;
	raiz->father = aux;
	raiz->left->father = raiz;
	atualizaAlt(raiz->right);
	atualizaAlt(raiz);

	return (aux);
}

Node* rotacaoDuplaEsquerda (Node *raiz){
	Node *resultado =(Node*) malloc(sizeof(Node));

	raiz->right = rotacaoDireita(raiz->right);
	resultado = rotacaoEsquerda(raiz->left);

	return(resultado);
}



Node* rotacaoDuplaDireita (Node *raiz){
	Node *resultado =(Node*) malloc(sizeof(Node));
	raiz->left = rotacaoEsquerda(raiz->left);
	resultado = rotacaoDireita(raiz->right);

	return(resultado);
}

void inserir (int x, Node *raiz){

	if (raiz == NULL)
	{
		raiz =(Node*) malloc(sizeof(Node));
		raiz->num = x;
		raiz->left = NULL;
		raiz->right = NULL;
		raiz->alt = 1;
	}
	else{
		if (x < raiz->num){
			inserir(x, raiz->left);
			if (((getaltura(raiz->left)) - (getaltura(raiz->right))) == 2){
				if (x < raiz->left->num){
					rotacaoDireita(raiz);
				}
				else{
					rotacaoDuplaDireita(raiz);
				}
			}

		}
		else{
			inserir(x, raiz->right);
			if (((getaltura(raiz->right)) - (getaltura(raiz->left))) == 2){
				if (x > raiz->right->num){
					rotacaoEsquerda(raiz);
				}
				else{
					rotacaoDuplaEsquerda(raiz);
				}
			}
		}
	}
	atualizaAlt(raiz);
}

void inOrdem(Node *x){
	if (x != NULL){
		inOrdem(x->left);
		printf("%d\n",x );
		inOrdem(x->right);
	}
}

Node* buscar(int value, Node *tree){
	if (tree == NULL){
		return (NULL);
	}
	else{
		if (value == tree->num){
			return(tree);
		}
		if (value < tree->num){
			return(buscar(value, tree->left));
		}
		else{
			return(buscar(value, tree->right));
		}
	}
}
		





int main (){
	int info, Q, k;
	Node *esq, *dir, *father;

	scanf("%i", &Q);

	for (int i = 0; i < Q; i++){
		scanf("%i %i", &k, &info);

		if (k == 1)
		{
			inserir(info, father);
		}

		if (k == 2){
            Node* x = buscar(info, father);
		      if (x == NULL){
		          printf("Data tidak ada");
		      }
		      else{
		          printf("%i", x->alt);
		      }
		        }
	}

	return 0;
}