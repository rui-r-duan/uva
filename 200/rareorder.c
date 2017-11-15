#include <stdio.h>

#define MAX_WORD_LENGTH 20

char g_wordone[MAX_WORD_LENGTH + 1];               /* need be static? */
char g_wordtwo[MAX_WORD_LENGTH + 1];

typedef struct _Node {
    char c;                      /* char */
    struct _Node* next;
    struct _Node* prev;
} Node;

#define MAX_NODES 27
Node g_node_list[MAX_NODES];      /* initialized to zero for each member */

char* read_word(char* buf, int max_word_length)
{
    char c;
    int i;
    for (i = 0; i < max_word_length && (c = getchar()) != EOF && c != '\n'; ) {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return buf;
}

Node* find_node(Node node_list[], int character)
{
    int i;
    for (i = 0; i < MAX_NODES; ++i) {
        if (node_list[i].c == character) {
            return &node_list[i];
        }
    }
    return NULL;
}

Node* find_first_empty_node(Node node_list[])
{
    int i;
    for (i = 0; i < MAX_NODES; ++i) {
        if (node_list[i].c == 0) {
            return &node_list[i];
        }
    }
}

Node* find_first_alphabet_node(Node node_list[])
{
    int i;
    for (i = 0; i < MAX_NODES; ++i) {
        if (node_list[i].prev == 0) {
            return &node_list[i];
        }
    }
}

void update_rule_list(char* first, char* second)
{
    char a;
    char b;
    Node* na;
    Node* nb;
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        a = first[i];
        b = second[i];
        if (a == '\0' || b == '\0') {
            break;
        } else if (a == b) {
            continue;
        }

        /* only when a != b can we obtain a valid rule */
        na = find_node(g_node_list, a);
        nb = find_node(g_node_list, b);
        if (na == NULL) {
            na = find_first_empty_node(g_node_list);
            na->c = a;
        }
        if (nb == NULL) {
            nb = find_first_empty_node(g_node_list);
            nb->c = b;
        }

        /* insert na before nb */
        if (nb->prev != NULL) {
            nb->prev->next = na;
            na->prev = nb->prev;
        }
        na->next = nb;
        nb->prev = na;
        break;
    }
}

void print_rule_in_alphabetical_order(Node* head)
{
    Node* p;
    for (p = head; p != NULL; p = p->next) {
        putchar(p->c);
    }
}

int main(int argc, char* argv[])
{
    char* first = g_wordone;
    char* second = g_wordtwo;
    char* tmp = first;

    (void)read_word(first, MAX_WORD_LENGTH);
    while (1) {
        (void)read_word(second, MAX_WORD_LENGTH);

        /* the only one exit */
        if (second[0] == '#') {
            break;
        }

        update_rule_list(first, second);

        /* swap the two buffers, then in the next round, update second */
        tmp = first;
        first = second;
        second = tmp;
    }

    print_rule_in_alphabetical_order(find_first_alphabet_node(g_node_list));

    return 0;
}
