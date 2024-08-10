#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node (element)
typedef struct Element {
    int data;
    struct Element *right;
    struct Element *left;
} Element;

// Function to create a new tree node
Element *novi_element(int data) {
    Element *novi = malloc(sizeof(Element));
    if (novi == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    novi->data = data;
    novi->right = NULL;
    novi->left = NULL;
    return novi;
}

// Function to add a node iteratively
Element *dodaj_element_iterativno(Element *root, Element *novi) {
    if (root == NULL) {
        return novi;
    }
    Element *tmp = root;
    while (1) {
        if (novi->data < tmp->data) {
            if (tmp->left == NULL) {
                tmp->left = novi;
                return root;
            } else {
                tmp = tmp->left;
            }
        } else {
            if (tmp->right == NULL) {
                tmp->right = novi;
                return root;
            } else {
                tmp = tmp->right;
            }
        }
    }
}

// Function to add a node recursively
Element *dodaj_element_rekurzivno(Element *root, Element *novi) {
    if (root == NULL) {
        return novi;
    }
    if (novi->data < root->data) {
        root->left = dodaj_element_rekurzivno(root->left, novi);
    } else {
        root->right = dodaj_element_rekurzivno(root->right, novi);
    }
    return root;
}

// Preorder tree traversal
void ispisi_stablo_preorder(Element *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    ispisi_stablo_preorder(root->left);
    ispisi_stablo_preorder(root->right);
}

// Inorder tree traversal
void ispisi_stablo_inorder(Element *root) {
    if (root == NULL) {
        return;
    }
    ispisi_stablo_inorder(root->left);
    printf("%d ", root->data);
    ispisi_stablo_inorder(root->right);
}

// Postorder tree traversal
void ispisi_stablo_postorder(Element *root) {
    if (root == NULL) {
        return;
    }
    ispisi_stablo_postorder(root->left);
    ispisi_stablo_postorder(root->right);
    printf("%d ", root->data);
}

// Function to delete the entire tree
Element *obrisi_celo_stablo(Element *root) {
    if (root != NULL) {
        obrisi_celo_stablo(root->left);
        obrisi_celo_stablo(root->right);
        free(root);
    }
    return NULL;
}

// Function to find a node iteratively
Element *pronadji_element_iterativno(Element *root, int data) {
    while (root != NULL) {
        if (root->data == data) {
            return root;
        }
        if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// Function to find a node recursively
Element *pronadji_element_rekurzivno(Element *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return pronadji_element_rekurzivno(root->left, data);
    } else {
        return pronadji_element_rekurzivno(root->right, data);
    }
}

// Function to find the largest node
Element *najveci_element(Element *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to find the smallest node
Element *najmanji_element(Element *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to calculate the depth of the tree
int dubina_stabla(Element *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_depth = dubina_stabla(root->left);
        int right_depth = dubina_stabla(root->right);

        if (left_depth > right_depth) {
            return (left_depth + 1);
        } else {
            return (right_depth + 1);
        }
    }
}

// Function to delete a node from the tree
Element *obrisi_element(Element *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = obrisi_element(root->left, data);
    } else if (data > root->data) {
        root->right = obrisi_element(root->right, data);
    } else {
        if (root->left == NULL) {
            Element *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Element *temp = root->left;
            free(root);
            return temp;
        }
        Element *temp = najmanji_element(root->right);
        root->data = temp->data;
        root->right = obrisi_element(root->right, temp->data);
    }
    return root;
}

int main() {
    Element *root = NULL;
    Element *tmp = NULL;
    int command;
    int data;

    do {
        scanf("%d", &command);
        switch (command) {
        case 0:
            break;
        case 1:
            printf("----------------------------\n");
            ispisi_stablo_preorder(root);
            printf("\n----------------------------\n");
            break;
        case 2:
            printf("----------------------------\n");
            ispisi_stablo_inorder(root);
            printf("\n----------------------------\n");
            break;
        case 3:
            printf("----------------------------\n");
            ispisi_stablo_postorder(root);
            printf("\n----------------------------\n");
            break;
        case 4:
            root = obrisi_celo_stablo(root);
            break;
        case 5:
            scanf("%d", &data);
            root = dodaj_element_iterativno(root, novi_element(data));
            break;
        case 6:
            scanf("%d", &data);
            root = dodaj_element_rekurzivno(root, novi_element(data));
            break;
        case 7:
            scanf("%d", &data);
            tmp = pronadji_element_iterativno(root, data);
            if (tmp != NULL)
                printf("Pronadjen element: %d\n", tmp->data);
            else
                printf("Element ne postoji\n");
            break;
        case 8:
            scanf("%d", &data);
            tmp = pronadji_element_rekurzivno(root, data);
            if (tmp != NULL)
                printf("Pronadjen element: %d\n", tmp->data);
            else
                printf("Element ne postoji\n");
            break;
        case 9:
            tmp = najveci_element(root);
            if (tmp != NULL)
                printf("Najveci element: %d\n", tmp->data);
            else
                printf("Prazno stablo\n");
            break;
        case 10:
            tmp = najmanji_element(root);
            if (tmp != NULL)
                printf("Najmanji element: %d\n", tmp->data);
            else
                printf("Prazno stablo\n");
            break;
        case 11:
            scanf("%d", &data);
            root = obrisi_element(root, data);
            break;
        case 12:
            printf("Dubina stabla: %d\n", dubina_stabla(root));
            break;
        default:
            printf("Pogresna komanda!\n"
                   "Komande su:\n"
                   "1: Ispisuje stablo - preorder\n"
                   "2: Ispisuje stablo - inorder\n"
                   "3: Ispisuje stablo - postorder\n"
                   "4: Brise celo stablo\n"
                   "5: Dodavanje u stablo iterativno\n"
                   "6: Dodavanje u stablo rekurzivno\n"
                   "7: Pronalazenje elementa u stablu iterativno\n"
                   "8: Pronalazenje elementa u stablu rekurzivno\n"
                   "9: Najveci element u stablu\n"
                   "10: Najmanji element u stablu\n"
                   "11: Brisanje elementa po vrednosti\n"
                   "12: Dubina stabla\n");
        }

    } while (command != 0);
    return 0;
}
