#pragma ONCE
#include "queue.h"


//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila

void queue_append (queue_t **queue, queue_t *elem) {
    int i = 0;
    if (queue == NULL) {
        printf("FILA INEXISTENTE");
        return;
    }
    while (queue[i]->next != NULL) {
        i++;
    }

}