#include <stdio.h>
#include <assert.h>

struct tree{
    struct tree *left;
    struct tree *right;
    int data;
};

struct *build_tree(){
    strcut tree *root = calloc(1, sizeof(struct tree));
    assert(root);

    root->data = 1;
}


int main(){

}