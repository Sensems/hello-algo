/*
 * File: PrintUtil.hpp
 * Created Time: 2021-12-19
 * Author: Krahets (krahets@163.com), msk397 (machangxinq@gmail.com)
 */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "ListNode.hpp"
#include "TreeNode.hpp"

class PrintUtil {
    public:
        /**
         * @brief Find an element in a vector
         * 
         * @tparam T 
         * @param vec 
         * @param ele 
         * @return int 
         */
        template <typename T>
        static int vecFind(const vector<T>& vec, T ele) {
            int j = INT_MAX;
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == ele) {
                    j = i;
                }
            }
            return j;
        }

        /**
         * @brief Concatenate a vector with a delim
         * 
         * @tparam T 
         * @param delim 
         * @param vec 
         * @return string 
         */
        template <typename T>
        static string strJoin(const string& delim, const T& vec) {
            ostringstream s;
            for (const auto& i : vec) {
                if (&i != &vec[0]) {
                    s << delim;
                }
                s << i;
            }
            return s.str();
        }

        /**
         * @brief Repeat a string for n times
         * 
         * @param str 
         * @param n 
         * @return string 
         */
        static string strRepeat(string str, int n) {
            ostringstream os;
            for(int i = 0; i < n; i++)
                os << str;
            return os.str();
        }

        /**
         * @brief Print an Array
         * 
         * @tparam T 
         * @tparam n 
         */
        template<typename T>
        static void printArray(T* arr, int n)
        {
            cout << "[";
            for (size_t i = 0; i < n - 1; i++) {
                cout << arr[i] << ", ";
            }
            cout << arr[n - 1] << "]" << '\n';
        }

        /**
         * @brief Get the Vector String object
         * 
         * @tparam T 
         * @param list 
         * @return string 
         */
        template <typename T>
        static string getVectorString(vector<T> &list) {
            return "[" + strJoin(", ", list) + "]";
        }

        /**
         * @brief Print a vector
         * 
         * @tparam T 
         * @param list 
         */
        template <typename T>
        static void printVector(vector<T> list) {
            cout << getVectorString(list) << '\n';
        }

        /**
         * @brief Print a vector matrix
         * 
         * @tparam T 
         * @param matrix 
         */
        template <typename T>
        static void printVectorMatrix(vector<vector<T>> &matrix) {
            cout << "[" << '\n';
            for (vector<T> &list : matrix)
                cout << "  " + getVectorString(list) + "," << '\n';
            cout << "]" << '\n';
        }

        /**
         * @brief Print a linked list
         * 
         * @param head 
         */
        static void printLinkedList(ListNode *head) {
            vector<int> list;
            while (head != nullptr) {
                list.push_back(head->val);
                head = head->next;
            }
            
            cout << strJoin(" -> ", list) << '\n';
        }

        /**
         * @brief This tree printer is borrowed from TECHIE DELIGHT
         *        https://www.techiedelight.com/c-program-print-binary-tree/
         */
        struct Trunk {
            Trunk *prev;
            string str;
            Trunk(Trunk *prev, string str) {
                this->prev = prev;
                this->str = str;
            }
        };
        
        /**
         * @brief Helper function to print branches of the binary tree
         * 
         * @param p 
         */
        static void showTrunks(Trunk *p) {
            if (p == nullptr) {
                return;
            }
        
            showTrunks(p->prev);
            cout << p->str;
        }

        /**
         * @brief The interface of the tree printer
         * 
         * @param root 
         */
        static void printTree(TreeNode *root) {
            printTree(root, nullptr, false);
        }

        /**
         * @brief Print a binary tree
         * 
         * @param root 
         * @param prev 
         * @param isLeft 
         */
        static void printTree(TreeNode *root, Trunk *prev, bool isLeft) {
            if (root == nullptr) {
                return;
            }
        
            string prev_str = "    ";
            Trunk *trunk = new Trunk(prev, prev_str);
        
            printTree(root->right, trunk, true);
        
            if (!prev) {
                trunk->str = "———";
            }
            else if (isLeft) {
                trunk->str = "/———";
                prev_str = "   |";
            }
            else {
                trunk->str = "\\———";
                prev->str = prev_str;
            }
        
            showTrunks(trunk);
            cout << " " << root->val << endl;
        
            if (prev) {
                prev->str = prev_str;
            }
            trunk->str = "   |";
        
            printTree(root->left, trunk, false);
        }
    
        /**
         * @brief Print a stack
         * 
         * @tparam T 
         * @param stk
         */
        template <typename T>
        static void printStack(stack<T> stk) {
            // Reverse the input stack
            stack<T> tmp;
            while(!stk.empty()) {
                tmp.push(stk.top());
                stk.pop();
            }
            // Generate the string to print
            ostringstream s;
            bool flag = true;
            while(!tmp.empty()) {
                if (flag) {
                    s << tmp.top();
                    flag = false;
                }
                else s << ", " << tmp.top();
                tmp.pop();
            }
            cout << "[" + s.str() + "]" << '\n';
        }

        /**
         * @brief 
         * 
         * @tparam T 
         * @param queue 
         */
        template <typename T>
        static void printQueue(queue<T> queue)
        {
            // Generate the string to print
            ostringstream s;
            bool flag = true;
            while(!queue.empty()) {
                if (flag) {
                    s << queue.front();
                    flag = false;
                }
                else s << ", " << queue.front();
                queue.pop();
            }
            cout << "[" + s.str() + "]" << '\n';
        }

        template <typename T>
        static void printDeque(deque<T> deque) {
            // Generate the string to print
            ostringstream s;
            bool flag = true;
            while(!deque.empty()) {
                if (flag) {
                    s << deque.front();
                    flag = false;
                }
                else s << ", " << deque.front();
                deque.pop_front();
            }
            cout << "[" + s.str() + "]" << '\n';
        }

        /**
         * @brief Print a HashMap
         *
         * @tparam TKey
         * @tparam TValue
         * @param map
         */
        // 定义模板参数 TKey 和 TValue，用于指定键值对的类型
        template <typename TKey, typename TValue>
        static void printHashMap(unordered_map<TKey,TValue> map) {
            for (auto kv : map) {
                cout << kv.first << " -> " << kv.second << '\n';
            }
        }
};
