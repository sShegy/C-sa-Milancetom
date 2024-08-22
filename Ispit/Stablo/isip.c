#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Osoba
{
    int data;
    struct Osoba *left;
    struct Osoba *right;
} Osoba;
Osoba *novi_element(int data)
{
    Osoba *nova = malloc(sizeof(Osoba));
    nova->data = data;

    nova->left = NULL;
    nova->right = NULL;

    return nova;
}
Osoba *dodaj_nova_iterativno(Osoba *root, Osoba *nova)
{
    if (root == NULL)
    {
        return nova;
    }
    else
    {
        while (1)
        {
            Osoba *tmp = root;
            if (nova->data < tmp->data)
            {
                if (tmp->left == NULL)
                {
                    tmp->left = nova->data;
                    return root;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
            else
            {
                if (tmp->right == NULL)
                {
                    tmp->right = nova->data;
                    return root;
                }
                else
                {
                    root = root->right;
                }
            }
        }
    }
}
Osoba *dodaj_nova_rek(Osoba *root, Osoba *nova)
{
    if (root == NULL)
    {
        return nova;
    }
    else
    {

        if (nova->data < root->data)
        {
            root->left = dodaj_nova_rek(root->left, nova);
        }
        else
        {
            root->right = dodaj_nova_rek(root->right, nova);
        }
        return root;
    }
}

void isipis(Osoba*root){
    if (root!=NULL)
    {
        isipis(root->left);
        printf("%d",root->data);
        isipis(root->right);
    }
    return;
}
Osoba*izbrisi(Osoba*root){
    if (root==NULL)
    {
        return NULL;
    }else{
        izbrisi(root->left);
        izbrisi(root->left);
        free(root);
    }
    return NULL;
}
int main()
{
    Osoba *root = NULL;
    int command;

    do
    {
        printf("Unesi comandu: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            break;
        case 1:
            isipis(root);
            break;
        default:
            break;
        }

    } while (command != 0);
}