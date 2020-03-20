//Chandra Deb
//Linked list in C++ language
#include <iostream>
#include <fstream>
using namespace std;

//listNode class
class listNode
	{
		public:
			int data;
			listNode* next;
			void printNode(listNode *node){
				cout << "(" << node -> data << ", " << node << ", " << node -> next << ", " << node -> next -> data << ")";
			}
	};
	
//Linked list class
class linkedList
{
	private:
		listNode *head;
	
	public:
		linkedList(){
			head = NULL;
		}
		
		void listHead (listNode *node){
			head = node;
		}
		
		listNode * createNode(int value){
			listNode *temp = new listNode;
			temp -> data = value;
			temp -> next = NULL;
			return temp;
		}
		
		void constructLL(ifstream& inFile, ofstream& outFile2){
			int x;
			while(inFile >> x){
				listNode *temp = new listNode;
				temp = createNode(x);
				listInsert(temp);
				printList(outFile2);
			}
		}
		
		void listInsert (listNode *newNode){
			listNode *spot = findSpot(newNode);
			newNode -> next = spot -> next;
			spot -> next = newNode; 
		}
		
		listNode * findMiddleNode(ofstream& outFile2){
			listNode *walk1 = head;
			listNode *walk2 = head;
			outFile2 << endl << endl << "Finding middle node now:" << endl;
			
			while((walk2 != NULL) && (walk2 -> next != NULL)){
				outFile2 << "(" << walk1 -> data << ", " << walk1 << ", " << walk1 -> next << ", " << walk1 -> next -> data << ") -> ";
				walk1 = walk1 -> next;
				walk2 = walk2 -> next -> next;
			}
			outFile2 << "(" << walk1 -> data << ", " << walk1 << ", " << walk1 -> next << ", " << walk1 -> next -> data << ")";
			return walk1;
		}
		
		listNode * findSpot(listNode *newNode){
			listNode *spot = head;
			int x = newNode -> data;
			if(spot -> next == NULL)
				return spot;
			else
			{
				while(spot -> next != NULL && (spot -> next -> data < x)){
					spot = spot -> next;
				}
				return spot;
			}
		}
		
		void printList (ofstream& outFile){
			listNode *temp = head;
			outFile << "listHead ->";
			while (temp -> next != NULL){
				outFile << "(" << temp -> data << ", " << temp << ", " << temp -> next << ", " << temp -> next -> data << ") -> " ;
				temp = temp -> next;
			} 
			outFile << " NULL" << endl;
			
		}
	
};



//main class
int main(int argc, char** argv) {
	ifstream inFile;
	ofstream outFile;
	ofstream outFile2;
	if (argc!= 4)
	{
		cout << "Programn format is: a.out  infile_name outfile1_name outfile2_name.";
	}
	
	inFile.open(argv[1]);
	outFile.open(argv[2]);
	outFile2.open(argv[3]);
	
	linkedList list;
	listNode *dummy = list.createNode(-9999);
	list.listHead(dummy);
	list.constructLL(inFile, outFile2);
	list.printList(outFile);
	listNode *middleNode = list.findMiddleNode(outFile2);
	outFile << endl << "Middle node: " <<  "(" << middleNode -> data << ", " << middleNode << ")";
	
	inFile.close();
	outFile.close();
	outFile2.close();
	
	return 0;
}
