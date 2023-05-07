#include "BinaryTree.h"

BST::BST() {
	root = NULL;
	index = 0;
}

Node* BST::getNode() {
	return root;
}
int BST::Size() {
	return index;
}
Node* BST::createNode(Setting* data){
	Node* temp = new Node;
	temp->value = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void BST::InsertToTree(Setting* data, Node* node) {
	Node* newNode = createNode(data);
	if (data->getOwnerID() < node->value->getOwnerID()) {
		if (node->left != NULL) {
			InsertToTree(data, node->left);
		}
		else {
			node->left = newNode;
			index++;
		}
	}
	else if (data->getOwnerID() > node->value->getOwnerID()) {
		if (node->right != NULL) {
			InsertToTree(data, node->right);
		}
		else {
			node->right = newNode;
			index++;
		}
	}
	else {
		return;
	}
}
void BST::Insert(Setting* data) {
	Node* newNode = createNode(data);
	if (root != NULL) {
		InsertToTree(data, root);
	}
	else {
		root = newNode;
		index++;
	}
}
Node* BST::SearchInTree(Setting* Key, Node* node) {
	if (node != NULL) {
		if (Key->getOwnerID() == node->value->getOwnerID()) {
			return node;
		}
		else {
			if (Key->getOwnerID() < node->value->getOwnerID()) {
				SearchInTree(Key, node->left);
			}
			else {
				SearchInTree(Key, node->right);
			}
		}
	}
	else {
		return NULL;
	}
}
Node* BST::Search(Setting* Key) {
	return SearchInTree(Key, root);
}
//void BST::OverWriteNode(Setting* data, Node* node) {
//	if (node != NULL) {
//		if (data->getOwnerID() == node->value->getOwnerID()) {
//			node->value = data;
//			return;
//		}
//		else if (data->getOwnerID() < node->value->getOwnerID()) {
//			OverWriteNode(data, node->left);
//		}
//		else {
//			OverWriteNode(data, node->right);
//		}
//	}
//}
//void BST::OverWrite(Setting* data) {
//	OverWriteNode(data, root);
//}

void BST::Print_Display(Node* node) {
	if (node != NULL) {
		Print_Display(node->left);
		node->value->printCommonInfo();
		node->value->getDisplay()->printDisplayInfo();
		Print_Display(node->right);
	}
}
void BST::Print_Sound(Node* node) {
	if (node != NULL) {
		Print_Sound(node->left);
		node->value->printCommonInfo();
		node->value->getSound()->printSoundInfo();
		Print_Sound(node->right);
	}
}
void BST::Print_General(Node* node) {
	if (node != NULL) {
		Print_General(node->left);
		node->value->printCommonInfo();
		node->value->getGeneral()->printGeneralInfo();
		Print_General(node->right);
	}
}
void BST::Print_All(Node* node) {
	if (node != NULL) {
		Print_All(node->left);
		cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" << setw(25) << "Remind service" << endl;
		node->value->printCommonInfo();
		cout << endl;
		cout << left << setw(20) << "Display: " << setw(20) << "Light" << setw(25) << "Screen Light" << setw(25) << "Taplo Light" << endl;
		cout << setw(20) << "";
		node->value->getDisplay()->printDisplayInfo();
		cout << left << setw(20) << "Sound: " << setw(20) << "Media" << setw(20) << "Call" << setw(25) << "Navigation" << setw(25) << "Notification" << endl;
		cout << setw(20) << "";
		node->value->getSound()->printSoundInfo();
		cout << left << setw(20) << "General: " << setw(40) << "Timezone" << setw(30) << " " << "Language" << endl;
		cout << setw(20) << " ";
		node->value->getGeneral()->printGeneralInfo();
		cout << "------------------------------------------------------------------------------------" << endl;
		Print_All(node->right);
	}
}
void BST::Print(category type) {
	if (type == DISPLAY) {
		cout << "--- Display setting ---" << endl;
		cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" << setw(25) << "Remind service" << setw(20) << "Light level" << setw(25) << "Screen light level" << setw(25) << "Taplo light level" << endl;
		Print_Display(root);
	}
	else if (type == SOUND) {
		cout << "--- Sound setting ---" << endl;
		cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" << setw(25) << "Remind service" << setw(20) << "Media" << setw(20) << "Call" << setw(25) << "Navigation" << setw(25) << "Notification" << endl;
		Print_Sound(root);
	}
	else if (type == GENERAL) {
		cout << "--- General setting ---" << endl;
		cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" << setw(25) << "Remind service" << setw(48) << "Timezone" << setw(30) << right << "Language" << endl;
		Print_General(root);
	}
	else{
		cout << "--- All setting ---" << endl;
		Print_All(root);
	}
}

void BST::SaveData(Node* node) {
	ofstream file(STORAGE_PATH, ios::app);
	try {
		if (file.is_open()) {
			if (node != NULL) {
				SaveData(node->left);
				file << "Common:"
					<< node->value->getOwnerName() << ","
					<< node->value->getEmail() << ","
					<< node->value->getOwnerID() << ","
					<< node->value->getOdoNumber() << ","
					<< node->value->getServiceRemind() << ";"
					<< "Display:"
					<< node->value->getDisplay()->getLightLevel() << ","
					<< node->value->getDisplay()->getScreenLightLevel() << ","
					<< node->value->getDisplay()->getTaploLightLevel() << ";"
					<< "Sound:" << node->value->getSound()->getCallVolume() << ","
					<< node->value->getSound()->getMediaVolume() << ","
					<< node->value->getSound()->getNavigationVolume() << ","
					<< node->value->getSound()->getNotificationVolume() << ";"
					<< "General:"
					<< node->value->getGeneral()->getTimeZone() << ","
					<< node->value->getGeneral()->getLanguage() << endl;
				SaveData(node->right);
			}
		}
		else {
			throw " FAIL TO WRITE TO STORAGE";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file.close();
	}
}
void BST::SaveData() {
	SaveData(root);
}