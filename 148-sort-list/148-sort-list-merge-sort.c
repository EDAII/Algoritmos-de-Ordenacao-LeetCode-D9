/**
 * Definição da estrutura para uma lista encadeada (fornecida pelo LeetCode):
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// --- Estruturas e Funções Auxiliares ---

// Função para juntar (merge) duas listas ordenadas
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    // Usamos um nó "dummy" (fantoche) para simplificar o início da lista
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    
    // Enquanto ambas as listas tiverem elementos
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // Anexa o restante da lista que não terminou
    if (l1 != NULL) {
        current->next = l1;
    } else if (l2 != NULL) {
        current->next = l2;
    }
    
    // O início da lista mesclada está em dummy.next
    return dummy.next;
}

// --- Função Principal da Solução ---

struct ListNode* sortList(struct ListNode* head) {
    // 1. Caso Base (Dividir)
    // Se a lista está vazia ou tem apenas um nó, ela já está ordenada.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // 2. Encontrar o Meio (Dividir)
    // Usamos a técnica do "ponteiro rápido e lento" (fast and slow)
    struct ListNode* slow = head;
    struct ListNode* fast = head->next; // Começa uma posição à frente
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // 'slow' agora está no nó do meio (ou um pouco antes do meio, se par)
    // 'head' é o início da primeira metade.
    // 'head2' (slow->next) será o início da segunda metade.
    
    struct ListNode* head2 = slow->next;
    
    // Quebra a lista em duas:
    slow->next = NULL; 
    
    // 3. Conquistar (Chamadas Recursivas)
    struct ListNode* l1 = sortList(head);  // Ordena a primeira metade
    struct ListNode* l2 = sortList(head2); // Ordena a segunda metade
    
    // 4. Combinar (Merge)
    return merge(l1, l2);
}