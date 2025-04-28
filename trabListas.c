//na remove turma:
while(gpAtual){
    
    removeGrupo(gpAtual->num);
    gpAtual = grAtual->prox;
}

void removeGrupo(int codturma, int cod){
    Turma *turma = &listaTurmas[codturma];
    Grupo *atual = turma->primeiroGrupo;
    Grupo *ant = atual;

    
    while(atual){
        if(atual->num == cod){
            turma->primeiroGrupo = atual->prox;
            free(atual);
            printf("Removido com sucesso");
            return;
        }
        if(atual->prox == NULL && atual->num == cod){
            ant->prox = NULL;
            free(atual);
        }
        else if(atual->num == cod){
            ant->prox = atual->prox
            free(atual);
        }
        
        ant = atual;
        atual = atual->prox;
        

    }
    printf("Removido com sucesso");
}
