#include <cstdio>
#include <string.h>

using namespace std;
#define MAX_N 100000

//ノードを表す構造体
struct node {
    int val;
    node *lch;
    node *rch;
};

//数xを追加
node *insert(node *p, int x){
    if (p == NULL){
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else{
        if(x < p->val){
            p->lch = insert(p->lch,x);
        }
        else{
            p->rch = insert(p->rch,x);
        }
        return p;
    }
}

//数xを検索
bool find(node *p, int x){
    if (p = NULL){
        return false;
    }
    else if(x = p->val){
        return true;
    }
    else if(x < p->val){
        return find(p->lch, x);
    }
    else return find(p->rch, x);
}

//数xを削除
node *remove(node *p, int x){
    if (p == NULL){
        return NULL;
    }
    else if(x < p->val){
        p->lch = remove(p->lch,x);
    }
    else if(x > p->val){
        p->rch = remove(p->rch,x);
    }
    else if(p->lch == NULL){
        node *q = p->rch;
        delete p;
        return q;
    }
    else if(p->lch->rch == NULL){
        node *q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    }
    else{
    node *q;
    for (q = p->lch; q->rch->rch != NULL; q = q->rch);
    node *r = q->rch;
    r->lch = p->lch;
    r->rch = p->rch;
    delete p;
    return r;
    }
    return p;
}

int main(){
    printf("aaa\n");
    printf("aaa\n");
    node *root = NULL;   //初期化
    root = insert(root,1);   //ノードを追加
    printf("%d\n",find(root, 1));
    return 0;
}