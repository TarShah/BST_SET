#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define len(v) v.size()
 
struct node{
	int val;
	node* left;
	node* right;
};
struct BST{
	node* root;
	BST() : root(nullptr){
	}
	node* addnode(node* root,int x){
		if(root == nullptr){
			node* newnode = new node();
			newnode->val = x;
			root = newnode;
		}
		else if(x < root->val){
			root->left = addnode(root->left,x);
		}
		else if(x > root->val){
			root->right = addnode(root->right,x);	
		}
		return root;
	}
	node* delnode(node* root, int x){
		if(root == nullptr) return root;
	
    	if(root->val > x){
        	root->left = delnode(root->left, x);
        	return root;
    	}
    	else if(root->val < x){
        	root->right = delnode(root->right, x);
        	return root;
    	}
 		// One child;
    	if(root->left == nullptr){
        	node* temporary = root->right;
        	delete(root);
        	return temporary;
    	}
    	else if(root->right == nullptr){
        	node* temporary = root->left;
        	delete(root);
        	return temporary;
    	}
    	//Two child;
    	else{
        	node* succParent = root;
        	node* succ = root->right;
        	while (succ->left != nullptr) {
            	succParent = succ;
            	succ = succ->left;
        	}
        	if(succParent != root) succParent->left = succ->right;
        	else succParent->right = succ->right;
       		root->val = succ->val;
        	delete(succ);
        	return root;
    	}
	}
	void inorder(node* root){
		if(root == nullptr) return;
		inorder(root->left);
		cout<<root->val<<',';
		inorder(root->right);
	
	}
	bool search(node* root,int x){
		if(root == nullptr) return false;
		else if(root->val == x) return true;
		else if(root->val > x) return search(root->left,x);
		else if(root->val < x) return search(root->right,x);
	}
	void toarr(node* root,vector<int>& v){
		if(root==nullptr) return;
		else{
			toarr(root->left,v);
			v.pb(root->val);
			toarr(root->right,v);
		}
	}
	void clear(node* root){
		if(root == nullptr) return;
		else{
			clear(root->left);
			clear(root->right);
			delete(root);
		}
	}
};
class SET{
	public:
	int length = 0;
	BST tree;
	void Insert(int x){
		if(tree.search(tree.root,x)==false) length++;
		tree.root = tree.addnode(tree.root,x);
		cout<<length<<endl;
	}
	void Delete(int x){
		if(tree.search(tree.root,x)==true) length--;
		tree.root = tree.delnode(tree.root,x);
		cout<<length<<endl;
	}
	void Belongs_To(int x){
		if(tree.search(tree.root,x)==true) cout<<1<<endl;
		else cout<<0<<endl;
	}
	void Union(SET other){
		vector<int> tree1;
		vector<int> tree2;
		tree.toarr(tree.root,tree1);
		other.tree.toarr(other.tree.root,tree2);
		
		tree.clear(tree.root);
		tree.root = nullptr;
		length = 0;
		
		for(int i=0;i<len(tree1);i++){
			if(!tree.search(tree.root,tree1[i])) {
				tree.root = tree.addnode(tree.root,tree1[i]);
				length++;	
			}
		}
		for(int i=0;i<len(tree2);i++){
			if(!tree.search(tree.root,tree2[i])) { 
				tree.root = tree.addnode(tree.root,tree2[i]);
				length++;	
			}
		}
		cout<<length<<endl;
		
	}		
	void Intersection(SET other){
		vector<int> tree1;
		vector<int> tree2;
		tree.toarr(tree.root,tree1);
		other.tree.toarr(other.tree.root,tree2);
		
		tree.clear(tree.root);
		tree.root = nullptr;
		length = 0;
		
		int i=0,j=0;
		while(i<len(tree1) and j<len(tree2)){
			while(j<len(tree2) and tree1[i]>tree2[j]){
				j++;
			}
			if(j<len(tree2) and tree1[i] == tree2[j]){
				tree.root = tree.addnode(tree.root,tree1[i]);
				length++;
			}
			i++;
		}
		cout<<length<<endl;
	}
	void Size(){
		cout<<length<<endl;	
	}
	void Difference(SET other){
	 	vector<int> tree1;
	 	vector<int> tree2;
	 	tree.toarr(tree.root,tree1);
	 	other.tree.toarr(other.tree.root,tree2);
	 	
	 	tree.clear(tree.root);
	 	tree.root =  nullptr;
	 	length = 0;
	 	
	 	vector<int> newvec;
	 	int i=0,j=0;
		while(i<len(tree1) and j<len(tree2)){
			while(j<len(tree2) and tree1[i]>tree2[j]){
				j++;
			}
			if(j<len(tree2) and tree1[i] == tree2[j]){
				newvec.pb(tree1[i]);
			}
			i++;
		}
	 	
	 	j=0;
	 	for(int i=0;i<len(tree1);i++){
			if(j<len(newvec) and tree1[i]==newvec[j]){
				j++;
			}
			else{
				tree.root = tree.addnode(tree.root,tree1[i]);
				length++;
			}
	 	}
	 	cout<<length<<endl;
	}
	void Symmetric_Difference(SET other){
	 	vector<int> tree1;
	 	vector<int> tree2;
	 	tree.toarr(tree.root,tree1);
	 	other.tree.toarr(other.tree.root,tree2);
	 	
	 	tree.clear(tree.root);
	 	tree.root =  nullptr;
	 	length = 0;
	 	
	 	int i=0;int j=0;
	 	while(i<len(tree1) or j<len(tree2)){
			if(j==len(tree2)){
				while(i<len(tree1)){
					tree.root = tree.addnode(tree.root,tree1[i]);
					i++;
					length++;
				}
			}
			if(i==len(tree1)){
				while(j<len(tree2)){
					tree.root = tree.addnode(tree.root,tree2[j]);
					j++;
					length++;
				}
			}
			if(i<len(tree1) and j<len(tree2) and tree1[i]<tree2[j]){
				while(i<len(tree1) and j<len(tree2) and tree1[i]<tree2[j]){
					tree.root = tree.addnode(tree.root,tree1[i]);
					i++;
					length++;
				}
			}
			else if(i<len(tree1) and j<len(tree2) and tree1[i]>tree2[j]){
				while(i<len(tree1) and j<len(tree2) and tree1[i]>tree2[j]){
					tree.root = tree.addnode(tree.root,tree2[j]);
					j++;
					length++;
				}
				
			}
			if(i<len(tree1) and j<len(tree2) and tree1[i]==tree2[j]){
				i++;
				j++;
			}
	 	}
	 	cout<<length<<endl;
	}
	void Print(){
		if(length == 0){
			cout<<endl;
			return;
		}
		vector<int> trav;
		tree.toarr(tree.root,trav);
		cout<<trav[0];
		for(int i=1;i<len(trav);i++){
			cout<<','<<trav[i];
		}
		cout<<endl;
		return;
	}
};

int main(){
	vector<SET> sets;
	int com_num;
	while(cin>>com_num){
		int num,ele,n1,n2;
			if(com_num==1){
				cin>>num>>ele;
				num++;
				if(len(sets)<num){
					SET s;
					sets.pb(s);
					sets[num-1].Insert(ele);
				}
				else{
					sets[num-1].Insert(ele);
				}
				continue;
			}
			if(com_num==2){
				cin>>num>>ele;
				num++;
				if(len(sets)<num){
					cout<<-1<<endl;
				}
				else{
					sets[num-1].Delete(ele);
				}
				continue;
			}
			if(com_num==3){
				cin>>num>>ele;
				num++;
				if(len(sets)<num){
					cout<<-1<<endl;
				}
				else{
					sets[num-1].Belongs_To(ele);
				}
				continue;
			}
			if(com_num==4){
				cin>>n1>>n2;
				n1++;n2++;
				if(max(n1,n2)==len(sets)+1){ 
					SET s;
					sets.pb(s);
				}
				else if(max(n1,n2)==len(sets)+2){
					SET s1,s2;
					sets.pb(s1);
					sets.pb(s2);
				}
				n1--; n2--;
				sets[n1].Union(sets[n2]);
				continue;
			}
			if(com_num==5){
				cin>>n1>>n2;
				n1++;n2++;
				if(max(n1,n2)==len(sets)+1){ 
					SET s;
					sets.pb(s);
				}
				else if(max(n1,n2)==len(sets)+2){
					SET s1,s2;
					sets.pb(s1);
					sets.pb(s2);
				}
				n1--; n2--;
				sets[n1].Intersection(sets[n2]);
				continue;
			}
			if(com_num==6){
				cin>>num;
				num++;
				if(len(sets)<num){
					SET s;
					sets.pb(s);
					cout<<0<<endl;
				}
				else{
					sets[num-1].Size();
				}
				continue;
			}
			if(com_num==7){
				cin>>n1>>n2;
				n1++;n2++;
				if(max(n1,n2)==len(sets)+1){ 
					SET s;
					sets.pb(s);
				}
				else if(max(n1,n2)==len(sets)+2){
					SET s1,s2;
					sets.pb(s1);
					sets.pb(s2);
				}
				n1--; n2--;
				sets[n1].Difference(sets[n2]);
				continue;
			}
			if(com_num==8){
				cin>>n1>>n2;
				n1++;n2++;
				if(max(n1,n2)==len(sets)+1){ 
					SET s;
					sets.pb(s);
				}
				else if(max(n1,n2)==len(sets)+2){
					SET s1,s2;
					sets.pb(s1);
					sets.pb(s2);
				}
				n1--; n2--;
				sets[n1].Symmetric_Difference(sets[n2]);
				continue;
			}
			if(com_num==9){
				cin>>num;
				num++;
				if(len(sets)<num) cout<<endl;
				else sets[num-1].Print();
				continue;
			}
		
	}
	for(int i=0;i<len(sets);i++){
		sets[i].tree.clear(sets[i].tree.root);
	}
	return 0;
}
