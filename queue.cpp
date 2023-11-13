#include<iostream>
#include<cstring>
using namespace std;

static int STT = 0;


class phieuNopTien{
    private:
        int stt;
        string hoten;
        string sotien;
    public:
        phieuNopTien(){
            stt = 0;
            hoten = "";
            sotien = "";
        }
        phieuNopTien(string name, string money){
            stt = ++STT;
            hoten = name;
            sotien = money;
        }
        void input(){
            stt = ++STT;
            cout << "\nHo va ten: ";
            getline(cin, hoten);
            cout << "\nSo tien nop: ";
            getline(cin, sotien);
        }
        void output(){
            cout << "\nStt: " << stt;
            cout << "\nHo va ten: " << hoten;
            cout << "\nSo tien dong: " << sotien;
        }
};


struct node{
    phieuNopTien data;
    node* next;
    node* prev;
};
class queue{
    private:
        node* top;
        node* bot;
        int size;
    public:
        queue();
        bool isEmpty();
		void enqueue();
        int length();
		phieuNopTien peek();
		phieuNopTien dequeue();
		void print();
};
queue::queue(){
    top=bot=NULL;
    size=0;
}

phieuNopTien queue::peek(){
    if(top!=NULL) return bot->data;
}


bool queue::isEmpty(){
    return (top==NULL);
}

int queue::length(){
    return size;
}
void queue::enqueue(){
    phieuNopTien x;
    x.input();
    node* newNode=new node;
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(top==NULL) top=bot=newNode;
    else {
        bot->next=newNode;
        newNode->prev=bot;
        bot=newNode;
    }
    ++size;
}

phieuNopTien queue::dequeue(){
	if(this->isEmpty()) cout << "\nHang doi rong";
    else {
        node* temp = top;
        phieuNopTien x = temp->data;
        top = top->next;
        if (top != NULL) top->prev = NULL;
        else  bot = NULL;
        delete temp;
        --size;
        return x;
    }
}

void queue::print(){
    node* temp=top;
    while(temp!=NULL){
        temp->data.output();
        temp=temp->next;
    }
}

void menu(){

    queue q;
    phieuNopTien last;
    int count = 0;


    menu:
    int ch;
    do{
        cout << "\n-------------MENU------------";
        cout << "\n1. Them 1 sinh vien";
        cout << "\n2. Duyet 1 sinh vien";
        cout << "\n3. Co bao nhieu sinh vien da nop duoc tien";
        cout << "\n4. Co bao nhieu sinh vien dang doi nop tien";
        cout << "\n5. Thong tin sinh vien moi nop tien";
        cout << "\n6. Thoat" << endl;
        cin >> ch;
        cin.ignore();
    } while(ch<1 || ch>5);

    

    switch(ch){
        case 1:
            cout << "\nNhap phieu: ";
            q.enqueue();
            break;
        case 2:
            if(q.isEmpty()) cout << "\nHang doi rong";
            else{
                last = q.dequeue();
                ++count;
            }
            break;
        case 3:
            cout << "\nCo " << count << " sinh vien da nop duoc tien";
            break;
        case 4:
            cout << "\nCo " << q.length() << " sinh vien dang doi nop tien";
            break;
        case 5:
            cout << "\nThong tin sinh vien vua nop tien:";
            last.output();
            break;
        case 6:
            return;
    }

    int rch;
    do{
        cout << "\n1. Tiep tuc";
        cout << "\n2. Thoat" << endl;
        cin >> rch;
    } while(rch!=1 && rch!=2);

    switch(rch){
        case 1:
            goto menu;
            break;
        case 2:
            return;
    }
}

int main(){
    menu();
    cout << endl;
    system("pause");
    return 0;
}