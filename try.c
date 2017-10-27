#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(x, y)       ( (x == y) ? 0 : (x > y) ? 1 : -1)
struct node
{
             int coef;
             int px, py, pz;
             struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
            NODE x;
            x = (NODE) malloc(sizeof(struct node));
            if(x == NULL)
            {
                        printf("Running out of memory \n");
                        return NULL;
            }
            return x;
}

NODE attach(int coef, int px, int py, int pz, NODE head)
{
       NODE temp, cur;
       temp = getnode();
       temp->coef = coef;
       temp->px = px;
       temp->py = py;
       temp->pz = pz;
       cur = head->link;
            while(cur->link != head)
            {
                        cur = cur->link;
            }
            cur->link = temp;
            temp->link = head;
            return head;
}

NODE read_poly(NODE head)
{
            int i, j, coef, px, py, pz, n;
            printf("\nEnter the no of terms in the polynomial: ");
            scanf("%d", &n);
            for(i=1; i<=n; i++)
            {
                  printf("\n\tEnter the %d term: ",i);
                  printf("\n\t\tCoef =  ");
                  scanf("%d", &coef);
                  printf("\n\t\tEnter Pow(x) Pow(y) and Pow(z): ");
                  scanf("%d", &px);
                  scanf("%d", &py);
                  scanf("%d", &pz);
                  head = attach(coef, px, py, pz, head);
            }
              return head;
}

void display(NODE head)
{
            NODE temp;
            if(head->link == head)
            {
                         printf("\n polynomial does not exist");
                         return;
            }
            temp = head->link;

            while(temp != head)
            {
                         printf("%dx^%dy^%dz^%d", temp->coef, temp->px, temp->py, temp->pz);
                         temp = temp->link;
                         if(temp != head)
                                    printf(" + ");
            }
}

int poly_evaluate(NODE head)
{
            int x, y, z, sum = 0;
            NODE poly;

            printf("\nEnter the value of x,y and z: ");
            scanf("%d %d %d", &x, &y, &z);

            poly = head->link;
            while(poly != head)
            {
                        sum =sum + (poly->coef) * pow(x,poly->px)* pow(y,poly->py) * pow(z,poly->pz);
                        poly = poly->link;
            }
            return sum;
}

NODE poly_sum(NODE head1, NODE head2, NODE head3)
{
    NODE a, b;
    int coef;
    a = head1->link;
    b = head2->link;

    while(a!=head1 && b!=head2)
    {
            while(1)
            {
                        if(a->px == b->px && a->py == b->py && a->pz == b->pz)
                        {
                                    coef = a->coef + b->coef;
                                    head3 = attach(coef, a->px, a->py, a->pz, head3);
                                    a = a->link;
                                    b = b->link;
                                    break;
                        }
                        if(a->px!=0 || b->px!=0)
                        {
                                    switch(COMPARE(a->px, b->px))
                                    {
                                     case -1 :  head3 = attach(b->coef, b->px, b->py, b->pz, head3);
                                                    b = b->link;
                                                    break;

                                    case 0 :    if(a->py > b->py)
                                                    {
                                                            head3 = attach(a->coef, a->px, a->py, a->pz, head3);
                                                            a = a->link;
                                                            break;
                                                     }
                                                     else if(a->py < b->py)
                                                     {
                                                             head3 = attach(b->coef, b->px, b->py, b->pz, head3);
                                                             b = b->link;
                                                             break;
                                                     }
                                                    else if(a->pz > b->pz)
                                                    {
                                                            head3 = attach(a->coef, a->px, a->py, a->pz, head3);
                                                            a = a->link;
                                                            break;
                                                    }
                                                    else if(a->pz < b->pz)
                                                   {
                                                            head3 = attach(b->coef, b->px, b->py, b->pz, head3);
                                                            b = b->link;
                                                            break;
                                                   }
                                    case 1 :    head3 = attach(a->coef,a->px,a->py,a->pz,head3);
                                                    a = a->link;
                                                    break;
                                    }
                                    break;
                        }
                        if(a->py!=0 || b->py!=0)
                        {
                                    switch(COMPARE(a->py, b->py))
                                    {
                                          case -1 :   head3 = attach(b->coef, b->px, b->py, b->pz, head3);
                                                          b = b->link;
                                                          break;
                                           case 0 :   if(a->pz > b->pz)
                                                          {
                                                                 head3 = attach(a->coef, a->px, a->py, a->pz, head3);
                                                                 a = a->link;
                                                                 break;
                                                            }
                                                            else if(a->pz < b->pz)
                                                            {
                                                                 head3 = attach(b->coef, b->px, b->py, b->pz, head3);
                                                                 b = b->link;
                                                                 break;
                                                            }
                                            case 1 :    head3 = attach(a->coef, a->px, a->py, a->pz, head3);
                                                            a = a->link;
                                                            break;
                                    }
                                    break;
                        }
                        if(a->pz!=0 || b->pz!=0)
                        {
                                    switch(COMPARE(a->pz,b->pz))
                                    {
                                                case -1 :   head3 = attach(b->coef,b->px,b->py,b->pz,head3);
                                                                b = b->link;
                                                                break;
                                                case 1 :    head3 = attach(a->coef, a->px, a->py, a->pz, head3);
                                                                a = a->link;
                                                                break;
                                    }
                                    break;
                        }
            }
    }
    while(a!= head1)
    {
             head3 = attach(a->coef,a->px,a->py,a->pz,head3);
            a = a->link;
    }
    while(b!= head2)
    {
            head3 = attach(b->coef,b->px,b->py,b->pz,head3);
            b = b->link;
    }
    return head3;
}

void main()
{
  NODE head, head1, head2, head3;
  int res, ch;
  head =  getnode();   
  head1 = getnode();   
  head2 = getnode();    
  head3 = getnode();  

  head->link=head;
  head1->link=head1;
  head2->link=head2;
  head3->link= head3;

  while(1)
  {
	printf("\n Enter your choice:");
        printf("\n 1.Evaluate a Polynomial P(x,y,z)");
        printf("\n 2.Find the sum of two polynomials\n");
        
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n Polynomial evaluation P(x,y,z)\n");
                        head = read_poly(head);
                        printf("\n Representation of Polynomial for evaluation: \n");
                        display(head);
                        res = poly_evaluate(head);
                        printf("\n Result of polynomial evaluation is : %d \n", res);
                        break;

            case 2: printf("\n Enter the POLY1(x,y,z):  \n");
                        head1 = read_poly(head1);
                        printf("\n Polynomial 1 is:  \n");
                        display(head1);

                        printf("\n Enter the POLY2(x,y,z):  \n");
                        head2 = read_poly(head2);
                        printf("\n Polynomial 2 is: \n");
                        display(head2);

                        printf("\n Polynomial addition result: \n");
                        head3 = poly_sum(head1,head2,head3);
                        display(head3);
                        break;

            case 3: exit(0);
        }
    }
}
