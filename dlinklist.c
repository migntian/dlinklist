#include <stdio.h>
#include"dlinklist.h"
void dlinklist_init(dlinklist **head)
{
    if(head == NULL)
    {
        return;
    }
    *head = dcreat(0);
}
dlinklist *dcreat(dlinktype value)
{
    dlinklist *newnode =(dlinklist *) malloc(sizeof(dlinklist));
    newnode->next = newnode;
    newnode->prev = newnode;
    newnode->data = value;
    return newnode;
}
void dlinklist_print(dlinklist *head)
{
    if(head == NULL)
    {
        return;//非法输入
    }
    else
    {
        dlinklist *cur1 = head->next;
        dlinklist *cur2 = head->prev;
        while(cur1 != head)
        {
            printf("[%c|%p] ",cur1->data,cur1);
            cur1 = cur1->next;
        }
        printf("\n");
        while(cur2 != head)
        {
            printf("[%c|%p] ",cur2->data,cur2);
            cur2 = cur2->prev;
        }
        printf("\n");
        return;
    }
}
void dlinklist_pushback(dlinklist *head,dlinktype value)
{
    if(head == NULL)
    {
        return;//非法输入
    }
    else
    {
        dlinklist *cur = dcreat(value);
        dlinklist *cur2=head->prev;
        cur2->next = cur;
        cur->prev = cur2;
        head->prev = cur;
        cur->next = head;
        return;

    }
}
void dlinklist_popback(dlinklist *head)
{
    if(head == NULL)
    {
        return;//非法输入

    }
    if(head->next == head)
    {
        return;
    }
    else
    {
        dlinklist *cur1 = head->prev;
        cur1->prev->next = head;
        head->prev = cur1->prev;
        free(cur1);
    }
}
void dlinklist_pushfront(dlinklist *head,dlinktype value)
{
    if(head == NULL)
    {
        return;//非法输入
    }
    else
    {
        dlinklist *cur = head->next;
        dlinklist *new = dcreat(value);
        new->next = cur;
        cur->prev = new;
        new->prev = head;
        head->next = new;
    }
}

void dlinklist_popfront(dlinklist *head)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == head)
    {
        return;
    }
    else
    {
        dlinklist *cur = head->next;
        head->next = cur->next;
        cur->next->prev = head;
        free(cur);
    }
}
dlinklist * dlinklist_find(dlinklist *head,dlinktype value)
{
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        dlinklist *cur = head->next;
        while(cur != head)
        {
            if(cur->data==value)
            {
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }
}


void dlinklist_pushleft(dlinklist *head,dlinklist *pos,dlinktype value)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        dlinklist *cur1 = pos->prev;
        dlinklist *cur2 = dcreat(value);
        cur1->next = cur2;
        cur2->prev = cur1;
        cur2->next = pos;
        pos->prev = cur2;

    }
}
void dlinklist_pushright(dlinklist *head,dlinklist *pos,dlinktype value)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        dlinklist *cur1 = pos->next;
        dlinklist *cur2 = dcreat(value);
        pos->next = cur2;
        cur2->prev = pos;
        cur1->prev = cur2;
        cur2->next = cur1;
    }
}
void dlinklist_erase(dlinklist *head,dlinklist *pos)
{
    if(head == NULL)
    {
        return;
    }
    dlinklist *cur1 = pos->prev;
    dlinklist *cur2 = pos->next;
    cur1->next = cur2;
    cur2->prev = cur1;
    free(pos);

}
void dlinklist_remove(dlinklist *head,dlinktype value)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == head)
    {
        return;
    }
    else
    {
        dlinklist *pos = dlinklist_find(head,value);
        dlinklist_erase(head,pos);

    }
}
void dlinklist_removeall(dlinklist *head,dlinktype value)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == head)
    {
        return;
    }
    else
    {
        dlinklist *cur = head->next;
        while(cur!=head)
        {
            dlinklist *pos = dlinklist_find(head,value);
            if(pos == NULL)
            {
                return;
            }
            dlinklist_erase(head,pos);
            cur = cur->next;
        }
    }
}
size_t dlinklist_size(dlinklist *head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        size_t count = 0;
        dlinklist *cur = head->next;
        while(cur != head)
        {
            count++;
            cur = cur->next;
        }
        return count;
    }
}

int dlinklist_isempty(dlinklist *head)
{
    if(head == NULL)
    {
        return -1;
    }
    else
    {
        if(head->next == head)
        {
            return 0;
        }
        return 1;

    }
}
/////////////////////////
//测试
///////////////////////////
void test_dlinklist_pushback()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    printf("\n");
}


void test_dlinklist_popback()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    printf("尾删一个节点\n");
    dlinklist_popback(head);
    dlinklist_print(head);

}

void test_dlinklist_pushfront()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("头插四个节点\n");
    dlinklist_pushfront(head,'a');
    dlinklist_pushfront(head,'b');
    dlinklist_pushfront(head,'c');
    dlinklist_pushfront(head,'d');
    dlinklist_print(head);

}

void test_dlinklist_popfront()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    printf("头删一个节点");
    dlinklist_popfront(head);
    dlinklist_print(head);

}
void test_dlinklist_find()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    dlinklist *pos=dlinklist_find(head,'c');
    printf("查找c的位置\n");
    printf("[%c|%p]\n",pos->data,pos);

}

void test_dlinklist_pushleft()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    printf("在b的前面插入一个x\n");
    dlinklist_pushleft(head,dlinklist_find(head,'b'),'x');
    dlinklist_print(head);

}
void test_dlinklist_pushright()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    printf("在b的后面插入一个x\n");
    dlinklist_pushright(head,dlinklist_find(head,'b'),'x');
    dlinklist_print(head);
}
void test_dlinklist_erase()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    printf("删除第二个节点\n");
    dlinklist_erase(head,dlinklist_find(head,'b'));
    dlinklist_print(head);


}
void test_dlinklist_remove()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_remove(head,'c');
    dlinklist_print(head);

}

void test_dlinklist_removeall()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    dlinklist_removeall(head,'b');
    dlinklist_print(head);
}

void test_dlinklist_size()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'a');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'c');
    dlinklist_pushback(head,'d');
    dlinklist_print(head);
    size_t i = dlinklist_size(head);
    printf("%u",i);

}
void test_dlinklist_isempty()
{
    HEADER;
    dlinklist *head;
    dlinklist_init(&head);
    printf("尾插四个节点\n");
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'b');
    dlinklist_pushback(head,'b');
    dlinklist_print(head);
    printf("判断是否为空，空返回0，非空返回1\n");
    int i = dlinklist_isempty(head);
    printf("%d\n",i);

}
int main()
{
    test_dlinklist_pushback();
    test_dlinklist_popback();
    test_dlinklist_pushfront();
    test_dlinklist_popfront();
    test_dlinklist_find();
    test_dlinklist_pushleft();
    test_dlinklist_pushright();
    test_dlinklist_erase();
    test_dlinklist_remove();
    test_dlinklist_removeall();
    test_dlinklist_size();  
    test_dlinklist_isempty();
    return 0;
}
