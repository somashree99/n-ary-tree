#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int max_depth,max_branch;

class node{
	public:
		int data;
		int num_of_child;
		vector<node*> cnodes;
		node()
		{
			data=0;
		}
		node(int val)	
		{
			data=val;
		}
		
};

class node1{
	public:
		int data1;
		int num_of_child1;
		vector<node1*> cnodes1;
		int depth;
		node1()
		{
			data1=0;
		}
		node1(int val)
		{
			data1=val;
		}
};




class Node{
	public:
	int xmin,xmax;
	node* nd;
	Node(int xmin,int xmax,node* curr){
		this->xmin=xmin;
		this->xmax=xmax;
		this->nd=curr;
	}
};


double convert(float deg){
	return deg*3.14159/180;
}
void display_vis(node* root){
	queue<Node> pq;
	setcolor(BLACK);
	Node rand(0,1600,root);
	pq.push(rand);
	circle(800,100,20);
	int y=200;
	int r=20;
	outtextxy(800-7,100-7,&(to_string(root->data))[0]);
	while(!pq.empty()){
		int size=pq.size();
		while(size--){
	 		auto q=pq.front();
	 		pq.pop();
	 		node* curr=q.nd;
		    int total_width=q.xmax-q.xmin;
			int xmax=q.xmax;
			int xmin=q.xmin;
			int x1=(xmax+xmin)/2;
			int y1=y-100;
			if(curr->cnodes.size()>0){
			int gap=total_width/curr->cnodes.size();
			double angle=135;
			for(int i=0;i<curr->cnodes.size();i++){
			   circle(xmin+(i*gap)+gap/2,y,20);
			   outtextxy(xmin+(i*gap)+gap/2-7,y-7,&(to_string(curr->cnodes[i]->data))[0]);
			   int x2=xmin+(i*gap)+gap/2,y2=y;
			   line(x1+r*cos(convert(angle)),y1+r*sin(convert(angle)),x2+r*cos(convert(-90)),y2+r*sin(convert(-90)));
			   Node emni(xmin+i*gap,xmin+(i+1)*gap,curr->cnodes[i]);
			   pq.push(emni);
			   angle-=45;	
			}
		  }
		 }
		 y+=100;
	 }

}

void clearscreen()
{
	for(int y=450;y<=650;y++)
	{
		for(int x=600;x<=1020;x++)
			putpixel(x,y,WHITE);
	}
}

node* createTree(node *root){
	int x,n;
	cout<<"\nEnter root node: ";
	cin>>x;
	max_branch=1;
	queue<node*> q;
	root=new node(x);
	node *ptr,*ptr1,*ptr2;
	q.push(root);
	while(!q.empty())
	{
		ptr=q.front();
		q.pop();
		cout<<"Enter number of child nodes of "<<ptr->data<<" : ";
		cin>>n;
		if(max_branch < n)
			max_branch=n;
		ptr->num_of_child=n;
		if(n>0)
		{
			//(ptr->cnodes).resize(n);
			
			cout<<"Enter child nodes of "<<ptr->data<<" :-\n";
			for(int i=0;i<n;i++)
			{
				cin>>x;
				ptr1=new node(x);
				(ptr->cnodes).push_back(ptr1);
				q.push(ptr1);
			}
		}
	}
	return root;
}

node1* newTree(node* root)
{
	node1 *root1,*ptr1,*ptr2;
	node *ptr;
	queue<node*> q;
	queue<node1*> q1;
	q.push(root);
	root1=new node1(root->data);
	root1->depth=0;
	root1->num_of_child1=root->num_of_child;
	q1.push(root1);
	while(!q.empty())
	{
		ptr=q.front();
		ptr1=q1.front();
		cout<<"\nptr1->data = "<<ptr1->data1<<endl;
		cout<<"\nptr1->depth = "<<ptr1->depth<<endl;
		cout<<"\nptr1->num_of_child = "<<ptr1->num_of_child1 <<endl;
		q1.pop();
		q.pop();
		for(int i=0;i<ptr->num_of_child;i++)
		{
			ptr2=new node1((ptr->cnodes[i])->data);
			ptr2->depth=ptr1->depth + 1;
			if(ptr2->depth>max_depth)
				max_depth=ptr2->depth;
			ptr2->num_of_child1=ptr->cnodes[i]->num_of_child;
			ptr1->cnodes1.push_back(ptr2);
			//ptr1->cnodes1[i]=ptr2;
			
			
			q.push(ptr->cnodes[i]);
			q1.push(ptr2);
		}
	}
	return root1;
}
/*
void display2(node *root)
{
	initwindow(1000,900);
	int hx,hy,x,y;
	hx=getmaxx();
	hy=getmaxy();
	char s[10];
	sprintf(s,"%d",root->data);
	//cout<<"hx="<<hx;
	//cout<<"hy="<<hy;
	outtextxy(hx/2,30,s);
	circle(hx/2,35,20);
	queue<node*> q;
	x=hx/2;
	y=35;
	getch();
	closegraph();
}*/
/*
void display_newTree(node1 *root)
{
	cout<<"root node is "<<root->data1;
	node1 *ptr,*ptr1;
	queue<node1*> q;
	q.push(root);
	int n;
	while(!q.empty())
	{
		ptr=q.front();
		q.pop();
		if(ptr->num_of_child1==0)
			cout<<"\nNode "<<ptr->data1<<" has no child nodes.";
		else{
			n=ptr->num_of_child1;
			cout<<"\nNo. of child nodes of "<<ptr->data1<<" are "<<n<<" and they are:-\n";
			//cout<<(ptr->cnodes).size();
			for(int i=0;i<n;i++)
			{
				ptr1=(ptr->cnodes1[i]);
				//cout<<"\nvector access done";
				cout<<ptr1->data1<<" ";
				q.push(ptr1);
			}
		}
	}
}
*/
void display(node *root)
{
	cout<<"root node is "<<root->data;
	node *ptr,*ptr1;;
	queue<node*> q;
	q.push(root);
	int n;
	while(!q.empty())
	{
		ptr=q.front();
		q.pop();
		if(ptr->num_of_child==0)
			cout<<"\nNode "<<ptr->data<<" has no child nodes.";
		else{
			n=ptr->num_of_child;
			cout<<"\nNo. of child nodes of "<<ptr->data<<" are "<<n<<" and they are:-\n";
			//cout<<(ptr->cnodes).size();
			for(int i=0;i<n;i++)
			{
				ptr1=(ptr->cnodes[i]);
				//cout<<"\nvector access done";
				cout<<ptr1->data<<" ";
				q.push(ptr1);
			}
		}
	}
}

void bfs(node *root){
	int val;
	string s="";
	char buffer[100];
	s="-------------------BFS------------------------";
	strcpy(buffer,s.c_str());
	outtextxy(700,450,buffer);
	cout<<"\n\n-------------------BFS------------------------\n\n";
	cout<<"\n\n\n\nEnter value to search: ";
	cin>>val;
	queue<node*> open,closed;
	if(root==NULL)
	{
		cout<<"tree is empty!! cannot find the desired node.";
		return;
	}
	node *ptr;
	open.push(root);
	while(!open.empty())
	{
		ptr=open.front();
		open.pop();
		closed.push(ptr);
		if(ptr->data==val)
		{
			cout<<"\nElement found!!";
			s="Goal node found";
			strcpy(buffer,s.c_str());
			outtextxy(600,470,buffer);
			break;
		}
		for(int i=0;i<ptr->num_of_child;i++)
		{
			open.push(ptr->cnodes[i]);
		}
	}
	if(ptr->data != val)
	{
		cout<<"\nElement not found!!";
		s="Goal node not found";
		strcpy(buffer,s.c_str());
		outtextxy(600,470,buffer);
	}
	//cout<<"\nBFS order: ";
	s="BFS order: ";
	while(!closed.empty())
	{
		ptr=closed.front();
		closed.pop();
		//cout<<ptr->data<<" ";
		s=s+to_string(ptr->data)+" ";
	}
	strcpy(buffer,s.c_str());
	outtextxy(600,490,buffer);
	//rectangle(580,450,1020,650);
}

void dfs(node *root)
{
	stack<node*> open;
	queue<node*> closed;
	string s="";
	char buffer[100];
	int val;
	s="-------------------DFS------------------------";
	strcpy(buffer,s.c_str());
	outtextxy(700,450,buffer);
	cout<<"\n\n-------------------DFS------------------------\n\n";
	cout<<"Enter element to search: ";
	cin>>val;
	open.push(root);
	node *ptr;
	while(!open.empty())
	{
		ptr=open.top();
		open.pop();
		closed.push(ptr);
		if(ptr->data==val)
		{
			cout<<"\nElement found!!";
			s="Goal Node found.";
			strcpy(buffer,s.c_str());
			outtextxy(600,470,buffer);
			break;
		}
		for(int i=ptr->num_of_child-1;i>=0;i--)
			open.push(ptr->cnodes[i]);
	}
	if(ptr->data != val)
	{
		cout<<"\nElement not found!!";
		s="Goal node not found in the tree";
		strcpy(buffer,s.c_str());
		outtextxy(700,470,buffer);
	}
	//cout<<"\nDFS order: ";
	s="DFS order: ";
	while(!closed.empty())
	{
		ptr=closed.front();
		closed.pop();
		//cout<<ptr->data<<" ";
		s=s+to_string(ptr->data)+" ";
		strcpy(buffer,s.c_str());
	}
	outtextxy(700,490,buffer);
}

bool DLS(node1* root,int goal,int limit,int x,int y)
{
	stack<node1*> open;
	queue<node1*> closed;
	string s;
	char buffer[50];
	//node1 *root1;
	//root1=newTree(root);
	//cout<<"\n\nAfter converting the new tree is: \n";
	//display_newTree(root1);
	open.push(root);
	node1 *ptr;
	int flag=0;//not found
	while(!open.empty())
	{
		ptr=open.top();
		open.pop();
		
		if(ptr->depth>limit)
			continue;
		closed.push(ptr);
		if(ptr->data1==goal)
		{
			//cout<<"\nElement found!!";
			flag=1;
			break;	
		}
		for(int i=ptr->num_of_child1-1;i>=0;i--)
			open.push(ptr->cnodes1[i]);
	}
	//if(flag == 0)
		//cout<<"\nElement not found!!";
	//cout<<"\nDLS order: ";
	s="";
	while(!closed.empty())
	{
		ptr=closed.front();
		closed.pop();
		//cout<<ptr->data1<<" ";
		s=s+to_string(ptr->data1)+" ";
	}
	strcpy(buffer,s.c_str());
	outtextxy(x,y,buffer);
	if(flag==1)
		return true;
	else
		return false;
}

bool IDS(node1* root, int goal,int &ans)
{
	//cout<<"maximum depth of the tree is "<<max_depth<<endl;
	//return true;
	string s="";
	char buffer[100];
	s="";
	//cout<<"\nDepth\t\tDFS order\n";
	s="Depth		DFS order";
	strcpy(buffer,s.c_str());
	outtextxy(600,490,buffer);
	int x=600,y=510;
	for(int depth=0;depth<=max_depth;depth++)
	{
		//cout<<"   "<<depth<<"\t\t";
		s="   "+to_string(depth)+"	    ";
		strcpy(buffer,s.c_str());
		outtextxy(x,y,buffer);
		if(DLS(root,goal,depth,x+100,y))
		{
			ans=depth;
			return true;
		}
		//cout<<endl;
		y+=20;
	}
	return false;
}

bool IBS(node *root,int goal,int &ans){
	node *ptr;
	int flag=0;
	string s="";
	char buffer[100];
	stack<node*> temp;
	stack<node*> open;
	queue<node*> closed;
	s="------------------------IBS--------------------";
	strcpy(buffer,s.c_str());
	outtextxy(700,450,buffer);
	cout<<"\n------------------------IBS--------------------\n\n";
	//cout<<"\nBranch\t\tDFS order\n";
	s="Branch		DFS order";
	strcpy(buffer,s.c_str());
	outtextxy(700,470,buffer);
	int x=700;
	int y=490;
	for(int branch=1;branch<=max_branch;branch++)
	{
		//cout<<"   "<<branch<<"\t\t";
		s="	"+to_string(branch)+"		";
		strcpy(buffer,s.c_str());
		outtextxy(x,y,buffer);
		open.push(root);
		while(!open.empty()){
			ptr=open.top();
			open.pop();
			closed.push(ptr);
			if(ptr->data==goal)
			{
				flag=1;
				ans=branch;
				break;
			}
			for(int i=0;i<branch and i<ptr->num_of_child;i++)
				temp.push(ptr->cnodes[i]);
			while(!temp.empty())
			{
				open.push(temp.top());
				temp.pop();
			}
		}
		s="";
		while(!closed.empty())
		{
			ptr=closed.front();
			closed.pop();
			//cout<<ptr->data<<" ";
			s=s+to_string(ptr->data)+" ";
		}
		strcpy(buffer,s.c_str());
		outtextxy(x+100,y,buffer);
		//cout<<endl;
		if(flag==1)
			break;
		y+=20;
	}
	if(flag==1)
		return true;
	else
		return false;
}

int main(){
	initwindow(1600,800);
	setbkcolor(15);
	cleardevice();
	string s;
	char buffer[100];
	node *r;
	r=createTree(r);
	cout<<"\n\n\n\nDetails of tree nodes:\n";
	cout<<"------------------------------\n\n";
	display(r);
	display_vis(r);
	node1 *root;
	root=newTree(r);
	//cout<<"\n\n\nNew Tree-----------------\n";
	//display_newTree(root);
	int choice,goal,limit,ans;
	do{
		cout<<"\n*******______________Choose any search technique__________________*********\n\t1. BFS (Breadth First Search)\n\t2. DFS (Depth First Search)\n\t3. DLS (Depth Limited Search)\n\t4. IDS (Iterative deepening search)\n\t5. IBS (Iterative broadening search)\n\t6. Stop searching\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: clearscreen();
				bfs(r);
				break;
			case 2: clearscreen();
				dfs(r);
				break;
			case 3: clearscreen();
				cout<<"\nEnter goal node: ";
				cin>>goal;
				cout<<"\nEnter depth limit: ";
				cin>>limit;
				
				s="-------------------DLS------------------------";
				strcpy(buffer,s.c_str());
				outtextxy(700,450,buffer);
				cout<<"\n\n-------------------DLS------------------------\n\n";
				//cout<<"DFS order: ";
				s="DFS order: ";
				strcpy(buffer,s.c_str());
				outtextxy(700,470,buffer);
				if(DLS(root,goal,limit,800,470))
					cout<<"\nGoal node found!\n";
				else
					cout<<"\nGoal node not found!!\n";
				break;
			case 4: cout<<"\nEnter goal node: ";
				cin>>goal;
				clearscreen();
				ans=0;
				if(IDS(root,goal,ans))
					cout<<"\nGoal node found at depth "<<ans<<"\n";
				else
					cout<<"\nGoal node not found!!\n";
				break;
			case 5: clearscreen();
				cout<<"\nEnter goal node: ";
				cin>>goal;
				ans=0;
				if(IBS(r,goal,ans))
					cout<<"\nGoal node found at branch "<<ans<<"\n";
				else
					cout<<"\nGoal node not found!!\n";
				break;
			case 6: cout<<"Exit from program.";
				break;
			default: cout<<"\nPlease enter correct choice of search technique, otherwise press correct switch to stop searching.\n";
		}
	}while(choice!=6);
	closegraph();
	return 0;
}
