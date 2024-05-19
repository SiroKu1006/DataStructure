#include <iostream>
#include <string>
#include "bcd.h"
#include "linkedlist.cpp"
using namespace std;

DoubleLinkedList<BCD64> input(string in_){
    DoubleLinkedList<BCD64> list;
    while (in_.size() > 16) {
        string part = in_.substr(in_.size() - 16);
        in_ = in_.substr(0, in_.size() - 16);

        BCD64 num(part);
        list.addBack(num);
    }
    if (!in_.empty()) {
        BCD64 num(in_);
        list.addBack(num);
    }
    return list;
};

DoubleLinkedList<BCD64> adder(DoubleLinkedList<BCD64> num1, DoubleLinkedList<BCD64> num2){
    DoubleLinkedList<BCD64> result;
    Node<BCD64>* current1 = num1.getFirst();
    Node<BCD64>* current2 = num2.getFirst();
    unsigned char carry = 0;
    while (current1 != nullptr || current2 != nullptr) {
        BCD64 sum;
        if (current1 != nullptr && current2 != nullptr) {
            sum = current1->getData().add(current2->getData(),&carry,carry);
            current1 = current1->getNext();
            current2 = current2->getNext();
        } else if (current1 != nullptr) {
            sum = current1->getData().add(BCD64(carry), &carry);
            current1 = current1->getNext();
        } else {
            sum = current2->getData().add(BCD64(carry), &carry);
            current2 = current2->getNext();
        }
        result.addBack(sum);
    }
    if (carry > 0) {
        result.addBack(BCD64(carry));
    }
    // result.Print();
    return result;
};

DoubleLinkedList<BCD64> subtract(DoubleLinkedList<BCD64> num1, DoubleLinkedList<BCD64> num2){
    DoubleLinkedList<BCD64> result;
    Node<BCD64>* current1 = num1.getFirst();
    Node<BCD64>* current2 = num2.getFirst();
    unsigned char borrow = 0;
    while (current1 != nullptr || current2 != nullptr) {
        BCD64 diff;
        if (current1 != nullptr && current2 != nullptr) {
            diff = current1->getData().subtract(current2->getData(), &borrow, borrow);
            current1 = current1->getNext();
            current2 = current2->getNext();
        } else if (current1 != nullptr) {
            diff = current1->getData().subtract(BCD64(borrow), &borrow);
            current1 = current1->getNext();
        } else {
            diff = current2->getData().subtract(BCD64(borrow), &borrow);
            current2 = current2->getNext();
        }
        result.addBack(diff);
    }
    // result.Print();
    return result;
};

void output(DoubleLinkedList<BCD64> num){
    Node<BCD64>* current = num.getFirst();
    string result = "";
    int count = 0;
    while (current != nullptr) {
        result = current->getData().toString() + result;
        current = current->getNext();
    }
    while (result[count] == '0'){
        count++;
    }
    for (count; count < result.size(); count++){
        cout << result[count];
    }
    cout << "\n";
}

int main() {
    string in_ , num , type ;
    DoubleLinkedList<BCD64> num_ans;
    // BCD64 result;
    // BCD64 num1(in_);
    // BCD64 num2();
    // result = num1.add(num2);
    // cout << result << endl;
    while(cin >> num){
        if (num == "STOP") break;
        num_ans = input(num);
        // num_ans.Print();
        while (cin >> in_){
            if (in_ == "=") break;
            if (in_ == "+" || in_ == "-" ){
                type = in_;
                continue;
            }
            if (type == "+"){
                DoubleLinkedList<BCD64> new_num = input(in_);
                num_ans = adder(num_ans, new_num);
            }
            else if (type == "-"){
                DoubleLinkedList<BCD64> new_num = input(in_);
                num_ans = subtract(num_ans, new_num);
            }
        }
        output(num_ans);
    }
    return 0;
}