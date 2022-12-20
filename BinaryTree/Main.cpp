#include "utility.h"
#include "BinTree.h"
#include "BinSearchTree.h"

void instructor(int &treeType) {
	// 二叉树的介绍
	cout << "欢迎来到二叉树模拟程序" << endl;
	cout << "在这里你可以模拟二叉树和二叉查找树，并对它们进行一些操作" << endl;
	cout << "请选择你想生成的二叉树：1. 二叉树\t2. 二叉查找树" << endl;
	cin >> treeType;
	while (treeType != 1 && treeType != 2) {
		cout << "输入有误，请重新输入：";
		cin >> treeType;
	}
}

void simulate(int treeType) {
	if (treeType == 1) {
		system("cls");
		cout << "你选择的是二叉树" << endl;
		cout << "请通过前序遍历的方式创建这棵树" << endl;
		cout << "输入小写字母，0表示空节点，例如：abc00de00f00g0h00" << endl;
		string tree;
		cin >> tree;
		for (int i = 0; i < tree.size(); i ++) {
			if (tree[i] == '0') tree[i] = 0;
		}
		BinTree<char> bt(tree.c_str());
		cout << "你可以进行以下操作：\n"
			<< "1. 前序遍历\n"
			<< "2. 中序遍历\n"
			<< "3. 后序遍历\n"
			<< "4. 层序遍历\n"
			<< "5. 求二叉树的深度\n"
			<< "6. 求二叉树的宽度\n"
			<< "7. 统计度数为0的节点数\n"
			<< "8. 统计度数为1的节点数\n"
			<< "9. 统计度数为2的节点数\n"
			<< "0. 退出程序" << endl;
		while (true) {
			cout << "请选择你想做的操作：";
			int op;
			cin >> op;
			if (op == 0) break;
			switch (op)
			{
			case 1:
				cout << "前序遍历结果为：";
				bt.preOrder();
				break;
			case 2:
				cout << "中序遍历结果为：";
				bt.inOrder();
				break;
			case 3:
				cout << "后序遍历结果为：";
				bt.postOrder();
				break;
			case 4:
				cout << "层序遍历结果为：";
				bt.levelOrder();
				break;
			case 5:
				cout << "树的深度为：" << bt.getDepth() << endl;
				break;
			case 6:
				cout << "数的宽度为：" << bt.getWidth() << endl;
				break;
			case 7:
				cout << "度数为0的节点有" << bt.degree0() << "个" << endl;
				break;
			case 8:
				cout << "度数为1的节点有" << bt.degree1() << "个" << endl;
				break;
			case 9:
				cout << "度数为2的节点有" << bt.degree2() << "个" << endl;
				break;
			default:
				cout << "输入有误，请重新输入" << endl;
				break;
			}
		}
	}
	else {
		system("cls");
		cout << "你选择的是二叉查找树" << endl;
		cout << "请输入一个由小写英文字母组成的字符串，将通过这个字符串以字典序创建一棵二叉查找树" << endl;
		string seq;
		cin >> seq;
		BinSearchTree<char> bst(seq.c_str(), seq.size());
		cout << "你可以进行以下操作：\n"
			<< "1. 前序遍历\n"
			<< "2. 中序遍历\n"
			<< "3. 后序遍历\n"
			<< "4. 层序遍历\n"
			<< "5. 求二叉树的深度\n"
			<< "6. 求二叉树的宽度\n"
			<< "7. 统计度数为0的节点数\n"
			<< "8. 统计度数为1的节点数\n"
			<< "9. 统计度数为2的节点数\n"
			<< "10. 插入一个字符\n"
			<< "11. 删除一个字符\n"
			<< "12. 查找一个字符是否在树中\n"
			<< "0. 退出程序" << endl;
		while (true) {
			cout << "请选择你想做的操作：";
			int op;
			cin >> op;
			if (op == 0) break;
			switch (op)
			{
			case 1:
				cout << "前序遍历结果为：";
				bst.preOrder();
				break;
			case 2:
				cout << "中序遍历结果为：";
				bst.inOrder();
				break;
			case 3:
				cout << "后序遍历结果为：";
				bst.postOrder();
				break;
			case 4:
				cout << "层序遍历结果为：";
				bst.levelOrder();
				break;
			case 5:
				cout << "树的深度为：" << bst.getDepth() << endl;
				break;
			case 6:
				cout << "数的宽度为：" << bst.getWidth() << endl;
				break;
			case 7:
				cout << "度数为0的节点有" << bst.degree0() << "个" << endl;
				break;
			case 8:
				cout << "度数为1的节点有" << bst.degree1() << "个" << endl;
				break;
			case 9:
				cout << "度数为2的节点有" << bst.degree2() << "个" << endl;
				break;
			case 10:
				cout << "请输入插入的字符";
				char input;
				cin >> input;
				if (bst.insert(input)) cout << "插入成功！" << endl;
				else cout << "该字符已经在树中" << endl;
				break;
			case 11:
				cout << "请输入要删除的字符";
				char del;
				cin >> del;
				if (bst.remove(del)) cout << "删除成功！" << endl;
				else cout << "未找到该字符！" << endl;
				break;
			case 12:
			{
				cout << "请输入要查找的字符：";
				char req;
				cin >> req;
				BinSearchTree<char>::node n = bst.search(req);
				if (n == NULL) cout << "未找到该字符！" << endl;
				else cout << "字符" << n->data << "在树中，深度为" << n->depth << endl;
				break;
			}
			default:
				cout << "输入有误，请重新输入" << endl;
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