#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    //Definindo o registro
    //que representara cada elemento da lista
    struct LISTA
    {
        int num;
        LISTA *prox;
        LISTA *ant;
    };

    //A lista esta vazia, logo,
    //o ponteiro inicio tem o valor NULL
    //o ponteiro inicio contera o endereco
    //do primeiro elemento da lista
    LISTA *inicio = NULL;
    //o primeiro fim contera o endereco
    //do ultimo elemento da lista
    LISTA *fim = NULL;
    //o ponteiro aux e o ponteiro auxiliar
    LISTA *aux;
    //apresentando o menu de opcao
    int op, numero, achou;
    do
    {
        system("CLS");
        cout<<"\nMENU DE OPCOES\n";
        cout<<"\n1 - Inserir no inicio da lista";
        cout<<"\n2 - Inserir no fim da lista";
        cout<<"\n3 - Consultar a lista do inicio ao fim";
        cout<<"\n4 - Consultar a lista do fim ao inicio";
        cout<<"\n5 - Remover da lista";
        cout<<"\n6 - Esvaziar a lista";
        cout<<"\n7 - Sair";
        cout<<"\nDigite sua opcao: ";
        cin>>op;
        if(op < 1 || op > 7 ){
            cout<<"Opcao invalida! ";
        }
        if (op == 1){
            cout<<"Digite o número a ser inserido no inicio da lista: ";
            LISTA *novo = new LISTA();
            cin>>novo->num;
            if (inicio == NULL){
                //a lista estaca vazia
                //e o elemento inserido sera
                //o primeiro e o ultimo
                inicio = novo;
                fim = novo;
                novo->prox = inicio;
                novo->ant = inicio;
            }
            else{
            	//a lista ja contem elementos
            	//e o novo elemento
            	//sera inserido no inicio da lista
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = fim;
                fim->prox = novo;
                inicio = novo;
            }
            cout<<"Numero inserido no inicio da lista!";
        }

        if (op == 2){
            cout<<"Digite o numero a ser inserido no fim da lista: ";
            LISTA *novo = new LISTA();
            cin>>novo->num;
            if (inicio == NULL){
                //a lista esta vazia
                //e o elemento inserido sera
                //o primeiro e o ultimo
                inicio = novo;
                fim = novo;
              	novo->prox = inicio;
                novo->ant = inicio;
            }
            else{
            	//a lista ja contem elementos e o
            	//novo elemento
            	//sera inseridono fim da lista
                fim->prox = novo;
                novo->ant = fim;
                fim = novo;
                fim-> prox = inicio;
                inicio->ant = fim;
            }
            cout<<"Numero inserido no fim da lista!";
        }

        if (op == 3){
            if (inicio == NULL){
            	//a lista esta vazia
                cout<<"Lista vazia!";
            }
            else{
            	//a lista contem elementos e estes
            	//serao
            	//mostrados do inicio ao fim
                cout<<"\nConsultando a lista do inicio ao fim\n";
                aux = inicio;
                do
                {
                    cout<<aux->num<<" ";
                    aux = aux-> prox;
                }while (aux != inicio);

            }
        }

        if (op == 4){
            if (inicio = NULL){
            	//a lista esta vazia
                cout<<"Lista vazia!";
            }
            else{
            	//a lista contem elementos
            	//e estes serao
            	//mostrados o fim ao inicio
                cout<<"\nConsultando a lista do fim ao início\n";
                aux = fim;
                do
                {
                    cout<<aux->num<<" ";
                    aux = aux->ant;
                } while (aux != fim);
            }
        }

        if (op ==5){
            if (inicio == NULL){
            	//a lista esta vazia
                cout<<"Lista vazia!";
            }
            else{
            	//a lista contem elementos
            	//e o elemento a set
            	//removido deve ser digitado
                cout<<"\nDigite o elemento a ser removido:";
                cin>>numero;
                //todas as ocorrencias da lista
                //iguais ao numeros digitado
                //seram removidos
                aux = inicio;
                achou = 0;
                //descobrindo a quantidade de
                //elementos da lista
                int quantidade = 0;
                aux = inicio;
                do{
                    quantidade = quantidade +1;
                    aux = aux->prox;
                } while (aux != inicio);
                int elemento =1;
                do
                {
                	//se a lista possui apenas um elemento
                    if (inicio == fim && inicio->num == numero){
                        inicio = NULL;
                        delete(inicio);
                        achou = achou +1;
                    }
                    else{
                        if (aux->num == numero){
                        	//o numero digitado
                        	//foi encontrado na lista
                        	//e sera removido
                            achou = achou +1;
                            if (aux == inicio){
                            	//o numero a ser removido
                            	//e o primeiro da lista
                                inicio = aux->prox;
                                inicio->ant = fim;
                                fim->prox = inicio;
                                delete(aux);
                                aux = inicio;
                            }
                            else if (aux == fim){
                            	//o numero a ser
                            	//removido
                            	//e o ultimo da lista
                                fim = fim->ant;
                                fim->prox = inicio;
                                inicio->ant = fim;
                                delete(aux);
                                aux = NULL;
                            }
                            else{
                                aux->ant->prox = aux->prox;
                                aux->prox->ant = aux->ant;
                                LISTA *aux2;
                                aux2 = aux;
                                aux = aux->prox;
                                delete(aux2);
                            }
                        }
                        else{
                            aux = aux->prox;
                        }
                    }
                    elemento = elemento +1;
                } while (elemento <= quantidade);
                if (achou == 0)
                    cout<<"Numero não encontrado";
                else if (achou ==1)
                    cout<<"Numero removido 1 vez";
                else
                    cout<<"Numero removido "<<achou<<" vezes";
            }
        }
        if (op == 6){
            if (inicio == NULL){
                //a lista esta vazia
                cout<<"Lista vazia!";
            }
            else{
                //a lista sera esvaziada
                aux = inicio;
                do
                {
                    inicio = inicio->prox;
                    delete(aux);
                    aux = inicio;
                } while (aux != fim);
                delete(aux);
                inicio = NULL;
                cout<<"Lista esvaziada";
            }
        }
        getch();
    }while (op != 7);
}
