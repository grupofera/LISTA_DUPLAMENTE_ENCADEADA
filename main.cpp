#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    //DEFINIDO O REQUISITO QUE REPRESENTARA
    //CADA ELEMENTO DA LISTA
    struct LISTA
    {
        int num;
        LISTA *prox;
        LISTA *ant;
    };

    //A LISTA ESTA VAZIA, LOGO,
    //O PONTEIRO INICIO TEM O VALOR NULL
    //O PONTEIRO INICIO CONTERA O ENDERECO
    //DO PRIMEIRO ELEMENTO DA LISTA
    LISTA *inicio = NULL;
    //O PONTEIRO FIM CONTERA O ENDERECO
    //DO ULTIMO ELEMENTO DA LISTA
    LISTA *fim = NULL;
    //O PONTEIRO AUX E O PONTEIRO AUXILIAR
    LISTA *aux;
    //APRESENTANDO O MENU DE OPCAO
    int op, numero, achou;
    do
    {
        system("CLS");
        cout<<"\nMENU DE OPCOES\n";
        cout<<"\n1 - Inserir na lista";
        cout<<"\n2 - Consultar a lista do inicio ao fim";
        cout<<"\n3 - Consultar a lista do fim ao inicio";
        cout<<"\n4 - Remover da lista";
        cout<<"\n5 - Esvaziar a lista";
        cout<<"\n6 - Sair";
        cout<<"\nDigite sua opcao: ";
        cin>>op;
        if(op < 1 || op > 6 ){
            cout<<"Opcao invalida! ";
        }
        if (op == 1){
            cout<<"Digite o n�mero a ser inserido no inicio da lista: ";
            LISTA *novo = new LISTA();
            cin>>novo->num;
            if (inicio == NULL){
                //A LISTA ESTACA VAZIA
                //E O ELEMENTO INSERIDO SERA
                //O PRIMEIRO E O ULTIMO
                novo->prox = NULL;
                novo->ant = NULL;
                inicio = novo;
                fim = novo;
            }
            else{
            	//A LISTA JA CONTEM ELEMENTOS
            	//E O NOVO ELEMENTO
            	//SERA INSERIDO NO INICIO DA LISTA
            	//RESPEITANDO A ORDENA��O CRESCENTE
            	aux = inicio;
            	while (aux != NULL && novo->num > aux->num){
                    aux = aux->prox;
            	}
            	if(aux == inicio){
                    //O NOVO NUMERO SERA INSERIDO
                    //E MENOR QUE TODOS OS NUMEROS DA LISTA
                    // LOGO SERA INCERIDO NO INICIO
                    novo->prox = inicio;
                    novo->ant = NULL;
                    inicio->ant = novo;
                    inicio = novo;
            	}else if(aux == NULL){
                    //O NUMERO A SER INSERIDO � MAIOR QUE TODOS OS NUMEROS
                    fim->prox = novo;
                    novo->ant = fim;
                    fim = novo;
                    fim->prox = NULL;
            	}else{
            	    cout<<"mais um ";
                    // NOVO NUMERO INSERIDO ENTRE DOIS NUMEROS
                    novo->prox = aux;
                    aux->ant->prox = novo;
                    novo->ant = aux->ant;
                    aux->ant = novo;
            	}
            }
            cout<<"Numero inserido no inicio da lista!";
        }

        if (op == 2){
            if (inicio == NULL){
            	//A LISTA ESTA VAZIA
                cout<<"Lista vazia!";
            }
            else{
            	//A LISTA CONTEM ELEMENTOS E ESTES
            	//SERAO
            	//MOSTRADOS DO INICIO AO FIM
                cout<<"\nConsultando a lista do inicio ao fim\n";
                aux = inicio;
                while (aux != NULL){
                    cout<<aux->num<<" ";
                    aux = aux->prox;
                }
            }
        }

        if (op == 3){
            if (inicio = NULL){
            	//A LISTA ESTA VAZIA
                cout<<"Lista vazia!";
            }
            else{
            	//A LISTA CONTEM ELEMENTOS
            	//E ESTES SERAO
            	//MOSTRADOS O FIM AO INICIO
                cout<<"\nConsultando a lista do fim ao in�cio\n";
                aux = fim;
                while (aux != NULL){
                    cout<<aux->num<<" ";
                    aux = aux->ant;
                }
            }
        }

        if (op == 4){
            if (inicio == NULL){
            	//A LISTA ESTA VAZIA
                cout<<"Lista vazia!";
            }
            else{
            	//A LISTA CONTEM ELEMENTOS
            	//E O ELEMENTO A SET
            	//REMOVIDO DEVE SER DIGITADO
                cout<<"\nDigite o elemento a ser removido:";
                cin>>numero;
                //TODAS AS OCORRENCIAS DA LISTA
                //IGUAIS AO NUMEROS DIGITADO
                //SERAM REMOVIDOS
                aux = inicio;
                achou = 0;
                while (aux != NULL)
                {
                	if (aux->num == numero){
                        //O NUMERO DIGITADO
                        //FOI ENCONTRADO NA LISTA
                        //E SERA REMOVIDO
                        achou = achou +1;
                        if (aux == inicio){
                            //O NUMERO A SER REMOVIDO
                            //E O PRIMEIRO DA LISTA
                            inicio = aux->prox;
                            if(inicio != NULL){
                                inicio->ant = NULL;
                            }
                            delete(aux);
                            aux = inicio;
                        }
                        else if (aux == fim){
                            //O NUMERO A SER
                            //REMOVIDO
                            //E O ULTIMO DA LISTA
                            fim = fim->ant;
                            fim->prox = NULL;
                            delete(aux);
                            aux = NULL;
                        }
                        else{
                            aux->ant->prox = aux->prox;
                            aux->prox->ant = aux->ant;
                            LISTA *aux2;
                            aux2 = aux->prox;
                            delete(aux);
                            aux = aux2;
                        }
                    }
                    else{
                        aux = aux->prox;
                    }
                }
                if (achou == 0)
                    cout<<"Numero n�o encontrado";
                else if (achou ==1)
                    cout<<"Numero removido 1 vez";
                else
                    cout<<"Numero removido "<<achou<<" vezes";
            }
        }
        if (op == 5){
            if (inicio == NULL){
                //A LISTA ESTA VAZIA
                cout<<"Lista vazia!";
            }
            else{
                //A LISTA SERA ESVAZIADA
                aux = inicio;
                while (aux != NULL)
                {
                    inicio = inicio->prox;
                    delete(aux);
                    aux = inicio;
                }
                cout<<"Lista esvaziada";
            }
        }
        getch();
    }while (op != 7);
}
