#include <stdio.h>
#include <stdlib.h>
#include <time.h>



  typedef struct no{
    int k,valor;
    struct no *prox;
    int ativo;
  }no;

 typedef struct{
   no *inicio;
   no *fim;

  }fila;

   fila* criar_fila(){
   fila *f;
   f = (fila*)malloc(sizeof(fila));
   if(f == NULL){
    printf("erro ao alocar a fila");
    exit(1);
  }
    f->inicio = NULL;
    f->fim = NULL;
    printf("fila criada");
   return f;
   }


   void inserir_na_fila(fila *f,int val){
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(novo==NULL){
        printf("erro na fila");
        exit(1);

    }
    novo->valor = val;
    novo->prox = NULL;
    if(f->fim!=NULL){
      f->fim->prox = novo;

    }else{
        f->inicio = novo;
    }
    f->fim = novo;



   }

  void remocao_na_fila(fila*f){
    if(f->inicio!=NULL){
      no *remocao;
      remocao = f->inicio;
      f->inicio = f->inicio->prox;
      if(f->inicio==NULL){
        f->fim =NULL;

      }
      remocao->ativo = 0;

        free(remocao);
    }
   else{
    printf("nao tem nada para remover");

   }
  }



 int consultar_fila(fila *f){
       no *novo;
       novo = f->inicio;
       int tam=0;
      while(novo != NULL){
        if(novo->ativo!=0){
         tam++;
        }
        novo = novo->prox;

       }
       return tam;



   }


   int lava_jato(int *binario,int n){
    int k=0;
    printf("informe o tamanho da sua fila");
    scanf("%d", &k);
  fila *fi;
  fi = criar_fila();

  int t=0,lavados=0;




     for(int i=0;i<n;i++){

        if(binario[i]==0){

            if(fi->inicio!=NULL){
                if(t==3){
                    remocao_na_fila(fi);

                    t=0;
                    lavados = lavados+1;
                       t++;
                }else{

                  t++;
            }
            }
        }else{

            if(t==3){
                remocao_na_fila(fi);
                lavados++;
                t=0;


                    inserir_na_fila(fi,1);
                    t++;


            }else if(consultar_fila(fi)!=k){

             inserir_na_fila(fi,1);


             t++;
            }else{
             t++;
            }

        }



     }



     free(fi);
  return lavados;




   }

  int main(){
      int n;


    printf("Digite o tamanho do vetor binario: ");
    scanf("%d", &n);


    int* vetorBinario = (int*)malloc(n * sizeof(int));

    if (vetorBinario == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return 0;
    }

    srand(time(NULL));
    printf("Vetor binário gerado:\n");

     for (int i = 0; i < n; i++) {
        vetorBinario[i] = rand() % 2;
        printf("%d ", vetorBinario[i]);
         }

       vetorBinario[n - 1] = 1;
       printf("1\n");



    int lavados = lava_jato(vetorBinario, n);
    free(vetorBinario);
    printf("lavados: %d", lavados);

 return 0;}

