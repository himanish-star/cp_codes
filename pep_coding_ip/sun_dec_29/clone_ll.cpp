// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

Node *copyList(Node *head);

void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res, Node *cloned_addr,
                Node *generated_addr) {

    if (generated_addr == cloned_addr) return false;

    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data) return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;
    Node *generated_addr = NULL;
    /*reading input stuff*/
    cin >> T;

    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
            }
            Node *tempB = head;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
            }

            // when both a is greater than N
            if (a <= n) tempA->arb = tempB;
        }
        /*read finished*/

        generated_addr = head;
        Node *res = copyList(head);

        Node *cloned_addr = res;

        cout << validation(head, res, cloned_addr, generated_addr) << endl;
    }

    return 0;
}
// } Driver Code Ends
/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    Node *chead=new Node(head->data);
    Node *ctrv=chead;
    Node *trv=head;
    
    vector<Node*> mems;
    while(trv) {
        Node *temp=trv;
        mems.push_back(trv);
        trv=trv->next;
        if(trv) {
            Node *newnode=new Node(trv->data);
            ctrv->next=newnode;
        } else {
            ctrv->next=NULL;
        }
        
        temp->next=ctrv;
        ctrv=ctrv->next;
    }
    
    ctrv=chead;
    for(int i=0;i<mems.size();i++) {
        trv=mems[i];
        if(trv->arb) {
            ctrv->arb=trv->arb->next;
        }
        ctrv=ctrv->next;
    }
    
    for(int i=0;i<mems.size()-1;i++) {
        mems[i]->next=mems[i+1];
    }
    
    ctrv=head;
    while(ctrv) {
        if(ctrv->arb) {
            // printf("(%d arb:%d)",ctrv->data,ctrv->arb->data);
        } else {
            // printf("(%d)",ctrv->data);
        }
        if(!ctrv->next->next)
            ctrv->next=NULL;
        ctrv=ctrv->next;
    }
    
    // cout<<endl;
    return chead;
}