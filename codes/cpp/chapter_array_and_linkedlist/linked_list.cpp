/*
 * File: linked_list.cpp
 * Created Time: 2022-11-25
 * Author: Krahets (krahets@163.com)
 */

#include "../include/include.hpp"

/* 在链表的结点 n0 之后插入结点 P */
void insert(ListNode* n0, ListNode* P) {
    ListNode* n1 = n0->next;
    n0->next = P;
    P->next = n1;
}

/* 删除链表的结点 n0 之后的首个结点 */
void remove(ListNode* n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode* P = n0->next;
    ListNode* n1 = P->next;
    n0->next = n1;
    // 释放内存
    delete P;
}

/* 访问链表中索引为 index 的结点 */
ListNode* access(ListNode* head, int index) {
    for (int i = 0; i < index; i++) {
        head = head->next;
        if (head == nullptr)
            return nullptr;
    }
    return head;
}

/* 在链表中查找值为 target 的首个结点 */
int find(ListNode* head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}


/* Driver Code */
int main() {
    /* 初始化链表 */
    // 初始化各个结点 
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(4);
    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << "初始化的链表为" << endl;
    PrintUtil::printLinkedList(n0);

    /* 插入结点 */
    insert(n0, new ListNode(0));
    cout << "插入结点后的链表为" << endl;
    PrintUtil::printLinkedList(n0);

    /* 删除结点 */
    remove(n0);
    cout << "删除结点后的链表为" << endl;
    PrintUtil::printLinkedList(n0);

    /* 访问结点 */
    ListNode* node = access(n0, 3);
    cout << "链表中索引 3 处的结点的值 = " << node->val << endl;

    /* 查找结点 */
    int index = find(n0, 2);
    cout << "链表中值为 2 的结点的索引 = " << index << endl;

    return 0;
}
