//
// Created by Andrey Neupokoev on 05.06.2022.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

namespace list
{
    template<typename T>
    class List
    {
    private:
        template<typename V>
        class Node
        {
        public:
            Node* pointerNext;
            T data;
            Node(V data = V(), Node* pointerNext = nullptr)
            {
                this->data = data;
                this->pointerNext = pointerNext;
            }
        };

        int sizeList;
        Node<T>* head;

    public:

        List()
        {
            sizeList = 0;
            head = nullptr;
        }

        ~List()
        {
            clearList();
        }

        void pushBack(T data)
        {
            if (head != nullptr)
            {

                Node<T>* c = this->head;
                while (c->pointerNext != nullptr)
                {
                    c = c->pointerNext;
                }
                c->pointerNext = new Node<T>(data);
                sizeList++;
                return;
            }

            head = new Node<T>(data);
            sizeList++;
        }

        void pushFront(T data)
        {
            head = new Node<T>(data, head);
            sizeList++;
        }

        void insert(T data, int index)
        {
            if (index == 0)
            {
                pushFront(data);
                return;
            }

            Node<T>* p = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->pointerNext;
            }

            p->pointerNext = new Node<T>(data, p->pointerNext);
            sizeList++;
        }

        void delFirst()
        {
            Node<T>* t = head;
            head = head->pointerNext;
            delete t;
            sizeList--;
        }

        void removeAt(int index)
        {
            if (index == 0)
            {
                delFirst();
                return;
            }

            Node<T>* p = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->pointerNext;
            }

            Node<T>* del = p->pointerNext;
            p->pointerNext = del->pointerNext;

            delete del;
            sizeList--;
        }

        void delLast()
        {
            removeAt(sizeList - 1);
        }

        int getSize()
        {
            return sizeList;
        }
        void clearList()
        {
            while (sizeList)
            {
                delFirst();
            }
        }
        T& operator[](const int index)
        {
            Node<T>* c = this->head;
            int count = 0;

            while (c != nullptr)
            {
                if (count == index)
                {
                    return c->data;
                }
                c = c->pointerNext;
                count++;
            }
        }
    };
}


#endif //LIST_LIST_H