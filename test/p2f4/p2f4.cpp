// ============================================================================
// Partie II – Feuille 4
// ----------------------------------------------------------------------------
// IMPORTANT : NE PAS EXÉCUTER. Faire UNIQUEMENT la trace mémoire (Google Sheet « Mémoire »).
// Ces fragments de code servent de support à la représentation mémoire.
// ============================================================================

#include <cstdlib>

// ============================================================================
// main1 — Modification indirecte
// ============================================================================
void ModifyValue(int* p)
{
    *p = 20;
}

void main1()
{
    int x = 10;
    int* ptr = &x;
    ModifyValue(ptr);
    x += 5;
}

// ============================================================================
// main2 — Utilisation après libération
// ============================================================================
void main2()
{
    int* p = (int*)malloc(sizeof(int));
    *p = 30;
    free(p);
    int i = 5;
    *p = 50;
}

// ============================================================================
// main3 — Retour d’adresse locale
// ============================================================================
int* CreateLocal()
{
    int temp = 100;
    return &temp;
}

void main3()
{
    int* p;
    p = CreateLocal();
    *p = 10;
}

// ============================================================================
// main4 — Retour d’adresse allouée dynamiquement
// ============================================================================
int* CreateHeap()
{
    int* p = (int*)malloc(sizeof(int));
    *p = 100;
    return p;
}

void main4()
{
    int* p;
    p = CreateHeap();
    *p = 10;

    int* q;
    free(p);
    q = (int*)malloc(sizeof(int));
}

// ============================================================================
// main5 — Pointeur non initialisé
// ============================================================================
void main5()
{
    {
        int i = 0;
        int j = 0;
    }

    int* p;
    *p = 123;
}

// ============================================================================
// main6 — Échange de valeurs via pointeurs
// ============================================================================
void main6()
{
    int* p1 = (int*)malloc(sizeof(int));
    int* p2 = (int*)malloc(sizeof(int));

    *p1 = 25;
    *p2 = 50;

    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

    free(p1);
    free(p2);
    p1 = p2 = nullptr;
}