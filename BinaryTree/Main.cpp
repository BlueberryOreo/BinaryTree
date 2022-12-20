#include "utility.h"
#include "BinTree.h"
#include "BinSearchTree.h"

void instructor(int &treeType) {
	// �������Ľ���
	cout << "��ӭ����������ģ�����" << endl;
	cout << "�����������ģ��������Ͷ�����������������ǽ���һЩ����" << endl;
	cout << "��ѡ���������ɵĶ�������1. ������\t2. ���������" << endl;
	cin >> treeType;
	while (treeType != 1 && treeType != 2) {
		cout << "�����������������룺";
		cin >> treeType;
	}
}

void simulate(int treeType) {
	if (treeType == 1) {
		system("cls");
		cout << "��ѡ����Ƕ�����" << endl;
		cout << "��ͨ��ǰ������ķ�ʽ���������" << endl;
		cout << "����Сд��ĸ��0��ʾ�սڵ㣬���磺abc00de00f00g0h00" << endl;
		string tree;
		cin >> tree;
		for (int i = 0; i < tree.size(); i ++) {
			if (tree[i] == '0') tree[i] = 0;
		}
		BinTree<char> bt(tree.c_str());
		cout << "����Խ������²�����\n"
			<< "1. ǰ�����\n"
			<< "2. �������\n"
			<< "3. �������\n"
			<< "4. �������\n"
			<< "5. ������������\n"
			<< "6. ��������Ŀ��\n"
			<< "7. ͳ�ƶ���Ϊ0�Ľڵ���\n"
			<< "8. ͳ�ƶ���Ϊ1�Ľڵ���\n"
			<< "9. ͳ�ƶ���Ϊ2�Ľڵ���\n"
			<< "0. �˳�����" << endl;
		while (true) {
			cout << "��ѡ���������Ĳ�����";
			int op;
			cin >> op;
			if (op == 0) break;
			switch (op)
			{
			case 1:
				cout << "ǰ��������Ϊ��";
				bt.preOrder();
				break;
			case 2:
				cout << "����������Ϊ��";
				bt.inOrder();
				break;
			case 3:
				cout << "����������Ϊ��";
				bt.postOrder();
				break;
			case 4:
				cout << "����������Ϊ��";
				bt.levelOrder();
				break;
			case 5:
				cout << "�������Ϊ��" << bt.getDepth() << endl;
				break;
			case 6:
				cout << "���Ŀ��Ϊ��" << bt.getWidth() << endl;
				break;
			case 7:
				cout << "����Ϊ0�Ľڵ���" << bt.degree0() << "��" << endl;
				break;
			case 8:
				cout << "����Ϊ1�Ľڵ���" << bt.degree1() << "��" << endl;
				break;
			case 9:
				cout << "����Ϊ2�Ľڵ���" << bt.degree2() << "��" << endl;
				break;
			default:
				cout << "������������������" << endl;
				break;
			}
		}
	}
	else {
		system("cls");
		cout << "��ѡ����Ƕ��������" << endl;
		cout << "������һ����СдӢ����ĸ��ɵ��ַ�������ͨ������ַ������ֵ��򴴽�һ�ö��������" << endl;
		string seq;
		cin >> seq;
		BinSearchTree<char> bst(seq.c_str(), seq.size());
		cout << "����Խ������²�����\n"
			<< "1. ǰ�����\n"
			<< "2. �������\n"
			<< "3. �������\n"
			<< "4. �������\n"
			<< "5. ������������\n"
			<< "6. ��������Ŀ��\n"
			<< "7. ͳ�ƶ���Ϊ0�Ľڵ���\n"
			<< "8. ͳ�ƶ���Ϊ1�Ľڵ���\n"
			<< "9. ͳ�ƶ���Ϊ2�Ľڵ���\n"
			<< "10. ����һ���ַ�\n"
			<< "11. ɾ��һ���ַ�\n"
			<< "12. ����һ���ַ��Ƿ�������\n"
			<< "0. �˳�����" << endl;
		while (true) {
			cout << "��ѡ���������Ĳ�����";
			int op;
			cin >> op;
			if (op == 0) break;
			switch (op)
			{
			case 1:
				cout << "ǰ��������Ϊ��";
				bst.preOrder();
				break;
			case 2:
				cout << "����������Ϊ��";
				bst.inOrder();
				break;
			case 3:
				cout << "����������Ϊ��";
				bst.postOrder();
				break;
			case 4:
				cout << "����������Ϊ��";
				bst.levelOrder();
				break;
			case 5:
				cout << "�������Ϊ��" << bst.getDepth() << endl;
				break;
			case 6:
				cout << "���Ŀ��Ϊ��" << bst.getWidth() << endl;
				break;
			case 7:
				cout << "����Ϊ0�Ľڵ���" << bst.degree0() << "��" << endl;
				break;
			case 8:
				cout << "����Ϊ1�Ľڵ���" << bst.degree1() << "��" << endl;
				break;
			case 9:
				cout << "����Ϊ2�Ľڵ���" << bst.degree2() << "��" << endl;
				break;
			case 10:
				cout << "�����������ַ�";
				char input;
				cin >> input;
				if (bst.insert(input)) cout << "����ɹ���" << endl;
				else cout << "���ַ��Ѿ�������" << endl;
				break;
			case 11:
				cout << "������Ҫɾ�����ַ�";
				char del;
				cin >> del;
				if (bst.remove(del)) cout << "ɾ���ɹ���" << endl;
				else cout << "δ�ҵ����ַ���" << endl;
				break;
			case 12:
			{
				cout << "������Ҫ���ҵ��ַ���";
				char req;
				cin >> req;
				BinSearchTree<char>::node n = bst.search(req);
				if (n == NULL) cout << "δ�ҵ����ַ���" << endl;
				else cout << "�ַ�" << n->data << "�����У����Ϊ" << n->depth << endl;
				break;
			}
			default:
				cout << "������������������" << endl;
				break;
			}
		}
	}
}

int main() {

	int treeType;
	instructor(treeType);
	simulate(treeType);
	
	//int arr[] = { 9, 6, 5, 0, 0, 0, 7, 0, 0 };
	//BinTree<int> tree(arr);
	//cout << "pre:";
	//tree.preOrder();
	//cout << "in:";
	//tree.inOrder();
	//cout << "post:";
	//tree.postOrder();
	//cout << "level:";
	//tree.levelOrder();

	//cout << tree.getDepth() << endl;
	//cout << tree.getWidth() << endl;

	//cout << tree.degree0() << " " << tree.degree1() << " " << tree.degree2() << endl;

	//int arr2[] = { 1 };
	//BinSearchTree<int> bst(arr2, sizeof(arr2) / sizeof(arr2[0]));
	//cout << 1 << " " << bst.insert(1) << endl;
	//cout << 8 << " " << bst.insert(8) << endl;
	//bst.preOrder();
	//bst.inOrder();
	////cout << "here" << endl;
	//bst.remove(9);
	//bst.remove(1);
	//bst.remove(8);
	////cout << bst.remove(10) << endl;
	//bst.preOrder();
	//bst.inOrder();
	//bst.levelOrder();
	//BinSearchTree<int>::node n = bst.search(10);
	//if (n) cout << n->data << endl;
	//else cout << "None" << endl;

	return 0;
}

// 9 6 5 0 0 0 7 0 0