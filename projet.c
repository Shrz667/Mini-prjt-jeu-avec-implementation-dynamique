
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

typedef struct{
char name [20];
int num;
int age;
int score;
int total;
int wins;
int loses;
int seq;
int losst;
struct joueur *next;
}joueur;


 struct queue{
    joueur *head;
    joueur *tail;
    int size;
} 


typedef struct{
    joueur *head;
}Liste ;

typedef struct 
{
    joueur *j1;
    joueur *j2;
    int scoreJ1;
    int scoreJ2;
}partie;


int sommeChiffres(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int pgcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int chiffrePresent(int n, int d) {
    if (n == 0 && d == 0) return 1;
    while (n > 0) {
        if (n % 10 == d) return 1;
        n /= 10;
    }
    return 0;
}


//FILE ========================================== 
void initFile(struct queue *f) {
    f->head = NULL;
     f->tail = NULL;
   // f->size = 0;
}

int empty(struct queue *f) {
    if (f->head == NULL)return 1; 
}

void enq(struct queue *f, joueur *j) {
    j->next = NULL;
    if (fempty(f)){
        f->head = j;
         f->tail = j;}
    else {
        f->tail->next = j;
        f->tail = j;
    }
    // f->size++;
}

joueur* deq(struct queue *f) {
    if (empty(f)) return NULL;
    joueur *j = f->head;
    f->head = j->next;
    if (!f->head) f->tail = NULL;
    j->next = NULL;
    f->size--;
    return j;
}

//LISTE========================================== 

// void initListe(Liste *l) {
//     l->head = NULL;
// }

void ajouterListe(Liste *l, joueur *j) {
    j->next = l->head;
    l->head = j;
}



void afficherFile(struct queue *f) {
    
    joueur *p = f->head;
    while (p) {
        printf("[%s]", p->name);
        p = p->next;
    }
    printf("\n");
}

void afficherListe(Liste *l) {
    
    joueur *p = l->head;
    while (p) {
        printf("[%s]", p->name);
        p = p->next;
    }
    printf("\n");
}

joueur* Partie1(joueur *j1, joueur *j2, int numPartie) {
    j1->score = j2->score = 0;

    printf(" partie numero %d", numPartie);
    printf("%s VS %s\n", j1->name, j2->name);
    int tours = 0;
    while (abs(j1->score - j2->score) < 3 && tours < 12) {
        int v1 = rand() % 100000 + 1; //generation du nombre de j1
        int v2 = rand() % 100000 + 1;// generation du nombre de j2

        if (sommeChiffres(v1) % 5 == 0) j1->score++;
        if (sommeChiffres(v2) % 5 == 0) j2->score++;

        tours++;
    }

    printf("Score final : %s=%d | %s=%d\n",j1->name, j1->score, j2->name, j2->score);

    if (j1->score > j2->score) 
    {printf ("le gagnant est %s ", j1->name);
        return j1;}else{
    if (j2->score > j1->score) {
        printf ("le gagnant est %s ", j2->name);
    return j2;}else{
    return NULL; // égalité
}


 }

}
joueur* Partie2(joueur *j1, joueur *j2, int numPartie) {
    j1->score = 0;
    j2->score = 0;

    printf("partie numero %d", numPartie);
    printf("%s VS %s\n", j1->name, j2->name);
    int tours = 0;
    while (abs(j1->score - j2->score) < 3 && tours < 16) {
        int a = rand() % 900 + 100;
        int b = rand() % 900 + 100;

        int g = pgcd(a, b);
        int temp = g;
        bool ok = true;

        while (temp > 0 && !ok) {
            int d = temp % 10;
            if (chiffrePresent(a, d) || chiffrePresent(b, d))
                ok = false;
            temp /= 10;
        }

        if (ok) j1->score++;
        else j2->score++;

        tours++;
    }

    printf("Score final : %s=%d | %s=%d\n",
           j1->nom, j1->scorePartie,
           j2->nom, j2->scorePartie);

    if (j1->scorePartie > j2->scorePartie) return j1;
    if (j2->scorePartie > j1->scorePartie) return j2;
    return NULL;
}







int main() {
    printf("hello");
    return 0;
}