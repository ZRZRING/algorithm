#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIME_LEN 9

struct TIME {
    char time[MAX_TIME_LEN];
    int h, m, s, cnt;
};

struct ORDER {
    struct TIME time;
    int id;
};

// Function to initialize TIME structure
void init_TIME(struct TIME* t, char* T) {
    strncpy(t->time, T, MAX_TIME_LEN);
    t->h = (t->time[0] - '0') * 10 + t->time[1] - '0';
    t->m = (t->time[3] - '0') * 10 + t->time[4] - '0';
    t->s = (t->time[6] - '0') * 10 + t->time[7] - '0';
    t->cnt = t->h * 3600 + t->m * 60 + t->s;
}

// Function to initialize ORDER structure
void init_ORDER(struct ORDER* o, struct TIME t, int d) {
    o->time = t;
    o->id = d;
}

// Function to create a new node for linked list
struct Node {
    int val;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to add node to the end of the list
void appendNode(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE* fp = fopen("dict.dic", "r");
    int n, m;
    fscanf(fp, "%d %d", &n, &m);

    // Allocate memory for arrays
    char** id_str = (char**)malloc((n + m + 1) * sizeof(char*));
    for (int i = 0; i <= n + m; i++) {
        id_str[i] = (char*)malloc(100 * sizeof(char));
    }
    int* id = (int*)malloc((n + m + 1) * sizeof(int));
    int* cost = (int*)malloc((n + 1) * sizeof(int));
    int* cap = (int*)malloc((n + 1) * sizeof(int));
    int* tot = (int*)malloc((n + 1) * sizeof(int));
    int* time = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        fscanf(fp, "%s", id_str[i]);
        id[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        fscanf(fp, "%d", &cost[i]);
    }
    for (int i = 1; i <= n; i++) {
        fscanf(fp, "%d", &cap[i]);
    }
    struct TIME start_time;
    init_TIME(&start_time, "07:00:00");
    for (int i = 1; i <= n; i++) {
        time[i] = start_time.cnt;
    }

    int W1, W2;
    fscanf(fp, "%d %d", &W1, &W2);

    struct Node** cb = (struct Node**)malloc((n + m + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++) {
        cb[i] = createNode(i);
    }

    char buffer[1000];
    fgets(buffer, sizeof(buffer), fp);  // Consume newline
    for (int i = 1; i <= m; i++) {
        fgets(buffer, sizeof(buffer), fp);
        char* token = strtok(buffer, " ");
        int CB = n + i;
        strcpy(id_str[CB], token);
        id[CB] = CB;

        while ((token = strtok(NULL, " \n")) != NULL) {
            appendNode(&cb[CB], id[token[0] - 'A' + 1]);
        }
    }
    fclose(fp);

    int k, wait_cnt = 0, lock = 0;
    scanf("%d", &k);
    int* wait = (int*)malloc((k + 1) * sizeof(int));
    struct ORDER* order = (struct ORDER*)malloc((k + 1) * sizeof(struct ORDER));
    struct TIME* ans = (struct TIME*)malloc((k + 1) * sizeof(struct TIME));
    struct Node** q = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    memset(q, 0, (n + 1) * sizeof(struct Node*));

    for (int i = 1; i <= k; i++) {
        char t[MAX_TIME_LEN], S[100];
        scanf("%s %s", t, S);
        struct TIME T;
        init_TIME(&T, t);
        init_ORDER(&order[i], T, id[S[0] - 'A' + 1]);
    }

    for (int i = 25200, j = 1; i < 86400; i++) {
        for (int j = 1; j <= n; j++) {
            if (tot[j] == cap[j]) {
                time[j] = i;
                continue;
            }
            if (i - time[j] == cost[j]) {
                time[j] = i;
                if (q[j] == NULL) {
                    tot[j]++;
                    continue;
                }
                int x = q[j]->val;
                struct Node* temp = q[j];
                q[j] = q[j]->next;
                free(temp);
                wait[x]--;
                if (wait[x] == 0) {
                    ans[x] = start_time;
                    wait_cnt--;
                }
            }
        }
        if (j <= k && i == order[j].time.cnt) {
            if (lock) {
                strcpy(ans[j].time, "Fail");
                j++;
                continue;
            }
            struct Node* curr = cb[order[j].id];
            while (curr != NULL) {
                int food = curr->val;
                if (tot[food]) {
                    tot[food]--;
                } else {
                    appendNode(&q[food], j);
                    wait[j]++;
                }
                curr = curr->next;
            }
            if (!wait[j]) {
                ans[j] = start_time;
            } else {
                wait_cnt++;
            }
            j++;
        }
        if (wait_cnt > W1) {
            lock = 1;
        }
        if (wait_cnt < W2) {
            lock = 0;
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%s\n", ans[i].time);
    }

    // Free allocated memory
    for (int i = 0; i <= n + m; i++) {
        free(id_str[i]);
    }
    free(id_str);
    free(id);
    free(cost);
    free(cap);
    free(tot);
    free(time);
    for (int i = 1; i <= n + m; i++) {
        freeList(cb[i]);
    }
    free(cb);
    free(wait);
    free(order);
    free(ans);

    return 0;
}
