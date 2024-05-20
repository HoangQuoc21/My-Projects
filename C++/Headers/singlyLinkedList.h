#include <iostream>
using namespace std;
//I. SINGLY LINKED LIST
struct SNODE {
    int key;
    SNODE* pNext;
};

struct list {
    SNODE* pHead;
    SNODE* pTail;
};

bool isEmpty(list* L){
    return ((L->pHead == NULL) && (L->pTail == NULL));
}

SNODE* createNode(int data){
    SNODE* newNode = new SNODE;
    if (newNode){
        newNode->key = data;
        newNode->pNext = NULL;
        return newNode;
    }
    return NULL;
}

list* createList(SNODE* pNode){
    list* newList = new list;
    if (newList && pNode){
        newList->pHead = newList->pTail = pNode;
        return newList;
    } 
    return NULL;
}

bool addHead(list* &L, int data){
    SNODE* newNode = createNode(data);
    if (newNode){
        if (isEmpty(L))
            L->pHead = L->pTail = newNode;
        else{
            newNode->pNext = L->pHead;
            L->pHead = newNode;
        }
        return true;
    }
    return false;
}

bool addTail(list* &L, int data){
    SNODE* newNode = createNode(data);
    if (newNode){
        if (isEmpty(L))
            L->pHead = L->pTail = newNode;
        else{
            L->pTail->pNext = newNode;
            L->pTail = newNode;
        }
        return true;
    }
    return false;
}

void removeHead(list* &L){
    SNODE* deleteNode = L->pHead;
    if (L->pHead == L->pTail)
        L->pHead = L->pTail = NULL;
    else{
        L->pHead = L->pHead->pNext;
    }
    delete deleteNode;
}

void removeTail(list* &L){
    SNODE* deleteNode = L->pTail;
    if(L->pHead == L->pTail)
        L->pHead = L->pTail = NULL;
    else{
        SNODE* tempNode = L->pHead;
        while(tempNode->pNext != deleteNode)
            tempNode = tempNode->pNext;
        tempNode->pNext = NULL;
        L->pTail = tempNode;
    }
    delete deleteNode;
}

void removeAll(list* &L){
    SNODE* tempNode1;
    SNODE* tempNode2 = L->pHead;
    while(tempNode2){
        tempNode1 = tempNode2;
        tempNode2 = tempNode2->pNext;
        delete tempNode1;
    }
    L->pHead = L->pTail = NULL;
}

int countVal(list *L, int val){
    int count = 0;
    SNODE* tempNode = L->pHead;
    while(tempNode){
        if(tempNode->key == val)
            count++;
        tempNode = tempNode->pNext;
    }
    return count;
}

int countElements(list* L){
    int count = 0;
    if(!isEmpty(L)){
        SNODE* tempNode = L->pHead;
        while(tempNode){
            count++;
            tempNode = tempNode->pNext;
        }
    }
    return count;
}

void removeBefore(list* L, int val){
    if(!isEmpty(L)){
        if (L->pHead->pNext->key == val)
            removeHead(L);
        SNODE* tempNode = L->pHead;
        while(tempNode && tempNode->pNext && tempNode->pNext->pNext){
            //tempNode -> deleteNode -> valNode
            if (tempNode->pNext->pNext->key == val){
                SNODE* deleteNode = tempNode->pNext;
                tempNode->pNext = tempNode->pNext->pNext;
                delete deleteNode;
            }
            tempNode = tempNode->pNext;
        }
        if (countElements(L) == 2 && countVal(L, val) == 2)
            removeHead(L);
    }
}

void removeAfter(list* L, int val){
    if(!isEmpty(L)){
        SNODE* tempNode = L->pHead;
        while(tempNode && tempNode->pNext){
            if (tempNode->key == val && tempNode->pNext == L->pTail)
                removeTail(L);
            //tempNode -> deleteNode
            else if(tempNode->key == val){
                SNODE* deleteNode = tempNode->pNext;
                tempNode->pNext = deleteNode->pNext;
                delete deleteNode;
            }
            tempNode = tempNode->pNext;
        }
    }
}

//QUY ƯỚC: vị trí (index) trong danh sách liên kết bắt đầu từ 0;
bool checkPos(list* L, int pos){
    if (!isEmpty(L))
        return (pos >= 0 && (pos < countElements(L)));
    return false;
}

bool addPos(list* &L, int data, int pos){
    if (pos == 1)
        return addHead(L, data);
    else if (pos == countElements(L))
        return addTail(L, data);
    else{
        //thêm Node sau 1 Node
        int curIndex = 1;
        SNODE* tempNode = L->pHead;
        while(curIndex < pos ){
            tempNode = tempNode->pNext;
            curIndex++;
        }
        SNODE* addNode = createNode(data);
        if(addNode){
            addNode->pNext = tempNode->pNext;
            tempNode->pNext = addNode;
            return true;
        }
    }
    return false;
}

void removePos(list* &L, int pos){
    if(pos == 1)
        removeHead(L);
    else if(pos == countElements(L))
        removeTail(L);
    else{
        //Xóa Node sau 1 Node
        int curIndex = 1;
        SNODE* tempNode = L->pHead;
        while(curIndex < pos -1 ){
            tempNode = tempNode->pNext;
            curIndex++;
        }
        SNODE* deleteNode = tempNode->pNext;
        tempNode->pNext = deleteNode->pNext;
        delete deleteNode;
    }
}

bool addBefore(list* L, int data, int val){
    if(!isEmpty(L) && (countVal(L,val) != 0)){
        SNODE* tempNode = L->pHead;
        while(tempNode->pNext){
            //tempNode -> addNode -> valNode
            if(tempNode->pNext->key == val){
                SNODE* addNode = createNode(data);
                addNode->pNext = tempNode->pNext;
                tempNode->pNext = addNode;
                tempNode = tempNode->pNext->pNext;
            }
            else
                tempNode = tempNode->pNext;
        }
        if (L->pHead->key == val)
            return addHead(L, data);
        return true;
    }
    return false;
}

bool addAfter(list* L, int data, int val){
    if(!isEmpty(L) && (countVal(L,val) != 0)){
        SNODE* tempNode = L->pHead;
        while(tempNode){
            //tempNode -> addNode 
            if(tempNode->key == val){
                SNODE* addNode = createNode(data);
                addNode->pNext = tempNode->pNext;
                tempNode->pNext = addNode;
                tempNode = tempNode->pNext->pNext;
            }
            else
                tempNode = tempNode->pNext;
        }
        if (L->pTail->key == val)
            return addTail(L, data);
        return true;
    }
    return false;
}

void printList(list* L){
    SNODE* tempNode = L->pHead;
    while(tempNode){
        if(tempNode->pNext)
            cout << tempNode->key << " -> ";
        else
            cout << tempNode->key;
        tempNode = tempNode->pNext;
    }
}

list* reverseList(list* L){
    if(!isEmpty(L)){
        SNODE* prevNode = NULL;
        SNODE* currNode = L->pHead;
        SNODE* nextNode = NULL;
        while(currNode){
            nextNode = currNode->pNext;
            currNode->pNext = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        L->pTail = L->pHead;
        L->pHead = prevNode;
    }
    return L;
}

void removeDuplicate(list* &L){
    SNODE* tempNode1 = L->pHead, *tempNode2, *dupNode;
    while(tempNode1 && tempNode1->pNext){
        tempNode2 = tempNode1;
        while(tempNode2->pNext){
            if(tempNode1->key == tempNode2->pNext->key){
                if (tempNode2->pNext == L->pTail)
                    removeTail(L);
                else{
                    dupNode = tempNode2->pNext;
                    tempNode2->pNext = tempNode2->pNext->pNext;
                    delete dupNode;
                } 
            }
            else
                tempNode2 = tempNode2->pNext;
        }
        tempNode1 = tempNode1->pNext;
    }
}

bool removeElement(list* &L, int key){
    if (countVal(L, key) == 1 && countElements(L) == 1){
        removeHead(L);
        return true;
    }
    if(!isEmpty(L) && (countVal(L, key) != 0)){
        SNODE* tempNode = L->pHead;
        while(tempNode && tempNode->pNext && tempNode->pNext->pNext){
            if (tempNode->pNext->key == key){
                SNODE* deleteNode = tempNode->pNext;
                tempNode->pNext = tempNode->pNext->pNext;
                delete deleteNode;
            }
            else 
                tempNode = tempNode->pNext;
        }
        if(L->pHead->key == key)
            removeHead(L);
        if(L->pTail->key == key)
            removeTail(L);
        return true;
    }
    return false;
}