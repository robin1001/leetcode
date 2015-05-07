#include <iostream>
#include <vector>
#include <assert.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *createNodeList(std::vector<int> &arr) {
    assert(arr.size() > 0);
    ListNode *l = NULL, *p = NULL;
    for (int i = 0; i < arr.size(); i++) {
        if (l == NULL) {
            p = l = new ListNode(arr[i]);
        } else {
            p->next = new ListNode(arr[i]);
            p = p->next;
        }
    }
    return l;
}

void printlNodeList(ListNode* l) {
    while (l != NULL) {
        std::cout << l->val << "->";
        l = l->next;
    }
    std::cout << std::endl;
}

bool equalNodeList(ListNode* l1, ListNode* l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->val != l2->val)
            return false;
        l1 = l1->next;       
        l2 = l2->next;
    }
    if (l1 != NULL || l2 != NULL) 
        return false;
    return true;
}

ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
    assert(l1 != NULL);
    assert(l2 != NULL);
    ListNode *l3 = NULL, *p3 = NULL; 
    bool full = false;
    while (l1 != NULL && l2 != NULL) {
        int val = l1->val + l2->val; 
        if (full) {
            val++;
            full = false;
        }
        if (val >= 10) {
           val = val - 10; 
           full = true;
        }
        if (l3 == NULL) {
            l3 = p3 = new ListNode(val);

        } else {
            p3->next = new ListNode(val);                
            p3 = p3->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode *l = (l1 != NULL? l1 : l2);
    while (l != NULL) {
        int val = l->val;
        if (full) {
            val++;
            full = false;
        }
        if (val >= 10) {
            val = val - 10; 
            full = true;
        }
        p3->next = new ListNode(val);                
        p3 = p3->next;
        l = l->next;
        
    }
    if (full) {
        p3->next = new ListNode(1);                
        p3 = p3->next;
    }
    return l3;
}

void testAddTwoNodeList() {
    std::vector<int> arr1(2, 0), arr2(3, 0), arr3(3,0);
    arr1[0] = 1, arr1[1] = 1;
    //arr1[0] = 1, arr1[1] = 1, arr1[2] =  5;
    arr2[0] = 1, arr2[1] = 1, arr2[2] =  5;
    arr3[0] = 2, arr3[1] = 2, arr3[2] =  5;
    //arr3[0] = 2, arr3[1] = 2, arr3[2] =  0, arr3[3] = 1;
    ListNode *l1 = createNodeList(arr1);
    ListNode *l2 = createNodeList(arr2);
    ListNode *l3 = createNodeList(arr3);
    printlNodeList(l3);
    ListNode *l = addTwoNumbers(l1, l2);
    printlNodeList(l);
    assert(equalNodeList(l, l3));
}

int main() {
    testAddTwoNodeList();
    return 0;
}
