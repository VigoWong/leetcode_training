//
// Created by Vigo Wong on 21/4/20.
//


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *stepOne(struct ListNode *head) {
    if (head != NULL) {
        head = head->next;
    }
    return head;
}

struct ListNode *stepTwo(struct ListNode *head) {
    if (head != NULL) {
        head = head->next;
        if (head != NULL)head = head->next;
    }
    return head;
}

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fir = head;
    struct ListNode *sed = head;
    while (sed != NULL && sed->next != NULL) {
        fir = stepOne(fir);
        sed = stepTwo(sed);
    }
    return fir;
}

int main(int argc, char const *argv[]) {

    return 0;
}
