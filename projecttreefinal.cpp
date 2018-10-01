#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<cctype>
using namespace std;
struct tree_node
{
    char var;
    tree_node *left,*right;
} ;
class exp_tree
{
    char post[30],inf[30];
    tree_node *root;
public:
    exp_tree()
    {
        root=NULL;
    }
    void get_exp()
    {
        cout<<"Enter the infix expression(please use digit):: ";
        cin>>inf;

    }
    tree_node* get_root()
    {
        return root;
    }
    void convert();
    void exp_to_tree();
    void inorder(tree_node *);
    void preorder(tree_node *);
    void postorder(tree_node *);
};
void exp_tree::convert()
{
    int y=0,top=-1,stac[10];
    for(int i=0;inf[i]!=0;i++)
    {


        if(inf[i]>=49&&inf[i]<=57)
            post[y++]=inf[i];
        else
        {
            switch(inf[i])
            {
            case '+':
            case '-':
                while(top>=0&&stac[top]!='(')
                    post[y++]=stac[top--];
                stac[++top]=inf[i];
                break;
                case '*':
                case '/':
                    while(stac[top]!='+'&&stac[top]!='-'&&top>=0&&stac[top]!='(')
                         post[y++]=stac[top--];
                    stac[++top]=inf[i];
                    break;
                case '^':
                    stac[++top]=inf[i];
                    break;
                case '(':
                    stac[++top]=inf[i];
                    break;
                case ')':
                    while(stac[top]!='(')
                        post[y++]=stac[top--];
                    top--;
                    break;
                }
        }
    }
    while(top>=0)
        post[y++]=stac[top--];
    post[y]=0;
}
void exp_tree::exp_to_tree()
{
    int top=-1,z;
    tree_node *stack[20];
    for(int i=0;post[i]!=0;i++)
    {
        stack[++top]=new tree_node;
        if(post[i]>=49&&post[i]<=57)
        {
            stack[top]->var=post[i];
            stack[top]->left=stack[top]->right=NULL;
        }
        else
        {
            stack[top]->var=post[i];
            stack[top]->left=stack[top-2];
            stack[top]->right=stack[top-1];
            top=top-2;
            root=stack[top]=stack[top+2];
        }
    }
}
void exp_tree::inorder(tree_node *temp)
{
    if(temp==NULL)
        return;
    inorder(temp->left);
    cout<<temp->var;
    inorder(temp->right);
}
void exp_tree::postorder(tree_node *temp)
{
    if(temp==NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);

    cout<<temp->var;
}
void exp_tree::preorder(tree_node *temp)
{
    if(temp==NULL)
        return;
    cout<<temp->var;
    preorder(temp->left);
    preorder(temp->right);
}



int stack[20];
int top = -1;

void push(int x)
{
        stack[++top] = x;
}

int pop()
{
        return stack[top--];
}
int main()
{
    cout<<"==========================Project: Expression Tree==============================="<<endl;
    exp_tree exp;
    exp.get_exp();
    exp.convert();
    exp.exp_to_tree();
    cout<<"Expression tree Successfully created "<<endl;
    cout<<"Infix Expression : ";
    exp.inorder(exp.get_root());
    cout<<endl<<"Postfix Expression : ";
    exp.postorder(exp.get_root());
    cout<<endl<<"Prefix Expression : ";
    exp.preorder(exp.get_root());

     char expr[20];
        char *e;
        int n1,n2,n3,num;
        printf("\nCopy Postfix expression here to evaluate :: ");
        scanf("%s",expr);

        e = expr;
       // while(*e!='\0')
        //{

        //}

        while(*e != '\0')
        {        if(isalpha(*e))
             {
                cout<<"Please enter valid expression with number";
                 exit(0);
             }


               if(isdigit(*e))
                {
                        num = *e - 48;
                        push(num);
                }
                else
                {
                        n1 = pop();
                        n2 = pop();
                        switch(*e)
                        {
                                case '+':
                                {
                                        n3 = n1 + n2;
                    break;
                                }
                                case '-':
                                {
                                        n3 = n2 - n1;
                                        break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        n3 = n2 / n1;
                                        break;
                                }
                        }
                        push(n3);
                }
                e++;
        }
        printf("\nThe Evaluation of expression %s  =  %d\n\n",expr,pop());
        cout<<"===================================THANK YOU========================================="<<endl;
        cout<<"============================RAJIB ,TANVIR & SAQLAIN========================================"<<endl;
        return 0;

    return 0;
}
