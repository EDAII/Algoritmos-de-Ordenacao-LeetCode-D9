/**
 * Definição da estrutura para uma lista encadeada (fornecida pelo LeetCode):
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// --- 1. Função Auxiliar: Juntar DUAS listas ordenadas ---
// (Esta é a solução para o LeetCode 21, e a mesma lógica de 'merge' do LeetCode 148)
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // Casos base: se uma das listas for nula, retorne a outra
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    // Nó "dummy" (fantoche) para simplificar
    struct ListNode dummy;
    struct ListNode* tail = &dummy; // 'tail' é o último nó da nossa lista mesclada

    // Percorre as duas listas
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; // Avança o 'tail'
    }

    // Anexa o restante da lista que não terminou
    // (Apenas um desses 'if' será verdadeiro)
    if (l1 != NULL) {
        tail->next = l1;
    } else if (l2 != NULL) {
        tail->next = l2;
    }

    return dummy.next; // O início real está em dummy.next
}

// --- 2. Função Principal: Juntar K listas (usando recursão) ---

// Função recursiva auxiliar para dividir o array de listas
struct ListNode* mergeKListsRecursive(struct ListNode** lists, int start, int end) {
    // --- Casos Base (Dividir) ---
    
    // Se o 'start' ultrapassar o 'end', não há listas neste intervalo
    if (start > end) {
        return NULL;
    }
    // Se 'start' e 'end' são iguais, há apenas UMA lista.
    // Retorne essa lista, pois ela já está "mesclada" (consigo mesma).
    if (start == end) {
        return lists[start];
    }
    
    // --- Etapa de Divisão ---
    // Encontra o meio do array de listas
    int mid = start + (end - start) / 2;
    
    // --- Etapa de Conquista (Recursão) ---
    // Mescla a primeira metade (de 'start' até 'mid')
    struct ListNode* leftHalf = mergeKListsRecursive(lists, start, mid);
    // Mescla a segunda metade (de 'mid + 1' até 'end')
    struct ListNode* rightHalf = mergeKListsRecursive(lists, mid + 1, end);
    
    // --- Etapa de Combinação ---
    // Combina as duas metades resultantes
    return mergeTwoLists(leftHalf, rightHalf);
}

// Função principal que o LeetCode chama
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // Inicia a recursão cobrindo todo o array de listas (de 0 a listsSize - 1)
    return mergeKListsRecursive(lists, 0, listsSize - 1);
}