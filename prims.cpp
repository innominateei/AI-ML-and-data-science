#include<iostream>
using namespace std;

class tree
{
	int a[20][20],l,u,w,i,j,vertices,edges,visited[20],vertexset[10],p;
public:
	void input();
	void display();
	int search(int vertexset[],int N,int x)
    {
        for(int c=0;c<N;c++)
            if(vertexset[c]==x)
                return 1;
        return -1;
    }
	void minimum();
};
void tree::input()
{
	cout<<"Enter the no. of vertices(column): ";//vertices
	cin>>vertices;
	for(i=1;i<=vertices;i++)
	{
		cout<<"\nEnter vertx "<<i<<"  : ";
		cin>>vertexset[i];
	}

	for(i=0;i<vertices;i++)
	{
		visited[i]=0;
		for(j=0;j<vertices;j++)
		{
			a[i][j]=999;
		}
	}

	cout<<"\nEnter the no. of edges(rows): ";//edges
	cin>>edges;

	for(i=0;i<edges;i++)
	{
		cout<<"Enter the starting and end verices of edges:  "<<endl;
		cout<<"Stating :"<<endl;
		cin>>l;
		 p=search(vertexset,20,l);      
            while(p==-1)
            {
                cout<<"\nEnter valid vertex...";
                cin>>l;
                p=search(vertexset,20,l);
            }  

		cout<<"Ending : "<<endl;
		cin>>u;
		 p=search(vertexset,20,u);   
            while(p==-1)
            {
                cout<<"\nEnter valid vertex...";
                cin>>u;
                p=search(vertexset,20,u);
            }

		cout<<"Enter the phone company charges for this connection(weight of edges)- ";
		cin>>w;
		a[l-1][u-1]=a[u-1][l-1]=w;
	}
}
void tree::display()
{
	cout<<"\nAdjacency matrix:";
	for(i=0;i<vertices;i++)
	{
		cout<<endl;
		for(j=0;j<vertices;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void tree::minimum()
{
	int p=0,q=0,total=0,min;
	visited[0]=1;
	for(int count=0;count<(vertices-1);count++)
	{
		min=999;
		for(i=0;i<vertices;i++)
		{
			if(visited[i]==1)
			{
				for(j=0;j<vertices;j++)
				{
					if(visited[j]!=1)
					{
						if(min > a[i][j])
						{
							min=a[i][j];
							p=i;
							q=j;
						}
					}
				}
			}
		}
		visited[p]=1;
		visited[q]=1;
		total=total+min;
		cout<<"Minimum cost connection is"<<(p+1)<<" -> "<<(q+1)<<"  with charge : "<<min<< endl;
		
	}
	cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}

int main()
{
	int ch;
	tree t;
	do
	{
		cout<<"==========PRIM'S ALGORITHM================="<<endl;
		cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
	
	switch(ch)
	{	
	case 1: cout<<"*******INPUT YOUR VALUES*******"<<endl;	
		t.input();
		break;

	case 2: cout<<"*******DISPLAY THE CONTENTS********"<<endl;
		t.display();
		break;

	case 3: cout<<"*********MINIMUM************"<<endl;
		t.minimum();
		break;
	}
	
	}while(ch!=4);
	return 0;
}
