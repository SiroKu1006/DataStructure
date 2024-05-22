#include <iostream>
#include <string>
#include "bcd.h"
#include "linkedlist.cpp"
#include <chrono>
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

DoubleLinkedList<int> input_int(string in_){
    DoubleLinkedList<int> list;
    for (int i = 0; i < in_.size(); i++){
        list.addBack(in_[i] - '0');
    }
    return list;
};

DoubleLinkedList<int> int_adder(DoubleLinkedList<int> num1, DoubleLinkedList<int> num2){
    DoubleLinkedList<int> result;
    Node<int>* current1 = num1.getLast();
    Node<int>* current2 = num2.getLast();
    unsigned char carry = 0;
    while (current1 != nullptr || current2 != nullptr) {
        int sum;
        if (current1 != nullptr && current2 != nullptr) {
            sum = current1->getData() + current2->getData() + carry;
            current1 = current1->getPrev();
            current2 = current2->getPrev();
        } else if (current1 != nullptr) {
            sum = current1->getData() + carry;
            current1 = current1->getPrev();
        } else {
            sum = current2->getData() + carry;
            current2 = current2->getPrev();
        }
        result.addFront(sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) {
        result.addFront(carry);
    }
    return result;
};

DoubleLinkedList<int> int_subtract(DoubleLinkedList<int> num1, DoubleLinkedList<int> num2){
    DoubleLinkedList<int> result;
    Node<int>* current1 = num1.getLast();
    Node<int>* current2 = num2.getLast();
    unsigned char borrow = 0;
    while (current1 != nullptr || current2 != nullptr) {
        int diff;
        if (current1 != nullptr && current2 != nullptr) {
            diff = current1->getData() - current2->getData() - borrow;
            current1 = current1->getPrev();
            current2 = current2->getPrev();
        } else if (current1 != nullptr) {
            diff = current1->getData() - borrow;
            current1 = current1->getPrev();
        } else {
            diff = -current2->getData() - borrow;
            current2 = current2->getPrev();
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.addFront(diff);
    }
    if (borrow > 0) {
        throw invalid_argument("有負數");
    }
    return result;
};

int main() {
    int cas = 1;
    string in_ , num , type ;
    DoubleLinkedList<BCD64> num_ans;
    DoubleLinkedList<int> n_num ;
    // BCD64 result;
    // BCD64 num2();
    // result = num1.add(num2);
    // cout << result << endl;
    auto start = chrono::high_resolution_clock::now();
    if (cas == 0){
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
    }else if(cas == 1){
        while(cin >> num){
            if (num == "STOP") break;
            n_num = input_int(num);
            // num_ans.Print();
            while (cin >> in_){
                if (in_ == "=") break;
                if (in_ == "+" || in_ == "-" ){
                    type = in_;
                    continue;
                }
                if (type == "+"){
                    DoubleLinkedList<int> new_num = input_int(in_);
                    n_num = int_adder(n_num, new_num);
                }
                else if (type == "-"){
                    DoubleLinkedList<int> new_num = input_int(in_);
                    n_num = int_subtract(n_num, new_num);
                }
            }
            n_num.Print();
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto time_bg = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Use " << time_bg/1000.0 << "ms\n" ;
    return 0;
}