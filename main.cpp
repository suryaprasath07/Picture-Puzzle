#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <string>
using namespace std;

const int x=getmaxwidth()/2;
const int y=getmaxheight()/2;

struct node
{
    string image;
    int num;
    int lx;
    int ly;
    int hx;
    int hy;
    struct node *left=nullptr;
    struct node *right=nullptr;
    struct node *up=nullptr;
    struct node *down=nullptr;
    struct node *prev=nullptr;
    struct node *start=nullptr;
    
    void insert(std::string &a)
    {
        if (start == nullptr)
        {
            createNewNode(a, x - 200, y - 200, x - 100, y - 100);
        }
        else
        {
            struct node *p = createNewNode(a);

            if ((prev->num) % 3 == 1)
            {
                insertAsLeftChild(p);
            }
            else if ((prev->num) % 3 == 2)
            {
                insertAsMiddleChild(p);
            }
            else
            {
                insertAsRightChild(p);
            }
        }
    }

    void createNewNode(std::string &a, int lx, int ly, int hx, int hy)
    {
        unique_ptr<node> p = make_unique<node>();
        p->num = 1;
        strcpy(p->image, a);
        start = p;
        prev = p;
        p->lx = lx;
        p->ly = ly;
        p->hx = hx;
        p->hy = hy;
    }

    struct node *createNewNode(std::string &a)
    {
        unique_ptr<node> p = make_unique<node>();
        strcpy(p->image, a);
        p->num = prev->num + 1;
        return p;
    }

    void insertAsLeftChild(struct node *p)
    {
        p->left = prev;
        struct node *ptr = findInsertionPoint();
        connectNodes(ptr, p);
        prev = p;
        setCoordinates(p, x - 96, y - 200, x, y - 100, x - 96, y - 96, x, y + 4, x - 96, y + 8, x, y + 108);
    }

    void insertAsMiddleChild(struct node *p)
    {
        p->left = prev;
        struct node *ptr = findInsertionPoint();
        connectNodes(ptr, p);
        prev = p;
        setCoordinates(p, x + 4, y - 200, x + 100, y - 100, x + 4, y - 96, x + 100, y + 4, x + 4, y + 8, x + 100, y + 108);
    }

    void insertAsRightChild(struct node *p)
    {
        struct node *ptr = start;
        while (ptr->down != nullptr)
        {
            ptr = ptr->down;
        }
        p->up = ptr;
        ptr->down = p;
        prev = p;
        setCoordinates(p, x - 200, y - 96, x - 100, y + 4, x - 200, y + 8, x - 100, y + 108);
    }

    struct node *findInsertionPoint()
    {
        if (start->right != nullptr)
        {
            struct node *ptr = start->right;
            while (ptr->down != nullptr)
            {
                ptr = ptr->down;
            }
            return ptr;
        }
        return prev;
    }

    void connectNodes(struct node *parent, struct node *child)
    {
        parent->right = child;
        child->up = parent;
    }

    void setCoordinates(struct node *p, int lx1, int ly1, int hx1, int hy1, int lx2, int ly2, int hx2, int hy2, int lx3, int ly3, int hx3, int hy3)
    {
        if (p->num == 2)
        {
            p->lx = lx1;
            p->ly = ly1;
            p->hx = hx1;
            p->hy = hy1;
        }
        else if (p->num == 5)
        {
            p->lx = lx2;
            p->ly = ly2;
            p->hx = hx2;
            p->hy = hy2;
        }
        else
        {
            p->lx = lx3;
            p->ly = ly3;
            p->hx = hx3;
            p->hy = hy3;
        }
    }


    void display()
    {
        struct node *ptr = start;
        
        while (ptr != nullptr)
        {
            cout << "\n\nNODE : " << ptr->num;
            cout << "\nIMAGE : " << ptr->image;
            ptr = ptr->down;
        }

        if (start != nullptr)
        {
            ptr = start->right;
            while (ptr != nullptr)
            {
                cout << "\n\nNODE : " << ptr->num;
                cout << "\nIMAGE : " << ptr->image;
                ptr = ptr->down;
            }
            
            if (start->right != nullptr)
            {
                ptr = start->right->right;
                while (ptr != nullptr)
                {
                    cout << "\n\nNODE : " << ptr->num;
                    cout << "\nIMAGE : " << ptr->image;
                    ptr = ptr->down;
                }
            }
        }
    }

    node* get(int i)
    {
        struct node *ptr=start;
        while(ptr!=nullptr)
        {
            if(ptr->num==i)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down;
        while(ptr!=nullptr)
        {
            if(ptr->num==i)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down->down;
        while(ptr!=nullptr)
        {
            if(ptr->num==i)
                return ptr;
            ptr=ptr->right;
        }
    }
    node *getvoid()
    {
        struct node *ptr=start;
        while(ptr!=nullptr)
        {
            if(strcmpi(ptr->image,"9.jpg")==0)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down;
        while(ptr!=nullptr)
        {
            if(strcmpi(ptr->image,"9.jpg")==0)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down->down;
        while(ptr!=nullptr)
        {
            if(strcmpi(ptr->image,"9.jpg")==0)
                return ptr;
            ptr=ptr->right;
        }
    }
}Q,Q1;

void swapdata(node C, node* a, node* b)
{
    std::string temp;

    temp = a->image;
    a->image = b->image;
    b->image = temp;
}

POINT picdisplay(node C)
{
    node *p=C.get(1);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(2);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(3);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(4);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(5);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(6);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(7);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(8);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    p=C.get(9);
    readimagefile(p->image,p->lx,p->ly,p->hx,p->hy);
    while(true)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            POINT a;
            GetCursorPos(&a);
            return a;
        }
    }
}
int nodeequal(node A1,node A2)
{
    node *p1,*p2;
    
    p1=A1.start;
    p2=A2.start;
    int i=1;
    while(i!=4)
    {
        if(strcmpi(p1->image,p2->image)!=0)
            break;
        else
        {
            p1=p1->right;
            p2=p2->right;
        }
        if(p1==nullptr)
        {
            if(i==1)
            {
                p1=A1.start->down;
                p2=A2.start->down;
                i++;
            }
            else if(i==2)
            {
                p1=A1.start->down->down;
                p2=A2.start->down->down;
                i++;
            }
            else
                i++;
        }
    }
    if(i==4)
        return 1;
    else
        return 0;
}

void initializePuzzle(node &Q, node &Q1) {
    for (int j = 1; j <= 9; j++) {
        char a[30];
        itoa(j, a, 10);
        strcat(a, ".jpg");
        Q.insert(a);
    }

    int shuffle[] = {1, 2, 3, 4, 6, 5, 7, 8, 9};  // Adjust the shuffle order
    for (int i = 0; i < 9; i++) {
        struct node *p = Q.get(shuffle[i]);
        Q1.insert(p->image);
    }
}

void performPuzzle(node &Q, node &Q1) {
    initwindow(getmaxwidth(), getmaxheight(), "IMAGE PUZZLE");
    while (!nodeequal(Q, Q1)) {
        POINT s;
        s = picdisplay(Q1);
        node *p = Q1.getvoid();

        checkAndSwap(Q1, p->left, p, s);
        checkAndSwap(Q1, p->right, p, s);
        checkAndSwap(Q1, p->up, p, s);
        checkAndSwap(Q1, p->down, p, s);
    }
    closegraph();
}

void checkAndSwap(node &Q1, node* neighbor, node* p, POINT s) {
    if (neighbor != nullptr && isPointInBounds(s, neighbor->lx, neighbor->ly, neighbor->hx, neighbor->hy)) {
        swapdata(Q1, neighbor, p);
    }
}

bool isPointInBounds(POINT s, int lx, int ly, int hx, int hy) {
    return (s.x >= lx && s.x <= hx && s.y >= ly && s.y <= hy);
}

int main() {
    node Q, Q1;

    initializePuzzle(Q, Q1);
    performPuzzle(Q, Q1);

    if (nodeequal(Q, Q1)) {
        const char *message = "WOW! You finished the puzzle";
        for (int i = 0; i < strlen(message); i++) {
            cout << message[i];
            Sleep(500);
        }
    } else {
        cout << "You haven't solved the puzzle";
    }

    return 0;
}
