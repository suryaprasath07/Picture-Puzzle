#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <string.h>
using namespace std;

const int x=getmaxwidth()/2;
const int y=getmaxheight()/2;

struct node
{
    char image[20];
    int num;
    int lx;
    int ly;
    int hx;
    int hy;
    struct node *left=NULL;
    struct node *right=NULL;
    struct node *up=NULL;
    struct node *down=NULL;
    struct node *prev=NULL;
    struct node *start=NULL;
    void insert(char a[])
    {
        if(start==NULL)
        {
            struct node *p=new node;
            p->num=1;
            strcpy(p->image,a);
            start=p;
            prev=p;
            p->lx=x-200;
            p->ly=y-200;
            p->hx=x-100;
            p->hy=y-100;
        }
        else
        {
            struct node *p=new node;
            strcpy(p->image,a);
            p->num=prev->num+1;
            if((prev->num)%3==1)
            {
                p->left=prev;
                if(start->right!=NULL)
                {
                    struct node *ptr=start->right;
                    while(ptr->down!=NULL)
                        ptr=ptr->down;
                    ptr->down=p;
                    p->up=ptr;
                }
                prev->right=p;
                prev=p;
                if(p->num==2)
                {
                    p->lx=x-96;
                    p->ly=y-200;
                    p->hx=x;
                    p->hy=y-100;
                }
                else if(p->num==5)
                {
                    p->lx=x-96;
                    p->ly=y-96;
                    p->hx=x;
                    p->hy=y+4;
                }
                else
                {
                    p->lx=x-96;
                    p->ly=y+8;
                    p->hx=x;
                    p->hy=y+108;
                }
            }
            else if((prev->num)%3==2)
            {
                p->left=prev;
                if((start->right)->right!=NULL)
                {
                    struct node *ptr=(start->right)->right;
                    while(ptr->down!=NULL)
                        ptr=ptr->down;
                    ptr->down=p;
                    p->up=ptr;
                }
                prev->right=p;
                prev=p;
                if(p->num==3)
                {
                    p->lx=x+4;
                    p->ly=y-200;
                    p->hx=x+100;
                    p->hy=y-100;
                }
                else if(p->num==6)
                {
                    p->lx=x+4;
                    p->ly=y-96;
                    p->hx=x+100;
                    p->hy=y+4;
                }
                else
                {
                    p->lx=x+4;
                    p->ly=y+8;
                    p->hx=x+100;
                    p->hy=y+108;
                }
            }
            else
            {
                struct node *ptr=start;
                while(ptr->down!=NULL)
                {
                    ptr=ptr->down;
                }
                p->up=ptr;
                ptr->down=p;
                prev=p;
                if(p->num==4)
                {
                    p->lx=x-200;
                    p->ly=y-96;
                    p->hx=x-100;
                    p->hy=y+4;
                }
                else
                {
                    p->lx=x-200;
                    p->ly=y+8;
                    p->hx=x-100;
                    p->hy=y+108;
                }
            }
        }
    }
    void display()
    {
        struct node *ptr=start;
        while(ptr!=NULL)
        {
            cout<<"\n\nNODE : "<<ptr->num;
            cout<<"\nIMAGE :"<<ptr->image;
            ptr=ptr->down;
        }
        ptr=start->right;
        while(ptr!=NULL)
        {
            cout<<"\n\nNODE : "<<ptr->num;
            cout<<"\nIMAGE :"<<ptr->image;
            ptr=ptr->down;
        }
        ptr=(start->right)->right;
        while(ptr!=NULL)
        {
            cout<<"\n\nNODE : "<<ptr->num;
            cout<<"\nIMAGE :"<<ptr->image;
            ptr=ptr->down;
        }
    }
    node* get(int i)
    {
        struct node *ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->num==i)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down;
        while(ptr!=NULL)
        {
            if(ptr->num==i)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down->down;
        while(ptr!=NULL)
        {
            if(ptr->num==i)
                return ptr;
            ptr=ptr->right;
        }
    }
    node *getvoid()
    {
        struct node *ptr=start;
        while(ptr!=NULL)
        {
            if(strcmpi(ptr->image,"9.jpg")==0)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down;
        while(ptr!=NULL)
        {
            if(strcmpi(ptr->image,"9.jpg")==0)
                return ptr;
            ptr=ptr->right;
        }
        ptr=start->down->down;
        while(ptr!=NULL)
        {
            if(strcmpi(ptr->image,"9.jpg")==0)
                return ptr;
            ptr=ptr->right;
        }
    }
}Q,Q1;
void swapdata(node C,node *a,node *b)
{
    char temp[10];
    strcpy(temp,a->image);
    strcpy(a->image,b->image);
    strcpy(b->image,temp);
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
    while(1)
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
        if(p1==NULL)
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
int main()
{
    int j;
    for(j=1;j<=9;j++)
    {
        char a[30];
        itoa(j,a,10);
        strcat(a,".jpg");
        Q.insert(a);
    }
    int i;
    int gm=DETECT,gd;
    initwindow(getmaxwidth(),getmaxheight(),"IMAGE PUZZLE");
    picdisplay(Q);
    closegraph();
    int shuffle[9];
    /*for(i=1;i<10;i++)
    {
        int k=rand()%9+1;
        for(j=0;j<i-1;j++)
        {
            if(shuffle[j]==k)
                k=0;
        }
        if(k==0)
            i--;
        else
            shuffle[i-1]=k;
    }*/

    shuffle[0]=1;
    shuffle[1]=2;
    shuffle[2]=3;
    shuffle[3]=4;
    shuffle[4]=5;
    shuffle[5]=6;
    shuffle[6]=7;
    shuffle[7]=9;
    shuffle[8]=8;            //FOR TESTING PURPOSE

    for(i=0;i<9;i++)
    {
        struct node *p=Q.get(shuffle[i]);
        Q1.insert(p->image);
    }

    initwindow(getmaxwidth(),getmaxheight(),"IMAGE PUZZLE");

    while(!nodeequal(Q,Q1))
    {
        POINT s;
        s=picdisplay(Q1);
        node *p;
        p=Q1.getvoid();
        if(p->left!=NULL)
        {
            if(s.x>=p->left->lx && s.x<=p->left->hx && s.y>=p->left->ly && s.y<=p->left->hy)
            {
                swapdata(Q1,p->left,p);
            }
        }
        if(p->right!=NULL)
        {
            if(s.x>= p->right->lx && s.x<=p->right->hx && s.y>=p->right->ly && s.y<=p->right->hy)
            {
                swapdata(Q1,p->right,p);
            }
        }
        if(p->up!=NULL)
        {
            if(s.x>= p->up->lx && s.x<=p->up->hx && s.y>=p->up->ly && s.y<=p->up->hy)
            {
                swapdata(Q1,p->up,p);
            }
        }
        if(p->down!=NULL)
        {
            if(s.x>= p->down->lx && s.x<=p->down->hx && s.y>=p->down->ly && s.y<=p->down->hy)
            {
                swapdata(Q1,p->down,p);
            }
        }
    }
    closegraph();
    if(nodeequal(Q,Q1))
    {
        char str[]="WOW! you finished the puzzle";
        for(int i=0;i<strlen(str);i++)
        {
            cout<<str[i];
            Sleep(500);
        }
    }
    else
    {
        cout<<"You haven't solved the puzzle";
    }
}
